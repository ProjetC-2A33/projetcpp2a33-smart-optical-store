#ifndef mainwindow_H
#define mainwindow_H

#include <QMainWindow>
#include <QTimer>
#include <QDialog>
#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "client.h"

class MainWindow;
namespace Ui {
class mainwindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
      ~MainWindow();
    QSqlQueryModel *sortBySalaireAsc();
    QSqlQueryModel *sortBySalaireDesc();

Ui::mainwindow *ui;
private slots:
    void on_pb_supprimer_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_ajouter_clicked();

    void handleMessageBoxResult(int result);

    void refreshTable();

    void on_tab_clients_clicked(const QModelIndex &index);
void on_sortAscButton_clicked();
void on_sortDescButton_clicked();
void refreshTable(QSqlQueryModel *model);
void on_refrech_pb_clicked();

void on_Imprimer_clicked();

void on_pb_pdf_clicked();

void on_pb_word_clicked();

void on_statgenre_clicked();
void Stat();

void on_lineEdit_textChanged(const QString &arg1);
void on_pushButton_clicked();

void StatNiv();
void on_statniv_clicked();

private:

    QString role_e;
};
#endif // mainwindow_H
