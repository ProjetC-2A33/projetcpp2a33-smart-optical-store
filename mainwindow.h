#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"
#include "employe.h"
#include "fournisseur.h"
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void onLoginClicked();

    // Navigation
    void on_btnGestionClients_PageStock_clicked();
    void on_btnGestionEmployes_PageStock_clicked();
    void on_btnBack_PageStock_clicked();
    void on_btnGestionStock_PageClients_clicked();
    void on_btnGestionEmployes_PageClients_clicked();
    void on_btnBack_PageClients_clicked();
    void on_btnGestionStock_Page_Employes_clicked();
    void on_btnGestionClients_Page_Employes_clicked();
    void on_btnBack_Page_Employes_clicked();
    void on_btnGestionSponsors_PageStock_clicked();
    void on_btnGestionFournisseurs_PageStock_clicked();
    void on_btnGestionSponsors_PageClients_clicked();
    void on_btnGestionFournisseurs_PageClients_clicked();
    void on_btnGestionSponsors_Page_Employes_clicked();
    void on_btnGestionFournisseurs_Page_Employes_clicked();
    void on_btnGestionStock_Page_Sponsors_clicked();
    void on_btnGestionClients_Page_Sponsors_clicked();
    void on_btnGestionEmployes_Page_Sponsors_clicked();
    void on_btnGestionFournisseurs_Page_Sponsors_clicked();
    void on_btnBack_Page_Sponsors_clicked();
    void on_btnGestionStock_Page_Fournisseurs_clicked();
    void on_btnGestionClients_Page_Fournisseurs_clicked();
    void on_btnGestionEmployes_PageFournisseurs_clicked();
    void on_btnGestionSponsors_Page_Fournisseurs_clicked();
    void on_btnBack_Page_Fournisseurs_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    // CRUD Produit
    void on_btnAjouter_clicked();
    void on_btnModifier_clicked();
    void on_btnSupprimer_clicked();
    void afficherProduits();
    void viderChamps();
    void chargerFournisseurs();

    // CRUD Employé
    void on_btnAjouterEmploye_clicked();
    void on_btnModifierEmploye_clicked();
    void on_btnSupprimerEmploye_clicked();
    void on_tableWidgetEmployes_itemClicked(QTableWidgetItem *item);
    void afficherEmployes();
    void viderChampsEmploye();

    // CRUD Fournisseur
    void on_btnAjouterFournisseur_clicked();
    void on_btnModifierFournisseur_clicked();
    void on_btnSupprimerFournisseur_clicked();
    void on_btnRechercherFournisseur_clicked();
    void on_btnTrierFournisseur_clicked();
    void on_btnStatFournisseur_clicked();
    void on_btnExportPdfFournisseur_clicked();
    void on_btnCallFournisseur_clicked();  // 📞 Call button
    void on_btnAIAgent_clicked();  // 🤖 AI Agent
    void on_btnAdvancedFeatures_clicked();
    void afficherFournisseurs();
    void viderChampsFournisseur();

    // CRUD Client
    void on_btnAjouterClient_clicked();
    void on_btnModifierClient_clicked();
    void on_btnSupprimerClient_clicked();
    void on_pushButton_10_clicked(); // Rechercher un client
    void on_tableWidgetClients_itemClicked(QTableWidgetItem *item);
    void afficherClients();
    void viderChampsClient();
    
    // Additional Buttons (Stock/Produit page)
    void on_pushButton_4_clicked();  // TRI Produits
    void on_pushButton_5_clicked();  // Recherche Produits
    void on_pushButton_3_clicked();  // Export PDF
    void on_pushButton_22_clicked(); // Upload Image
    
    // Client page advanced
    void on_pushButton_11_clicked(); // TRI clients
    void on_pushButton_33_clicked(); // PDF clients
    void on_pushButton_12_clicked(); // Statut fidélité
    void on_pushButton_13_clicked(); // Historique médical
    
    // Sponsor buttons
    void on_pushButton_23_clicked(); // Ajouter Sponsor
    void on_pushButton_24_clicked(); // Afficher Sponsors
    void on_pushButton_27_clicked(); // Modifier Sponsor
    void on_pushButton_29_clicked(); // Supprimer Sponsor
    void on_pushButton_30_clicked(); // Statu Sponsor
    void on_pushButton_26_clicked(); // Recommandation automatique

private:
    Ui::MainWindow *ui;
    Produit produitTemp;
    Employe employeTemp;
    Fournisseur fournisseurTemp;
    Client clientTemp;
};

#endif // MAINWINDOW_H
