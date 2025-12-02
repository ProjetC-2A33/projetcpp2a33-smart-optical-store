#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QTableWidget>

class Client
{
private:
    int CIN;
    QString PRENOM;
    QString NOM;
    QString EMAIL;
    QString TELEPHONE;
    QString ADRESSE;
    QString SEXE;

public:
    Client();

    // Setters
    void setCIN(int cin) { this->CIN = cin; }
    void setPRENOM(QString prenom) { this->PRENOM = prenom; }
    void setNOM(QString nom) { this->NOM = nom; }
    void setEMAIL(QString email) { this->EMAIL = email; }
    void setTELEPHONE(QString tel) { this->TELEPHONE = tel; }
    void setADRESSE(QString adresse) { this->ADRESSE = adresse; }
    void setSEXE(QString sexe) { this->SEXE = sexe; }

    // Getters
    int getCIN() const { return CIN; }
    QString getPRENOM() const { return PRENOM; }
    QString getNOM() const { return NOM; }
    QString getEMAIL() const { return EMAIL; }
    QString getTELEPHONE() const { return TELEPHONE; }
    QString getADRESSE() const { return ADRESSE; }
    QString getSEXE() const { return SEXE; }

    // Méthodes CRUD
    bool ajouter();
    void remplirTableWidget(QTableWidget *tableWidget);
    bool supprimer(int cin);
    bool modifier(int cin);
};

#endif // CLIENT_H


