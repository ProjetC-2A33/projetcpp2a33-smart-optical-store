#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection
{
public:
    Connection();
    static bool createconnect();
};

#endif // CONNECTION_H
