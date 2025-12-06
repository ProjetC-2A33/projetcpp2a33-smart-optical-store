/********************************************************************************
** Form generated from reading UI file 'pageabonnements.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEABONNEMENTS_H
#define UI_PAGEABONNEMENTS_H

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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pageabonnements
{
public:
    QPushButton *activite2pb;
    QPushButton *logoutpb2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *Group;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *cin_ab;
    QPushButton *pb_modifier_2;
    QPushButton *pb_ajouter;
    QTableWidget *tab_abonnements;
    QPushButton *pb_supprimer;
    QLabel *label_5;
    QLineEdit *cin_c;
    QLabel *label_8;
    QLineEdit *id_a;
    QLabel *label_9;
    QPushButton *sortAscButton;
    QPushButton *sortDescButton;
    QDateEdit *dated_ab;
    QDateEdit *datef_ab;
    QComboBox *type_ab;
    QComboBox *mode_ab;
    QLabel *label_10;
    QComboBox *prix_ab;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *lab_chart_pie;
    QLabel *lab_chart_bar;
    QGroupBox *groupBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *meteo;
    QLabel *label_35;
    QWidget *tab_2;
    QGroupBox *groupBox_7;
    QLabel *label_53;
    QLabel *label_54;
    QLineEdit *rcpt;
    QLineEdit *subject;
    QLabel *label_56;
    QPlainTextEdit *msg;
    QPushButton *sendBtn2;
    QLabel *label_34;
    QPushButton *client2pb;
    QPushButton *planning2pb;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *employepb;
    QPushButton *back2pb;

    void setupUi(QDialog *Pageabonnements)
    {
        if (Pageabonnements->objectName().isEmpty())
            Pageabonnements->setObjectName(QStringLiteral("Pageabonnements"));
        Pageabonnements->resize(1265, 759);
        activite2pb = new QPushButton(Pageabonnements);
        activite2pb->setObjectName(QStringLiteral("activite2pb"));
        activite2pb->setGeometry(QRect(40, 450, 111, 71));
        activite2pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415366346_1746257945859861_8686726138527086848_n.png);"));
        logoutpb2 = new QPushButton(Pageabonnements);
        logoutpb2->setObjectName(QStringLiteral("logoutpb2"));
        logoutpb2->setGeometry(QRect(10, 620, 91, 51));
        logoutpb2->setStyleSheet(QStringLiteral("border-image: url(:/img/img/4400629.png);"));
        tabWidget = new QTabWidget(Pageabonnements);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(200, 0, 1051, 931));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        Group = new QGroupBox(tab);
        Group->setObjectName(QStringLiteral("Group"));
        Group->setGeometry(QRect(0, 0, 1061, 721));
        Group->setStyleSheet(QLatin1String("\n"
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
"    color: white; /* Text color for labels */\n"
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
        label = new QLabel(Group);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 120, 141, 51));
        label_2 = new QLabel(Group);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 180, 111, 31));
        label_3 = new QLabel(Group);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 220, 111, 51));
        label_4 = new QLabel(Group);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 280, 111, 51));
        label_6 = new QLabel(Group);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 400, 151, 41));
        cin_ab = new QLineEdit(Group);
        cin_ab->setObjectName(QStringLiteral("cin_ab"));
        cin_ab->setGeometry(QRect(170, 130, 251, 31));
        pb_modifier_2 = new QPushButton(Group);
        pb_modifier_2->setObjectName(QStringLiteral("pb_modifier_2"));
        pb_modifier_2->setGeometry(QRect(210, 550, 131, 41));
        pb_ajouter = new QPushButton(Group);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(30, 550, 161, 41));
        tab_abonnements = new QTableWidget(Group);
        tab_abonnements->setObjectName(QStringLiteral("tab_abonnements"));
        tab_abonnements->setGeometry(QRect(490, 140, 511, 421));
        pb_supprimer = new QPushButton(Group);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(350, 550, 121, 41));
        label_5 = new QLabel(Group);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 450, 151, 41));
        cin_c = new QLineEdit(Group);
        cin_c->setObjectName(QStringLiteral("cin_c"));
        cin_c->setGeometry(QRect(170, 450, 251, 31));
        label_8 = new QLabel(Group);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 500, 121, 41));
        id_a = new QLineEdit(Group);
        id_a->setObjectName(QStringLiteral("id_a"));
        id_a->setGeometry(QRect(170, 500, 251, 31));
        label_9 = new QLabel(Group);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(420, 90, 71, 31));
        sortAscButton = new QPushButton(Group);
        sortAscButton->setObjectName(QStringLiteral("sortAscButton"));
        sortAscButton->setGeometry(QRect(490, 110, 251, 28));
        sortDescButton = new QPushButton(Group);
        sortDescButton->setObjectName(QStringLiteral("sortDescButton"));
        sortDescButton->setGeometry(QRect(740, 110, 261, 28));
        dated_ab = new QDateEdit(Group);
        dated_ab->setObjectName(QStringLiteral("dated_ab"));
        dated_ab->setGeometry(QRect(170, 180, 251, 31));
        datef_ab = new QDateEdit(Group);
        datef_ab->setObjectName(QStringLiteral("datef_ab"));
        datef_ab->setGeometry(QRect(170, 230, 251, 31));
        type_ab = new QComboBox(Group);
        type_ab->setObjectName(QStringLiteral("type_ab"));
        type_ab->setGeometry(QRect(170, 290, 251, 31));
        mode_ab = new QComboBox(Group);
        mode_ab->setObjectName(QStringLiteral("mode_ab"));
        mode_ab->setGeometry(QRect(170, 400, 251, 31));
        label_10 = new QLabel(Group);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 350, 131, 41));
        prix_ab = new QComboBox(Group);
        prix_ab->setObjectName(QStringLiteral("prix_ab"));
        prix_ab->setGeometry(QRect(170, 350, 251, 31));
        pushButton_2 = new QPushButton(Group);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 610, 161, 41));
        pushButton_4 = new QPushButton(Group);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(350, 610, 131, 41));
        pushButton_5 = new QPushButton(Group);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(210, 610, 131, 41));
        lab_chart_pie = new QLabel(Group);
        lab_chart_pie->setObjectName(QStringLiteral("lab_chart_pie"));
        lab_chart_pie->setGeometry(QRect(540, 160, 621, 451));
        lab_chart_bar = new QLabel(Group);
        lab_chart_bar->setObjectName(QStringLiteral("lab_chart_bar"));
        lab_chart_bar->setGeometry(QRect(600, 150, 451, 391));
        groupBox = new QGroupBox(Group);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(490, 570, 511, 141));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 90, 191, 41));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(230, 20, 121, 41));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 20, 191, 41));
        meteo = new QLabel(Group);
        meteo->setObjectName(QStringLiteral("meteo"));
        meteo->setGeometry(QRect(620, 170, 401, 371));
        label_35 = new QLabel(Group);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(-10, -10, 1171, 801));
        label_35->setStyleSheet(QStringLiteral("border-image: url(:/img/img/sports-nautiques.jpg);"));
        label_35->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_6->raise();
        cin_ab->raise();
        pb_modifier_2->raise();
        pb_ajouter->raise();
        tab_abonnements->raise();
        pb_supprimer->raise();
        label_5->raise();
        cin_c->raise();
        label_8->raise();
        id_a->raise();
        label_9->raise();
        sortAscButton->raise();
        sortDescButton->raise();
        dated_ab->raise();
        datef_ab->raise();
        type_ab->raise();
        mode_ab->raise();
        label_10->raise();
        prix_ab->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        lab_chart_pie->raise();
        lab_chart_bar->raise();
        groupBox->raise();
        meteo->raise();
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 0, 1171, 801));
        groupBox_7->setStyleSheet(QLatin1String("\n"
"/* Style for QGroupBox */\n"
"QRadioButton{ color: white; /* Text color for labels */\n"
"    font-size: 16px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}\n"
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
"    color: white; /* Text color for labels */\n"
"    font-size: 16px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}\n"
"\n"
"/* Style for QPushButton */\n"
"QPushButton {\n"
"    background-color: #3498db;"
                        " /* Blue color for buttons */\n"
"    border: 1px solid #2980b9; /* Border color for buttons */\n"
"    border-radius: 5px; /* Border radius for buttons */\n"
"    padding: 5px 10px; /* Adjust padding as needed */\n"
"    color: white; /* Text color on buttons */\n"
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
        label_53 = new QLabel(groupBox_7);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(50, 80, 191, 31));
        label_54 = new QLabel(groupBox_7);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(40, 160, 171, 31));
        rcpt = new QLineEdit(groupBox_7);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(290, 80, 501, 30));
        rcpt->setStyleSheet(QStringLiteral(""));
        subject = new QLineEdit(groupBox_7);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(290, 150, 501, 30));
        subject->setStyleSheet(QStringLiteral(""));
        label_56 = new QLabel(groupBox_7);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(51, 276, 171, 31));
        msg = new QPlainTextEdit(groupBox_7);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(290, 240, 511, 150));
        sendBtn2 = new QPushButton(groupBox_7);
        sendBtn2->setObjectName(QStringLiteral("sendBtn2"));
        sendBtn2->setGeometry(QRect(500, 450, 93, 28));
        label_34 = new QLabel(groupBox_7);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(0, 0, 1171, 801));
        label_34->setStyleSheet(QStringLiteral("border-image: url(:/img/img/sports-nautiques.jpg);"));
        label_34->raise();
        label_53->raise();
        label_54->raise();
        rcpt->raise();
        subject->raise();
        label_56->raise();
        msg->raise();
        sendBtn2->raise();
        tabWidget->addTab(tab_2, QString());
        client2pb = new QPushButton(Pageabonnements);
        client2pb->setObjectName(QStringLiteral("client2pb"));
        client2pb->setGeometry(QRect(60, 110, 71, 61));
        client2pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415287996_755433109383168_7582230033290630906_n.png);"));
        planning2pb = new QPushButton(Pageabonnements);
        planning2pb->setObjectName(QStringLiteral("planning2pb"));
        planning2pb->setGeometry(QRect(50, 370, 91, 51));
        planning2pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416368571_906095227681180_9098143267016132972_n.png);"));
        label_7 = new QLabel(Pageabonnements);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(-460, -70, 661, 851));
        label_7->setStyleSheet(QStringLiteral("border-image: url(:/img/img/Sidebar2.png);"));
        pushButton = new QPushButton(Pageabonnements);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 280, 81, 61));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416322058_1151869056186867_7815397858715591504_n.png);"));
        employepb = new QPushButton(Pageabonnements);
        employepb->setObjectName(QStringLiteral("employepb"));
        employepb->setGeometry(QRect(70, 200, 61, 61));
        employepb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415260602_915404969798523_5173262210140723394_n.png);"));
        back2pb = new QPushButton(Pageabonnements);
        back2pb->setObjectName(QStringLiteral("back2pb"));
        back2pb->setGeometry(QRect(-50, -40, 221, 151));
        back2pb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/gearr.png);"));
        label_7->raise();
        activite2pb->raise();
        logoutpb2->raise();
        tabWidget->raise();
        client2pb->raise();
        planning2pb->raise();
        pushButton->raise();
        employepb->raise();
        back2pb->raise();

        retranslateUi(Pageabonnements);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Pageabonnements);
    } // setupUi

    void retranslateUi(QDialog *Pageabonnements)
    {
        Pageabonnements->setWindowTitle(QApplication::translate("Pageabonnements", "Dialog", Q_NULLPTR));
        activite2pb->setText(QString());
        logoutpb2->setText(QString());
        Group->setTitle(QString());
        label->setText(QApplication::translate("Pageabonnements", "Cin", Q_NULLPTR));
        label_2->setText(QApplication::translate("Pageabonnements", "Date debut", Q_NULLPTR));
        label_3->setText(QApplication::translate("Pageabonnements", "Date fin", Q_NULLPTR));
        label_4->setText(QApplication::translate("Pageabonnements", "Type sport", Q_NULLPTR));
        label_6->setText(QApplication::translate("Pageabonnements", "Mode Payement", Q_NULLPTR));
        pb_modifier_2->setText(QApplication::translate("Pageabonnements", "Modifier", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("Pageabonnements", "Ajouter", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("Pageabonnements", "Supprimer", Q_NULLPTR));
        label_5->setText(QApplication::translate("Pageabonnements", "cin client", Q_NULLPTR));
        label_8->setText(QApplication::translate("Pageabonnements", "Id activite", Q_NULLPTR));
        label_9->setText(QApplication::translate("Pageabonnements", "Trier", Q_NULLPTR));
        sortAscButton->setText(QApplication::translate("Pageabonnements", "ASC", Q_NULLPTR));
        sortDescButton->setText(QApplication::translate("Pageabonnements", "DESC", Q_NULLPTR));
        type_ab->clear();
        type_ab->insertItems(0, QStringList()
         << QApplication::translate("Pageabonnements", "KAYAKING", Q_NULLPTR)
         << QApplication::translate("Pageabonnements", "JETSKY", Q_NULLPTR)
         << QApplication::translate("Pageabonnements", "WIND SURFING", Q_NULLPTR)
         << QApplication::translate("Pageabonnements", "SAIING", Q_NULLPTR)
         << QApplication::translate("Pageabonnements", "SAILING", Q_NULLPTR)
         << QApplication::translate("Pageabonnements", "PARASAILING", Q_NULLPTR)
         << QApplication::translate("Pageabonnements", "SCABADIVING", Q_NULLPTR)
        );
        mode_ab->clear();
        mode_ab->insertItems(0, QStringList()
         << QApplication::translate("Pageabonnements", "CARTE BANCAIRE", Q_NULLPTR)
         << QApplication::translate("Pageabonnements", "ESPECE", Q_NULLPTR)
         << QApplication::translate("Pageabonnements", "CHEQUE BANCAIRE", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("Pageabonnements", "Prix de sport", Q_NULLPTR));
        prix_ab->clear();
        prix_ab->insertItems(0, QStringList()
         << QApplication::translate("Pageabonnements", "PACK MENSUEL 500 DT", Q_NULLPTR)
         << QApplication::translate("Pageabonnements", "PACK PRIMUN 3 MONTHS 1000 DT", Q_NULLPTR)
         << QApplication::translate("Pageabonnements", "PACK ONETIME A DAY 50 DT", Q_NULLPTR)
        );
        pushButton_2->setText(QApplication::translate("Pageabonnements", "Telecharger en PDF", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Pageabonnements", "Stats Par type AB", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Pageabonnements", "Stats par Activit\303\251", Q_NULLPTR));
        lab_chart_pie->setText(QString());
        lab_chart_bar->setText(QString());
        groupBox->setTitle(QApplication::translate("Pageabonnements", "Fonctionalit\303\251s Avanc\303\251es", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Pageabonnements", "Gestion Administrative", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Pageabonnements", "Map", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Pageabonnements", "Calendrier Evenementiel", Q_NULLPTR));
        meteo->setText(QString());
        label_35->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Pageabonnements", "Gestion d'abonnements", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("Pageabonnements", "SMTP", Q_NULLPTR));
        label_53->setText(QApplication::translate("Pageabonnements", "Email", Q_NULLPTR));
        label_54->setText(QApplication::translate("Pageabonnements", "Sujet:", Q_NULLPTR));
        label_56->setText(QApplication::translate("Pageabonnements", "Message:", Q_NULLPTR));
        sendBtn2->setText(QApplication::translate("Pageabonnements", "Envoyer", Q_NULLPTR));
        label_34->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Pageabonnements", "Send Notification", Q_NULLPTR));
        client2pb->setText(QString());
        planning2pb->setText(QString());
        label_7->setText(QString());
        pushButton->setText(QString());
        employepb->setText(QString());
        back2pb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Pageabonnements: public Ui_Pageabonnements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEABONNEMENTS_H
