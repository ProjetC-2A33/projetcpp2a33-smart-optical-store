#include "logindialog.h"
#include "ui_logindialog.h"
#include "smtpclient.h"
#include "gmailclient.h"
#include "smsclient.h"
#include "forgotpassworddialog.h"
#include "curlemailer.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QRegularExpression>
#include <QDateTime>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QSettings>

namespace {
const QString SMTP_HOST = "smtp.gmail.com";
const quint16 SMTP_PORT = 587;  // Port TLS/STARTTLS (recommandé par Gmail)
const QString LOGIN_PAR_DEFAUT = "admin";
const QString MDP_PAR_DEFAUT = "admin";
}

QString LoginDialog::getDialogStyleSheet()
{
    return R"(
        QDialog {
            background-color: #06122A;
            color: #ffffff;
            font-family: "Segoe UI";
        }
        QLabel {
            color: #ffffff;
        }
        QLineEdit {
            background-color: #0f1c3b;
            color: #ffffff;
            border: 1.5px solid #253c6f;
            border-radius: 10px;
            padding: 6px 10px;
        }
        QPushButton {
            background-color: #2d5bff;
            color: #ffffff;
            border-radius: 10px;
            padding: 8px 18px;
            font-weight: 600;
        }
        QPushButton:hover {
            background-color: #4d73ff;
        }
        QPushButton:pressed {
            background-color: #1f44c6;
        }
        QMessageBox {
            background-color: #06122A;
            color: #ffffff;
        }
        QMessageBox QLabel {
            color: #ffffff;
        }
        QMessageBox QPushButton {
            background-color: #2d5bff;
            color: #ffffff;
            border-radius: 10px;
            padding: 8px 18px;
            font-weight: 600;
        }
        QMessageBox QPushButton:hover {
            background-color: #4d73ff;
        }
    )";
}

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    codeAuthentification(),
    emailPourReinitialisation()
{
    ui->setupUi(this);
    setWindowTitle("Authentification");
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    // Appliquer le styleSheet aux dialogues enfants
    qApp->setStyleSheet(qApp->styleSheet() + getDialogStyleSheet());

    connect(ui->pushButton_login, &QPushButton::clicked,
            this, &LoginDialog::onLoginClicked);
    connect(ui->pushButton_forgot, &QPushButton::clicked,
            this, &LoginDialog::onForgotPasswordClicked);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::onLoginClicked()
{
    const QString login = ui->lineEdit_login->text().trimmed();
    const QString password = ui->lineEdit_password->text();

    if (login.isEmpty() || password.isEmpty()) {
        afficherMessageErreur("Merci de compléter tous les champs.");
        return;
    }

    if (!verifierIdentifiants(login, password)) {
        afficherMessageErreur("Identifiants incorrects.");
        return;
    }

    // Récupérer l'email de l'utilisateur depuis la base de données
    QString email;
    QSqlQuery query;
    
    // Vérifier d'abord dans la table EMPLOYE
    query.prepare("SELECT \"EMAIL\" FROM EMPLOYE WHERE UPPER(\"EMAIL\") = UPPER(:login)");
    query.bindValue(":login", login);
    
    if (query.exec() && query.next()) {
        email = query.value(0).toString();
    } else {
        // Sinon vérifier dans la table UTILISATEUR
        query.prepare("SELECT EMAIL FROM UTILISATEUR WHERE UPPER(LOGIN) = UPPER(:login) OR UPPER(EMAIL) = UPPER(:login)");
        query.bindValue(":login", login);
        
        if (query.exec() && query.next()) {
            email = query.value(0).toString();
        }
    }

    // Si un email valide est trouvé, envoyer le code de vérification
    if (!email.isEmpty()) {
        if (!verifierCodeAuthentification(email)) {
            afficherMessageErreur("Code de vérification incorrect.");
            return;
        }
    }

    accept();
}

void LoginDialog::onForgotPasswordClicked()
{
    ForgotPasswordDialog dialog(this);
    dialog.exec();
    
    // Le dialogue gère maintenant l'envoi automatique de l'email
    // Plus besoin de récupérer l'email ici car tout est géré dans le dialogue
}

bool LoginDialog::verifierIdentifiants(const QString& login, const QString& motDePasse)
{
    // Vérification dans la table EMPLOYE (email et mot de passe)
    QSqlQuery query;
    
    // Vérifier dans la table EMPLOYE avec l'email
    query.prepare("SELECT \"MOT_DE_PASSE_EMPLOYE\" FROM EMPLOYE WHERE UPPER(\"EMAIL\") = UPPER(:login)");
    query.bindValue(":login", login);
    
    if (query.exec() && query.next()) {
        QString motDePasseBdd = query.value(0).toString();
        // Comparaison du mot de passe
        if (motDePasse == motDePasseBdd) {
            return true;
        }
    }
    
    // Si la requête échoue ou aucun employé trouvé, essayer aussi la table UTILISATEUR
    query.prepare("SELECT MOT_DE_PASSE FROM UTILISATEUR WHERE UPPER(LOGIN) = UPPER(:login) OR UPPER(EMAIL) = UPPER(:login)");
    query.bindValue(":login", login);
    
    if (query.exec() && query.next()) {
        QString motDePasseBdd = query.value(0).toString();
        if (motDePasse == motDePasseBdd) {
            return true;
        }
    }
    
    // En dernier recours, utiliser les identifiants par défaut
    return (login.compare(LOGIN_PAR_DEFAUT, Qt::CaseInsensitive) == 0 && 
            motDePasse == MDP_PAR_DEFAUT);
}

void LoginDialog::afficherMessageErreur(const QString& message)
{
    ui->label_error->setText(message);
    ui->label_error->setVisible(true);
}

QString LoginDialog::genererCodeAuthentification()
{
    // Générer un code à 6 chiffres
    // Initialiser le générateur avec le temps actuel
    qsrand(QDateTime::currentDateTime().toTime_t());
    int code = qrand() % 900000 + 100000; // Génère un nombre entre 100000 et 999999
    return QString::number(code);
}

void LoginDialog::reinitialiserMotDePasse(const QString& email)
{
    bool ok = false;
    QString nouveauMotDePasse = QInputDialog::getText(
        this,
        "Nouveau mot de passe",
        QString("Code vérifié avec succès !\n\n"
                "Veuillez saisir votre nouveau mot de passe :"),
        QLineEdit::Password,
        QString(),
        &ok
    ).trimmed();

    if (!ok || nouveauMotDePasse.isEmpty()) {
        QMessageBox::information(this, "Annulé",
                                 "Réinitialisation annulée.");
        codeAuthentification.clear();
        emailPourReinitialisation.clear();
        return;
    }

    if (nouveauMotDePasse.length() < 4) {
        QMessageBox::warning(this, "Mot de passe trop court",
                             "Le mot de passe doit contenir au moins 4 caractères.");
        codeAuthentification.clear();
        emailPourReinitialisation.clear();
        return;
    }

    // Demander confirmation
    QString confirmation = QInputDialog::getText(
        this,
        "Confirmation",
        "Veuillez confirmer votre nouveau mot de passe :",
        QLineEdit::Password,
        QString(),
        &ok
    ).trimmed();

    if (!ok) {
        codeAuthentification.clear();
        emailPourReinitialisation.clear();
        return;
    }

    if (nouveauMotDePasse != confirmation) {
        QMessageBox::warning(this, "Erreur",
                             "Les mots de passe ne correspondent pas.");
        codeAuthentification.clear();
        emailPourReinitialisation.clear();
        return;
    }

    // Mettre à jour le mot de passe dans la base de données
    QSqlQuery query;
    
    // Note: En production, il faudrait hacher le mot de passe avec bcrypt ou similaire
    // Pour l'instant, on stocke en clair (à améliorer pour la sécurité)
    query.prepare("UPDATE UTILISATEUR SET MOT_DE_PASSE = :password WHERE UPPER(EMAIL) = UPPER(:email)");
    query.bindValue(":password", nouveauMotDePasse);
    query.bindValue(":email", email);
    
    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
    QMessageBox::information(this, "Succès",
                             QString("Votre mot de passe a été réinitialisé avec succès.\n\n"
                                     "Vous pouvez maintenant vous connecter avec votre nouveau mot de passe."));
        } else {
            QMessageBox::warning(this, "Erreur",
                                 QString("Aucun utilisateur trouvé avec l'email : %1\n\n"
                                         "Le mot de passe n'a pas pu être mis à jour.\n\n"
                                         "Assurez-vous que la table UTILISATEUR existe et contient cet email.").arg(email));
        }
    } else {
        QMessageBox::critical(this, "Erreur base de données",
                             QString("Impossible de mettre à jour le mot de passe :\n%1\n\n"
                                     "Vérifiez que la table UTILISATEUR existe dans votre base de données.\n"
                                     "Exécutez le script create_table_utilisateur.sql si nécessaire.")
                             .arg(query.lastError().text()));
    }
    
    codeAuthentification.clear();
    emailPourReinitialisation.clear();
}

bool LoginDialog::verifierCodeAuthentification(const QString& email)
{
    // Générer un code de vérification à 6 chiffres
    QString code = genererCodeAuthentification();
    codeAuthentification = code;
    
    // Envoyer le code par email
    if (!envoyerCodeParEmail(email, code)) {
        QMessageBox::warning(this, "Erreur d'envoi",
                           "Impossible d'envoyer le code de vérification.\n\n"
                           "Vérifiez votre connexion Internet.");
        return false;
    }
    
    // Demander à l'utilisateur de saisir le code
    bool ok;
    QString codeSaisi = QInputDialog::getText(
        this,
        "Vérification en deux étapes",
        QString("Un code de vérification a été envoyé à :\n%1\n\n"
                "Veuillez entrer le code à 6 chiffres :").arg(email),
        QLineEdit::Normal,
        QString(),
        &ok
    ).trimmed();
    
    if (!ok) {
        codeAuthentification.clear();
        return false;
    }
    
    // Vérifier le code
    if (codeSaisi != codeAuthentification) {
        QMessageBox::warning(this, "Code incorrect",
                           "Le code de vérification saisi est incorrect.\n\n"
                           "Veuillez réessayer.");
        codeAuthentification.clear();
        return false;
    }
    
    codeAuthentification.clear();
    return true;
}

bool LoginDialog::envoyerCodeParEmail(const QString& email, const QString& code)
{
    QString subject = "Code de vérification - Application Gestion Employés";
    QString body = QString(
        "========================================\n"
        "  CODE DE VÉRIFICATION\n"
        "  Application Gestion Employés\n"
        "========================================\n\n"
        "Bonjour,\n\n"
        "Vous tentez de vous connecter à l'application.\n\n"
        "Votre code de vérification est :\n\n"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
        "        %1\n"
        "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n"
        "Ce code est valable pour cette session de connexion uniquement.\n\n"
        "Si vous n'êtes pas à l'origine de cette tentative de connexion,\n"
        "veuillez ignorer ce message et contacter l'administrateur.\n\n"
        "Cordialement,\n"
        "L'équipe de l'Application Gestion Employés\n\n"
        "========================================\n")
        .arg(code);
    
    // Envoyer l'email via curl
    QString error;
    CurlEmailer emailer;
    return emailer.sendEmail(email, subject, body, &error);
}

