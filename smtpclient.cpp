#include "smtpclient.h"

#include <QTextStream>
#include <QDebug>

SmtpClient::SmtpClient(const QString& host,
                       quint16 port,
                       const QString& username,
                       const QString& password,
                       QObject *parent)
    : QObject(parent)
    , m_host(host)
    , m_port(port)
    , m_username(username)
    , m_password(password)
{
}

bool SmtpClient::sendMail(const QString& from,
                          const QStringList& to,
                          const QString& subject,
                          const QString& body,
                          QString *errorMessage)
{
    QSslSocket socket;
    
    // Pour le port 587, on utilise STARTTLS (connexion non chiffrée puis upgrade)
    // Pour le port 465, on utilise SSL direct
    if (m_port == 465) {
        // Connexion SSL directe (port 465)
        socket.connectToHostEncrypted(m_host, m_port);
        if (!socket.waitForEncrypted(10000)) {
            if (errorMessage) {
                *errorMessage = QStringLiteral("Connexion SSL impossible : %1")
                                    .arg(socket.errorString());
            }
            return false;
        }
    } else {
        // Connexion non chiffrée puis STARTTLS (port 587)
        socket.connectToHost(m_host, m_port);
        if (!socket.waitForConnected(10000)) {
            if (errorMessage) {
                *errorMessage = QStringLiteral("Connexion impossible : %1")
                                    .arg(socket.errorString());
            }
            return false;
        }
        
        // Lire la réponse initiale du serveur
        if (!readResponse(socket, 220, errorMessage)) {
            return false;
        }
    }

    if (!sendCommand(socket, QByteArrayLiteral("EHLO localhost\r\n"), 250, errorMessage)) {
        return false;
    }
    
    // Pour le port 587, initier STARTTLS
    if (m_port != 465) {
        if (!sendCommand(socket, QByteArrayLiteral("STARTTLS\r\n"), 220, errorMessage)) {
            return false;
        }
        
        // Activer le chiffrement
        socket.startClientEncryption();
        if (!socket.waitForEncrypted(10000)) {
            if (errorMessage) {
                *errorMessage = QStringLiteral("Échec STARTTLS : %1")
                                    .arg(socket.errorString());
            }
            return false;
        }
        
        // Renvoyer EHLO après STARTTLS
        if (!sendCommand(socket, QByteArrayLiteral("EHLO localhost\r\n"), 250, errorMessage)) {
            return false;
        }
    }

    if (!sendCommand(socket, QByteArrayLiteral("AUTH LOGIN\r\n"), 334, errorMessage)) {
        return false;
    }

    // Envoyer le nom d'utilisateur (email) encodé en base64
    QByteArray usernameBase64 = m_username.toUtf8().toBase64();
    if (!sendCommand(socket, usernameBase64 + "\r\n", 334, errorMessage)) {
        if (errorMessage && errorMessage->isEmpty()) {
            *errorMessage = "Échec de l'authentification : nom d'utilisateur rejeté";
        }
        return false;
    }

    // Envoyer le mot de passe encodé en base64
    QByteArray passwordBase64 = m_password.toUtf8().toBase64();
    if (!sendCommand(socket, passwordBase64 + "\r\n", 235, errorMessage)) {
        if (errorMessage) {
            QString detailedError = *errorMessage;
            if (detailedError.contains("535") || detailedError.contains("not accepted") || detailedError.contains("BadCredentials")) {
                *errorMessage = QStringLiteral(
                    "Erreur d'authentification Gmail :\n\n"
                    "Le nom d'utilisateur ou le mot de passe est incorrect.\n\n"
                    "SOLUTION :\n"
                    "1. Assurez-vous d'utiliser un MOT DE PASSE D'APPLICATION (16 caractères)\n"
                    "   et NON votre mot de passe Gmail normal.\n"
                    "2. Créez un mot de passe d'application sur :\n"
                    "   https://myaccount.google.com/apppasswords\n"
                    "3. Activez d'abord la 'Validation en 2 étapes' si nécessaire.\n"
                    "4. Utilisez le mot de passe de 16 caractères généré par Google.\n\n"
                    "Erreur technique : %1").arg(detailedError);
            }
        }
        return false;
    }

    if (!sendCommand(socket, "MAIL FROM:<" + from.toUtf8() + ">\r\n", 250, errorMessage)) {
        return false;
    }

    for (const QString& dest : to) {
        if (!sendCommand(socket, "RCPT TO:<" + dest.toUtf8() + ">\r\n", 250, errorMessage)) {
            return false;
        }
    }

    if (!sendCommand(socket, QByteArrayLiteral("DATA\r\n"), 354, errorMessage)) {
        return false;
    }

    QByteArray data;
    data.append("From: <" + from.toUtf8() + ">\r\n");
    if (!to.isEmpty()) {
        data.append("To: <" + to.first().toUtf8() + ">\r\n");
    }
    
    // Encoder le sujet en UTF-8 avec format RFC 2047 pour les caractères spéciaux
    QByteArray subjectBytes = subject.toUtf8();
    QString encodedSubject;
    if (subjectBytes != subject.toLatin1()) {
        // Le sujet contient des caractères non-ASCII, utiliser l'encodage RFC 2047
        encodedSubject = "=?UTF-8?B?" + subjectBytes.toBase64() + "?=";
    } else {
        encodedSubject = subject;
    }
    data.append("Subject: " + encodedSubject.toUtf8() + "\r\n");
    data.append("Content-Type: text/plain; charset=UTF-8\r\n");
    data.append("Content-Transfer-Encoding: 8bit\r\n");
    data.append("\r\n");
    
    // Normaliser les sauts de ligne du corps du message
    QString normalizedBody = body;
    normalizedBody.replace("\r\n", "\n");  // Normaliser d'abord
    normalizedBody.replace("\r", "\n");   // Puis remplacer les \r restants
    normalizedBody.replace("\n", "\r\n");  // Convertir en \r\n pour SMTP
    
    // Vérifier que le corps n'est pas vide
    if (normalizedBody.isEmpty()) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("Le corps du message est vide");
        }
        qDebug() << "ERREUR: Le corps du message est vide!";
        return false;
    }
    
    qDebug() << "Envoi SMTP - From:" << from;
    qDebug() << "Envoi SMTP - To:" << to;
    qDebug() << "Envoi SMTP - Subject:" << subject;
    qDebug() << "Envoi SMTP - Body length:" << normalizedBody.length();
    qDebug() << "Envoi SMTP - Body preview:" << normalizedBody.left(200);
    
    data.append(normalizedBody.toUtf8());
    data.append("\r\n.\r\n");
    
    qDebug() << "Envoi SMTP - Total data size:" << data.size() << "bytes";

    if (!socket.write(data) || !socket.waitForBytesWritten(10000)) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("Impossible d'envoyer les données : %1")
                                .arg(socket.errorString());
        }
        return false;
    }

    if (!readResponse(socket, 250, errorMessage)) {
        return false;
    }

    sendCommand(socket, QByteArrayLiteral("QUIT\r\n"), 221, nullptr);
    socket.disconnectFromHost();
    socket.waitForDisconnected(3000);
    return true;
}

bool SmtpClient::sendCommand(QSslSocket& socket,
                             const QByteArray& command,
                             int expectedCode,
                             QString *errorMessage)
{
    if (!socket.write(command) || !socket.waitForBytesWritten(5000)) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("Impossible d'écrire sur le socket : %1")
                                .arg(socket.errorString());
        }
        return false;
    }
    return readResponse(socket, expectedCode, errorMessage);
}

bool SmtpClient::readResponse(QSslSocket& socket,
                              int expectedCode,
                              QString *errorMessage)
{
    QByteArray fullResponse;
    QString codeStr = QString::number(expectedCode);
    bool foundExpectedCode = false;
    int timeout = 5000;

    // Lire toutes les lignes de la réponse jusqu'à trouver le code attendu
    while (socket.waitForReadyRead(timeout)) {
        while (socket.canReadLine()) {
            QByteArray line = socket.readLine();
            fullResponse += line;
            
            // Vérifier si cette ligne contient le code attendu
            // Format SMTP: "250 OK" ou "250-..." (multi-ligne) ou "250 ..."
            QString lineStr = QString::fromUtf8(line).trimmed();
            if (lineStr.startsWith(codeStr + " ") || 
                lineStr.startsWith(codeStr + "-") ||
                (lineStr.length() == codeStr.length() && lineStr == codeStr)) {
                foundExpectedCode = true;
                // Si c'est une réponse multi-ligne (250-...), continuer à lire
                // jusqu'à trouver la ligne finale (250 ...)
                if (!lineStr.startsWith(codeStr + "-")) {
                    // Ligne finale trouvée, on peut retourner
                    return true;
                }
            }
        }
        
        // Si on a trouvé le code attendu sur une ligne finale, on est déjà sorti
        // Sinon, continuer à lire pour trouver la ligne finale
        if (foundExpectedCode && !socket.canReadLine()) {
            // Plus de données à lire, vérifier si on a une réponse valide
            break;
        }
    }

    if (!foundExpectedCode) {
        if (errorMessage) {
            *errorMessage = QStringLiteral("Réponse inattendue du serveur (attendu: %1) : %2")
                                .arg(expectedCode)
                                .arg(QString::fromUtf8(fullResponse));
        }
        return false;
    }
    return true;
}



