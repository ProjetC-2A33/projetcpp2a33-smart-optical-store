#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"
#include "employe.h"
#include "fournisseur.h"
#include "client.h"


#include <QDialog>
#include <QTimer>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "client.h"
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QList>
#include <QByteArray>
#include <QString>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QSqlQueryModel>
#include <QInputDialog>
#include <QLabel>
#include <QVBoxLayout>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSqlQueryModel *sortBySalaireAsc();
    QSqlQueryModel *sortBySalaireDesc();

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


    

    




    void on_pb_supprimer_clicked();
    void on_pb_modifier_2_clicked();
    void on_pb_ajouter_clicked();
    void handleMessageBoxResult(int result);
    void refreshTable();
    void on_tab_clients_clicked(const QModelIndex &index);
    void refreshTable(QSqlQueryModel *model);
    void on_refrech_pb_clicked();
    void on_Imprimer_clicked();
    void on_pb_pdf_clicked();
    void on_pb_word_clicked();
    void on_lineEdit_textChanged(const QString &arg1);

    void on_tableWidget_c_cellClicked(int row, int column);
    void on_comboBox_tri_currentIndexChanged(int index);
    void on_search_textChanged(const QString &text);
    void on_stats_clicked();
    void envoyerSMS(const QString& telephone, const QString& message);
    void onSMSReply(QNetworkReply *reply);
    void on_pushButton_envoyerSMS_clicked();
    void on_pb_history_clicked();
   void updateStatsLabel();
    QPointF calculatePointOnCircle(QPointF center, double radius, double angleDegrees);

   void checkUI();
    void on_pushButton_11_clicked();



    void on_pushButton_6_clicked();

    void on_btnLogin_clicked();

private:
    Ui::MainWindow *ui;
    Produit produitTemp;
    Employe employeTemp;
    Fournisseur fournisseurTemp;
    Clients clientTemp;
    QNetworkAccessManager *networkManager;
   QString infobipApiKey = "159d83b9b9b5d72146befb991fe14eba-c3993467-3f30-4564-b7c7-5fdbd4edd91a";
    QString infobipBaseUrl = "https://nmvl3e.api.infobip.com";
};

#endif // MAINWINDOW_H
