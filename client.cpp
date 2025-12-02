#include "client.h"
#include <QSqlQuery>
#include <QDebug>
#include <QTableWidgetItem>
#include <QSqlError>

// Constructeur
Client::Client()
    : CIN(0)
{
}

// Méthode ajouter
bool Client::ajouter()
{
    qDebug() << "=== TENTATIVE AJOUT CLIENT ===";

    // Vérifications basiques
    if(CIN <= 0) {
        qDebug() << "❌ ERREUR: CIN invalide :" << CIN;
        return false;
    }

    if(NOM.isEmpty()) {
        qDebug() << "❌ ERREUR: Nom client vide";
        return false;
    }

    // AFFICHER TOUTES LES DONNÉES POUR DEBUG
    qDebug() << "CIN:" << CIN;
    qDebug() << "Prenom:" << PRENOM;
    qDebug() << "Nom:" << NOM;
    qDebug() << "Email:" << EMAIL;
    qDebug() << "Téléphone:" << TELEPHONE;
    qDebug() << "Adresse:" << ADRESSE;
    qDebug() << "Sexe:" << SEXE;

    // Vérifier la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "❌ ERREUR: Base de données non connectée";
        qDebug() << "Erreur DB:" << db.lastError().text();
        return false;
    }

    // Vérifier si le CIN existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM CLIENT WHERE CIN = :cin");
    checkQuery.bindValue(":cin", CIN);

    if (!checkQuery.exec()) {
        qDebug() << "❌ ERREUR lors de la vérification du CIN:" << checkQuery.lastError().text();
        return false;
    }

    if(checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        qDebug() << "❌ ERREUR: Ce CIN existe déjà ! CIN:" << CIN;
        return false;
    }

    // Utiliser des prepared statements
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE) "
                  "VALUES (:cin, :prenom, :nom, :email, :telephone, :adresse, :sexe)");

    query.bindValue(":cin", CIN);
    query.bindValue(":prenom", PRENOM);
    query.bindValue(":nom", NOM);
    query.bindValue(":email", EMAIL);
    query.bindValue(":telephone", TELEPHONE);
    query.bindValue(":adresse", ADRESSE);
    query.bindValue(":sexe", SEXE);

    qDebug() << "Requête SQL préparée:" << query.lastQuery();

    if(query.exec()) {
        qDebug() << "✅✅✅ SUCCÈS! Client ajouté";
        return true;
    } else {
        qDebug() << "❌ ÉCHEC de l'insertion:" << query.lastError().text();
        qDebug() << "Erreur détaillée:" << query.lastError().databaseText();
        return false;
    }
}

void Client::remplirTableWidget(QTableWidget *tableWidget)
{
    // Récupérer TOUTES les colonnes nécessaires
    QSqlQuery query("SELECT CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE FROM CLIENT");

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(7); // 7 colonnes

    QStringList headers;
    headers << "CIN" << "Prénom" << "Nom" << "Email" << "Téléphone"
            << "Adresse" << "Sexe";
    tableWidget->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // CIN
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // PRENOM
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // NOM
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // EMAIL
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // TELEPHONE
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // ADRESSE
        tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // SEXE
        row++;
    }

    tableWidget->resizeColumnsToContents();

    qDebug() << "Nombre de clients chargés:" << row;
}

bool Client::supprimer(int cin)
{
    if(cin <= 0) return false;

    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    if(query.exec()) {
        qDebug() << "✅ Client supprimé avec succès, CIN:" << cin;
        return true;
    } else {
        qDebug() << "❌ Échec de la suppression:" << query.lastError().text();
        return false;
    }
}

bool Client::modifier(int cin)
{
    qDebug() << "=== TENTATIVE MODIFICATION CLIENT ===";

    qDebug() << "Nouveau prénom:" << PRENOM;
    qDebug() << "Nouveau nom:" << NOM;
    qDebug() << "Nouveau email:" << EMAIL;

    // Requête SQL de modification avec prepared statements
    QSqlQuery query;
    query.prepare("UPDATE CLIENT SET PRENOM=:prenom, NOM=:nom, "
                  "EMAIL=:email, TELEPHONE=:telephone, ADRESSE=:adresse, SEXE=:sexe "
                  "WHERE CIN=:cin");

    query.bindValue(":prenom", PRENOM);
    query.bindValue(":nom", NOM);
    query.bindValue(":email", EMAIL);
    query.bindValue(":telephone", TELEPHONE);
    query.bindValue(":adresse", ADRESSE);
    query.bindValue(":sexe", SEXE);
    query.bindValue(":cin", cin);

    qDebug() << "SQL préparé:" << query.lastQuery();

    if(query.exec()) {
        qDebug() << "✅✅✅ CLIENT MODIFIÉ!";
        return true;
    }

    qDebug() << "❌ ÉCHEC de la modification:" << query.lastError().text();
    return false;
}

