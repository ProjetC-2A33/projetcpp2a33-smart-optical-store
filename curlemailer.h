#ifndef CURLEMAILER_H
#define CURLEMAILER_H

#include <QObject>
#include <QString>

class CurlEmailer : public QObject
{
    Q_OBJECT
public:
    explicit CurlEmailer(QObject *parent = nullptr);
    
    // Envoyer un email en utilisant curl en ligne de commande
    bool sendEmail(const QString& to,
                   const QString& subject,
                   const QString& body,
                   QString *errorMessage = nullptr);
};

#endif // CURLEMAILER_H
