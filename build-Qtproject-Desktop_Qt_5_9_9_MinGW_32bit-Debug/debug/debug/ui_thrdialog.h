/********************************************************************************
** Form generated from reading UI file 'thrdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRDIALOG_H
#define UI_THRDIALOG_H

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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thrDialog
{
public:
    QPushButton *logoutpb;
    QPushButton *planningpb;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QPushButton *pb_ajouter;
    QLineEdit *cin_e;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *nom_e;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *prenom_e;
    QLabel *label_6;
    QLineEdit *daten_e;
    QLabel *label_9;
    QLineEdit *salaire_e;
    QLabel *label_5;
    QLineEdit *datee_e;
    QTableView *tab_employes;
    QComboBox *role_e;
    QLabel *label_21;
    QLineEdit *telephone_e;
    QLabel *label_22;
    QLineEdit *adresse_e;
    QLabel *label_23;
    QLineEdit *email_e;
    QPushButton *pb_modifier_2;
    QPushButton *pb_supprimer;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QPushButton *sortAscButton;
    QPushButton *sortDescButton;
    QLabel *label_8;
    QPushButton *bg_pb;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_13;
    QLineEdit *user_e;
    QLabel *label_14;
    QLineEdit *pas_e;
    QPushButton *pb_pdf;
    QPushButton *pb_word;
    QPushButton *refrech_pb;
    QPushButton *pushButton;
    QLabel *label_20;
    QPushButton *statrole;
    QLabel *lab_chart_pie;
    QLabel *lab_chart_bar;
    QPushButton *Imprimer;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QTableView *tab_employes_2;
    QLabel *label_31;
    QTableView *tableView;
    QWidget *tab_3;
    QGroupBox *groupBox_3;
    QPushButton *pb_ajouter_3;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_26;
    QLabel *label_28;
    QPushButton *start_Camera;
    QPushButton *Stop_Camera;
    QLabel *imgLabel;
    QWidget *tab_5;
    QLabel *label_35;
    QTableView *month;
    QWidget *tab_4;
    QLabel *label_34;
    QGroupBox *groupBox_7;
    QLabel *label_53;
    QLabel *label_54;
    QLineEdit *rcpt;
    QLineEdit *subject;
    QLabel *label_56;
    QPlainTextEdit *msg;
    QPushButton *sendBtn2;
    QPushButton *pushButton_3;
    QPushButton *activitepb;
    QPushButton *clientpb;
    QPushButton *abonnementpb;
    QPushButton *backpb;
    QLabel *label_10;

    void setupUi(QDialog *thrDialog)
    {
        if (thrDialog->objectName().isEmpty())
            thrDialog->setObjectName(QStringLiteral("thrDialog"));
        thrDialog->resize(1392, 823);
        logoutpb = new QPushButton(thrDialog);
        logoutpb->setObjectName(QStringLiteral("logoutpb"));
        logoutpb->setGeometry(QRect(10, 680, 181, 81));
        logoutpb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/logout.png);"));
        planningpb = new QPushButton(thrDialog);
        planningpb->setObjectName(QStringLiteral("planningpb"));
        planningpb->setGeometry(QRect(20, 380, 51, 31));
        planningpb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416368571_906095227681180_9098143267016132972_n.png);"));
        tabWidget = new QTabWidget(thrDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(210, 0, 1181, 821));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(-40, 0, 1211, 821));
        groupBox->setStyleSheet(QLatin1String("\n"
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
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(210, 710, 141, 51));
        pb_ajouter->setStyleSheet(QStringLiteral(""));
        cin_e = new QLineEdit(groupBox);
        cin_e->setObjectName(QStringLiteral("cin_e"));
        cin_e->setGeometry(QRect(190, 100, 291, 31));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 460, 111, 41));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 160, 88, 30));
        label->setStyleSheet(QStringLiteral(""));
        nom_e = new QLineEdit(groupBox);
        nom_e->setObjectName(QStringLiteral("nom_e"));
        nom_e->setGeometry(QRect(190, 150, 291, 31));
        nom_e->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 100, 91, 30));
        label_2->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 200, 166, 30));
        label_3->setStyleSheet(QStringLiteral(""));
        prenom_e = new QLineEdit(groupBox);
        prenom_e->setObjectName(QStringLiteral("prenom_e"));
        prenom_e->setGeometry(QRect(190, 200, 291, 31));
        prenom_e->setStyleSheet(QStringLiteral(""));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 360, 181, 51));
        label_6->setStyleSheet(QStringLiteral(""));
        daten_e = new QLineEdit(groupBox);
        daten_e->setObjectName(QStringLiteral("daten_e"));
        daten_e->setGeometry(QRect(190, 370, 291, 31));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 520, 101, 30));
        label_9->setStyleSheet(QStringLiteral(""));
        salaire_e = new QLineEdit(groupBox);
        salaire_e->setObjectName(QStringLiteral("salaire_e"));
        salaire_e->setGeometry(QRect(190, 510, 291, 31));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 420, 151, 31));
        datee_e = new QLineEdit(groupBox);
        datee_e->setObjectName(QStringLiteral("datee_e"));
        datee_e->setGeometry(QRect(190, 410, 291, 31));
        tab_employes = new QTableView(groupBox);
        tab_employes->setObjectName(QStringLiteral("tab_employes"));
        tab_employes->setGeometry(QRect(500, 110, 431, 441));
        tab_employes->setStyleSheet(QStringLiteral(""));
        role_e = new QComboBox(groupBox);
        role_e->setObjectName(QStringLiteral("role_e"));
        role_e->setGeometry(QRect(190, 461, 291, 31));
        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(50, 270, 151, 41));
        telephone_e = new QLineEdit(groupBox);
        telephone_e->setObjectName(QStringLiteral("telephone_e"));
        telephone_e->setGeometry(QRect(190, 280, 291, 31));
        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(70, 240, 121, 31));
        adresse_e = new QLineEdit(groupBox);
        adresse_e->setObjectName(QStringLiteral("adresse_e"));
        adresse_e->setGeometry(QRect(190, 239, 291, 31));
        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(80, 320, 71, 31));
        email_e = new QLineEdit(groupBox);
        email_e->setObjectName(QStringLiteral("email_e"));
        email_e->setGeometry(QRect(190, 319, 291, 31));
        pb_modifier_2 = new QPushButton(groupBox);
        pb_modifier_2->setObjectName(QStringLiteral("pb_modifier_2"));
        pb_modifier_2->setGeometry(QRect(400, 710, 151, 51));
        pb_supprimer = new QPushButton(groupBox);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(630, 710, 151, 51));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(530, 30, 97, 20));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(600, 30, 111, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(410, 20, 121, 31));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(720, 30, 211, 22));
        sortAscButton = new QPushButton(groupBox);
        sortAscButton->setObjectName(QStringLiteral("sortAscButton"));
        sortAscButton->setGeometry(QRect(500, 60, 211, 28));
        sortDescButton = new QPushButton(groupBox);
        sortDescButton->setObjectName(QStringLiteral("sortDescButton"));
        sortDescButton->setGeometry(QRect(710, 60, 221, 28));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(410, 60, 101, 31));
        bg_pb = new QPushButton(groupBox);
        bg_pb->setObjectName(QStringLiteral("bg_pb"));
        bg_pb->setGeometry(QRect(860, 710, 191, 61));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 0, 1201, 801));
        label_12->setStyleSheet(QStringLiteral("border-image: url(:/img/img/sports-nautiques.jpg);"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(-250, -10, 1481, 811));
        label_11->setStyleSheet(QStringLiteral("border-image: url(:/img/img/try1.png);"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(70, 570, 131, 41));
        user_e = new QLineEdit(groupBox);
        user_e->setObjectName(QStringLiteral("user_e"));
        user_e->setGeometry(QRect(190, 580, 281, 31));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(70, 630, 121, 51));
        pas_e = new QLineEdit(groupBox);
        pas_e->setObjectName(QStringLiteral("pas_e"));
        pas_e->setGeometry(QRect(190, 640, 281, 31));
        pb_pdf = new QPushButton(groupBox);
        pb_pdf->setObjectName(QStringLiteral("pb_pdf"));
        pb_pdf->setGeometry(QRect(1030, 150, 71, 28));
        pb_word = new QPushButton(groupBox);
        pb_word->setObjectName(QStringLiteral("pb_word"));
        pb_word->setGeometry(QRect(1030, 220, 71, 28));
        refrech_pb = new QPushButton(groupBox);
        refrech_pb->setObjectName(QStringLiteral("refrech_pb"));
        refrech_pb->setGeometry(QRect(1030, 80, 71, 31));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(960, 420, 231, 31));
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(1030, 360, 111, 41));
        statrole = new QPushButton(groupBox);
        statrole->setObjectName(QStringLiteral("statrole"));
        statrole->setGeometry(QRect(960, 480, 231, 28));
        lab_chart_pie = new QLabel(groupBox);
        lab_chart_pie->setObjectName(QStringLiteral("lab_chart_pie"));
        lab_chart_pie->setGeometry(QRect(660, 140, 541, 600));
        QFont font;
        font.setFamily(QStringLiteral("Yu Gothic UI Semibold"));
        font.setBold(true);
        font.setWeight(75);
        lab_chart_pie->setFont(font);
        lab_chart_bar = new QLabel(groupBox);
        lab_chart_bar->setObjectName(QStringLiteral("lab_chart_bar"));
        lab_chart_bar->setGeometry(QRect(940, 200, 541, 701));
        lab_chart_bar->setFont(font);
        Imprimer = new QPushButton(groupBox);
        Imprimer->setObjectName(QStringLiteral("Imprimer"));
        Imprimer->setGeometry(QRect(1030, 280, 71, 28));
        lab_chart_pie->raise();
        lab_chart_bar->raise();
        label_12->raise();
        label_11->raise();
        label->raise();
        nom_e->raise();
        label_2->raise();
        label_3->raise();
        prenom_e->raise();
        label_6->raise();
        daten_e->raise();
        label_9->raise();
        salaire_e->raise();
        pb_ajouter->raise();
        cin_e->raise();
        label_4->raise();
        label_5->raise();
        datee_e->raise();
        tab_employes->raise();
        role_e->raise();
        label_21->raise();
        telephone_e->raise();
        label_22->raise();
        adresse_e->raise();
        label_23->raise();
        email_e->raise();
        pb_modifier_2->raise();
        pb_supprimer->raise();
        radioButton->raise();
        radioButton_2->raise();
        label_7->raise();
        lineEdit->raise();
        sortAscButton->raise();
        sortDescButton->raise();
        label_8->raise();
        bg_pb->raise();
        label_13->raise();
        user_e->raise();
        label_14->raise();
        pas_e->raise();
        pb_pdf->raise();
        pb_word->raise();
        refrech_pb->raise();
        pushButton->raise();
        label_20->raise();
        statrole->raise();
        Imprimer->raise();
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(-10, -10, 1041, 821));
        groupBox_2->setStyleSheet(QLatin1String("\n"
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
        tab_employes_2 = new QTableView(groupBox_2);
        tab_employes_2->setObjectName(QStringLiteral("tab_employes_2"));
        tab_employes_2->setGeometry(QRect(70, 110, 911, 371));
        tab_employes_2->setStyleSheet(QStringLiteral(""));
        label_31 = new QLabel(groupBox_2);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(10, 10, 991, 771));
        label_31->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416387957_1461190647815249_568358904637209358_n.jpg);"));
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(60, 120, 911, 501));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 1041, 821));
        groupBox_3->setStyleSheet(QLatin1String("\n"
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
        pb_ajouter_3 = new QPushButton(groupBox_3);
        pb_ajouter_3->setObjectName(QStringLiteral("pb_ajouter_3"));
        pb_ajouter_3->setGeometry(QRect(470, 690, 141, 51));
        pb_ajouter_3->setStyleSheet(QStringLiteral(""));
        label_32 = new QLabel(groupBox_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(-20, -20, 1031, 821));
        label_32->setStyleSheet(QStringLiteral("border-image: url(:/img/img/sports-nautiques.jpg);"));
        label_33 = new QLabel(groupBox_3);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(10, 10, 991, 771));
        label_33->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416387957_1461190647815249_568358904637209358_n.jpg);"));
        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(280, 50, 311, 31));
        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(230, 20, 631, 31));
        start_Camera = new QPushButton(groupBox_3);
        start_Camera->setObjectName(QStringLiteral("start_Camera"));
        start_Camera->setGeometry(QRect(70, 480, 461, 41));
        Stop_Camera = new QPushButton(groupBox_3);
        Stop_Camera->setObjectName(QStringLiteral("Stop_Camera"));
        Stop_Camera->setGeometry(QRect(530, 480, 451, 41));
        imgLabel = new QLabel(groupBox_3);
        imgLabel->setObjectName(QStringLiteral("imgLabel"));
        imgLabel->setGeometry(QRect(80, 130, 891, 341));
        label_33->raise();
        label_26->raise();
        label_32->raise();
        pb_ajouter_3->raise();
        label_28->raise();
        start_Camera->raise();
        Stop_Camera->raise();
        imgLabel->raise();
        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_35 = new QLabel(tab_5);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(0, 0, 1031, 821));
        label_35->setStyleSheet(QStringLiteral("border-image: url(:/img/img/sports-nautiques.jpg);"));
        month = new QTableView(tab_5);
        month->setObjectName(QStringLiteral("month"));
        month->setGeometry(QRect(150, 40, 851, 561));
        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_34 = new QLabel(tab_4);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(0, 0, 1171, 801));
        label_34->setStyleSheet(QStringLiteral("border-image: url(:/img/img/sports-nautiques.jpg);"));
        groupBox_7 = new QGroupBox(tab_4);
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
        label_54->setGeometry(QRect(50, 160, 171, 31));
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
        tabWidget->addTab(tab_4, QString());
        pushButton_3 = new QPushButton(thrDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 220, 41, 41));
        pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415260602_915404969798523_5173262210140723394_n.png);"));
        activitepb = new QPushButton(thrDialog);
        activitepb->setObjectName(QStringLiteral("activitepb"));
        activitepb->setGeometry(QRect(10, 460, 71, 61));
        activitepb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415366346_1746257945859861_8686726138527086848_n.png);"));
        clientpb = new QPushButton(thrDialog);
        clientpb->setObjectName(QStringLiteral("clientpb"));
        clientpb->setGeometry(QRect(30, 140, 51, 51));
        clientpb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/415287996_755433109383168_7582230033290630906_n.png);"));
        abonnementpb = new QPushButton(thrDialog);
        abonnementpb->setObjectName(QStringLiteral("abonnementpb"));
        abonnementpb->setGeometry(QRect(20, 290, 51, 51));
        abonnementpb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/416322058_1151869056186867_7815397858715591504_n.png);"));
        backpb = new QPushButton(thrDialog);
        backpb->setObjectName(QStringLiteral("backpb"));
        backpb->setGeometry(QRect(-20, 0, 181, 141));
        backpb->setStyleSheet(QStringLiteral("border-image: url(:/img/img/gearr.png);"));
        label_10 = new QLabel(thrDialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(-10, 0, 1401, 911));
        label_10->setStyleSheet(QStringLiteral("border-image: url(:/img/img/try1.png);"));
        label_10->raise();
        logoutpb->raise();
        planningpb->raise();
        tabWidget->raise();
        pushButton_3->raise();
        activitepb->raise();
        clientpb->raise();
        abonnementpb->raise();
        backpb->raise();

        retranslateUi(thrDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(thrDialog);
    } // setupUi

    void retranslateUi(QDialog *thrDialog)
    {
        thrDialog->setWindowTitle(QApplication::translate("thrDialog", "Dialog", Q_NULLPTR));
        logoutpb->setText(QString());
        planningpb->setText(QString());
        groupBox->setTitle(QString());
        pb_ajouter->setText(QApplication::translate("thrDialog", "Save", Q_NULLPTR));
        cin_e->setPlaceholderText(QApplication::translate("thrDialog", "Numbers only", Q_NULLPTR));
        label_4->setText(QApplication::translate("thrDialog", "Role", Q_NULLPTR));
        label->setText(QApplication::translate("thrDialog", "Nom", Q_NULLPTR));
        nom_e->setPlaceholderText(QApplication::translate("thrDialog", "Characters only", Q_NULLPTR));
        label_2->setText(QApplication::translate("thrDialog", "Cin", Q_NULLPTR));
        label_3->setText(QApplication::translate("thrDialog", "Prenom", Q_NULLPTR));
        prenom_e->setPlaceholderText(QApplication::translate("thrDialog", "Characters only", Q_NULLPTR));
        label_6->setText(QApplication::translate("thrDialog", "Date de naissance", Q_NULLPTR));
        daten_e->setPlaceholderText(QApplication::translate("thrDialog", "YYYY-MM-DD", Q_NULLPTR));
        label_9->setText(QApplication::translate("thrDialog", "Salaire", Q_NULLPTR));
        salaire_e->setPlaceholderText(QApplication::translate("thrDialog", "Number only", Q_NULLPTR));
        label_5->setText(QApplication::translate("thrDialog", "date d'embauche", Q_NULLPTR));
        datee_e->setPlaceholderText(QApplication::translate("thrDialog", "YYYY-MM-DD", Q_NULLPTR));
        role_e->clear();
        role_e->insertItems(0, QStringList()
         << QApplication::translate("thrDialog", "Receptioniste", Q_NULLPTR)
         << QApplication::translate("thrDialog", "Assistant", Q_NULLPTR)
         << QApplication::translate("thrDialog", "Ressource Humaine", Q_NULLPTR)
        );
        label_21->setText(QApplication::translate("thrDialog", "Telephone", Q_NULLPTR));
        telephone_e->setPlaceholderText(QApplication::translate("thrDialog", "+216", Q_NULLPTR));
        label_22->setText(QApplication::translate("thrDialog", "Adresse", Q_NULLPTR));
        adresse_e->setPlaceholderText(QApplication::translate("thrDialog", "Characters only", Q_NULLPTR));
        label_23->setText(QApplication::translate("thrDialog", "Email", Q_NULLPTR));
        email_e->setPlaceholderText(QApplication::translate("thrDialog", "email@gmail.com", Q_NULLPTR));
        pb_modifier_2->setText(QApplication::translate("thrDialog", "Modifier", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("thrDialog", "Supprimer", Q_NULLPTR));
        radioButton->setText(QApplication::translate("thrDialog", "Nom", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("thrDialog", "Prenom", Q_NULLPTR));
        label_7->setText(QApplication::translate("thrDialog", "Recherche", Q_NULLPTR));
        sortAscButton->setText(QApplication::translate("thrDialog", "ASC", Q_NULLPTR));
        sortDescButton->setText(QApplication::translate("thrDialog", "DESC", Q_NULLPTR));
        label_8->setText(QApplication::translate("thrDialog", "Trier", Q_NULLPTR));
        bg_pb->setText(QApplication::translate("thrDialog", "Background", Q_NULLPTR));
        label_12->setText(QString());
        label_11->setText(QString());
        label_13->setText(QApplication::translate("thrDialog", "Username", Q_NULLPTR));
        user_e->setPlaceholderText(QString());
        label_14->setText(QApplication::translate("thrDialog", "Password", Q_NULLPTR));
        pb_pdf->setText(QApplication::translate("thrDialog", "PDF", Q_NULLPTR));
        pb_word->setText(QApplication::translate("thrDialog", "word", Q_NULLPTR));
        refrech_pb->setText(QApplication::translate("thrDialog", "Refrech", Q_NULLPTR));
        pushButton->setText(QApplication::translate("thrDialog", "R\303\251partition par exp\303\251rience de travail", Q_NULLPTR));
        label_20->setText(QApplication::translate("thrDialog", "Stats", Q_NULLPTR));
        statrole->setText(QApplication::translate("thrDialog", "Role", Q_NULLPTR));
        lab_chart_pie->setText(QString());
        lab_chart_bar->setText(QString());
        Imprimer->setText(QApplication::translate("thrDialog", "Imprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("thrDialog", "Gestion des employe", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_31->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("thrDialog", "tasks for employes", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        pb_ajouter_3->setText(QApplication::translate("thrDialog", "Valider", Q_NULLPTR));
        label_32->setText(QString());
        label_33->setText(QString());
        label_26->setText(QApplication::translate("thrDialog", "Donner un prime ", Q_NULLPTR));
        label_28->setText(QApplication::translate("thrDialog", "Enregistrez des vid\303\251os pour les nouveaux employ\303\251s afin de les guider", Q_NULLPTR));
        start_Camera->setText(QApplication::translate("thrDialog", "commencer l'enregistrement", Q_NULLPTR));
        Stop_Camera->setText(QApplication::translate("thrDialog", "arr\303\252te l'enregistrement", Q_NULLPTR));
        imgLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("thrDialog", "enregistrement", Q_NULLPTR));
        label_35->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("thrDialog", "Employe of the month", Q_NULLPTR));
        label_34->setText(QString());
        groupBox_7->setTitle(QApplication::translate("thrDialog", "SMTP", Q_NULLPTR));
        label_53->setText(QApplication::translate("thrDialog", "Email", Q_NULLPTR));
        label_54->setText(QApplication::translate("thrDialog", "Sujet:", Q_NULLPTR));
        label_56->setText(QApplication::translate("thrDialog", "Message:", Q_NULLPTR));
        sendBtn2->setText(QApplication::translate("thrDialog", "Envoyer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("thrDialog", "Mailing", Q_NULLPTR));
        pushButton_3->setText(QString());
        activitepb->setText(QString());
        clientpb->setText(QString());
        abonnementpb->setText(QString());
        backpb->setText(QString());
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class thrDialog: public Ui_thrDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRDIALOG_H
