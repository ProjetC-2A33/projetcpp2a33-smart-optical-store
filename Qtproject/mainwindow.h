#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlQueryModel *sortBySalaireAsc();
    QSqlQueryModel *sortBySalaireDesc();

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *networkManager;
    QString infobipApiKey = "159d83b9b9b5d72146befb991fe14eba-c3993467-3f30-4564-b7c7-5fdbd4edd91a";
    QString infobipBaseUrl = "https://nmvl3e.api.infobip.com";
private slots:
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
    void on_pushButton_clicked();
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
};

#endif // MAINWINDOW_H
