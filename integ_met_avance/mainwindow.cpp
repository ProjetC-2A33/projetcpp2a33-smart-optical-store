#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow_navigation.cpp"
#include "mainwindow_produits.cpp"
#include "mainwindow_employes.cpp"
#include "mainwindow_tri_recherche.cpp"
#include "mainwindow_pdf_export.cpp"
#include "mainwindow_statistiques.cpp"
#include "mainwindow_image_detection.cpp"
#include "mainwindow_notifications.cpp"
#include "mainwindow_email_auth.cpp"
#include "mainwindow_styles.cpp"

// Initialisation de la clé API SendGrid
const QString MainWindow::SENDGRID_API_KEY = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Initialisation des composants
    model = new QSqlQueryModel(this);
    networkManager = new QNetworkAccessManager(this);
    
    // Configuration de l'interface utilisateur
    setupUi();
    applyStyles();
    setupSystemTray();
    
    // Connexion à la base de données
    if (!connectToDatabase()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données");
        QTimer::singleShot(0, this, &QApplication::quit);
        return;
    }
    
    // Initialisation des données
    afficherTousProduits();
    afficherTousEmployes();
    mettreAJourStatistiques();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("gestion_optique.db");
    
    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données:" << db.lastError().text();
        return false;
    }
    
    // Création des tables si elles n'existent pas
    QSqlQuery query;
    QStringList tables = db.tables();
    
    if (!tables.contains("PRODUITS")) {
        query.exec("CREATE TABLE PRODUITS ("
                  "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "REFERENCE TEXT NOT NULL UNIQUE, "
                  "NOM TEXT NOT NULL, "
                  "QUANTITE INTEGER NOT NULL, "
                  "PRIX REAL NOT NULL, "
                  "FOURNISSEUR TEXT, "
                  "TYPE TEXT, "
                  "DATE_AJOUT DATE DEFAULT CURRENT_DATE)");
    }
    
    if (!tables.contains("EMPLOYES")) {
        query.exec("CREATE TABLE EMPLOYES ("
                  "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "NOM TEXT NOT NULL, "
                  "PRENOM TEXT NOT NULL, "
                  "EMAIL TEXT UNIQUE, "
                  "TELEPHONE TEXT, "
                  "POSTE TEXT, "
                  "SALAIRE REAL, "
                  "DATE_EMBAUCHE DATE)");
    }
    
    if (!tables.contains("UTILISATEURS")) {
        query.exec("CREATE TABLE UTILISATEURS ("
                  "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "NOM_UTILISATEUR TEXT NOT NULL UNIQUE, "
                  "EMAIL TEXT NOT NULL UNIQUE, "
                  "MOT_DE_PASSE TEXT NOT NULL, "
                  "ROLE TEXT NOT NULL, "
                  "DATE_CREATION DATE DEFAULT CURRENT_DATE)");
    }
    
    return true;
}

void MainWindow::setupUi()
{
    // Configuration de la fenêtre principale
    setWindowTitle("Gestion Optique Pro");
    resize(1024, 768);
    
    // Configuration de la barre d'outils
    ui->toolBar->setMovable(false);
    
    // Configuration de la table des produits
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    
    // Configuration des validateurs pour les champs numériques
    ui->lineEdit_quantite->setValidator(new QIntValidator(0, 9999, this));
    ui->lineEdit_prix->setValidator(new QDoubleValidator(0, 999999.99, 2, this));
    
    // Configuration des dates
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_embauche->setDate(QDate::currentDate());
    
    // Configuration des menus déroulants
    QStringList typesProduits = {"Lunettes", "Lentilles", "Montures", "Étuis", "Accessoires"};
    ui->comboBox_type->addItems(typesProduits);
    
    QStringList postes = {"Vendeur", "Optométriste", "Gérant", "Comptable", "Autre"};
    ui->comboBox_poste->addItems(postes);
    
    // Connexion des signaux et slots
    connect(ui->actionQuitter, &QAction::triggered, this, &QApplication::quit);
    connect(ui->actionA_propos, &QAction::triggered, this, &MainWindow::afficherAPropos);
    
    // Autres initialisations d'interface utilisateur...
}

void MainWindow::afficherAPropos()
{
    QMessageBox::about(this, "À propos", 
                      "<h3>Gestion Optique Pro</h3>"
                      "<p>Version 1.0.0</p>"
                      "<p>Application de gestion pour magasins d'optique</p>"
                      "<p>&copy; 2025 Tous droits réservés</p>");
}
