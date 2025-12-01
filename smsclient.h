#ifndef SMSCLIENT_H
#define SMSCLIENT_H

#include <QObject>

class SmsClient : public QObject
{
    Q_OBJECT
public:
    explicit SmsClient(const QString& apiKey,
                      const QString& apiSecret,
                      const QString& fromNumber,
                      QObject *parent = nullptr);

    bool sendSms(const QString& to,
                 const QString& message,
                 QString *errorMessage = nullptr);

private:
    QString m_apiKey;
    QString m_apiSecret;
    QString m_fromNumber;
};

#endif // SMSCLIENT_H



