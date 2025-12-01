#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStyleFactory>

void MainWindow::applyStyles()
{
    // Définir le style Fusion pour une apparence moderne et cohérente sur toutes les plateformes
    qApp->setStyle(QStyleFactory::create("Fusion"));
    
    // Palette de couleurs personnalisée
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(240, 240, 240));
    palette.setColor(QPalette::WindowText, QColor(53, 53, 53));
    palette.setColor(QPalette::Base, QColor(255, 255, 255));
    palette.setColor(QPalette::AlternateBase, QColor(240, 240, 240));
    palette.setColor(QPalette::ToolTipBase, QColor(53, 53, 53));
    palette.setColor(QPalette::ToolTipText, QColor(255, 255, 255));
    palette.setColor(QPalette::Text, QColor(53, 53, 53));
    palette.setColor(QPalette::Button, QColor(240, 240, 240));
    palette.setColor(QPalette::ButtonText, QColor(53, 53, 53));
    palette.setColor(QPalette::BrightText, QColor(255, 255, 255));
    palette.setColor(QPalette::Link, QColor(42, 130, 218));
    palette.setColor(QPalette::Highlight, QColor(61, 142, 255));
    palette.setColor(QPalette::HighlightedText, QColor(255, 255, 255));
    
    qApp->setPalette(palette);
    
    // Style général de l'application
    QString styleSheet = R"(
        /* Style général de la fenêtre */
        QMainWindow, QDialog {
            background-color: #f0f0f0;
        }
        
        /* Style des boutons */
        QPushButton {
            background-color: #3d8eff;
            color: white;
            border: none;
            border-radius: 4px;
            padding: 8px 16px;
            min-width: 100px;
            font-weight: bold;
        }
        
        QPushButton:hover {
            background-color: #2a7ae9;
        }
        
        QPushButton:pressed {
            background-color: #1a5bc4;
        }
        
        QPushButton:disabled {
            background-color: #cccccc;
            color: #666666;
        }
        
        /* Style des boutons d'action */
        QPushButton.primary {
            background-color: #4caf50;
        }
        
        QPushButton.primary:hover {
            background-color: #43a047;
        }
        
        QPushButton.danger {
            background-color: #f44336;
        }
        
        QPushButton.danger:hover {
            background-color: #e53935;
        }
        
        /* Style des champs de saisie */
        QLineEdit, QTextEdit, QPlainTextEdit, QComboBox, QSpinBox, QDoubleSpinBox, QDateEdit {
            border: 1px solid #cccccc;
            border-radius: 4px;
            padding: 6px;
            background-color: white;
        }
        
        QLineEdit:focus, QTextEdit:focus, QPlainTextEdit:focus, 
        QComboBox:focus, QSpinBox:focus, QDoubleSpinBox:focus, QDateEdit:focus {
            border: 1px solid #3d8eff;
        }
        
        /* Style des onglets */
        QTabWidget::pane {
            border: 1px solid #cccccc;
            border-radius: 4px;
            background-color: white;
        }
        
        QTabBar::tab {
            background-color: #e0e0e0;
            border: 1px solid #cccccc;
            border-bottom: none;
            border-top-left-radius: 4px;
            border-top-right-radius: 4px;
            padding: 8px 16px;
            margin-right: 2px;
        }
        
        QTabBar::tab:selected {
            background-color: white;
            border-bottom: 1px solid white;
            margin-bottom: -1px;
        }
        
        QTabBar::tab:!selected {
            margin-top: 2px;
        }
        
        /* Style des tableaux */
        QTableView, QTableWidget {
            border: 1px solid #cccccc;
            border-radius: 4px;
            background-color: white;
            gridline-color: #e0e0e0;
        }
        
        QHeaderView::section {
            background-color: #f0f0f0;
            padding: 8px;
            border: none;
            border-right: 1px solid #e0e0e0;
            border-bottom: 1px solid #e0e0e0;
        }
        
        QHeaderView::section:last {
            border-right: none;
        }
        
        /* Style des menus */
        QMenuBar {
            background-color: #f0f0f0;
            border: none;
        }
        
        QMenuBar::item {
            padding: 8px 16px;
            background-color: transparent;
        }
        
        QMenuBar::item:selected {
            background-color: #e0e0e0;
        }
        
        QMenu {
            background-color: white;
            border: 1px solid #cccccc;
            border-radius: 4px;
        }
        
        QMenu::item:selected {
            background-color: #3d8eff;
            color: white;
        }
        
        /* Style des barres de défilement */
        QScrollBar:vertical {
            border: none;
            background-color: #f0f0f0;
            width: 12px;
            margin: 0px;
        }
        
        QScrollBar::handle:vertical {
            background-color: #c0c0c0;
            border-radius: 6px;
            min-height: 20px;
        }
        
        QScrollBar::handle:vertical:hover {
            background-color: #a0a0a0;
        }
        
        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0px;
        }
        
        /* Style des cases à cocher et des boutons radio */
        QCheckBox::indicator, QRadioButton::indicator {
            width: 16px;
            height: 16px;
        }
        
        QCheckBox::indicator:unchecked {
            border: 1px solid #cccccc;
            background-color: white;
        }
        
        QCheckBox::indicator:checked {
            border: 1px solid #3d8eff;
            background-color: #3d8eff;
            image: url(:/icons/checkmark.png);
        }
        
        QRadioButton::indicator:unchecked {
            border: 1px solid #cccccc;
            border-radius: 8px;
            background-color: white;
        }
        
        QRadioButton::indicator:checked {
            border: 1px solid #3d8eff;
            border-radius: 8px;
            background-color: white;
        }
        
        QRadioButton::indicator:checked {
            background-color: #3d8eff;
            border: 4px solid white;
        }
        
        /* Style des boîtes de dialogue */
        QDialog {
            background-color: white;
        }
        
        QDialogButtonBox {
            border-top: 1px solid #e0e0e0;
            padding: 16px;
        }
        
        /* Style des étiquettes d'état */
        QLabel[state="success"] {
            color: #4caf50;
            font-weight: bold;
        }
        
        QLabel[state="warning"] {
            color: #ff9800;
            font-weight: bold;
        }
        
        QLabel[state="error"] {
            color: #f44336;
            font-weight: bold;
        }
        
        /* Style des onglets de la barre d'état */
        QStatusBar {
            background-color: #f0f0f0;
            border-top: 1px solid #e0e0e0;
        }
        
        /* Style des séparateurs */
        QFrame[frameShape="4"], QFrame[frameShape="5"] {
            color: #e0e0e0;
        }
        
        /* Style des tooltips */
        QToolTip {
            background-color: #333333;
            color: white;
            border: 1px solid #555555;
            padding: 4px 8px;
            border-radius: 4px;
        }
    )";
    
    // Appliquer la feuille de style
    qApp->setStyleSheet(styleSheet);
    
    // Appliquer des styles spécifiques à certains widgets
    ui->pushButton_ajouter->setProperty("class", "primary");
    ui->pushButton_supprimer->setProperty("class", "danger");
    
    // Personnalisation des icônes des boutons
    ui->pushButton_ajouter->setIcon(QIcon(":/icons/add.png"));
    ui->pushButton_modifier->setIcon(QIcon(":/icons/edit.png"));
    ui->pushButton_supprimer->setIcon(QIcon(":/icons/delete.png"));
    ui->pushButton_actualiser->setIcon(QIcon(":/icons/refresh.png"));
    ui->pushButton_imprimer->setIcon(QIcon(":/icons/print.png"));
    ui->pushButton_exporter->setIcon(QIcon(":/icons/export.png"));
    
    // Personnalisation de la barre d'outils
    ui->toolBar->setIconSize(QSize(24, 24));
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    
    // Personnalisation de la barre de statut
    ui->statusbar->setStyleSheet("QStatusBar { padding: 4px; }");
    
    // Personnalisation des en-têtes de tableau
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    
    // Personnalisation des onglets
    ui->tabWidget->setDocumentMode(true);
    ui->tabWidget->setTabPosition(QTabWidget::North);
    
    // Personnalisation des champs de recherche
    ui->lineEdit_recherche->setPlaceholderText("Rechercher...");
    ui->lineEdit_recherche->setClearButtonEnabled(true);
    
    // Personnalisation des messages d'état
    ui->label_statut->setProperty("state", "info");
    
    // Personnalisation des messages d'erreur
    ui->label_erreur->setStyleSheet("color: #f44336; font-weight: bold;");
    
    // Personnalisation des titres
    QList<QLabel*> labels = findChildren<QLabel*>();
    foreach (QLabel *label, labels) {
        if (label->property("isTitle").toBool()) {
            QFont font = label->font();
            font.setPointSize(font.pointSize() + 2);
            font.setBold(true);
            label->setFont(font);
            label->setStyleSheet("color: #3d8eff;");
        }
    }
    
    // Personnalisation des boutons de navigation
    ui->pushButton_precedent->setIcon(QIcon(":/icons/previous.png"));
    ui->pushButton_suivant->setIcon(QIcon(":/icons/next.png"));
    
    // Personnalisation des boutons de tri
    ui->pushButton_tri_croissant->setIcon(QIcon(":/icons/sort-asc.png"));
    ui->pushButton_tri_decroissant->setIcon(QIcon(":/icons/sort-desc.png"));
    
    // Personnalisation des boutons d'export
    ui->pushButton_excel->setIcon(QIcon(":/icons/excel.png"));
    ui->pushButton_pdf->setIcon(QIcon(":/icons/pdf.png"));
    
    // Personnalisation des boutons d'action rapide
    ui->pushButton_rapide_ajout->setIcon(QIcon(":/icons/quick-add.png"));
    ui->pushButton_rapide_edition->setIcon(QIcon(":/icons/quick-edit.png"));
    
    // Personnalisation des indicateurs de chargement
    ui->progressBar->setTextVisible(true);
    ui->progressBar->setAlignment(Qt::AlignCenter);
    
    // Personnalisation des messages d'information
    ui->label_info->setStyleSheet("background-color: #e3f2fd; color: #0d47a1; padding: 8px; border-radius: 4px;");
    
    // Personnalisation des messages d'avertissement
    ui->label_avertissement->setStyleSheet("background-color: #fff3e0; color: #e65100; padding: 8px; border-radius: 4px;");
    
    // Personnalisation des messages d'erreur
    ui->label_erreur->setStyleSheet("background-color: #ffebee; color: #c62828; padding: 8px; border-radius: 4px;");
}
