#include "connection.h"
#include <QDebug>
#include <QString>

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("soumaya");
    db.setPassword("esprit18");
    if (db.open()) {
        test = true;
        qDebug() << "Connexion à la base de données réussie.";
        
        // Créer automatiquement les tables si elles n'existent pas
        qDebug() << "Vérification et création des tables...";
        creerTableUtilisateur();
        
        bool tableEmployeCreee = creerTableEmploye();
        if (tableEmployeCreee) {
            qDebug() << "Table EMPLOYE vérifiée/créée avec succès.";
        } else {
            qDebug() << "Avertissement : La table EMPLOYE n'a pas pu être créée ou vérifiée.";
        }
        
        // Toujours vérifier et créer les colonnes nécessaires si nécessaire
        creerColonneEmailEmploye();
        creerColonneMotDePasseEmploye();
        
        qDebug() << "Initialisation de la base de données terminée.";
    } else {
        qDebug() << "Erreur de connexion à la base de données (DSN) :" << db.lastError().text();

        // Tentative de repli : connexion explicite via chaîne ODBC (sans DSN)
        // Remplacez DRIVER et DBQ par les valeurs adaptées à votre installation
        QString driverName = "Oracle in instantclient_19_12"; // ex: nom du driver ODBC installé
        QString dbq = "host:1521/ORCL"; // ex: host:port/service ou nom TNS
        QString user = "soumaya";
        QString pass = "esprit18";

        QString connStr = QString("DRIVER={%1};DBQ=%2;Uid=%3;Pwd=%4;")
                          .arg(driverName)
                          .arg(dbq)
                          .arg(user)
                          .arg(pass);

        QSqlDatabase db2 = QSqlDatabase::addDatabase("QODBC", "fallback_connection");
        db2.setDatabaseName(connStr);
        // user/password inclus dans la chaîne, mais on peut les redéfinir
        db2.setUserName(user);
        db2.setPassword(pass);

        if (db2.open()) {
            test = true;
            qDebug() << "Connexion à la base de données réussie (via chaîne de connexion explicite).";

            // mêmes initialisations que pour la connexion principale
            qDebug() << "Vérification et création des tables...";
            creerTableUtilisateur();
            bool tableEmployeCreee = creerTableEmploye();
            if (tableEmployeCreee) {
                qDebug() << "Table EMPLOYE vérifiée/créée avec succès.";
            } else {
                qDebug() << "Avertissement : La table EMPLOYE n'a pas pu être créée ou vérifiée.";
            }
            creerColonneEmailEmploye();
            creerColonneMotDePasseEmploye();
            qDebug() << "Initialisation de la base de données terminée.";
        } else {
            qDebug() << "Erreur de connexion à la base de données (chaîne) :" << db2.lastError().text();
        }
    }

    return test;
}

bool Connection::tableUtilisateurExiste()
{
    QSqlQuery query;
    // Vérifier si la table existe en essayant de la sélectionner
    // Oracle : utiliser USER_TABLES ou ALL_TABLES
    query.prepare("SELECT COUNT(*) FROM USER_TABLES WHERE UPPER(TABLE_NAME) = 'UTILISATEUR'");
    
    if (query.exec() && query.next()) {
        return (query.value(0).toInt() > 0);
    }
    
    // Méthode alternative : essayer de sélectionner depuis la table
    query.prepare("SELECT COUNT(*) FROM UTILISATEUR WHERE 1=0");
    if (query.exec()) {
        return true;
    }
    
    return false;
}

bool Connection::creerTableUtilisateur()
{
    // Vérifier si la table existe déjà
    if (tableUtilisateurExiste()) {
        qDebug() << "La table UTILISATEUR existe déjà.";
        return true;
    }

    QSqlQuery query;
    
    // Créer la table UTILISATEUR
    // Utiliser une séquence pour Oracle (compatible avec toutes les versions)
    QString createTableSQL = 
        "CREATE TABLE UTILISATEUR ("
        "    ID NUMBER PRIMARY KEY,"
        "    LOGIN VARCHAR2(50) UNIQUE NOT NULL,"
        "    EMAIL VARCHAR2(100) UNIQUE NOT NULL,"
        "    MOT_DE_PASSE VARCHAR2(255) NOT NULL,"
        "    DATE_CREATION DATE DEFAULT SYSDATE,"
        "    DATE_DERNIERE_CONNEXION DATE"
        ")";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "Erreur lors de la création de la table UTILISATEUR :" << query.lastError().text();
        return false;
    }
    
    // Créer une séquence pour l'auto-incrémentation (compatible Oracle)
    QString createSequenceSQL = 
        "CREATE SEQUENCE SEQ_UTILISATEUR_ID "
        "START WITH 1 "
        "INCREMENT BY 1 "
        "NOCACHE";
    
    query.exec(createSequenceSQL); // Ignorer l'erreur si la séquence existe déjà
    
    // Créer un trigger pour l'auto-incrémentation
    QString createTriggerSQL = 
        "CREATE OR REPLACE TRIGGER TRG_UTILISATEUR_ID "
        "BEFORE INSERT ON UTILISATEUR "
        "FOR EACH ROW "
        "BEGIN "
        "    IF :NEW.ID IS NULL THEN "
        "        SELECT SEQ_UTILISATEUR_ID.NEXTVAL INTO :NEW.ID FROM DUAL; "
        "    END IF; "
        "END;";
    
    if (!query.exec(createTriggerSQL)) {
        qDebug() << "Erreur lors de la création du trigger :" << query.lastError().text();
        // Continuer même si le trigger échoue
    }
    
    // Créer un index sur l'email pour améliorer les performances
    QString createIndexSQL = "CREATE INDEX IDX_UTILISATEUR_EMAIL ON UTILISATEUR(UPPER(EMAIL))";
    query.exec(createIndexSQL); // Ignorer l'erreur si l'index existe déjà
    
    // Insérer un utilisateur par défaut (admin) s'il n'existe pas déjà
    query.prepare("SELECT COUNT(*) FROM UTILISATEUR WHERE UPPER(LOGIN) = 'ADMIN'");
    bool adminExists = false;
    if (query.exec() && query.next()) {
        adminExists = (query.value(0).toInt() > 0);
    }
    
    if (!adminExists) {
        query.prepare("INSERT INTO UTILISATEUR (ID, LOGIN, EMAIL, MOT_DE_PASSE) "
                     "VALUES (SEQ_UTILISATEUR_ID.NEXTVAL, 'admin', 'admin@example.com', 'admin')");
        if (!query.exec()) {
            qDebug() << "Erreur lors de l'insertion de l'utilisateur admin :" << query.lastError().text();
        } else {
            qDebug() << "Utilisateur admin créé avec succès.";
        }
    }
    
    qDebug() << "Table UTILISATEUR créée avec succès.";
    
    return true;
}

bool Connection::creerColonneMotDePasseEmploye()
{
    QSqlQuery query;
    
    // Vérifier d'abord si la table EMPLOYE existe
    query.prepare("SELECT COUNT(*) FROM USER_TABLES WHERE UPPER(TABLE_NAME) = 'EMPLOYE'");
    bool tableExiste = false;
    if (query.exec() && query.next()) {
        tableExiste = (query.value(0).toInt() > 0);
    }
    
    if (!tableExiste) {
        qDebug() << "La table EMPLOYE n'existe pas encore. La colonne sera créée lors de la création de la table.";
        return true; // Pas d'erreur, la table sera créée plus tard
    }
    
    // Méthode 1: Vérifier via USER_TAB_COLUMNS
    query.prepare("SELECT COUNT(*) FROM USER_TAB_COLUMNS WHERE UPPER(TABLE_NAME) = 'EMPLOYE' AND UPPER(COLUMN_NAME) = 'MOT_DE_PASSE_EMPLOYE'");
    
    bool colonneExiste = false;
    if (query.exec() && query.next()) {
        colonneExiste = (query.value(0).toInt() > 0);
    }
    
    // Méthode 2: Si la première méthode échoue, essayer de sélectionner la colonne directement
    if (!colonneExiste) {
        query.prepare("SELECT \"MOT_DE_PASSE_EMPLOYE\" FROM EMPLOYE WHERE 1=0");
        if (query.exec()) {
            colonneExiste = true;
            qDebug() << "La colonne MOT_DE_PASSE_EMPLOYE existe (vérifiée via SELECT).";
        }
    }
    
    if (colonneExiste) {
        qDebug() << "La colonne MOT_DE_PASSE_EMPLOYE existe déjà dans la table EMPLOYE.";
        return true;
    }
    
    // Créer la colonne
    QString alterTableSQL = "ALTER TABLE EMPLOYE ADD \"MOT_DE_PASSE_EMPLOYE\" VARCHAR2(255)";
    
    if (!query.exec(alterTableSQL)) {
        QString error = query.lastError().text();
        // Si l'erreur indique que la colonne existe déjà (peut arriver avec certaines versions d'Oracle)
        if (error.contains("already exists", Qt::CaseInsensitive) || 
            error.contains("déjà existant", Qt::CaseInsensitive) ||
            error.contains("ORA-01430", Qt::CaseInsensitive) ||
            error.contains("ORA-00904", Qt::CaseInsensitive)) {
            qDebug() << "La colonne MOT_DE_PASSE_EMPLOYE existe déjà (détecté via erreur).";
            return true;
        }
        qDebug() << "Erreur lors de l'ajout de la colonne MOT_DE_PASSE_EMPLOYE :" << error;
        // Ne pas retourner false, car cela pourrait empêcher l'application de démarrer
        // La colonne sera peut-être créée manuellement
        return false;
    }
    
    qDebug() << "Colonne MOT_DE_PASSE_EMPLOYE ajoutée avec succès à la table EMPLOYE.";
    return true;
}

bool Connection::creerColonneEmailEmploye()
{
    QSqlQuery query;
    
    // Vérifier d'abord si la table EMPLOYE existe
    query.prepare("SELECT COUNT(*) FROM USER_TABLES WHERE UPPER(TABLE_NAME) = 'EMPLOYE'");
    bool tableExiste = false;
    if (query.exec() && query.next()) {
        tableExiste = (query.value(0).toInt() > 0);
    }
    
    if (!tableExiste) {
        qDebug() << "La table EMPLOYE n'existe pas encore. La colonne sera créée lors de la création de la table.";
        return true; // Pas d'erreur, la table sera créée plus tard
    }
    
    // Méthode 1: Vérifier via USER_TAB_COLUMNS (chercher EMAIL en majuscules, avec ou sans guillemets)
    query.prepare("SELECT COUNT(*) FROM USER_TAB_COLUMNS WHERE UPPER(TABLE_NAME) = 'EMPLOYE' AND UPPER(COLUMN_NAME) = 'EMAIL'");
    
    bool colonneExiste = false;
    if (query.exec() && query.next()) {
        colonneExiste = (query.value(0).toInt() > 0);
    }
    
    // Méthode 2: Essayer de sélectionner la colonne avec guillemets
    if (!colonneExiste) {
        query.prepare("SELECT \"EMAIL\" FROM EMPLOYE WHERE 1=0");
        if (query.exec()) {
            colonneExiste = true;
            qDebug() << "La colonne EMAIL existe (vérifiée via SELECT avec guillemets).";
        }
    }
    
    // Méthode 3: Essayer de sélectionner la colonne sans guillemets (majuscules)
    if (!colonneExiste) {
        query.prepare("SELECT EMAIL FROM EMPLOYE WHERE 1=0");
        if (query.exec()) {
            colonneExiste = true;
            qDebug() << "La colonne EMAIL existe (vérifiée via SELECT sans guillemets).";
            // Si la colonne existe sans guillemets, on doit la renommer avec guillemets pour la cohérence
            // Mais cela nécessite de supprimer et recréer, ce qui est risqué. On va plutôt adapter les requêtes.
            qDebug() << "Note: La colonne EMAIL existe sans guillemets. Les requêtes doivent utiliser EMAIL (sans guillemets).";
            return true;
        }
    }
    
    if (colonneExiste) {
        qDebug() << "La colonne EMAIL existe déjà dans la table EMPLOYE.";
        return true;
    }
    
    // Créer la colonne avec guillemets pour garantir la casse
    QString alterTableSQL = "ALTER TABLE EMPLOYE ADD \"EMAIL\" VARCHAR2(100)";
    
    if (!query.exec(alterTableSQL)) {
        QString error = query.lastError().text();
        // Si l'erreur indique que la colonne existe déjà
        if (error.contains("already exists", Qt::CaseInsensitive) || 
            error.contains("déjà existant", Qt::CaseInsensitive) ||
            error.contains("ORA-01430", Qt::CaseInsensitive)) {
            qDebug() << "La colonne EMAIL existe déjà (détecté via erreur).";
            return true;
        }
        qDebug() << "Erreur lors de l'ajout de la colonne EMAIL :" << error;
        return false;
    }
    
    qDebug() << "Colonne EMAIL ajoutée avec succès à la table EMPLOYE.";
    return true;
}

bool Connection::tableEmployeExiste()
{
    QSqlQuery query;
    // Vérifier si la table existe
    query.prepare("SELECT COUNT(*) FROM USER_TABLES WHERE UPPER(TABLE_NAME) = 'EMPLOYE'");
    
    if (query.exec() && query.next()) {
        return (query.value(0).toInt() > 0);
    }
    
    // Méthode alternative : essayer de sélectionner depuis la table
    query.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE 1=0");
    if (query.exec()) {
        return true;
    }
    
    return false;
}

bool Connection::creerTableEmploye()
{
    // Vérifier si la table existe déjà
    if (tableEmployeExiste()) {
        qDebug() << "La table EMPLOYE existe déjà.";
        // Vérifier quand même que toutes les colonnes nécessaires existent
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM USER_TAB_COLUMNS WHERE UPPER(TABLE_NAME) = 'EMPLOYE' AND UPPER(COLUMN_NAME) = 'NOM'");
        if (query.exec() && query.next() && query.value(0).toInt() > 0) {
            return true; // La table existe avec au moins la colonne NOM
        }
        // Si la table existe mais sans colonne NOM, on doit la recréer
        qDebug() << "La table EMPLOYE existe mais semble incomplète. Tentative de recréation...";
        query.exec("DROP TABLE EMPLOYE CASCADE CONSTRAINTS");
    }

    QSqlQuery query;
    
    qDebug() << "Création de la table EMPLOYE...";
    
    // Créer la table EMPLOYE avec toutes les colonnes nécessaires
    QString createTableSQL = 
        "CREATE TABLE EMPLOYE ("
        "    ID NUMBER PRIMARY KEY,"
        "    NOM VARCHAR2(100) NOT NULL,"
        "    PRENOM VARCHAR2(100) NOT NULL,"
        "    \"EMAIL\" VARCHAR2(100),"
        "    \"MOT_DE_PASSE_EMPLOYE\" VARCHAR2(255),"
        "    DATE_DEMBAUCHE DATE NOT NULL,"
        "    POSTE VARCHAR2(100) NOT NULL,"
        "    \"ANNÉE_EXPERIENCES\" NUMBER DEFAULT 0,"
        "    SALAIRE NUMBER(10,2) DEFAULT 0,"
        "    DATE_NAISSANCE DATE NOT NULL,"
        "    ETAT_CIVIL VARCHAR2(50)"
        ")";
    
    if (!query.exec(createTableSQL)) {
        QString error = query.lastError().text();
        qDebug() << "Erreur lors de la création de la table EMPLOYE :" << error;
        // Si l'erreur indique que la table existe déjà, c'est OK
        if (!error.contains("already exists", Qt::CaseInsensitive) && 
            !error.contains("déjà existant", Qt::CaseInsensitive) &&
            !error.contains("ORA-00955", Qt::CaseInsensitive)) {
            return false;
        }
        qDebug() << "La table existe déjà, on continue...";
    } else {
        qDebug() << "Table EMPLOYE créée avec succès.";
    }
    
    // Créer une séquence pour l'auto-incrémentation de l'ID
    QString createSequenceSQL = 
        "CREATE SEQUENCE SEQ_EMPLOYE_ID "
        "START WITH 1 "
        "INCREMENT BY 1 "
        "NOCACHE";
    
    if (!query.exec(createSequenceSQL)) {
        QString error = query.lastError().text();
        // Ignorer l'erreur si la séquence existe déjà
        if (!error.contains("already exists", Qt::CaseInsensitive) && 
            !error.contains("déjà existant", Qt::CaseInsensitive) &&
            !error.contains("ORA-00955", Qt::CaseInsensitive)) {
            qDebug() << "Avertissement lors de la création de la séquence :" << error;
        }
    } else {
        qDebug() << "Séquence SEQ_EMPLOYE_ID créée avec succès.";
    }
    
    // Créer un trigger pour l'auto-incrémentation
    QString createTriggerSQL = 
        "CREATE OR REPLACE TRIGGER TRG_EMPLOYE_ID "
        "BEFORE INSERT ON EMPLOYE "
        "FOR EACH ROW "
        "BEGIN "
        "    IF :NEW.ID IS NULL THEN "
        "        SELECT SEQ_EMPLOYE_ID.NEXTVAL INTO :NEW.ID FROM DUAL; "
        "    END IF; "
        "END;";
    
    if (!query.exec(createTriggerSQL)) {
        qDebug() << "Avertissement lors de la création du trigger EMPLOYE :" << query.lastError().text();
        // Continuer même si le trigger échoue
    } else {
        qDebug() << "Trigger TRG_EMPLOYE_ID créé avec succès.";
    }
    
    // Créer des index pour améliorer les performances
    if (!query.exec("CREATE INDEX IDX_EMPLOYE_EMAIL ON EMPLOYE(UPPER(\"EMAIL\"))")) {
        // Ignorer l'erreur si l'index existe déjà
    }
    if (!query.exec("CREATE INDEX IDX_EMPLOYE_NOM ON EMPLOYE(UPPER(NOM))")) {
        // Ignorer l'erreur si l'index existe déjà
    }
    
    qDebug() << "Table EMPLOYE prête à être utilisée.";
    return true;
}
