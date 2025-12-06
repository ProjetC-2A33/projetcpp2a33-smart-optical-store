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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QLineEdit *type_ab;
    QLineEdit *datef_ab;
    QLineEdit *dated_ab;
    QLineEdit *mode_ab;
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
        tabWidget->setGeometry(QRect(200, 10, 1051, 731));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        Group = new QGroupBox(tab);
        Group->setObjectName(QStringLiteral("Group"));
        Group->setGeometry(QRect(0, 0, 1061, 691));
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
        label = new QLabel(Group);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 130, 141, 51));
        label_2 = new QLabel(Group);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 190, 111, 31));
        label_3 = new QLabel(Group);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 230, 111, 51));
        label_4 = new QLabel(Group);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 280, 111, 51));
        label_6 = new QLabel(Group);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 350, 151, 41));
        cin_ab = new QLineEdit(Group);
        cin_ab->setObjectName(QStringLiteral("cin_ab"));
        cin_ab->setGeometry(QRect(170, 140, 251, 31));
        type_ab = new QLineEdit(Group);
        type_ab->setObjectName(QStringLiteral("type_ab"));
        type_ab->setGeometry(QRect(170, 290, 251, 31));
        datef_ab = new QLineEdit(Group);
        datef_ab->setObjectName(QStringLiteral("datef_ab"));
        datef_ab->setGeometry(QRect(170, 240, 251, 31));
        dated_ab = new QLineEdit(Group);
        dated_ab->setObjectName(QStringLiteral("dated_ab"));
        dated_ab->setGeometry(QRect(170, 190, 251, 31));
        mode_ab = new QLineEdit(Group);
        mode_ab->setObjectName(QStringLiteral("mode_ab"));
        mode_ab->setGeometry(QRect(170, 360, 251, 31));
        pb_modifier_2 = new QPushButton(Group);
        pb_modifier_2->setObjectName(QStringLiteral("pb_modifier_2"));
        pb_modifier_2->setGeometry(QRect(270, 600, 131, 41));
        pb_ajouter = new QPushButton(Group);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(70, 600, 161, 41));
        tab_abonnements = new QTableWidget(Group);
        tab_abonnements->setObjectName(QStringLiteral("tab_abonnements"));
        tab_abonnements->setGeometry(QRect(490, 140, 421, 421));
        pb_supprimer = new QPushButton(Group);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(450, 600, 121, 41));
        label_5 = new QLabel(Group);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 420, 151, 41));
        cin_c = new QLineEdit(Group);
        cin_c->setObjectName(QStringLiteral("cin_c"));
        cin_c->setGeometry(QRect(170, 430, 241, 31));
        label_8 = new QLabel(Group);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 480, 121, 31));
        id_a = new QLineEdit(Group);
        id_a->setObjectName(QStringLiteral("id_a"));
        id_a->setGeometry(QRect(170, 490, 241, 21));
        label_9 = new QLabel(Group);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(400, 100, 71, 31));
        sortAscButton = new QPushButton(Group);
        sortAscButton->setObjectName(QStringLiteral("sortAscButton"));
        sortAscButton->setGeometry(QRect(490, 100, 221, 28));
        sortDescButton = new QPushButton(Group);
        sortDescButton->setObjectName(QStringLiteral("sortDescButton"));
        sortDescButton->setGeometry(QRect(702, 100, 211, 28));
        tabWidget->addTab(tab, QString());
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
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Pageabonnements", "Gestion d'abonnements", Q_NULLPTR));
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
