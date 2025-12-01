#include "curlemailer.h"
#include <QProcess>
#include <QDebug>
#include <QTemporaryFile>
#include <QTextStream>

CurlEmailer::CurlEmailer(QObject *parent)
    : QObject(parent)
{
}

bool CurlEmailer::sendEmail(const QString& to,
                           const QString& subject,
                           const QString& body,
                           QString *errorMessage)
{
    // Utiliser curl pour envoyer via l'API Resend
    QString apiKey = "re_duAW4BAW_9psUkLuVf8RaN3Tg8LrBWwrC";
    
    // Échapper les caractères spéciaux dans le JSON
    QString escapedBody = body;
    escapedBody.replace("\\", "\\\\");
    escapedBody.replace("\"", "\\\"");
    escapedBody.replace("\n", "\\n");
    escapedBody.replace("\r", "");
    
    QString escapedSubject = subject;
    escapedSubject.replace("\\", "\\\\");
    escapedSubject.replace("\"", "\\\"");
    
    // Construire le JSON directement
    QString jsonData = QString("{\"from\":\"Ghofranne Barhoumi <onboarding@resend.dev>\",\"to\":\"%1\",\"subject\":\"%2\",\"text\":\"%3\"}")
                          .arg(to, escapedSubject, escapedBody);
    
    qDebug() << "=== ENVOI EMAIL VIA CURL ===";
    qDebug() << "Destinataire:" << to;
    qDebug() << "JSON:" << jsonData;
    
    // Construire la commande curl
    QStringList arguments;
    arguments << "-k"; // Ignorer la vérification SSL
    arguments << "-s"; // Mode silencieux (pas de progression)
    arguments << "-X" << "POST";
    arguments << "https://api.resend.com/emails";
    arguments << "-H" << "Authorization: Bearer " + apiKey;
    arguments << "-H" << "Content-Type: application/json";
    arguments << "-d" << jsonData;
    
    qDebug() << "Commande curl:" << "curl" << arguments.join(" ");
    
    // Exécuter curl
    QProcess process;
    process.start("curl", arguments);
    
    if (!process.waitForStarted(5000)) {
        if (errorMessage) {
            *errorMessage = "Impossible de démarrer curl. Assurez-vous que curl est installé.";
        }
        return false;
    }
    
    if (!process.waitForFinished(30000)) {
        if (errorMessage) {
            *errorMessage = "Timeout lors de l'envoi de l'email";
        }
        process.kill();
        return false;
    }
    
    QByteArray output = process.readAllStandardOutput();
    QByteArray errorOutput = process.readAllStandardError();
    int exitCode = process.exitCode();
    
    qDebug() << "Exit code:" << exitCode;
    qDebug() << "Output:" << QString::fromUtf8(output);
    
    if (exitCode == 0 && output.contains("\"id\"")) {
        return true;
    }
    
    if (errorMessage) {
        *errorMessage = QString("Erreur curl: %1")
                           .arg(QString::fromUtf8(output));
    }
    
    return false;
}
