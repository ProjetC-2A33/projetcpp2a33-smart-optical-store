/********************************************************************************
** Form generated from reading UI file 'pageactivite.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEACTIVITE_H
#define UI_PAGEACTIVITE_H

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

class Ui_Pageactivite
{
public:
    QPushButton *abonnement3pb;
    QPushButton *planning3pb;
    QPushButton *client3pb;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tab_activite;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *id_a;
    QLineEdit *nom_a;
    QLineEdit *description_a;
    QLineEdit *duree_a;
    QLineEdit *nbm_a;
    QLineEdit *equipements_a;
    QPushButton *pb_ajouter;
    QPushButton *pb_modifier_2;
    QPushButton *pb_supprimer;
    QLabel *label_8;
    QLineEdit *cin_e;
    QPushButton *logoutpb3;
    QPushButton *back3pb;
    QPushButton *pushButton_14;
    QPushButton *employe3pb;
    QLabel *label_7;

    void setupUi(QDialog *Pageactivite)
    {
        if (Pageactivite->objectName().isEmpty())
            Pageactivite->setObjectName(QStringLiteral("Pageactivite"));
        Pageactivite->resize(1079, 735);
        abonnement3pb = new QPushButton(Pageactivite);
        abonnement3pb->setObjectName(QStringLiteral("abonnement3pb"));
        abonnement3pb->setGeometry(QRect(60, 300, 81, 61));
        abonnement3pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416322058_1151869056186867_7815397858715591504_n.png);"));
        planning3pb = new QPushButton(Pageactivite);
        planning3pb->setObjectName(QStringLiteral("planning3pb"));
        planning3pb->setGeometry(QRect(60, 380, 91, 61));
        planning3pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416368571_906095227681180_9098143267016132972_n.png);"));
        client3pb = new QPushButton(Pageactivite);
        client3pb->setObjectName(QStringLiteral("client3pb"));
        client3pb->setGeometry(QRect(60, 150, 81, 61));
        client3pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415287996_755433109383168_7582230033290630906_n.png);"));
        tabWidget = new QTabWidget(Pageactivite);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(190, 40, 931, 541));
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
        tab_activite = new QTableWidget(tab);
        tab_activite->setObjectName(QStringLiteral("tab_activite"));
        tab_activite->setGeometry(QRect(440, 20, 451, 301));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 81, 31));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 70, 81, 31));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-10, 120, 131, 31));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 160, 91, 31));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 210, 61, 21));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(-10, 240, 171, 41));
        id_a = new QLineEdit(tab);
        id_a->setObjectName(QStringLiteral("id_a"));
        id_a->setGeometry(QRect(100, 30, 311, 31));
        nom_a = new QLineEdit(tab);
        nom_a->setObjectName(QStringLiteral("nom_a"));
        nom_a->setGeometry(QRect(100, 69, 311, 31));
        description_a = new QLineEdit(tab);
        description_a->setObjectName(QStringLiteral("description_a"));
        description_a->setGeometry(QRect(100, 119, 311, 31));
        duree_a = new QLineEdit(tab);
        duree_a->setObjectName(QStringLiteral("duree_a"));
        duree_a->setGeometry(QRect(100, 159, 311, 31));
        nbm_a = new QLineEdit(tab);
        nbm_a->setObjectName(QStringLiteral("nbm_a"));
        nbm_a->setGeometry(QRect(100, 210, 311, 31));
        equipements_a = new QLineEdit(tab);
        equipements_a->setObjectName(QStringLiteral("equipements_a"));
        equipements_a->setGeometry(QRect(100, 249, 311, 31));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(70, 367, 121, 41));
        pb_modifier_2 = new QPushButton(tab);
        pb_modifier_2->setObjectName(QStringLiteral("pb_modifier_2"));
        pb_modifier_2->setGeometry(QRect(240, 367, 131, 41));
        pb_supprimer = new QPushButton(tab);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(410, 367, 111, 41));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(-10, 310, 151, 31));
        cin_e = new QLineEdit(tab);
        cin_e->setObjectName(QStringLiteral("cin_e"));
        cin_e->setGeometry(QRect(130, 310, 271, 31));
        tabWidget->addTab(tab, QString());
        logoutpb3 = new QPushButton(Pageactivite);
        logoutpb3->setObjectName(QStringLiteral("logoutpb3"));
        logoutpb3->setGeometry(QRect(0, 640, 121, 71));
        logoutpb3->setStyleSheet(QStringLiteral("border-image: url(:/img/img/4400629.png);"));
        back3pb = new QPushButton(Pageactivite);
        back3pb->setObjectName(QStringLiteral("back3pb"));
        back3pb->setGeometry(QRect(-40, -10, 201, 181));
        back3pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/gearr.png);"));
        pushButton_14 = new QPushButton(Pageactivite);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(50, 450, 111, 71));
        pushButton_14->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415366346_1746257945859861_8686726138527086848_n.png);"));
        employe3pb = new QPushButton(Pageactivite);
        employe3pb->setObjectName(QStringLiteral("employe3pb"));
        employe3pb->setGeometry(QRect(60, 230, 81, 51));
        employe3pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415260602_915404969798523_5173262210140723394_n.png);"));
        label_7 = new QLabel(Pageactivite);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(-380, 20, 561, 701));
        label_7->setStyleSheet(QStringLiteral("border-image: url(:/img/img/Sidebar2.png);"));
        label_7->raise();
        abonnement3pb->raise();
        planning3pb->raise();
        client3pb->raise();
        tabWidget->raise();
        logoutpb3->raise();
        back3pb->raise();
        pushButton_14->raise();
        employe3pb->raise();

        retranslateUi(Pageactivite);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Pageactivite);
    } // setupUi

    void retranslateUi(QDialog *Pageactivite)
    {
        Pageactivite->setWindowTitle(QApplication::translate("Pageactivite", "Dialog", Q_NULLPTR));
        abonnement3pb->setText(QString());
        planning3pb->setText(QString());
        client3pb->setText(QString());
        label->setText(QApplication::translate("Pageactivite", "Id", Q_NULLPTR));
        label_2->setText(QApplication::translate("Pageactivite", "Nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("Pageactivite", "Description", Q_NULLPTR));
        label_4->setText(QApplication::translate("Pageactivite", "Duree", Q_NULLPTR));
        label_5->setText(QApplication::translate("Pageactivite", "Nbm", Q_NULLPTR));
        label_6->setText(QApplication::translate("Pageactivite", "Equipement", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("Pageactivite", "Ajouter", Q_NULLPTR));
        pb_modifier_2->setText(QApplication::translate("Pageactivite", "Modifer", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("Pageactivite", "Supprimer", Q_NULLPTR));
        label_8->setText(QApplication::translate("Pageactivite", "CIN Employe", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Pageactivite", "Gestion de activite", Q_NULLPTR));
        logoutpb3->setText(QString());
        back3pb->setText(QString());
        pushButton_14->setText(QString());
        employe3pb->setText(QString());
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Pageactivite: public Ui_Pageactivite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEACTIVITE_H
