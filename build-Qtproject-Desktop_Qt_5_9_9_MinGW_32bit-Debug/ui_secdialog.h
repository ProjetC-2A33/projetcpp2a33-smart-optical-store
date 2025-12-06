/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QLabel *label_nom;
    QLabel *label_prenom;
    QLabel *label_role;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QStringLiteral("SecDialog"));
        SecDialog->resize(1920, 1080);
        SecDialog->setStyleSheet(QStringLiteral(""));
        label = new QLabel(SecDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-300, -170, 1871, 1411));
        label->setMinimumSize(QSize(1871, 0));
        label->setMaximumSize(QSize(1871, 1411));
        label->setStyleSheet(QLatin1String("border-image: url(:/img/img/sports-nautiques.jpg);\n"
"QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 16px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}"));
        pushButton = new QPushButton(SecDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 20, 311, 71));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"    background-color: #4c537d; /* Match the blue color of input boxes */\n"
"    border: 1px solid #2980b9; /* Border color for buttons */\n"
"    border-radius: 5px; /* Border radius for buttons */\n"
"	font: 14pt \"Roboto Bk\";\n"
"    padding: 5px 10px; /* Adjust padding as needed */\n"
"    color: white; /* Text color on buttons */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2c3e50; /* Darker blue on hover */\n"
"    border-color: #1f2a38; /* Darker border color on hover */\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #1f2a38; /* Even darker blue when pressed */\n"
"    border-color: #141e2b; /* Even darker border color when pressed */\n"
"    color: #95a5a6; /* Slightly lighter text color when pressed */\n"
"}"));
        pushButton_2 = new QPushButton(SecDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 140, 311, 81));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"    background-color: #4c537d; /* Match the blue color of input boxes */\n"
"    border: 1px solid #2980b9; /* Border color for buttons */\n"
"    border-radius: 5px; /* Border radius for buttons */\n"
"	font: 14pt \"Roboto Bk\";\n"
"    padding: 5px 10px; /* Adjust padding as needed */\n"
"    color: white; /* Text color on buttons */\n"
"}QPushButton:hover {\n"
"    background-color: #2c3e50; /* Darker blue on hover */\n"
"    border-color: #1f2a38; /* Darker border color on hover */\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #1f2a38; /* Even darker blue when pressed */\n"
"    border-color: #141e2b; /* Even darker border color when pressed */\n"
"    color: #95a5a6; /* Slightly lighter text color when pressed */\n"
"}"));
        pushButton_4 = new QPushButton(SecDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(70, 380, 321, 91));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"    background-color: #4c537d; /* Match the blue color of input boxes */\n"
"    border: 1px solid #2980b9; /* Border color for buttons */\n"
"    border-radius: 5px; /* Border radius for buttons */\n"
"	font: 14pt \"Roboto Bk\";\n"
"    padding: 5px 10px; /* Adjust padding as needed */\n"
"    color: white; /* Text color on buttons */\n"
"}QPushButton:hover {\n"
"    background-color: #2c3e50; /* Darker blue on hover */\n"
"    border-color: #1f2a38; /* Darker border color on hover */\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #1f2a38; /* Even darker blue when pressed */\n"
"    border-color: #141e2b; /* Even darker border color when pressed */\n"
"    color: #95a5a6; /* Slightly lighter text color when pressed */\n"
"}"));
        pushButton_3 = new QPushButton(SecDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 260, 311, 81));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"    background-color: #4c537d; /* Match the blue color of input boxes */\n"
"    border: 1px solid #2980b9; /* Border color for buttons */\n"
"    border-radius: 5px; /* Border radius for buttons */\n"
"	font: 14pt \"Roboto Bk\";\n"
"    padding: 5px 10px; /* Adjust padding as needed */\n"
"    color: white; /* Text color on buttons */\n"
"}QPushButton:hover {\n"
"    background-color: #2c3e50; /* Darker blue on hover */\n"
"    border-color: #1f2a38; /* Darker border color on hover */\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #1f2a38; /* Even darker blue when pressed */\n"
"    border-color: #141e2b; /* Even darker border color when pressed */\n"
"    color: #95a5a6; /* Slightly lighter text color when pressed */\n"
"}"));
        pushButton_5 = new QPushButton(SecDialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 500, 321, 91));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton {\n"
"	\n"
"    background-color: #4c537d; /* Match the blue color of input boxes */\n"
"    border: 1px solid #2980b9; /* Border color for buttons */\n"
"    border-radius: 5px; /* Border radius for buttons */\n"
"	font: 14pt \"Roboto Bk\";\n"
"    padding: 5px 10px; /* Adjust padding as needed */\n"
"    color: white; /* Text color on buttons */\n"
"}QPushButton:hover {\n"
"    background-color: #2c3e50; /* Darker blue on hover */\n"
"    border-color: #1f2a38; /* Darker border color on hover */\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #1f2a38; /* Even darker blue when pressed */\n"
"    border-color: #141e2b; /* Even darker border color when pressed */\n"
"    color: #95a5a6; /* Slightly lighter text color when pressed */\n"
"}"));
        label_nom = new QLabel(SecDialog);
        label_nom->setObjectName(QStringLiteral("label_nom"));
        label_nom->setGeometry(QRect(1060, 20, 111, 51));
        label_nom->setStyleSheet(QLatin1String("QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 16px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}"));
        label_prenom = new QLabel(SecDialog);
        label_prenom->setObjectName(QStringLiteral("label_prenom"));
        label_prenom->setGeometry(QRect(1180, 20, 121, 51));
        label_prenom->setStyleSheet(QLatin1String("QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 16px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}"));
        label_role = new QLabel(SecDialog);
        label_role->setObjectName(QStringLiteral("label_role"));
        label_role->setGeometry(QRect(1310, 20, 241, 51));
        label_role->setStyleSheet(QLatin1String("QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 16px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}"));

        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QApplication::translate("SecDialog", "Dialog", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QApplication::translate("SecDialog", "Gestion de employe", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SecDialog", "Gestion d'Abonnement", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("SecDialog", "Gestion des clients", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("SecDialog", "Gestion des activite", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("SecDialog", "Gestion des planning", Q_NULLPTR));
        label_nom->setText(QString());
        label_prenom->setText(QString());
        label_role->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
