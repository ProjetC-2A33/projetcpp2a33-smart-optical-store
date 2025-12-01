#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include <QSound>

void MainWindow::setupSystemTray()
{
    // Créer l'icône de la barre d'état système
    systemTrayIcon = new QSystemTrayIcon(this);
    systemTrayIcon->setIcon(windowIcon());
    systemTrayIcon->setToolTip("Gestion Optique - Notifications");
    
    // Créer le menu contextuel
    QMenu *trayMenu = new QMenu(this);
    
    QAction *restoreAction = new QAction("Ouvrir", this);
    QAction *quitAction = new QAction("Quitter", this);
    
    connect(restoreAction, &QAction::triggered, this, &MainWindow::showNormal);
    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);
    
    trayMenu->addAction(restoreAction);
    trayMenu->addSeparator();
    trayMenu->addAction(quitAction);
    
    systemTrayIcon->setContextMenu(trayMenu);
    systemTrayIcon->show();
    
    // Connecter le signal de clic sur l'icône
    connect(systemTrayIcon, &QSystemTrayIcon::activated, this, &MainWindow::onSystemTrayIconActivated);
    
    // Démarrer la vérification périodique des stocks
    QTimer *stockCheckTimer = new QTimer(this);
    connect(stockCheckTimer, &QTimer::timeout, this, &MainWindow::checkLowStockLevels);
    stockCheckTimer->start(3600000); // Vérifier toutes les heures
}

void MainWindow::onSystemTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick) {
        if (isHidden()) {
            showNormal();
            activateWindow();
        } else {
            showMinimized();
        }
    }
}

void MainWindow::showNotification(const QString &title, const QString &message, NotificationType type)
{
    if (!systemTrayIcon || !systemTrayIcon->isVisible())
        return;
    
    // Définir l'icône en fonction du type de notification
    QSystemTrayIcon::MessageIcon iconType = QSystemTrayIcon::Information;
    
    switch (type) {
    case NotificationType::Information:
        iconType = QSystemTrayIcon::Information;
        break;
    case NotificationType::Warning:
        iconType = QSystemTrayIcon::Warning;
        QSound::play("sounds/warning.wav"); // Jouer un son d'avertissement
        break;
    case NotificationType::Critical:
        iconType = QSystemTrayIcon::Critical;
        QSound::play("sounds/alert.wav"); // Jouer un son d'alerte
        break;
    }
    
    // Afficher la notification
    systemTrayIcon->showMessage(title, message, iconType, 5000);
    
    // Si la fenêtre est minimisée, faire clignoter la barre des tâches
    if (isMinimized()) {
        flashWindow();
    }
}

void MainWindow::checkLowStockLevels()
{
    // Vérifier les produits en faible quantité
    QSqlQuery query("SELECT NOM, QUANTITE FROM PRODUITS WHERE QUANTITE < 5 ORDER BY QUANTITE ASC");
    
    QStringList lowStockItems;
    while (query.next()) {
        QString nom = query.value(0).toString();
        int quantite = query.value(1).toInt();
        lowStockItems << QString("%1 (il en reste %2)").arg(nom).arg(quantite);
    }
    
    if (!lowStockItems.isEmpty()) {
        QString message = "Les produits suivants sont en faible quantité :\n" + lowStockItems.join("\n");
        showNotification("Stock faible", message, NotificationType::Warning);
        
        // Envoyer un email d'alerte si configuré
        if (ui->checkBox_notifications_email->isChecked()) {
            sendLowStockEmail(lowStockItems);
        }
    }
}

void MainWindow::on_pushButton_parametres_notifications_clicked()
{
    // Afficher la boîte de dialogue des paramètres de notification
    QDialog dialog(this);
    dialog.setWindowTitle("Paramètres des notifications");
    
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    
    // Activer/désactiver les notifications
    QCheckBox *enableNotifications = new QCheckBox("Activer les notifications", &dialog);
    enableNotifications->setChecked(ui->checkBox_notifications->isChecked());
    
    // Activer/désactiver les notifications par email
    QCheckBox *enableEmailNotifications = new QCheckBox("Activer les notifications par email", &dialog);
    enableEmailNotifications->setChecked(ui->checkBox_notifications_email->isChecked());
    enableEmailNotifications->setEnabled(enableNotifications->isChecked());
    
    // Seuil d'alerte de stock
    QLabel *labelSeuil = new QLabel("Seuil d'alerte de stock :", &dialog);
    QSpinBox *seuilStock = new QSpinBox(&dialog);
    seuilStock->setRange(1, 100);
    seuilStock->setValue(ui->spinBox_seuil_stock->value());
    
    // Fréquence de vérification
    QLabel *labelFrequence = new QLabel("Fréquence de vérification (minutes) :", &dialog);
    QSpinBox *frequenceVerif = new QSpinBox(&dialog);
    frequenceVerif->setRange(1, 1440); // 1 minute à 24 heures
    frequenceVerif->setValue(60); // Par défaut 60 minutes
    
    // Boutons
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    
    // Mise en page
    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow(enableNotifications);
    formLayout->addRow(enableEmailNotifications);
    formLayout->addRow(labelSeuil, seuilStock);
    formLayout->addRow(labelFrequence, frequenceVerif);
    
    layout->addLayout(formLayout);
    layout->addWidget(buttonBox);
    
    // Connexions
    connect(enableNotifications, &QCheckBox::toggled, enableEmailNotifications, &QCheckBox::setEnabled);
    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    
    // Afficher la boîte de dialogue
    if (dialog.exec() == QDialog::Accepted) {
        // Enregistrer les paramètres
        ui->checkBox_notifications->setChecked(enableNotifications->isChecked());
        ui->checkBox_notifications_email->setChecked(enableEmailNotifications->isChecked());
        ui->spinBox_seuil_stock->setValue(seuilStock->value());
        
        // Redémarrer le minuteur avec la nouvelle fréquence
        QTimer *timer = findChild<QTimer*>(QString(), Qt::FindDirectChildrenOnly);
        if (timer) {
            timer->stop();
            timer->start(frequenceVerif->value() * 60000); // Convertir en millisecondes
        }
        
        // Afficher un message de confirmation
        showNotification("Paramètres enregistrés", "Les paramètres de notification ont été mis à jour.", 
                        NotificationType::Information);
    }
}

void MainWindow::sendLowStockEmail(const QStringList &lowStockItems)
{
    // Vérifier si l'envoi d'emails est configuré
    if (smtpServer.isEmpty() || smtpPort == 0 || smtpUser.isEmpty() || smtpPassword.isEmpty()) {
        qWarning() << "Configuration SMTP manquante pour l'envoi d'emails";
        return;
    }
    
    // Préparer le message
    QString subject = "Alerte : Stock faible";
    QString message = "Les produits suivants sont en faible quantité :\n\n" + lowStockItems.join("\n");
    
    // Créer l'objet SMTP
    SmtpClient smtp(smtpServer, smtpPort, smtpUseSsl ? SmtpClient::SslConnection : SmtpClient::TcpConnection);
    smtp.setUser(smtpUser);
    smtp.setPassword(smtpPassword);
    
    // Créer le message MIME
    MimeMessage email;
    email.setSender(new EmailAddress(smtpUser, "Système de Gestion Optique"));
    email.addRecipient(new EmailAddress(adminEmail, "Administrateur"));
    email.setSubject(subject);
    
    // Ajouter le texte brut
    MimeText *text = new MimeText();
    text->setText(message);
    email.addPart(text);
    
    // Envoyer l'email de manière asynchrone
    if (!smtp.connectToHost()) {
        qWarning() << "Échec de la connexion au serveur SMTP";
        return;
    }
    
    if (!smtp.login()) {
        qWarning() << "Échec de l'authentification SMTP";
        return;
    }
    
    if (!smtp.sendMail(email)) {
        qWarning() << "Échec de l'envoi de l'email";
    } else {
        qDebug() << "Email d'alerte de stock faible envoyé avec succès";
    }
    
    smtp.quit();
}

void MainWindow::flashWindow()
{
    // Faire clignoter la fenêtre dans la barre des tâches
    flashTimer = new QTimer(this);
    flashCounter = 0;
    
    connect(flashTimer, &QTimer::timeout, this, [this]() {
        if (flashCounter >= 10) { // Clignoter 5 fois (10 changements)
            flashTimer->stop();
            if (isMinimized()) {
                setWindowState((windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
            }
            return;
        }
        
        // Alterner entre la couleur normale et la couleur de flash
        if (flashCounter % 2 == 0) {
            setWindowOpacity(0.7);
        } else {
            setWindowOpacity(1.0);
        }
        
        flashCounter++;
    });
    
    flashTimer->start(200); // Clignoter toutes les 200ms
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (trayIcon && trayIcon->isVisible()) {
        hide();
        event->ignore();
    } else {
        event->accept();
    }
}
