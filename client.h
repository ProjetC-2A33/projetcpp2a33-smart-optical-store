#ifndef CLIENTS_H
#define CLIENTS_H

#include <QString>
#include <QSqlQueryModel>

class Clients
{
private:
    QString cin;
    QString nom;
    QString prenom;
    QString adresse;
    QString tel;
    QString email;
    QString sexe;
    QString historique;
    bool    statutFidelite;

    static bool logAction(const QString& cin, const QString& actionType,
                          const QString& oldValues = "", const QString& newValues = "");

public:
    // === Constructeurs ===
    Clients();
    Clients(const QString &cin,
            const QString &nom,
            const QString &prenom,
            const QString &adresse,
            const QString &tel,
            const QString &email,
            const QString &sexe,
            const QString &historique,
            bool statutFidelite);

    static QSqlQueryModel* getHistory();
    static bool clearHistory();
    // === Getters ===
    QString getCin()            const { return cin; }
    QString getNom()            const { return nom; }
    QString getPrenom()         const { return prenom; }
    QString getAdresse()        const { return adresse; }
    QString getTel()            const { return tel; }
    QString getEmail()          const { return email; }
    QString getSexe()           const { return sexe; }
    QString getHistorique()     const { return historique; }
    bool    isFidelite()        const { return statutFidelite; }

    // === Setters ===
    void setCin(const QString &c)            { cin = c; }
    void setNom(const QString &n)            { nom = n; }
    void setPrenom(const QString &p)         { prenom = p; }
    void setAdresse(const QString &a)        { adresse = a; }
    void setTel(const QString &t)            { tel = t; }
    void setEmail(const QString &e)          { email = e; }
    void setSexe(const QString &s)           { sexe = s; }
    void setHistorique(const QString &h)     { historique = h; }
    void setFidelite(bool f)                 { statutFidelite = f; }

    // === Database operations ===
    bool ajouter();
    QSqlQueryModel* afficher();
    static bool supprimer(const QString &cin);
    bool modifier();

    // === Vérification d'unicité ===
    static bool cinExiste(const QString &cin,
                          const QString &cinActuel = "");
    static bool emailExiste(const QString &email,
                            const QString &cinActuel = "");

    // === Fonctions demandées (Trier, Rechercher, PDF) ===
    static QSqlQueryModel* rechercher(const QString &critere);
    static QSqlQueryModel* trier(const QString &colonne, const QString &ordre);
    static bool exportPDF(const QString &filePath);
    static QSqlQueryModel* trierParCritere(const QString &critere, const QString &ordre = "");

};

#endif // CLIENTS_H
