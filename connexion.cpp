#include "connexion.h"

// ***** Constructeur *****
// Initialise la connexion avec les paramètres de la base de données
Connection::Connection() {
    // Using QOCI (Oracle Call Interface) - no ODBC driver needed!
    db = QSqlDatabase::addDatabase("QOCI");
}

// ***** Destructeur *****
// Ferme la connexion si elle est encore ouverte lorsque l'objet est détruit
Connection::~Connection() {
    if (db.isOpen())
        db.close();
}

// ***** Méthode statique *****
// Retourne une instance unique (singleton)
Connection& Connection::createInstance() {
    static Connection instance; // Unique instance (C++11 garantit la sécurité des threads)
    return instance;
}

// ***** Méthode d'ouverture de la connexion *****
bool Connection::createConnection () {
    // Check if database is already added
    if (!QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::addDatabase("QOCI");  // Direct Oracle connection!
    } else {
        db = QSqlDatabase::database();
    }
    
    // ========================================
    // CONFIGURATION: Change these for your user!
    // ========================================
    // Option 1: gestion_user (your current user) - ACTIVE
    // Format: hostname:port/servicename for pluggable database
    db.setDatabaseName("localhost:1521/xepdb1");  // Full connection string
    db.setUserName("gestion_user");               // Your username
    db.setPassword("123456789.mii");              // Your password
    
    // Option 2: ghaith user (your friend's user) - uncomment lines below
    // db.setDatabaseName("localhost:1521/XE");  // XE is the SID (old format)
    // db.setUserName("ghaith");
    // db.setPassword("esprit25");
    // ========================================

    qDebug() << "🔌 Tentative de connexion à Oracle...";
    qDebug() << "   Database:" << db.databaseName();
    qDebug() << "   User:" << db.userName();

    if (!db.open()) {
        qDebug() << "❌ ERREUR de connexion :" << db.lastError().text();
        qDebug() << "❌ Driver QOCI disponible?" << QSqlDatabase::isDriverAvailable("QOCI");
        return false;
    }

    qDebug() << "✅✅✅ Connexion Oracle réussie !";
    return true;
}
