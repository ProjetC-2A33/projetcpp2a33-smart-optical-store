#include "connexion.h"

// ***** Constructeur *****
// Initialise la connexion avec les paramètres de la base de données
Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");
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
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Oracle in XE};Dbq=XE;Uid=ghaith;Pwd=esprit25;");

    if (!db.open()) {
        qDebug() << "Erreur de connexion :" << db.lastError().text();
        return false;
    }

    qDebug() << "Connexion réussie !";
    return true;
}
