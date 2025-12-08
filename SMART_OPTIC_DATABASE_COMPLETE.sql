-- =============================================================================
-- SMART OPTIC - COMPLETE DATABASE SETUP SCRIPT
-- =============================================================================
-- This script creates all tables for the Smart Optic management system
-- Run this in Oracle SQL Developer with your user credentials
-- =============================================================================

-- =============================================================================
-- STEP 1: DROP EXISTING TABLES (if they exist)
-- =============================================================================
BEGIN
   EXECUTE IMMEDIATE 'DROP TABLE PRODUIT CASCADE CONSTRAINTS';
   EXCEPTION WHEN OTHERS THEN NULL;
END;
/
BEGIN
   EXECUTE IMMEDIATE 'DROP TABLE CLIENT CASCADE CONSTRAINTS';
   EXCEPTION WHEN OTHERS THEN NULL;
END;
/
BEGIN
   EXECUTE IMMEDIATE 'DROP TABLE FOURNISSEUR CASCADE CONSTRAINTS';
   EXCEPTION WHEN OTHERS THEN NULL;
END;
/
BEGIN
   EXECUTE IMMEDIATE 'DROP TABLE EMPLOYE CASCADE CONSTRAINTS';
   EXCEPTION WHEN OTHERS THEN NULL;
END;
/
BEGIN
   EXECUTE IMMEDIATE 'DROP TABLE SPONSORING CASCADE CONSTRAINTS';
   EXCEPTION WHEN OTHERS THEN NULL;
END;
/

-- =============================================================================
-- STEP 2: CREATE PARENT TABLES (No dependencies)
-- =============================================================================

-- 2.1 FOURNISSEUR TABLE (Suppliers)
-- =============================================================================
CREATE TABLE FOURNISSEUR (
    ID_FOURNISSEUR NUMBER PRIMARY KEY,
    NOM VARCHAR2(100) NOT NULL,
    ADRESSE VARCHAR2(200),
    EMAIL VARCHAR2(100),
    TELEPHONE VARCHAR2(20),
    TYPE_PRODUITS VARCHAR2(100),
    HISTORIQUE_LIVRAISONS VARCHAR2(500),
    IS_ACTIVE NUMBER(1) DEFAULT 1,
    CONSTRAINT CHK_FOURNISSEUR_ACTIVE CHECK (IS_ACTIVE IN (0, 1))
);

-- Add comment to table
COMMENT ON TABLE FOURNISSEUR IS 'Table des fournisseurs - Smart Optic';

-- 2.2 CLIENT TABLE (Customers)
-- =============================================================================
CREATE TABLE CLIENT (
    CIN NUMBER PRIMARY KEY,
    PRENOM VARCHAR2(100) NOT NULL,
    NOM VARCHAR2(100) NOT NULL,
    EMAIL VARCHAR2(100),
    TELEPHONE VARCHAR2(20),
    ADRESSE VARCHAR2(200),
    SEXE VARCHAR2(10),
    CONSTRAINT CHK_CLIENT_SEXE CHECK (SEXE IN ('homme', 'femme'))
);

COMMENT ON TABLE CLIENT IS 'Table des clients - Smart Optic';

-- 2.3 EMPLOYE TABLE (Employees)
-- =============================================================================
CREATE TABLE EMPLOYE (
    ID_EMPLOYE NUMBER PRIMARY KEY,
    NOM_EMPLOYE VARCHAR2(100) NOT NULL,
    PRENOM_EMPLOYE VARCHAR2(100),
    DATE_NAISSANCE DATE,
    DATE_EMBAUCHE DATE,
    ETAT_CIVIL VARCHAR2(50),
    POST VARCHAR2(100),
    SALAIRE NUMBER(10,2),
    NBRE_ENFANTS NUMBER,
    ANNEES_EXPERIENCE NUMBER,
    DIPLOME VARCHAR2(200),
    CONSTRAINT CHK_EMPLOYE_SALAIRE CHECK (SALAIRE >= 0)
);

COMMENT ON TABLE EMPLOYE IS 'Table des employés - Smart Optic';

-- 2.4 SPONSORING TABLE (Sponsors)
-- =============================================================================
CREATE TABLE SPONSORING (
    ID_SPONSOR NUMBER PRIMARY KEY,
    NOM_SPONSOR VARCHAR2(100) NOT NULL,
    EMAIL VARCHAR2(100),
    DATE_EMBAUCHE DATE,
    TYPE_SPONSOR VARCHAR2(50),
    DUREE_CONTRAT VARCHAR2(50),
    DATE_SPONSOR DATE,
    CONSTRAINT CHK_SPONSOR_TYPE CHECK (TYPE_SPONSOR IN ('Entreprise', 'Auto-entrepreneur', 'Particulier'))
);

COMMENT ON TABLE SPONSORING IS 'Table des sponsors - Smart Optic';

-- =============================================================================
-- STEP 3: CREATE CHILD TABLES (With dependencies)
-- =============================================================================

-- 3.1 PRODUIT TABLE (Products) - References FOURNISSEUR and CLIENT
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
    -- Constraints
    CONSTRAINT CHK_PRODUIT_QUANTITE CHECK (QUANTITE >= 0),
    CONSTRAINT CHK_PRODUIT_PRIX CHECK (PRIX >= 0),
    -- Foreign Keys with proper cascading
    CONSTRAINT FK_PRODUIT_FOURNISSEUR FOREIGN KEY (ID_FOURNISSEURS) 
        REFERENCES FOURNISSEUR(ID_FOURNISSEUR) ON DELETE SET NULL,
    CONSTRAINT FK_PRODUIT_CLIENT FOREIGN KEY (ID_CLIENTS) 
        REFERENCES CLIENT(CIN) ON DELETE SET NULL
);

COMMENT ON TABLE PRODUIT IS 'Table des produits - Smart Optic - Avec relations FK vers FOURNISSEUR et CLIENT';

-- =============================================================================
-- STEP 4: INSERT TEST DATA
-- =============================================================================

-- 4.1 FOURNISSEUR Data
-- =============================================================================
INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE)
VALUES (1, 'Optical Suppliers Inc', '15 Rue de la Vision, Paris', 'contact@opticalsuppliers.com', '+33123456789', 'Lunettes et Montures', '25 livraisons réussies', 1);

INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE)
VALUES (2, 'Lenses Pro', '42 Avenue des Opticiens, Lyon', 'info@lensespro.fr', '+33198765432', 'Lentilles de contact', '18 livraisons réussies', 1);

INSERT INTO FOURNISSEUR (ID_FOURNISSEUR, NOM, ADRESSE, EMAIL, TELEPHONE, TYPE_PRODUITS, HISTORIQUE_LIVRAISONS, IS_ACTIVE)
VALUES (3, 'Vision Equipment', '8 Boulevard Technologique, Marseille', 'sales@visionequip.fr', '+33155512345', 'Équipements optiques', '32 livraisons réussies', 1);

-- 4.2 CLIENT Data
-- =============================================================================
INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE)
VALUES (12345678, 'Ahmed', 'Ben Salah', 'ahmed.bensalah@email.tn', '20123456', '12 Avenue Habib Bourguiba, Tunis', 'homme');

INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE)
VALUES (87654321, 'Leila', 'Trabelsi', 'leila.trabelsi@email.tn', '25987654', '45 Rue de la Liberté, Sfax', 'femme');

INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE)
VALUES (11223344, 'Mohamed', 'Kacem', 'mohamed.kacem@email.tn', '22334455', '78 Avenue de la République, Sousse', 'homme');

INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE)
VALUES (99887766, 'Fatma', 'Mansour', 'fatma.mansour@email.tn', '28887766', '23 Rue des Jasmins, Monastir', 'femme');

-- 4.3 EMPLOYE Data
-- =============================================================================
INSERT INTO EMPLOYE (ID_EMPLOYE, NOM_EMPLOYE, PRENOM_EMPLOYE, DATE_NAISSANCE, DATE_EMBAUCHE, ETAT_CIVIL, POST, SALAIRE, NBRE_ENFANTS, ANNEES_EXPERIENCE, DIPLOME)
VALUES (1, 'Gharbi', 'Karim', TO_DATE('1990-05-15', 'YYYY-MM-DD'), TO_DATE('2020-01-10', 'YYYY-MM-DD'), 'Marié(e)', 'Opticien', 2500.00, 2, 5, 'Opticien');

INSERT INTO EMPLOYE (ID_EMPLOYE, NOM_EMPLOYE, PRENOM_EMPLOYE, DATE_NAISSANCE, DATE_EMBAUCHE, ETAT_CIVIL, POST, SALAIRE, NBRE_ENFANTS, ANNEES_EXPERIENCE, DIPLOME)
VALUES (2, 'Mejri', 'Sonia', TO_DATE('1992-08-22', 'YYYY-MM-DD'), TO_DATE('2021-03-15', 'YYYY-MM-DD'), 'Célibataire', 'Vendeur', 1800.00, 0, 3, 'Vendeur');

INSERT INTO EMPLOYE (ID_EMPLOYE, NOM_EMPLOYE, PRENOM_EMPLOYE, DATE_NAISSANCE, DATE_EMBAUCHE, ETAT_CIVIL, POST, SALAIRE, NBRE_ENFANTS, ANNEES_EXPERIENCE, DIPLOME)
VALUES (3, 'Ben Ali', 'Youssef', TO_DATE('1988-12-10', 'YYYY-MM-DD'), TO_DATE('2019-06-01', 'YYYY-MM-DD'), 'Marié(e)', 'Employé de stock', 1600.00, 1, 7, 'Employé de stock');

-- 4.4 SPONSORING Data
-- =============================================================================
INSERT INTO SPONSORING (ID_SPONSOR, NOM_SPONSOR, EMAIL, DATE_EMBAUCHE, TYPE_SPONSOR, DUREE_CONTRAT, DATE_SPONSOR)
VALUES (1, 'OptiFrance SA', 'contact@optifrance.fr', TO_DATE('2023-01-15', 'YYYY-MM-DD'), 'Entreprise', '2 Ans', TO_DATE('2023-01-15', 'YYYY-MM-DD'));

INSERT INTO SPONSORING (ID_SPONSOR, NOM_SPONSOR, EMAIL, DATE_EMBAUCHE, TYPE_SPONSOR, DUREE_CONTRAT, DATE_SPONSOR)
VALUES (2, 'Vision Plus', 'info@visionplus.tn', TO_DATE('2023-06-20', 'YYYY-MM-DD'), 'Auto-entrepreneur', '1 Ans', TO_DATE('2023-06-20', 'YYYY-MM-DD'));

-- 4.5 PRODUIT Data (with valid FK references)
-- =============================================================================
INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, DATE_FAB, DATE_EXP, ID_FOURNISSEURS, ID_CLIENTS)
VALUES (1001, 'Lunettes Ray-Ban Aviator', 50, 450.00, 'Lunettes de soleil', 'Optical Suppliers Inc', 
        TO_DATE('2024-01-15', 'YYYY-MM-DD'), TO_DATE('2029-01-15', 'YYYY-MM-DD'), 1, 12345678);

INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, DATE_FAB, DATE_EXP, ID_FOURNISSEURS, ID_CLIENTS)
VALUES (1002, 'Lentilles Acuvue Oasys', 200, 85.00, 'Lentilles de contact', 'Lenses Pro', 
        TO_DATE('2024-02-10', 'YYYY-MM-DD'), TO_DATE('2025-02-10', 'YYYY-MM-DD'), 2, 87654321);

INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, DATE_FAB, DATE_EXP, ID_FOURNISSEURS, ID_CLIENTS)
VALUES (1003, 'Monture Oakley Sport', 75, 320.00, 'Montures', 'Optical Suppliers Inc', 
        TO_DATE('2024-03-05', 'YYYY-MM-DD'), TO_DATE('2029-03-05', 'YYYY-MM-DD'), 1, 11223344);

INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, DATE_FAB, DATE_EXP, ID_FOURNISSEURS, ID_CLIENTS)
VALUES (1004, 'Réfractomètre Automatique', 5, 8500.00, 'Équipement optique', 'Vision Equipment', 
        TO_DATE('2024-04-01', 'YYYY-MM-DD'), TO_DATE('2034-04-01', 'YYYY-MM-DD'), 3, 99887766);

INSERT INTO PRODUIT (REFERENCE, NOM, QUANTITE, PRIX, CATEGORY, FOURNISSEURS, DATE_FAB, DATE_EXP, ID_FOURNISSEURS, ID_CLIENTS)
VALUES (1005, 'Lunettes de lecture +2.0', 120, 35.00, 'Lunettes de lecture', 'Optical Suppliers Inc', 
        TO_DATE('2024-05-12', 'YYYY-MM-DD'), TO_DATE('2027-05-12', 'YYYY-MM-DD'), 1, 12345678);

-- =============================================================================
-- STEP 5: COMMIT ALL CHANGES
-- =============================================================================
COMMIT;

-- =============================================================================
-- STEP 6: VERIFICATION QUERIES
-- =============================================================================

-- 6.1 Count records in each table
SELECT 'FOURNISSEUR' AS TABLE_NAME, COUNT(*) AS TOTAL_RECORDS FROM FOURNISSEUR
UNION ALL
SELECT 'CLIENT', COUNT(*) FROM CLIENT
UNION ALL
SELECT 'EMPLOYE', COUNT(*) FROM EMPLOYE
UNION ALL
SELECT 'SPONSORING', COUNT(*) FROM SPONSORING
UNION ALL
SELECT 'PRODUIT', COUNT(*) FROM PRODUIT
ORDER BY TABLE_NAME;

-- 6.2 Verify foreign key relationships
SELECT 
    P.REFERENCE,
    P.NOM AS PRODUIT,
    P.QUANTITE,
    P.PRIX || ' DT' AS PRIX,
    P.CATEGORY,
    F.NOM AS FOURNISSEUR,
    C.PRENOM || ' ' || C.NOM AS CLIENT
FROM PRODUIT P
LEFT JOIN FOURNISSEUR F ON P.ID_FOURNISSEURS = F.ID_FOURNISSEUR
LEFT JOIN CLIENT C ON P.ID_CLIENTS = C.CIN
ORDER BY P.REFERENCE;

-- 6.3 Display all tables structure
SELECT 'FOURNISSEUR TABLE' AS INFO FROM DUAL
UNION ALL SELECT '===================' FROM DUAL;
DESC FOURNISSEUR;

-- =============================================================================
-- STEP 7: CREATE INDEXES FOR PERFORMANCE (Optional)
-- =============================================================================
CREATE INDEX IDX_PRODUIT_FOURNISSEUR ON PRODUIT(ID_FOURNISSEURS);
CREATE INDEX IDX_PRODUIT_CLIENT ON PRODUIT(ID_CLIENTS);
CREATE INDEX IDX_CLIENT_EMAIL ON CLIENT(EMAIL);
CREATE INDEX IDX_FOURNISSEUR_EMAIL ON FOURNISSEUR(EMAIL);

-- =============================================================================
-- END OF SMART OPTIC DATABASE SETUP
-- =============================================================================
-- Database: SMART OPTIC
-- Created: 2024
-- Tables: FOURNISSEUR, CLIENT, EMPLOYE, SPONSORING, PRODUIT
-- Foreign Keys: PRODUIT -> FOURNISSEUR, PRODUIT -> CLIENT
-- =============================================================================

SELECT '✅ SMART OPTIC DATABASE SETUP COMPLETED SUCCESSFULLY!' AS STATUS FROM DUAL;

