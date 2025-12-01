#include "smsclient.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QTimer>

SmsClient::SmsClient(const QString& apiKey,
                     const QString& apiSecret,
                     const QString& fromNumber,
                     QObject *parent)
    : QObject(parent)
    , m_apiKey(apiKey)
    , m_apiSecret(apiSecret)
    , m_fromNumber(fromNumber)
{
}

bool SmsClient::sendSms(const QString& to, const QString& message, QString *errorMessage)
{
    // Utilisation de l'API Twilio pour envoyer des SMS
    // Format: https://api.twilio.com/2010-04-01/Accounts/{AccountSid}/Messages.json
    
    QNetworkAccessManager manager;
    QUrl url(QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(m_apiKey));
    
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    
    // Authentification basique avec AccountSid et AuthToken
    QString credentials = QString("%1:%2").arg(m_apiKey, m_apiSecret);
    request.setRawHeader("Authorization", "Basic " + credentials.toUtf8().toBase64());
    
    QUrlQuery postData;
    postData.addQueryItem("From", m_fromNumber);
    postData.addQueryItem("To", to);
    postData.addQueryItem("Body", message);
    
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    timer.setInterval(30000); // 30 secondes timeout
    
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    
    QNetworkReply *reply = manager.post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
    timer.start();
    loop.exec();
    timer.stop();
    
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QByteArray responseData = reply->readAll();
    QNetworkReply::NetworkError networkError = reply->error();
    QString errorString = reply->errorString();
    
    // Debug : afficher la réponse
    qDebug() << "SMS Response Status:" << statusCode;
    qDebug() << "SMS Response Data:" << QString::fromUtf8(responseData);
    qDebug() << "SMS Network Error:" << networkError << errorString;
    
    reply->deleteLater();
    
    if (networkError != QNetworkReply::NoError) {
        if (errorMessage) {
            *errorMessage = QString("Erreur réseau : %1\nCode d'erreur : %2").arg(errorString).arg(networkError);
        }
        return false;
    }
    
    // Vérifier la réponse JSON
    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    if (doc.isObject()) {
        QJsonObject obj = doc.object();
        
        // Vérifier les erreurs Twilio
        if (obj.contains("code") || obj.contains("message") || obj.contains("error_code")) {
            if (errorMessage) {
                QString errorCode = obj.value("code").toString();
                QString errorMsg = obj.value("message").toString();
                int errorCodeNum = obj.value("error_code").toInt();
                
                QString fullError;
                if (!errorCode.isEmpty()) {
                    fullError = QString("Code d'erreur : %1\n").arg(errorCode);
                }
                if (!errorMsg.isEmpty()) {
                    fullError += QString("Message : %1").arg(errorMsg);
                }
                if (errorCodeNum != 0) {
                    fullError += QString("\nCode numérique : %1").arg(errorCodeNum);
                }
                if (fullError.isEmpty()) {
                    fullError = QString::fromUtf8(responseData);
                }
                
                *errorMessage = QString("Erreur API Twilio :\n%1").arg(fullError);
            }
            return false;
        }
        
        // Succès si on a un "sid" dans la réponse
        if (obj.contains("sid")) {
            QString sid = obj.value("sid").toString();
            qDebug() << "SMS envoyé avec succès. SID:" << sid;
            if (errorMessage) {
                *errorMessage = QString("SMS envoyé avec succès. SID: %1").arg(sid);
            }
            return true;
        }
    }
    
    // Si pas de JSON valide, vérifier le code HTTP
    if (statusCode >= 200 && statusCode < 300) {
        qDebug() << "SMS envoyé avec succès (code HTTP:" << statusCode << ")";
        return true;
    }
    
    if (errorMessage) {
        *errorMessage = QString("Erreur HTTP %1 : %2").arg(statusCode).arg(QString::fromUtf8(responseData));
    }
    return false;
}

