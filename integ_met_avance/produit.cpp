#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QDateTime>
#include <QTableWidgetItem>
#include <qsqlerror.h>

// Constructeur
Produit::Produit()
    : QUANTITE(0), ID_FOURNISSEURS(0), ID_CLIENTS(0), PRIX(0.0)
{
}

// Méthode ajouter
bool Produit::ajouter()
{
    qDebug() << "=== TENTATIVE AJOUT AVEC TOUS LES CHAMPS ===";

    if(REFERENCE.isEmpty()) {
        qDebug() << "? ERREUR: Référence vide";
        return false;
    }

    bool ok;
    int refNumber = REFERENCE.toInt(&ok);
    if(!ok) {
        qDebug() << "? ERREUR: Référence doit ?tre un nombre";
        return false;
    }

    qDebug() << "Référence:" << refNumber;
    qDebug() << "Nom:" << NOM;
    qDebug() << "Quantité:" << QUANTITE;
    qDebug() << "Prix:" << PRIX;
    qDebug() << "Catégorie:" << CATEGORY;
    qDebug() << "Fournisseur:" << FOURNISSEURS;
    qDebug() << "Date Fabrication:" << DATE_FAB.toString("yyyy-MM-dd");
    qDebug() << "Date Expiration:" << DATE_EXP.toString("yyyy-MM-dd");

    // Requ?te SQL COMPL?TE avec tous les champs
    QString sql = QString("INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, DATE_FAB, DATE_EXP) VALUES (%1, '%2', %3, %4, '%5', '%6', TO_DATE('%7', 'YYYY-MM-DD'), TO_DATE('%8', 'YYYY-MM-DD'))")
                      .arg(refNumber)
                      .arg(NOM)
                      .arg(QUANTITE)
                      .arg(PRIX)
                      .arg(CATEGORY)
                      .arg(FOURNISSEURS)
                      .arg(DATE_FAB.toString("yyyy-MM-dd"))
                      .arg(DATE_EXP.toString("yyyy-MM-dd"));

    qDebug() << "SQL:" << sql;

    QSqlQuery query;
    if(query.exec(sql)) {
        qDebug() << "? SUCC?S! Produit ajouté";
        query.exec("COMMIT");
        return true;
    }

    qDebug() << "? ÉCHEC de l'insertion:" << query.lastError().text();
    return false;
}

void Produit::remplirTableWidget(QTableWidget *tableWidget)
{
    // Récupérer TOUTES les colonnes nécessaires
    QSqlQuery query("SELECT REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, TO_CHAR(DATE_FAB, 'YYYY-MM-DD'), TO_CHAR(DATE_EXP, 'YYYY-MM-DD') FROM PRODUIT");

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(8); // 8 colonnes

    QStringList headers;
    headers << "Référence" << "Nom" << "Quantité" << "Prix" << "Catégorie" << "Fournisseur" << "Date Fabrication" << "Date Expiration";
    tableWidget->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // REFERENCE
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // NOM
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // QUANTITE
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // PRIX
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // CATEGORY
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // FOURNISSEURS
        tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // DATE_FAB
        tableWidget->setItem(row, 7, new QTableWidgetItem(query.value(7).toString())); // DATE_EXP
        row++;
    }

    tableWidget->resizeColumnsToContents();

    qDebug() << "Nombre de produits chargés:" << row;
}
bool Produit::supprimer(QString reference)
{
    bool ok;
    int refNumber = reference.toInt(&ok);
    if(!ok) return false;

    QString sql = "DELETE FROM PRODUIT WHERE REFERENCE = " + QString::number(refNumber);
    QSqlQuery query;
    return query.exec(sql);
}






// modifier :
bool Produit::modifier(QString ancienneReference, QString nouvelleReference)
{
    qDebug() << "=== TENTATIVE MODIFICATION ===";

    qDebug() << "Nouveau nom:" << NOM;
    qDebug() << "Nouvelle quantité:" << QUANTITE;
    qDebug() << "Nouveau prix:" << PRIX;

    // Convertir les références en nombres
    bool ok1, ok2;
    int ancienneRefNumber = ancienneReference.toInt(&ok1);
    int nouvelleRefNumber = nouvelleReference.toInt(&ok2);

    if(!ok1 || !ok2) {
        qDebug() << "? Référence(s) invalide(s)";
        return false;
    }

    // Requ?te SQL de modification COMPL?TE avec changement de référence
    QString sql = QString("UPDATE PRODUIT SET REFERENCE=%1, NOM='%2', QUANTITE=%3, PRIX=%4, CATEGORY='%5', FOURNISSEURS='%6', DATE_FAB=TO_DATE('%7', 'YYYY-MM-DD'), DATE_EXP=TO_DATE('%8', 'YYYY-MM-DD') WHERE REFERENCE=%9")
                      .arg(nouvelleRefNumber)  // NOUVELLE référence
                      .arg(NOM)
                      .arg(QUANTITE)
                      .arg(PRIX)
                      .arg(CATEGORY)
                      .arg(FOURNISSEURS)
                      .arg(DATE_FAB.toString("yyyy-MM-dd"))
                      .arg(DATE_EXP.toString("yyyy-MM-dd"))
                      .arg(ancienneRefNumber);  // ANCIENNE référence pour WHERE

    qDebug() << "SQL:" << sql;

    QSqlQuery query;
    if(query.exec(sql)) {
        qDebug() << "??? PRODUIT MODIFIÉ!";
        query.exec("COMMIT");
        return true;
    }

    qDebug() << "? ÉCHEC de la modification";
    return false;
}
bool Produit::verifierFournisseurExiste(const QString& nomFournisseur)
{
    if(nomFournisseur.isEmpty()) {
        qDebug() << "? Nom fournisseur vide";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FOURNISSEURS WHERE UPPER(NOM_F) = UPPER(:nom_fournisseur)");
    query.bindValue(":nom_fournisseur", nomFournisseur.trimmed());

    if(!query.exec()) {
        qDebug() << "? Erreur lors de la vérification du fournisseur:" << query.lastError().text();
        return false;
    }

    if(query.next()) {
        int count = query.value(0).toInt();
        qDebug() << "?? Fournisseur" << nomFournisseur << "trouvé:" << count << "fois";
        return (count > 0);
    }

    return false;
}
