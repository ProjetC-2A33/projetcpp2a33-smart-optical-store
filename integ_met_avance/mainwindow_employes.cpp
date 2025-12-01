#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

// Fonctions de gestion des employés (CRUD)
void MainWindow::on_pushButton_ajouter_employe_clicked()
{
    // Récupération des valeurs des champs
    QString cin = ui->lineEdit_cin->text();
    QString nom = ui->lineEdit_nom_employe->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString email = ui->lineEdit_email->text();
    QString telephone = ui->lineEdit_telephone->text();
    QString role = ui->comboBox_role->currentText();
    QString departement = ui->lineEdit_departement->text();
    float salaire = ui->doubleSpinBox_salaire->value();
    QDate date_embauche = ui->dateEdit_embauche->date();

    // Vérification des champs obligatoires
    if(cin.isEmpty() || nom.isEmpty() || prenom.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires");
        return;
    }

    // Vérification du format de l'email
    QRegularExpression emailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b", 
                                QRegularExpression::CaseInsensitiveOption);
    if(!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Format incorrect", "Veuillez saisir une adresse email valide");
        return;
    }

    // Préparation de la requête SQL
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (CIN, NOM, PRENOM, EMAIL, TELEPHONE, ROLE, "
                  
