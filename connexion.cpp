#include "connexion.h"
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

Connection::Connection()
{
}

bool Connection::createconnect()
{
    // Vérifie d'abord si une connexion existe déjà
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
        if (db.isOpen()) {
            qDebug() << "Connexion déjà ouverte";
            return true;
        }
    }

    /*// Crée une nouvelle connexion
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("smartoptic");
    db.setUserName("system");
    db.setPassword("Sou16022005@");*/
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Oracle in XE};Dbq=XE;Uid=system;Pwd=Sou16022005@;");

    if (db.open()) {
        qDebug() << "Connexion à la base de données réussie";
        return true;
    } else {
        qDebug() << "Échec de connexion:" << db.lastError().text();
        QMessageBox::critical(nullptr, "Erreur de connexion",
                              "Impossible de se connecter à la base de données:\n" + db.lastError().text());
        return false;
    }
}
