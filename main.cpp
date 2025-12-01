#include "mainwindow.h"
#include "logindialog.h"

#include <QApplication>
#include <QMessageBox>
#include <QEventLoop>

#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    if (!c.createconnect()) {
        QMessageBox::critical(nullptr, QObject::tr("Base de données"),
                              QObject::tr("Échec de la connexion à la base.\n"
                                          "L'application va se fermer."));
        return 0;
    }

    // Boucle pour gérer les connexions/déconnexions
    while (true) {
        LoginDialog login;
        if (login.exec() != QDialog::Accepted) {
            // Si l'utilisateur annule le login, quitter l'application
            return 0;
        }

        // Créer et afficher la fenêtre principale
        MainWindow w;
        w.show();
        
        // Utiliser un event loop local pour gérer la fenêtre
        // Quand l'utilisateur se déconnecte, la fenêtre se ferme et on revient ici
        QEventLoop loop;
        QObject::connect(&w, &QMainWindow::destroyed, &loop, &QEventLoop::quit);
        
        // Exécuter l'event loop jusqu'à ce que la fenêtre soit fermée
        loop.exec();
        
        // Si on arrive ici, la fenêtre a été fermée (déconnexion ou fermeture normale)
        // On continue la boucle pour afficher à nouveau le login
        // Si l'utilisateur ferme l'application normalement, on sortira de la boucle
    }

    return 0;
}
