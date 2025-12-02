#include "fournisseur.h"
#include <QSqlQuery>
#include <QDebug>
#include <QTableWidgetItem>
#include <QSqlError>

// Constructeur
Fournisseur::Fournisseur()
    : ID_FOURNISSEUR(0), IS_ACTIVE(1)
{
}

// Méthode ajouter
bool Fournisseur::ajouter()
{
    qDebug() << "=== TENTATIVE AJOUT FOURNISSEUR ===";

    // Vérifications basiques
    if(ID_FOURNISSEUR <= 0) {
        qDebug() << "❌ ERREUR: ID fournisseur invalide :" << ID_FOURNISSEUR;
        return false;
    }

    if(NOM.isEmpty()) {
        qDebug() << "❌ ERREUR: Nom fournisseur vide";
        return false;
    }

    // AFFICHER TOUTES LES DONNÉES POUR DEBUG
    qDebug() << "ID:" << ID_FOURNISSEUR;
    qDebug() << "Nom:" << NOM;
    qDebug() << "Adresse:" << ADRESSE;
    qDebug() << "Email:" << EMAIL;
    qDebug() << "Téléphone:" << TELEPHONE;
    qDebug() << "Type Produits:" << TYPE_PRODUITS;
    qDebug() << "Historique:" << HISTORIQUE_LIVRAISONS;
    qDebug() << "Active:" << IS_ACTIVE;

    // Vérifier la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "❌ ERREUR: Base de données non connectée";
        qDebug() << "Erreur DB:" << db.lastError().text();
        return false;
    }

    // Vérifier si l'ID existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM FOURNISSEUR WHERE ID_FOURNISSEUR = :id");
    checkQuery.bindValue(":id", ID_FOURNISSEUR);

    if (!checkQuery.exec()) {
        qDebug() << "❌ ERREUR lors de la vérification de l'ID:" << checkQuery.lastError().text();
        return false;
    }

    if(checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        qDebug() << "❌ ERREUR: Cet ID existe déjà ! ID:" << ID_FOURNISSEUR;
        return false;
    }

    // Utiliser des prepared statements
    QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE) "
                  "VALUES (:id, :nom, :adresse, :email, :telephone, :type_produits, :historique, :is_active)");

    query.bindValue(":id", ID_FOURNISSEUR);
    query.bindValue(":nom", NOM);
    query.bindValue(":adresse", ADRESSE);
    query.bindValue(":email", EMAIL);
    query.bindValue(":telephone", TELEPHONE);
    query.bindValue(":type_produits", TYPE_PRODUITS);
    query.bindValue(":historique", HISTORIQUE_LIVRAISONS);
    query.bindValue(":is_active", IS_ACTIVE);

    qDebug() << "Requête SQL préparée:" << query.lastQuery();

    if(query.exec()) {
        qDebug() << "✅✅✅ SUCCÈS! Fournisseur ajouté";
        return true;
    } else {
        qDebug() << "❌ ÉCHEC de l'insertion:" << query.lastError().text();
        qDebug() << "Erreur détaillée:" << query.lastError().databaseText();
        return false;
    }
}

void Fournisseur::remplirTableWidget(QTableWidget *tableWidget)
{
    // Récupérer TOUTES les colonnes nécessaires
    QSqlQuery query("SELECT ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE FROM FOURNISSEUR");

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(8); // 8 colonnes

    QStringList headers;
    headers << "ID" << "Nom" << "Adresse" << "Email" << "Téléphone"
            << "Type Produits" << "Historique" << "Active";
    tableWidget->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID_FOURNISSEUR
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // NOM
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // ADRESSE
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // EMAIL
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // TELEPHONE
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // TYPE_PRODUITS
        tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // HISTORIQUE_LIVRAISONS
        tableWidget->setItem(row, 7, new QTableWidgetItem(query.value(7).toString())); // IS_ACTIVE
        row++;
    }

    tableWidget->resizeColumnsToContents();

    qDebug() << "Nombre de fournisseurs chargés:" << row;
}

bool Fournisseur::supprimer(int idFournisseur)
{
    if(idFournisseur <= 0) return false;

    QSqlQuery query;
    query.prepare("DELETE FROM FOURNISSEUR WHERE ID_FOURNISSEUR = :id");
    query.bindValue(":id", idFournisseur);

    if(query.exec()) {
        qDebug() << "✅ Fournisseur supprimé avec succès, ID:" << idFournisseur;
        return true;
    } else {
        qDebug() << "❌ Échec de la suppression:" << query.lastError().text();
        return false;
    }
}

bool Fournisseur::modifier(int idFournisseur)
{
    qDebug() << "=== TENTATIVE MODIFICATION FOURNISSEUR ===";

    qDebug() << "Nouveau nom:" << NOM;
    qDebug() << "Nouveau email:" << EMAIL;
    qDebug() << "Nouveau type produits:" << TYPE_PRODUITS;

    // Requête SQL de modification avec prepared statements
    QSqlQuery query;
    query.prepare("UPDATE FOURNISSEUR SET NOM=:nom, ADRESSE=:adresse, "
                  "EMAIL=:email, TELEPHONE=:telephone, TYPE_PRODUITS=:type_produits, "
                  "HISTORIQUE_LIVRAISONS=:historique, IS_ACTIVE=:is_active "
                  "WHERE ID_FOURNISSEUR=:id");

    query.bindValue(":nom", NOM);
    query.bindValue(":adresse", ADRESSE);
    query.bindValue(":email", EMAIL);
    query.bindValue(":telephone", TELEPHONE);
    query.bindValue(":type_produits", TYPE_PRODUITS);
    query.bindValue(":historique", HISTORIQUE_LIVRAISONS);
    query.bindValue(":is_active", IS_ACTIVE);
    query.bindValue(":id", idFournisseur);

    qDebug() << "SQL préparé:" << query.lastQuery();

    if(query.exec()) {
        qDebug() << "✅✅✅ FOURNISSEUR MODIFIÉ!";
        return true;
    }

    qDebug() << "❌ ÉCHEC de la modification:" << query.lastError().text();
    return false;
}

