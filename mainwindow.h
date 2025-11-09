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
    QString prenom;
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

private:
    void afficherEmployes();
    void viderFormulaire();
    void remplirFormulaire(const Employe& employe);
    Employe lireFormulaire() const;
    int trouverIndexEmploye(int id) const;
    // Mode mémoire uniquement (pas de base de données)

    Ui::MainWindow *ui;
    QList<Employe> listeEmployes;
    int prochainId;
};
#endif // MAINWINDOW_H
