#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
    bool creerTableUtilisateur();
    bool creerTableEmploye();
    bool creerColonneMotDePasseEmploye();
    bool creerColonneEmailEmploye();

private:
    bool tableUtilisateurExiste();
    bool tableEmployeExiste();
};

#endif // CONNECTION_H
