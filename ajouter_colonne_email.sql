-- Script SQL pour ajouter la colonne EMAIL à la table EMPLOYE
-- Exécutez ce script dans votre base de données Oracle si la colonne n'existe pas encore

-- Vérifier si la colonne existe déjà (optionnel)
-- Si la colonne existe déjà, cette commande échouera, mais ce n'est pas grave

ALTER TABLE EMPLOYE ADD "EMAIL" VARCHAR2(100);

-- Ajouter un commentaire pour documenter la colonne
COMMENT ON COLUMN EMPLOYE."EMAIL" IS 'Adresse email unique pour chaque employé';

COMMIT;

