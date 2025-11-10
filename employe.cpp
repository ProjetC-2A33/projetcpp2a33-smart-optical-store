#include "employe.h"
#include <QSqlQuery>
#include <QDebug>
#include <QDateTime>
#include <QTableWidgetItem>
#include <QSqlError>

// Constructeur
Employe::Employe()
    : ID_EMPLOYE(0), SALAIRE(0.0), NBRE_ENFANTS(0), ANNEES_EXPERIENCE(0)
{
}

// Méthode ajouter
bool Employe::ajouter()
{
    qDebug() << "=== TENTATIVE AJOUT EMPLOYE ===";

    // Vérifications basiques
    if(ID_EMPLOYE <= 0) {
        qDebug() << "❌ ERREUR: ID employé invalide :" << ID_EMPLOYE;
        return false;
    }

    if(NOM_EMPLOYE.isEmpty()) {
        qDebug() << "❌ ERREUR: Nom employé vide";
        return false;
    }

    // AFFICHER TOUTES LES DONNÉES POUR DEBUG
    qDebug() << "ID:" << ID_EMPLOYE;
    qDebug() << "Nom:" << NOM_EMPLOYE;
    qDebug() << "Prénom:" << PRENOM_EMPLOYE;
    qDebug() << "Date Naissance:" << DATE_NAISSANCE.toString("yyyy-MM-dd");
    qDebug() << "Date Embauche:" << DATE_EMBAUCHE.toString("yyyy-MM-dd");
    qDebug() << "État Civil:" << ETAT_CIVIL;
    qDebug() << "Poste:" << POST;
    qDebug() << "Salaire:" << SALAIRE;
    qDebug() << "Nb Enfants:" << NBRE_ENFANTS;
    qDebug() << "Années Exp:" << ANNEES_EXPERIENCE;
    qDebug() << "Diplôme:" << DIPLOME;

    // Vérifier la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "❌ ERREUR: Base de données non connectée";
        qDebug() << "Erreur DB:" << db.lastError().text();
        return false;
    }

    // Vérifier si l'ID existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE ID_EMPLOYE = :id");
    checkQuery.bindValue(":id", ID_EMPLOYE);

    if (!checkQuery.exec()) {
        qDebug() << "❌ ERREUR lors de la vérification de l'ID:" << checkQuery.lastError().text();
        return false;
    }

    if(checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        qDebug() << "❌ ERREUR: Cet ID existe déjà ! ID:" << ID_EMPLOYE;
        return false;
    }

    // Utiliser des prepared statements
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (ID_EMPLOYE, NOM_EMPLOYE, PRENOM_EMPLOYE, DATE_NAISSANCE, DATE_EMBAUCHE, ETAT_CIVIL, POST, SALAIRE, NBRE_ENFANTS, ANNEES_EXPERIENCE, DIPLOME) "
                  "VALUES (:id, :nom, :prenom, TO_DATE(:date_naissance, 'YYYY-MM-DD'), TO_DATE(:date_embauche, 'YYYY-MM-DD'), :etat_civil, :post, :salaire, :nbre_enfants, :annees_experience, :diplome)");

    query.bindValue(":id", ID_EMPLOYE);
    query.bindValue(":nom", NOM_EMPLOYE);
    query.bindValue(":prenom", PRENOM_EMPLOYE);
    query.bindValue(":date_naissance", DATE_NAISSANCE.toString("yyyy-MM-dd"));
    query.bindValue(":date_embauche", DATE_EMBAUCHE.toString("yyyy-MM-dd"));
    query.bindValue(":etat_civil", ETAT_CIVIL);
    query.bindValue(":post", POST);
    query.bindValue(":salaire", SALAIRE);
    query.bindValue(":nbre_enfants", NBRE_ENFANTS);
    query.bindValue(":annees_experience", ANNEES_EXPERIENCE);
    query.bindValue(":diplome", DIPLOME);

    qDebug() << "Requête SQL préparée:" << query.lastQuery();

    if(query.exec()) {
        qDebug() << "✅✅✅ SUCCÈS! Employé ajouté";
        return true;
    } else {
        qDebug() << "❌ ÉCHEC de l'insertion:" << query.lastError().text();
        qDebug() << "Erreur détaillée:" << query.lastError().databaseText();
        return false;
    }
}

void Employe::remplirTableWidget(QTableWidget *tableWidget)
{
    // Récupérer TOUTES les colonnes nécessaires
    QSqlQuery query("SELECT ID_EMPLOYE, NOM_EMPLOYE, PRENOM_EMPLOYE, TO_CHAR(DATE_NAISSANCE, 'YYYY-MM-DD'), TO_CHAR(DATE_EMBAUCHE, 'YYYY-MM-DD'), ETAT_CIVIL, POST, SALAIRE, NBRE_ENFANTS, ANNEES_EXPERIENCE, DIPLOME FROM EMPLOYES");

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(11); // 11 colonnes

    QStringList headers;
    headers << "ID" << "Nom" << "Prénom" << "Date Naissance" << "Date Embauche"
            << "État Civil" << "Poste" << "Salaire" << "Nb Enfants" << "Années Exp" << "Diplôme";
    tableWidget->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID_EMPLOYE
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // NOM_EMPLOYE
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // PRENOM_EMPLOYE
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // DATE_NAISSANCE
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // DATE_EMBAUCHE
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // ETAT_CIVIL
        tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // POST
        tableWidget->setItem(row, 7, new QTableWidgetItem(query.value(7).toString())); // SALAIRE
        tableWidget->setItem(row, 8, new QTableWidgetItem(query.value(8).toString())); // NBRE_ENFANTS
        tableWidget->setItem(row, 9, new QTableWidgetItem(query.value(9).toString())); // ANNEES_EXPERIENCE
        tableWidget->setItem(row, 10, new QTableWidgetItem(query.value(10).toString())); // DIPLOME
        row++;
    }

    tableWidget->resizeColumnsToContents();

    qDebug() << "Nombre d'employés chargés:" << row;
}

bool Employe::supprimer(int idEmploye)
{
    if(idEmploye <= 0) return false;

    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYES WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", idEmploye);

    if(query.exec()) {
        qDebug() << "✅ Employé supprimé avec succès, ID:" << idEmploye;
        return true;
    } else {
        qDebug() << "❌ Échec de la suppression:" << query.lastError().text();
        return false;
    }
}
bool Employe::modifier(int idEmploye)
{
    qDebug() << "=== TENTATIVE MODIFICATION EMPLOYE ===";

    qDebug() << "Nouveau nom:" << NOM_EMPLOYE;
    qDebug() << "Nouveau prénom:" << PRENOM_EMPLOYE;
    qDebug() << "Nouveau salaire:" << SALAIRE;

    // Requête SQL de modification avec prepared statements
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYES SET NOM_EMPLOYE=:nom, PRENOM_EMPLOYE=:prenom, "
                  "DATE_NAISSANCE=TO_DATE(:date_naissance, 'YYYY-MM-DD'), DATE_EMBAUCHE=TO_DATE(:date_embauche, 'YYYY-MM-DD'), "
                  "ETAT_CIVIL=:etat_civil, POST=:post, SALAIRE=:salaire, NBRE_ENFANTS=:nbre_enfants, ANNEES_EXPERIENCE=:annees_experience, DIPLOME=:diplome "
                  "WHERE ID_EMPLOYE=:id");

    query.bindValue(":nom", NOM_EMPLOYE);
    query.bindValue(":prenom", PRENOM_EMPLOYE);
    query.bindValue(":date_naissance", DATE_NAISSANCE.toString("yyyy-MM-dd"));
    query.bindValue(":date_embauche", DATE_EMBAUCHE.toString("yyyy-MM-dd"));
    query.bindValue(":etat_civil", ETAT_CIVIL);
    query.bindValue(":post", POST);
    query.bindValue(":salaire", SALAIRE);
    query.bindValue(":nbre_enfants", NBRE_ENFANTS);
    query.bindValue(":annees_experience", ANNEES_EXPERIENCE);
    query.bindValue(":diplome", DIPLOME);
    query.bindValue(":id", idEmploye);

    qDebug() << "SQL préparé:" << query.lastQuery();

    if(query.exec()) {
        qDebug() << "✅✅✅ EMPLOYE MODIFIÉ!";
        return true;
    }

    qDebug() << "❌ ÉCHEC de la modification:" << query.lastError().text();
    return false;
}
