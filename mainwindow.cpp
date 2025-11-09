#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , prochainId(1)
{
    ui->setupUi(this);
    
    // Configuration du tableau
    ui->tableWidget->setColumnCount(8);
    QStringList headers = {"ID", "Prénom", "Date d'embauche", "Poste", 
                          "Années d'expérience", "Salaire", "Date de naissance", "État civil"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    
    // Connexion des boutons
    connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::onAjouterClicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onModifierClicked);
    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::onSupprimerClicked);
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &MainWindow::onTableItemClicked);
    
    // Initialisation (mode mémoire)
    afficherEmployes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAjouterClicked()
{
    Employe nouvEmploye = lireFormulaire();

    //  Vérification des champs obligatoires
    if (nouvEmploye.prenom.isEmpty() || 
        nouvEmploye.poste.isEmpty() || 
        !nouvEmploye.dateEmbauche.isValid() || 
        !nouvEmploye.dateNaissance.isValid()) 
    {
        QMessageBox::warning(this, "Erreur",
            "Les champs obligatoires (Prénom, Poste, Dates) sont vides !");
        return;
    }

    //  Vérification du prénom (uniquement lettres et espaces)
    QRegularExpression regexNom("^[A-Za-zÀ-ÿ\\s'-]+$");
    if (!regexNom.match(nouvEmploye.prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur",
            "Le prénom ne doit contenir que des lettres !");
        return;
    }

    //  Vérification du poste (minimum 3 caractères)
    if (nouvEmploye.poste.length() < 3) {
        QMessageBox::warning(this, "Erreur",
            "Le poste doit contenir au moins 3 caractères !");
        return;
    }

    //  Vérification de la date d'embauche (pas dans le futur)
    if (nouvEmploye.dateEmbauche > QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur",
            "La date d'embauche ne peut pas être dans le futur !");
        return;
    }

    //  Vérification de la date de naissance (âge minimum 18 ans)
    int age = nouvEmploye.dateNaissance.daysTo(QDate::currentDate()) / 365;
    if (age < 18) {
        QMessageBox::warning(this, "Erreur",
            "L'employé doit avoir au moins 18 ans !");
        return;
    }

    //  Vérification des années d'expérience (pas négatif)
    if (nouvEmploye.anneesExperience < 0) {
        QMessageBox::warning(this, "Erreur",
            "Les années d'expérience doivent être positives !");
        return;
    }

    // Vérification du salaire (supérieur à 0)
    if (nouvEmploye.salaire <= 0) {
        QMessageBox::warning(this, "Erreur",
            "Le salaire doit être supérieur à 0 !");
        return;
    }

    //  Vérification de l'état civil
    if (nouvEmploye.etatCivil.isEmpty()) {
        QMessageBox::warning(this, "Erreur",
            "Veuillez sélectionner un état civil !");
        return;
    }

    //  Vérification de doublon sur le prénom et date de naissance
    for (const Employe &emp : listeEmployes) {
        if (emp.prenom == nouvEmploye.prenom &&
            emp.dateNaissance == nouvEmploye.dateNaissance) 
        {
            QMessageBox::warning(this, "Erreur",
                "Un employé avec le même prénom et la même date de naissance existe déjà !");
            return;
        }
    }

    //  Si tout est bon → ajouter l'employé (mémoire)
    if (nouvEmploye.id <= 0) {
        nouvEmploye.id = prochainId++;
    }
    listeEmployes.append(nouvEmploye);
    afficherEmployes();
    viderFormulaire();

    QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
}

void MainWindow::onModifierClicked()
{
    // Récupérer l'ID depuis le formulaire
    bool ok;
    int id = ui->lineEdit->text().toInt(&ok);
    
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un employé à modifier.");
        return;
    }
    
    // Trouver l'index de l'employé
    int index = trouverIndexEmploye(id);
    
    if (index == -1) {
        QMessageBox::warning(this, "Erreur", "Employé non trouvé.");
        return;
    }
    
    // Validation
    Employe employeModifie = lireFormulaire();
    
    if (employeModifie.prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un prénom.");
        return;
    }
    
    if (employeModifie.poste.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un poste.");
        return;
    }
    
    // Mettre à jour l'ID
    employeModifie.id = id;
    
    // Modifier l'employé (mémoire)
    listeEmployes[index] = employeModifie;
    
    // Rafraîchir l'affichage
    afficherEmployes();
    
    // Vider le formulaire
    viderFormulaire();
    
    QMessageBox::information(this, "Succès", "Employé modifié avec succès!");
}

void MainWindow::onSupprimerClicked()
{
    // Récupérer l'ID depuis le formulaire
    bool ok;
    int id = ui->lineEdit->text().toInt(&ok);
    
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un employé à supprimer.");
        return;
    }
    
    // Demander confirmation
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmation", 
        "Êtes-vous sûr de vouloir supprimer cet employé ?",
        QMessageBox::Yes | QMessageBox::No
    );
    
    if (reply != QMessageBox::Yes) {
        return;
    }
    
    // Trouver et supprimer l'employé
    int index = trouverIndexEmploye(id);
    
    if (index == -1) {
        QMessageBox::warning(this, "Erreur", "Employé non trouvé.");
        return;
    }
    
    // Supprimer (mémoire)
    listeEmployes.removeAt(index);
    
    // Rafraîchir l'affichage
    afficherEmployes();
    
    // Vider le formulaire
    viderFormulaire();
    
    QMessageBox::information(this, "Succès", "Employé supprimé avec succès!");
}

void MainWindow::onTableItemClicked(int row, int column)
{
    Q_UNUSED(column);
    
    if (row < 0 || row >= ui->tableWidget->rowCount()) {
        return;
    }
    
    // Récupérer l'ID de la ligne sélectionnée
    QTableWidgetItem* itemId = ui->tableWidget->item(row, 0);
    if (!itemId) {
        return;
    }
    
    bool ok;
    int id = itemId->text().toInt(&ok);
    if (!ok) {
        return;
    }
    
    // Trouver l'employé
    int index = trouverIndexEmploye(id);
    if (index == -1) {
        return;
    }
    
    // Remplir le formulaire
    remplirFormulaire(listeEmployes[index]);
}

void MainWindow::afficherEmployes()
{
    // Vider le tableau
    ui->tableWidget->setRowCount(0);
    
    // Ajouter chaque employé
    for (const Employe& emp : listeEmployes) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(emp.id)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(emp.prenom));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(emp.dateEmbauche.toString("dd/MM/yyyy")));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(emp.poste));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(emp.anneesExperience)));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(emp.salaire, 'f', 2)));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(emp.dateNaissance.toString("dd/MM/yyyy")));
        ui->tableWidget->setItem(row, 7, new QTableWidgetItem(emp.etatCivil));
    }
}

// Mode mémoire: pas de fonctions base de données

void MainWindow::viderFormulaire()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->spinBox_2->setValue(0);
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
}

void MainWindow::remplirFormulaire(const Employe& employe)
{
    ui->lineEdit->setText(QString::number(employe.id));
    ui->lineEdit_2->setText(employe.prenom);
    ui->dateEdit->setDate(employe.dateEmbauche);
    ui->lineEdit_3->setText(employe.poste);
    ui->spinBox_2->setValue(employe.anneesExperience);
    ui->lineEdit_4->setText(QString::number(employe.salaire));
    ui->dateEdit_2->setDate(employe.dateNaissance);
    
    // État civil
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
    
    if (employe.etatCivil == "Célibataire") {
        ui->radioButton->setChecked(true);
    } else if (employe.etatCivil == "Marié(e)") {
        ui->radioButton_2->setChecked(true);
    } else if (employe.etatCivil == "Divorcé(e)") {
        ui->radioButton_3->setChecked(true);
    }
}

Employe MainWindow::lireFormulaire() const
{
    Employe emp;
    
    // ID (peut être vide pour un nouvel employé)
    emp.id = ui->lineEdit->text().toInt();
    
    // Prénom
    emp.prenom = ui->lineEdit_2->text().trimmed();
    
    // Date d'embauche
    emp.dateEmbauche = ui->dateEdit->date();
    
    // Poste
    emp.poste = ui->lineEdit_3->text().trimmed();
    
    // Années d'expérience
    emp.anneesExperience = ui->spinBox_2->value();
    
    // Salaire
    bool ok;
    emp.salaire = ui->lineEdit_4->text().toDouble(&ok);
    if (!ok) {
        emp.salaire = 0.0;
    }
    
    // Date de naissance
    emp.dateNaissance = ui->dateEdit_2->date();
    
    // État civil
    if (ui->radioButton->isChecked()) {
        emp.etatCivil = "Célibataire";
    } else if (ui->radioButton_2->isChecked()) {
        emp.etatCivil = "Marié(e)";
    } else if (ui->radioButton_3->isChecked()) {
        emp.etatCivil = "Divorcé(e)";
    } else {
        emp.etatCivil = "";
    }
    
    return emp;
}

int MainWindow::trouverIndexEmploye(int id) const
{
    for (int i = 0; i < listeEmployes.size(); ++i) {
        if (listeEmployes[i].id == id) {
            return i;
        }
    }
    return -1;
}
