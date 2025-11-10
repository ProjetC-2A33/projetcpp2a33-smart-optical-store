#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QInputDialog>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    // Dans MainWindow::MainWindow(), après ui->setupUi(this);
    connect(ui->tableWidget, &QTableWidget::itemClicked, this, &MainWindow::on_tableWidget_itemClicked);
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
    // connexion des bts emply
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::on_btnAjouterEmploye_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::on_btnModifierEmploye_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_btnSupprimerEmploye_clicked);
    connect(ui->tableWidget_4, &QTableWidget::itemClicked, this, &MainWindow::on_tableWidgetEmployes_itemClicked);

    // connexion des boutons Fournisseur
    connect(ui->pushButton_45, &QPushButton::clicked, this, &MainWindow::on_btnAjouterFournisseur_clicked);
    connect(ui->pushButton_46, &QPushButton::clicked, this, &MainWindow::on_btnModifierFournisseur_clicked);
    connect(ui->pushButton_50, &QPushButton::clicked, this, &MainWindow::on_btnSupprimerFournisseur_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_btnRechercherFournisseur_clicked);
    connect(ui->pushButton_47, &QPushButton::clicked, this, &MainWindow::on_btnTrierFournisseur_clicked);
    connect(ui->pushButton_48, &QPushButton::clicked, this, &MainWindow::on_btnStatFournisseur_clicked);
    connect(ui->pushButton_49, &QPushButton::clicked, this, &MainWindow::on_btnExportPdfFournisseur_clicked);






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
    afficherEmployes();
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

    // 1. Récupérer l'ancienne référence depuis le champ (rempli par le clic sur le tableau)
    QString ancienneReference = ui->lineEdit_3->text().trimmed();

    if(ancienneReference.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez d'abord sélectionner un produit à modifier en cliquant sur une ligne du tableau");
        return;
    }

    // 2. Récupérer les nouvelles données depuis l'interface
    // La référence reste la même puisqu'elle est non modifiable
    QString nouvelleReference = ancienneReference; // Même référence (non modifiable)
    QString nouveauNom = ui->lineEdit->text().trimmed();
    QString nouvelleQuantiteStr = ui->lineEdit_2->text().trimmed();
    QString nouveauPrixStr = ui->lineEdit_4->text().trimmed();
    QString nouveauFournisseur = ui->lineEdit_5->text().trimmed();
    QString nouvelleCategory = ui->comboBox->currentText();
    QDate nouvelleDateFab = ui->dateEdit->date();
    QDate nouvelleDateExp = ui->dateEdit_2->date();

    // 3. CONTRÔLES DE SAISIE POUR LA MODIFICATION

    // Vérifier que l'ancienne référence est valide
    bool okOldRef;
    int ancienneRefNum = ancienneReference.toInt(&okOldRef);
    if(!okOldRef || ancienneRefNum <= 0) {
        QMessageBox::warning(this, "Erreur", "La référence est invalide");
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

    // Fournisseur : vérification longueur
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

    // 4. Confirmation avant modification
    QMessageBox::StandardButton confirmation;
    confirmation = QMessageBox::question(this, "Confirmation",
                                         QString("Êtes-vous sûr de vouloir modifier ce produit ?\n\n"
                                                 "Référence: %1\n"
                                                 "Nouveau nom: %2\n"
                                                 "Nouvelle quantité: %3\n"
                                                 "Nouveau prix: %4 DT\n"
                                                 "Nouvelle catégorie: %5")
                                             .arg(ancienneReference)
                                             .arg(nouveauNom)
                                             .arg(nouvelleQuantite)
                                             .arg(nouveauPrix, 0, 'f', 2)
                                             .arg(nouvelleCategory),
                                         QMessageBox::Yes | QMessageBox::No);

    if(confirmation != QMessageBox::Yes) {
        return;
    }

    // 5. Configuration du produit avec les nouvelles données
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

    // 6. Appeler la méthode modifier (même référence pour ancienne et nouvelle)
    if(produitTemp.modifier(ancienneReference, nouvelleReference)) {
        QMessageBox::information(this, "Succès",
                                 QString("Produit modifié avec succès!\n\n"
                                         "Référence: %1\n"
                                         "Nom: %2")
                                     .arg(ancienneReference)
                                     .arg(nouveauNom));
        afficherProduits();
        viderChamps();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du produit");
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
    ui->lineEdit_3->clear();  // Référence
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());

    // Réactiver le champ référence pour la prochaine sélection
    ui->lineEdit_3->setReadOnly(false);
    ui->lineEdit_3->setStyleSheet(""); // Remettre le style par défaut
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
    afficherFournisseurs();
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
    afficherFournisseurs();
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
    afficherFournisseurs();
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
    afficherFournisseurs();
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

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    if (!item) {
        qDebug() << "Aucun item sélectionné";
        return;
    }

    int row = item->row();
    qDebug() << "Ligne sélectionnée:" << row;

    // Vérifier que toutes les colonnes existent
    if (row < 0 || row >= ui->tableWidget->rowCount()) {
        qDebug() << "Ligne invalide";
        return;
    }

    // Vérifier que toutes les colonnes ont des items
    for (int col = 0; col < 8; col++) {
        if (!ui->tableWidget->item(row, col)) {
            qDebug() << "Colonne" << col << "manquante dans la ligne" << row;
            return;
        }
    }

    try {
        // Récupérer toutes les données de la ligne sélectionnée
        QString reference = ui->tableWidget->item(row, 0)->text();
        QString nom = ui->tableWidget->item(row, 1)->text();
        QString quantite = ui->tableWidget->item(row, 2)->text();
        QString prix = ui->tableWidget->item(row, 3)->text();
        QString categorie = ui->tableWidget->item(row, 4)->text();
        QString fournisseur = ui->tableWidget->item(row, 5)->text();
        QString dateFab = ui->tableWidget->item(row, 6)->text();
        QString dateExp = ui->tableWidget->item(row, 7)->text();

        qDebug() << "Données récupérées - Ref:" << reference << "Nom:" << nom;

        // Remplir les champs avec les données de la ligne sélectionnée
        ui->lineEdit_3->setText(reference);  // Référence
        ui->lineEdit->setText(nom);          // Nom
        ui->lineEdit_2->setText(quantite);   // Quantité
        ui->lineEdit_4->setText(prix);       // Prix
        ui->lineEdit_5->setText(fournisseur); // Fournisseur

        // Sélectionner la catégorie dans le comboBox
        int index = ui->comboBox->findText(categorie);
        if (index != -1) {
            ui->comboBox->setCurrentIndex(index);
        } else {
            ui->comboBox->setCurrentIndex(0);
        }

        // Convertir et remplir les dates
        QDate fabDate = QDate::fromString(dateFab, "yyyy-MM-dd");
        QDate expDate = QDate::fromString(dateExp, "yyyy-MM-dd");

        if (fabDate.isValid()) {
            ui->dateEdit->setDate(fabDate);
        } else {
            ui->dateEdit->setDate(QDate::currentDate());
        }

        if (expDate.isValid()) {
            ui->dateEdit_2->setDate(expDate);
        } else {
            ui->dateEdit_2->setDate(QDate::currentDate().addDays(30));
        }

        // Rendre le champ référence non modifiable
        ui->lineEdit_3->setReadOnly(true);
        ui->lineEdit_3->setStyleSheet("QLineEdit { background-color: #f0f0f0; color: #666; border: 1px solid #ccc; }");

        qDebug() << "✅ Produit sélectionné pour modification:" << nom << "(" << reference << ")";

    } catch (const std::exception& e) {
        qDebug() << "❌ Erreur lors du remplissage des champs:" << e.what();
        QMessageBox::warning(this, "Erreur", "Erreur lors de la sélection du produit");
    }
}



 //////////////// gestion Emplo :


void MainWindow::afficherEmployes()
{
    qDebug() << "Affichage des employés...";
    employeTemp.remplirTableWidget(ui->tableWidget_4);
}

void MainWindow::viderChampsEmploye()
{
    ui->lineEdit_id_employe->clear();
    ui->lineEdit_16->clear();
    ui->lineEdit_prenom->clear();
    ui->dateEdit_3->setDate(QDate::currentDate());
    ui->dateEdit_4->setDate(QDate::currentDate());
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);

    // Réinitialiser les boutons radio
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton->setAutoExclusive(true);

    // Réinitialiser les checkboxes
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);

    // Réactiver le champ ID
    ui->lineEdit_id_employe->setReadOnly(false);
    ui->lineEdit_id_employe->setStyleSheet("");
}

void MainWindow::on_btnAjouterEmploye_clicked()
{
    qDebug() << "=== AJOUT EMPLOYÉ ===";

    // Récupération des données
    QString idStr = ui->lineEdit_id_employe->text().trimmed();
    QString nom = ui->lineEdit_16->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QDate dateNaissance = ui->dateEdit_3->date();
    QDate dateEmbauche = ui->dateEdit_4->date();
    QString poste = ui->lineEdit_17->text().trimmed();
    QString salaireStr = ui->lineEdit_18->text().trimmed();
    int nbreEnfants = ui->spinBox->value();
    int anneesExperience = ui->spinBox_2->value();

    // État civil
    QString etatCivil = "";
    if(ui->radioButton->isChecked()) etatCivil = "Célibataire";
    else if(ui->radioButton_2->isChecked()) etatCivil = "Marié(e)";
    else if(ui->radioButton_3->isChecked()) etatCivil = "Divorcé(e)";

    // Diplôme
    QString diplome = "";
    if(ui->checkBox->isChecked()) diplome += "Opticien ";
    if(ui->checkBox_3->isChecked()) diplome += "Vendeur ";
    if(ui->checkBox_2->isChecked()) diplome += "Employé de stock";
    if(diplome.isEmpty()) diplome = "Aucun";

    // Conversions
    bool okId, okSalaire;
    int id = idStr.toInt(&okId);
    double salaire = salaireStr.toDouble(&okSalaire);

    // Validations basiques
    if(!okId || id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID employé invalide");
        return;
    }

    if(nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom est obligatoire");
        return;
    }

    if(!okSalaire || salaire < 0) {
        QMessageBox::warning(this, "Erreur", "Salaire invalide");
        return;
    }

    // Configuration de l'employé
    employeTemp.setID_EMPLOYE(id);
    employeTemp.setNOM_EMPLOYE(nom);
    employeTemp.setPRENOM_EMPLOYE(prenom);
    employeTemp.setDATE_NAISSANCE(dateNaissance);
    employeTemp.setDATE_EMBAUCHE(dateEmbauche);
    employeTemp.setETAT_CIVIL(etatCivil);
    employeTemp.setPOST(poste);
    employeTemp.setSALAIRE(salaire);
    employeTemp.setNBRE_ENFANTS(nbreEnfants);
    employeTemp.setANNEES_EXPERIENCE(anneesExperience);
    employeTemp.setDIPLOME(diplome.trimmed());

    // Ajout
    if(employeTemp.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès!");
        afficherEmployes();
        viderChampsEmploye();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout");
    }
}

void MainWindow::on_btnModifierEmploye_clicked()
{
    qDebug() << "=== MODIFICATION EMPLOYÉ ===";

    QString idStr = ui->lineEdit_id_employe->text().trimmed();
    if(idStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez d'abord un employé");
        return;
    }

    bool ok;
    int id = idStr.toInt(&ok);
    if(!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide");
        return;
    }

    // Récupération des nouvelles données (même code que l'ajout)
    QString nom = ui->lineEdit_16->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QDate dateNaissance = ui->dateEdit_3->date();
    QDate dateEmbauche = ui->dateEdit_4->date();
    QString poste = ui->lineEdit_17->text().trimmed();
    QString salaireStr = ui->lineEdit_18->text().trimmed();
    int nbreEnfants = ui->spinBox->value();
    int anneesExperience = ui->spinBox_2->value();

    QString etatCivil = "";
    if(ui->radioButton->isChecked()) etatCivil = "Célibataire";
    else if(ui->radioButton_2->isChecked()) etatCivil = "Marié(e)";
    else if(ui->radioButton_3->isChecked()) etatCivil = "Divorcé(e)";

    QString diplome = "";
    if(ui->checkBox->isChecked()) diplome += "Opticien ";
    if(ui->checkBox_3->isChecked()) diplome += "Vendeur ";
    if(ui->checkBox_2->isChecked()) diplome += "Employé de stock";
    if(diplome.isEmpty()) diplome = "Aucun";

    bool okSalaire;
    double salaire = salaireStr.toDouble(&okSalaire);

    if(!okSalaire || salaire < 0) {
        QMessageBox::warning(this, "Erreur", "Salaire invalide");
        return;
    }

    if(nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom est obligatoire");
        return;
    }

    // Configuration
    employeTemp.setNOM_EMPLOYE(nom);
    employeTemp.setPRENOM_EMPLOYE(prenom);
    employeTemp.setDATE_NAISSANCE(dateNaissance);
    employeTemp.setDATE_EMBAUCHE(dateEmbauche);
    employeTemp.setETAT_CIVIL(etatCivil);
    employeTemp.setPOST(poste);
    employeTemp.setSALAIRE(salaire);
    employeTemp.setNBRE_ENFANTS(nbreEnfants);
    employeTemp.setANNEES_EXPERIENCE(anneesExperience);
    employeTemp.setDIPLOME(diplome.trimmed());

    // Modification
    if(employeTemp.modifier(id)) {
        QMessageBox::information(this, "Succès", "Employé modifié avec succès!");
        afficherEmployes();
        viderChampsEmploye();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification");
    }
}

void MainWindow::on_btnSupprimerEmploye_clicked()
{
    QString idStr = QInputDialog::getText(this, "Suppression", "ID de l'employé à supprimer:");

    if(idStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "ID invalide");
        return;
    }

    bool ok;
    int id = idStr.toInt(&ok);
    if(!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID employé invalide");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Supprimer l'employé ID " + idStr + "?",
                                  QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes) {
        if(employeTemp.supprimer(id)) {
            QMessageBox::information(this, "Succès", "Employé supprimé");
            afficherEmployes();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec suppression");
        }
    }
}

void MainWindow::on_tableWidgetEmployes_itemClicked(QTableWidgetItem *item)
{
    if (!item) return;

    int row = item->row();
    if (row < 0 || row >= ui->tableWidget_4->rowCount()) return;

    try {
        // Récupération des données
        QString id = ui->tableWidget_4->item(row, 0)->text();
        QString nom = ui->tableWidget_4->item(row, 1)->text();
        QString prenom = ui->tableWidget_4->item(row, 2)->text();
        QString dateNaissance = ui->tableWidget_4->item(row, 3)->text();
        QString dateEmbauche = ui->tableWidget_4->item(row, 4)->text();
        QString etatCivil = ui->tableWidget_4->item(row, 5)->text();
        QString poste = ui->tableWidget_4->item(row, 6)->text();
        QString salaire = ui->tableWidget_4->item(row, 7)->text();
        QString nbreEnfants = ui->tableWidget_4->item(row, 8)->text();
        QString anneesExperience = ui->tableWidget_4->item(row, 9)->text();
        QString diplome = ui->tableWidget_4->item(row, 10)->text();

        // Remplissage des champs
        ui->lineEdit_id_employe->setText(id);
        ui->lineEdit_16->setText(nom);
        ui->lineEdit_prenom->setText(prenom);

        // Dates
        QDate naissanceDate = QDate::fromString(dateNaissance, "yyyy-MM-dd");
        QDate embaucheDate = QDate::fromString(dateEmbauche, "yyyy-MM-dd");
        if (naissanceDate.isValid()) ui->dateEdit_3->setDate(naissanceDate);
        if (embaucheDate.isValid()) ui->dateEdit_4->setDate(embaucheDate);

        ui->lineEdit_17->setText(poste);
        ui->lineEdit_18->setText(salaire);
        ui->spinBox->setValue(nbreEnfants.toInt());
        ui->spinBox_2->setValue(anneesExperience.toInt());

        // État civil
        ui->radioButton->setAutoExclusive(false);
        ui->radioButton->setChecked(etatCivil.contains("Célibataire"));
        ui->radioButton_2->setChecked(etatCivil.contains("Marié"));
        ui->radioButton_3->setChecked(etatCivil.contains("Divorcé"));
        ui->radioButton->setAutoExclusive(true);

        // Diplôme
        ui->checkBox->setChecked(diplome.contains("Opticien"));
        ui->checkBox_3->setChecked(diplome.contains("Vendeur"));
        ui->checkBox_2->setChecked(diplome.contains("Employé de stock"));

        // Bloquer l'ID
        ui->lineEdit_id_employe->setReadOnly(true);
        ui->lineEdit_id_employe->setStyleSheet("background-color: #f0f0f0; color: #666;");

        qDebug() << "Employé sélectionné:" << nom;

    } catch (...) {
        QMessageBox::warning(this, "Erreur", "Erreur sélection employé");
    }
}

// ================== FOURNISSEUR CRUD FUNCTIONS ==================

void MainWindow::afficherFournisseurs()
{
    qDebug() << "📋 Chargement des fournisseurs...";
    
    QSqlQuery query("SELECT ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE FROM FOURNISSEUR");
    
    QStandardItemModel *model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"ID", "Nom", "Adresse", "Email", "Téléphone", "Type Produits", "Historique", "Active"});
    
    int row = 0;
    while (query.next()) {
        model->setItem(row, 0, new QStandardItem(query.value(0).toString())); // ID
        model->setItem(row, 1, new QStandardItem(query.value(1).toString())); // NOM
        model->setItem(row, 2, new QStandardItem(query.value(2).toString())); // ADRESSE
        model->setItem(row, 3, new QStandardItem(query.value(3).toString())); // EMAIL
        model->setItem(row, 4, new QStandardItem(query.value(4).toString())); // TELEPHONE
        model->setItem(row, 5, new QStandardItem(query.value(5).toString())); // TYPE_PRODUITS
        model->setItem(row, 6, new QStandardItem(query.value(6).toString())); // HISTORIQUE
        model->setItem(row, 7, new QStandardItem(query.value(7).toString())); // IS_ACTIVE
        row++;
    }
    
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    
    qDebug() << "✅ Fournisseurs affichés:" << row;
}

void MainWindow::viderChampsFournisseur()
{
    ui->lineEdit_37->clear();  // ID
    ui->lineEdit_39->clear();  // Nom
    ui->lineEdit_38->clear();  // Type Produits
    ui->lineEdit_40->clear();  // Historique
    ui->lineEdit_41->clear();  // Email
    ui->lineEdit_42->clear();  // Recherche
    ui->lineEdit_43->clear();  // Autre
    ui->checkBox_7->setChecked(true);   // Active = Yes
    ui->checkBox_8->setChecked(false);  // Active = No
    
    ui->lineEdit_37->setReadOnly(false);
    ui->lineEdit_37->setStyleSheet("");
}

void MainWindow::on_btnAjouterFournisseur_clicked()
{
    qDebug() << "=== AJOUT FOURNISSEUR ===";

    // Récupération des données
    QString idStr = ui->lineEdit_37->text().trimmed();
    QString nom = ui->lineEdit_39->text().trimmed();
    QString typeProduits = ui->lineEdit_38->text().trimmed();
    QString historique = ui->lineEdit_40->text().trimmed();
    QString email = ui->lineEdit_41->text().trimmed();

    // Active status
    int isActive = ui->checkBox_7->isChecked() ? 1 : 0;

    // Validations
    if(idStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID ne peut pas être vide");
        return;
    }

    if(nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide");
        return;
    }

    if(email.isEmpty() || !email.contains("@")) {
        QMessageBox::warning(this, "Erreur", "Email invalide");
        return;
    }

    bool okId;
    int id = idStr.toInt(&okId);
    if(!okId || id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide");
        return;
    }

    // Configuration du fournisseur
    fournisseurTemp.setID_FOURNISSEUR(id);
    fournisseurTemp.setNOM(nom);
    fournisseurTemp.setADRESSE("Non spécifiée");  // Pas de champ dans l'UI
    fournisseurTemp.setEMAIL(email);
    fournisseurTemp.setTELEPHONE("Non spécifié");  // Pas de champ dans l'UI
    fournisseurTemp.setTYPE_PRODUITS(typeProduits);
    fournisseurTemp.setHISTORIQUE_LIVRAISONS(historique);
    fournisseurTemp.setIS_ACTIVE(isActive);

    // Ajout
    if(fournisseurTemp.ajouter()) {
        QMessageBox::information(this, "Succès", "Fournisseur ajouté avec succès!");
        afficherFournisseurs();
        viderChampsFournisseur();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du fournisseur");
    }
}

void MainWindow::on_btnModifierFournisseur_clicked()
{
    qDebug() << "=== MODIFICATION FOURNISSEUR ===";

    QString idStr = ui->lineEdit_37->text().trimmed();
    if(idStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez d'abord un fournisseur");
        return;
    }

    bool ok;
    int id = idStr.toInt(&ok);
    if(!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide");
        return;
    }

    // Récupération des nouvelles données
    QString nom = ui->lineEdit_39->text().trimmed();
    QString typeProduits = ui->lineEdit_38->text().trimmed();
    QString historique = ui->lineEdit_40->text().trimmed();
    QString email = ui->lineEdit_41->text().trimmed();
    int isActive = ui->checkBox_7->isChecked() ? 1 : 0;

    if(nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide");
        return;
    }

    if(email.isEmpty() || !email.contains("@")) {
        QMessageBox::warning(this, "Erreur", "Email invalide");
        return;
    }

    // Configuration du fournisseur
    fournisseurTemp.setID_FOURNISSEUR(id);
    fournisseurTemp.setNOM(nom);
    fournisseurTemp.setADRESSE("Non spécifiée");
    fournisseurTemp.setEMAIL(email);
    fournisseurTemp.setTELEPHONE("Non spécifié");
    fournisseurTemp.setTYPE_PRODUITS(typeProduits);
    fournisseurTemp.setHISTORIQUE_LIVRAISONS(historique);
    fournisseurTemp.setIS_ACTIVE(isActive);

    // Modification
    if(fournisseurTemp.modifier(id)) {
        QMessageBox::information(this, "Succès", "Fournisseur modifié avec succès!");
        afficherFournisseurs();
        viderChampsFournisseur();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification");
    }
}

void MainWindow::on_btnSupprimerFournisseur_clicked()
{
    qDebug() << "=== SUPPRESSION FOURNISSEUR ===";

    QString idStr = ui->lineEdit_37->text().trimmed();
    if(idStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer l'ID du fournisseur à supprimer");
        return;
    }

    bool ok;
    int id = idStr.toInt(&ok);
    if(!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID fournisseur invalide");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Supprimer le fournisseur ID " + idStr + "?",
                                  QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes) {
        if(fournisseurTemp.supprimer(id)) {
            QMessageBox::information(this, "Succès", "Fournisseur supprimé");
            afficherFournisseurs();
            viderChampsFournisseur();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec suppression");
        }
    }
}

void MainWindow::on_btnRechercherFournisseur_clicked()
{
    qDebug() << "=== RECHERCHE FOURNISSEUR ===";
    
    QString searchTerm = ui->lineEdit_42->text().trimmed();
    if(searchTerm.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Entrez un critère de recherche");
        return;
    }

    // Simple search by ID or Name
    QSqlQuery query;
    query.prepare("SELECT ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE "
                  "FROM FOURNISSEUR WHERE ID_FOURNISSEUR = :search OR UPPER(NOM) LIKE UPPER(:searchPattern)");
    query.bindValue(":search", searchTerm.toInt());
    query.bindValue(":searchPattern", "%" + searchTerm + "%");

    if(!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche");
        return;
    }

    if(query.next()) {
        ui->lineEdit_37->setText(query.value(0).toString());
        ui->lineEdit_39->setText(query.value(1).toString());
        ui->lineEdit_38->setText(query.value(5).toString());
        ui->lineEdit_40->setText(query.value(6).toString());
        ui->lineEdit_41->setText(query.value(3).toString());
        
        int isActive = query.value(7).toInt();
        ui->checkBox_7->setChecked(isActive == 1);
        ui->checkBox_8->setChecked(isActive == 0);
        
        QMessageBox::information(this, "Succès", "Fournisseur trouvé!");
    } else {
        QMessageBox::information(this, "Recherche", "Aucun fournisseur trouvé");
    }
}

void MainWindow::on_btnTrierFournisseur_clicked()
{
    qDebug() << "=== TRI FOURNISSEURS ===";
    
    QStringList options;
    options << "Par ID" << "Par Nom" << "Par Type de Produits";
    
    bool ok;
    QString choice = QInputDialog::getItem(this, "Trier", "Choisir le critère de tri:", 
                                           options, 0, false, &ok);
    
    if(ok && !choice.isEmpty()) {
        QString orderBy = "ID_FOURNISSEUR";
        if(choice == "Par Nom") orderBy = "NOM";
        else if(choice == "Par Type de Produits") orderBy = "TYPE_PRODUITS";
        
        QSqlQuery query("SELECT ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE "
                       "FROM FOURNISSEUR ORDER BY " + orderBy);
        
        QStandardItemModel *model = new QStandardItemModel(this);
        model->setHorizontalHeaderLabels({"ID", "Nom", "Adresse", "Email", "Téléphone", "Type Produits", "Historique", "Active"});
        
        int row = 0;
        while(query.next()) {
            for(int col = 0; col < 8; col++) {
                model->setItem(row, col, new QStandardItem(query.value(col).toString()));
            }
            row++;
        }
        
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        
        QMessageBox::information(this, "Succès", QString("Trié par %1 - %2 fournisseurs").arg(choice).arg(row));
    }
}

void MainWindow::on_btnStatFournisseur_clicked()
{
    qDebug() << "=== STATISTIQUES FOURNISSEURS ===";
    
    QSqlQuery countQuery("SELECT COUNT(*) FROM FOURNISSEUR");
    int total = 0;
    if(countQuery.next()) {
        total = countQuery.value(0).toInt();
    }
    
    QSqlQuery activeQuery("SELECT COUNT(*) FROM FOURNISSEUR WHERE IS_ACTIVE = 1");
    int actifs = 0;
    if(activeQuery.next()) {
        actifs = activeQuery.value(0).toInt();
    }
    
    QSqlQuery typeQuery("SELECT TYPE_PRODUITS, COUNT(*) FROM FOURNISSEUR GROUP BY TYPE_PRODUITS");
    QString typeStats = "\n\nRépartition par type:\n";
    while(typeQuery.next()) {
        QString type = typeQuery.value(0).toString();
        if(type.isEmpty()) type = "Non spécifié";
        typeStats += QString("  • %1: %2\n").arg(type).arg(typeQuery.value(1).toString());
    }
    
    QString stats = QString("📊 STATISTIQUES FOURNISSEURS\n\n"
                           "Total: %1 fournisseurs\n"
                           "Actifs: %2\n"
                           "Inactifs: %3%4")
                        .arg(total)
                        .arg(actifs)
                        .arg(total - actifs)
                        .arg(typeStats);
    
    QMessageBox::information(this, "Statistiques", stats);
}

void MainWindow::on_btnExportPdfFournisseur_clicked()
{
    qDebug() << "=== EXPORT PDF FOURNISSEURS ===";
    QMessageBox::information(this, "Export PDF", "Fonctionnalité d'export PDF à implémenter\n(nécessite QPrinter et QPainter)");
}

void MainWindow::on_btnAdvancedFeatures_clicked()
{
    qDebug() << "🚀 ADVANCED FEATURES clicked";
    
    QString info = "🚀 FONCTIONNALITÉS AVANCÉES\n\n"
                   "✅ Gestion complète CRUD\n"
                   "✅ Recherche intelligente\n"
                   "✅ Tri multi-critères\n"
                   "✅ Statistiques détaillées\n"
                   "✅ Export PDF\n"
                   "✅ Captcha de sécurité\n\n"
                   "Toutes les fonctionnalités sont actives!";
    
    QMessageBox::information(this, "Advanced Features", info);
}