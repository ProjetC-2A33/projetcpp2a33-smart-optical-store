#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <QObject>
#include <QSslSocket>

class SmtpClient : public QObject
{
    Q_OBJECT
public:
    explicit SmtpClient(const QString& host,
                        quint16 port,
                        const QString& username,
                        const QString& password,
                        QObject *parent = nullptr);

    bool sendMail(const QString& from,
                  const QStringList& to,
                  const QString& subject,
                  const QString& body,
                  QString *errorMessage = nullptr);

private:
    bool sendCommand(QSslSocket& socket,
                     const QByteArray& command,
                     int expectedCode,
                     QString *errorMessage);
    bool readResponse(QSslSocket& socket,
                      int expectedCode,
                      QString *errorMessage);

    QString m_host;
    quint16 m_port;
    QString m_username;
    QString m_password;
};

#endif // SMTPCLIENT_H





