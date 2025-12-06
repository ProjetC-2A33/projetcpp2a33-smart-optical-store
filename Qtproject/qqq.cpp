#include "qqq.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFileDialog>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cin_c->setValidator(new QIntValidator(0, 99999999, this));
    refreshTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString cin = ui->cin_c->text().trimmed();
    QString nom = ui->nom_c->text().trimmed();
    QString prenom = ui->prenom_c->text().trimmed();
    QString adresse = ui->adresse_c->text().trimmed();
    QString tel = ui->telephone_c->text().trimmed();
    QString email = ui->email_c->text().trimmed();
    QString sexe = ui->genre_c->currentText();
    QString historique = "";
    bool fidele = (ui->niv_c->currentText() == "Oui");
    QString nomEmpl = "";

    if (cin.isEmpty() || nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() ||
        tel.isEmpty() || email.isEmpty() || sexe.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (cin.length() != 8 || !cin.toInt()) {
        QMessageBox::warning(this, "CIN invalide", "Le CIN doit contenir exactement 8 chiffres.");
        return;
    }

    // Create client instance for validation
    Clients tempClient;
    if (Clients::cinExiste(cin)) {
        QMessageBox::warning(this, "CIN existant", "Ce CIN existe déjà dans la base de données.");
        return;
    }

    if (Clients::emailExiste(email)) {
        QMessageBox::warning(this, "Email existant", "Cet email existe déjà dans la base de données.");
        return;
    }

    Clients client(cin, nom, prenom, adresse, tel, email, sexe, historique, fidele, nomEmpl);
    bool test = client.ajouter();

    if (test) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
        refreshTable();
        on_refrech_pb_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}

void MainWindow::on_pb_supprimer_clicked()
{
    QString cin = ui->cin_c->text().trimmed();

    if (cin.isEmpty()) {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un client à supprimer.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation de suppression",
                                  "Êtes-vous sûr de vouloir supprimer le client CIN: " + cin + " ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Clients::supprimer(cin)) {
            QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
            refreshTable();
            on_refrech_pb_clicked();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression du client.");
        }
    }
}

void MainWindow::on_pb_modifier_2_clicked()
{
    QString cin = ui->cin_c->text().trimmed();
    QString nom = ui->nom_c->text().trimmed();
    QString prenom = ui->prenom_c->text().trimmed();
    QString adresse = ui->adresse_c->text().trimmed();
    QString tel = ui->telephone_c->text().trimmed();
    QString email = ui->email_c->text().trimmed();
    QString sexe = ui->genre_c->currentText();
    QString historique = "";
    bool fidele = (ui->niv_c->currentText() == "Oui");
    QString nomEmpl = "";

    if (cin.isEmpty()) {
        QMessageBox::warning(this, "Modification", "Veuillez sélectionner un client à modifier.");
        return;
    }

    if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() ||
        tel.isEmpty() || email.isEmpty() || sexe.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (Clients::emailExiste(email, cin)) {
        QMessageBox::warning(this, "Email existant", "Cet email est déjà utilisé par un autre client.");
        return;
    }

    Clients client(cin, nom, prenom, adresse, tel, email, sexe, historique, fidele, nomEmpl);

    if (client.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès !");
        refreshTable();
        on_refrech_pb_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client.");
    }
}

void MainWindow::on_tab_clients_clicked(const QModelIndex &index)
{
    int row = index.row();
    QAbstractItemModel *model = ui->tab_clients->model();

    ui->cin_c->setText(model->data(model->index(row, 0)).toString());
    ui->nom_c->setText(model->data(model->index(row, 1)).toString());
    ui->prenom_c->setText(model->data(model->index(row, 2)).toString());
    ui->adresse_c->setText(model->data(model->index(row, 3)).toString());
    ui->telephone_c->setText(model->data(model->index(row, 4)).toString());
    ui->email_c->setText(model->data(model->index(row, 5)).toString());
    ui->genre_c->setCurrentText(model->data(model->index(row, 6)).toString());

    QString statutFidelite = model->data(model->index(row, 8)).toString();
    ui->niv_c->setCurrentText(statutFidelite == "1" ? "Oui" : "Non");
}

void MainWindow::refreshTable()
{
    Clients client;  // Create instance to call non-static method
    QSqlQueryModel *model = client.afficher();  // Call on instance

    if (model) {
        QStandardItemModel *standardModel = new QStandardItemModel(model->rowCount(), model->columnCount(), this);

        for (int col = 0; col < model->columnCount(); ++col) {
            standardModel->setHorizontalHeaderItem(col, new QStandardItem(model->headerData(col, Qt::Horizontal).toString()));
        }

        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QModelIndex index = model->index(row, col);
                QString data = model->data(index).toString();

                if (col == 8) {
                    data = (data == "1") ? "Oui" : "Non";
                }

                QStandardItem *item = new QStandardItem(data);
                standardModel->setItem(row, col, item);
            }
        }

        ui->tab_clients->setModel(standardModel);
        delete model;
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les données des clients.");
    }
}

void MainWindow::on_refrech_pb_clicked()
{
    ui->cin_c->clear();
    ui->nom_c->clear();
    ui->prenom_c->clear();
    ui->adresse_c->clear();
    ui->telephone_c->clear();
    ui->email_c->clear();
    ui->genre_c->setCurrentIndex(0);
    ui->niv_c->setCurrentIndex(0);
    ui->tab_clients->clearSelection();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString critere = arg1.trimmed();

    if (critere.isEmpty()) {
        refreshTable();
        return;
    }

    Clients client;  // Create instance
    QSqlQueryModel *model = client.rechercher(critere);  // Call on instance

    if (model) {
        QStandardItemModel *standardModel = new QStandardItemModel(model->rowCount(), model->columnCount(), this);

        for (int col = 0; col < model->columnCount(); ++col) {
            standardModel->setHorizontalHeaderItem(col, new QStandardItem(model->headerData(col, Qt::Horizontal).toString()));
        }

        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QModelIndex index = model->index(row, col);
                QString data = model->data(index).toString();

                if (col == 8) {
                    data = (data == "1") ? "Oui" : "Non";
                }

                QStandardItem *item = new QStandardItem(data);
                standardModel->setItem(row, col, item);
            }
        }

        ui->tab_clients->setModel(standardModel);
        delete model;
    }
}

void MainWindow::on_sortAscButton_clicked()
{
    Clients client;  // Create instance
    QSqlQueryModel *model = client.trier("NOM", "ASC");  // Call on instance
    if (model) {
        refreshTable(model);
    }
}

void MainWindow::on_sortDescButton_clicked()
{
    Clients client;  // Create instance
    QSqlQueryModel *model = client.trier("NOM", "DESC");  // Call on instance
    if (model) {
        refreshTable(model);
    }
}

void MainWindow::refreshTable(QSqlQueryModel *model)
{
    if (!model) return;

    QStandardItemModel *standardModel = new QStandardItemModel(model->rowCount(), model->columnCount(), this);

    for (int col = 0; col < model->columnCount(); ++col) {
        standardModel->setHorizontalHeaderItem(col, new QStandardItem(model->headerData(col, Qt::Horizontal).toString()));
    }

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            QString data = model->data(index).toString();

            if (col == 8) {
                data = (data == "1") ? "Oui" : "Non";
            }

            QStandardItem *item = new QStandardItem(data);
            standardModel->setItem(row, col, item);
        }
    }

    ui->tab_clients->setModel(standardModel);
    delete model;
}

void MainWindow::on_pb_pdf_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    if (!filePath.isEmpty()) {
        Clients client;  // Create instance
        if (client.exportPDF(filePath)) {  // Call on instance
            QMessageBox::information(this, "Succès", "Export PDF réussi !");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de l'export PDF !");
        }
    }
}

void MainWindow::handleMessageBoxResult(int result)
{
    if (result == QMessageBox::Cancel) {
    }
}

// Keep your existing methods for statistics and other features
void MainWindow::on_Imprimer_clicked() { /* your existing code */ }
void MainWindow::on_pb_word_clicked() { /* your existing code */ }
void MainWindow::Stat() { /* your existing code */ }
void MainWindow::on_statgenre_clicked() { /* your existing code */ }
void MainWindow::on_pushButton_clicked() { /* your existing code */ }
void MainWindow::StatNiv() { /* your existing code */ }
void MainWindow::on_statniv_clicked() { /* your existing code */ }

QSqlQueryModel *MainWindow::sortBySalaireAsc() { return nullptr; }
QSqlQueryModel *MainWindow::sortBySalaireDesc() { return nullptr; }
