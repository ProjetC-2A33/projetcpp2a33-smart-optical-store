#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QDateTime>
#include <QTableWidgetItem>

// Constructeur
Produit::Produit()
    : QUANTITE(0), ID_FOURNISSEURS(0), ID_CLIENTS(0), PRIX(0.0)
{
}

// Méthode ajouter
bool Produit::ajouter()
{
    qDebug() << "=== TENTATIVE AJOUT ===";

    // Vérifier la référence
    if(REFERENCE.isEmpty()) {
        qDebug() << "❌ ERREUR: Référence vide";
        return false;
    }

    // Convertir la référence en nombre
    bool ok;
    int refNumber = REFERENCE.toInt(&ok);
    if(!ok) {
        qDebug() << "❌ ERREUR: Référence doit être un nombre";
        return false;
    }

    qDebug() << "Référence:" << refNumber;
    qDebug() << "Nom:" << NOM;
    qDebug() << "Quantité:" << QUANTITE;
    qDebug() << "Prix:" << PRIX;
    qDebug() << "Catégorie:" << CATEGORY;
    qDebug() << "Fournisseur:" << FOURNISSEURS;

    // Requête SQL
    QString sql = QString("INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS) VALUES (%1, '%2', %3, %4, '%5', '%6')")
                      .arg(refNumber)
                      .arg(NOM)
                      .arg(QUANTITE)
                      .arg(PRIX)
                      .arg(CATEGORY)
                      .arg(FOURNISSEURS);

    qDebug() << "SQL:" << sql;

    QSqlQuery query;
    if(query.exec(sql)) {
        qDebug() << "✅✅✅ SUCCÈS! Produit ajouté";
        query.exec("COMMIT");
        return true;
    }

    qDebug() << "❌ ÉCHEC de l'insertion";
    return false;
}

void Produit::remplirTableWidget(QTableWidget *tableWidget)
{
    QSqlQuery query("SELECT REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS FROM PRODUIT");

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(6);

    QStringList headers;
    headers << "Référence" << "Nom" << "Quantité" << "Prix" << "Category" << "Fournisseurs";
    tableWidget->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        row++;
    }

    tableWidget->resizeColumnsToContents();
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
    qDebug() << "Ancienne référence:" << ancienneReference;
    qDebug() << "Nouvelle référence:" << nouvelleReference;
    qDebug() << "Nouveau nom:" << NOM;
    qDebug() << "Nouvelle quantité:" << QUANTITE;
    qDebug() << "Nouveau prix:" << PRIX;

    // Convertir les références en nombres
    bool ok1, ok2;
    int ancienneRefNumber = ancienneReference.toInt(&ok1);
    int nouvelleRefNumber = nouvelleReference.toInt(&ok2);

    if(!ok1 || !ok2) {
        qDebug() << "❌ Référence(s) invalide(s)";
        return false;
    }

    // Requête SQL de modification COMPLÈTE avec changement de référence
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
        qDebug() << "✅✅✅ PRODUIT MODIFIÉ!";
        query.exec("COMMIT");
        return true;
    }

    qDebug() << "❌ ÉCHEC de la modification";
    return false;
}
