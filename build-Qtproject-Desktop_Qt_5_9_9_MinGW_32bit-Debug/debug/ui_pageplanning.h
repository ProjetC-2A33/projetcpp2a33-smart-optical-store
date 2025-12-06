/********************************************************************************
** Form generated from reading UI file 'pageplanning.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEPLANNING_H
#define UI_PAGEPLANNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageplanning
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *id_p;
    QLineEdit *nom_p;
    QLineEdit *type_p;
    QLineEdit *duree_p;
    QLineEdit *date_p;
    QLineEdit *place_p;
    QLineEdit *nb_p;
    QPushButton *pb_ajouter;
    QPushButton *pb_modifier;
    QPushButton *pb_supprimer;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QTableWidget *tab_planning;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *id_pp;
    QLineEdit *nom_pp;
    QLineEdit *type_pp;
    QLineEdit *duree_pp;
    QLineEdit *date_pp;
    QLineEdit *place_pp;
    QLineEdit *nb_pp;
    QPushButton *pb_ajouterr;
    QPushButton *pb_modifierr;
    QPushButton *pb_supprimerr;
    QPushButton *planning5pb;
    QPushButton *activite5pb;
    QPushButton *client5pb;
    QPushButton *employe5pb;
    QPushButton *abonnement5pb;
    QPushButton *back5pb;
    QPushButton *pushButton_13;
    QLabel *label_15;
    QPushButton *logoutpb5;

    void setupUi(QDialog *pageplanning)
    {
        if (pageplanning->objectName().isEmpty())
            pageplanning->setObjectName(QStringLiteral("pageplanning"));
        pageplanning->resize(1128, 735);
        tabWidget = new QTabWidget(pageplanning);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(180, 10, 911, 611));
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
        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(510, 10, 381, 421));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 30, 121, 41));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 110, 91, 21));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 143, 121, 31));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 210, 71, 41));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 253, 101, 31));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 293, 81, 31));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 360, 47, 14));
        id_p = new QLineEdit(tab);
        id_p->setObjectName(QStringLiteral("id_p"));
        id_p->setGeometry(QRect(190, 40, 113, 20));
        nom_p = new QLineEdit(tab);
        nom_p->setObjectName(QStringLiteral("nom_p"));
        nom_p->setGeometry(QRect(140, 110, 113, 20));
        type_p = new QLineEdit(tab);
        type_p->setObjectName(QStringLiteral("type_p"));
        type_p->setGeometry(QRect(160, 160, 113, 20));
        duree_p = new QLineEdit(tab);
        duree_p->setObjectName(QStringLiteral("duree_p"));
        duree_p->setGeometry(QRect(150, 220, 113, 20));
        date_p = new QLineEdit(tab);
        date_p->setObjectName(QStringLiteral("date_p"));
        date_p->setGeometry(QRect(150, 260, 113, 20));
        place_p = new QLineEdit(tab);
        place_p->setObjectName(QStringLiteral("place_p"));
        place_p->setGeometry(QRect(160, 300, 113, 20));
        nb_p = new QLineEdit(tab);
        nb_p->setObjectName(QStringLiteral("nb_p"));
        nb_p->setGeometry(QRect(160, 350, 113, 20));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(70, 450, 93, 28));
        pb_modifier = new QPushButton(tab);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(260, 460, 93, 28));
        pb_supprimer = new QPushButton(tab);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(490, 470, 93, 28));
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, -20, 911, 611));
        tabWidget_2->setStyleSheet(QLatin1String("\n"
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
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_planning = new QTableWidget(tab_2);
        tab_planning->setObjectName(QStringLiteral("tab_planning"));
        tab_planning->setGeometry(QRect(510, 10, 381, 421));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 50, 121, 41));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 110, 91, 21));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 160, 121, 31));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(70, 210, 71, 41));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(80, 253, 101, 31));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(70, 293, 81, 31));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(70, 340, 111, 41));
        id_pp = new QLineEdit(tab_2);
        id_pp->setObjectName(QStringLiteral("id_pp"));
        id_pp->setGeometry(QRect(150, 50, 291, 31));
        nom_pp = new QLineEdit(tab_2);
        nom_pp->setObjectName(QStringLiteral("nom_pp"));
        nom_pp->setGeometry(QRect(150, 100, 291, 31));
        type_pp = new QLineEdit(tab_2);
        type_pp->setObjectName(QStringLiteral("type_pp"));
        type_pp->setGeometry(QRect(150, 160, 291, 31));
        duree_pp = new QLineEdit(tab_2);
        duree_pp->setObjectName(QStringLiteral("duree_pp"));
        duree_pp->setGeometry(QRect(150, 209, 291, 31));
        date_pp = new QLineEdit(tab_2);
        date_pp->setObjectName(QStringLiteral("date_pp"));
        date_pp->setGeometry(QRect(150, 249, 291, 31));
        place_pp = new QLineEdit(tab_2);
        place_pp->setObjectName(QStringLiteral("place_pp"));
        place_pp->setGeometry(QRect(150, 289, 291, 31));
        nb_pp = new QLineEdit(tab_2);
        nb_pp->setObjectName(QStringLiteral("nb_pp"));
        nb_pp->setGeometry(QRect(150, 339, 291, 31));
        pb_ajouterr = new QPushButton(tab_2);
        pb_ajouterr->setObjectName(QStringLiteral("pb_ajouterr"));
        pb_ajouterr->setGeometry(QRect(70, 437, 151, 41));
        pb_modifierr = new QPushButton(tab_2);
        pb_modifierr->setObjectName(QStringLiteral("pb_modifierr"));
        pb_modifierr->setGeometry(QRect(260, 437, 121, 41));
        pb_supprimerr = new QPushButton(tab_2);
        pb_supprimerr->setObjectName(QStringLiteral("pb_supprimerr"));
        pb_supprimerr->setGeometry(QRect(590, 440, 131, 41));
        tabWidget_2->addTab(tab_2, QString());
        tabWidget->addTab(tab, QString());
        planning5pb = new QPushButton(pageplanning);
        planning5pb->setObjectName(QStringLiteral("planning5pb"));
        planning5pb->setGeometry(QRect(50, 420, 91, 61));
        planning5pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416368571_906095227681180_9098143267016132972_n.png);"));
        activite5pb = new QPushButton(pageplanning);
        activite5pb->setObjectName(QStringLiteral("activite5pb"));
        activite5pb->setGeometry(QRect(40, 500, 111, 71));
        activite5pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415366346_1746257945859861_8686726138527086848_n.png);"));
        client5pb = new QPushButton(pageplanning);
        client5pb->setObjectName(QStringLiteral("client5pb"));
        client5pb->setGeometry(QRect(50, 140, 81, 61));
        client5pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415287996_755433109383168_7582230033290630906_n.png);"));
        employe5pb = new QPushButton(pageplanning);
        employe5pb->setObjectName(QStringLiteral("employe5pb"));
        employe5pb->setGeometry(QRect(60, 230, 81, 51));
        employe5pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415260602_915404969798523_5173262210140723394_n.png);"));
        abonnement5pb = new QPushButton(pageplanning);
        abonnement5pb->setObjectName(QStringLiteral("abonnement5pb"));
        abonnement5pb->setGeometry(QRect(60, 320, 81, 61));
        abonnement5pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416322058_1151869056186867_7815397858715591504_n.png);"));
        back5pb = new QPushButton(pageplanning);
        back5pb->setObjectName(QStringLiteral("back5pb"));
        back5pb->setGeometry(QRect(-30, -30, 201, 181));
        back5pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/gearr.png);"));
        pushButton_13 = new QPushButton(pageplanning);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(180, 870, 121, 71));
        pushButton_13->setStyleSheet(QStringLiteral("border-image: url(:/img/img/4400629.png);"));
        label_15 = new QLabel(pageplanning);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(-380, 0, 561, 701));
        label_15->setStyleSheet(QStringLiteral("border-image: url(:/img/img/img.jpg);"));
        logoutpb5 = new QPushButton(pageplanning);
        logoutpb5->setObjectName(QStringLiteral("logoutpb5"));
        logoutpb5->setGeometry(QRect(20, 620, 121, 61));
        logoutpb5->setStyleSheet(QStringLiteral("border-image: url(:/img/img/4400629.png);"));
        label_15->raise();
        tabWidget->raise();
        planning5pb->raise();
        activite5pb->raise();
        client5pb->raise();
        employe5pb->raise();
        abonnement5pb->raise();
        back5pb->raise();
        pushButton_13->raise();
        logoutpb5->raise();

        retranslateUi(pageplanning);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pageplanning);
    } // setupUi

    void retranslateUi(QDialog *pageplanning)
    {
        pageplanning->setWindowTitle(QApplication::translate("pageplanning", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("pageplanning", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("pageplanning", "Nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("pageplanning", "Type", Q_NULLPTR));
        label_4->setText(QApplication::translate("pageplanning", "Duree", Q_NULLPTR));
        label_5->setText(QApplication::translate("pageplanning", "Date", Q_NULLPTR));
        label_6->setText(QApplication::translate("pageplanning", "Place", Q_NULLPTR));
        label_7->setText(QApplication::translate("pageplanning", "Nb", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("pageplanning", "Ajouter", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("pageplanning", "Modifier", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("pageplanning", "Supprimer", Q_NULLPTR));
        label_8->setText(QApplication::translate("pageplanning", "ID", Q_NULLPTR));
        label_9->setText(QApplication::translate("pageplanning", "Nom", Q_NULLPTR));
        label_10->setText(QApplication::translate("pageplanning", "Type", Q_NULLPTR));
        label_11->setText(QApplication::translate("pageplanning", "Duree", Q_NULLPTR));
        label_12->setText(QApplication::translate("pageplanning", "Date", Q_NULLPTR));
        label_13->setText(QApplication::translate("pageplanning", "Place", Q_NULLPTR));
        label_14->setText(QApplication::translate("pageplanning", "Nb", Q_NULLPTR));
        pb_ajouterr->setText(QApplication::translate("pageplanning", "Ajouter", Q_NULLPTR));
        pb_modifierr->setText(QApplication::translate("pageplanning", "Modifier", Q_NULLPTR));
        pb_supprimerr->setText(QApplication::translate("pageplanning", "Supprimer", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("pageplanning", "Gestion des planning", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("pageplanning", "Gestion des planning", Q_NULLPTR));
        planning5pb->setText(QString());
        activite5pb->setText(QString());
        client5pb->setText(QString());
        employe5pb->setText(QString());
        abonnement5pb->setText(QString());
        back5pb->setText(QString());
        pushButton_13->setText(QString());
        label_15->setText(QString());
        logoutpb5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pageplanning: public Ui_pageplanning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEPLANNING_H
