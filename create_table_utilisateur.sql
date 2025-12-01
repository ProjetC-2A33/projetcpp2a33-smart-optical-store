-- Script SQL pour créer la table UTILISATEUR
-- Nécessaire pour la fonctionnalité "Mot de passe oublié"
-- Exécutez ce script dans votre base de données Oracle
-- Compatible avec toutes les versions d'Oracle

-- Créer la table UTILISATEUR
CREATE TABLE UTILISATEUR (
    ID NUMBER PRIMARY KEY,
    LOGIN VARCHAR2(50) UNIQUE NOT NULL,
    EMAIL VARCHAR2(100) UNIQUE NOT NULL,
    MOT_DE_PASSE VARCHAR2(255) NOT NULL,
    DATE_CREATION DATE DEFAULT SYSDATE,
    DATE_DERNIERE_CONNEXION DATE
);

-- Créer une séquence pour l'auto-incrémentation (compatible avec toutes les versions)
CREATE SEQUENCE SEQ_UTILISATEUR_ID
START WITH 1
INCREMENT BY 1
NOCACHE;

-- Créer un trigger pour l'auto-incrémentation automatique
CREATE OR REPLACE TRIGGER TRG_UTILISATEUR_ID
BEFORE INSERT ON UTILISATEUR
FOR EACH ROW
BEGIN
    IF :NEW.ID IS NULL THEN
        SELECT SEQ_UTILISATEUR_ID.NEXTVAL INTO :NEW.ID FROM DUAL;
    END IF;
END;
/

-- Créer un index sur l'email pour améliorer les performances de recherche
CREATE INDEX IDX_UTILISATEUR_EMAIL ON UTILISATEUR(UPPER(EMAIL));

-- Insérer un utilisateur par défaut (admin)
-- Le mot de passe est "admin" (à changer en production)
INSERT INTO UTILISATEUR (LOGIN, EMAIL, MOT_DE_PASSE) 
VALUES ('admin', 'admin@example.com', 'admin');

COMMIT;

-- Note importante sur la sécurité :
-- En production, il est fortement recommandé de :
-- 1. Hacher les mots de passe avec bcrypt ou Argon2
-- 2. Ajouter un champ SALT pour chaque utilisateur
-- 3. Implémenter une expiration des mots de passe
-- 4. Ajouter des tentatives de connexion limitées
-- 5. Utiliser des tokens JWT pour les sessions

