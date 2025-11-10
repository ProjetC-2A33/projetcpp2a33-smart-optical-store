#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QTableWidget>

class Fournisseur
{
private:
    int ID_FOURNISSEUR;
    QString NOM;
    QString ADRESSE;
    QString EMAIL;
    QString TELEPHONE;
    QString TYPE_PRODUITS;
    QString HISTORIQUE_LIVRAISONS;
    int IS_ACTIVE;

public:
    Fournisseur();

    // Setters
    void setID_FOURNISSEUR(int id) { this->ID_FOURNISSEUR = id; }
    void setNOM(QString nom) { this->NOM = nom; }
    void setADRESSE(QString adresse) { this->ADRESSE = adresse; }
    void setEMAIL(QString email) { this->EMAIL = email; }
    void setTELEPHONE(QString tel) { this->TELEPHONE = tel; }
    void setTYPE_PRODUITS(QString type) { this->TYPE_PRODUITS = type; }
    void setHISTORIQUE_LIVRAISONS(QString historique) { this->HISTORIQUE_LIVRAISONS = historique; }
    void setIS_ACTIVE(int active) { this->IS_ACTIVE = active; }

    // Getters
    int getID_FOURNISSEUR() const { return ID_FOURNISSEUR; }
    QString getNOM() const { return NOM; }
    QString getADRESSE() const { return ADRESSE; }
    QString getEMAIL() const { return EMAIL; }
    QString getTELEPHONE() const { return TELEPHONE; }
    QString getTYPE_PRODUITS() const { return TYPE_PRODUITS; }
    QString getHISTORIQUE_LIVRAISONS() const { return HISTORIQUE_LIVRAISONS; }
    int getIS_ACTIVE() const { return IS_ACTIVE; }

    // Méthodes CRUD
    bool ajouter();
    void remplirTableWidget(QTableWidget *tableWidget);
    bool supprimer(int idFournisseur);
    bool modifier(int idFournisseur);
};

#endif // FOURNISSEUR_H

