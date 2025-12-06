/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *pushButton_7;
    QLabel *label_7;
    QLabel *statslabel;
    QPushButton *pushButton_9;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *cin_c;
    QLineEdit *prenom_c;
    QLineEdit *nom_c;
    QLineEdit *email_c;
    QLineEdit *tel_c;
    QLabel *label_6;
    QPushButton *ajouter_c;
    QPushButton *supp_c;
    QPushButton *modif_c;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_5;
    QLineEdit *adr_c;
    QLabel *label_8;
    QLabel *label_10;
    QComboBox *comboBoxSTATUTFIDELITE_c;
    QComboBox *comboBoxsexe_c;
    QPushButton *annuler_c;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_envoyerSMS;
    QPushButton *pb_history;
    QPushButton *pushButton_6;
    QTableWidget *tableWidget_c;
    QComboBox *comboBox_tri;
    QLabel *label_11;
    QLineEdit *search;
    QPushButton *stats;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1351, 667);
        pushButton_7 = new QPushButton(MainWindow);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(440, 40, 90, 29));
        pushButton_7->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 255);\n"
"background-color: rgb(0, 0, 136);"));
        label_7 = new QLabel(MainWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(450, 380, 171, 20));
        statslabel = new QLabel(MainWindow);
        statslabel->setObjectName(QStringLiteral("statslabel"));
        statslabel->setGeometry(QRect(440, 440, 361, 211));
        statslabel->setPixmap(QPixmap(QString::fromUtf8("../../../../gestion client/icone-statistique-fond-clair-symbole-donnees-entreprise-graphique-analysant-analytique-contour-plat_.png")));
        statslabel->setScaledContents(true);
        pushButton_9 = new QPushButton(MainWindow);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(1190, 500, 90, 29));
        pushButton_9->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 136);"));
        groupBox = new QGroupBox(MainWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 421, 691));
        groupBox->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(21, 21, 21);"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 63, 20));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 63, 20));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 63, 20));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 180, 71, 31));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 290, 71, 21));
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        cin_c = new QLineEdit(groupBox);
        cin_c->setObjectName(QStringLiteral("cin_c"));
        cin_c->setGeometry(QRect(90, 30, 113, 28));
        prenom_c = new QLineEdit(groupBox);
        prenom_c->setObjectName(QStringLiteral("prenom_c"));
        prenom_c->setGeometry(QRect(90, 80, 113, 28));
        nom_c = new QLineEdit(groupBox);
        nom_c->setObjectName(QStringLiteral("nom_c"));
        nom_c->setGeometry(QRect(90, 130, 113, 28));
        email_c = new QLineEdit(groupBox);
        email_c->setObjectName(QStringLiteral("email_c"));
        email_c->setGeometry(QRect(90, 180, 113, 28));
        tel_c = new QLineEdit(groupBox);
        tel_c->setObjectName(QStringLiteral("tel_c"));
        tel_c->setGeometry(QRect(90, 230, 113, 28));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 230, 71, 31));
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        ajouter_c = new QPushButton(groupBox);
        ajouter_c->setObjectName(QStringLiteral("ajouter_c"));
        ajouter_c->setGeometry(QRect(10, 530, 151, 31));
        ajouter_c->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 136);"));
        supp_c = new QPushButton(groupBox);
        supp_c->setObjectName(QStringLiteral("supp_c"));
        supp_c->setGeometry(QRect(210, 620, 151, 31));
        modif_c = new QPushButton(groupBox);
        modif_c->setObjectName(QStringLiteral("modif_c"));
        modif_c->setGeometry(QRect(10, 620, 151, 31));
        modif_c->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 136);"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 570, 151, 31));
        pushButton_4->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 136);"));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(210, 560, 181, 31));
        lineEdit_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        adr_c = new QLineEdit(groupBox);
        adr_c->setObjectName(QStringLiteral("adr_c"));
        adr_c->setGeometry(QRect(90, 290, 113, 28));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 340, 63, 20));
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 390, 71, 21));
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        comboBoxSTATUTFIDELITE_c = new QComboBox(groupBox);
        comboBoxSTATUTFIDELITE_c->setObjectName(QStringLiteral("comboBoxSTATUTFIDELITE_c"));
        comboBoxSTATUTFIDELITE_c->setGeometry(QRect(220, 390, 141, 26));
        comboBoxsexe_c = new QComboBox(groupBox);
        comboBoxsexe_c->setObjectName(QStringLiteral("comboBoxsexe_c"));
        comboBoxsexe_c->setGeometry(QRect(220, 350, 141, 26));
        annuler_c = new QPushButton(groupBox);
        annuler_c->setObjectName(QStringLiteral("annuler_c"));
        annuler_c->setGeometry(QRect(250, 510, 93, 29));
        groupBox_3 = new QGroupBox(MainWindow);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(820, 410, 301, 121));
        pushButton_envoyerSMS = new QPushButton(groupBox_3);
        pushButton_envoyerSMS->setObjectName(QStringLiteral("pushButton_envoyerSMS"));
        pushButton_envoyerSMS->setGeometry(QRect(70, 30, 171, 31));
        pb_history = new QPushButton(groupBox_3);
        pb_history->setObjectName(QStringLiteral("pb_history"));
        pb_history->setGeometry(QRect(70, 80, 171, 31));
        pushButton_6 = new QPushButton(MainWindow);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(450, 130, 90, 29));
        tableWidget_c = new QTableWidget(MainWindow);
        if (tableWidget_c->columnCount() < 7)
            tableWidget_c->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_c->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_c->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_c->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_c->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_c->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_c->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_c->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget_c->setObjectName(QStringLiteral("tableWidget_c"));
        tableWidget_c->setGeometry(QRect(580, 80, 731, 251));
        comboBox_tri = new QComboBox(MainWindow);
        comboBox_tri->setObjectName(QStringLiteral("comboBox_tri"));
        comboBox_tri->setGeometry(QRect(540, 40, 101, 31));
        label_11 = new QLabel(MainWindow);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(820, 50, 47, 14));
        search = new QLineEdit(MainWindow);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(890, 40, 251, 31));
        stats = new QPushButton(MainWindow);
        stats->setObjectName(QStringLiteral("stats"));
        stats->setGeometry(QRect(580, 380, 75, 23));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Dialog", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "TRI", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Statistiques clients:", Q_NULLPTR));
        statslabel->setText(QString());
        pushButton_9->setText(QApplication::translate("MainWindow", "log out ", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Gestion Client", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Email ", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Adress", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "T\303\251l\303\251phone", Q_NULLPTR));
        ajouter_c->setText(QApplication::translate("MainWindow", "Ajouter un Client", Q_NULLPTR));
        supp_c->setText(QApplication::translate("MainWindow", "Supprimer un Client", Q_NULLPTR));
        modif_c->setText(QApplication::translate("MainWindow", "Modifier info", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Rechercher un client", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Sexe ", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "statut", Q_NULLPTR));
        comboBoxSTATUTFIDELITE_c->clear();
        comboBoxSTATUTFIDELITE_c->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
        );
        comboBoxsexe_c->clear();
        comboBoxsexe_c->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "homme", Q_NULLPTR)
         << QApplication::translate("MainWindow", "femme", Q_NULLPTR)
        );
        annuler_c->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "m\303\251tiers avanc\303\251s", Q_NULLPTR));
        pushButton_envoyerSMS->setText(QApplication::translate("MainWindow", "send sms", Q_NULLPTR));
        pb_history->setText(QApplication::translate("MainWindow", "History", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_c->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_c->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_c->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_c->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_c->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Telephone", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_c->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Adresse", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_c->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Sexe", Q_NULLPTR));
        comboBox_tri->clear();
        comboBox_tri->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "trier par", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CIN Croissant", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CIN D\303\251croissant", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Nom Croissant", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Nom D\303\251croissant", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        stats->setText(QApplication::translate("MainWindow", "Stats", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
