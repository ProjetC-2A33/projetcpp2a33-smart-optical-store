-- =============================================================================
-- COMPLETE DATABASE SETUP SCRIPT - RESPECTING FOREIGN KEY RELATIONS
-- =============================================================================
-- Run this script in Oracle SQL Developer with your user (gestion_user/system)
-- This script creates all tables in the correct order to respect FK constraints
-- =============================================================================

-- Drop tables in reverse order (children first, then parents)
DROP TABLE PRODUIT CASCADE CONSTRAINTS;
DROP TABLE CLIENT CASCADE CONSTRAINTS;
DROP TABLE FOURNISSEUR CASCADE CONSTRAINTS;
DROP TABLE EMPLOYES CASCADE CONSTRAINTS;
DROP TABLE SPONSOR CASCADE CONSTRAINTS;

-- =============================================================================
-- 1. FOURNISSEUR TABLE (Parent - no dependencies)
-- =============================================================================
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

-- Insert test data for FOURNISSEUR
INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE)
VALUES (1, 'Fournisseur ABC', '123 Rue Principale', 'abc@email.com', '123456789', 'Électronique', '10 livraisons réussies', 1);

INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE)
VALUES (2, 'Fournisseur XYZ', '456 Avenue Central', 'xyz@email.com', '987654321', 'Mobilier', '5 livraisons réussies', 1);

INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE)
VALUES (3, 'Fournisseur Tech', '789 Bd Innovation', 'tech@email.com', '555123456', 'Informatique', '15 livraisons réussies', 1);

-- =============================================================================
-- 2. CLIENT TABLE (Parent - no dependencies)
-- =============================================================================
CREATE TABLE CLIENT (
    CIN NUMBER PRIMARY KEY,
    PRENOM VARCHAR2(100) NOT NULL,
    NOM VARCHAR2(100) NOT NULL,
    EMAIL VARCHAR2(100),
    TELEPHONE VARCHAR2(20),
    ADRESSE VARCHAR2(200),
    SEXE VARCHAR2(10)
);

-- Insert test data for CLIENT
INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE)
VALUES (12345678, 'Ahmed', 'Ben Ali', 'ahmed.benali@email.com', '20123456', '12 Rue Habib Bourguiba, Tunis', 'homme');

INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE)
VALUES (87654321, 'Fatma', 'Trabelsi', 'fatma.trabelsi@email.com', '25987654', '45 Avenue de la Liberté, Sfax', 'femme');

INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE)
VALUES (11223344, 'Mohamed', 'Saidi', 'mohamed.saidi@email.com', '22334455', '78 Rue de la République, Sousse', 'homme');

-- =============================================================================
-- 3. PRODUIT TABLE (Child - depends on FOURNISSEUR and CLIENT)
-- =============================================================================
CREATE TABLE PRODUIT (
    REFERENCE NUMBER PRIMARY KEY,
    NOM VARCHAR2(100) NOT NULL,
    QUANTITE NUMBER NOT NULL,
    PRIX NUMBER(10,2) NOT NULL,
    CATEGORY VARCHAR2(100),
    FOURNISSEURS VARCHAR2(100),
    DATE_FAB DATE,
    DATE_EXP DATE,
    ID_FOURNISSEURS NUMBER,
    ID_CLIENTS NUMBER,
    -- Foreign Key Constraints
    CONSTRAINT FK_PRODUIT_FOURNISSEUR FOREIGN KEY (ID_FOURNISSEURS) 
        REFERENCES FOURNISSEUR(ID_FOURNISSEUR) ON DELETE SET NULL,
    CONSTRAINT FK_PRODUIT_CLIENT FOREIGN KEY (ID_CLIENTS) 
        REFERENCES CLIENT(CIN) ON DELETE SET NULL
);

-- Insert test data for PRODUIT (with valid FK references)
INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, DATE_FAB, DATE_EXP, ID_FOURNISSEURS, ID_CLIENTS)
VALUES (1001, 'Ordinateur Portable HP', 50, 2500.00, 'Informatique', 'Fournisseur Tech', 
        TO_DATE('2024-01-15', 'YYYY-MM-DD'), TO_DATE('2026-01-15', 'YYYY-MM-DD'), 3, 12345678);

INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, DATE_FAB, DATE_EXP, ID_FOURNISSEURS, ID_CLIENTS)
VALUES (1002, 'Chaise de Bureau', 100, 350.50, 'Mobilier', 'Fournisseur XYZ', 
        TO_DATE('2024-02-10', 'YYYY-MM-DD'), TO_DATE('2029-02-10', 'YYYY-MM-DD'), 2, 87654321);

INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, DATE_FAB, DATE_EXP, ID_FOURNISSEURS, ID_CLIENTS)
VALUES (1003, 'Souris Sans Fil', 200, 45.00, 'Électronique', 'Fournisseur ABC', 
        TO_DATE('2024-03-05', 'YYYY-MM-DD'), TO_DATE('2025-03-05', 'YYYY-MM-DD'), 1, 11223344);

INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, DATE_FAB, DATE_EXP, ID_FOURNISSEURS, ID_CLIENTS)
VALUES (1004, 'Clavier Mécanique', 75, 150.00, 'Informatique', 'Fournisseur Tech', 
        TO_DATE('2024-04-01', 'YYYY-MM-DD'), TO_DATE('2026-04-01', 'YYYY-MM-DD'), 3, 12345678);

-- =============================================================================
-- COMMIT ALL CHANGES
-- =============================================================================
COMMIT;

-- =============================================================================
-- VERIFICATION QUERIES
-- =============================================================================
-- Check all tables
SELECT 'FOURNISSEUR' AS TABLE_NAME, COUNT(*) AS ROW_COUNT FROM FOURNISSEUR
UNION ALL
SELECT 'CLIENT', COUNT(*) FROM CLIENT
UNION ALL
SELECT 'PRODUIT', COUNT(*) FROM PRODUIT;

-- Verify foreign key relationships
SELECT 
    P.REFERENCE,
    P.NOM AS PRODUIT_NOM,
    F.NOM AS FOURNISSEUR_NOM,
    C.NOM || ' ' || C.PRENOM AS CLIENT_NOM
FROM PRODUIT P
LEFT JOIN FOURNISSEUR F ON P.ID_FOURNISSEURS = F.ID_FOURNISSEUR
LEFT JOIN CLIENT C ON P.ID_CLIENTS = C.CIN
ORDER BY P.REFERENCE;

-- =============================================================================
-- END OF SCRIPT
-- =============================================================================

