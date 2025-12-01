#include "mainwindow.h"
#include "./ui_mainwindow.h"

// Fonctions de navigation entre les pages
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_btnRetour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnRetour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnRetour_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnRetour_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnRetour_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnRetour_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
