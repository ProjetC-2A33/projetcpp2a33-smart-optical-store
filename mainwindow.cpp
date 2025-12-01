#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "logindialog.h"
#include <QMessageBox>
#include <QApplication>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QRegularExpression>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QPageLayout>
#include <QPageSize>
#include <QDir>
#include <QComboBox>
#include <QLineEdit>
#include <QSqlQuery>
#include <QSqlError>
#include <algorithm>
#include <QDialog>
#include <QVBoxLayout>
#include <QMap>
#include <QLabel>
#include <QPainterPath>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QTimer>
#include <QGraphicsOpacityEffect>

class PostePieWidget : public QWidget
{
public:
    explicit PostePieWidget(const QList<QPair<QString, int>>& data, QWidget *parent = nullptr)
        : QWidget(parent), m_data(data), m_animationProgress(0.0), m_legendOpacity(0.0)
    {
        setMinimumSize(360, 320);
        setStyleSheet("background-color: #0a1628;");
        
        // Animation pour le graphique avec timer
        m_animationTimer = new QTimer(this);
        connect(m_animationTimer, &QTimer::timeout, this, [this]() {
            m_animationProgress += 0.02;
            if (m_animationProgress > 1.0) {
                m_animationProgress = 1.0;
                m_animationTimer->stop();
                // Démarrer l'animation de la légende
                m_legendTimer->start();
            }
            update();
        });
        
        // Animation pour la légende (fade-in)
        m_legendTimer = new QTimer(this);
        connect(m_legendTimer, &QTimer::timeout, this, [this]() {
            m_legendOpacity += 0.05;
            if (m_legendOpacity > 1.0) {
                m_legendOpacity = 1.0;
                m_legendTimer->stop();
            }
            update();
        });
        
        // Démarrer les animations après un court délai
        QTimer::singleShot(100, [this]() {
            m_animationTimer->start(30); // 30ms = ~33 FPS
        });
        m_legendTimer->setInterval(20);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        QWidget::paintEvent(event);
        if (m_data.isEmpty()) {
            return;
        }

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QRectF pieRect(20, 20, width() - 200, height() - 40);
        if (pieRect.width() <= 0 || pieRect.height() <= 0) {
            return;
        }

        int total = 0;
        for (const auto& item : m_data) {
            total += item.second;
        }
        if (total <= 0) {
            return;
        }

        QVector<QColor> colors = {
            QColor("#3A7AFE"), QColor("#FF7A7A"), QColor("#F6C343"),
            QColor("#7BDA5E"), QColor("#BC7CFF"), QColor("#FF9F40"),
            QColor("#2EC4B6"), QColor("#FF6F91")
        };

        double startAngle = 0.0;
        int colorIndex = 0;

        painter.setPen(Qt::NoPen);

        // Animation du graphique : dessiner progressivement
        for (const auto& item : m_data) {
            double span = 360.0 * static_cast<double>(item.second) / total;
            double animatedSpan = span * m_animationProgress;
            
            // Effet de rotation progressive
            double rotationOffset = (1.0 - m_animationProgress) * 90.0;
            double animatedStartAngle = startAngle + rotationOffset;
            
            QColor color = colors[colorIndex % colors.size()];
            // Effet de fade-in pour chaque segment
            color.setAlphaF(m_animationProgress);
            painter.setBrush(color);
            
            painter.drawPie(pieRect, int(animatedStartAngle * 16), int(animatedSpan * 16));
            startAngle += span;
            ++colorIndex;
        }

        // Draw legend with fade-in animation
        painter.setOpacity(m_legendOpacity);
        painter.setPen(Qt::white);
        painter.setFont(QFont("Segoe UI", 10, QFont::Bold));
        int legendX = pieRect.right() + 20;
        int legendY = 30;
        colorIndex = 0;
        for (const auto& item : m_data) {
            QColor color = colors[colorIndex % colors.size()];
            painter.setBrush(color);
            painter.drawRect(legendX, legendY, 16, 16);
            
            // Animation de slide pour le texte
            int textOffset = (1.0 - m_legendOpacity) * 20;
            painter.drawText(legendX + 24 + textOffset, legendY + 13,
                             QString("%1 (%2)").arg(item.first).arg(item.second));
            legendY += 26;
            ++colorIndex;
        }
        painter.setOpacity(1.0);
    }

private:
    QList<QPair<QString, int>> m_data;
    double m_animationProgress;
    double m_legendOpacity;
    QTimer *m_animationTimer;
    QTimer *m_legendTimer;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , prochainId(1)
{
    ui->setupUi(this);
    termeRecherche.clear();
    critereTriIndex = 0;

    // Configuration du tableau
    ui->tableWidget->setColumnCount(10);
    QStringList headers = {"ID", "Nom", "Prénom", "Date d'embauche", "Date de naissance", 
                          "Salaire", "Poste", "Mot de passe", "Email", "État civil"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // Connexion des boutons
    connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::onAjouterClicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onModifierClicked);
    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::onSupprimerClicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::onExporterPdfClicked);
    connect(ui->pushButton_recherche, &QPushButton::clicked, this, &MainWindow::onRechercheClicked);
    connect(ui->pushButton_genererMotDePasse, &QPushButton::clicked, this, &MainWindow::onGenererMotDePasseClicked);
    connect(ui->lineEdit_recherche, &QLineEdit::returnPressed, this, &MainWindow::onRechercheClicked);
    connect(ui->comboBox_tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onTriChanged);
    connect(ui->pushButton_stats_poste, &QPushButton::clicked, this, &MainWindow::onAfficherStatistiquesPostes);
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &MainWindow::onTableItemClicked);
    connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::onDeconnecterClicked);
    ui->comboBox_tri->setCurrentIndex(0);

    // Initialisation (mode mémoire)
    afficherEmployes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAjouterClicked()
{
    Employe nouvEmploye = lireFormulaire();

    //  Vérification des champs obligatoires
    if (nouvEmploye.nom.isEmpty() ||
        nouvEmploye.prenom.isEmpty() ||
        nouvEmploye.email.isEmpty() ||
        nouvEmploye.poste.isEmpty() ||
        !nouvEmploye.dateEmbauche.isValid() ||
        !nouvEmploye.dateNaissance.isValid())
    {
        QMessageBox::warning(this, "Erreur",
            "Les champs obligatoires (Nom, Prénom, Email, Poste, Dates) sont vides !");
        return;
    }

    //  Vérification du nom (uniquement lettres et espaces)
    QRegularExpression regexNom("^[A-Za-zÀ-ÿ\\s'-]+$");
    if (!regexNom.match(nouvEmploye.nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur",
            "Le nom ne doit contenir que des lettres !");
        return;
    }

    //  Vérification du prénom (uniquement lettres et espaces)
    if (!regexNom.match(nouvEmploye.prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur",
            "Le prénom ne doit contenir que des lettres !");
        return;
    }

    //  Vérification de l'email
    QRegularExpression regexEmail(R"((^[\w\.-]+@[\w\.-]+\.[A-Za-z]{2,}$))");
    if (!regexEmail.match(nouvEmploye.email).hasMatch()) {
        QMessageBox::warning(this, "Erreur",
            "L'adresse email n'est pas valide !");
        return;
    }

    //  Vérification du poste (minimum 3 caractères)
    if (nouvEmploye.poste.length() < 3) {
        QMessageBox::warning(this, "Erreur",
            "Le poste doit contenir au moins 3 caractères !");
        return;
    }

    //  Vérification de la date d'embauche (pas dans le futur)
    if (nouvEmploye.dateEmbauche > QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur",
            "La date d'embauche ne peut pas être dans le futur !");
        return;
    }

    //  Vérification de la date de naissance (âge minimum 18 ans)
    int age = nouvEmploye.dateNaissance.daysTo(QDate::currentDate()) / 365;
    if (age < 18) {
        QMessageBox::warning(this, "Erreur",
            "L'employé doit avoir au moins 18 ans !");
        return;
    }

    //  Vérification des années d'expérience (pas négatif)
    if (nouvEmploye.anneesExperience < 0) {
        QMessageBox::warning(this, "Erreur",
            "Les années d'expérience doivent être positives !");
        return;
    }

    // Vérification du salaire (supérieur à 0)
    if (nouvEmploye.salaire <= 0) {
        QMessageBox::warning(this, "Erreur",
            "Le salaire doit être supérieur à 0 !");
        return;
    }

    //  Vérification de l'état civil
    if (nouvEmploye.etatCivil.isEmpty()) {
        QMessageBox::warning(this, "Erreur",
            "Veuillez sélectionner un état civil !");
        return;
    }

    //  Vérification de doublon sur l'email
    for (const Employe &emp : listeEmployes) {
        if (emp.id != nouvEmploye.id && emp.email == nouvEmploye.email) {
            QMessageBox::warning(this, "Erreur",
                "Un employé avec cette adresse email existe déjà !");
            return;
        }
    }

    //  Si tout est bon → ajouter l'employé (mémoire)
    if (nouvEmploye.id <= 0) {
        nouvEmploye.id = prochainId++;
    }

    if (!insererEmploye(nouvEmploye)) {
        return;
    }

    afficherEmployes();
    viderFormulaire();

    QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
}

void MainWindow::onModifierClicked()
{
    // Récupérer l'ID depuis le formulaire
    bool ok;
    int id = ui->lineEdit->text().toInt(&ok);

    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un employé à modifier.");
        return;
    }

    // Trouver l'index de l'employé
    int index = trouverIndexEmploye(id);

    if (index == -1) {
        QMessageBox::warning(this, "Erreur", "Employé non trouvé.");
        return;
    }

    // Validation
    Employe employeModifie = lireFormulaire();

    if (employeModifie.prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un prénom.");
        return;
    }

    if (employeModifie.poste.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un poste.");
        return;
    }

    // Mettre à jour l'ID
    employeModifie.id = id;

    if (!modifierEmployeBdd(employeModifie)) {
        return;
    }

    // Rafraîchir l'affichage
    afficherEmployes();

    // Vider le formulaire
    viderFormulaire();

    QMessageBox::information(this, "Succès", "Employé modifié avec succès!");
}

void MainWindow::onSupprimerClicked()
{
    // Récupérer l'ID depuis le formulaire
    bool ok;
    int id = ui->lineEdit->text().toInt(&ok);

    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un employé à supprimer.");
        return;
    }

    // Demander confirmation
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmation",
        "Êtes-vous sûr de vouloir supprimer cet employé ?",
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply != QMessageBox::Yes) {
        return;
    }

    // Trouver et supprimer l'employé
    int index = trouverIndexEmploye(id);

    if (index == -1) {
        QMessageBox::warning(this, "Erreur", "Employé non trouvé.");
        return;
    }

    if (!supprimerEmployeBdd(id)) {
        return;
    }

    // Rafraîchir l'affichage
    afficherEmployes();

    // Vider le formulaire
    viderFormulaire();

    QMessageBox::information(this, "Succès", "Employé supprimé avec succès!");
}

void MainWindow::onTableItemClicked(int row, int column)
{
    Q_UNUSED(column);

    if (row < 0 || row >= ui->tableWidget->rowCount()) {
        return;
    }

    // Récupérer l'ID de la ligne sélectionnée
    QTableWidgetItem* itemId = ui->tableWidget->item(row, 0);
    if (!itemId) {
        return;
    }

    bool ok;
    int id = itemId->text().toInt(&ok);
    if (!ok) {
        return;
    }

    // Trouver l'employé
    int index = trouverIndexEmploye(id);
    if (index == -1) {
        return;
    }

    // Remplir le formulaire
    remplirFormulaire(listeEmployes[index]);
}

void MainWindow::onRechercheClicked()
{
    termeRecherche = ui->lineEdit_recherche->text().trimmed();
    afficherEmployes();
}

void MainWindow::onTriChanged(int index)
{
    if (index < 0) {
        critereTriIndex = 0;
    } else {
        critereTriIndex = index;
    }
    afficherEmployes();
}


void MainWindow::onAfficherStatistiquesPostes()
{
    QSqlQuery query;
    if (!query.exec(QStringLiteral("SELECT POSTE, COUNT(*) FROM EMPLOYE GROUP BY POSTE"))) {
        QMessageBox::critical(this, "Base de données",
                              "Impossible de récupérer les statistiques :\n" + query.lastError().text());
        return;
    }

    QList<QPair<QString, int>> data;
    while (query.next()) {
        const QString poste = query.value(0).toString();
        const int count = query.value(1).toInt();
        if (poste.isEmpty() || count <= 0) {
            continue;
        }
        data.append(qMakePair(poste, count));
    }

    if (data.isEmpty()) {
        QMessageBox::information(this, "Statistiques par poste", "Aucun poste enregistré.");
        return;
    }

    QDialog dialog(this);
    dialog.setWindowTitle("Statistiques par poste");
    dialog.resize(600, 450);
    dialog.setStyleSheet(
        "QDialog {"
        "    background-color: #0a1628;"
        "    border-radius: 15px;"
        "}"
        "QLabel {"
        "    color: #ffffff;"
        "    font-family: 'Segoe UI';"
        "    font-size: 14px;"
        "}"
    );
    
    // Animation de fade-in pour la fenêtre
    dialog.setWindowOpacity(0.0);
    QPropertyAnimation *fadeIn = new QPropertyAnimation(&dialog, "windowOpacity");
    fadeIn->setDuration(400);
    fadeIn->setStartValue(0.0);
    fadeIn->setEndValue(1.0);
    fadeIn->setEasingCurve(QEasingCurve::InOutQuad);
    
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->setContentsMargins(20, 20, 20, 20);
    
    // Titre animé
    QLabel *titleLabel = new QLabel("📊 Statistiques par Poste", &dialog);
    titleLabel->setStyleSheet(
        "QLabel {"
        "    color: #ffffff;"
        "    font-family: 'Segoe UI';"
        "    font-size: 20px;"
        "    font-weight: bold;"
        "    padding: 10px;"
        "    background-color: rgba(58, 122, 254, 0.2);"
        "    border-radius: 10px;"
        "}"
    );
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);
    
    PostePieWidget *pieWidget = new PostePieWidget(data, &dialog);
    layout->addWidget(pieWidget);
    
    // Animation du titre
    titleLabel->setGraphicsEffect(nullptr);
    QGraphicsOpacityEffect *titleEffect = new QGraphicsOpacityEffect(titleLabel);
    titleLabel->setGraphicsEffect(titleEffect);
    QPropertyAnimation *titleFade = new QPropertyAnimation(titleEffect, "opacity");
    titleFade->setDuration(600);
    titleFade->setStartValue(0.0);
    titleFade->setEndValue(1.0);
    titleFade->setEasingCurve(QEasingCurve::OutCubic);
    
    // Démarrer les animations
    fadeIn->start();
    titleFade->start();

    dialog.exec();
}

void MainWindow::onExporterPdfClicked()
{
    if (ui->tableWidget->rowCount() == 0) {
        QMessageBox::information(this, "Export PDF", "Aucun employé à exporter.");
        return;
    }

    QString defaultPath = QDir::homePath() + "/employes.pdf";
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Exporter au format PDF",
        defaultPath,
        "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty()) {
        return;
    }

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageOrientation(QPageLayout::Landscape);

    QPainter painter(&writer);
    if (!painter.isActive()) {
        QMessageBox::critical(this, "Export PDF", "Impossible de créer le fichier PDF.");
        return;
    }

    QRect pageRect = writer.pageLayout().paintRectPixels(writer.resolution());
    QSize tableSize = ui->tableWidget->size();
    double xscale = pageRect.width() / static_cast<double>(tableSize.width());
    double yscale = pageRect.height() / static_cast<double>(tableSize.height());
    double scale = qMin(xscale, yscale);

    painter.translate(pageRect.topLeft());
    painter.scale(scale, scale);
    painter.setRenderHint(QPainter::Antialiasing);
    ui->tableWidget->render(&painter);
    painter.end();

    QMessageBox::information(this, "Export PDF", "Exportation réalisée avec succès.");
}

void MainWindow::afficherEmployes()
{
    if (!chargerEmployesDepuisBdd(termeRecherche, critereTriIndex)) {
        ui->tableWidget->setRowCount(0);
        return;
    }

    ui->tableWidget->setRowCount(0);

    for (const Employe& emp : listeEmployes) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Ordre des colonnes : ID, Nom, Prénom, Date d'embauche, Date de naissance, Salaire, Poste, Mot de passe, Email, État civil
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(emp.id)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(emp.nom));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(emp.prenom));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(emp.dateEmbauche.toString("dd/MM/yyyy")));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(emp.dateNaissance.toString("dd/MM/yyyy")));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(emp.salaire, 'f', 2)));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(emp.poste));
        // Afficher le mot de passe complet
        ui->tableWidget->setItem(row, 7, new QTableWidgetItem(emp.motDePasse.isEmpty() ? "Non défini" : emp.motDePasse));
        ui->tableWidget->setItem(row, 8, new QTableWidgetItem(emp.email));
        ui->tableWidget->setItem(row, 9, new QTableWidgetItem(emp.etatCivil));
    }
}

bool MainWindow::chargerEmployesDepuisBdd(const QString& filtreRecherche, int indexTri)
{
    listeEmployes.clear();
    QSqlQuery query;

    QString requete =
        QStringLiteral("SELECT ID, NOM, PRENOM, \"EMAIL\", NVL(\"MOT_DE_PASSE_EMPLOYE\", ''), DATE_DEMBAUCHE, POSTE, \"ANNÉE_EXPERIENCES\", "
                       "SALAIRE, DATE_NAISSANCE, ETAT_CIVIL FROM EMPLOYE");

    QString filtre = filtreRecherche.trimmed().toLower();
    if (!filtre.isEmpty()) {
        requete += QStringLiteral(" WHERE LOWER(TO_CHAR(ID)) LIKE :filtre_id "
                                  "OR LOWER(NOM) LIKE :filtre_nom "
                                  "OR LOWER(\"EMAIL\") LIKE :filtre_email "
                                  "OR LOWER(TO_CHAR(SALAIRE)) LIKE :filtre_salaire "
                                  "OR LOWER(POSTE) LIKE :filtre_poste");
    }

    switch (indexTri) {
    case 0:
        requete += QStringLiteral(" ORDER BY ID");
        break;
    case 1:
        requete += QStringLiteral(" ORDER BY SALAIRE");
        break;
    case 2:
        requete += QStringLiteral(" ORDER BY POSTE");
        break;
    default:
        requete += QStringLiteral(" ORDER BY ID");
        break;
    }

    query.prepare(requete);

    if (!filtre.isEmpty()) {
        QString like = "%" + filtre + "%";
        query.bindValue(":filtre_id", like);
        query.bindValue(":filtre_nom", like);
        query.bindValue(":filtre_email", like);
        query.bindValue(":filtre_salaire", like);
        query.bindValue(":filtre_poste", like);
    }

    if (!query.exec()) {
        QString error = query.lastError().text();
        
        // Si l'erreur indique que EMAIL n'existe pas, essayer sans guillemets
        if (error.contains("EMAIL", Qt::CaseInsensitive) && 
            error.contains("invalid identifier", Qt::CaseInsensitive)) {
            // Réessayer avec EMAIL sans guillemets (majuscules)
            requete = requete.replace("\"EMAIL\"", "EMAIL");
            query.prepare(requete);
            
            if (!filtre.isEmpty()) {
                QString like = "%" + filtre + "%";
                query.bindValue(":filtre_id", like);
                query.bindValue(":filtre_nom", like);
                query.bindValue(":filtre_email", like);
                query.bindValue(":filtre_salaire", like);
                query.bindValue(":filtre_poste", like);
            }
            
            if (!query.exec()) {
                QMessageBox::critical(this, "Base de données",
                                      "Impossible de charger les employés :\n" + query.lastError().text() +
                                      "\n\n⚠️ La colonne EMAIL n'existe pas dans la table EMPLOYE.\n"
                                      "Redémarrez l'application pour créer automatiquement la colonne.");
                return false;
            }
        } else {
            QMessageBox::critical(this, "Base de données",
                                  "Impossible de charger les employés :\n" + error);
            return false;
        }
    }

    int maxId = 0;
    while (query.next()) {
        Employe emp;
        emp.id = query.value(0).toInt();
        emp.nom = query.value(1).toString();
        emp.prenom = query.value(2).toString();
        emp.email = query.value(3).toString();
        emp.motDePasse = query.value(4).toString(); // Mot de passe
        emp.dateEmbauche = query.value(5).toDate();
        emp.poste = query.value(6).toString();
        emp.anneesExperience = query.value(7).toInt();
        emp.salaire = query.value(8).toDouble();
        emp.dateNaissance = query.value(9).toDate();
        emp.etatCivil = query.value(10).toString();
        listeEmployes.append(emp);
        if (emp.id > maxId) {
            maxId = emp.id;
        }
    }

    prochainId = maxId + 1;
    return true;
}

// Mode mémoire: pas de fonctions base de données

void MainWindow::viderFormulaire()
{
    ui->lineEdit->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_motDePasse->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->spinBox_2->setValue(0);
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
}

void MainWindow::remplirFormulaire(const Employe& employe)
{
    ui->lineEdit->setText(QString::number(employe.id));
    ui->lineEdit_nom->setText(employe.nom);
    ui->lineEdit_2->setText(employe.prenom);
    ui->lineEdit_email->setText(employe.email);
    ui->lineEdit_motDePasse->setText(employe.motDePasse);
    ui->dateEdit->setDate(employe.dateEmbauche);
    ui->lineEdit_3->setText(employe.poste);
    ui->spinBox_2->setValue(employe.anneesExperience);
    ui->lineEdit_4->setText(QString::number(employe.salaire));
    ui->dateEdit_2->setDate(employe.dateNaissance);

    // État civil
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);

    if (employe.etatCivil == "Célibataire") {
        ui->radioButton->setChecked(true);
    } else if (employe.etatCivil == "Marié(e)") {
        ui->radioButton_2->setChecked(true);
    } else if (employe.etatCivil == "Divorcé(e)") {
        ui->radioButton_3->setChecked(true);
    }
}

Employe MainWindow::lireFormulaire() const
{
    Employe emp;

    // ID (peut être vide pour un nouvel employé)
    emp.id = ui->lineEdit->text().toInt();

    // Nom
    emp.nom = ui->lineEdit_nom->text().trimmed();

    // Prénom
    emp.prenom = ui->lineEdit_2->text().trimmed();

    // Email
    emp.email = ui->lineEdit_email->text().trimmed();

    // Mot de passe
    emp.motDePasse = ui->lineEdit_motDePasse->text().trimmed();
    // Si le mot de passe est vide, générer un mot de passe unique automatiquement
    if (emp.motDePasse.isEmpty()) {
        emp.motDePasse = genererMotDePasseUnique(emp.nom, emp.prenom, emp.id);
    }

    // Date d'embauche
    emp.dateEmbauche = ui->dateEdit->date();

    // Poste
    emp.poste = ui->lineEdit_3->text().trimmed();

    // Années d'expérience
    emp.anneesExperience = ui->spinBox_2->value();

    // Salaire
    bool ok;
    emp.salaire = ui->lineEdit_4->text().toDouble(&ok);
    if (!ok) {
        emp.salaire = 0.0;
    }

    // Date de naissance
    emp.dateNaissance = ui->dateEdit_2->date();

    // État civil
    if (ui->radioButton->isChecked()) {
        emp.etatCivil = "Célibataire";
    } else if (ui->radioButton_2->isChecked()) {
        emp.etatCivil = "Marié(e)";
    } else if (ui->radioButton_3->isChecked()) {
        emp.etatCivil = "Divorcé(e)";
    } else {
        emp.etatCivil = "";
    }

    return emp;
}

bool MainWindow::insererEmploye(const Employe& employe)
{
    QSqlQuery query;
    query.prepare(QStringLiteral(
        "INSERT INTO EMPLOYE "
        "(ID, NOM, PRENOM, \"EMAIL\", \"MOT_DE_PASSE_EMPLOYE\", DATE_DEMBAUCHE, POSTE, \"ANNÉE_EXPERIENCES\", SALAIRE, DATE_NAISSANCE, ETAT_CIVIL) "
        "VALUES (:id, :nom, :prenom, :email, :mot_de_passe, :date_embauche, :poste, :annees, :salaire, :date_naissance, :etat_civil)"));
    query.bindValue(":id", employe.id);
    query.bindValue(":nom", employe.nom);
    query.bindValue(":prenom", employe.prenom);
    query.bindValue(":email", employe.email);
    query.bindValue(":mot_de_passe", employe.motDePasse);
    query.bindValue(":date_embauche", employe.dateEmbauche);
    query.bindValue(":poste", employe.poste);
    query.bindValue(":annees", employe.anneesExperience);
    query.bindValue(":salaire", employe.salaire);
    query.bindValue(":date_naissance", employe.dateNaissance);
    query.bindValue(":etat_civil", employe.etatCivil);

    if (!query.exec()) {
        QString error = query.lastError().text();
        QString message = "Impossible d'ajouter l'employé :\n" + error;
        
        // Si l'erreur indique que la table ou une colonne n'existe pas
        if (error.contains("invalid identifier", Qt::CaseInsensitive) || 
            error.contains("table or view does not exist", Qt::CaseInsensitive) ||
            error.contains("table ou vue n'existe pas", Qt::CaseInsensitive)) {
            
            // Essayer de créer la table automatiquement
            QMessageBox::information(this, "Création de la table",
                                     "La table EMPLOYE n'existe pas.\n"
                                     "Création automatique en cours...");
            
            Connection c;
            if (c.creerTableEmploye()) {
                // Réessayer l'insertion
                query.prepare(QStringLiteral(
                    "INSERT INTO EMPLOYE "
                    "(ID, NOM, PRENOM, \"EMAIL\", \"MOT_DE_PASSE_EMPLOYE\", DATE_DEMBAUCHE, POSTE, \"ANNÉE_EXPERIENCES\", SALAIRE, DATE_NAISSANCE, ETAT_CIVIL) "
                    "VALUES (:id, :nom, :prenom, :email, :mot_de_passe, :date_embauche, :poste, :annees, :salaire, :date_naissance, :etat_civil)"));
                query.bindValue(":id", employe.id);
                query.bindValue(":nom", employe.nom);
                query.bindValue(":prenom", employe.prenom);
                query.bindValue(":email", employe.email);
                query.bindValue(":mot_de_passe", employe.motDePasse);
                query.bindValue(":date_embauche", employe.dateEmbauche);
                query.bindValue(":poste", employe.poste);
                query.bindValue(":annees", employe.anneesExperience);
                query.bindValue(":salaire", employe.salaire);
                query.bindValue(":date_naissance", employe.dateNaissance);
                query.bindValue(":etat_civil", employe.etatCivil);
                
                if (query.exec()) {
                    QMessageBox::information(this, "Succès",
                                             "✅ La table EMPLOYE a été créée automatiquement.\n\n"
                                             "L'employé a été ajouté avec succès.\n\n"
                                             "Les colonnes EMAIL et MOT_DE_PASSE_EMPLOYE ont été incluses.");
                    return true;
                } else {
                    QMessageBox::critical(this, "Erreur",
                                         "La table a été créée mais l'insertion a échoué :\n" + 
                                         query.lastError().text());
                    return false;
                }
            } else {
                QMessageBox::critical(this, "Erreur",
                                     "Impossible de créer la table EMPLOYE.\n\n"
                                     "Vérifiez les permissions de votre utilisateur de base de données.\n"
                                     "Ou exécutez manuellement le script : create_table_employe.sql");
            }
            
            message += "\n\n⚠️ La table EMPLOYE ou certaines colonnes n'existent pas.\n\n"
                       "Solution : Redémarrez l'application pour créer automatiquement la table.\n"
                       "Ou exécutez manuellement le script : create_table_employe.sql";
        }
        
        QMessageBox::critical(this, "Base de données", message);
        return false;
    }
    return true;
}

bool MainWindow::modifierEmployeBdd(const Employe& employe)
{
    QSqlQuery query;
    query.prepare(QStringLiteral(
        "UPDATE EMPLOYE SET "
        "NOM = :nom, PRENOM = :prenom, \"EMAIL\" = :email, \"MOT_DE_PASSE_EMPLOYE\" = :mot_de_passe, "
        "DATE_DEMBAUCHE = :date_embauche, POSTE = :poste, "
        "\"ANNÉE_EXPERIENCES\" = :annees, SALAIRE = :salaire, "
        "DATE_NAISSANCE = :date_naissance, ETAT_CIVIL = :etat_civil "
        "WHERE ID = :id"));
    query.bindValue(":nom", employe.nom);
    query.bindValue(":prenom", employe.prenom);
    query.bindValue(":email", employe.email);
    query.bindValue(":mot_de_passe", employe.motDePasse);
    query.bindValue(":date_embauche", employe.dateEmbauche);
    query.bindValue(":poste", employe.poste);
    query.bindValue(":annees", employe.anneesExperience);
    query.bindValue(":salaire", employe.salaire);
    query.bindValue(":date_naissance", employe.dateNaissance);
    query.bindValue(":etat_civil", employe.etatCivil);
    query.bindValue(":id", employe.id);

    if (!query.exec()) {
        QString error = query.lastError().text();
        QString message = "Impossible de modifier l'employé :\n" + error;
        
        // Si l'erreur indique que la table ou une colonne n'existe pas
        if (error.contains("invalid identifier", Qt::CaseInsensitive) || 
            error.contains("table or view does not exist", Qt::CaseInsensitive) ||
            error.contains("table ou vue n'existe pas", Qt::CaseInsensitive)) {
            
            // Essayer de créer la table automatiquement
            Connection c;
            if (c.creerTableEmploye()) {
                // Réessayer la mise à jour
                query.prepare(QStringLiteral(
                    "UPDATE EMPLOYE SET "
                    "NOM = :nom, PRENOM = :prenom, \"EMAIL\" = :email, \"MOT_DE_PASSE_EMPLOYE\" = :mot_de_passe, "
                    "DATE_DEMBAUCHE = :date_embauche, POSTE = :poste, "
                    "\"ANNÉE_EXPERIENCES\" = :annees, SALAIRE = :salaire, "
                    "DATE_NAISSANCE = :date_naissance, ETAT_CIVIL = :etat_civil "
                    "WHERE ID = :id"));
                query.bindValue(":nom", employe.nom);
                query.bindValue(":prenom", employe.prenom);
                query.bindValue(":email", employe.email);
                query.bindValue(":mot_de_passe", employe.motDePasse);
                query.bindValue(":date_embauche", employe.dateEmbauche);
                query.bindValue(":poste", employe.poste);
                query.bindValue(":annees", employe.anneesExperience);
                query.bindValue(":salaire", employe.salaire);
                query.bindValue(":date_naissance", employe.dateNaissance);
                query.bindValue(":etat_civil", employe.etatCivil);
                query.bindValue(":id", employe.id);
                
                if (query.exec()) {
                    QMessageBox::information(this, "Succès",
                                             "La table EMPLOYE a été créée automatiquement.\n"
                                             "L'employé a été modifié avec succès.");
                    return true;
                }
            }
            
            message += "\n\n⚠️ La table EMPLOYE ou certaines colonnes n'existent pas.\n\n"
                       "Solution : Redémarrez l'application pour créer automatiquement la table.\n"
                       "Ou exécutez manuellement le script : create_table_employe.sql";
        }
        
        QMessageBox::critical(this, "Base de données", message);
        return false;
    }
    return true;
}

bool MainWindow::supprimerEmployeBdd(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE ID = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        QMessageBox::critical(this, "Base de données",
                              "Impossible de supprimer l'employé :\n" + query.lastError().text());
        return false;
    }
    return true;
}

int MainWindow::trouverIndexEmploye(int id) const
{
    for (int i = 0; i < listeEmployes.size(); ++i) {
        if (listeEmployes[i].id == id) {
            return i;
        }
    }
    return -1;
}

QString MainWindow::genererMotDePasseUnique(const QString& nom, const QString& prenom, int id) const
{
    // Générer un mot de passe unique basé sur le nom, prénom et ID
    // Format: Première lettre du prénom + 3 premières lettres du nom + ID + caractères spéciaux
    QString motDePasse;
    
    if (!prenom.isEmpty() && !nom.isEmpty()) {
        QString premiereLettrePrenom = prenom.left(1).toUpper();
        QString troisPremieresLettresNom = nom.left(3).toUpper();
        motDePasse = premiereLettrePrenom + troisPremieresLettresNom + QString::number(id) + "!@#";
    } else {
        // Si nom ou prénom vide, générer un mot de passe aléatoire
        qsrand(QDateTime::currentDateTime().toTime_t());
        QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%";
        motDePasse = "EMP" + QString::number(id);
        for (int i = 0; i < 6; ++i) {
            int index = qrand() % chars.length();
            motDePasse += chars[index];
        }
    }
    
    return motDePasse;
}

void MainWindow::onGenererMotDePasseClicked()
{
    // Générer un mot de passe basé sur les informations du formulaire
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_2->text().trimmed();
    QString idStr = ui->lineEdit->text().trimmed();
    int id = idStr.isEmpty() ? prochainId : idStr.toInt();
    
    QString motDePasse = genererMotDePasseUnique(nom, prenom, id);
    ui->lineEdit_motDePasse->setText(motDePasse);
    
    QMessageBox::information(this, "Mot de passe généré",
                             QString("Un mot de passe unique a été généré :\n\n%1\n\n"
                                     "Notez-le bien, il sera utilisé pour l'authentification de cet employé.")
                             .arg(motDePasse));
}

void MainWindow::onDeconnecterClicked()
{
    int reponse = QMessageBox::question(this, "Déconnexion",
                                        "Êtes-vous sûr de vouloir vous déconnecter ?",
                                        QMessageBox::Yes | QMessageBox::No,
                                        QMessageBox::No);
    
    if (reponse == QMessageBox::Yes) {
        // Fermer la fenêtre principale pour revenir à l'écran de login
        // La fermeture de la fenêtre déclenchera le signal destroyed() dans main.cpp
        // qui quittera l'event loop et affichera à nouveau le login
        this->close();
    }
}
