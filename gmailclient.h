#ifndef GMAILCLIENT_H
#define GMAILCLIENT_H

#include <QObject>

class GmailClient : public QObject
{
    Q_OBJECT
public:
    explicit GmailClient(QObject *parent = nullptr);
    
    // Envoyer un email via l'API Gmail avec authentification automatique
    bool sendEmail(const QString& to,
                   const QString& subject,
                   const QString& body,
                   QString *errorMessage = nullptr);
    
    // Configurer l'authentification (demandée une seule fois)
    bool setupAuthentication(QWidget *parent = nullptr);

private:
    QString m_accessToken;
    QString m_refreshToken;
    QString m_userEmail;
    
    bool requestAccessToken(QWidget *parent = nullptr);
    bool refreshAccessToken();
    QString getAuthorizationUrl();
    QString extractTokenFromUrl(const QString& url);
};

#endif // GMAILCLIENT_H



