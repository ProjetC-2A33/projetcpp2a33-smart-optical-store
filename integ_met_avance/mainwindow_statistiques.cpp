#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QSqlQuery>
#include <QMessageBox>

void MainWindow::afficherStatistiques()
{
    // Création du graphique
    QChart *chart = new QChart();
    chart->setTitle("Statistiques des produits par type");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Requête pour récupérer les données
    QSqlQuery query("SELECT TYPE, COUNT(*) as count, SUM(PRIX * QUANTITE) as total FROM PRODUITS GROUP BY TYPE");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des statistiques : " + query.lastError().text());
        return;
    }

    // Création des séries pour le graphique
    QBarSeries *series = new QBarSeries();
    QPieSeries *pieSeries = new QPieSeries();
    QStringList categories;
    QBarSet *set = new QBarSet("Valeur totale");

    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        double total = query.value(2).toDouble();

        *set << total;
        categories << type;
        
        // Ajout au graphique circulaire
        pieSeries->append(type + " (" + QString::number(count) + ")", total);
    }

    // Configuration du graphique en barres
    series->append(set);
    chart->addSeries(series);
    
    // Configuration des axes
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Valeur totale (DT)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Configuration du graphique circulaire
    pieSeries->setLabelsVisible();
    pieSeries->setLabelsPosition(QPieSlice::LabelOutside);
    
    // Création d'une vue pour chaque graphique
    QChartView *barChartView = new QChartView(chart);
    barChartView->setRenderHint(QPainter::Antialiasing);
    
    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition par type");
    pieChart->setAnimationOptions(QChart::SeriesAnimations);
    
    QChartView *pieChartView = new QChartView(pieChart);
    pieChartView->setRenderHint(QPainter::Antialiasing);

    // Création d'un layout pour afficher les deux graphiques
    QWidget *statsWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(statsWidget);
    layout->addWidget(barChartView);
    layout->addWidget(pieChartView);
    
    // Affichage dans une boîte de dialogue
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des produits");
    dialog->setLayout(layout);
    dialog->resize(800, 800);
    dialog->exec();
}

void MainWindow::mettreAJourStatistiques()
{
    // Mettre à jour les statistiques en temps réel
    QSqlQuery query("SELECT COUNT(*) as total, SUM(QUANTITE) as quantite_totale, "
                   "SUM(PRIX * QUANTITE) as valeur_totale FROM PRODUITS");
    
    if (query.next()) {
        int totalProduits = query.value(0).toInt();
        int quantiteTotale = query.value(1).toInt();
        double valeurTotale = query.value(2).toDouble();
        
        ui->label_total_produits->setText(QString::number(totalProduits));
        ui->label_quantite_totale->setText(QString::number(quantiteTotale));
        ui->label_valeur_totale->setText(QString::number(valeurTotale, 'f', 2) + " DT");
        
        // Vérifier les stocks faibles
        verifierStocksFaibles();
    }
}

void MainWindow::verifierStocksFaibles()
{
    // Vérifier les produits en faible quantité
    QSqlQuery query("SELECT NOM, QUANTITE FROM PRODUITS WHERE QUANTITE < 5 ORDER BY QUANTITE ASC");
    
    QStringList produitsFaibleStock;
    while (query.next()) {
        QString nom = query.value(0).toString();
        int quantite = query.value(1).toInt();
        produitsFaibleStock << QString("%1 (il en reste %2)").arg(nom).arg(quantite);
    }
    
    if (!produitsFaibleStock.isEmpty()) {
        // Afficher une notification
        QString message = "Les produits suivants sont en faible quantité :\n" + produitsFaibleStock.join("\n");
        QMessageBox::warning(this, "Stock faible", message);
        
        // Envoyer une notification par email si configuré
        if (ui->checkBox_notifications->isChecked()) {
            envoyerNotificationStockFaible(produitsFaibleStock);
        }
    }
}

void MainWindow::on_btnExporterStats_clicked()
{
    // Exporter les statistiques au format PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter les statistiques", 
                                                   "", "Fichiers PDF (*.pdf)");
    
    if (fileName.isEmpty())
        return;
    
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMarginsF(30, 30, 30, 30));
    
    QPainter painter(&writer);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // En-tête
    QFont font = painter.font();
    font.setPointSize(14);
    font.setBold(true);
    painter.setFont(font);
    
    painter.drawText(QRect(0, 0, writer.width(), 50), Qt::AlignCenter, "Statistiques des produits");
    
    // Date du rapport
    font.setPointSize(10);
    font.setBold(false);
    painter.setFont(font);
    painter.drawText(QRect(0, 60, writer.width(), 30), 
                    Qt::AlignRight, 
                    "Généré le " + QDate::currentDate().toString("dd/MM/yyyy"));
    
    // Récupération des données
    QSqlQuery query("SELECT TYPE, COUNT(*) as count, SUM(QUANTITE) as quantite, "
                   "SUM(PRIX * QUANTITE) as total FROM PRODUITS GROUP BY TYPE");
    
    // Tableau des données
    int y = 150;
    int rowHeight = 30;
    int col1 = 50;
    int col2 = 200;
    int col3 = 350;
    int col4 = 500;
    
    // En-têtes du tableau
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(col1, y, "Type de produit");
    painter.drawText(col2, y, "Nombre");
    painter.drawText(col3, y, "Quantité");
    painter.drawText(col4, y, "Valeur totale");
    
    // Lignes de séparation
    painter.drawLine(50, y + 10, writer.width() - 50, y + 10);
    y += 30;
    
    // Données
    font.setBold(false);
    painter.setFont(font);
    
    double totalGeneral = 0;
    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        int quantite = query.value(2).toInt();
        double total = query.value(3).toDouble();
        totalGeneral += total;
        
        painter.drawText(col1, y, type);
        painter.drawText(col2, y, QString::number(count));
        painter.drawText(col3, y, QString::number(quantite));
        painter.drawText(col4, y, QString::number(total, 'f', 2) + " DT");
        
        y += rowHeight;
    }
    
    // Ligne de total
    y += 10;
    painter.drawLine(50, y, writer.width() - 50, y);
    y += 20;
    
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(col1, y, "Total général");
    painter.drawText(col4, y, QString::number(totalGeneral, 'f', 2) + " DT");
    
    // Pied de page
    y = writer.height() - 50;
    font.setPointSize(8);
    font.setItalic(true);
    painter.setFont(font);
    painter.drawText(QRect(0, y, writer.width(), 30), 
                    Qt::AlignCenter, 
                    "Document généré par l'application de gestion optique - Tous droits réservés");
    
    painter.end();
    
    QMessageBox::information(this, "Export réussi", 
                            "Les statistiques ont été exportées avec succès dans :\n" + fileName);
}
