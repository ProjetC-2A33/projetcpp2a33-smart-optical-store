#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>
#include <QTableWidget>

class Employe
{
private:
    int ID_EMPLOYE;
    QString NOM_EMPLOYE;
    QString PRENOM_EMPLOYE;
    QDate DATE_NAISSANCE;
    QDate DATE_EMBAUCHE;
    QString ETAT_CIVIL;
    QString POST;
    double SALAIRE;
    int NBRE_ENFANTS;
    int ANNEES_EXPERIENCE;
    QString DIPLOME;

public:
    Employe();

    // Setters
    void setID_EMPLOYE(int id) { this->ID_EMPLOYE = id; }
    void setNOM_EMPLOYE(QString nom) { this->NOM_EMPLOYE = nom; }
    void setPRENOM_EMPLOYE(QString prenom) { this->PRENOM_EMPLOYE = prenom; }
    void setDATE_NAISSANCE(QDate date) { this->DATE_NAISSANCE = date; }
    void setDATE_EMBAUCHE(QDate date) { this->DATE_EMBAUCHE = date; }
    void setETAT_CIVIL(QString etat) { this->ETAT_CIVIL = etat; }
    void setPOST(QString post) { this->POST = post; }
    void setSALAIRE(double salaire) { this->SALAIRE = salaire; }
    void setNBRE_ENFANTS(int nbr) { this->NBRE_ENFANTS = nbr; }
    void setANNEES_EXPERIENCE(int annees) { this->ANNEES_EXPERIENCE = annees; }
    void setDIPLOME(QString diplome) { this->DIPLOME = diplome; }

    // Getters
    int getID_EMPLOYE() const { return ID_EMPLOYE; }
    QString getNOM_EMPLOYE() const { return NOM_EMPLOYE; }
    QString getPRENOM_EMPLOYE() const { return PRENOM_EMPLOYE; }
    QDate getDATE_NAISSANCE() const { return DATE_NAISSANCE; }
    QDate getDATE_EMBAUCHE() const { return DATE_EMBAUCHE; }
    QString getETAT_CIVIL() const { return ETAT_CIVIL; }
    QString getPOST() const { return POST; }
    double getSALAIRE() const { return SALAIRE; }
    int getNBRE_ENFANTS() const { return NBRE_ENFANTS; }
    int getANNEES_EXPERIENCE() const { return ANNEES_EXPERIENCE; }
    QString getDIPLOME() const { return DIPLOME; }

    // Méthodes CRUD
    bool ajouter();
    void remplirTableWidget(QTableWidget *tableWidget);
    bool supprimer(int idEmploye);
    bool modifier(int idEmploye);
};

#endif // EMPLOYE_Hndif // EMPLOYE_H
