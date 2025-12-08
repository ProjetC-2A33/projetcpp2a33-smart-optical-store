-- Script SQL pour créer la table FOURNISSEUR
-- Compatible avec Oracle Database
-- 
-- IMPORTANT: Run this with YOUR Oracle user in SQL Developer
-- (gestion_user, ghaith, or system - depending on your setup)

-- Supprimer la table si elle existe (optionnel - uncomment if needed)
-- DROP TABLE FOURNISSEUR CASCADE CONSTRAINTS;

-- Créer la table FOURNISSEUR
CREATE TABLE FOURNISSEUR (
    ID_FOURNISSEUR NUMBER PRIMARY KEY,
    NOM VARCHAR2(100) NOT NULL,
    ADRESSE VARCHAR2(200),
    EMAIL VARCHAR2(100),
    TELEPHONE VARCHAR2(20),
    TYPE_PRODUITS VARCHAR2(100),
    HISTORIQUE_LIVRAISONS VARCHAR2(500),
    IS_ACTIVE NUMBER(1) DEFAULT 1
);

-- Insérer quelques données de test
INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE)
VALUES (1, 'Fournisseur ABC', '123 Rue Principale', 'abc@email.com', '123456789', 'Électronique', '10 livraisons réussies', 1);

INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE)
VALUES (2, 'Fournisseur XYZ', '456 Avenue Central', 'xyz@email.com', '987654321', 'Mobilier', '5 livraisons réussies', 1);

INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE)
VALUES (3, 'Fournisseur Tech', '789 Bd Innovation', 'tech@email.com', '555123456', 'Informatique', '15 livraisons réussies', 1);

COMMIT;

-- Vérifier l'insertion
SELECT * FROM FOURNISSEUR;

