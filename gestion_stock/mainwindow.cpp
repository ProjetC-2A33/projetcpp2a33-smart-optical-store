#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QInputDialog>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setStyleSheet(R"(
/* ===== STYLES GÉNÉRAUX (texte clair) ===== */
/* ===== STYLES GÉNÉRAUX - THÈME BLEU FONCÉ ===== */
QMainWindow {
    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #0D1B2A, stop:1 #1B263B);
}

QPushButton {
    background-color: #1E3A5F;
    color: #E0E1DD;
    border-radius: 8px;
    padding: 10px;
    font-weight: bold;
    border: 2px solid #415A77;
    font-size: 14px;
}

QPushButton:hover {
    background-color: #2E4C7E;
    border: 2px solid #4A689A;
}

QPushButton:pressed {
    background-color: #152642;
    border: 2px solid #1E3A5F;
}

QLineEdit {
    border: 2px solid #415A77;
    border-radius: 8px;
    padding: 8px;
    background-color: #1B263B;
    color: #E0E1DD;
    font-size: 14px;
    selection-background-color: #415A77;
}

QLineEdit:focus {
    border: 2px solid #4A689A;
    background-color: #0D1B2A;
}

QLabel {
    color: #E0E1DD;
    font-weight: bold;
    font-size: 14px;
    background-color: transparent;
}

QGroupBox {
    border: 2px solid #415A77;
    border-radius: 8px;
    margin-top: 10px;
    padding-top: 10px;
    background-color: rgba(13, 27, 42, 0.9);
    color: #E0E1DD;
    font-weight: bold;
}

QGroupBox::title {
    subcontrol-origin: margin;
    subcontrol-position: top center;
    padding: 5px 10px;
    background-color: #1E3A5F;
    color: #E0E1DD;
    border-radius: 4px;
}

QTableWidget {
    background-color: #0D1B2A;
    border: 2px solid #415A77;
    gridline-color: #415A77;
    selection-background-color: #2E4C7E;
    selection-color: #E0E1DD;
    color: #E0E1DD;
    font-size: 13px;
}

QHeaderView::section {
    background-color: #1E3A5F;
    color: #E0E1DD;
    font-weight: bold;
    padding: 8px;
    border: 1px solid #415A77;
}

QComboBox {
    border: 2px solid #415A77;
    border-radius: 8px;
    padding: 6px;
    background-color: #1B263B;
    color: #E0E1DD;
    min-width: 6em;
}

QComboBox::drop-down {
    border: none;
}

QComboBox QAbstractItemView {
    border: 2px solid #415A77;
    background-color: #0D1B2A;
    color: #E0E1DD;
    selection-background-color: #2E4C7E;
}

QDateEdit {
    border: 2px solid #415A77;
    border-radius: 8px;
    padding: 6px;
    background-color: #1B263B;
    color: #E0E1DD;
}

QSpinBox {
    border: 2px solid #415A77;
    border-radius: 8px;
    padding: 6px;
    background-color: #1B263B;
    color: #E0E1DD;
}

QTextEdit {
    background-color: #1B263B;
    color: #E0E1DD;
    border: 2px solid #415A77;
    border-radius: 8px;
    padding: 8px;
}

/* ===== STYLES POUR LES MESSAGES SEULEMENT - TEXTE NOIR ===== */

/* QInputDialog - Messages en NOIR */
QInputDialog {
    background-color: #FFFFFF;
    border: 3px solid #007BFF;
    border-radius: 10px;
}

QInputDialog QLabel {
    color: #000000 !important;
    background-color: #E3F2FD;
    padding: 12px;
    border-radius: 6px;
    font-weight: bold;
    font-size: 14px;
    border: 2px solid #64B5F6;
    margin: 8px;
}

QInputDialog QLineEdit {
    background-color: #FFFFFF;
    color: #000000;
    border: 2px solid #6C757D;
    border-radius: 6px;
    padding: 10px;
    font-size: 14px;
    margin: 8px;
    selection-background-color: #007BFF;
    selection-color: #FFFFFF;
}

QInputDialog QLineEdit:focus {
    border: 2px solid #007BFF;
    background-color: #F8F9FA;
}

QInputDialog QPushButton {
    background-color: #007BFF;
    color: #FFFFFF;
    border: 2px solid #0056B3;
    border-radius: 6px;
    padding: 8px 16px;
    font-weight: bold;
    min-width: 80px;
    margin: 5px;
}

QInputDialog QPushButton:hover {
    background-color: #0056B3;
    border: 2px solid #004085;
}

/* QMessageBox - Messages en NOIR */
QMessageBox {
    background-color: #FFFFFF;
    border: 3px solid #6C757D;
    border-radius: 10px;
}

QMessageBox QLabel {
    color: #000000 !important;
    background-color: #F8F9FA;
    padding: 15px;
    border-radius: 8px;
    font-size: 14px;
    font-weight: bold;
    border: 1px solid #DEE2E6;
    margin: 10px;
}

QMessageBox QPushButton {
    background-color: #6C757D;
    color: #FFFFFF;
    border: 2px solid #545B62;
    border-radius: 6px;
    padding: 8px 16px;
    font-weight: bold;
    min-width: 80px;
    margin: 5px;
}

QMessageBox QPushButton:hover {
    background-color: #545B62;
}

/* Message Box d'information (bleu) */
QMessageBox[windowTitle*="information"] {
    border: 3px solid #007BFF;
}

QMessageBox[windowTitle*="information"] QLabel {
    background-color: #E3F2FD;
    border: 1px solid #64B5F6;
}

QMessageBox[windowTitle*="information"] QPushButton {
    background-color: #007BFF;
    border: 2px solid #0056B3;
}

/* Message Box d'avertissement (orange) */
QMessageBox[windowTitle*="warning"],
QMessageBox[windowTitle*="avertissement"] {
    border: 3px solid #FFC107;
}

QMessageBox[windowTitle*="warning"] QLabel,
QMessageBox[windowTitle*="avertissement"] QLabel {
    background-color: #FFF3CD;
    border: 1px solid #FFEaa7;
}

QMessageBox[windowTitle*="warning"] QPushButton,
QMessageBox[windowTitle*="avertissement"] QPushButton {
    background-color: #FFC107;
    border: 2px solid #E0A800;
    color: #000000;
}

/* Message Box d'erreur (rouge) */
QMessageBox[windowTitle*="error"],
QMessageBox[windowTitle*="erreur"] {
    border: 3px solid #DC3545;
}

QMessageBox[windowTitle*="error"] QLabel,
QMessageBox[windowTitle*="erreur"] QLabel {
    background-color: #F8D7DA;
    border: 1px solid #F5C6CB;
}

QMessageBox[windowTitle*="error"] QPushButton,
QMessageBox[windowTitle*="erreur"] QPushButton {
    background-color: #DC3545;
    border: 2px solid #C82333;
}

/* Message Box de question */
QMessageBox[windowTitle*="question"],
QMessageBox[windowTitle*="confirmation"] {
    border: 3px solid #28A745;
}

QMessageBox[windowTitle*="question"] QLabel,
QMessageBox[windowTitle*="confirmation"] QLabel {
    background-color: #D4EDDA;
    border: 1px solid #C3E6CB;
}

QMessageBox[windowTitle*="question"] QPushButton,
QMessageBox[windowTitle*="confirmation"] QPushButton {
    background-color: #28A745;
    border: 2px solid #1E7E34;
}

/* ===== STYLES POUR LES BOÎTES DE DIALOGUE PERSONNALISÉES ===== */

/* Dialogue de modification */
QDialog[windowTitle*="Modification"] {
    background-color: #FFFFFF;
    border: 3px solid #007BFF;
    border-radius: 10px;
}

QDialog[windowTitle*="Modification"] QLabel {
    color: #000000;
    background-color: #E3F2FD;
    padding: 12px;
    border-radius: 6px;
    font-weight: bold;
    font-size: 14px;
    border: 2px solid #64B5F6;
}

/* Dialogue de suppression */
QDialog[windowTitle*="Suppression"] {
    background-color: #FFFFFF;
    border: 3px solid #DC3545;
    border-radius: 10px;
}

QDialog[windowTitle*="Suppression"] QLabel {
    color: #000000;
    background-color: #F8D7DA;
    padding: 12px;
    border-radius: 6px;
    font-weight: bold;
    font-size: 14px;
    border: 2px solid #F5C6CB;
}

/* ===== STYLES POUR LES ÉLÉMENTS SPÉCIFIQUES ===== */

/* Radio buttons et checkboxes */
QRadioButton, QCheckBox {
    color: #E0E1DD;
    font-size: 14px;
}

QRadioButton::indicator, QCheckBox::indicator {
    width: 16px;
    height: 16px;
}

QRadioButton::indicator::unchecked {
    border: 2px solid #415A77;
    border-radius: 8px;
    background-color: #1B263B;
}

QRadioButton::indicator::checked {
    border: 2px solid #4A689A;
    border-radius: 8px;
    background-color: #2E4C7E;
}

QCheckBox::indicator::unchecked {
    border: 2px solid #415A77;
    background-color: #1B263B;
}

QCheckBox::indicator::checked {
    border: 2px solid #4A689A;
    background-color: #2E4C7E;
}

/* Scrollbars */
QScrollBar:vertical {
    background-color: #1B263B;
    width: 12px;
    margin: 0px;
}

QScrollBar::handle:vertical {
    background-color: #415A77;
    border-radius: 6px;
    min-height: 20px;
}

QScrollBar::handle:vertical:hover {
    background-color: #4A689A;
}

QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
    border: none;
    background: none;
}

/* Progress bars */
QProgressBar {
    border: 2px solid #415A77;
    border-radius: 6px;
    background-color: #1B263B;
    text-align: center;
    color: #E0E1DD;
}

QProgressBar::chunk {
    background-color: #2E4C7E;
    border-radius: 4px;
}
    )");
    // Vérification de la connexion
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Base de données non connectée!");
    } else {
        qDebug() << "✅ Base de données connectée avec succès";
    }
    // Configuration initiale
    ui->comboBox->addItem("Informatique");
    ui->comboBox->addItem("Électronique");
    ui->comboBox->addItem("Mobilier");
    ui->comboBox->addItem("Fournitures");


    QPixmap image(":/stat.png");
    ui->labelImage->setPixmap(image);
    ui->labelImage->setScaledContents(true);
    ui->stackedWidget->setCurrentIndex(0);
    // VALIDATEURS en temps réel
    // Référence : uniquement des chiffres
    /*QRegularExpressionValidator *refValidator = new QRegularExpressionValidator(QRegularExpression("\\d*"), this);
    ui->lineEdit_3->setValidator(refValidator);

    // Quantité : uniquement des chiffres
    QRegularExpressionValidator *qteValidator = new QRegularExpressionValidator(QRegularExpression("\\d*"), this);
    ui->lineEdit_2->setValidator(qteValidator);

    // Prix : chiffres avec point décimal
    QRegularExpressionValidator *prixValidator = new QRegularExpressionValidator(QRegularExpression("\\d*\\.?\\d*"), this);
    ui->lineEdit_4->setValidator(prixValidator); */
    // Connexions
    connect(ui->btnLogin, &QPushButton::clicked, this, &MainWindow::onLoginClicked);

    // Connexion des boutons CRUD
    connect(ui->pushButton_21, &QPushButton::clicked, this, &MainWindow::on_btnAjouter_clicked);
    connect(ui->pushButton_17, &QPushButton::clicked, this, &MainWindow::on_btnModifier_clicked);
    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::on_btnSupprimer_clicked);






    // Navigation depuis la page Stock (index 1)
    connect(ui->btnGestionClients_PageStock, &QPushButton::clicked, this, &MainWindow::on_btnGestionClients_PageStock_clicked);
    connect(ui->btnGestionEmployes_PageStock, &QPushButton::clicked, this, &MainWindow::on_btnGestionEmployes_PageStock_clicked);
    connect(ui->btnGestionSponsors_PageStock, &QPushButton::clicked, this, &MainWindow::on_btnGestionSponsors_PageStock_clicked);
    connect(ui->btnGestionFournisseurs_PageStock, &QPushButton::clicked, this, &MainWindow::on_btnGestionFournisseurs_PageStock_clicked);
    connect(ui->btnBack_PageStock, &QPushButton::clicked, this, &MainWindow::on_btnBack_PageStock_clicked);

    // Navigation depuis la page Clients (index 2)
    connect(ui->btnGestionStock_PageClients, &QPushButton::clicked, this, &MainWindow::on_btnGestionStock_PageClients_clicked);
    connect(ui->btnGestionEmployes_PageClients, &QPushButton::clicked, this, &MainWindow::on_btnGestionEmployes_PageClients_clicked);
    connect(ui->btnGestionSponsors_PageClients, &QPushButton::clicked, this, &MainWindow::on_btnGestionSponsors_PageClients_clicked);
    connect(ui->btnGestionFournisseurs_PageClients, &QPushButton::clicked, this, &MainWindow::on_btnGestionFournisseurs_PageClients_clicked);
    connect(ui->btnBack_PageClients, &QPushButton::clicked, this, &MainWindow::on_btnBack_PageClients_clicked);

    // Navigation depuis la page Employés (index 3)
    connect(ui->btnGestionStock_Page_Employes, &QPushButton::clicked, this, &MainWindow::on_btnGestionStock_Page_Employes_clicked);
    connect(ui->btnGestionClients_Page_Employes, &QPushButton::clicked, this, &MainWindow::on_btnGestionClients_Page_Employes_clicked);
    connect(ui->btnGestionSponsors_Page_Employes, &QPushButton::clicked, this, &MainWindow::on_btnGestionSponsors_Page_Employes_clicked);
    connect(ui->btnGestionFournisseurs_PageClients, &QPushButton::clicked, this, &MainWindow::on_btnGestionFournisseurs_Page_Employes_clicked);
    connect(ui->btnBack_Page_Employes, &QPushButton::clicked, this, &MainWindow::on_btnBack_Page_Employes_clicked);

    // Navigation depuis la page Sponsors (index 4)
    connect(ui->btnGestionStock_Page_Sponsors, &QPushButton::clicked, this, &MainWindow::on_btnGestionStock_Page_Sponsors_clicked);
    connect(ui->btnGestionClients_Page_Sponsors, &QPushButton::clicked, this, &MainWindow::on_btnGestionClients_Page_Sponsors_clicked);
    connect(ui->btnGestionEmployes_Page_Sponsors, &QPushButton::clicked, this, &MainWindow::on_btnGestionEmployes_Page_Sponsors_clicked);
    connect(ui->btnGestionFournisseurs_Page_Sponsors, &QPushButton::clicked, this, &MainWindow::on_btnGestionFournisseurs_Page_Sponsors_clicked);
    connect(ui->btnBack_Page_Sponsors, &QPushButton::clicked, this, &MainWindow::on_btnBack_Page_Sponsors_clicked);

    // Navigation depuis la page Fournisseurs (index 5)
    connect(ui->btnGestionStock_Page_Fournisseurs, &QPushButton::clicked, this, &MainWindow::on_btnGestionStock_Page_Fournisseurs_clicked);
    connect(ui->btnGestionClients_Page_Fournisseurs, &QPushButton::clicked, this, &MainWindow::on_btnGestionClients_Page_Fournisseurs_clicked);
    connect(ui->btnGestionEmployes_PageFournisseurs, &QPushButton::clicked, this, &MainWindow::on_btnGestionEmployes_PageFournisseurs_clicked);
    connect(ui->btnGestionSponsors_Page_Fournisseurs, &QPushButton::clicked, this, &MainWindow::on_btnGestionSponsors_Page_Fournisseurs_clicked);
    connect(ui->btnBack_Page_Fournisseurs, &QPushButton::clicked, this, &MainWindow::on_btnBack_Page_Fournisseurs_clicked);
    // Configuration du tableWidget
    ui->tableWidget->setColumnCount(9);
    QStringList headers;
    headers << "ID" << "Nom" << "Quantité" << "Prix" << "Catégorie" << "Référence"
            << "Fournisseur" << "Date Fabrication" << "Date Expiration";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Affichage initial des produits
    afficherProduits();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherProduits()
{
    produitTemp.remplirTableWidget(ui->tableWidget);
}

//////////////////////////////////////// Modifier :

void MainWindow::on_btnModifier_clicked()
{
    qDebug() << "=== BOUTON MODIFIER CLIQUE ===";

    // 1. Récupérer les données depuis l'interface
    QString nouvelleReference = ui->lineEdit_3->text().trimmed();
    QString nouveauNom = ui->lineEdit->text().trimmed();
    QString nouvelleQuantiteStr = ui->lineEdit_2->text().trimmed();
    QString nouveauPrixStr = ui->lineEdit_4->text().trimmed();
    QString nouveauFournisseur = ui->lineEdit_5->text().trimmed();
    QString nouvelleCategory = ui->comboBox->currentText();
    QDate nouvelleDateFab = ui->dateEdit->date();
    QDate nouvelleDateExp = ui->dateEdit_2->date();

    // 2. CONTRÔLES DE SAISIE POUR LA MODIFICATION

    // Nouvelle référence : doit être un nombre positif
    if(nouvelleReference.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "La nouvelle référence est obligatoire");
        ui->lineEdit_3->setFocus();
        return;
    }

    bool okNewRef;
    int nouvelleRefNum = nouvelleReference.toInt(&okNewRef);
    if(!okNewRef || nouvelleRefNum <= 0) {
        QMessageBox::warning(this, "Erreur", "La nouvelle référence doit être un nombre positif");
        ui->lineEdit_3->selectAll();
        ui->lineEdit_3->setFocus();
        return;
    }

    // Demander l'ancienne référence
    QString ancienneReference = QInputDialog::getText(this, "Modification",
                                                      "Ancienne référence du produit à modifier:");

    if(ancienneReference.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ancienne référence est obligatoire");
        return;
    }

    // Vérifier que l'ancienne référence est valide
    bool okOldRef;
    int ancienneRefNum = ancienneReference.toInt(&okOldRef);
    if(!okOldRef || ancienneRefNum <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ancienne référence doit être un nombre positif");
        return;
    }

    // Vérifier que le produit existe (avec l'ancienne référence)
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM PRODUIT WHERE REFERENCE = :ref");
    checkQuery.bindValue(":ref", ancienneRefNum);
    if(!checkQuery.exec() || !checkQuery.next() || checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucun produit trouvé avec cette référence");
        return;
    }

    // Vérifier que la nouvelle référence n'existe pas déjà (sauf si c'est la même)
    if(nouvelleRefNum != ancienneRefNum) {
        QSqlQuery checkNewRefQuery;
        checkNewRefQuery.prepare("SELECT COUNT(*) FROM PRODUIT WHERE REFERENCE = :ref");
        checkNewRefQuery.bindValue(":ref", nouvelleRefNum);
        if(checkNewRefQuery.exec() && checkNewRefQuery.next() && checkNewRefQuery.value(0).toInt() > 0) {
            QMessageBox::warning(this, "Erreur", "La nouvelle référence existe déjà!");
            ui->lineEdit_3->selectAll();
            ui->lineEdit_3->setFocus();
            return;
        }
    }

    // Nom : non vide, longueur raisonnable
    if(nouveauNom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom du produit est obligatoire");
        ui->lineEdit->setFocus();
        return;
    }

    if(nouveauNom.length() > 100) {
        QMessageBox::warning(this, "Erreur", "Le nom est trop long (max 100 caractères)");
        ui->lineEdit->selectAll();
        ui->lineEdit->setFocus();
        return;
    }

    // Quantité : nombre positif
    if(nouvelleQuantiteStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "La quantité est obligatoire");
        ui->lineEdit_2->setFocus();
        return;
    }

    bool okQte;
    int nouvelleQuantite = nouvelleQuantiteStr.toInt(&okQte);
    if(!okQte || nouvelleQuantite <= 0) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être un nombre positif");
        ui->lineEdit_2->selectAll();
        ui->lineEdit_2->setFocus();
        return;
    }

    if(nouvelleQuantite > 10000) {
        QMessageBox::warning(this, "Erreur", "La quantité est trop élevée (max 10000)");
        ui->lineEdit_2->selectAll();
        ui->lineEdit_2->setFocus();
        return;
    }

    // Prix : nombre positif avec 2 décimales max
    if(nouveauPrixStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le prix est obligatoire");
        ui->lineEdit_4->setFocus();
        return;
    }

    bool okPrix;
    double nouveauPrix = nouveauPrixStr.toDouble(&okPrix);
    if(!okPrix || nouveauPrix <= 0) {
        QMessageBox::warning(this, "Erreur", "Le prix doit être un nombre positif");
        ui->lineEdit_4->selectAll();
        ui->lineEdit_4->setFocus();
        return;
    }

    if(nouveauPrix > 1000000) {
        QMessageBox::warning(this, "Erreur", "Le prix est trop élevé");
        ui->lineEdit_4->selectAll();
        ui->lineEdit_4->setFocus();
        return;
    }

    // Vérifier le format des décimales
    if(nouveauPrixStr.contains('.') && nouveauPrixStr.split('.')[1].length() > 2) {
        QMessageBox::warning(this, "Erreur", "Le prix ne peut avoir que 2 décimales maximum");
        ui->lineEdit_4->selectAll();
        ui->lineEdit_4->setFocus();
        return;
    }

    // Fournisseur : longueur raisonnable
    if(nouveauFournisseur.length() > 100) {
        QMessageBox::warning(this, "Erreur", "Le nom du fournisseur est trop long (max 100 caractères)");
        ui->lineEdit_5->selectAll();
        ui->lineEdit_5->setFocus();
        return;
    }

    // Catégorie : doit être sélectionnée
    if(nouvelleCategory.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une catégorie");
        ui->comboBox->setFocus();
        return;
    }

    // Dates : date expiration > date fabrication
    if(nouvelleDateExp <= nouvelleDateFab) {
        QMessageBox::warning(this, "Erreur", "La date d'expiration doit être après la date de fabrication");
        ui->dateEdit_2->setFocus();
        return;
    }

    // 3. Confirmation avant modification
    QMessageBox::StandardButton confirmation;
    confirmation = QMessageBox::question(this, "Confirmation",
                                         QString("Êtes-vous sûr de vouloir modifier ce produit ?\n\n"
                                                 "Ancienne référence: %1\n"
                                                 "Nouvelle référence: %2\n"
                                                 "Nouveau nom: %3\n"
                                                 "Nouvelle quantité: %4\n"
                                                 "Nouveau prix: %5 €")
                                             .arg(ancienneReference)
                                             .arg(nouvelleReference)
                                             .arg(nouveauNom)
                                             .arg(nouvelleQuantite)
                                             .arg(nouveauPrix, 0, 'f', 2),
                                         QMessageBox::Yes | QMessageBox::No);

    if(confirmation != QMessageBox::Yes) {
        return;
    }

    // 4. Configuration du produit avec les NOUVELLES données
    produitTemp.setREFERENCE(nouvelleReference);
    produitTemp.setNOM(nouveauNom);
    produitTemp.setQUANTITE(nouvelleQuantite);
    produitTemp.setPRIX(nouveauPrix);
    produitTemp.setCATEGORY(nouvelleCategory);
    produitTemp.setFOURNISSEURS(nouveauFournisseur);
    produitTemp.setDATE_FAB(nouvelleDateFab);
    produitTemp.setDATE_EXP(nouvelleDateExp);
    produitTemp.setID_FOURNISSEURS(1);
    produitTemp.setID_CLIENTS(1);

    // 5. Appeler la méthode modifier
    if(produitTemp.modifier(ancienneReference, nouvelleReference)) {
        QMessageBox::information(this, "Succès",
                                 QString("Produit modifié avec succès!\n\n"
                                         "Ancienne référence: %1\n"
                                         "Nouvelle référence: %2")
                                     .arg(ancienneReference).arg(nouvelleReference));
        afficherProduits();
        viderChamps();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification");
    }
}




 ///////////////////////////////// Ajout
void MainWindow::on_btnAjouter_clicked()
{
    qDebug() << "=== BOUTON AJOUTER CLIQUE ===";

    // 1. Récupérer les données depuis l'interface
    QString reference = ui->lineEdit_3->text().trimmed();  // .trimmed() enlève les espaces
    QString nom = ui->lineEdit->text().trimmed();
    QString quantiteStr = ui->lineEdit_2->text().trimmed();
    QString prixStr = ui->lineEdit_4->text().trimmed();
    QString fournisseurs = ui->lineEdit_5->text().trimmed();
    QString category = ui->comboBox->currentText();
    QDate dateFab = ui->dateEdit->date();
    QDate dateExp = ui->dateEdit_2->date();

    // 2. CONTRÔLES DE SAISIE

    // Référence : doit être un nombre positif et unique
    if(reference.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "La référence est obligatoire");
        ui->lineEdit_3->setFocus();
        return;
    }

    bool okRef;
    int referenceNum = reference.toInt(&okRef);
    if(!okRef || referenceNum <= 0) {
        QMessageBox::warning(this, "Erreur", "La référence doit être un nombre positif");
        ui->lineEdit_3->selectAll();
        ui->lineEdit_3->setFocus();
        return;
    }

    // Vérifier si la référence existe déjà
    QSqlQuery checkRefQuery;
    checkRefQuery.prepare("SELECT COUNT(*) FROM PRODUIT WHERE REFERENCE = :ref");
    checkRefQuery.bindValue(":ref", referenceNum);
    if(checkRefQuery.exec() && checkRefQuery.next() && checkRefQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Erreur", "Cette référence existe déjà!");
        ui->lineEdit_3->selectAll();
        ui->lineEdit_3->setFocus();
        return;
    }

    // Nom : non vide, longueur raisonnable
    if(nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom du produit est obligatoire");
        ui->lineEdit->setFocus();
        return;
    }

    if(nom.length() > 100) {
        QMessageBox::warning(this, "Erreur", "Le nom est trop long (max 100 caractères)");
        ui->lineEdit->selectAll();
        ui->lineEdit->setFocus();
        return;
    }

    // Quantité : nombre positif
    if(quantiteStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "La quantité est obligatoire");
        ui->lineEdit_2->setFocus();
        return;
    }

    bool okQte;
    int quantite = quantiteStr.toInt(&okQte);
    if(!okQte || quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être un nombre positif");
        ui->lineEdit_2->selectAll();
        ui->lineEdit_2->setFocus();
        return;
    }

    if(quantite > 10000) {
        QMessageBox::warning(this, "Erreur", "La quantité est trop élevée (max 10000)");
        ui->lineEdit_2->selectAll();
        ui->lineEdit_2->setFocus();
        return;
    }

    // Prix : nombre positif avec 2 décimales max
    if(prixStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le prix est obligatoire");
        ui->lineEdit_4->setFocus();
        return;
    }

    bool okPrix;
    double prix = prixStr.toDouble(&okPrix);
    if(!okPrix || prix <= 0) {
        QMessageBox::warning(this, "Erreur", "Le prix doit être un nombre positif");
        ui->lineEdit_4->selectAll();
        ui->lineEdit_4->setFocus();
        return;
    }

    if(prix > 1000000) {
        QMessageBox::warning(this, "Erreur", "Le prix est trop élevé");
        ui->lineEdit_4->selectAll();
        ui->lineEdit_4->setFocus();
        return;
    }

    // Vérifier le format des décimales
    if(prixStr.contains('.') && prixStr.split('.')[1].length() > 2) {
        QMessageBox::warning(this, "Erreur", "Le prix ne peut avoir que 2 décimales maximum");
        ui->lineEdit_4->selectAll();
        ui->lineEdit_4->setFocus();
        return;
    }

    // Fournisseur : longueur raisonnable
    if(fournisseurs.length() > 100) {
        QMessageBox::warning(this, "Erreur", "Le nom du fournisseur est trop long (max 100 caractères)");
        ui->lineEdit_5->selectAll();
        ui->lineEdit_5->setFocus();
        return;
    }

    // Dates : date expiration > date fabrication
    if(dateExp <= dateFab) {
        QMessageBox::warning(this, "Erreur", "La date d'expiration doit être après la date de fabrication");
        ui->dateEdit_2->setFocus();
        return;
    }

    // 3. Si tous les contrôles passent, ajouter le produit
    Produit nouveauProduit;
    nouveauProduit.setREFERENCE(reference);
    nouveauProduit.setNOM(nom);
    nouveauProduit.setQUANTITE(quantite);
    nouveauProduit.setPRIX(prix);
    nouveauProduit.setCATEGORY(category);
    nouveauProduit.setFOURNISSEURS(fournisseurs);
    nouveauProduit.setDATE_FAB(dateFab);
    nouveauProduit.setDATE_EXP(dateExp);
    nouveauProduit.setID_FOURNISSEURS(1);
    nouveauProduit.setID_CLIENTS(1);

    if(nouveauProduit.ajouter()) {
        QMessageBox::information(this, "Succès", "Produit ajouté avec succès!");
        afficherProduits();
        viderChamps();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du produit");
    }
}









void MainWindow::viderChamps()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();  // Référence aussi
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}












void MainWindow::on_btnSupprimer_clicked()
{
    // Demander la RÉFÉRENCE (QString) et non plus l'ID (int)
    QString reference = QInputDialog::getText(this, "Suppression", "Référence du produit à supprimer:");

    if(reference.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Référence invalide");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Êtes-vous sûr de vouloir supprimer le produit " + reference + "?",
                                  QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes) {
        // Passer la RÉFÉRENCE (QString) à supprimer()
        if(produitTemp.supprimer(reference)) {
            QMessageBox::information(this, "Succès", "Produit supprimé avec succès");
            afficherProduits();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression");
        }
    }
}
void MainWindow::on_pushButton_clicked()
{
    // Exemple : ajouter produit dans le tableau
    QString nom = ui->lineEdit->text();
    QString quantite = ui->lineEdit_2->text();

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(nom));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(quantite));
}

void MainWindow::onLoginClicked()
{
    QString user = ui->lineUser->text();
    QString pass = ui->linePass->text();

    if(user == "admin" && pass == "1234") {
        ui->stackedWidget->setCurrentIndex(1);
        afficherProduits(); // Afficher les produits après login
    } else {
        QMessageBox::warning(this, "Erreur", "Identifiants incorrects");
    }
}
/////////////////////////////////Navigations
// page 1 :
void MainWindow::on_btnGestionClients_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnGestionEmployes_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_btnGestionSponsors_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_btnGestionFournisseurs_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_btnBack_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

// page 2 :

void MainWindow::on_btnGestionStock_PageClients_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_btnGestionEmployes_PageClients_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_btnGestionSponsors_PageClients_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnGestionFournisseurs_PageClients_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_btnBack_PageClients_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// page 3 :


void MainWindow::on_btnGestionStock_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnGestionClients_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_btnGestionSponsors_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}
void MainWindow::on_btnGestionFournisseurs_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_btnBack_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
// page 4 :


void MainWindow::on_btnGestionStock_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_btnGestionClients_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btnGestionEmployes_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_btnGestionFournisseurs_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_btnBack_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// page 5 :
void MainWindow::on_btnGestionStock_Page_Fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnGestionClients_Page_Fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_btnGestionEmployes_PageFournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_btnGestionSponsors_Page_Fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_btnBack_Page_Fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

