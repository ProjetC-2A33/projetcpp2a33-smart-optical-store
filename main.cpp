#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Smart Optic Shop - Gestion Client");
    window.resize(500, 700);

    QVBoxLayout *mainLayout = new QVBoxLayout(&window);

    // --- Formulaire client ---
    QLabel *labelNom = new QLabel("Nom :");
    QLineEdit *editNom = new QLineEdit();
    QLabel *labelPrenom = new QLabel("Prénom :");
    QLineEdit *editPrenom = new QLineEdit();
    QLabel *labelAdresse = new QLabel("Adresse :");
    QLineEdit *editAdresse = new QLineEdit();
    QLabel *labelTelephone = new QLabel("Téléphone :");
    QLineEdit *editTelephone = new QLineEdit();
    QLabel *labelEmail = new QLabel("Email :");
    QLineEdit *editEmail = new QLineEdit();

    mainLayout->addWidget(labelNom);
    mainLayout->addWidget(editNom);
    mainLayout->addWidget(labelPrenom);
    mainLayout->addWidget(editPrenom);
    mainLayout->addWidget(labelAdresse);
    mainLayout->addWidget(editAdresse);
    mainLayout->addWidget(labelTelephone);
    mainLayout->addWidget(editTelephone);
    mainLayout->addWidget(labelEmail);
    mainLayout->addWidget(editEmail);

    // --- Historique d'achat ---
    QLabel *labelHistorique = new QLabel("Historique d’achats :");
    QTextEdit *txtHistorique = new QTextEdit();
    txtHistorique->setPlaceholderText("Exemple : Lunettes, Lentilles, Accessoires...");
    txtHistorique->setFixedHeight(100);

    mainLayout->addWidget(labelHistorique);
    mainLayout->addWidget(txtHistorique);

    // --- Boutons CRUD ---
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    QPushButton *btnAjouter = new QPushButton("➕ Ajouter");
    QPushButton *btnModifier = new QPushButton("✏️ Modifier");
    QPushButton *btnSupprimer = new QPushButton("❌ Supprimer");
    buttonsLayout->addWidget(btnAjouter);
    buttonsLayout->addWidget(btnModifier);
    buttonsLayout->addWidget(btnSupprimer);
    mainLayout->addLayout(buttonsLayout);

    // --- Barre de recherche ---
    QHBoxLayout *searchLayout = new QHBoxLayout();
    QLineEdit *searchBar = new QLineEdit();
    searchBar->setPlaceholderText("Rechercher un client par nom ou ID...");
    QPushButton *btnRechercher = new QPushButton("🔍 Rechercher");
    searchLayout->addWidget(searchBar);
    searchLayout->addWidget(btnRechercher);
    mainLayout->addLayout(searchLayout);

    // --- Boutons métiers avancés et statistiques ---
    QHBoxLayout *metiersLayout = new QHBoxLayout();
    QPushButton *btnFidelite = new QPushButton("⭐ Statut fidélité");
    QPushButton *btnSuivi = new QPushButton("🗓️ Suivi médical / Rendez-vous");
    QPushButton *btnStats = new QPushButton("📊 Statistiques clients");
    metiersLayout->addWidget(btnFidelite);
    metiersLayout->addWidget(btnSuivi);
    metiersLayout->addWidget(btnStats);
    mainLayout->addLayout(metiersLayout);

    // --- Connexions simples ---
    QObject::connect(btnAjouter, &QPushButton::clicked, [&](){
        QMessageBox::information(&window, "Ajout", "Client ajouté : " + editNom->text());
        txtHistorique->clear();
    });

    QObject::connect(btnModifier, &QPushButton::clicked, [&](){
        QMessageBox::information(&window, "Modification", "Client modifié : " + editNom->text());
    });

    QObject::connect(btnSupprimer, &QPushButton::clicked, [&](){
        QMessageBox::information(&window, "Suppression", "Client supprimé : " + editNom->text());
        editNom->clear();
        editPrenom->clear();
        editAdresse->clear();
        editTelephone->clear();
        editEmail->clear();
        txtHistorique->clear();
    });

    QObject::connect(btnRechercher, &QPushButton::clicked, [&](){
        QMessageBox::information(&window, "Recherche", "Recherche du client : " + searchBar->text());
    });

    QObject::connect(btnFidelite, &QPushButton::clicked, [&](){
        QMessageBox::information(&window, "Fidélité", "Affichage du statut fidélité du client : " + editNom->text());
    });

    QObject::connect(btnSuivi, &QPushButton::clicked, [&](){
        QMessageBox::information(&window, "Suivi médical", "Affichage du suivi médical / rendez-vous pour : " + editNom->text());
    });

    QObject::connect(btnStats, &QPushButton::clicked, [&](){
        QMessageBox::information(&window, "Statistiques", "Affichage des statistiques clients");
    });

    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}
