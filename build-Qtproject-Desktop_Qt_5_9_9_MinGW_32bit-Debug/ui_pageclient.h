/********************************************************************************
** Form generated from reading UI file 'pageclient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGECLIENT_H
#define UI_PAGECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageclient
{
public:
    QLabel *label;
    QPushButton *logoutpb4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tab_clients;
    QPushButton *pb_ajouter;
    QPushButton *pb_modifier_2;
    QPushButton *pb_supprimer;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *cin_c;
    QLineEdit *nom_c;
    QLineEdit *prenom_c;
    QLineEdit *email_c;
    QLineEdit *daten_c;
    QLineEdit *telephone_c;
    QLineEdit *cond_c;
    QLineEdit *niv_c;
    QLabel *label_11;
    QLineEdit *adresse_c;
    QComboBox *genre_c;
    QPushButton *abonnement4pb;
    QPushButton *employe4pb;
    QPushButton *activite4pb;
    QPushButton *back4pb;
    QPushButton *pushButton_9;
    QPushButton *planning4pb;

    void setupUi(QDialog *pageclient)
    {
        if (pageclient->objectName().isEmpty())
            pageclient->setObjectName(QStringLiteral("pageclient"));
        pageclient->resize(1051, 711);
        label = new QLabel(pageclient);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-340, -30, 561, 701));
        label->setStyleSheet(QStringLiteral("border-image: url(:/img/img/Sidebar2.png);"));
        logoutpb4 = new QPushButton(pageclient);
        logoutpb4->setObjectName(QStringLiteral("logoutpb4"));
        logoutpb4->setGeometry(QRect(40, 560, 141, 101));
        logoutpb4->setStyleSheet(QStringLiteral("border-image: url(:/img/img/4400629.png);"));
        tabWidget = new QTabWidget(pageclient);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(230, 30, 851, 671));
        tabWidget->setStyleSheet(QLatin1String("\n"
"/* Style for QGroupBox */\n"
"\n"
"\n"
"/* Style for QLineEdit (input box) */\n"
"QLineEdit {\n"
"    background-color: #3498db; /* Blue color for input boxes */\n"
"    border: 1px solid #2980b9; /* Border color for input boxes */\n"
"    border-radius: 5px; /* Border radius for input boxes */\n"
"    padding: 5px; /* Padding for input boxes */\n"
"    color: black; /* Text color inside input boxes */\n"
"}\n"
"\n"
"/* Style for QLabel (text label) */\n"
"QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 16px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}\n"
"\n"
"/* Style for QPushButton */\n"
"QPushButton {\n"
"    background-color: #3498db; /* Blue color for buttons */\n"
"    border: 1px solid #2980b9; /* Border color for buttons */\n"
"    border-radius: 5px; /* Border radius for buttons */\n"
"    padding: 5px 10px; /* Adjust padding as needed */\n"
"    color: whit"
                        "e; /* Text color on buttons */\n"
"}\n"
"\n"
"/* Additional styling for better appearance */\n"
"QPushButton:hover {\n"
"    background-color: #2980b9; /* Darker blue on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #21618c; /* Even darker blue when pressed */\n"
"}\n"
"\n"
"/* Add more styles as needed for your specific application */\n"
""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab_clients = new QTableView(tab);
        tab_clients->setObjectName(QStringLiteral("tab_clients"));
        tab_clients->setGeometry(QRect(470, 40, 371, 431));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(170, 557, 161, 41));
        pb_modifier_2 = new QPushButton(tab);
        pb_modifier_2->setObjectName(QStringLiteral("pb_modifier_2"));
        pb_modifier_2->setGeometry(QRect(360, 557, 121, 41));
        pb_supprimer = new QPushButton(tab);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(510, 557, 141, 41));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 40, 101, 41));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 90, 91, 31));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 140, 121, 31));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 190, 111, 31));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 270, 141, 41));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 310, 111, 31));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 360, 131, 31));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 420, 151, 31));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(100, 460, 111, 31));
        cin_c = new QLineEdit(tab);
        cin_c->setObjectName(QStringLiteral("cin_c"));
        cin_c->setGeometry(QRect(200, 49, 241, 31));
        nom_c = new QLineEdit(tab);
        nom_c->setObjectName(QStringLiteral("nom_c"));
        nom_c->setGeometry(QRect(200, 89, 241, 31));
        prenom_c = new QLineEdit(tab);
        prenom_c->setObjectName(QStringLiteral("prenom_c"));
        prenom_c->setGeometry(QRect(200, 140, 241, 31));
        email_c = new QLineEdit(tab);
        email_c->setObjectName(QStringLiteral("email_c"));
        email_c->setGeometry(QRect(200, 189, 241, 31));
        daten_c = new QLineEdit(tab);
        daten_c->setObjectName(QStringLiteral("daten_c"));
        daten_c->setGeometry(QRect(200, 269, 241, 31));
        telephone_c = new QLineEdit(tab);
        telephone_c->setObjectName(QStringLiteral("telephone_c"));
        telephone_c->setGeometry(QRect(200, 309, 241, 31));
        cond_c = new QLineEdit(tab);
        cond_c->setObjectName(QStringLiteral("cond_c"));
        cond_c->setGeometry(QRect(200, 360, 241, 31));
        niv_c = new QLineEdit(tab);
        niv_c->setObjectName(QStringLiteral("niv_c"));
        niv_c->setGeometry(QRect(200, 419, 241, 31));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(100, 230, 101, 31));
        adresse_c = new QLineEdit(tab);
        adresse_c->setObjectName(QStringLiteral("adresse_c"));
        adresse_c->setGeometry(QRect(200, 229, 241, 31));
        genre_c = new QComboBox(tab);
        genre_c->setObjectName(QStringLiteral("genre_c"));
        genre_c->setGeometry(QRect(200, 461, 241, 31));
        tabWidget->addTab(tab, QString());
        abonnement4pb = new QPushButton(pageclient);
        abonnement4pb->setObjectName(QStringLiteral("abonnement4pb"));
        abonnement4pb->setGeometry(QRect(80, 270, 81, 61));
        abonnement4pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416322058_1151869056186867_7815397858715591504_n.png);"));
        employe4pb = new QPushButton(pageclient);
        employe4pb->setObjectName(QStringLiteral("employe4pb"));
        employe4pb->setGeometry(QRect(80, 200, 81, 51));
        employe4pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415260602_915404969798523_5173262210140723394_n.png);"));
        activite4pb = new QPushButton(pageclient);
        activite4pb->setObjectName(QStringLiteral("activite4pb"));
        activite4pb->setGeometry(QRect(70, 440, 111, 71));
        activite4pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415366346_1746257945859861_8686726138527086848_n.png);"));
        back4pb = new QPushButton(pageclient);
        back4pb->setObjectName(QStringLiteral("back4pb"));
        back4pb->setGeometry(QRect(-20, -60, 201, 181));
        back4pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/gearr.png);"));
        pushButton_9 = new QPushButton(pageclient);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(80, 120, 81, 61));
        pushButton_9->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415287996_755433109383168_7582230033290630906_n.png);"));
        planning4pb = new QPushButton(pageclient);
        planning4pb->setObjectName(QStringLiteral("planning4pb"));
        planning4pb->setGeometry(QRect(80, 360, 91, 61));
        planning4pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416368571_906095227681180_9098143267016132972_n.png);"));
        label->raise();
        tabWidget->raise();
        abonnement4pb->raise();
        employe4pb->raise();
        activite4pb->raise();
        back4pb->raise();
        pushButton_9->raise();
        planning4pb->raise();
        logoutpb4->raise();

        retranslateUi(pageclient);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pageclient);
    } // setupUi

    void retranslateUi(QDialog *pageclient)
    {
        pageclient->setWindowTitle(QApplication::translate("pageclient", "Dialog", Q_NULLPTR));
        label->setText(QString());
        logoutpb4->setText(QString());
        pb_ajouter->setText(QApplication::translate("pageclient", "Ajouter", Q_NULLPTR));
        pb_modifier_2->setText(QApplication::translate("pageclient", "Modifier", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("pageclient", "supprimer", Q_NULLPTR));
        label_2->setText(QApplication::translate("pageclient", "Cin", Q_NULLPTR));
        label_3->setText(QApplication::translate("pageclient", "Nom", Q_NULLPTR));
        label_4->setText(QApplication::translate("pageclient", "Prenom", Q_NULLPTR));
        label_5->setText(QApplication::translate("pageclient", "Email", Q_NULLPTR));
        label_6->setText(QApplication::translate("pageclient", "Date de naissance", Q_NULLPTR));
        label_7->setText(QApplication::translate("pageclient", "Telephone", Q_NULLPTR));
        label_8->setText(QApplication::translate("pageclient", "Condition phy", Q_NULLPTR));
        label_9->setText(QApplication::translate("pageclient", "niveau scolaire", Q_NULLPTR));
        label_10->setText(QApplication::translate("pageclient", "genre", Q_NULLPTR));
        label_11->setText(QApplication::translate("pageclient", "Adresse", Q_NULLPTR));
        genre_c->clear();
        genre_c->insertItems(0, QStringList()
         << QApplication::translate("pageclient", "homme", Q_NULLPTR)
         << QApplication::translate("pageclient", "femme", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("pageclient", "Gestion des clients", Q_NULLPTR));
        abonnement4pb->setText(QString());
        employe4pb->setText(QString());
        activite4pb->setText(QString());
        back4pb->setText(QString());
        pushButton_9->setText(QString());
        planning4pb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pageclient: public Ui_pageclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGECLIENT_H
