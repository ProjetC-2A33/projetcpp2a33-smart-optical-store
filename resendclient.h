#ifndef RESENDCLIENT_H
#define RESENDCLIENT_H

#include <QObject>
#include <QString>

class ResendClient : public QObject
{
    Q_OBJECT
public:
    explicit ResendClient(const QString& apiKey, QObject *parent = nullptr);
    
    bool sendEmail(const QString& from,
                   const QString& to,
                   const QString& subject,
                   const QString& body,
                   QString *errorMessage = nullptr);

private:
    QString m_apiKey;
};

#endif // RESENDCLIENT_H
