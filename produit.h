#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>
#include <QTableWidget>

class Produit
{
private:
    QString REFERENCE;
    int QUANTITE;
    QString NOM;
    QString CATEGORY;
    QDate DATE_FAB;
    QDate DATE_EXP;
    QString FOURNISSEURS;
    int ID_FOURNISSEURS;
    int ID_CLIENTS;
    double PRIX;

public:
    Produit();

    // Setters
    void setREFERENCE(QString ref) { this->REFERENCE = ref; }
    void setQUANTITE(int quantite) { this->QUANTITE = quantite; }
    void setNOM(QString nom) { this->NOM = nom; }
    void setCATEGORY(QString category) { this->CATEGORY = category; }
    void setDATE_FAB(QDate date) { this->DATE_FAB = date; }
    void setDATE_EXP(QDate date) { this->DATE_EXP = date; }
    void setFOURNISSEURS(QString fournisseurs) { this->FOURNISSEURS = fournisseurs; }
    void setID_FOURNISSEURS(int id) { this->ID_FOURNISSEURS = id; }
    void setID_CLIENTS(int id) { this->ID_CLIENTS = id; }
    void setPRIX(double prix) { this->PRIX = prix; }

    // Getters
    QString getREFERENCE() const { return REFERENCE; }
    int getQUANTITE() const { return QUANTITE; }
    QString getNOM() const { return NOM; }
    QString getCATEGORY() const { return CATEGORY; }
    QDate getDATE_FAB() const { return DATE_FAB; }
    QDate getDATE_EXP() const { return DATE_EXP; }
    QString getFOURNISSEURS() const { return FOURNISSEURS; }
    int getID_FOURNISSEURS() const { return ID_FOURNISSEURS; }
    int getID_CLIENTS() const { return ID_CLIENTS; }
    double getPRIX() const { return PRIX; }

    // Méthodes CRUD
    bool ajouter();
    void remplirTableWidget(QTableWidget *tableWidget);
    bool supprimer(QString reference);
    bool modifier(QString ancienneReference, QString nouvelleReference);
};

#endif // PRODUIT_H
