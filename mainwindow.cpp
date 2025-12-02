#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QInputDialog>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>
#include <QDesktopServices>
#include <QUrl>
#include <QClipboard>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QScrollBar>
#include <QTimer>
#include <QLineEdit>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QDateTime>
#include <QFileInfo>
#include <QDir>
#include <QPageSize>
#include <QPageLayout>
#include <QFont>
#include <QPen>

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
    connect(ui->pushButton_48, &QPushButton::clicked, this, &MainWindow::on_btnStatFournisseur_clicked);  // Statistics
    connect(ui->pushButton_49, &QPushButton::clicked, this, &MainWindow::on_btnExportPdfFournisseur_clicked);  // PDF Export
    connect(ui->btnCallFournisseur, &QPushButton::clicked, this, &MainWindow::on_btnCallFournisseur_clicked);  // 📞 CALL BUTTON
    connect(ui->btnAIAgent, &QPushButton::clicked, this, &MainWindow::on_btnAIAgent_clicked);  // 🤖 AI AGENT






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

    // Charger les fournisseurs dans le ComboBox
    chargerFournisseurs();

    // Connexion des boutons Client
    connect(ui->tableWidget_5, &QTableWidget::itemClicked, this, &MainWindow::on_tableWidgetClients_itemClicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::on_pushButton_10_clicked); // Rechercher
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::on_pushButton_11_clicked); // TRI
    connect(ui->pushButton_33, &QPushButton::clicked, this, &MainWindow::on_pushButton_33_clicked); // PDF
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::on_pushButton_12_clicked); // Statut fidélité
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::on_pushButton_13_clicked); // Historique

    // Client CRUD buttons - NOW CONNECTED!
    connect(ui->pushButton_AjouterClient, &QPushButton::clicked, this, &MainWindow::on_btnAjouterClient_clicked);
    connect(ui->pushButton_ModifierClient, &QPushButton::clicked, this, &MainWindow::on_btnModifierClient_clicked);
    connect(ui->pushButton_SupprimerClient, &QPushButton::clicked, this, &MainWindow::on_btnSupprimerClient_clicked);

    // Additional button connections for Stock/Produit page
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_4_clicked);   // TRI Produits
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::on_pushButton_5_clicked);   // Recherche Produits
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);   // Export PDF
    connect(ui->pushButton_22, &QPushButton::clicked, this, &MainWindow::on_pushButton_22_clicked); // Upload Image

    // Sponsor page buttons
    connect(ui->pushButton_23, &QPushButton::clicked, this, &MainWindow::on_pushButton_23_clicked); // Ajouter Sponsor
    connect(ui->pushButton_24, &QPushButton::clicked, this, &MainWindow::on_pushButton_24_clicked); // Afficher Sponsors
    connect(ui->pushButton_27, &QPushButton::clicked, this, &MainWindow::on_pushButton_27_clicked); // Modifier Sponsor
    connect(ui->pushButton_29, &QPushButton::clicked, this, &MainWindow::on_pushButton_29_clicked); // Supprimer Sponsor
    connect(ui->pushButton_30, &QPushButton::clicked, this, &MainWindow::on_pushButton_30_clicked); // Statu Sponsor
    connect(ui->pushButton_26, &QPushButton::clicked, this, &MainWindow::on_pushButton_26_clicked); // Recommandation
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherProduits()
{
    produitTemp.remplirTableWidget(ui->tableWidget);
}

void MainWindow::chargerFournisseurs()
{
    qDebug() << "📋 Chargement des fournisseurs dans le ComboBox...";

    // Clear existing items
    ui->comboBox_Fournisseurs->clear();

    // Add default empty item
    ui->comboBox_Fournisseurs->addItem("-- Sélectionner un fournisseur --");

    // Query to get all supplier names from FOURNISSEUR table
    QSqlQuery query("SELECT NOM FROM FOURNISSEUR WHERE IS_ACTIVE = 1 ORDER BY NOM");

    int count = 0;
    while (query.next()) {
        QString nomFournisseur = query.value(0).toString();
        ui->comboBox_Fournisseurs->addItem(nomFournisseur);
        count++;
    }

    qDebug() << "✅" << count << "fournisseurs chargés dans le ComboBox";
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
    QString nouveauFournisseur = ui->comboBox_Fournisseurs->currentText();
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

    // Fournisseur : doit être sélectionné
    if(nouveauFournisseur.isEmpty() || nouveauFournisseur == "-- Sélectionner un fournisseur --") {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un fournisseur");
        ui->comboBox_Fournisseurs->setFocus();
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
    QString fournisseurs = ui->comboBox_Fournisseurs->currentText();
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

    // Fournisseur : doit être sélectionné
    if(fournisseurs.isEmpty() || fournisseurs == "-- Sélectionner un fournisseur --") {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un fournisseur");
        ui->comboBox_Fournisseurs->setFocus();
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
    ui->comboBox_Fournisseurs->setCurrentIndex(0);  // Reset to default item
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
        chargerFournisseurs(); // Charger les fournisseurs après login
    } else {
        QMessageBox::warning(this, "Erreur", "Identifiants incorrects");
    }
}
/////////////////////////////////Navigations
// page 1 :
void MainWindow::on_btnGestionClients_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    afficherClients(); // Charger les clients quand on arrive sur la page
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
    chargerFournisseurs(); // Recharger les fournisseurs au retour sur la page Stock
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
    chargerFournisseurs(); // Recharger les fournisseurs au retour sur la page Stock
}


void MainWindow::on_btnGestionClients_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    afficherClients(); // Charger les clients quand on arrive sur la page
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
    chargerFournisseurs(); // Recharger les fournisseurs au retour sur la page Stock
}



void MainWindow::on_btnGestionClients_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    afficherClients(); // Charger les clients quand on arrive sur la page
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
    chargerFournisseurs(); // Recharger les fournisseurs au retour sur la page Stock
}


void MainWindow::on_btnGestionClients_Page_Fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    afficherClients(); // Charger les clients quand on arrive sur la page
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

        // Sélectionner le fournisseur dans le ComboBox
        int indexFournisseur = ui->comboBox_Fournisseurs->findText(fournisseur);
        if (indexFournisseur != -1) {
            ui->comboBox_Fournisseurs->setCurrentIndex(indexFournisseur);
        } else {
            ui->comboBox_Fournisseurs->setCurrentIndex(0);
        }

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
    ui->lineEdit_telephone->clear();  // Téléphone
    ui->lineEdit_42->clear();  // Recherche
    ui->lineEdit_43->clear();  // Autre
    // Checkboxes removed - all suppliers active by default

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
    QString telephone = ui->lineEdit_telephone->text().trimmed();  // 📞 NEW: Téléphone

    // Active status - default to active
    int isActive = 1;  // All suppliers are active by default

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

    if(telephone.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "⚠️ Le numéro de téléphone est requis pour pouvoir appeler le fournisseur!");
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
    fournisseurTemp.setTELEPHONE(telephone);  // 📞 NEW: Save telephone
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
    QString telephone = ui->lineEdit_telephone->text().trimmed();  // 📞 NEW: Téléphone
    int isActive = 1;  // All suppliers are active by default

    if(nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide");
        return;
    }

    if(email.isEmpty() || !email.contains("@")) {
        QMessageBox::warning(this, "Erreur", "Email invalide");
        return;
    }

    if(telephone.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "⚠️ Le numéro de téléphone est requis!");
        return;
    }

    // Configuration du fournisseur
    fournisseurTemp.setID_FOURNISSEUR(id);
    fournisseurTemp.setNOM(nom);
    fournisseurTemp.setADRESSE("Non spécifiée");
    fournisseurTemp.setEMAIL(email);
    fournisseurTemp.setTELEPHONE(telephone);  // 📞 NEW: Save telephone
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
        // Checkboxes removed - just show the status
        QString statusText = (isActive == 1) ? "Actif" : "Inactif";

        QMessageBox::information(this, "Succès", QString("Fournisseur trouvé!\nStatut: %1").arg(statusText));
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
    
    // Check if there is data to export
    QSqlQuery checkQuery("SELECT COUNT(*) FROM FOURNISSEUR");
    if(checkQuery.next() && checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Aucune donnée", "⚠️ Aucun fournisseur à exporter!\n\nAjoutez des fournisseurs avant d'exporter.");
        return;
    }
    
    // Ask user where to save the PDF
    QString defaultFileName = QString("Fournisseurs_%1.pdf").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss"));
    QString filePath = QFileDialog::getSaveFileName(this, 
                                                     "Exporter les Fournisseurs en PDF",
                                                     QDir::homePath() + "/" + defaultFileName,
                                                     "PDF Files (*.pdf)");
    
    if(filePath.isEmpty()) {
        qDebug() << "Export PDF annulé par l'utilisateur";
        return;
    }
    
    // Create PDF printer
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageSize(QPageSize::A4);
    printer.setPageOrientation(QPageLayout::Landscape);
    
    QPainter painter;
    if(!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "❌ Impossible de créer le fichier PDF!");
        return;
    }
    
    // Get page dimensions
    QRect pageRect = printer.pageRect(QPrinter::DevicePixel).toRect();
    int pageWidth = pageRect.width();
    int pageHeight = pageRect.height();
    
    // Define margins
    int margin = 100;
    int currentY = margin;
    
    // Title
    QFont titleFont("Arial", 24, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(QPen(QColor(30, 58, 95)));
    painter.drawText(margin, currentY, "📋 Liste des Fournisseurs - Smart Optic");
    currentY += 80;
    
    // Subtitle with date
    QFont subtitleFont("Arial", 12);
    painter.setFont(subtitleFont);
    painter.setPen(QPen(Qt::darkGray));
    QString dateStr = QString("Généré le: %1").arg(QDateTime::currentDateTime().toString("dd/MM/yyyy à HH:mm"));
    painter.drawText(margin, currentY, dateStr);
    currentY += 60;
    
    // Draw separator line
    painter.setPen(QPen(QColor(30, 58, 95), 2));
    painter.drawLine(margin, currentY, pageWidth - margin, currentY);
    currentY += 40;
    
    // Query to get all suppliers
    QSqlQuery query("SELECT ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE FROM FOURNISSEUR ORDER BY NOM");
    
    // Table headers
    QFont headerFont("Arial", 10, QFont::Bold);
    painter.setFont(headerFont);
    painter.setPen(QPen(Qt::white));
    
    // Column widths (landscape mode)
    int col1Width = 80;   // ID
    int col2Width = 250;  // Nom
    int col3Width = 280;  // Adresse
    int col4Width = 300;  // Email
    int col5Width = 180;  // Téléphone
    int col6Width = 220;  // Type Produits
    int col7Width = 100;  // Active
    
    int rowHeight = 40;
    int headerHeight = 50;
    
    // Draw header background
    painter.fillRect(margin, currentY, pageWidth - 2*margin, headerHeight, QColor(30, 58, 95));
    
    // Draw header text
    int xPos = margin + 10;
    painter.drawText(xPos, currentY + 30, "ID");
    xPos += col1Width;
    painter.drawText(xPos, currentY + 30, "Nom");
    xPos += col2Width;
    painter.drawText(xPos, currentY + 30, "Adresse");
    xPos += col3Width;
    painter.drawText(xPos, currentY + 30, "Email");
    xPos += col4Width;
    painter.drawText(xPos, currentY + 30, "Téléphone");
    xPos += col5Width;
    painter.drawText(xPos, currentY + 30, "Type Produits");
    xPos += col6Width;
    painter.drawText(xPos, currentY + 30, "Statut");
    
    currentY += headerHeight;
    
    // Data rows
    QFont dataFont("Arial", 9);
    painter.setFont(dataFont);
    
    int rowCount = 0;
    bool alternateBg = false;
    
    while(query.next()) {
        // Check if we need a new page
        if(currentY + rowHeight > pageHeight - margin) {
            printer.newPage();
            currentY = margin;
            
            // Redraw header on new page
            painter.setFont(headerFont);
            painter.setPen(QPen(Qt::white));
            painter.fillRect(margin, currentY, pageWidth - 2*margin, headerHeight, QColor(30, 58, 95));
            
            xPos = margin + 10;
            painter.drawText(xPos, currentY + 30, "ID");
            xPos += col1Width;
            painter.drawText(xPos, currentY + 30, "Nom");
            xPos += col2Width;
            painter.drawText(xPos, currentY + 30, "Adresse");
            xPos += col3Width;
            painter.drawText(xPos, currentY + 30, "Email");
            xPos += col4Width;
            painter.drawText(xPos, currentY + 30, "Téléphone");
            xPos += col5Width;
            painter.drawText(xPos, currentY + 30, "Type Produits");
            xPos += col6Width;
            painter.drawText(xPos, currentY + 30, "Statut");
            
            currentY += headerHeight;
            painter.setFont(dataFont);
        }
        
        // Alternate row background
        if(alternateBg) {
            painter.fillRect(margin, currentY, pageWidth - 2*margin, rowHeight, QColor(240, 240, 240));
        }
        alternateBg = !alternateBg;
        
        // Draw row data
        painter.setPen(QPen(Qt::black));
        xPos = margin + 10;
        
        // ID
        painter.drawText(QRect(xPos, currentY, col1Width - 10, rowHeight), 
                        Qt::AlignLeft | Qt::AlignVCenter, 
                        query.value(0).toString());
        xPos += col1Width;
        
        // Nom
        QString nom = query.value(1).toString();
        if(nom.length() > 25) nom = nom.left(22) + "...";
        painter.drawText(QRect(xPos, currentY, col2Width - 10, rowHeight), 
                        Qt::AlignLeft | Qt::AlignVCenter, 
                        nom);
        xPos += col2Width;
        
        // Adresse
        QString adresse = query.value(2).toString();
        if(adresse.length() > 30) adresse = adresse.left(27) + "...";
        painter.drawText(QRect(xPos, currentY, col3Width - 10, rowHeight), 
                        Qt::AlignLeft | Qt::AlignVCenter, 
                        adresse);
        xPos += col3Width;
        
        // Email
        QString email = query.value(3).toString();
        if(email.length() > 35) email = email.left(32) + "...";
        painter.drawText(QRect(xPos, currentY, col4Width - 10, rowHeight), 
                        Qt::AlignLeft | Qt::AlignVCenter, 
                        email);
        xPos += col4Width;
        
        // Téléphone
        painter.drawText(QRect(xPos, currentY, col5Width - 10, rowHeight), 
                        Qt::AlignLeft | Qt::AlignVCenter, 
                        query.value(4).toString());
        xPos += col5Width;
        
        // Type Produits
        QString typeProduits = query.value(5).toString();
        if(typeProduits.length() > 25) typeProduits = typeProduits.left(22) + "...";
        painter.drawText(QRect(xPos, currentY, col6Width - 10, rowHeight), 
                        Qt::AlignLeft | Qt::AlignVCenter, 
                        typeProduits);
        xPos += col6Width;
        
        // Active status
        QString activeStatus = query.value(7).toInt() == 1 ? "Actif" : "Inactif";
        QColor statusColor = query.value(7).toInt() == 1 ? QColor(0, 150, 0) : QColor(200, 0, 0);
        painter.setPen(QPen(statusColor));
        painter.drawText(QRect(xPos, currentY, col7Width - 10, rowHeight), 
                        Qt::AlignLeft | Qt::AlignVCenter, 
                        activeStatus);
        
        currentY += rowHeight;
        rowCount++;
    }
    
    // Footer
    currentY = pageHeight - margin + 20;
    painter.setPen(QPen(Qt::darkGray));
    QFont footerFont("Arial", 9);
    footerFont.setItalic(true);
    painter.setFont(footerFont);
    QString footer = QString("Total: %1 fournisseur(s) | Smart Optic - Gestion des Fournisseurs").arg(rowCount);
    painter.drawText(margin, currentY, footer);
    
    painter.end();
    
    qDebug() << "✅ PDF exporté avec succès:" << filePath;
    
    // Show success message with option to open
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Export réussi", 
                                   QString("✅ PDF exporté avec succès!\n\n"
                                          "📄 Fichier: %1\n"
                                          "📊 %2 fournisseur(s) exporté(s)\n\n"
                                          "Voulez-vous ouvrir le fichier?").arg(QFileInfo(filePath).fileName()).arg(rowCount),
                                   QMessageBox::Yes | QMessageBox::No);
    
    if(reply == QMessageBox::Yes) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }
}

void MainWindow::on_btnCallFournisseur_clicked()
{
    qDebug() << "📞 CALL FOURNISSEUR clicked - Microsoft Teams";

    // Get the phone number from the lineEdit
    QString phoneNumber = ui->lineEdit_telephone->text().trimmed();

    // Validation
    if(phoneNumber.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "⚠️ Veuillez entrer un numéro de téléphone!\n\nEntrez le numéro dans le champ 'Téléphone' avant d'appeler.");
        return;
    }

    // Format phone number - remove spaces and special characters
    QString cleanNumber = phoneNumber;
    cleanNumber.remove(' ').remove('-').remove('(').remove(')');

    // Confirmation dialog
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation d'appel",
                                   QString("📞 Appeler via Microsoft Teams?\n\n"
                                          "Numéro: %1\n\n"
                                          "Microsoft Teams va s'ouvrir pour lancer l'appel.").arg(phoneNumber),
                                   QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Create Microsoft Teams call URL
        QString teamsUrl = QString("msteams:/l/call/0/0?users=%1").arg(cleanNumber);
        
        qDebug() << "📞 Opening Microsoft Teams with URL:" << teamsUrl;

        // Open Microsoft Teams with the phone number
        bool success = QDesktopServices::openUrl(QUrl(teamsUrl));

        if(success) {
            QMessageBox::information(this, "Appel en cours",
                                    QString("✅ Microsoft Teams s'ouvre pour appeler:\n\n%1\n\n"
                                           "L'appel va démarrer dans Teams!").arg(phoneNumber));
            qDebug() << "✅ Microsoft Teams opened successfully";
        } else {
            // Fallback: Copy to clipboard
            QClipboard *clipboard = QApplication::clipboard();
            clipboard->setText(phoneNumber);
            
            QMessageBox::information(this, "Numéro copié",
                                    QString("📋 Le numéro a été copié:\n\n%1\n\n"
                                           "Ouvrez Microsoft Teams manuellement et collez le numéro pour appeler.").arg(phoneNumber));
            qDebug() << "📋 Number copied to clipboard";
        }
    } else {
        qDebug() << "📞 Call cancelled by user";
    }
}

void MainWindow::on_btnAIAgent_clicked()
{
    qDebug() << "🤖 AI AGENT clicked";

    QDialog *aiDialog = new QDialog(this);
    aiDialog->setWindowTitle("🤖 Assistant IA - Smart Optic");
    aiDialog->setMinimumSize(700, 600);

    QVBoxLayout *mainLayout = new QVBoxLayout(aiDialog);

    QLabel *titleLabel = new QLabel("🤖 Assistant IA Smart Optic");
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: #00FF9C; padding: 10px;");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    QTextEdit *chatDisplay = new QTextEdit();
    chatDisplay->setReadOnly(true);
    chatDisplay->setStyleSheet(
        "QTextEdit {"
        "   background-color: #0F2A3D;"
        "   color: #E6F1FF;"
        "   border: 2px solid #00C8FF;"
        "   border-radius: 8px;"
        "   padding: 10px;"
        "   font-size: 14px;"
        "}"
    );
    
    QString welcomeMsg = "<div style='background-color: #122D42; padding: 10px; border-radius: 8px; margin: 5px;'>"
                        "<b style='color: #00FF9C;'>🤖 Assistant IA:</b><br>"
                        "Bienvenue chez <b>Smart Optic</b>! 👓✨<br><br>"
                        "Je suis votre assistant intelligent pour la gestion des fournisseurs.<br><br>"
                        "<b>Posez-moi vos questions!</b> Par exemple:<br>"
                        "• Quel est le format du numéro de téléphone?<br>"
                        "• L'email est-il obligatoire?<br>"
                        "• Comment ajouter un fournisseur?<br>"
                        "• Salut / Bonjour / Hi<br><br>"
                        "💬 <b>Tapez votre question ci-dessous!</b>"
                        "</div>";
    chatDisplay->setHtml(welcomeMsg);
    mainLayout->addWidget(chatDisplay);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    
    QLineEdit *userInput = new QLineEdit();
    userInput->setPlaceholderText("💬 Tapez votre question ici...");
    userInput->setStyleSheet(
        "QLineEdit {"
        "   background-color: #122D42;"
        "   color: #E6F1FF;"
        "   border: 2px solid #00C8FF;"
        "   border-radius: 8px;"
        "   padding: 10px;"
        "   font-size: 14px;"
        "}"
    );
    
    QPushButton *btnSend = new QPushButton("📤 Envoyer");
    btnSend->setStyleSheet(
        "QPushButton {"
        "   background-color: #00C8FF;"
        "   color: #0B1C2C;"
        "   border: none;"
        "   border-radius: 8px;"
        "   padding: 10px 20px;"
        "   font-weight: bold;"
        "   font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #00FF9C;"
        "}"
    );
    
    inputLayout->addWidget(userInput);
    inputLayout->addWidget(btnSend);
    mainLayout->addLayout(inputLayout);
    
    QPushButton *btnClose = new QPushButton("❌ Fermer");
    btnClose->setStyleSheet(
        "QPushButton {"
        "   background-color: #FF4444;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 8px;"
        "   padding: 10px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #CC0000;"
        "}"
    );
    mainLayout->addWidget(btnClose);

    QLabel *typingLabel = new QLabel();
    typingLabel->setStyleSheet("color: #00FF9C; font-style: italic; padding: 5px;");
    typingLabel->setVisible(false);
    mainLayout->insertWidget(mainLayout->count() - 1, typingLabel);
    
    QTimer *typingTimer = new QTimer(aiDialog);
    QString *currentResponse = new QString();
    int *charIndex = new int(0);
    QStringList *conversationHistory = new QStringList();

    auto processMessage = [chatDisplay, userInput, typingLabel, typingTimer, currentResponse, charIndex, conversationHistory]() {
        QString userMsg = userInput->text().trimmed();
        if(userMsg.isEmpty()) return;
        
        if(typingTimer->isActive()) return;
        
        userInput->setEnabled(false);
        
        conversationHistory->append("<div style='background-color: #1E3D57; padding: 10px; border-radius: 8px; margin: 5px; text-align: right;'>"
                                    "<b style='color: #FFFFFF;'>Vous:</b> " + userMsg + "</div>");
        
        QString fullHtml;
        for(const QString &msg : *conversationHistory) {
            fullHtml += msg;
        }
        chatDisplay->setHtml(fullHtml);
        chatDisplay->verticalScrollBar()->setValue(chatDisplay->verticalScrollBar()->maximum());
        
        typingLabel->setText("🤖 Assistant IA est en train d'écrire...");
        typingLabel->setVisible(true);
        
        QString aiResponse;
        QString lowerMsg = userMsg.toLower();
        
        if(lowerMsg.contains("hi") || lowerMsg.contains("hello") || lowerMsg.contains("salut") || 
           lowerMsg.contains("bonjour") || lowerMsg.contains("bonsoir")) {
            aiResponse = "👋 <b>Bonjour et bienvenue chez Smart Optic!</b> 👓✨<br><br>"
                        "Je suis ravi de vous aider aujourd'hui!<br>"
                        "Comment puis-je vous assister avec la gestion des fournisseurs?";
        }
        else if(lowerMsg.contains("format") && (lowerMsg.contains("téléphone") || lowerMsg.contains("telephone") || 
                lowerMsg.contains("numero") || lowerMsg.contains("numéro") || lowerMsg.contains("phone"))) {
            aiResponse = "📞 <b>Format du numéro de téléphone:</b><br><br>"
                        "✅ <b>Format correct:</b> +216XXXXXXXX<br>"
                        "✅ <b>Exemple:</b> +21612345678<br>"
                        "✅ <b>Avec code pays:</b> +216 (Tunisie), +33 (France), +1 (USA)<br><br>"
                        "⚠️ <b>Important:</b> Commencez toujours par <b>+</b> suivi du code pays!";
        }
        else if((lowerMsg.contains("email") || lowerMsg.contains("mail")) && 
                (lowerMsg.contains("obligatoire") || lowerMsg.contains("requis") || lowerMsg.contains("nécessaire"))) {
            aiResponse = "📧 <b>Oui, l'email est OBLIGATOIRE!</b><br><br>"
                        "✅ <b>Format requis:</b> exemple@domaine.com<br>"
                        "✅ <b>Doit contenir:</b> @ et un domaine<br>"
                        "✅ <b>Exemples valides:</b><br>"
                        "   • contact@smartoptic.tn<br>"
                        "   • fournisseur@gmail.com<br>"
                        "   • info@entreprise.fr<br><br>"
                        "❌ <b>Sans email valide, vous ne pouvez pas ajouter le fournisseur!</b>";
        }
        else if((lowerMsg.contains("comment") || lowerMsg.contains("how")) && 
                (lowerMsg.contains("ajouter") || lowerMsg.contains("add") || lowerMsg.contains("créer"))) {
            aiResponse = "📝 <b>Pour ajouter un fournisseur:</b><br><br>"
                        "1️⃣ <b>ID Fournisseur:</b> Numéro unique (ex: 1, 2, 3...)<br>"
                        "2️⃣ <b>Nom:</b> Nom du fournisseur (obligatoire)<br>"
                        "3️⃣ <b>Email:</b> Format valide avec @ (obligatoire)<br>"
                        "4️⃣ <b>Téléphone:</b> +216XXXXXXXX (obligatoire)<br>"
                        "5️⃣ <b>Type Produits:</b> Ex: Lunettes, Lentilles...<br>"
                        "6️⃣ <b>Historique:</b> Notes sur les livraisons<br>"
                        "7️⃣ Cliquez sur <b>Ajouter</b><br><br>"
                        "✅ <b>C'est fait!</b>";
        }
        else if((lowerMsg.contains("appel") || lowerMsg.contains("call") || lowerMsg.contains("téléphoner")) ||
                (lowerMsg.contains("comment") && lowerMsg.contains("appeler"))) {
            aiResponse = "📞 <b>Pour appeler un fournisseur:</b><br><br>"
                        "1️⃣ Assurez-vous que le <b>numéro de téléphone</b> est rempli<br>"
                        "2️⃣ Cliquez sur le bouton <b>📞 Appeler</b><br>"
                        "3️⃣ <b>Microsoft Teams</b> s'ouvrira automatiquement<br>"
                        "4️⃣ L'appel sera lancé!<br><br>"
                        "💡 <b>Astuce:</b> Microsoft Teams doit être installé sur votre PC!";
        }
        else if(lowerMsg.contains("merci") || lowerMsg.contains("thanks") || lowerMsg.contains("thank you")) {
            aiResponse = "😊 <b>De rien!</b> Je suis là pour vous aider!<br><br>"
                        "N'hésitez pas si vous avez d'autres questions! 💪";
        }
        else if(lowerMsg.contains("au revoir") || lowerMsg.contains("bye") || lowerMsg.contains("aurevoir") ||
                lowerMsg.contains("à bientôt") || lowerMsg.contains("ciao")) {
            aiResponse = "👋 <b>Au revoir et à bientôt chez Smart Optic!</b> 👓✨<br><br>"
                        "Bonne gestion de vos fournisseurs! 😊";
        }
        else {
            aiResponse = "🤔 <b>Je peux vous aider avec:</b><br><br>"
                        "• <b>Format du téléphone</b> - Demandez: \"Quel est le format du numéro?\"<br>"
                        "• <b>Email obligatoire</b> - Demandez: \"L'email est-il obligatoire?\"<br>"
                        "• <b>Comment ajouter</b> - Demandez: \"Comment ajouter un fournisseur?\"<br>"
                        "• <b>Comment appeler</b> - Demandez: \"Comment appeler?\"<br><br>"
                        "Ou utilisez les boutons ci-dessous! 👇";
        }
        
        *currentResponse = aiResponse;
        *charIndex = 0;
        userInput->clear();
        
        QTimer::singleShot(500, [typingTimer, typingLabel, userInput]() {
            typingLabel->setVisible(false);
            typingTimer->start(20);
        });
    };
    
    auto typeNextChar = [chatDisplay, typingLabel, currentResponse, charIndex, typingTimer, userInput, conversationHistory]() {
        if (*charIndex < currentResponse->length()) {
            QString partialResponse = currentResponse->left(*charIndex + 1);
            
            QString fullHtml;
            for(int i = 0; i < conversationHistory->size(); i++) {
                fullHtml += conversationHistory->at(i);
            }
            fullHtml += "<div style='background-color: #122D42; padding: 10px; border-radius: 8px; margin: 5px;'>"
                       "<b style='color: #00FF9C;'>🤖 Assistant IA:</b><br>" + partialResponse +
                       "</div>";
            
            chatDisplay->setHtml(fullHtml);
            chatDisplay->verticalScrollBar()->setValue(chatDisplay->verticalScrollBar()->maximum());
            (*charIndex)++;
        } else {
            typingTimer->stop();
            typingLabel->setVisible(false);
            
            conversationHistory->append("<div style='background-color: #122D42; padding: 10px; border-radius: 8px; margin: 5px;'>"
                                       "<b style='color: #00FF9C;'>🤖 Assistant IA:</b><br>" + *currentResponse +
                                       "</div>");
            
            *charIndex = 0;
            userInput->setEnabled(true);
            userInput->setFocus();
        }
    };
    
    connect(typingTimer, &QTimer::timeout, typeNextChar);
    connect(btnSend, &QPushButton::clicked, processMessage);
    connect(userInput, &QLineEdit::returnPressed, processMessage);
    connect(btnClose, &QPushButton::clicked, aiDialog, &QDialog::accept);

    aiDialog->setStyleSheet(
        "QDialog {"
        "   background-color: #0F2A3D;"
        "}"
        "QLabel {"
        "   color: #E6F1FF;"
        "}"
    );

    aiDialog->exec();
    delete aiDialog;
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

// ================== CLIENT CRUD FUNCTIONS ==================

void MainWindow::afficherClients()
{
    qDebug() << "📋 Chargement des clients...";
    clientTemp.remplirTableWidget(ui->tableWidget_5);
}

void MainWindow::viderChampsClient()
{
    ui->lineEdit_6->clear();   // CIN
    ui->lineEdit_7->clear();   // Prenom
    ui->lineEdit_8->clear();   // Nom
    ui->lineEdit_9->clear();   // Email
    ui->lineEdit_10->clear();  // Telephone
    ui->lineEdit_29->clear();  // Adresse

    // Reset radio buttons
    ui->radioButton_4->setAutoExclusive(false);
    ui->radioButton_4->setChecked(false);
    ui->radioButton_5->setChecked(false);
    ui->radioButton_4->setAutoExclusive(true);

    ui->lineEdit_6->setReadOnly(false);
    ui->lineEdit_6->setStyleSheet("");
}

void MainWindow::on_btnAjouterClient_clicked()
{
    qDebug() << "=== AJOUT CLIENT ===";

    // Récupération des données
    QString cinStr = ui->lineEdit_6->text().trimmed();
    QString prenom = ui->lineEdit_7->text().trimmed();
    QString nom = ui->lineEdit_8->text().trimmed();
    QString email = ui->lineEdit_9->text().trimmed();
    QString telephone = ui->lineEdit_10->text().trimmed();
    QString adresse = ui->lineEdit_29->text().trimmed();

    // Sexe
    QString sexe = "";
    if(ui->radioButton_4->isChecked()) sexe = "femme";
    else if(ui->radioButton_5->isChecked()) sexe = "homme";

    // Validations
    if(cinStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le CIN ne peut pas être vide");
        return;
    }

    bool okCin;
    int cin = cinStr.toInt(&okCin);
    if(!okCin || cin <= 0) {
        QMessageBox::warning(this, "Erreur", "CIN invalide");
        return;
    }

    if(nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide");
        return;
    }

    if(prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le prénom ne peut pas être vide");
        return;
    }

    if(email.isEmpty() || !email.contains("@")) {
        QMessageBox::warning(this, "Erreur", "Email invalide");
        return;
    }

    if(sexe.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner le sexe");
        return;
    }

    // Configuration du client
    clientTemp.setCIN(cin);
    clientTemp.setPRENOM(prenom);
    clientTemp.setNOM(nom);
    clientTemp.setEMAIL(email);
    clientTemp.setTELEPHONE(telephone);
    clientTemp.setADRESSE(adresse);
    clientTemp.setSEXE(sexe);

    // Ajout
    if(clientTemp.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès!");
        afficherClients();
        viderChampsClient();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client");
    }
}

void MainWindow::on_btnModifierClient_clicked()
{
    qDebug() << "=== MODIFICATION CLIENT ===";

    QString cinStr = ui->lineEdit_6->text().trimmed();
    if(cinStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez d'abord un client");
        return;
    }

    bool ok;
    int cin = cinStr.toInt(&ok);
    if(!ok || cin <= 0) {
        QMessageBox::warning(this, "Erreur", "CIN invalide");
        return;
    }

    // Récupération des nouvelles données
    QString prenom = ui->lineEdit_7->text().trimmed();
    QString nom = ui->lineEdit_8->text().trimmed();
    QString email = ui->lineEdit_9->text().trimmed();
    QString telephone = ui->lineEdit_10->text().trimmed();
    QString adresse = ui->lineEdit_29->text().trimmed();

    QString sexe = "";
    if(ui->radioButton_4->isChecked()) sexe = "femme";
    else if(ui->radioButton_5->isChecked()) sexe = "homme";

    if(nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide");
        return;
    }

    if(prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le prénom ne peut pas être vide");
        return;
    }

    if(email.isEmpty() || !email.contains("@")) {
        QMessageBox::warning(this, "Erreur", "Email invalide");
        return;
    }

    // Configuration du client
    clientTemp.setCIN(cin);
    clientTemp.setPRENOM(prenom);
    clientTemp.setNOM(nom);
    clientTemp.setEMAIL(email);
    clientTemp.setTELEPHONE(telephone);
    clientTemp.setADRESSE(adresse);
    clientTemp.setSEXE(sexe);

    // Modification
    if(clientTemp.modifier(cin)) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès!");
        afficherClients();
        viderChampsClient();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification");
    }
}

void MainWindow::on_btnSupprimerClient_clicked()
{
    qDebug() << "=== SUPPRESSION CLIENT ===";

    QString cinStr = ui->lineEdit_6->text().trimmed();
    if(cinStr.isEmpty()) {
        cinStr = QInputDialog::getText(this, "Suppression", "CIN du client à supprimer:");
    }

    if(cinStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer le CIN du client à supprimer");
        return;
    }

    bool ok;
    int cin = cinStr.toInt(&ok);
    if(!ok || cin <= 0) {
        QMessageBox::warning(this, "Erreur", "CIN invalide");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Supprimer le client CIN " + cinStr + "?",
                                  QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes) {
        if(clientTemp.supprimer(cin)) {
            QMessageBox::information(this, "Succès", "Client supprimé");
            afficherClients();
            viderChampsClient();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec suppression");
        }
    }
}

void MainWindow::on_tableWidgetClients_itemClicked(QTableWidgetItem *item)
{
    if (!item) return;

    int row = item->row();
    if (row < 0 || row >= ui->tableWidget_5->rowCount()) return;

    try {
        // Récupération des données
        QString cin = ui->tableWidget_5->item(row, 0)->text();
        QString prenom = ui->tableWidget_5->item(row, 1)->text();
        QString nom = ui->tableWidget_5->item(row, 2)->text();
        QString email = ui->tableWidget_5->item(row, 3)->text();
        QString telephone = ui->tableWidget_5->item(row, 4)->text();
        QString adresse = ui->tableWidget_5->item(row, 5)->text();
        QString sexe = ui->tableWidget_5->item(row, 6)->text();

        // Remplissage des champs
        ui->lineEdit_6->setText(cin);
        ui->lineEdit_7->setText(prenom);
        ui->lineEdit_8->setText(nom);
        ui->lineEdit_9->setText(email);
        ui->lineEdit_10->setText(telephone);
        ui->lineEdit_29->setText(adresse);

        // Sexe
        ui->radioButton_4->setAutoExclusive(false);
        ui->radioButton_4->setChecked(sexe.toLower().contains("femme"));
        ui->radioButton_5->setChecked(sexe.toLower().contains("homme"));
        ui->radioButton_4->setAutoExclusive(true);

        // Bloquer le CIN
        ui->lineEdit_6->setReadOnly(true);
        ui->lineEdit_6->setStyleSheet("background-color: #f0f0f0; color: #666;");

        qDebug() << "Client sélectionné:" << nom << prenom;

    } catch (...) {
        QMessageBox::warning(this, "Erreur", "Erreur sélection client");
    }
}

// ================== ADDITIONAL BUTTON IMPLEMENTATIONS ==================

// ===== PRODUIT/STOCK PAGE BUTTONS =====
void MainWindow::on_pushButton_4_clicked()  // TRI Produits
{
    qDebug() << "=== TRI PRODUITS ===";
    QStringList options;
    options << "Par Référence" << "Par Nom" << "Par Prix" << "Par Quantité";

    bool ok;
    QString choice = QInputDialog::getItem(this, "Trier les Produits", "Choisir le critère de tri:",
                                           options, 0, false, &ok);

    if(ok && !choice.isEmpty()) {
        QString orderBy = "REFERENCE";
        if(choice == "Par Nom") orderBy = "NOM";
        else if(choice == "Par Prix") orderBy = "PRIX";
        else if(choice == "Par Quantité") orderBy = "QUANTITE";

        QSqlQuery query("SELECT REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, TO_CHAR(DATE_FAB, 'YYYY-MM-DD'), TO_CHAR(DATE_EXP, 'YYYY-MM-DD') FROM PRODUIT ORDER BY " + orderBy);

        ui->tableWidget->setRowCount(0);
        int row = 0;
        while(query.next()) {
            ui->tableWidget->insertRow(row);
            for(int col = 0; col < 8; col++) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
            }
            row++;
        }
        QMessageBox::information(this, "Succès", QString("Trié par %1 - %2 produits").arg(choice).arg(row));
    }
}

void MainWindow::on_pushButton_5_clicked()  // Recherche Produits
{
    qDebug() << "=== RECHERCHE PRODUITS ===";
    QString searchTerm = ui->lineEdit_28->text().trimmed();

    if(searchTerm.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Entrez un terme de recherche");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, TO_CHAR(DATE_FAB, 'YYYY-MM-DD'), TO_CHAR(DATE_EXP, 'YYYY-MM-DD') "
                  "FROM PRODUIT WHERE REFERENCE = :search OR UPPER(NOM) LIKE UPPER(:searchPattern)");
    query.bindValue(":search", searchTerm.toInt());
    query.bindValue(":searchPattern", "%" + searchTerm + "%");

    if(!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche");
        return;
    }

    ui->tableWidget->setRowCount(0);
    int row = 0;
    while(query.next()) {
        ui->tableWidget->insertRow(row);
        for(int col = 0; col < 8; col++) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }

    if(row > 0) {
        QMessageBox::information(this, "Recherche", QString("%1 produit(s) trouvé(s)").arg(row));
    } else {
        QMessageBox::information(this, "Recherche", "Aucun produit trouvé");
    }
}

void MainWindow::on_pushButton_3_clicked()  // Export PDF
{
    qDebug() << "=== EXPORT PDF PRODUITS ===";
    QMessageBox::information(this, "Export PDF", "Fonctionnalité d'export PDF à implémenter\n(nécessite QPrinter et QPainter)");
}

void MainWindow::on_pushButton_22_clicked() // Upload Image
{
    qDebug() << "=== UPLOAD IMAGE ===";
    QMessageBox::information(this, "Upload Image", "Fonctionnalité d'upload d'image à implémenter\n(nécessite QFileDialog)");
}

// ===== CLIENT PAGE BUTTONS =====
void MainWindow::on_pushButton_10_clicked() // Rechercher un client
{
    qDebug() << "=== RECHERCHE CLIENT ===";
    QString searchTerm = ui->lineEdit_11->text().trimmed();

    if(searchTerm.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Entrez un CIN ou nom à rechercher");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE "
                  "FROM CLIENT WHERE CIN = :search OR UPPER(NOM) LIKE UPPER(:searchPattern) OR UPPER(PRENOM) LIKE UPPER(:searchPattern)");
    query.bindValue(":search", searchTerm.toInt());
    query.bindValue(":searchPattern", "%" + searchTerm + "%");

    if(!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche");
        return;
    }

    if(query.next()) {
        ui->lineEdit_6->setText(query.value(0).toString());
        ui->lineEdit_7->setText(query.value(1).toString());
        ui->lineEdit_8->setText(query.value(2).toString());
        ui->lineEdit_9->setText(query.value(3).toString());
        ui->lineEdit_10->setText(query.value(4).toString());
        ui->lineEdit_29->setText(query.value(5).toString());

        QString sexe = query.value(6).toString();
        ui->radioButton_4->setChecked(sexe.toLower().contains("femme"));
        ui->radioButton_5->setChecked(sexe.toLower().contains("homme"));

        QMessageBox::information(this, "Succès", "Client trouvé!");
    } else {
        QMessageBox::information(this, "Recherche", "Aucun client trouvé");
    }
}

void MainWindow::on_pushButton_11_clicked() // TRI clients
{
    qDebug() << "=== TRI CLIENTS ===";
    QStringList options;
    options << "Par CIN" << "Par Nom" << "Par Prénom";

    bool ok;
    QString choice = QInputDialog::getItem(this, "Trier les Clients", "Choisir le critère de tri:",
                                           options, 0, false, &ok);

    if(ok && !choice.isEmpty()) {
        QString orderBy = "CIN";
        if(choice == "Par Nom") orderBy = "NOM";
        else if(choice == "Par Prénom") orderBy = "PRENOM";

        QSqlQuery query("SELECT CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE FROM CLIENT ORDER BY " + orderBy);

        ui->tableWidget_5->setRowCount(0);
        int row = 0;
        while(query.next()) {
            ui->tableWidget_5->insertRow(row);
            for(int col = 0; col < 7; col++) {
                ui->tableWidget_5->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
            }   
            row++;
        }
        QMessageBox::information(this, "Succès", QString("Trié par %1 - %2 clients").arg(choice).arg(row));
    }
}

void MainWindow::on_pushButton_33_clicked() // PDF clients
{
    qDebug() << "=== EXPORT PDF CLIENTS ===";
    QMessageBox::information(this, "Export PDF", "Fonctionnalité d'export PDF clients à implémenter");
}

void MainWindow::on_pushButton_12_clicked() // Statut fidélité
{
    qDebug() << "=== STATUT FIDELITE ===";
    QMessageBox::information(this, "Statut Fidélité", "⭐ Programme de fidélité clients\n\nFonctionnalité à développer:\n- Points de fidélité\n- Réductions\n- Avantages");
}

void MainWindow::on_pushButton_13_clicked() // Historique médical
{
    qDebug() << "=== HISTORIQUE MEDICAL ===";
    QMessageBox::information(this, "Historique Médical", "🗓️ Historique médical clients\n\nFonctionnalité à développer:\n- Prescriptions\n- Historique achats\n- Dossier médical");
}

// ===== SPONSOR PAGE BUTTONS =====
void MainWindow::on_pushButton_23_clicked() // Ajouter Sponsor
{
    qDebug() << "=== AJOUT SPONSOR ===";
    QMessageBox::information(this, "Ajouter Sponsor", "Fonctionnalité d'ajout de sponsor à implémenter\n(nécessite classe Sponsor et table SPONSORING)");
}

void MainWindow::on_pushButton_24_clicked() // Afficher Sponsors
{
    qDebug() << "=== AFFICHER SPONSORS ===";
    QSqlQuery query("SELECT * FROM SPONSORING");
    int count = 0;
    while(query.next()) count++;
    QMessageBox::information(this, "Sponsors", QString("%1 sponsors dans la base").arg(count));
}

void MainWindow::on_pushButton_27_clicked() // Modifier Sponsor
{
    qDebug() << "=== MODIFIER SPONSOR ===";
    QMessageBox::information(this, "Modifier Sponsor", "Fonctionnalité de modification de sponsor à implémenter");
}

void MainWindow::on_pushButton_29_clicked() // Supprimer Sponsor
{
    qDebug() << "=== SUPPRIMER SPONSOR ===";
    QMessageBox::information(this, "Supprimer Sponsor", "Fonctionnalité de suppression de sponsor à implémenter");
}

void MainWindow::on_pushButton_30_clicked() // Statu Sponsor
{
    qDebug() << "=== STATISTIQUES SPONSOR ===";
    QSqlQuery query("SELECT COUNT(*) FROM SPONSORING");
    if(query.next()) {
        int total = query.value(0).toInt();
        QMessageBox::information(this, "Statistiques", QString("📊 Total sponsors: %1").arg(total));
    }
}

void MainWindow::on_pushButton_26_clicked() // Recommandation automatique
{
    qDebug() << "=== RECOMMANDATION AUTOMATIQUE ===";
    QMessageBox::information(this, "Recommandation", "🤖 Système de recommandation automatique\n\nFonctionnalité IA à développer");
}
