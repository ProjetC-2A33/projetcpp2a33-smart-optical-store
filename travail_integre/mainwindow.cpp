#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) // constructeur
{
    ui->setupUi(this);
    ui->comboBox->addItem("Category  A");
    ui->comboBox->addItem("Category  B");
    ui->comboBox->addItem("Produit C");
    QPixmap image(":/stat.png");  // le ":" indique que c'est une ressource
    ui->labelImage->setPixmap(image);
    ui->labelImage->setScaledContents(true);
    
    // Load stat.jpg on all pages
    QPixmap statImage(":/images/stat.jpg");
    ui->labelImage_2->setPixmap(statImage);
    ui->labelImage_2->setScaledContents(true);
    ui->labelImage_3->setPixmap(statImage);
    ui->labelImage_3->setScaledContents(true);
    ui->labelImage_4->setPixmap(statImage);
    ui->labelImage_4->setScaledContents(true);
    
    ui->stackedWidget->setCurrentIndex(0);// page 0 par defaut

    // quand on clique sur le bouton login → appeler la fonction
    connect(ui->btnLogin, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Exemple : ajouter produit dans le tableau
    QString nom = ui->lineEdit->text();
    QString quantite = ui->lineEdit_2->text();

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(nom));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(quantite));
}
void MainWindow::onLoginClicked()
{
    QString user = ui->lineUser->text();
    QString pass = ui->linePass->text();

    if(user == "admin" && pass == "1234") {
        // passage à la page gestion stock (index 1)
        ui->stackedWidget->setCurrentIndex(1);
    }
}



// page 1 :
void MainWindow::on_btnGestionClients_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnGestionEmployes_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_btnGestionSponsors_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_btnGestionFournisseurs_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_btnBack_PageStock_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

// page 2 :

void MainWindow::on_btnGestionStock_PageClients_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_btnGestionEmployes_PageClients_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_btnGestionSponsors_PageClients_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_btnGestionFournisseurs_PageClients_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_btnBack_PageClients_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// page 3 :


void MainWindow::on_btnGestionStock_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnGestionClients_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_btnGestionSponsors_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}
void MainWindow::on_btnGestionFournisseurs_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_btnBack_Page_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
// page 4 :


void MainWindow::on_btnGestionStock_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_btnGestionClients_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btnGestionEmployes_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_btnGestionFournisseurs_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_btnBack_Page_Sponsors_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// page 5 :
void MainWindow::on_btnGestionStock_Page_Fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnGestionClients_Page_Fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_btnGestionEmployes_PageFournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_btnGestionSponsors_Page_Fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_btnBack_Page_Fournisseurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

