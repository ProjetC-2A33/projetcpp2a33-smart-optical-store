#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class Connection {
public:
    // Méthode statique publique
    static Connection& createInstance();
    bool createConnection() ;

private:
    QSqlDatabase db;                    // Attribut : base de données

    // Constructeur privé pour empêcher la création d'instances multiples
    Connection();

    // Destructeur privé pour empêcher toute destruction non contrôlée
    ~Connection();

    // Interdiction de la copie
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;
};

#endif // CONNECTION_H
