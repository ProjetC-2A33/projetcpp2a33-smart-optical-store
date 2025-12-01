-- Script SQL pour ajouter la colonne MOT_DE_PASSE_EMPLOYE à la table EMPLOYE
-- Exécutez ce script dans votre base de données Oracle si la colonne n'existe pas encore

-- Vérifier si la colonne existe déjà (optionnel, Oracle peut donner une erreur si elle existe)
-- ALTER TABLE EMPLOYE ADD "MOT_DE_PASSE_EMPLOYE" VARCHAR2(255);

-- Si la colonne existe déjà, cette commande échouera, mais ce n'est pas grave
-- L'application créera automatiquement la colonne si nécessaire

ALTER TABLE EMPLOYE ADD "MOT_DE_PASSE_EMPLOYE" VARCHAR2(255);

-- Ajouter un commentaire pour documenter la colonne
COMMENT ON COLUMN EMPLOYE."MOT_DE_PASSE_EMPLOYE" IS 'Mot de passe unique pour chaque employé, utilisé pour l''authentification';

COMMIT;

