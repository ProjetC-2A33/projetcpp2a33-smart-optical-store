-- Script SQL pour créer la table EMPLOYE
-- Nécessaire pour la gestion des employés
-- Exécutez ce script dans votre base de données Oracle
-- Compatible avec toutes les versions d'Oracle

-- Créer la table EMPLOYE
CREATE TABLE EMPLOYE (
    ID NUMBER PRIMARY KEY,
    NOM VARCHAR2(100) NOT NULL,
    PRENOM VARCHAR2(100) NOT NULL,
    "EMAIL" VARCHAR2(100),
    "MOT_DE_PASSE_EMPLOYE" VARCHAR2(255),
    DATE_DEMBAUCHE DATE NOT NULL,
    POSTE VARCHAR2(100) NOT NULL,
    "ANNÉE_EXPERIENCES" NUMBER DEFAULT 0,
    SALAIRE NUMBER(10,2) DEFAULT 0,
    DATE_NAISSANCE DATE NOT NULL,
    ETAT_CIVIL VARCHAR2(50)
);

-- Créer une séquence pour l'auto-incrémentation (compatible avec toutes les versions)
CREATE SEQUENCE SEQ_EMPLOYE_ID
START WITH 1
INCREMENT BY 1
NOCACHE;

-- Créer un trigger pour l'auto-incrémentation automatique
CREATE OR REPLACE TRIGGER TRG_EMPLOYE_ID
BEFORE INSERT ON EMPLOYE
FOR EACH ROW
BEGIN
    IF :NEW.ID IS NULL THEN
        SELECT SEQ_EMPLOYE_ID.NEXTVAL INTO :NEW.ID FROM DUAL;
    END IF;
END;
/

-- Créer des index pour améliorer les performances de recherche
CREATE INDEX IDX_EMPLOYE_EMAIL ON EMPLOYE(UPPER("EMAIL"));
CREATE INDEX IDX_EMPLOYE_NOM ON EMPLOYE(UPPER(NOM));

COMMIT;

-- Note importante :
-- La colonne EMAIL utilise des guillemets pour préserver la casse
-- La colonne MOT_DE_PASSE_EMPLOYE utilise des guillemets pour préserver la casse
-- La colonne ANNÉE_EXPERIENCES utilise des guillemets car elle contient des caractères spéciaux

