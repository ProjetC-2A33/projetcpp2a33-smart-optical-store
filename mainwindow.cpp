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
, networkManager(new QNetworkAccessManager(this))
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
    connect(ui->pb_history, &QPushButton::clicked, []() {
        qDebug() << "pb_history button clicked (test connection)";
    });
    connect(ui->pb_history, &QPushButton::clicked, this, &MainWindow::on_pb_history_clicked);
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








#include "connexion.h"

    ui->cin_c->setValidator(new QIntValidator(0, 99999999, this));

    // Connect buttons to slots
    connect(ui->ajouter_c, &QPushButton::clicked, this, &MainWindow::on_pb_ajouter_clicked);
    connect(ui->supp_c, &QPushButton::clicked, this, &MainWindow::on_pb_supprimer_clicked);
    connect(ui->modif_c, &QPushButton::clicked, this, &MainWindow::on_pb_modifier_2_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pb_pdf_clicked);
    connect(ui->annuler_c, &QPushButton::clicked, this, &MainWindow::on_refrech_pb_clicked);
    connect(ui->tableWidget_c, &QTableWidget::cellClicked, this, &MainWindow::on_tableWidget_c_cellClicked);
    connect(ui->comboBox_tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_comboBox_tri_currentIndexChanged);
    connect(ui->search, &QLineEdit::textChanged, this, &MainWindow::on_search_textChanged);

    refreshTable();
    connect(ui->pushButton_envoyerSMS, &QPushButton::clicked,
            this, &MainWindow::on_pushButton_envoyerSMS_clicked);


    connect(networkManager, &QNetworkAccessManager::finished,
            this, &MainWindow::onSMSReply);



    ui->stats->setText("Cliquez sur 'Statistiques' pour afficher les données");
    QTimer *autoRefreshTimer = new QTimer(this);
    connect(autoRefreshTimer, &QTimer::timeout, this, &MainWindow::updateStatsLabel);
    autoRefreshTimer->start(5000); // Refresh every 5 seconds

    // Initial stats display
    updateStatsLabel();
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




void MainWindow::on_pb_ajouter_clicked()
{
    QString cin = ui->cin_c->text().trimmed();
    QString nom = ui->nom_c->text().trimmed();
    QString prenom = ui->prenom_c->text().trimmed();
    QString adresse = ui->adr_c->text().trimmed();
    QString tel = ui->tel_c->text().trimmed();
    QString email = ui->email_c->text().trimmed();
    QString sexe = ui->comboBoxsexe_c->currentText();

    // FIX: Use the correct combo box name from UI file
    QString statutText = ui->comboBoxSTATUTFIDELITE_c->currentText();

    bool statutFidelite = (statutText == "1");
    QString historique = "";

    if (cin.isEmpty() || nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() ||
        tel.isEmpty() || email.isEmpty() || sexe.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (cin.length() != 8) {
        QMessageBox::warning(this, "CIN invalide", "Le CIN doit contenir exactement 8 chiffres.");
        return;
    }

    // Use Clients class methods to check existence
    if (Clients::cinExiste(cin)) {
        QMessageBox::warning(this, "CIN existant", "Ce CIN existe déjà dans la base de données.");
        return;
    }

    if (Clients::emailExiste(email)) {
        QMessageBox::warning(this, "Email existant", "Cet email existe déjà dans la base de données.");
        return;
    }

    // Create and add client using Clients class
    Clients client(cin, nom, prenom, adresse, tel, email, sexe, historique, statutFidelite);

    if (client.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
        refreshTable();
        on_refrech_pb_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}


void MainWindow::on_pb_supprimer_clicked()
{
    QString cin = ui->cin_c->text().trimmed();

    if (cin.isEmpty()) {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un client à supprimer.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation de suppression",
                                  "Êtes-vous sûr de vouloir supprimer le client CIN: " + cin + " ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Clients::supprimer(cin)) {
            QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
            refreshTable();
            on_refrech_pb_clicked();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression du client.");
        }
    }
}

void MainWindow::on_pb_modifier_2_clicked()
{
    QString cin = ui->cin_c->text().trimmed();
    QString nom = ui->nom_c->text().trimmed();
    QString prenom = ui->prenom_c->text().trimmed();
    QString adresse = ui->adr_c->text().trimmed();
    QString tel = ui->tel_c->text().trimmed();
    QString email = ui->email_c->text().trimmed();
    QString sexe = ui->comboBoxsexe_c->currentText();

    // FIX: Use the correct combo box name from UI file
    QString statutText = ui->comboBoxSTATUTFIDELITE_c->currentText();

    bool statutFidelite = (statutText == "1");
    QString historique = "";

    if (cin.isEmpty()) {
        QMessageBox::warning(this, "Modification", "Veuillez sélectionner un client à modifier.");
        return;
    }

    if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() ||
        tel.isEmpty() || email.isEmpty() || sexe.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    // Use Clients class method to check email
    if (Clients::emailExiste(email, cin)) {
        QMessageBox::warning(this, "Email existant", "Cet email est déjà utilisé par un autre client.");
        return;
    }

    // Create and modify client using Clients class
    Clients client(cin, nom, prenom, adresse, tel, email, sexe, historique, statutFidelite);

    if (client.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès !");
        refreshTable();
        on_refrech_pb_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client.");
    }
}
void MainWindow::on_tab_clients_clicked(const QModelIndex &index)
{
    // Since you're using tableWidget_c instead of tab_clients, you need to implement this differently
    // This will need to be adapted based on how you want to handle selection in QTableWidget
}

void MainWindow::refreshTable()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT CIN, NOM, PRENOM, EMAIL, tel, ADRESSE, SEXE, STATUTFIDELITE FROM GESTIONCL2");

    if (model->lastError().isValid()) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les données des clients: " + model->lastError().text());
        delete model;
        return;
    }

    // Set headers
    model->setHeaderData(0, Qt::Horizontal, tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, tr("Sexe"));
    model->setHeaderData(7, Qt::Horizontal, tr("STATUTFIDELITE"));
    model->setHeaderData(8, Qt::Horizontal, tr("Nom Employé"));

    // For QTableWidget, you need to populate it manually
    ui->tableWidget_c->setRowCount(model->rowCount());
    ui->tableWidget_c->setColumnCount(model->columnCount());

    // Set headers for QTableWidget
    QStringList headers;
    headers << "CIN" << "Nom" << "Prénom" << "Email" << "Téléphone" << "Adresse" << "Sexe" << "STATUTFIDELITE" << "Nom Employé";
    ui->tableWidget_c->setHorizontalHeaderLabels(headers);

    // Populate data
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget_c->setItem(row, col, item);
        }
    }

    delete model;
}

void MainWindow::refreshTable(QSqlQueryModel *model)
{
    if (!model) return;

    ui->tableWidget_c->setRowCount(model->rowCount());
    ui->tableWidget_c->setColumnCount(model->columnCount());

    QStringList headers;
    headers << "CIN" << "Nom" << "Prénom" << "Email" << "Téléphone" << "Adresse" << "Sexe" << "STATUTFIDELITE" << "Nom Employé";
    ui->tableWidget_c->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget_c->setItem(row, col, item);
        }
    }
}

void MainWindow::on_refrech_pb_clicked()
{
    ui->cin_c->clear();
    ui->nom_c->clear();
    ui->prenom_c->clear();
    ui->adr_c->clear();
    ui->tel_c->clear();
    ui->email_c->clear();
    ui->comboBoxsexe_c->setCurrentIndex(0);

    // FIX: Use the correct combo box name from UI file
    ui->comboBoxSTATUTFIDELITE_c->setCurrentIndex(0);

    // Clear table selection if needed
    ui->tableWidget_c->clearSelection();
}
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString critere = arg1.trimmed();

    if (critere.isEmpty()) {
        refreshTable();
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString queryStr = "SELECT CIN, NOM, PRENOM, EMAIL, tel, ADRESSE, SEXE, STATUTFIDELITE FROM GESTIONCL2 "
                       "WHERE CIN LIKE '%" + critere + "%' OR "
                                   "NOM LIKE '%" + critere + "%' OR "
                                   "PRENOM LIKE '%" + critere + "%' OR "
                                   "EMAIL LIKE '%" + critere + "%'";

    model->setQuery(queryStr);

    if (model->lastError().isValid()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche: " + model->lastError().text());
        delete model;
        return;
    }

    refreshTable(model);
}


void MainWindow::on_pb_pdf_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    if (!filePath.isEmpty()) {
        // Implement PDF export functionality here
        QMessageBox::information(this, "PDF", "Export PDF - À implémenter");
    }
}

void MainWindow::handleMessageBoxResult(int result)
{
    if (result == QMessageBox::Cancel) {
        // Handle cancel action
    }
}

// Other methods - implement as needed
void MainWindow::on_Imprimer_clicked() {
    QMessageBox::information(this, "Impression", "Fonction d'impression - À implémenter");
}

void MainWindow::on_pb_word_clicked() {
    QMessageBox::information(this, "Word", "Export Word - À implémenter");
}





void MainWindow::on_tableWidget_c_cellClicked(int row, int column)
{
    // Get data from the clicked row
    QString cin = ui->tableWidget_c->item(row, 0)->text();
    QString nom = ui->tableWidget_c->item(row, 1)->text();
    QString prenom = ui->tableWidget_c->item(row, 2)->text();
    QString email = ui->tableWidget_c->item(row, 3)->text();
    QString tel = ui->tableWidget_c->item(row, 4)->text();
    QString adresse = ui->tableWidget_c->item(row, 5)->text();
    QString sexe = ui->tableWidget_c->item(row, 6)->text();
    QString statutFidelite = ui->tableWidget_c->item(row, 7)->text();

    // Populate line edits
    ui->cin_c->setText(cin);
    ui->nom_c->setText(nom);
    ui->prenom_c->setText(prenom);
    ui->email_c->setText(email);
    ui->tel_c->setText(tel);
    ui->adr_c->setText(adresse);

    // Set sexe in combo box
    int sexeIndex = ui->comboBoxsexe_c->findText(sexe);
    if (sexeIndex != -1) {
        ui->comboBoxsexe_c->setCurrentIndex(sexeIndex);
    } else {
        ui->comboBoxsexe_c->setCurrentIndex(0); // Default to first item if not found
    }

    // Set STATUTFIDELITE in combo box
    int statutIndex = ui->comboBoxSTATUTFIDELITE_c->findText(statutFidelite);
    if (statutIndex != -1) {
        ui->comboBoxSTATUTFIDELITE_c->setCurrentIndex(statutIndex);
    } else {
        ui->comboBoxSTATUTFIDELITE_c->setCurrentIndex(0); // Default to first item if not found
    }
}

void MainWindow::on_comboBox_tri_currentIndexChanged(int index)
{
    if (index == 0) return; // Skip the "Trier par" placeholder

    QString critere = ui->comboBox_tri->currentText();
    QSqlQueryModel *model = Clients::trierParCritere(critere, "");

    if (model) {
        refreshTable(model);
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors du tri des données.");
    }
}
void MainWindow::on_search_textChanged(const QString &text)
{
    QString searchText = text.trimmed();

    if (searchText.isEmpty()) {
        // If search is empty, show all data
        refreshTable();
        return;
    }

    // Use the Clients class search method
    QSqlQueryModel *model = Clients::rechercher(searchText);

    if (model && model->rowCount() > 0) {
        refreshTable(model);
    } else {
        // If no results found, show empty table
        ui->tableWidget_c->setRowCount(0);
        if (model) {
            delete model;
        }
    }
}
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>


#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "QMessageBox"
void MainWindow::envoyerSMS(const QString& telephone, const QString& message)
{

    QString formattedPhone = telephone;


    formattedPhone = formattedPhone.remove(" ").remove("-");


    if (!formattedPhone.startsWith("+")) {
        if (formattedPhone.startsWith("2")) {
            formattedPhone = "+216" + formattedPhone; // +2162xxxxxxx
        } else if (formattedPhone.length() == 8) {
            formattedPhone = "+216" + formattedPhone; // +216xxxxxxx
        }
    }


    QUrl url(infobipBaseUrl + "/sms/2/text/advanced");


    QJsonObject destinationObject;
    destinationObject["to"] = formattedPhone;

    QJsonArray destinationsArray;
    destinationsArray.append(destinationObject);

    QJsonObject messageObject;

    messageObject["from"] = "InfoSMS"; // Use this for free trial
    messageObject["destinations"] = destinationsArray; // Must be "destinations" array
    messageObject["text"] = message;

    QJsonArray messagesArray;
    messagesArray.append(messageObject);

    QJsonObject jsonPayload;
    jsonPayload["messages"] = messagesArray;

    QJsonDocument jsonDoc(jsonPayload);
    QByteArray postData = jsonDoc.toJson();

    qDebug() << "Sending JSON:" << jsonDoc.toJson(QJsonDocument::Indented);


    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", ("App " + infobipApiKey).toUtf8());

    networkManager->post(request, postData);

    QMessageBox::information(this, "SMS", "Envoi du SMS en cours...");
}
void MainWindow::onSMSReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();

        if (jsonObj.contains("messages")) {
            QJsonArray messages = jsonObj["messages"].toArray();
            if (!messages.isEmpty()) {
                QJsonObject firstMessage = messages[0].toObject();
                QJsonObject statusObj = firstMessage["status"].toObject();
                QString status = statusObj["name"].toString();
                QString messageId = firstMessage["messageId"].toString();

                QMessageBox::information(this, "SMS Réussi",
                                         QString("SMS envoyé avec succès!\nStatus: %1\nID: %2")
                                             .arg(status).arg(messageId));
            } else {
                QMessageBox::information(this, "SMS Réussi", "SMS envoyé avec succès!");
            }
        } else {
            QMessageBox::information(this, "SMS Réussi", "SMS envoyé avec succès!");
        }
    } else {
        QString errorDetails = reply->errorString();
        QByteArray response = reply->readAll();

        if (!response.isEmpty()) {
            QJsonDocument errorDoc = QJsonDocument::fromJson(response);
            if (!errorDoc.isNull()) {
                QJsonObject errorObj = errorDoc.object();
                if (errorObj.contains("requestError")) {
                    QJsonObject serviceException = errorObj["requestError"].toObject()["serviceException"].toObject();
                    errorDetails += "\n" + serviceException["text"].toString();
                }
            }
        }

        QMessageBox::critical(this, "Erreur SMS",
                              QString("Erreur lors de l'envoi du SMS: %1")
                                  .arg(errorDetails));
    }

    reply->deleteLater();
}

void MainWindow::on_pushButton_envoyerSMS_clicked()
{
    QString telephone = ui->tel_c->text().trimmed();
    QString nom = ui->nom_c->text().trimmed();

    if (telephone.isEmpty()) {
        QMessageBox::warning(this, "SMS", "Veuillez sélectionner un sponsor avec un numéro de téléphone.");
        return;
    }

    if (telephone.length() < 8) {
        QMessageBox::warning(this, "SMS", "Numéro de téléphone invalide.");
        return;
    }

    QString defaultMessage = QString("Cher(e) %1, nous vous remercions pour votre confiance et votre fidélité. C'est un plaisir de vous compter parmi nos clients.")
                                 .arg(nom.isEmpty() ? "client" : nom);

    bool ok;
    QString customMessage = QInputDialog::getMultiLineText(this,
                                                           "Message SMS",
                                                           "Entrez votre message:",
                                                           defaultMessage,
                                                           &ok);

    if (ok && !customMessage.isEmpty()) {
        if (customMessage.length() > 160) {
            QMessageBox::warning(this, "SMS", "Le message est trop long (max 160 caractères).");
            return;
        }
        envoyerSMS(telephone, customMessage);
    }
}
#include <QInputDialog>
void MainWindow::on_pb_history_clicked()
{
    QSqlQueryModel *historyModel = Clients::getHistory();

    if (!historyModel) {
        QMessageBox::warning(this, "Historique", "Impossible de charger l'historique.");
        return;
    }

    // Create history dialog
    QDialog *historyDialog = new QDialog(this);
    historyDialog->setWindowTitle("Historique des Modifications - Clients");
    historyDialog->setModal(true);
    historyDialog->resize(900, 600);

    QVBoxLayout *layout = new QVBoxLayout(historyDialog);

    // Create table view
    QTableView *tableView = new QTableView();
    tableView->setModel(historyModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->resizeColumnsToContents();

    // Set column widths
    tableView->setColumnWidth(0, 60);  // ID
    tableView->setColumnWidth(1, 100); // CIN
    tableView->setColumnWidth(2, 80);  // Action
    tableView->setColumnWidth(3, 150); // Date/Heure
    tableView->setColumnWidth(4, 200); // Anciennes Valeurs
    tableView->setColumnWidth(5, 200); // Nouvelles Valeurs
    tableView->setColumnWidth(6, 100); // Utilisateur

    // Create buttons layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *detailsButton = new QPushButton("Détails");
    QPushButton *clearButton = new QPushButton("Vider l'Historique");
    QPushButton *closeButton = new QPushButton("Fermer");

    buttonLayout->addWidget(detailsButton);
    buttonLayout->addWidget(clearButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(closeButton);

    layout->addWidget(tableView);
    layout->addLayout(buttonLayout);

    // Connect buttons - FIXED: Use mutable lambda or different approach
    connect(detailsButton, &QPushButton::clicked, [tableView, historyModel]() {
        QModelIndexList selected = tableView->selectionModel()->selectedRows();
        if (selected.isEmpty()) {
            QMessageBox::information(tableView, "Détails", "Veuillez sélectionner une entrée de l'historique.");
            return;
        }

        int row = selected.first().row();
        QString action = historyModel->data(historyModel->index(row, 2)).toString();
        QString oldValues = historyModel->data(historyModel->index(row, 4)).toString();
        QString newValues = historyModel->data(historyModel->index(row, 5)).toString();
        QString cin = historyModel->data(historyModel->index(row, 1)).toString();
        QString date = historyModel->data(historyModel->index(row, 3)).toString();

        QString details = QString("Détails de l'action:\n\n"
                                  "CIN: %1\n"
                                  "Action: %2\n"
                                  "Date/Heure: %3\n\n").arg(cin).arg(action).arg(date);

        if (action == "ADD") {
            details += "Nouveau client ajouté:\n";
            if (!newValues.isEmpty()) {
                QJsonDocument doc = QJsonDocument::fromJson(newValues.toUtf8());
                if (!doc.isNull()) {
                    QJsonObject obj = doc.object();
                    for (auto it = obj.begin(); it != obj.end(); ++it) {
                        details += QString("- %1: %2\n").arg(it.key()).arg(it.value().toString());
                    }
                }
            }
        } else if (action == "UPDATE") {
            details += "Modifications:\n\n";
            if (!oldValues.isEmpty() && !newValues.isEmpty()) {
                QJsonDocument oldDoc = QJsonDocument::fromJson(oldValues.toUtf8());
                QJsonDocument newDoc = QJsonDocument::fromJson(newValues.toUtf8());

                if (!oldDoc.isNull() && !newDoc.isNull()) {
                    QJsonObject oldObj = oldDoc.object();
                    QJsonObject newObj = newDoc.object();

                    for (auto it = newObj.begin(); it != newObj.end(); ++it) {
                        QString key = it.key();
                        QString oldVal = oldObj.value(key).toString();
                        QString newVal = it.value().toString();

                        if (oldVal != newVal) {
                            details += QString("- %1: '%2' → '%3'\n").arg(key).arg(oldVal).arg(newVal);
                        }
                    }
                }
            }
        } else if (action == "DELETE") {
            details += "Client supprimé:\n";
            if (!oldValues.isEmpty()) {
                QJsonDocument doc = QJsonDocument::fromJson(oldValues.toUtf8());
                if (!doc.isNull()) {
                    QJsonObject obj = doc.object();
                    for (auto it = obj.begin(); it != obj.end(); ++it) {
                        details += QString("- %1: %2\n").arg(it.key()).arg(it.value().toString());
                    }
                }
            }
        }

        QMessageBox::information(tableView, "Détails de l'Action", details);
    });

    // FIXED: Use a different approach for clear button that doesn't modify captured variables
    connect(clearButton, &QPushButton::clicked, historyDialog, [historyDialog, tableView]() {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(historyDialog, "Confirmation",
                                      "Êtes-vous sûr de vouloir vider tout l'historique ?",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            if (Clients::clearHistory()) {
                QMessageBox::information(historyDialog, "Succès", "Historique vidé avec succès.");
                // Refresh the table by creating a new model
                QSqlQueryModel *newModel = Clients::getHistory();
                if (newModel) {
                    // Get the current model and delete it
                    QSqlQueryModel *oldModel = qobject_cast<QSqlQueryModel*>(tableView->model());
                    tableView->setModel(newModel);
                    if (oldModel) {
                        oldModel->deleteLater();
                    }

                    // Reset column widths
                    tableView->setColumnWidth(0, 60);
                    tableView->setColumnWidth(1, 100);
                    tableView->setColumnWidth(2, 80);
                    tableView->setColumnWidth(3, 150);
                    tableView->setColumnWidth(4, 200);
                    tableView->setColumnWidth(5, 200);
                    tableView->setColumnWidth(6, 100);
                }
            } else {
                QMessageBox::warning(historyDialog, "Erreur", "Impossible de vider l'historique.");
            }
        }
    });

    connect(closeButton, &QPushButton::clicked, historyDialog, &QDialog::accept);

    // Set dialog result and clean up properly
    connect(historyDialog, &QDialog::finished, [historyModel](int result) {
        Q_UNUSED(result)
        // The model will be deleted when the dialog is destroyed
        // since it's set as the parent of the model in the table view
    });

    historyDialog->exec();

    // Clean up - the model will be automatically deleted when the dialog is destroyed
    // because it's set as the model for the tableView which is a child of the dialog
}

void MainWindow::on_stats_clicked()
{
    updateStatsLabel();
}
void MainWindow::updateStatsLabel()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        // Create high-quality error pixmap
        QPixmap errorPixmap(300, 300);
        errorPixmap.fill(QColor(255, 240, 240)); // Light red background
        QPainter painter(&errorPixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        painter.setPen(QColor(231, 76, 60)); // Red
        painter.setFont(QFont("Arial", 14, QFont::Bold));
        painter.drawText(QRect(0, 100, 300, 50), Qt::AlignCenter, "❌");
        painter.setFont(QFont("Arial", 10, QFont::Normal));
        painter.drawText(QRect(0, 150, 300, 100), Qt::AlignCenter,
                         "Base de données\nnon connectée");
        ui->statslabel->setPixmap(errorPixmap.scaled(ui->statslabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT SEXE, COUNT(*) FROM GESTIONCL2 GROUP BY SEXE");

    int hommeCount = 0;
    int femmeCount = 0;

    if (query.exec()) {
        while (query.next()) {
            QString sexe = query.value(0).toString().toLower();
            int count = query.value(1).toInt();

            if (sexe == "homme") {
                hommeCount = count;
            } else if (sexe == "femme") {
                femmeCount = count;
            }
        }
    } else {
        // Create high-quality error pixmap
        QPixmap errorPixmap(300, 300);
        errorPixmap.fill(QColor(255, 240, 240));
        QPainter painter(&errorPixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        painter.setPen(QColor(231, 76, 60));
        painter.setFont(QFont("Arial", 14, QFont::Bold));
        painter.drawText(QRect(0, 100, 300, 50), Qt::AlignCenter, "❌");
        painter.setFont(QFont("Arial", 10, QFont::Normal));
        painter.drawText(QRect(0, 150, 300, 100), Qt::AlignCenter,
                         "Erreur de requête");
        ui->statslabel->setPixmap(errorPixmap.scaled(ui->statslabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
        return;
    }

    int total = hommeCount + femmeCount;

    if (total == 0) {
        // Create high-quality empty state
        QPixmap emptyPixmap(300, 300);
        emptyPixmap.fill(QColor(248, 249, 250));
        QPainter painter(&emptyPixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        // Draw empty pie with gradient
        QRadialGradient gradient(150, 150, 140);
        gradient.setColorAt(0, QColor(230, 230, 230));
        gradient.setColorAt(1, QColor(200, 200, 200));
        painter.setBrush(gradient);
        painter.setPen(QColor(150, 150, 150));
        painter.drawEllipse(50, 50, 200, 200);

        // Draw text
        painter.setPen(QColor(120, 120, 120));
        painter.setFont(QFont("Arial", 16, QFont::Bold));
        painter.drawText(QRect(50, 50, 200, 200), Qt::AlignCenter, "0");

        ui->statslabel->setPixmap(emptyPixmap.scaled(ui->statslabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
        return;
    }

    double pourcHommes = hommeCount * 100.0 / total;
    double pourcFemmes = femmeCount * 100.0 / total;

    // Create HIGH QUALITY pixmap - larger for better resolution
    int size = 400; // Increased size for better quality
    QPixmap pixmap(size, size);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    // Enable all rendering hints for best quality
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    //painter.setRenderHint(QPainter::HighQualityAntialiasing, true);

    // Draw pie chart with shadow effect
    QRectF pieRect(80, 80, size - 160, size - 160); // Centered with padding

    // Create gradient for homme slice
    QRadialGradient hommeGradient(pieRect.center(), pieRect.width()/2);
    hommeGradient.setColorAt(0, QColor(52, 152, 219).lighter(120));
    hommeGradient.setColorAt(1, QColor(52, 152, 219).darker(120));

    // Create gradient for femme slice
    QRadialGradient femmeGradient(pieRect.center(), pieRect.width()/2);
    femmeGradient.setColorAt(0, QColor(231, 76, 60).lighter(120));
    femmeGradient.setColorAt(1, QColor(231, 76, 60).darker(120));

    // Draw homme slice with gradient
    painter.setBrush(hommeGradient);
    painter.setPen(QPen(QColor(52, 152, 219).darker(150), 1));
    painter.drawPie(pieRect, 0, 16 * 360 * (pourcHommes / 100.0));

    // Draw femme slice with gradient
    painter.setBrush(femmeGradient);
    painter.setPen(QPen(QColor(231, 76, 60).darker(150), 1));
    painter.drawPie(pieRect, 16 * 360 * (pourcHommes / 100.0), 16 * 360 * (pourcFemmes / 100.0));

    // Draw pie outline with thicker line
    painter.setPen(QPen(QColor(80, 80, 80), 2));
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(pieRect);

    // Draw total in center - large and prominent
    painter.setPen(QColor(44, 62, 80));
    QFont totalFont("Arial", 28, QFont::Bold);
    totalFont.setStyleStrategy(QFont::PreferAntialias);
    painter.setFont(totalFont);

    // Draw background for total number
    painter.setBrush(QColor(255, 255, 255, 200)); // Semi-transparent white
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(pieRect.center(), 45, 45);

    // Draw total number
    painter.setPen(QColor(44, 62, 80));
    painter.drawText(pieRect, Qt::AlignCenter, QString::number(total));

    // Draw detailed legend with "Homme" and "Femme"
    int legendY = size - 60;

    // Homme legend with icon and full text
    painter.setBrush(QColor(52, 152, 219));
    painter.setPen(QPen(QColor(52, 152, 219).darker(150), 1));
    painter.drawEllipse(60, legendY, 14, 14);

    painter.setPen(QColor(44, 62, 80));
    QFont legendFont("Arial", 11, QFont::Bold);
    legendFont.setStyleStrategy(QFont::PreferAntialias);
    painter.setFont(legendFont);

    painter.drawText(80, legendY + 12, QString("Homme: %1 (%2%)")
                                           .arg(hommeCount)
                                           .arg(pourcHommes, 0, 'f', 1));

    // Femme legend with icon and full text
    painter.setBrush(QColor(231, 76, 60));
    painter.setPen(QPen(QColor(231, 76, 60).darker(150), 1));
    painter.drawEllipse(60, legendY + 30, 14, 14);

    painter.setPen(QColor(44, 62, 80));
    painter.drawText(80, legendY + 42, QString("Femme: %1 (%2%)")
                                           .arg(femmeCount)
                                           .arg(pourcFemmes, 0, 'f', 1));

    // Draw percentages on slices if they're large enough
    if (pourcHommes > 15) {
        double hommeAngle = pourcHommes * 3.6 / 2;
        QPointF hommePoint = calculatePointOnCircle(pieRect.center(),
                                                    pieRect.width()/2 * 0.7,
                                                    hommeAngle);

        painter.setPen(Qt::white);
        QFont sliceFont("Arial", 12, QFont::Bold);
        sliceFont.setStyleStrategy(QFont::PreferAntialias);
        painter.setFont(sliceFont);

        // Draw white background for text
        painter.setBrush(QColor(255, 255, 255, 150));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(hommePoint, 25, 25);

        // Draw percentage text
        painter.setPen(QColor(52, 152, 219).darker());
        painter.drawText(QRectF(hommePoint.x() - 25, hommePoint.y() - 12, 50, 24),
                         Qt::AlignCenter, QString("%1%").arg(pourcHommes, 0, 'f', 1));
    }

    if (pourcFemmes > 15) {
        double femmeAngle = pourcHommes * 3.6 + pourcFemmes * 3.6 / 2;
        QPointF femmePoint = calculatePointOnCircle(pieRect.center(),
                                                    pieRect.width()/2 * 0.7,
                                                    femmeAngle);

        painter.setPen(Qt::white);
        QFont sliceFont("Arial", 12, QFont::Bold);
        sliceFont.setStyleStrategy(QFont::PreferAntialias);
        painter.setFont(sliceFont);

        // Draw white background for text
        painter.setBrush(QColor(255, 255, 255, 150));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(femmePoint, 25, 25);

        // Draw percentage text
        painter.setPen(QColor(231, 76, 60).darker());
        painter.drawText(QRectF(femmePoint.x() - 25, femmePoint.y() - 12, 50, 24),
                         Qt::AlignCenter, QString("%1%").arg(pourcFemmes, 0, 'f', 1));
    }

    // Scale to label size with high quality
    QPixmap scaledPixmap = pixmap.scaled(ui->statslabel->size(),
                                         Qt::KeepAspectRatio,
                                         Qt::SmoothTransformation);

    ui->statslabel->setPixmap(scaledPixmap);
    ui->statslabel->setAlignment(Qt::AlignCenter);

    // Set size policy to prevent stretching
    ui->statslabel->setScaledContents(false);

    // Detailed tooltip
    QString tooltip = QString(
                          "<div style='font-family: Arial; font-size: 12px;'>"
                          "<b>📊 Statistiques Clients</b><br>"
                          "<hr style='border: 1px solid #ccc;'>"
                          "<table style='border-spacing: 5px;'>"
                          "<tr><td><b>Total:</b></td><td>%1 clients</td></tr>"
                          "<tr><td><span style='color: #3498db;'><b>Hommes:</b></span></td>"
                          "<td>%2 (%3%)</td></tr>"
                          "<tr><td><span style='color: #e74c3c;'><b>Femmes:</b></span></td>"
                          "<td>%4 (%5%)</td></tr>"
                          "</table>"
                          "</div>")
                          .arg(total)
                          .arg(hommeCount)
                          .arg(pourcHommes, 0, 'f', 1)
                          .arg(femmeCount)
                          .arg(pourcFemmes, 0, 'f', 1);

    ui->statslabel->setToolTip(tooltip);
}
QPointF MainWindow::calculatePointOnCircle(QPointF center, double radius, double angleDegrees)
{
    double angleRadians = angleDegrees * M_PI / 180.0;
    double x = center.x() + radius * cos(angleRadians);
    double y = center.y() + radius * sin(angleRadians);
    return QPointF(x, y);
}
