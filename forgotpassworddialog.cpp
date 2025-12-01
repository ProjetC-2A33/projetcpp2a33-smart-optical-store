#include "forgotpassworddialog.h"
#include "ui_forgotpassworddialog.h"
#include "smtpclient.h"
#include "resendclient.h"
#include "curlemailer.h"

#include <QRegularExpression>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QTimer>
#include <QApplication>

ForgotPasswordDialog::ForgotPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgotPasswordDialog),
    m_emailEnvoye(false)
{
    ui->setupUi(this);
    setWindowTitle("Mot de passe oublié");
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    connect(ui->pushButton_send, &QPushButton::clicked,
            this, &ForgotPasswordDialog::onSendClicked);
    connect(ui->pushButton_cancel, &QPushButton::clicked,
            this, &ForgotPasswordDialog::onCancelClicked);
    
    // Connecter le signal textChanged pour envoyer automatiquement
    connect(ui->lineEdit_email, &QLineEdit::textChanged,
            this, &ForgotPasswordDialog::onEmailTextChanged);
    connect(ui->lineEdit_email, &QLineEdit::returnPressed,
            this, &ForgotPasswordDialog::onEmailReturnPressed);
}

ForgotPasswordDialog::~ForgotPasswordDialog()
{
    delete ui;
}

QString ForgotPasswordDialog::getEmail() const
{
    return ui->lineEdit_email->text().trimmed();
}

void ForgotPasswordDialog::onSendClicked()
{
    QString email = ui->lineEdit_email->text().trimmed();

    if (email.isEmpty()) {
        afficherMessageErreur("Veuillez saisir votre adresse email.");
        return;
    }

    if (!validerEmail(email)) {
        afficherMessageErreur("Adresse email invalide.\nVeuillez saisir une adresse email valide (ex: votre.email@gmail.com)");
        return;
    }

    // Envoyer l'email automatiquement
    envoyerEmailAutomatiquement(email);
}

void ForgotPasswordDialog::onEmailReturnPressed()
{
    onSendClicked();
}

void ForgotPasswordDialog::onEmailTextChanged()
{
    // Cacher l'erreur quand l'utilisateur tape
    ui->label_error->setVisible(false);
}

void ForgotPasswordDialog::onCancelClicked()
{
    reject();
}

void ForgotPasswordDialog::afficherMessageErreur(const QString& message)
{
    ui->label_error->setText(message);
    ui->label_error->setVisible(true);
}

bool ForgotPasswordDialog::validerEmail(const QString& email)
{
    QRegularExpression regex(R"((^[\w\.-]+@[\w\.-]+\.[A-Za-z]{2,}$))");
    return regex.match(email).hasMatch();
}

void ForgotPasswordDialog::envoyerEmailAutomatiquement(const QString& email)
{
    // Vérifier si l'email existe dans la table EMPLOYE et récupérer le mot de passe
    QSqlQuery query;
    query.prepare("SELECT \"MOT_DE_PASSE_EMPLOYE\", NOM, PRENOM FROM EMPLOYE WHERE UPPER(\"EMAIL\") = UPPER(:email)");
    query.bindValue(":email", email);
    
    QString motDePasseEmploye;
    QString nomEmploye;
    QString prenomEmploye;
    bool emailTrouve = false;
    
    if (query.exec() && query.next()) {
        motDePasseEmploye = query.value(0).toString();
        nomEmploye = query.value(1).toString();
        prenomEmploye = query.value(2).toString();
        emailTrouve = true;
    }
    
    if (!emailTrouve || motDePasseEmploye.isEmpty()) {
        QMessageBox::warning(this, "Email introuvable",
                             QString("Aucun employé trouvé avec l'email : %1\n\n"
                                     "Ou le mot de passe n'est pas défini pour cet employé.\n\n"
                                     "Veuillez vérifier votre adresse email ou contacter l'administrateur.")
                             .arg(email));
        return;
    }
    
    // Afficher un message de progression
    ui->label_error->setText("Envoi de l'email en cours...");
    ui->label_error->setStyleSheet("color: #4d73ff;");
    ui->label_error->setVisible(true);
    QApplication::processEvents();
    
    // Construire le message
    QString nomComplet = QString("%1 %2").arg(prenomEmploye, nomEmploye).trimmed();
    if (nomComplet.isEmpty()) {
        nomComplet = "Cher employé";
    }
    
    QString subject = "Récupération de votre mot de passe - Application Gestion Employés";
    QString body = QString(
        "========================================\n"
        "  RECUPERATION DE MOT DE PASSE\n"
        "  Application Gestion Employés\n"
        "========================================\n\n"
        "Bonjour %1,\n\n"
        "Vous avez demandé la récupération de votre mot de passe.\n\n"
        "VOICI VOS IDENTIFIANTS DE CONNEXION :\n\n"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
        "  EMAIL : %2\n"
        "  MOT DE PASSE : %3\n"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n"
        "Vous pouvez maintenant vous connecter à l'application avec ces identifiants.\n\n"
        "IMPORTANT : Pour votre sécurité, nous vous recommandons fortement de changer votre mot de passe après votre première connexion.\n\n"
        "Si vous n'avez pas fait cette demande, veuillez contacter l'administrateur immédiatement.\n\n"
        "Cordialement,\n"
        "L'équipe de l'Application Gestion Employés\n\n"
        "========================================\n")
        .arg(nomComplet, email, motDePasseEmploye);
    
    // Envoyer l'email via curl
    QString error;
    CurlEmailer emailer;
    bool success = emailer.sendEmail(email, subject, body, &error);
    
    if (success) {
        m_emailEnvoye = true;
        ui->label_error->setText("✅ Email envoyé avec succès ! Vérifiez votre boîte de réception.");
        ui->label_error->setStyleSheet("color: #4caf50;");
        ui->label_error->setVisible(true);
        
        QMessageBox::information(this, "Email envoyé",
                                 QString("✅ Votre mot de passe a été envoyé à :\n%1\n\n"
                                        "Vérifiez votre boîte Gmail pour recevoir votre mot de passe.\n\n"
                                        "Vous pouvez maintenant vous connecter avec votre email et votre mot de passe.")
                                 .arg(email));
        
        // Fermer le dialogue après un court délai
        QTimer::singleShot(2000, this, [this]() {
            accept();
        });
    } else {
        ui->label_error->setText("❌ Erreur lors de l'envoi de l'email.");
        ui->label_error->setStyleSheet("color: #ff8a80;");
        ui->label_error->setVisible(true);
        
        QMessageBox::critical(this, "Erreur d'envoi",
            QString("❌ Impossible d'envoyer l'email.\n\n"
                   "Erreur : %1\n\n"
                   "Vérifiez votre connexion Internet.")
            .arg(error));
    }
}

void ForgotPasswordDialog::envoyerEmailTest(const QString& emailDestinataire)
{
    // Configuration Resend API
    QString resendApiKey = "re_WRuNQxQG_DDVjwaGhpyyK5vPJZ5iZZpji";
    QString fromEmail = "onboarding@resend.dev"; // Email par défaut Resend
    
    // Afficher message de progression
    ui->label_error->setText("📧 Envoi de l'email de test en cours...");
    ui->label_error->setStyleSheet("color: #4d73ff;");
    ui->label_error->setVisible(true);
    QApplication::processEvents();
    
    // Préparer le message de test
    QString subject = "[TEST] Email de test - Application Gestion Employés";
    QString body = QString(
        "========================================\n"
        "  EMAIL DE TEST\n"
        "  Application Gestion Employés\n"
        "========================================\n\n"
        "Bonjour,\n\n"
        "Ceci est un email de test pour vérifier le bon fonctionnement\n"
        "du système d'envoi d'emails de l'application.\n\n"
        "Si vous recevez ce message, cela signifie que le système\n"
        "de mailing fonctionne correctement !\n\n"
        "Date et heure : %1\n\n"
        "Cordialement,\n"
        "L'équipe de développement\n\n"
        "========================================\n")
        .arg(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    
    qDebug() << "=== TEST ENVOI EMAIL VIA RESEND ===";
    qDebug() << "De:" << fromEmail;
    qDebug() << "À:" << emailDestinataire;
    qDebug() << "Sujet:" << subject;
    
    // Envoyer l'email via curl
    QString error;
    CurlEmailer emailer;
    bool success = emailer.sendEmail(emailDestinataire, subject, body, &error);
    
    qDebug() << "Résultat:" << (success ? "SUCCÈS ✅" : "ÉCHEC ❌");
    if (!success) {
        qDebug() << "Erreur:" << error;
    }
    
    if (success) {
        ui->label_error->setText("✅ Email de test envoyé avec succès !");
        ui->label_error->setStyleSheet("color: #4caf50;");
        ui->label_error->setVisible(true);
        
        QMessageBox::information(this, "Email envoyé",
                                 QString("✅ Email de test envoyé avec succès à :\n%1\n\n"
                                        "Vérifiez la boîte de réception.")
                                 .arg(emailDestinataire));
        return;
    } else {
        ui->label_error->setText("❌ Erreur lors de l'envoi");
        ui->label_error->setStyleSheet("color: #ff8a80;");
        ui->label_error->setVisible(true);
        
        QMessageBox::critical(this, "Erreur d'envoi",
            QString("❌ Impossible d'envoyer l'email de test.\n\n"
                   "Erreur : %1\n\n"
                   "Vérifiez votre connexion Internet.")
            .arg(error));
    }
}


