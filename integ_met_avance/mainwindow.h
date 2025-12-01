#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDesktopServices>
#include <QStandardPaths>
#include <QMessageBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QFormLayout>
#include <QHeaderView>
#include <QDebug>
#include <QPixmap>
#include <QBuffer>
#include <QImage>
#include <QtMath>
#include <algorithm>
#include <QSystemTrayIcon>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QInputDialog>

// En-têtes OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/features2d/features2d.hpp>

// Pour utiliser les types OpenCV dans Qt
#include <opencv2/core/types.hpp>

// Pour la conversion entre QImage et cv::Mat
#include <opencv2/imgcodecs.hpp>

//////////// AI :

// Inclure les en-têtes nécessaires pour QtCharts
#include <QtCharts>

// Déclaration anticipée de la classe Ui::MainWindow
namespace Ui {
class MainWindow;
}

// Inclure les en-têtes des classes Produit et Employe
#include "produit.h"
#include "employe.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void onLoginClicked();
    void on_btnCatalogue_clicked();

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

    // CRUD Employé
    void on_btnAjouterEmploye_clicked();
    void on_btnModifierEmploye_clicked();
    void on_btnSupprimerEmploye_clicked();
    void on_tableWidgetEmployes_itemClicked(QTableWidgetItem *item);
    void afficherEmployes();
    void viderChampsEmploye();
    void afficherFournisseursDisponibles();
    void peuplerComboFournisseurs();
    void on_rafraichirFournisseurs_clicked();
    bool verifierLoginEmploye(const QString& nomEmploye, const QString& idEmploye);
    void rechercherEtAfficherDansTableau(const QString& critere);
    void afficherTousProduits() ;

    // Tri
    void on_exportPDF_clicked();

    // Recherche
    void on_pushButton_5_clicked();
    void rechercherProduits(const QString& critere);
    void rechercherProduitsPartielle(const QString& critere);

    // Upload image
    void on_pushButton_22_clicked();
    void verifierStockFaible();
    void afficherNotificationStock();
    void onNotificationClicked();

    // Stats
public slots:
    void afficherStatistiques();
    void on_pushButton_18_clicked();
    void on_comboBox_2_currentIndexChanged(int index); // tri

    // Mot de passe oublié
    void onMotDePasseOublieClicked();
    void onEmailEnvoye(QNetworkReply *reply);
    void envoyerCodeVerification(const QString& email);

    void onCodeVerificationEnvoye(QNetworkReply *reply);


private:
    QString genererCodeVerification();
    bool verifierCode(const QString& codeSaisi);
    void creerFenetreVerification(const QString& email);
     void finaliserConnexion(const QString& email);
    // Variables pour la vérification
    QString codeVerification;
    QString emailEnAttente;
    QTimer *timerCodeExpiration;
    QDialog *dialogVerification;
    void afficherCatalogueLunettes();
    bool verifierEtAjouterProduitAvecImage();
    bool genererPDFStatistiques(const QString &fileName, const QVector<QStringList> &donnees);
    void creerGraphiqueStatistiques(QVBoxLayout *layout);
    bool genererPDFListeProduits(const QString& cheminFichier);
    void appliquerTriAvecOrderBy(const QString& orderBy);

    // === MÉTHODES DE DÉTECTION D'IMAGE INTELLIGENTE ===
    bool verifierImageLunette(const QByteArray &imageData);
    bool verifierImageLunetteIntelligente(const QByteArray &imageData);
    cv::Mat preprocessImage(const cv::Mat &image);
    double detecterMontureLunettes(const cv::Mat &image);
    double detecterBranchesLunettes(const cv::Mat &image);
    double analyserTextureVerres(const cv::Mat &image);
    bool verifierPerspectiveLunettes(const cv::Mat &image);
    double evaluerCouleurLunettes(const cv::Mat &image);
    bool verifierRefletsVerres(const cv::Mat &image);
    double calculerScoreConfiance(const cv::Mat &image);
    cv::Mat calculerLBP(const cv::Mat &src);
    QString genererRapportAvance(double scoreFinal,
                                 const QVector<double> &scores,
                                 const QVector<QString> &caracteristiques,
                                 const QVector<QString> &problemes);
    void afficherResultatDetection(bool estLunette, const QString &message = "");
    void sauvegarderImageDansBDD(const QString &reference, const QByteArray &imageData);

    // Méthodes d'analyse structurelle
    double analyserStructureLunettes(const QImage &image);
    QVector<QRect> detecterMassesPrincipales(const QImage &image);
    double calculerDensiteCellule(const QImage &image, int startX, int startY, int size);
    bool verifierDispositionHorizontale(const QVector<QRect> &masses);
    double calculerSymetrie(const QImage &image);
    void deconnecterUtilisateur() ;

    // Méthodes de détection de formes
    double detecterFormesSpecifiques(const QImage &image);
    QVector<QPointF> detecterCercles(const QImage &image);
    bool estCentreCercleProbable(const QImage &image, int cx, int cy);
    bool estPointContour(const QImage &image, int x, int y);

    // Méthodes d'analyse contextuelle
    double verifierContexteLunettes(const QImage &image);
    double calculerComplexite(const QImage &image);
    bool aDistributionEquilibree(const QImage &image);
    double calculerContraste(const QImage &image);
    double calculerLuminositeMoyenne(const QImage &image);

    // Génération de rapport
    QString genererRapportDetection(double scoreTotal, double scoreStructure,
                                    double scoreFormes, double scoreContexte,
                                    const QVector<QString> &caracteristiques,
                                    const QVector<QString> &problemes);
    QVector<QRect> regrouperMasses(const QVector<QVector<double>> &densityGrid, int cellSize) ;
    void ameliorerContours(cv::Mat& image);

    // === MÉTHODES MOT DE PASSE OUBLIÉ ===
    bool verifierMailExiste(const QString& mail);
    QString recupererMotDePasse(const QString& mail);
    void envoyerEmailTwilio(const QString& destinataire, const QString& motDePasse);
    void creerFenetreMotDePasseOublie();

    Ui::MainWindow *ui;
    Produit produitTemp;
    Employe employeTemp;

    // Variables pour la détection d'image
    QByteArray currentImageData;
    QString currentProductReference;

    // notification poupap :
    QTimer *timerVerificationStock;
    QSystemTrayIcon *trayIcon;
    bool notificationAlreadyShown;

    // Méthodes pour la gestion du stock
    QVector<QStringList> getProduitsStockFaible();
    void creerFenetreNotification(const QVector<QStringList>& produitsFaibleStock);
    void afficherNotificationSysteme(const QVector<QStringList>& produitsFaibleStock);
    bool utilisateurConnecte;

    // Pour l'envoi d'emails
    QNetworkAccessManager *networkManager;
    QString sendGridApiKey;
};

#endif // MAINWINDOW_H
