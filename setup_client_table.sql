-- Script SQL pour créer la table CLIENT
-- Compatible avec Oracle Database
-- 
-- IMPORTANT: Run this with YOUR Oracle user in SQL Developer
-- (gestion_user, ghaith, or system - depending on your setup)

-- Supprimer la table si elle existe (optionnel - uncomment if needed)
-- DROP TABLE CLIENT CASCADE CONSTRAINTS;

-- Créer la table CLIENT
CREATE TABLE CLIENT (
    CIN NUMBER PRIMARY KEY,
    PRENOM VARCHAR2(100) NOT NULL,
    NOM VARCHAR2(100) NOT NULL,
    EMAIL VARCHAR2(100),
    TELEPHONE VARCHAR2(20),
    ADRESSE VARCHAR2(200),
    SEXE VARCHAR2(10)
);

-- Insérer quelques données de test
INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE)
VALUES (12345678, 'Ahmed', 'Ben Ali', 'ahmed.benali@email.com', '20123456', '12 Rue Habib Bourguiba, Tunis', 'homme');

INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE)
VALUES (87654321, 'Fatma', 'Trabelsi', 'fatma.trabelsi@email.com', '25987654', '45 Avenue de la Liberté, Sfax', 'femme');

INSERT INTO CLIENT (CIN, PRENOM, NOM, EMAIL, TELEPHONE, ADRESSE, SEXE)
VALUES (11223344, 'Mohamed', 'Saidi', 'mohamed.saidi@email.com', '22334455', '78 Rue de la République, Sousse', 'homme');

COMMIT;

-- Vérifier l'insertion
SELECT * FROM CLIENT;

