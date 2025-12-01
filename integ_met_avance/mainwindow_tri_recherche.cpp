#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void MainWindow::on_lineEdit_recherche_textChanged(const QString &text)
{
    QString recherche = text.trimmed();
    
    if (recherche.isEmpty()) {
        afficherTousProduits();
        return;
    }
    
    // Préparer la requête de recherche
    QString requete = "SELECT * FROM PRODUITS WHERE ";
    QStringList conditions;
    
    // Ajouter des conditions de recherche pour chaque champ
    conditions << "REFERENCE LIKE :recherche";
    conditions << "NOM LIKE :recherche";
    conditions << "FOURNISSEUR LIKE :recherche";
    conditions << "TYPE LIKE :recherche";
    
    // Pour la recherche numérique (ID, quantité, prix)
    bool ok;
    recherche.toInt(&ok);
    if (ok) {
        conditions << "ID = " + recherche;
        conditions << "QUANTITE = " + recherche;
    }
    
    recherche.toDouble(&ok);
    if (ok) {
        conditions << "PRIX = " + recherche;
    }
    
    // Combiner toutes les conditions avec OR
    requete += conditions.join(" OR ");
    
    // Préparer et exécuter la requête
    QSqlQuery query;
    query.prepare(requete);
    query.bindValue(":recherche", "%" + recherche + "%");
    
    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche:" << query.lastError().text();
        return;
    }
    
    // Afficher les résultats dans le modèle
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(query);
    
    // Mettre à jour les en-têtes
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Référence"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, tr("Fournisseur"));
    model->setHeaderData(6, Qt::Horizontal, tr("Type"));
    
    // Appliquer le modèle à la table
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    QString orderBy;
    bool isAscending = true;
    
    // Déterminer le champ de tri et l'ordre
    switch (index) {
    case 1: // A-Z (Nom croissant)
        orderBy = "NOM ASC";
        break;
    case 2: // Z-A (Nom décroissant)
        orderBy = "NOM DESC";
        break;
    case 3: // Quantité croissante
        orderBy = "QUANTITE ASC";
        break;
    case 4: // Quantité décroissante
        orderBy = "QUANTITE DESC";
        break;
    case 5: // Prix croissant
        orderBy = "PRIX ASC";
        break;
    case 6: // Prix décroissant
        orderBy = "PRIX DESC";
        break;
    default:
        // Par défaut, trier par ID
        orderBy = "ID ASC";
    }
    
    // Mettre à jour la requête avec le tri sélectionné
    QString requete = "SELECT * FROM PRODUITS";
    
    // Si une recherche est en cours, ajouter la condition WHERE
    QString recherche = ui->lineEdit_recherche->text().trimmed();
    if (!recherche.isEmpty()) {
        requete += " WHERE (REFERENCE LIKE '%" + recherche + "%' OR "
                 + "NOM LIKE '%" + recherche + "%' OR "
                 + "FOURNISSEUR LIKE '%" + recherche + "%' OR "
                 + "TYPE LIKE '%" + recherche + "%')";
    }
    
    // Ajouter l'ordre de tri
    requete += " ORDER BY " + orderBy;
    
    // Exécuter la requête
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    if (!model) {
        model = new QSqlQueryModel(this);
    }
    
    model->setQuery(requete);
    
    // Vérifier les erreurs
    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors du tri:" << model->lastError().text();
        return;
    }
    
    // Mettre à jour les en-têtes
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Référence"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, tr("Fournisseur"));
    model->setHeaderData(6, Qt::Horizontal, tr("Type"));
    
    // Appliquer le modèle à la table
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_tableView_headerClicked(int logicalIndex)
{
    static QString lastColumn = "";
    static bool ascending = true;
    
    QString columnName;
    
    // Déterminer le nom de la colonne cliquée
    switch (logicalIndex) {
    case 0: columnName = "ID"; break;
    case 1: columnName = "REFERENCE"; break;
    case 2: columnName = "NOM"; break;
    case 3: columnName = "QUANTITE"; break;
    case 4: columnName = "PRIX"; break;
    case 5: columnName = "FOURNISSEUR"; break;
    case 6: columnName = "TYPE"; break;
    default: return;
    }
    
    // Inverser l'ordre si la même colonne est cliquée à nouveau
    if (lastColumn == columnName) {
        ascending = !ascending;
    } else {
        lastColumn = columnName;
        ascending = true;
    }
    
    // Mettre à jour le tri dans le modèle
    QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel*>(ui->tableView->model());
    
    if (!proxyModel) {
        // Si le modèle n'est pas un proxy, en créer un nouveau
        QSqlQueryModel *sourceModel = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
        if (!sourceModel) return;
        
        proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(sourceModel);
        ui->tableView->setModel(proxyModel);
    }
    
    // Appliquer le tri
    proxyModel->sort(logicalIndex, ascending ? Qt::AscendingOrder : Qt::DescendingOrder);
}

void MainWindow::on_btnFiltrer_clicked()
{
    // Récupérer les valeurs des filtres
    QString type = ui->comboBox_filtre_type->currentText();
    QString fournisseur = ui->comboBox_filtre_fournisseur->currentText();
    double prixMin = ui->doubleSpinBox_prix_min->value();
    double prixMax = ui->doubleSpinBox_prix_max->value();
    
    // Construire la requête de base
    QString requete = "SELECT * FROM PRODUITS WHERE 1=1";
    
    // Ajouter les conditions de filtre
    if (type != "Tous") {
        requete += " AND TYPE = '" + type + "'";
    }
    
    if (fournisseur != "Tous") {
        requete += " AND FOURNISSEUR = '" + fournisseur + "'";
    }
    
    if (prixMin > 0) {
        requete += " AND PRIX >= " + QString::number(prixMin);
    }
    
    if (prixMax > 0 && prixMax >= prixMin) {
        requete += " AND PRIX <= " + QString::number(prixMax);
    }
    
    // Appliquer le tri actuel
    int indexTri = ui->comboBox_2->currentIndex();
    if (indexTri > 0) {
        on_comboBox_2_currentIndexChanged(indexTri);
    } else {
        // Exécuter la requête
        QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
        if (!model) {
            model = new QSqlQueryModel(this);
        }
        
        model->setQuery(requete);
        
        // Vérifier les erreurs
        if (model->lastError().isValid()) {
            qDebug() << "Erreur lors du filtrage:" << model->lastError().text();
            return;
        }
        
        // Mettre à jour les en-têtes
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Référence"));
        model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, tr("Quantité"));
        model->setHeaderData(4, Qt::Horizontal, tr("Prix"));
        model->setHeaderData(5, Qt::Horizontal, tr("Fournisseur"));
        model->setHeaderData(6, Qt::Horizontal, tr("Type"));
        
        // Appliquer le modèle à la table
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }
}

void MainWindow::on_btnReinitialiserFiltres_clicked()
{
    // Réinitialiser les contrôles de filtre
    ui->comboBox_filtre_type->setCurrentIndex(0);
    ui->comboBox_filtre_fournisseur->setCurrentIndex(0);
    ui->doubleSpinBox_prix_min->setValue(0);
    ui->doubleSpinBox_prix_max->setValue(0);
    
    // Réafficher tous les produits
    afficherTousProduits();
}
