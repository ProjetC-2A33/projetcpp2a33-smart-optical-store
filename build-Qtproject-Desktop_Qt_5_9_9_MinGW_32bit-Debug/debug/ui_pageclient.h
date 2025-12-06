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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_pageclient
{
public:
    QPushButton *logoutpb4;
    QPushButton *abonnement4pb;
    QPushButton *employe4pb;
    QPushButton *activite4pb;
    QPushButton *back4pb;
    QPushButton *pushButton_9;
    QPushButton *planning4pb;
    QGroupBox *groupBox;
    QLineEdit *niv_c;
    QPushButton *pb_ajouter;
    QLineEdit *adresse_c;
    QComboBox *genre_c;
    QPushButton *pb_supprimer;
    QLineEdit *telephone_c;
    QLineEdit *prenom_c;
    QTableView *tab_clients;
    QLineEdit *cond_c;
    QLabel *label_2;
    QLineEdit *cin_c;
    QLineEdit *nom_c;
    QPushButton *pb_modifier_2;
    QLineEdit *email_c;
    QDateEdit *daten_c;
    QLabel *label;

    void setupUi(QDialog *pageclient)
    {
        if (pageclient->objectName().isEmpty())
            pageclient->setObjectName(QStringLiteral("pageclient"));
        pageclient->resize(1200, 680);
        pageclient->setStyleSheet(QStringLiteral(""));
        logoutpb4 = new QPushButton(pageclient);
        logoutpb4->setObjectName(QStringLiteral("logoutpb4"));
        logoutpb4->setGeometry(QRect(30, 580, 141, 31));
        logoutpb4->setStyleSheet(QStringLiteral("border-image: url(:/img/img/logout.png);"));
        abonnement4pb = new QPushButton(pageclient);
        abonnement4pb->setObjectName(QStringLiteral("abonnement4pb"));
        abonnement4pb->setGeometry(QRect(30, 310, 31, 31));
        abonnement4pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416322058_1151869056186867_7815397858715591504_n.png);"));
        employe4pb = new QPushButton(pageclient);
        employe4pb->setObjectName(QStringLiteral("employe4pb"));
        employe4pb->setGeometry(QRect(30, 240, 31, 31));
        employe4pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415260602_915404969798523_5173262210140723394_n.png);"));
        activite4pb = new QPushButton(pageclient);
        activite4pb->setObjectName(QStringLiteral("activite4pb"));
        activite4pb->setGeometry(QRect(30, 460, 31, 31));
        activite4pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415366346_1746257945859861_8686726138527086848_n.png);"));
        back4pb = new QPushButton(pageclient);
        back4pb->setObjectName(QStringLiteral("back4pb"));
        back4pb->setGeometry(QRect(-30, -30, 211, 191));
        back4pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/gearr.png);"));
        pushButton_9 = new QPushButton(pageclient);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(30, 180, 31, 31));
        pushButton_9->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415287996_755433109383168_7582230033290630906_n.png);"));
        planning4pb = new QPushButton(pageclient);
        planning4pb->setObjectName(QStringLiteral("planning4pb"));
        planning4pb->setGeometry(QRect(30, 390, 31, 31));
        planning4pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416368571_906095227681180_9098143267016132972_n.png);"));
        groupBox = new QGroupBox(pageclient);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(240, 80, 971, 631));
        groupBox->setStyleSheet(QLatin1String("/* Style for QGroupBox */\n"
"background-color: rgb(15, 58, 88);\n"
"QGroupBox {\n"
"    border: 2px solid #CCCCCC; /* Border color */\n"
"    border-radius: 20px; /* Rounded edges for the QGroupBox */\n"
"}\n"
"\n"
"/* Style for QGroupBox title */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 10px; /* Padding for the title */\n"
"}\n"
""));
        niv_c = new QLineEdit(groupBox);
        niv_c->setObjectName(QStringLiteral("niv_c"));
        niv_c->setGeometry(QRect(180, 350, 241, 31));
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(300, 530, 101, 41));
        adresse_c = new QLineEdit(groupBox);
        adresse_c->setObjectName(QStringLiteral("adresse_c"));
        adresse_c->setGeometry(QRect(180, 270, 241, 31));
        genre_c = new QComboBox(groupBox);
        genre_c->setObjectName(QStringLiteral("genre_c"));
        genre_c->setGeometry(QRect(180, 430, 241, 31));
        pb_supprimer = new QPushButton(groupBox);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(70, 530, 91, 41));
        telephone_c = new QLineEdit(groupBox);
        telephone_c->setObjectName(QStringLiteral("telephone_c"));
        telephone_c->setGeometry(QRect(180, 310, 241, 31));
        prenom_c = new QLineEdit(groupBox);
        prenom_c->setObjectName(QStringLiteral("prenom_c"));
        prenom_c->setGeometry(QRect(180, 150, 241, 31));
        tab_clients = new QTableView(groupBox);
        tab_clients->setObjectName(QStringLiteral("tab_clients"));
        tab_clients->setGeometry(QRect(460, 110, 431, 461));
        tab_clients->setStyleSheet(QLatin1String("/* Style for QTableView */\n"
"QTableView {\n"
"    border: 1px solid #ccc; /* Border color */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"}\n"
"\n"
"/* Style for header section */\n"
"QHeaderView::section {\n"
"    background-color: #f0f0f0; /* Background color */\n"
"    border: none; /* Remove border */\n"
"    padding: 4px; /* Padding */\n"
"    font-weight: bold; /* Bold font */\n"
"}\n"
"\n"
"/* Style for alternating row colors */\n"
"QTableView::item {\n"
"    background-color: #ffffff; /* White background */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #c0c0c0; /* Light gray background for selected item */\n"
"}\n"
"\n"
"/* Style for vertical grid lines */\n"
"QTableView::vertical::item {\n"
"    border-right: 1px solid #ccc; /* Vertical grid line color */\n"
"}\n"
"\n"
"/* Style for horizontal grid lines */\n"
"QTableView::horizontal::item {\n"
"    border-bottom: 1px solid #ccc; /* Horizontal grid line color */\n"
"}\n"
""));
        tab_clients->setShowGrid(true);
        tab_clients->setGridStyle(Qt::NoPen);
        tab_clients->setCornerButtonEnabled(false);
        cond_c = new QLineEdit(groupBox);
        cond_c->setObjectName(QStringLiteral("cond_c"));
        cond_c->setGeometry(QRect(180, 390, 241, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 40, 161, 51));
        QFont font;
        font.setFamily(QStringLiteral("Bebas Neue"));
        font.setPointSize(30);
        font.setBold(false);
        font.setWeight(50);
        label_2->setFont(font);
        label_2->setMouseTracking(false);
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"    font-size: 30pt; /* Adjust the size as needed */\n"
"}"));
        label_2->setTextFormat(Qt::AutoText);
        cin_c = new QLineEdit(groupBox);
        cin_c->setObjectName(QStringLiteral("cin_c"));
        cin_c->setGeometry(QRect(180, 190, 241, 31));
        cin_c->setAutoFillBackground(false);
        nom_c = new QLineEdit(groupBox);
        nom_c->setObjectName(QStringLiteral("nom_c"));
        nom_c->setGeometry(QRect(180, 110, 241, 31));
        pb_modifier_2 = new QPushButton(groupBox);
        pb_modifier_2->setObjectName(QStringLiteral("pb_modifier_2"));
        pb_modifier_2->setGeometry(QRect(180, 530, 101, 41));
        email_c = new QLineEdit(groupBox);
        email_c->setObjectName(QStringLiteral("email_c"));
        email_c->setGeometry(QRect(180, 230, 241, 31));
        daten_c = new QDateEdit(groupBox);
        daten_c->setObjectName(QStringLiteral("daten_c"));
        daten_c->setGeometry(QRect(180, 470, 241, 31));
        label = new QLabel(pageclient);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-10, 0, 1211, 691));
        label->setStyleSheet(QStringLiteral("border-image: url(:/img/img/try1.png);"));
        label->raise();
        abonnement4pb->raise();
        employe4pb->raise();
        activite4pb->raise();
        back4pb->raise();
        pushButton_9->raise();
        planning4pb->raise();
        logoutpb4->raise();
        groupBox->raise();

        retranslateUi(pageclient);

        QMetaObject::connectSlotsByName(pageclient);
    } // setupUi

    void retranslateUi(QDialog *pageclient)
    {
        pageclient->setWindowTitle(QApplication::translate("pageclient", "Dialog", Q_NULLPTR));
        logoutpb4->setText(QString());
        abonnement4pb->setText(QString());
        employe4pb->setText(QString());
        activite4pb->setText(QString());
        back4pb->setText(QString());
        pushButton_9->setText(QString());
        planning4pb->setText(QString());
        groupBox->setTitle(QString());
        niv_c->setPlaceholderText(QApplication::translate("pageclient", "Exemple (Coll\303\251ge, Lyc\303\251e, Bac, Bac+1, etc ...)", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("pageclient", "Ajouter", Q_NULLPTR));
        adresse_c->setPlaceholderText(QApplication::translate("pageclient", "Adresse Physique", Q_NULLPTR));
        genre_c->clear();
        genre_c->insertItems(0, QStringList()
         << QApplication::translate("pageclient", "Homme", Q_NULLPTR)
         << QApplication::translate("pageclient", "Femme", Q_NULLPTR)
        );
        pb_supprimer->setText(QApplication::translate("pageclient", "supprimer", Q_NULLPTR));
        telephone_c->setPlaceholderText(QApplication::translate("pageclient", "Num\303\251ro de T\303\251lephone", Q_NULLPTR));
        prenom_c->setPlaceholderText(QApplication::translate("pageclient", "Pr\303\250nom de Client", Q_NULLPTR));
        cond_c->setPlaceholderText(QApplication::translate("pageclient", "Maladie ou Cas sp\303\251ciale", Q_NULLPTR));
        label_2->setText(QApplication::translate("pageclient", "CLIENTS LIST", Q_NULLPTR));
        cin_c->setPlaceholderText(QApplication::translate("pageclient", "Num\303\251ro CIN", Q_NULLPTR));
        nom_c->setPlaceholderText(QApplication::translate("pageclient", "Nom de Client", Q_NULLPTR));
        pb_modifier_2->setText(QApplication::translate("pageclient", "Modifier", Q_NULLPTR));
        email_c->setPlaceholderText(QApplication::translate("pageclient", "Adresse Email (Exemple@gmail.com)", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pageclient: public Ui_pageclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGECLIENT_H
