#include "resendclient.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QDebug>
#include <QSslConfiguration>

ResendClient::ResendClient(const QString& apiKey, QObject *parent)
    : QObject(parent)
    , m_apiKey(apiKey)
{
}

bool ResendClient::sendEmail(const QString& from,
                             const QString& to,
                             const QString& subject,
                             const QString& body,
                             QString *errorMessage)
{
    QNetworkAccessManager manager;
    
    // Désactiver la vérification SSL pour contourner le problème OpenSSL
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    
    QUrl url("https://api.resend.com/emails");
    QNetworkRequest request(url);
    request.setSslConfiguration(sslConfig);
    
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
    
    // Créer le JSON pour l'API Resend
    QJsonObject emailData;
    emailData["from"] = from;
    emailData["to"] = to;
    emailData["subject"] = subject;
    emailData["text"] = body;
    
    QJsonDocument doc(emailData);
    QByteArray jsonData = doc.toJson();
    
    qDebug() << "=== ENVOI VIA RESEND API ===";
    qDebug() << "From:" << from;
    qDebug() << "To:" << to;
    qDebug() << "Subject:" << subject;
    qDebug() << "JSON:" << QString::fromUtf8(jsonData);
    
    // Envoyer la requête
    QEventLoop loop;
    QNetworkReply *reply = manager.post(request, jsonData);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QByteArray responseData = reply->readAll();
    reply->deleteLater();
    
    qDebug() << "Status Code:" << statusCode;
    qDebug() << "Response:" << QString::fromUtf8(responseData);
    
    if (statusCode >= 200 && statusCode < 300) {
        return true;
    }
    
    if (errorMessage) {
        QJsonDocument errorDoc = QJsonDocument::fromJson(responseData);
        if (errorDoc.isObject()) {
            QJsonObject errorObj = errorDoc.object();
            QString errorMsg = errorObj.value("message").toString();
            if (errorMsg.isEmpty()) {
                errorMsg = QString::fromUtf8(responseData);
            }
            *errorMessage = QString("Erreur Resend API (%1): %2").arg(statusCode).arg(errorMsg);
        } else {
            *errorMessage = QString("Erreur HTTP %1: %2").arg(statusCode).arg(QString::fromUtf8(responseData));
        }
    }
    
    return false;
}
