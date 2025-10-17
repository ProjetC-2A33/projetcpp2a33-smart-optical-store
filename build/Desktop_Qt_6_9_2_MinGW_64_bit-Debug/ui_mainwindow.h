/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_7;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_7;
    QPushButton *pushButton_7;
    QLabel *label_9;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 11, 11);\n"
"background-color: rgb(20, 20, 20);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 421, 541));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 33, 33);"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 63, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 63, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 130, 63, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 180, 71, 31));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 290, 71, 21));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 30, 113, 28));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(90, 80, 113, 28));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(90, 130, 113, 28));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(90, 180, 113, 28));
        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(90, 230, 113, 28));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 230, 71, 31));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 390, 151, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 136);"));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 500, 151, 31));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 500, 151, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 136);"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 450, 151, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 136);"));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(180, 450, 181, 31));
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(90, 290, 113, 28));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(100, 340, 111, 25));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(210, 340, 111, 25));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 340, 63, 20));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(580, 10, 301, 231));
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 21, 341, 211));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(580, 270, 301, 121));
        pushButton_8 = new QPushButton(groupBox_3);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(10, 40, 281, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 136);"));
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 70, 281, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 136);"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(460, 130, 90, 29));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(440, 410, 171, 20));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(460, 60, 90, 29));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"background-color: rgb(0, 0, 136);"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(440, 440, 251, 71));
        label_9->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/icone-statistique-fond-clair-symbole-donnees-entreprise-graphique-analysant-analytique-contour-plat_.png")));
        label_9->setScaledContents(true);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(700, 520, 90, 29));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 136);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Gestion Client", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "CIN", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Email ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Adress", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Ajouter un Client", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Supprimer un Client", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Modifier info", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Rechercher un client", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "femme", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "homme", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Sexe ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "CIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Sexe", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "m\303\251tiers avanc\303\251s", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\342\255\220 Statut fid\303\251lit\303\251", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\360\237\227\223\357\270\217 Historique m\303\251dical ", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Statistiques clients:", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "TRI", nullptr));
        label_9->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "log out ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
