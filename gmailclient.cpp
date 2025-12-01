#include "gmailclient.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QEventLoop>
#include <QTimer>
#include <QMessageBox>
#include <QInputDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QSettings>
#include <QDebug>

// Configuration OAuth2 Gmail
// NOTE: Vous devez créer un projet Google Cloud et obtenir ces informations
const QString CLIENT_ID = "YOUR_CLIENT_ID.apps.googleusercontent.com";
const QString CLIENT_SECRET = "YOUR_CLIENT_SECRET";
const QString REDIRECT_URI = "urn:ietf:wg:oauth:2.0:oob";
const QString SCOPE = "https://www.googleapis.com/auth/gmail.send";

GmailClient::GmailClient(QObject *parent)
    : QObject(parent)
{
    // Charger les tokens sauvegardés
    QSettings settings;
    m_accessToken = settings.value("gmail/accessToken", "").toString();
    m_refreshToken = settings.value("gmail/refreshToken", "").toString();
    m_userEmail = settings.value("gmail/userEmail", "").toString();
}

bool GmailClient::setupAuthentication(QWidget *parent)
{
    // Si on a déjà un refresh token, on peut rafraîchir l'access token
    if (!m_refreshToken.isEmpty()) {
        if (refreshAccessToken()) {
            return true;
        }
    }
    
    // Sinon, demander une nouvelle authentification
    return requestAccessToken(parent);
}

bool GmailClient::requestAccessToken(QWidget *parent)
{
    // Construire l'URL d'autorisation
    QString authUrl = getAuthorizationUrl();
    
    // Ouvrir le navigateur pour l'authentification
    QMessageBox::information(parent, "Authentification Gmail",
                            "Une fenêtre de votre navigateur va s'ouvrir pour vous connecter à Gmail.\n\n"
                            "Après la connexion, copiez le code d'authentification affiché.");
    
    QDesktopServices::openUrl(QUrl(authUrl));
    
    // Demander le code d'authentification
    bool ok = false;
    QString authCode = QInputDialog::getText(
        parent,
        "Code d'authentification Gmail",
        "Après vous être connecté dans le navigateur, copiez le code d'authentification\n"
        "et collez-le ici :",
        QLineEdit::Normal,
        QString(),
        &ok
    ).trimmed();
    
    if (!ok || authCode.isEmpty()) {
        return false;
    }
    
    // Échanger le code contre un access token
    QNetworkAccessManager manager;
    QUrl tokenUrl("https://oauth2.googleapis.com/token");
    QNetworkRequest request(tokenUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    
    QUrlQuery postData;
    postData.addQueryItem("client_id", CLIENT_ID);
    postData.addQueryItem("client_secret", CLIENT_SECRET);
    postData.addQueryItem("code", authCode);
    postData.addQueryItem("grant_type", "authorization_code");
    postData.addQueryItem("redirect_uri", REDIRECT_URI);
    
    QEventLoop loop;
    QNetworkReply *reply = manager.post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();
    
    QByteArray responseData = reply->readAll();
    reply->deleteLater();
    
    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    if (doc.isObject()) {
        QJsonObject obj = doc.object();
        if (obj.contains("access_token")) {
            m_accessToken = obj.value("access_token").toString();
            m_refreshToken = obj.value("refresh_token").toString();
            
            // Sauvegarder les tokens
            QSettings settings;
            settings.setValue("gmail/accessToken", m_accessToken);
            settings.setValue("gmail/refreshToken", m_refreshToken);
            
            // Obtenir l'email de l'utilisateur
            QNetworkRequest userRequest(QUrl("https://www.googleapis.com/oauth2/v2/userinfo"));
            userRequest.setRawHeader("Authorization", "Bearer " + m_accessToken.toUtf8());
            QNetworkReply *userReply = manager.get(userRequest);
            QEventLoop userLoop;
            QObject::connect(&manager, &QNetworkAccessManager::finished, &userLoop, &QEventLoop::quit);
            userLoop.exec();
            
            QByteArray userData = userReply->readAll();
            userReply->deleteLater();
            
            QJsonDocument userDoc = QJsonDocument::fromJson(userData);
            if (userDoc.isObject()) {
                m_userEmail = userDoc.object().value("email").toString();
                settings.setValue("gmail/userEmail", m_userEmail);
            }
            
            return true;
        } else if (obj.contains("error")) {
            qDebug() << "Erreur OAuth2:" << obj.value("error").toString();
            return false;
        }
    }
    
    return false;
}

bool GmailClient::refreshAccessToken()
{
    if (m_refreshToken.isEmpty()) {
        return false;
    }
    
    QNetworkAccessManager manager;
    QUrl tokenUrl("https://oauth2.googleapis.com/token");
    QNetworkRequest request(tokenUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    
    QUrlQuery postData;
    postData.addQueryItem("client_id", CLIENT_ID);
    postData.addQueryItem("client_secret", CLIENT_SECRET);
    postData.addQueryItem("refresh_token", m_refreshToken);
    postData.addQueryItem("grant_type", "refresh_token");
    
    QEventLoop loop;
    QNetworkReply *reply = manager.post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();
    
    QByteArray responseData = reply->readAll();
    reply->deleteLater();
    
    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    if (doc.isObject()) {
        QJsonObject obj = doc.object();
        if (obj.contains("access_token")) {
            m_accessToken = obj.value("access_token").toString();
            QSettings settings;
            settings.setValue("gmail/accessToken", m_accessToken);
            return true;
        }
    }
    
    return false;
}

QString GmailClient::getAuthorizationUrl()
{
    QUrlQuery query;
    query.addQueryItem("client_id", CLIENT_ID);
    query.addQueryItem("redirect_uri", REDIRECT_URI);
    query.addQueryItem("response_type", "code");
    query.addQueryItem("scope", SCOPE);
    query.addQueryItem("access_type", "offline");
    query.addQueryItem("prompt", "consent");
    
    QUrl url("https://accounts.google.com/o/oauth2/v2/auth");
    url.setQuery(query);
    return url.toString();
}

bool GmailClient::sendEmail(const QString& to, const QString& subject, const QString& body, QString *errorMessage)
{
    // Vérifier si on a un access token
    if (m_accessToken.isEmpty()) {
        if (errorMessage) {
            *errorMessage = "Authentification requise. Veuillez configurer l'authentification Gmail.";
        }
        return false;
    }
    
    // Créer le message au format RFC 2822
    QString message = QString(
        "From: %1\r\n"
        "To: %2\r\n"
        "Subject: %3\r\n"
        "\r\n"
        "%4"
    ).arg(m_userEmail, to, subject, body);
    
    // Encoder le message en base64url
    QByteArray messageBytes = message.toUtf8();
    QString encodedMessage = messageBytes.toBase64(QByteArray::Base64UrlEncoding | QByteArray::OmitTrailingEquals);
    
    // Créer la requête JSON pour l'API Gmail
    QJsonObject messageObj;
    QJsonObject rawObj;
    rawObj["raw"] = encodedMessage;
    messageObj["raw"] = encodedMessage;
    
    QJsonDocument doc(messageObj);
    
    // Envoyer via l'API Gmail
    QNetworkAccessManager manager;
    QUrl url("https://gmail.googleapis.com/gmail/v1/users/me/messages/send");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " + m_accessToken.toUtf8());
    
    QEventLoop loop;
    QNetworkReply *reply = manager.post(request, doc.toJson());
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();
    
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QByteArray responseData = reply->readAll();
    reply->deleteLater();
    
    if (statusCode == 401) {
        // Token expiré, essayer de le rafraîchir
        if (refreshAccessToken()) {
            // Réessayer l'envoi
            request.setRawHeader("Authorization", "Bearer " + m_accessToken.toUtf8());
            QNetworkReply *retryReply = manager.post(request, doc.toJson());
            QEventLoop retryLoop;
            QObject::connect(&manager, &QNetworkAccessManager::finished, &retryLoop, &QEventLoop::quit);
            retryLoop.exec();
            
            statusCode = retryReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            responseData = retryReply->readAll();
            retryReply->deleteLater();
        }
    }
    
    if (statusCode >= 200 && statusCode < 300) {
        return true;
    }
    
    if (errorMessage) {
        QJsonDocument errorDoc = QJsonDocument::fromJson(responseData);
        if (errorDoc.isObject()) {
            QJsonObject errorObj = errorDoc.object().value("error").toObject();
            QString errorMsg = errorObj.value("message").toString();
            *errorMessage = QString("Erreur API Gmail (%1): %2").arg(statusCode).arg(errorMsg);
        } else {
            *errorMessage = QString("Erreur HTTP %1: %2").arg(statusCode).arg(QString::fromUtf8(responseData));
        }
    }
    
    return false;
}



