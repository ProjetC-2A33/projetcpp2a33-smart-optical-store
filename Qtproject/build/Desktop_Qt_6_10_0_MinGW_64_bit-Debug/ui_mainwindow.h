/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1351, 667);
        pushButton_7 = new QPushButton(MainWindow);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(440, 40, 90, 29));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"background-color: rgb(0, 0, 136);"));
        label_7 = new QLabel(MainWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(450, 380, 171, 20));
        statslabel = new QLabel(MainWindow);
        statslabel->setObjectName("statslabel");
        statslabel->setGeometry(QRect(440, 440, 361, 211));
        statslabel->setPixmap(QPixmap(QString::fromUtf8("../../../../gestion client/icone-statistique-fond-clair-symbole-donnees-entreprise-graphique-analysant-analytique-contour-plat_.png")));
        statslabel->setScaledContents(true);
        pushButton_9 = new QPushButton(MainWindow);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(1190, 500, 90, 29));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 136);"));
        groupBox = new QGroupBox(MainWindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 421, 691));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(21, 21, 21);"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 63, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 63, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 130, 63, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 180, 71, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 290, 71, 21));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        cin_c = new QLineEdit(groupBox);
        cin_c->setObjectName("cin_c");
        cin_c->setGeometry(QRect(90, 30, 113, 28));
        prenom_c = new QLineEdit(groupBox);
        prenom_c->setObjectName("prenom_c");
        prenom_c->setGeometry(QRect(90, 80, 113, 28));
        nom_c = new QLineEdit(groupBox);
        nom_c->setObjectName("nom_c");
        nom_c->setGeometry(QRect(90, 130, 113, 28));
        email_c = new QLineEdit(groupBox);
        email_c->setObjectName("email_c");
        email_c->setGeometry(QRect(90, 180, 113, 28));
        tel_c = new QLineEdit(groupBox);
        tel_c->setObjectName("tel_c");
        tel_c->setGeometry(QRect(90, 230, 113, 28));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 230, 71, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ajouter_c = new QPushButton(groupBox);
        ajouter_c->setObjectName("ajouter_c");
        ajouter_c->setGeometry(QRect(10, 530, 151, 31));
        ajouter_c->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 136);"));
        supp_c = new QPushButton(groupBox);
        supp_c->setObjectName("supp_c");
        supp_c->setGeometry(QRect(210, 620, 151, 31));
        modif_c = new QPushButton(groupBox);
        modif_c->setObjectName("modif_c");
        modif_c->setGeometry(QRect(10, 620, 151, 31));
        modif_c->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 136);"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 570, 151, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 136);"));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(210, 560, 181, 31));
        lineEdit_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        adr_c = new QLineEdit(groupBox);
        adr_c->setObjectName("adr_c");
        adr_c->setGeometry(QRect(90, 290, 113, 28));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 340, 63, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 390, 71, 21));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        comboBoxSTATUTFIDELITE_c = new QComboBox(groupBox);
        comboBoxSTATUTFIDELITE_c->addItem(QString());
        comboBoxSTATUTFIDELITE_c->addItem(QString());
        comboBoxSTATUTFIDELITE_c->setObjectName("comboBoxSTATUTFIDELITE_c");
        comboBoxSTATUTFIDELITE_c->setGeometry(QRect(220, 390, 141, 26));
        comboBoxsexe_c = new QComboBox(groupBox);
        comboBoxsexe_c->addItem(QString());
        comboBoxsexe_c->addItem(QString());
        comboBoxsexe_c->setObjectName("comboBoxsexe_c");
        comboBoxsexe_c->setGeometry(QRect(220, 350, 141, 26));
        annuler_c = new QPushButton(groupBox);
        annuler_c->setObjectName("annuler_c");
        annuler_c->setGeometry(QRect(250, 510, 93, 29));
        groupBox_3 = new QGroupBox(MainWindow);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(820, 410, 301, 121));
        pushButton_envoyerSMS = new QPushButton(groupBox_3);
        pushButton_envoyerSMS->setObjectName("pushButton_envoyerSMS");
        pushButton_envoyerSMS->setGeometry(QRect(70, 30, 171, 31));
        pb_history = new QPushButton(groupBox_3);
        pb_history->setObjectName("pb_history");
        pb_history->setGeometry(QRect(70, 80, 171, 31));
        pushButton_6 = new QPushButton(MainWindow);
        pushButton_6->setObjectName("pushButton_6");
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
        tableWidget_c->setObjectName("tableWidget_c");
        tableWidget_c->setGeometry(QRect(580, 80, 731, 251));
        comboBox_tri = new QComboBox(MainWindow);
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName("comboBox_tri");
        comboBox_tri->setGeometry(QRect(540, 40, 101, 31));
        label_11 = new QLabel(MainWindow);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(820, 50, 47, 14));
        search = new QLineEdit(MainWindow);
        search->setObjectName("search");
        search->setGeometry(QRect(890, 40, 251, 31));
        stats = new QPushButton(MainWindow);
        stats->setObjectName("stats");
        stats->setGeometry(QRect(580, 380, 75, 23));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dialog", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "TRI", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Statistiques clients:", nullptr));
        statslabel->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "log out ", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Gestion Client", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CIN", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Email ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Adress", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        ajouter_c->setText(QCoreApplication::translate("MainWindow", "Ajouter un Client", nullptr));
        supp_c->setText(QCoreApplication::translate("MainWindow", "Supprimer un Client", nullptr));
        modif_c->setText(QCoreApplication::translate("MainWindow", "Modifier info", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Rechercher un client", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Sexe ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "statut", nullptr));
        comboBoxSTATUTFIDELITE_c->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBoxSTATUTFIDELITE_c->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));

        comboBoxsexe_c->setItemText(0, QCoreApplication::translate("MainWindow", "homme", nullptr));
        comboBoxsexe_c->setItemText(1, QCoreApplication::translate("MainWindow", "femme", nullptr));

        annuler_c->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "m\303\251tiers avanc\303\251s", nullptr));
        pushButton_envoyerSMS->setText(QCoreApplication::translate("MainWindow", "send sms", nullptr));
        pb_history->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_c->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "CIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_c->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_c->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_c->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_c->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_c->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_c->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Sexe", nullptr));
        comboBox_tri->setItemText(0, QCoreApplication::translate("MainWindow", "trier par", nullptr));
        comboBox_tri->setItemText(1, QCoreApplication::translate("MainWindow", "CIN Croissant", nullptr));
        comboBox_tri->setItemText(2, QCoreApplication::translate("MainWindow", "CIN D\303\251croissant", nullptr));
        comboBox_tri->setItemText(3, QCoreApplication::translate("MainWindow", "Nom Croissant", nullptr));
        comboBox_tri->setItemText(4, QCoreApplication::translate("MainWindow", "Nom D\303\251croissant", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        stats->setText(QCoreApplication::translate("MainWindow", "Stats", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
