#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QTextTableFormat>
#include <QTextCharFormat>
#include <QTextBlockFormat>
#include <QTextLength>

void MainWindow::on_exportPDF_clicked()
{
    // Demander à l'utilisateur où sauvegarder le fichier
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", 
                                                  QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), 
                                                  "Fichiers PDF (*.pdf)");
    
    if (fileName.isEmpty())
        return;
    
    // Créer un objet QPrinter pour générer le PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    
    // Créer un document texte pour le contenu
    QTextDocument doc;
    QTextCursor cursor(&doc);
    
    // Définir le style du titre
    QTextCharFormat titleFormat;
    titleFormat.setFontPointSize(16);
    titleFormat.setFontWeight(QFont::Bold);
    titleFormat.setForeground(Qt::darkBlue);
    
    // Ajouter le titre
    cursor.insertText("Liste des Produits\n", titleFormat);
    
    // Ajouter la date d'exportation
    QTextCharFormat dateFormat;
    dateFormat.setFontItalic(true);
    cursor.insertText("Exporté le: " + QDate::currentDate().toString("dd/MM/yyyy") + "\n\n", dateFormat);
    
    // Créer un tableau pour afficher les données
    QTextTableFormat tableFormat;
    tableFormat.setHeaderRowCount(1);
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setCellSpacing(0);
    tableFormat.setCellPadding(5);
    
    // Définir les largeurs de colonnes
    QVector<QTextLength> columnWidths;
    columnWidths << QTextLength(QTextLength::PercentageLength, 10);  // ID
    columnWidths << QTextLength(QTextLength::PercentageLength, 20); // Référence
    columnWidths << QTextLength(QTextLength::PercentageLength, 20); // Nom
    columnWidths << QTextLength(QTextLength::PercentageLength, 10); // Quantité
    columnWidths << QTextLength(QTextLength::PercentageLength, 15); // Prix
    columnWidths << QTextLength(QTextLength::PercentageLength, 25); // Fournisseur
    
    tableFormat.setColumnWidthConstraints(columnWidths);
    
    // Créer le tableau avec le nombre de colonnes nécessaires
    QTextTable *table = cursor.insertTable(1, 6, tableFormat);
    
    // Style pour l'en-tête du tableau
    QTextCharFormat headerFormat;
    headerFormat.setBackground(QColor(200, 220, 255));
    headerFormat.setFontWeight(QFont::Bold);
    
    // Remplir l'en-tête du tableau
    QTextTableCell headerCell;
    headerCell = table->cellAt(0, 0);
    headerCell.firstCursorPosition().insertText("ID", headerFormat);
    
    headerCell = table->cellAt(0, 1);
    headerCell.firstCursorPosition().insertText("Référence", headerFormat);
    
    headerCell = table->cellAt(0, 2);
    headerCell.firstCursorPosition().insertText("Nom", headerFormat);
    
    headerCell = table->cellAt(0, 3);
    headerCell.firstCursorPosition().insertText("Quantité", headerFormat);
    
    headerCell = table->cellAt(0, 4);
    headerCell.firstCursorPosition().insertText("Prix (DT)", headerFormat);
    
    headerCell = table->cellAt(0, 5);
    headerCell.firstCursorPosition().insertText("Fournisseur", headerFormat);
    
    // Récupérer les données de la base de données
    QSqlQuery query("SELECT ID, REFERENCE, NOM, QUANTITE, PRIX, FOURNISSEUR FROM PRODUITS ORDER BY NOM");
    
    // Style pour les cellules du tableau
    QTextCharFormat cellFormat;
    cellFormat.setFontPointSize(9);
    
    // Remplir le tableau avec les données
    int row = 1;
    while (query.next()) {
        // Ajouter une nouvelle ligne au tableau
        table->appendRows(1);
        
        // Remplir chaque cellule de la ligne
        for (int col = 0; col < 6; ++col) {
            QTextTableCell cell = table->cellAt(row, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            
            // Mettre en évidence les produits en faible quantité
            if (col == 3) { // Colonne quantité
                int quantite = query.value(col).toInt();
                if (quantite < 5) {
                    QTextCharFormat highlightFormat = cellFormat;
                    highlightFormat.setForeground(Qt::red);
                    cellCursor.setCharFormat(highlightFormat);
                } else {
                    cellCursor.setCharFormat(cellFormat);
                }
            } else {
                cellCursor.setCharFormat(cellFormat);
            }
            
            // Formater les nombres à virgule pour le prix
            if (col == 4) { // Colonne prix
                cellCursor.insertText(QString::number(query.value(col).toDouble(), 'f', 2));
            } else {
                cellCursor.insertText(query.value(col).toString());
            }
        }
        row++;
    }
    
    // Ajouter des informations de pied de page
    cursor.movePosition(QTextCursor::End);
    cursor.insertBlock();
    cursor.insertBlock();
    
    QTextCharFormat footerFormat;
    footerFormat.setFontItalic(true);
    footerFormat.setFontPointSize(8);
    
    cursor.insertText("Document généré par l'application de gestion optique - " + 
                     QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm"), 
                     footerFormat);
    
    // Imprimer le document dans le fichier PDF
    doc.print(&printer);
    
    // Afficher un message de confirmation
    QMessageBox::information(this, "Export réussi", 
                            "Le fichier a été exporté avec succès :\n" + fileName);
}

void MainWindow::exporterProduitEnPDF(int produitId)
{
    // Récupérer les informations du produit
    QSqlQuery query;
    query.prepare("SELECT * FROM PRODUITS WHERE ID = :id");
    query.bindValue(":id", produitId);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer les informations du produit");
        return;
    }
    
    // Demander à l'utilisateur où sauvegarder le fichier
    QString defaultName = QString("Produit_%1_%2.pdf")
                         .arg(query.value("REFERENCE").toString())
                         .arg(QDate::currentDate().toString("yyyyMMdd"));
    
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter la fiche produit", 
                                                  QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + 
                                                  "/" + defaultName, 
                                                  "Fichiers PDF (*.pdf)");
    
    if (fileName.isEmpty())
        return;
    
    // Créer un objet QPrinter pour générer le PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    
    // Créer un document texte pour le contenu
    QTextDocument doc;
    QTextCursor cursor(&doc);
    
    // Style pour le titre
    QTextCharFormat titleFormat;
    titleFormat.setFontPointSize(18);
    titleFormat.setFontWeight(QFont::Bold);
    titleFormat.setForeground(Qt::darkBlue);
    
    // Style pour les sous-titres
    QTextCharFormat subtitleFormat;
    subtitleFormat.setFontPointSize(12);
    subtitleFormat.setFontWeight(QFont::Bold);
    subtitleFormat.setForeground(Qt::darkBlue);
    
    // Style pour le texte normal
    QTextCharFormat normalFormat;
    normalFormat.setFontPointSize(10);
    
    // Style pour les libellés
    QTextCharFormat labelFormat;
    labelFormat.setFontWeight(QFont::Bold);
    
    // Ajouter le titre
    cursor.insertText("FICHE PRODUIT\n", titleFormat);
    
    // Ajouter une ligne de séparation
    cursor.insertHtml("<hr>");
    cursor.insertBlock();
    
    // Ajouter les informations de base
    cursor.insertText("Informations générales\n", subtitleFormat);
    
    // Créer un tableau pour les informations
    QTextTableFormat infoTableFormat;
    infoTableFormat.setCellSpacing(0);
    infoTableFormat.setCellPadding(5);
    infoTableFormat.setBorder(1);
    
    QTextTable *infoTable = cursor.insertTable(6, 2, infoTableFormat);
    
    // Remplir le tableau des informations
    QStringList labels = {"Référence", "Nom", "Quantité en stock", "Prix unitaire", "Fournisseur", "Type"};
    QStringList values = {
        query.value("REFERENCE").toString(),
        query.value("NOM").toString(),
        query.value("QUANTITE").toString(),
        QString::number(query.value("PRIX").toDouble(), 'f', 2) + " DT",
        query.value("FOURNISSEUR").toString(),
        query.value("TYPE").toString()
    };
    
    for (int i = 0; i < labels.size(); ++i) {
        QTextTableCell cell = infoTable->cellAt(i, 0);
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.setCharFormat(labelFormat);
        cellCursor.insertText(labels[i]);
        
        cell = infoTable->cellAt(i, 1);
        cellCursor = cell.firstCursorPosition();
        cellCursor.setCharFormat(normalFormat);
        cellCursor.insertText(values[i]);
    }
    
    // Ajouter une espace
    cursor.movePosition(QTextCursor::End);
    cursor.insertBlock();
    cursor.insertBlock();
    
    // Ajouter la date de génération
    cursor.insertText("Document généré le: " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm"), normalFormat);
    
    // Centrer le contenu
    QTextBlockFormat centerFormat;
    centerFormat.setAlignment(Qt::AlignCenter);
    cursor.mergeBlockFormat(centerFormat);
    
    // Imprimer le document dans le fichier PDF
    doc.print(&printer);
    
    // Afficher un message de confirmation
    QMessageBox::information(this, "Export réussi", 
                            "La fiche produit a été exportée avec succès :\n" + fileName);
}
