#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QDate>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// Structure pour représenter un employé
struct Employe {
    int id;
    QString nom;
    QString prenom;
    QString email;
    QString motDePasse;  // Mot de passe unique pour chaque employé
    QDate dateEmbauche;
    QString poste;
    int anneesExperience;
    double salaire;
    QDate dateNaissance;
    QString etatCivil;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAjouterClicked();
    void onModifierClicked();
    void onSupprimerClicked();
    void onTableItemClicked(int row, int column);
    void onExporterPdfClicked();
    void onRechercheClicked();
    void onTriChanged(int index);
    void onAfficherStatistiquesPostes();
    void onDeconnecterClicked();

private:
    void afficherEmployes();
    bool chargerEmployesDepuisBdd(const QString& filtreRecherche, int indexTri);
    bool insererEmploye(const Employe& employe);
    bool modifierEmployeBdd(const Employe& employe);
    bool supprimerEmployeBdd(int id);
    void viderFormulaire();
    void remplirFormulaire(const Employe& employe);
    Employe lireFormulaire() const;
    int trouverIndexEmploye(int id) const;
    QString genererMotDePasseUnique(const QString& nom, const QString& prenom, int id) const;
    void onGenererMotDePasseClicked();
    // Mode mémoire uniquement (pas de base de données)

    Ui::MainWindow *ui;
    QList<Employe> listeEmployes;
    int prochainId;
    QString termeRecherche;
    int critereTriIndex;
};
#endif // MAINWINDOW_H
