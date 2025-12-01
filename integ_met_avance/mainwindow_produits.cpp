#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

// Fonctions de gestion des produits (CRUD)
void MainWindow::on_pushButton_ajouter_clicked()
{
    // Récupération des valeurs des champs
    QString reference = ui->lineEdit_reference->text();
    QString nom = ui->lineEdit_nom->text();
    int quantite = ui->spinBox_quantite->value();
    float prix = ui->doubleSpinBox_prix->value();
    QString fournisseur = ui->lineEdit_fournisseur->text();
    QString type = ui->comboBox_type->currentText();

    // Vérification des champs obligatoires
    if(reference.isEmpty() || nom.isEmpty() || fournisseur.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires");
        return;
    }

    // Préparation de la requête SQL
    QSqlQuery query;
    query.prepare("INSERT INTO PRODUITS (REFERENCE, NOM, QUANTITE, PRIX, FOURNISSEUR, TYPE) "
                  "VALUES (:reference, :nom, :quantite, :prix, :fournisseur, :type)");
    
    // Liaison des valeurs
    query.bindValue(":reference", reference);
    query.bindValue(":nom", nom);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    query.bindValue(":fournisseur", fournisseur);
    query.bindValue(":type", type);

    // Exécution de la requête
    if(!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du produit : " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Succès", "Produit ajouté avec succès");
    afficherTousProduits();
    viderChamps();
}

void MainWindow::on_pushButton_modifier_clicked()
{
    // Vérifier si une ligne est sélectionnée
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner un produit à modifier");
        return;
    }

    // Récupérer l'ID du produit sélectionné
    int row = selectedIndexes.first().row();
    int id = model->data(model->index(row, 0)).toInt();

    // Récupération des nouvelles valeurs
    QString reference = ui->lineEdit_reference->text();
    QString nom = ui->lineEdit_nom->text();
    int quantite = ui->spinBox_quantite->value();
    float prix = ui->doubleSpinBox_prix->value();
    QString fournisseur = ui->lineEdit_fournisseur->text();
    QString type = ui->comboBox_type->currentText();

    // Vérification des champs obligatoires
    if(reference.isEmpty() || nom.isEmpty() || fournisseur.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires");
        return;
    }

    // Mise à jour dans la base de données
    QSqlQuery query;
    query.prepare("UPDATE PRODUITS SET REFERENCE = :reference, NOM = :nom, "
                  "QUANTITE = :quantite, PRIX = :prix, FOURNISSEUR = :fournisseur, "
                  "TYPE = :type WHERE ID = :id");
    
    query.bindValue(":id", id);
    query.bindValue(":reference", reference);
    query.bindValue(":nom", nom);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    query.bindValue(":fournisseur", fournisseur);
    query.bindValue(":type", type);

    if(!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification : " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Succès", "Produit modifié avec succès");
    afficherTousProduits();
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    // Vérifier si une ligne est sélectionnée
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner un produit à supprimer");
        return;
    }

    // Demander confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", 
                                 "Êtes-vous sûr de vouloir supprimer ce produit ?",
                                 QMessageBox::Yes | QMessageBox::No);
    
    if(reply == QMessageBox::No) {
        return;
    }

    // Récupérer l'ID du produit sélectionné
    int row = selectedIndexes.first().row();
    int id = model->data(model->index(row, 0)).toInt();

    // Suppression dans la base de données
    QSqlQuery query;
    query.prepare("DELETE FROM PRODUITS WHERE ID = :id");
    query.bindValue(":id", id);

    if(!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression : " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Succès", "Produit supprimé avec succès");
    afficherTousProduits();
    viderChamps();
}

void MainWindow::afficherTousProduits()
{
    model->setQuery("SELECT * FROM PRODUITS");
    if(model->lastError().isValid()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement des produits : " + model->lastError().text());
        return;
    }
    
    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Référence"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, tr("Fournisseur"));
    model->setHeaderData(6, Qt::Horizontal, tr("Type"));
    
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    // Récupérer les données de la ligne sélectionnée
    int row = index.row();
    
    // Mettre à jour les champs avec les données du produit sélectionné
    ui->lineEdit_reference->setText(model->data(model->index(row, 1)).toString());
    ui->lineEdit_nom->setText(model->data(model->index(row, 2)).toString());
    ui->spinBox_quantite->setValue(model->data(model->index(row, 3)).toInt());
    ui->doubleSpinBox_prix->setValue(model->data(model->index(row, 4)).toDouble());
    ui->lineEdit_fournisseur->setText(model->data(model->index(row, 5)).toString());
    
    // Sélectionner le bon type dans la comboBox
    int typeIndex = ui->comboBox_type->findText(model->data(model->index(row, 6)).toString());
    if(typeIndex >= 0) {
        ui->comboBox_type->setCurrentIndex(typeIndex);
    }
}

void MainWindow::viderChamps()
{
    ui->lineEdit_reference->clear();
    ui->lineEdit_nom->clear();
    ui->spinBox_quantite->setValue(0);
    ui->doubleSpinBox_prix->setValue(0.0);
    ui->lineEdit_fournisseur->clear();
    ui->comboBox_type->setCurrentIndex(0);
}
