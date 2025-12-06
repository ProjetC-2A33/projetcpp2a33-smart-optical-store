#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QIntValidator>
#include <QSqlQueryModel>
#include "connection.h"
#include <QTimer>
#include <QLineEdit>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QDateTime>
#include <QFileInfo>
#include <QDir>
#include <QPageSize>
#include <QPageLayout>
#include <QFont>
#include <QPen>

MainWindow::MainWindow(QWidget *parent)
: QDialog(parent), ui(new Ui::MainWindow),
  networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    // Add CIN validator
    ui->cin_c->setValidator(new QIntValidator(0, 99999999, this));

    // Connect buttons to slots
    connect(ui->ajouter_c, &QPushButton::clicked, this, &MainWindow::on_pb_ajouter_clicked);
    connect(ui->supp_c, &QPushButton::clicked, this, &MainWindow::on_pb_supprimer_clicked);
    connect(ui->modif_c, &QPushButton::clicked, this, &MainWindow::on_pb_modifier_2_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pb_pdf_clicked);
    connect(ui->annuler_c, &QPushButton::clicked, this, &MainWindow::on_refrech_pb_clicked);
    connect(ui->tableWidget_c, &QTableWidget::cellClicked, this, &MainWindow::on_tableWidget_c_cellClicked);
    connect(ui->comboBox_tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
               this, &MainWindow::on_comboBox_tri_currentIndexChanged);
    connect(ui->search, &QLineEdit::textChanged, this, &MainWindow::on_search_textChanged);

    Connection c;
      if (!c.createconnect()) {
          QMessageBox::critical(this, "Database Error", "Could not open database connection");
          return;
      }
    refreshTable();
    connect(ui->pushButton_envoyerSMS, &QPushButton::clicked,
               this, &MainWindow::on_pushButton_envoyerSMS_clicked);


       connect(networkManager, &QNetworkAccessManager::finished,
               this, &MainWindow::onSMSReply);

    ui->stats->setText("Cliquez sur 'Statistiques' pour afficher les données");
    QTimer *autoRefreshTimer = new QTimer(this);
    connect(autoRefreshTimer, &QTimer::timeout, this, &MainWindow::updateStatsLabel);
    autoRefreshTimer->start(5000); // Refresh every 5 seconds

    // Initial stats display
    updateStatsLabel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString cin = ui->cin_c->text().trimmed();
    QString nom = ui->nom_c->text().trimmed();
    QString prenom = ui->prenom_c->text().trimmed();
    QString adresse = ui->adr_c->text().trimmed();
    QString tel = ui->tel_c->text().trimmed();
    QString email = ui->email_c->text().trimmed();
    QString sexe = ui->comboBoxsexe_c->currentText();

    // FIX: Use the correct combo box name from UI file
    QString statutText = ui->comboBoxSTATUTFIDELITE_c->currentText();

    bool statutFidelite = (statutText == "1");
    QString historique = "";

    if (cin.isEmpty() || nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() ||
        tel.isEmpty() || email.isEmpty() || sexe.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (cin.length() != 8) {
        QMessageBox::warning(this, "CIN invalide", "Le CIN doit contenir exactement 8 chiffres.");
        return;
    }

    // Use Clients class methods to check existence
    if (Clients::cinExiste(cin)) {
        QMessageBox::warning(this, "CIN existant", "Ce CIN existe déjà dans la base de données.");
        return;
    }

    if (Clients::emailExiste(email)) {
        QMessageBox::warning(this, "Email existant", "Cet email existe déjà dans la base de données.");
        return;
    }

    // Create and add client using Clients class
    Clients client(cin, nom, prenom, adresse, tel, email, sexe, historique, statutFidelite);

    if (client.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
        refreshTable();
        on_refrech_pb_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}


void MainWindow::on_pb_supprimer_clicked()
{
    QString cin = ui->cin_c->text().trimmed();

    if (cin.isEmpty()) {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un client à supprimer.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation de suppression",
                                  "Êtes-vous sûr de vouloir supprimer le client CIN: " + cin + " ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Clients::supprimer(cin)) {
            QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
            refreshTable();
            on_refrech_pb_clicked();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression du client.");
        }
    }
}

void MainWindow::on_pb_modifier_2_clicked()
{
    QString cin = ui->cin_c->text().trimmed();
    QString nom = ui->nom_c->text().trimmed();
    QString prenom = ui->prenom_c->text().trimmed();
    QString adresse = ui->adr_c->text().trimmed();
    QString tel = ui->tel_c->text().trimmed();
    QString email = ui->email_c->text().trimmed();
    QString sexe = ui->comboBoxsexe_c->currentText();

    // FIX: Use the correct combo box name from UI file
    QString statutText = ui->comboBoxSTATUTFIDELITE_c->currentText();

    bool statutFidelite = (statutText == "1");
    QString historique = "";

    if (cin.isEmpty()) {
        QMessageBox::warning(this, "Modification", "Veuillez sélectionner un client à modifier.");
        return;
    }

    if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() ||
        tel.isEmpty() || email.isEmpty() || sexe.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    // Use Clients class method to check email
    if (Clients::emailExiste(email, cin)) {
        QMessageBox::warning(this, "Email existant", "Cet email est déjà utilisé par un autre client.");
        return;
    }

    // Create and modify client using Clients class
    Clients client(cin, nom, prenom, adresse, tel, email, sexe, historique, statutFidelite);

    if (client.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès !");
        refreshTable();
        on_refrech_pb_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client.");
    }
}
void MainWindow::on_tab_clients_clicked(const QModelIndex &index)
{
    // Since you're using tableWidget_c instead of tab_clients, you need to implement this differently
    // This will need to be adapted based on how you want to handle selection in QTableWidget
}

void MainWindow::refreshTable()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT CIN, NOM, PRENOM, EMAIL, tel, ADRESSE, SEXE, STATUTFIDELITE FROM GESTIONCL2");

    if (model->lastError().isValid()) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les données des clients: " + model->lastError().text());
        delete model;
        return;
    }

    // Set headers
    model->setHeaderData(0, Qt::Horizontal, tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, tr("Adresse"));
    model->setHeaderData(6, Qt::Horizontal, tr("Sexe"));
    model->setHeaderData(7, Qt::Horizontal, tr("STATUTFIDELITE"));
    model->setHeaderData(8, Qt::Horizontal, tr("Nom Employé"));

    // For QTableWidget, you need to populate it manually
    ui->tableWidget_c->setRowCount(model->rowCount());
    ui->tableWidget_c->setColumnCount(model->columnCount());

    // Set headers for QTableWidget
    QStringList headers;
    headers << "CIN" << "Nom" << "Prénom" << "Email" << "Téléphone" << "Adresse" << "Sexe" << "STATUTFIDELITE" << "Nom Employé";
    ui->tableWidget_c->setHorizontalHeaderLabels(headers);

    // Populate data
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget_c->setItem(row, col, item);
        }
    }

    delete model;
}

void MainWindow::refreshTable(QSqlQueryModel *model)
{
    if (!model) return;

    ui->tableWidget_c->setRowCount(model->rowCount());
    ui->tableWidget_c->setColumnCount(model->columnCount());

    QStringList headers;
    headers << "CIN" << "Nom" << "Prénom" << "Email" << "Téléphone" << "Adresse" << "Sexe" << "STATUTFIDELITE" << "Nom Employé";
    ui->tableWidget_c->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget_c->setItem(row, col, item);
        }
    }
}

void MainWindow::on_refrech_pb_clicked()
{
    ui->cin_c->clear();
    ui->nom_c->clear();
    ui->prenom_c->clear();
    ui->adr_c->clear();
    ui->tel_c->clear();
    ui->email_c->clear();
    ui->comboBoxsexe_c->setCurrentIndex(0);

    // FIX: Use the correct combo box name from UI file
    ui->comboBoxSTATUTFIDELITE_c->setCurrentIndex(0);

    // Clear table selection if needed
    ui->tableWidget_c->clearSelection();
}
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString critere = arg1.trimmed();

    if (critere.isEmpty()) {
        refreshTable();
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString queryStr = "SELECT CIN, NOM, PRENOM, EMAIL, tel, ADRESSE, SEXE, STATUTFIDELITE FROM GESTIONCL2 "
                       "WHERE CIN LIKE '%" + critere + "%' OR "
                       "NOM LIKE '%" + critere + "%' OR "
                       "PRENOM LIKE '%" + critere + "%' OR "
                       "EMAIL LIKE '%" + critere + "%'";

    model->setQuery(queryStr);

    if (model->lastError().isValid()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche: " + model->lastError().text());
        delete model;
        return;
    }

    refreshTable(model);
}


void MainWindow::on_pb_pdf_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    if (!filePath.isEmpty()) {
        // Implement PDF export functionality here
        QMessageBox::information(this, "PDF", "Export PDF - À implémenter");
    }
}

void MainWindow::handleMessageBoxResult(int result)
{
    if (result == QMessageBox::Cancel) {
        // Handle cancel action
    }
}

// Other methods - implement as needed
void MainWindow::on_Imprimer_clicked() {
    QMessageBox::information(this, "Impression", "Fonction d'impression - À implémenter");
}

void MainWindow::on_pb_word_clicked() {
    QMessageBox::information(this, "Word", "Export Word - À implémenter");
}


void MainWindow::on_pushButton_clicked() {
    // Search functionality - already handled by on_lineEdit_textChanged
    QMessageBox::information(this, "Recherche", "Recherche activée");
}



void MainWindow::on_tableWidget_c_cellClicked(int row, int column)
{
    // Get data from the clicked row
    QString cin = ui->tableWidget_c->item(row, 0)->text();
    QString nom = ui->tableWidget_c->item(row, 1)->text();
    QString prenom = ui->tableWidget_c->item(row, 2)->text();
    QString email = ui->tableWidget_c->item(row, 3)->text();
    QString tel = ui->tableWidget_c->item(row, 4)->text();
    QString adresse = ui->tableWidget_c->item(row, 5)->text();
    QString sexe = ui->tableWidget_c->item(row, 6)->text();
    QString statutFidelite = ui->tableWidget_c->item(row, 7)->text();

    // Populate line edits
    ui->cin_c->setText(cin);
    ui->nom_c->setText(nom);
    ui->prenom_c->setText(prenom);
    ui->email_c->setText(email);
    ui->tel_c->setText(tel);
    ui->adr_c->setText(adresse);

    // Set sexe in combo box
    int sexeIndex = ui->comboBoxsexe_c->findText(sexe);
    if (sexeIndex != -1) {
        ui->comboBoxsexe_c->setCurrentIndex(sexeIndex);
    } else {
        ui->comboBoxsexe_c->setCurrentIndex(0); // Default to first item if not found
    }

    // Set STATUTFIDELITE in combo box
    int statutIndex = ui->comboBoxSTATUTFIDELITE_c->findText(statutFidelite);
    if (statutIndex != -1) {
        ui->comboBoxSTATUTFIDELITE_c->setCurrentIndex(statutIndex);
    } else {
        ui->comboBoxSTATUTFIDELITE_c->setCurrentIndex(0); // Default to first item if not found
    }
}

void MainWindow::on_comboBox_tri_currentIndexChanged(int index)
{
    if (index == 0) return; // Skip the "Trier par" placeholder

    QString critere = ui->comboBox_tri->currentText();
    QSqlQueryModel *model = Clients::trierParCritere(critere, "");

    if (model) {
        refreshTable(model);
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors du tri des données.");
    }
}
void MainWindow::on_search_textChanged(const QString &text)
{
    QString searchText = text.trimmed();

    if (searchText.isEmpty()) {
        // If search is empty, show all data
        refreshTable();
        return;
    }

    // Use the Clients class search method
    QSqlQueryModel *model = Clients::rechercher(searchText);

    if (model && model->rowCount() > 0) {
        refreshTable(model);
    } else {
        // If no results found, show empty table
        ui->tableWidget_c->setRowCount(0);
        if (model) {
            delete model;
        }
    }
}


void MainWindow::on_stats_clicked()
{
    updateStatsLabel();
}
void MainWindow::updateStatsLabel()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        // Create high-quality error pixmap
        QPixmap errorPixmap(300, 300);
        errorPixmap.fill(QColor(255, 240, 240)); // Light red background
        QPainter painter(&errorPixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        painter.setPen(QColor(231, 76, 60)); // Red
        painter.setFont(QFont("Arial", 14, QFont::Bold));
        painter.drawText(QRect(0, 100, 300, 50), Qt::AlignCenter, "❌");
        painter.setFont(QFont("Arial", 10, QFont::Normal));
        painter.drawText(QRect(0, 150, 300, 100), Qt::AlignCenter,
                         "Base de données\nnon connectée");
        ui->statslabel->setPixmap(errorPixmap.scaled(ui->statslabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT SEXE, COUNT(*) FROM GESTIONCL2 GROUP BY SEXE");

    int hommeCount = 0;
    int femmeCount = 0;

    if (query.exec()) {
        while (query.next()) {
            QString sexe = query.value(0).toString().toLower();
            int count = query.value(1).toInt();

            if (sexe == "homme") {
                hommeCount = count;
            } else if (sexe == "femme") {
                femmeCount = count;
            }
        }
    } else {
        // Create high-quality error pixmap
        QPixmap errorPixmap(300, 300);
        errorPixmap.fill(QColor(255, 240, 240));
        QPainter painter(&errorPixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        painter.setPen(QColor(231, 76, 60));
        painter.setFont(QFont("Arial", 14, QFont::Bold));
        painter.drawText(QRect(0, 100, 300, 50), Qt::AlignCenter, "❌");
        painter.setFont(QFont("Arial", 10, QFont::Normal));
        painter.drawText(QRect(0, 150, 300, 100), Qt::AlignCenter,
                         "Erreur de requête");
        ui->statslabel->setPixmap(errorPixmap.scaled(ui->statslabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
        return;
    }

    int total = hommeCount + femmeCount;

    if (total == 0) {
        // Create high-quality empty state
        QPixmap emptyPixmap(300, 300);
        emptyPixmap.fill(QColor(248, 249, 250));
        QPainter painter(&emptyPixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        // Draw empty pie with gradient
        QRadialGradient gradient(150, 150, 140);
        gradient.setColorAt(0, QColor(230, 230, 230));
        gradient.setColorAt(1, QColor(200, 200, 200));
        painter.setBrush(gradient);
        painter.setPen(QColor(150, 150, 150));
        painter.drawEllipse(50, 50, 200, 200);

        // Draw text
        painter.setPen(QColor(120, 120, 120));
        painter.setFont(QFont("Arial", 16, QFont::Bold));
        painter.drawText(QRect(50, 50, 200, 200), Qt::AlignCenter, "0");

        ui->statslabel->setPixmap(emptyPixmap.scaled(ui->statslabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
        return;
    }

    double pourcHommes = hommeCount * 100.0 / total;
    double pourcFemmes = femmeCount * 100.0 / total;

    // Create HIGH QUALITY pixmap - larger for better resolution
    int size = 400; // Increased size for better quality
    QPixmap pixmap(size, size);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    // Enable all rendering hints for best quality
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    //painter.setRenderHint(QPainter::HighQualityAntialiasing, true);

    // Draw pie chart with shadow effect
    QRectF pieRect(80, 80, size - 160, size - 160); // Centered with padding

    // Create gradient for homme slice
    QRadialGradient hommeGradient(pieRect.center(), pieRect.width()/2);
    hommeGradient.setColorAt(0, QColor(52, 152, 219).lighter(120));
    hommeGradient.setColorAt(1, QColor(52, 152, 219).darker(120));

    // Create gradient for femme slice
    QRadialGradient femmeGradient(pieRect.center(), pieRect.width()/2);
    femmeGradient.setColorAt(0, QColor(231, 76, 60).lighter(120));
    femmeGradient.setColorAt(1, QColor(231, 76, 60).darker(120));

    // Draw homme slice with gradient
    painter.setBrush(hommeGradient);
    painter.setPen(QPen(QColor(52, 152, 219).darker(150), 1));
    painter.drawPie(pieRect, 0, 16 * 360 * (pourcHommes / 100.0));

    // Draw femme slice with gradient
    painter.setBrush(femmeGradient);
    painter.setPen(QPen(QColor(231, 76, 60).darker(150), 1));
    painter.drawPie(pieRect, 16 * 360 * (pourcHommes / 100.0), 16 * 360 * (pourcFemmes / 100.0));

    // Draw pie outline with thicker line
    painter.setPen(QPen(QColor(80, 80, 80), 2));
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(pieRect);

    // Draw total in center - large and prominent
    painter.setPen(QColor(44, 62, 80));
    QFont totalFont("Arial", 28, QFont::Bold);
    totalFont.setStyleStrategy(QFont::PreferAntialias);
    painter.setFont(totalFont);

    // Draw background for total number
    painter.setBrush(QColor(255, 255, 255, 200)); // Semi-transparent white
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(pieRect.center(), 45, 45);

    // Draw total number
    painter.setPen(QColor(44, 62, 80));
    painter.drawText(pieRect, Qt::AlignCenter, QString::number(total));

    // Draw detailed legend with "Homme" and "Femme"
    int legendY = size - 60;

    // Homme legend with icon and full text
    painter.setBrush(QColor(52, 152, 219));
    painter.setPen(QPen(QColor(52, 152, 219).darker(150), 1));
    painter.drawEllipse(60, legendY, 14, 14);

    painter.setPen(QColor(44, 62, 80));
    QFont legendFont("Arial", 11, QFont::Bold);
    legendFont.setStyleStrategy(QFont::PreferAntialias);
    painter.setFont(legendFont);

    painter.drawText(80, legendY + 12, QString("Homme: %1 (%2%)")
                                           .arg(hommeCount)
                                           .arg(pourcHommes, 0, 'f', 1));

    // Femme legend with icon and full text
    painter.setBrush(QColor(231, 76, 60));
    painter.setPen(QPen(QColor(231, 76, 60).darker(150), 1));
    painter.drawEllipse(60, legendY + 30, 14, 14);

    painter.setPen(QColor(44, 62, 80));
    painter.drawText(80, legendY + 42, QString("Femme: %1 (%2%)")
                                           .arg(femmeCount)
                                           .arg(pourcFemmes, 0, 'f', 1));

    // Draw percentages on slices if they're large enough
    if (pourcHommes > 15) {
        double hommeAngle = pourcHommes * 3.6 / 2;
        QPointF hommePoint = calculatePointOnCircle(pieRect.center(),
                                                    pieRect.width()/2 * 0.7,
                                                    hommeAngle);

        painter.setPen(Qt::white);
        QFont sliceFont("Arial", 12, QFont::Bold);
        sliceFont.setStyleStrategy(QFont::PreferAntialias);
        painter.setFont(sliceFont);

        // Draw white background for text
        painter.setBrush(QColor(255, 255, 255, 150));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(hommePoint, 25, 25);

        // Draw percentage text
        painter.setPen(QColor(52, 152, 219).darker());
        painter.drawText(QRectF(hommePoint.x() - 25, hommePoint.y() - 12, 50, 24),
                         Qt::AlignCenter, QString("%1%").arg(pourcHommes, 0, 'f', 1));
    }

    if (pourcFemmes > 15) {
        double femmeAngle = pourcHommes * 3.6 + pourcFemmes * 3.6 / 2;
        QPointF femmePoint = calculatePointOnCircle(pieRect.center(),
                                                    pieRect.width()/2 * 0.7,
                                                    femmeAngle);

        painter.setPen(Qt::white);
        QFont sliceFont("Arial", 12, QFont::Bold);
        sliceFont.setStyleStrategy(QFont::PreferAntialias);
        painter.setFont(sliceFont);

        // Draw white background for text
        painter.setBrush(QColor(255, 255, 255, 150));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(femmePoint, 25, 25);

        // Draw percentage text
        painter.setPen(QColor(231, 76, 60).darker());
        painter.drawText(QRectF(femmePoint.x() - 25, femmePoint.y() - 12, 50, 24),
                         Qt::AlignCenter, QString("%1%").arg(pourcFemmes, 0, 'f', 1));
    }

    // Scale to label size with high quality
    QPixmap scaledPixmap = pixmap.scaled(ui->statslabel->size(),
                                         Qt::KeepAspectRatio,
                                         Qt::SmoothTransformation);

    ui->statslabel->setPixmap(scaledPixmap);
    ui->statslabel->setAlignment(Qt::AlignCenter);

    // Set size policy to prevent stretching
    ui->statslabel->setScaledContents(false);

    // Detailed tooltip
    QString tooltip = QString(
                          "<div style='font-family: Arial; font-size: 12px;'>"
                          "<b>📊 Statistiques Clients</b><br>"
                          "<hr style='border: 1px solid #ccc;'>"
                          "<table style='border-spacing: 5px;'>"
                          "<tr><td><b>Total:</b></td><td>%1 clients</td></tr>"
                          "<tr><td><span style='color: #3498db;'><b>Hommes:</b></span></td>"
                          "<td>%2 (%3%)</td></tr>"
                          "<tr><td><span style='color: #e74c3c;'><b>Femmes:</b></span></td>"
                          "<td>%4 (%5%)</td></tr>"
                          "</table>"
                          "</div>")
                          .arg(total)
                          .arg(hommeCount)
                          .arg(pourcHommes, 0, 'f', 1)
                          .arg(femmeCount)
                          .arg(pourcFemmes, 0, 'f', 1);

    ui->statslabel->setToolTip(tooltip);
}
QPointF MainWindow::calculatePointOnCircle(QPointF center, double radius, double angleDegrees)
{
    double angleRadians = angleDegrees * M_PI / 180.0;
    double x = center.x() + radius * cos(angleRadians);
    double y = center.y() + radius * sin(angleRadians);
    return QPointF(x, y);
}
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "QMessageBox"
void MainWindow::envoyerSMS(const QString& telephone, const QString& message)
{

    QString formattedPhone = telephone;


    formattedPhone = formattedPhone.remove(" ").remove("-");


    if (!formattedPhone.startsWith("+")) {
        if (formattedPhone.startsWith("2")) {
            formattedPhone = "+216" + formattedPhone; // +2162xxxxxxx
        } else if (formattedPhone.length() == 8) {
            formattedPhone = "+216" + formattedPhone; // +216xxxxxxx
        }
    }


    QUrl url(infobipBaseUrl + "/sms/2/text/advanced");


    QJsonObject destinationObject;
    destinationObject["to"] = formattedPhone;

    QJsonArray destinationsArray;
    destinationsArray.append(destinationObject);

    QJsonObject messageObject;

    messageObject["from"] = "InfoSMS"; // Use this for free trial
    messageObject["destinations"] = destinationsArray; // Must be "destinations" array
    messageObject["text"] = message;

    QJsonArray messagesArray;
    messagesArray.append(messageObject);

    QJsonObject jsonPayload;
    jsonPayload["messages"] = messagesArray;

    QJsonDocument jsonDoc(jsonPayload);
    QByteArray postData = jsonDoc.toJson();

    qDebug() << "Sending JSON:" << jsonDoc.toJson(QJsonDocument::Indented);


    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", ("App " + infobipApiKey).toUtf8());

    networkManager->post(request, postData);

    QMessageBox::information(this, "SMS", "Envoi du SMS en cours...");
}
void MainWindow::onSMSReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();

        if (jsonObj.contains("messages")) {
            QJsonArray messages = jsonObj["messages"].toArray();
            if (!messages.isEmpty()) {
                QJsonObject firstMessage = messages[0].toObject();
                QJsonObject statusObj = firstMessage["status"].toObject();
                QString status = statusObj["name"].toString();
                QString messageId = firstMessage["messageId"].toString();

                QMessageBox::information(this, "SMS Réussi",
                                        QString("SMS envoyé avec succès!\nStatus: %1\nID: %2")
                                        .arg(status).arg(messageId));
            } else {
                QMessageBox::information(this, "SMS Réussi", "SMS envoyé avec succès!");
            }
        } else {
            QMessageBox::information(this, "SMS Réussi", "SMS envoyé avec succès!");
        }
    } else {
        QString errorDetails = reply->errorString();
        QByteArray response = reply->readAll();

        if (!response.isEmpty()) {
            QJsonDocument errorDoc = QJsonDocument::fromJson(response);
            if (!errorDoc.isNull()) {
                QJsonObject errorObj = errorDoc.object();
                if (errorObj.contains("requestError")) {
                    QJsonObject serviceException = errorObj["requestError"].toObject()["serviceException"].toObject();
                    errorDetails += "\n" + serviceException["text"].toString();
                }
            }
        }

        QMessageBox::critical(this, "Erreur SMS",
                             QString("Erreur lors de l'envoi du SMS: %1")
                             .arg(errorDetails));
    }

    reply->deleteLater();
}

void MainWindow::on_pushButton_envoyerSMS_clicked()
{
    QString telephone = ui->tel_c->text().trimmed();
    QString nom = ui->nom_c->text().trimmed();

    if (telephone.isEmpty()) {
        QMessageBox::warning(this, "SMS", "Veuillez sélectionner un sponsor avec un numéro de téléphone.");
        return;
    }

    if (telephone.length() < 8) {
        QMessageBox::warning(this, "SMS", "Numéro de téléphone invalide.");
        return;
    }

    QString defaultMessage = QString("Cher(e) %1, nous vous remercions pour votre confiance et votre fidélité. C'est un plaisir de vous compter parmi nos clients.")
                            .arg(nom.isEmpty() ? "client" : nom);

    bool ok;
    QString customMessage = QInputDialog::getMultiLineText(this,
                                                          "Message SMS",
                                                          "Entrez votre message:",
                                                          defaultMessage,
                                                          &ok);

    if (ok && !customMessage.isEmpty()) {
        if (customMessage.length() > 160) {
            QMessageBox::warning(this, "SMS", "Le message est trop long (max 160 caractères).");
            return;
        }
        envoyerSMS(telephone, customMessage);
    }
}
#include <QInputDialog>

void MainWindow::on_pb_history_clicked()
{
    QSqlQueryModel *historyModel = Clients::getHistory();

    if (!historyModel) {
        QMessageBox::warning(this, "Historique", "Impossible de charger l'historique.");
        return;
    }

    // Create history dialog
    QDialog *historyDialog = new QDialog(this);
    historyDialog->setWindowTitle("Historique des Modifications - Clients");
    historyDialog->setModal(true);
    historyDialog->resize(900, 600);

    QVBoxLayout *layout = new QVBoxLayout(historyDialog);

    // Create table view
    QTableView *tableView = new QTableView();
    tableView->setModel(historyModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->resizeColumnsToContents();

    // Set column widths
    tableView->setColumnWidth(0, 60);  // ID
    tableView->setColumnWidth(1, 100); // CIN
    tableView->setColumnWidth(2, 80);  // Action
    tableView->setColumnWidth(3, 150); // Date/Heure
    tableView->setColumnWidth(4, 200); // Anciennes Valeurs
    tableView->setColumnWidth(5, 200); // Nouvelles Valeurs
    tableView->setColumnWidth(6, 100); // Utilisateur

    // Create buttons layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *detailsButton = new QPushButton("Détails");
    QPushButton *clearButton = new QPushButton("Vider l'Historique");
    QPushButton *closeButton = new QPushButton("Fermer");

    buttonLayout->addWidget(detailsButton);
    buttonLayout->addWidget(clearButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(closeButton);

    layout->addWidget(tableView);
    layout->addLayout(buttonLayout);

    // Connect buttons - FIXED: Use mutable lambda or different approach
    connect(detailsButton, &QPushButton::clicked, [tableView, historyModel]() {
        QModelIndexList selected = tableView->selectionModel()->selectedRows();
        if (selected.isEmpty()) {
            QMessageBox::information(tableView, "Détails", "Veuillez sélectionner une entrée de l'historique.");
            return;
        }

        int row = selected.first().row();
        QString action = historyModel->data(historyModel->index(row, 2)).toString();
        QString oldValues = historyModel->data(historyModel->index(row, 4)).toString();
        QString newValues = historyModel->data(historyModel->index(row, 5)).toString();
        QString cin = historyModel->data(historyModel->index(row, 1)).toString();
        QString date = historyModel->data(historyModel->index(row, 3)).toString();

        QString details = QString("Détails de l'action:\n\n"
                                "CIN: %1\n"
                                "Action: %2\n"
                                "Date/Heure: %3\n\n").arg(cin).arg(action).arg(date);

        if (action == "ADD") {
            details += "Nouveau client ajouté:\n";
            if (!newValues.isEmpty()) {
                QJsonDocument doc = QJsonDocument::fromJson(newValues.toUtf8());
                if (!doc.isNull()) {
                    QJsonObject obj = doc.object();
                    for (auto it = obj.begin(); it != obj.end(); ++it) {
                        details += QString("- %1: %2\n").arg(it.key()).arg(it.value().toString());
                    }
                }
            }
        } else if (action == "UPDATE") {
            details += "Modifications:\n\n";
            if (!oldValues.isEmpty() && !newValues.isEmpty()) {
                QJsonDocument oldDoc = QJsonDocument::fromJson(oldValues.toUtf8());
                QJsonDocument newDoc = QJsonDocument::fromJson(newValues.toUtf8());

                if (!oldDoc.isNull() && !newDoc.isNull()) {
                    QJsonObject oldObj = oldDoc.object();
                    QJsonObject newObj = newDoc.object();

                    for (auto it = newObj.begin(); it != newObj.end(); ++it) {
                        QString key = it.key();
                        QString oldVal = oldObj.value(key).toString();
                        QString newVal = it.value().toString();

                        if (oldVal != newVal) {
                            details += QString("- %1: '%2' → '%3'\n").arg(key).arg(oldVal).arg(newVal);
                        }
                    }
                }
            }
        } else if (action == "DELETE") {
            details += "Client supprimé:\n";
            if (!oldValues.isEmpty()) {
                QJsonDocument doc = QJsonDocument::fromJson(oldValues.toUtf8());
                if (!doc.isNull()) {
                    QJsonObject obj = doc.object();
                    for (auto it = obj.begin(); it != obj.end(); ++it) {
                        details += QString("- %1: %2\n").arg(it.key()).arg(it.value().toString());
                    }
                }
            }
        }

        QMessageBox::information(tableView, "Détails de l'Action", details);
    });

    // FIXED: Use a different approach for clear button that doesn't modify captured variables
    connect(clearButton, &QPushButton::clicked, historyDialog, [historyDialog, tableView]() {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(historyDialog, "Confirmation",
                                    "Êtes-vous sûr de vouloir vider tout l'historique ?",
                                    QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            if (Clients::clearHistory()) {
                QMessageBox::information(historyDialog, "Succès", "Historique vidé avec succès.");
                // Refresh the table by creating a new model
                QSqlQueryModel *newModel = Clients::getHistory();
                if (newModel) {
                    // Get the current model and delete it
                    QSqlQueryModel *oldModel = qobject_cast<QSqlQueryModel*>(tableView->model());
                    tableView->setModel(newModel);
                    if (oldModel) {
                        oldModel->deleteLater();
                    }

                    // Reset column widths
                    tableView->setColumnWidth(0, 60);
                    tableView->setColumnWidth(1, 100);
                    tableView->setColumnWidth(2, 80);
                    tableView->setColumnWidth(3, 150);
                    tableView->setColumnWidth(4, 200);
                    tableView->setColumnWidth(5, 200);
                    tableView->setColumnWidth(6, 100);
                }
            } else {
                QMessageBox::warning(historyDialog, "Erreur", "Impossible de vider l'historique.");
            }
        }
    });

    connect(closeButton, &QPushButton::clicked, historyDialog, &QDialog::accept);

    // Set dialog result and clean up properly
    connect(historyDialog, &QDialog::finished, [historyModel](int result) {
        Q_UNUSED(result)
        // The model will be deleted when the dialog is destroyed
        // since it's set as the parent of the model in the table view
    });

    historyDialog->exec();

    // Clean up - the model will be automatically deleted when the dialog is destroyed
    // because it's set as the model for the tableView which is a child of the dialog
}
