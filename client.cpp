#include "client.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDateTime>
// Default constructor
Clients::Clients()
    : cin(""), nom(""), prenom(""), adresse(""), tel(""),
    email(""), sexe(""), historique(""), statutFidelite(false)
{
}

// Parameterized constructor
Clients::Clients(const QString &cin, const QString &nom, const QString &prenom,
                 const QString &adresse, const QString &tel, const QString &email,
                 const QString &sexe, const QString &historique, bool statutFidelite)
    : cin(cin), nom(nom), prenom(prenom), adresse(adresse), tel(tel),
    email(email), sexe(sexe), historique(historique),
    statutFidelite(statutFidelite)
{
}
bool Clients::logAction(const QString& cin, const QString& actionType,
                        const QString& oldValues, const QString& newValues)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database not open in logAction!";
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "INSERT INTO CLIENT_HISTORY (CIN, ACTION_TYPE, OLD_VALUES, NEW_VALUES) "
        "VALUES (:cin, :action_type, :old_values, :new_values)"
        );

    query.bindValue(":cin", cin);
    query.bindValue(":action_type", actionType);
    query.bindValue(":old_values", oldValues);
    query.bindValue(":new_values", newValues);

    if (!query.exec()) {
        qDebug() << "Error logging action:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Clients::ajouter()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Base non ouverte ! Erreur:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "INSERT INTO GESTIONCL2 "
        "(CIN, NOM, PRENOM, ADRESSE, TEL, EMAIL, SEXE, HISTORIQUE, STATUTFIDELITE) "
        "VALUES (:cin, :nom, :prenom, :adresse, :tel, :email, :sexe, :historique, :statutfidelite)"
        );

    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel", tel);
    query.bindValue(":email", email);
    query.bindValue(":sexe", sexe);
    query.bindValue(":historique", historique);
    query.bindValue(":statutfidelite", statutFidelite ? 1 : 0);

    if (!query.exec()) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        return false;
    }

    // Log the addition to history
    QJsonObject newValues;
    newValues["CIN"] = cin;
    newValues["NOM"] = nom;
    newValues["PRENOM"] = prenom;
    newValues["ADRESSE"] = adresse;
    newValues["TEL"] = tel;
    newValues["EMAIL"] = email;
    newValues["SEXE"] = sexe;
    newValues["HISTORIQUE"] = historique;
    newValues["STATUTFIDELITE"] = statutFidelite;

    QJsonDocument doc(newValues);
    logAction(cin, "ADD", "", doc.toJson(QJsonDocument::Compact));

    return true;
}

bool Clients::supprimer(const QString &cin)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Base non ouverte dans supprimer() !";
        return false;
    }

    // Get client data before deletion for history
    QSqlQuery selectQuery;
    selectQuery.prepare("SELECT * FROM GESTIONCL2 WHERE CIN = :cin");
    selectQuery.bindValue(":cin", cin);

    QJsonObject oldValues;
    if (selectQuery.exec() && selectQuery.next()) {
        oldValues["CIN"] = selectQuery.value("CIN").toString();
        oldValues["NOM"] = selectQuery.value("NOM").toString();
        oldValues["PRENOM"] = selectQuery.value("PRENOM").toString();
        oldValues["ADRESSE"] = selectQuery.value("ADRESSE").toString();
        oldValues["TEL"] = selectQuery.value("TEL").toString();
        oldValues["EMAIL"] = selectQuery.value("EMAIL").toString();
        oldValues["SEXE"] = selectQuery.value("SEXE").toString();
        oldValues["HISTORIQUE"] = selectQuery.value("HISTORIQUE").toString();
        oldValues["STATUTFIDELITE"] = selectQuery.value("STATUTFIDELITE").toBool();
    }

    QSqlQuery query;
    query.prepare("DELETE FROM GESTIONCL2 WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    if (!query.exec()) {
        qDebug() << "Erreur suppression client :" << query.lastError().text();
        return false;
    }

    // Log the deletion to history
    QJsonDocument doc(oldValues);
    logAction(cin, "DELETE", doc.toJson(QJsonDocument::Compact), "");

    return true;
}

bool Clients::modifier()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Base non ouverte dans modifier() !";
        return false;
    }

    // Get old values for history
    QSqlQuery selectQuery;
    selectQuery.prepare("SELECT * FROM GESTIONCL2 WHERE CIN = :cin");
    selectQuery.bindValue(":cin", cin);

    QJsonObject oldValues;
    if (selectQuery.exec() && selectQuery.next()) {
        oldValues["CIN"] = selectQuery.value("CIN").toString();
        oldValues["NOM"] = selectQuery.value("NOM").toString();
        oldValues["PRENOM"] = selectQuery.value("PRENOM").toString();
        oldValues["ADRESSE"] = selectQuery.value("ADRESSE").toString();
        oldValues["TEL"] = selectQuery.value("TEL").toString();
        oldValues["EMAIL"] = selectQuery.value("EMAIL").toString();
        oldValues["SEXE"] = selectQuery.value("SEXE").toString();
        oldValues["HISTORIQUE"] = selectQuery.value("HISTORIQUE").toString();
        oldValues["STATUTFIDELITE"] = selectQuery.value("STATUTFIDELITE").toBool();
    }

    QSqlQuery query;
    query.prepare(
        "UPDATE GESTIONCL2 SET "
        "NOM = :nom, PRENOM = :prenom, ADRESSE = :adresse, TEL = :tel, "
        "EMAIL = :email, SEXE = :sexe, HISTORIQUE = :historique, "
        "STATUTFIDELITE = :statutfidelite "
        "WHERE CIN = :cin"
        );

    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel", tel);
    query.bindValue(":email", email);
    query.bindValue(":sexe", sexe);
    query.bindValue(":historique", historique);
    query.bindValue(":statutfidelite", statutFidelite ? 1 : 0);

    if (!query.exec()) {
        qDebug() << "Erreur modification client :" << query.lastError().text();
        return false;
    }

    // Log the modification to history
    QJsonObject newValues;
    newValues["CIN"] = cin;
    newValues["NOM"] = nom;
    newValues["PRENOM"] = prenom;
    newValues["ADRESSE"] = adresse;
    newValues["TEL"] = tel;
    newValues["EMAIL"] = email;
    newValues["SEXE"] = sexe;
    newValues["HISTORIQUE"] = historique;
    newValues["STATUTFIDELITE"] = statutFidelite;

    QJsonDocument oldDoc(oldValues);
    QJsonDocument newDoc(newValues);
    logAction(cin, "UPDATE", oldDoc.toJson(QJsonDocument::Compact), newDoc.toJson(QJsonDocument::Compact));

    return true;
}

QSqlQueryModel* Clients::getHistory()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database not open in getHistory!";
        return nullptr;
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(
        "SELECT HISTORY_ID, CIN, ACTION_TYPE, ACTION_DATE, OLD_VALUES, NEW_VALUES, USER_NAME "
        "FROM CLIENT_HISTORY "
        "ORDER BY ACTION_DATE DESC"
        );

    if (model->lastError().isValid()) {
        qDebug() << "Error in getHistory:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Action"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date/Heure"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Anciennes Valeurs"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nouvelles Valeurs"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Utilisateur"));

    return model;
}

bool Clients::clearHistory()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database not open in clearHistory!";
        return false;
    }

    QSqlQuery query("DELETE FROM CLIENT_HISTORY");

    if (!query.exec()) {
        qDebug() << "Error clearing history:" << query.lastError().text();
        return false;
    }

    return true;
}
QSqlQueryModel* Clients::afficher()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Base non ouverte dans afficher() !";
        return nullptr;
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(
        "SELECT CIN, NOM, PRENOM, ADRESSE, TEL, EMAIL, SEXE, HISTORIQUE, STATUTFIDELITE "
        "FROM GESTIONCL2 ORDER BY NOM"
        );

    if (model->lastError().isValid()) {
        qDebug() << "Erreur dans afficher():" << model->lastError().text();
        delete model;
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Historique"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Statut Fidélité"));

    return model;
}



bool Clients::cinExiste(const QString &cin, const QString &cinActuel)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Base non ouverte dans cinExiste() !";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM GESTIONCL2 WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if (!cinActuel.isEmpty() && cin == cinActuel)
            return false;
        return count > 0;
    }
    return false;
}

bool Clients::emailExiste(const QString &email, const QString &cinActuel)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Base non ouverte dans emailExiste() !";
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "SELECT COUNT(*) FROM GESTIONCL2 WHERE EMAIL = :email AND CIN != :cin"
        );
    query.bindValue(":email", email);
    query.bindValue(":cin", cinActuel.isEmpty() ? "" : cinActuel);

    if (query.exec() && query.next())
        return query.value(0).toInt() > 0;
    return false;
}

QSqlQueryModel* Clients::rechercher(const QString &critere)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        return nullptr;
    }

    QSqlQueryModel *model = new QSqlQueryModel;

    QSqlQuery query;
    query.prepare(
        "SELECT CIN, NOM, PRENOM, ADRESSE, TEL, EMAIL, SEXE, HISTORIQUE, STATUTFIDELITE "
        "FROM GESTIONCL2 WHERE "
        "NOM LIKE :nom "  // Search only by name
        "ORDER BY NOM"
        );

    QString value = "%" + critere + "%";
    query.bindValue(":nom", value);

    if (!query.exec()) {
        delete model;
        return nullptr;
    }

    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Historique"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Statut Fidélité"));

    return model;
}
QSqlQueryModel* Clients::trier(const QString &colonne, const QString &ordre)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Base non ouverte dans trier() !";
        return nullptr;
    }

    QStringList colonnesValides = {"CIN", "NOM", "PRENOM", "EMAIL", "TEL", "ADRESSE", "SEXE", "STATUTFIDELITE"};

    QString col = colonne.toUpper();
    if (!colonnesValides.contains(col))
        col = "NOM";

    QString ord = (ordre.toUpper() == "DESC") ? "DESC" : "ASC";

    QSqlQueryModel *model = new QSqlQueryModel;
    QString queryStr =
        "SELECT CIN, NOM, PRENOM, ADRESSE, TEL, EMAIL, SEXE, HISTORIQUE, STATUTFIDELITE "
        "FROM GESTIONCL2 ORDER BY " + col + " " + ord;

    model->setQuery(queryStr);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur tri :" << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}

bool Clients::exportPDF(const QString &filePath)
{
    try {
        // Create PDF writer
        QPdfWriter pdfWriter(filePath);
        pdfWriter.setPageSize(QPageSize(QPageSize::A4));
        pdfWriter.setPageOrientation(QPageLayout::Portrait);
        pdfWriter.setTitle("Liste des Clients");
        pdfWriter.setCreator("Gestion Client Application");

        QPainter painter;
        if (!painter.begin(&pdfWriter)) {
            qDebug() << "Failed to initialize painter for PDF";
            return false;
        }

        // Set up fonts
        QFont titleFont("Arial", 16, QFont::Bold);
        QFont headerFont("Arial", 10, QFont::Bold);
        QFont dataFont("Arial", 8);
        QFont infoFont("Arial", 9);
Clients client;
        // Get data from database
        QSqlQueryModel* model = client.afficher();
        if (!model) {
            painter.end();
            qDebug() << "Failed to get data from database";
            return false;
        }

        int rowCount = model->rowCount();
        int columnCount = model->columnCount();

        // PDF settings
        int yPos = 100;
        const int lineHeight = 20;
        const int margin = 50;
        const int pageWidth = pdfWriter.width() - 2 * margin;

        // Draw title
        painter.setFont(titleFont);
        painter.setPen(Qt::darkBlue);
        painter.drawText(margin, yPos, "📋 LISTE DES CLIENTS");
        yPos += 40;

        // Draw date and info
        painter.setFont(infoFont);
        painter.setPen(Qt::black);
        painter.drawText(margin, yPos, "Date d'export: " + QDate::currentDate().toString("dd/MM/yyyy"));
        painter.drawText(pdfWriter.width() - margin - 200, yPos, "Total: " + QString::number(rowCount) + " clients");
        yPos += 30;

        // Draw table headers
        painter.setFont(headerFont);
        painter.setBrush(QBrush(QColor(52, 152, 219))); // Blue background
        painter.setPen(QPen(Qt::white));

        // Column widths
        QList<int> colWidths = {
            100,  // CIN
            120,  // Nom
            120,  // Prénom
            120,  // Téléphone
            200,  // Email
            80    // Statut
        };

        int currentX = margin;

        // Draw header background
        painter.drawRect(margin, yPos, pageWidth, lineHeight);

        // Draw header text
        QStringList headers = {"CIN", "Nom", "Prénom", "Téléphone", "Email", "Statut Fidélité"};

        for (int col = 0; col < headers.size() && col < colWidths.size(); ++col) {
            painter.drawText(currentX + 5, yPos + 5, colWidths[col] - 10, lineHeight - 10,
                             Qt::AlignLeft | Qt::AlignVCenter, headers[col]);
            currentX += colWidths[col];
        }

        yPos += lineHeight;

        // Reset pen for data
        painter.setPen(QPen(Qt::black));
        painter.setBrush(QBrush(Qt::NoBrush));

        // Draw table data
        painter.setFont(dataFont);

        // Get all data from database (more efficient than using model for each cell)
        QSqlQuery query("SELECT CIN, NOM, PRENOM, TEL, EMAIL, STATUTFIDELITE FROM GESTIONCL2 ORDER BY NOM");
        int currentRow = 0;

        while (query.next()) {
            // Check if we need a new page
            if (yPos > pdfWriter.height() - 100) {
                pdfWriter.newPage();
                yPos = 100;

                // Redraw header on new page
                painter.setFont(headerFont);
                painter.setBrush(QBrush(QColor(52, 152, 219)));
                painter.setPen(QPen(Qt::white));
                painter.drawRect(margin, yPos, pageWidth, lineHeight);

                currentX = margin;
                for (int col = 0; col < headers.size() && col < colWidths.size(); ++col) {
                    painter.drawText(currentX + 5, yPos + 5, colWidths[col] - 10, lineHeight - 10,
                                     Qt::AlignLeft | Qt::AlignVCenter, headers[col]);
                    currentX += colWidths[col];
                }

                yPos += lineHeight;
                painter.setPen(QPen(Qt::black));
                painter.setBrush(QBrush(Qt::NoBrush));
                painter.setFont(dataFont);
            }

            // Draw row background (alternating colors for readability)
            if (currentRow % 2 == 0) {
                painter.setBrush(QBrush(QColor(240, 240, 240)));
            } else {
                painter.setBrush(QBrush(Qt::white));
            }

            painter.drawRect(margin, yPos, pageWidth, lineHeight);
            painter.setBrush(QBrush(Qt::NoBrush));

            // Draw cell data
            currentX = margin;

            for (int col = 0; col < 6; ++col) {
                QString data;
                if (col < 5) {
                    data = query.value(col).toString();
                } else {
                    // Last column is fidelity status
                    bool isFidele = query.value(5).toBool();
                    data = isFidele ? "✓ Fidèle" : "Non fidèle";
                    if (isFidele) {
                        painter.setPen(QPen(Qt::darkGreen));
                    } else {
                        painter.setPen(QPen(Qt::darkRed));
                    }
                }

                painter.drawText(currentX + 5, yPos + 5, colWidths[col] - 10, lineHeight - 10,
                                 Qt::AlignLeft | Qt::AlignVCenter, data);

                // Reset pen color for next cell
                if (col == 5) {
                    painter.setPen(QPen(Qt::black));
                }

                currentX += colWidths[col];
            }

            yPos += lineHeight;
            currentRow++;
        }

        // Draw summary at bottom
        yPos += 30;
        painter.setFont(headerFont);
        painter.setPen(QPen(Qt::darkBlue));

        int fideleCount = 0;
        QSqlQuery countQuery("SELECT COUNT(*) FROM GESTIONCL2 WHERE STATUTFIDELITE = 1");
        if (countQuery.exec() && countQuery.next()) {
            fideleCount = countQuery.value(0).toInt();
        }

        painter.drawText(margin, yPos, "RÉSUMÉ:");
        yPos += 20;
        painter.setFont(infoFont);
        painter.setPen(QPen(Qt::black));
        painter.drawText(margin, yPos, "• Total clients: " + QString::number(rowCount));
        yPos += 15;
        painter.drawText(margin, yPos, "• Clients fidèles: " + QString::number(fideleCount));
        yPos += 15;
        painter.drawText(margin, yPos, "• Taux de fidélité: " +
                                           (rowCount > 0 ? QString::number((fideleCount * 100.0) / rowCount, 'f', 1) + "%" : "0%"));

        // Draw footer
        yPos = pdfWriter.height() - 50;
        painter.setFont(QFont("Arial", 7));
        painter.setPen(QPen(Qt::gray));
        painter.drawText(margin, yPos, "Document généré par Gestion Client Application - " +
                                           QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));

        painter.end();
        delete model;

        qDebug() << "PDF exporté avec succès:" << filePath;
        return true;

    } catch (const std::exception &e) {
        qDebug() << "Erreur export PDF:" << e.what();
        return false;
    } catch (...) {
        qDebug() << "Erreur inconnue lors de l'export PDF";
        return false;
    }
}
QSqlQueryModel* Clients::trierParCritere(const QString &critere, const QString &ordre)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Base non ouverte dans trierParCritere() !";
        return nullptr;
    }

    QString colonne;
    QString ordreSql;

    if (critere == "CIN Croissant") {
        colonne = "CIN";
        ordreSql = "ASC";
    } else if (critere == "CIN Décroissant") {
        colonne = "CIN";
        ordreSql = "DESC";
    } else if (critere == "Nom Croissant") {
        colonne = "NOM";
        ordreSql = "ASC";
    } else if (critere == "Nom Décroissant") {
        colonne = "NOM";
        ordreSql = "DESC";
    } else {
        // Default sorting by name ascending
        colonne = "NOM";
        ordreSql = "ASC";
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    QString queryStr =
        "SELECT CIN, NOM, PRENOM, ADRESSE, TEL, EMAIL, SEXE, HISTORIQUE, STATUTFIDELITE "
        "FROM GESTIONCL2 ORDER BY " + colonne + " " + ordreSql;

    model->setQuery(queryStr);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur tri :" << model->lastError().text();
        delete model;
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Historique"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Statut Fidélité"));

    return model;
}
