/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QLabel *label_subtitle;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QLabel *label_error;
    QPushButton *pushButton_login;
    QPushButton *pushButton_forgot;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(440, 320);
        LoginDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #06122A;\n"
"    color: #ffffff;\n"
"    font-family: \"Segoe UI\";\n"
"}\n"
"QLineEdit {\n"
"    background-color: #0f1c3b;\n"
"    color: #ffffff;\n"
"    border: 1.5px solid #253c6f;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}\n"
"QPushButton {\n"
"    background-color: #2d5bff;\n"
"    color: #ffffff;\n"
"    border-radius: 10px;\n"
"    padding: 8px 18px;\n"
"    font-weight: 600;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #4d73ff;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1f44c6;\n"
"}\n"
"QLabel#label_error {\n"
"    color: #ff8a80;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setObjectName("verticalLayout");
        label_title = new QLabel(LoginDialog);
        label_title->setObjectName("label_title");
        label_title->setAlignment(Qt::AlignCenter);
        label_title->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-weight: 700;\n"
"color: #ffffff;"));

        verticalLayout->addWidget(label_title);

        label_subtitle = new QLabel(LoginDialog);
        label_subtitle->setObjectName("label_subtitle");
        label_subtitle->setAlignment(Qt::AlignCenter);
        label_subtitle->setWordWrap(true);
        label_subtitle->setStyleSheet(QString::fromUtf8("color: #ffffff;"));

        verticalLayout->addWidget(label_subtitle);

        lineEdit_login = new QLineEdit(LoginDialog);
        lineEdit_login->setObjectName("lineEdit_login");

        verticalLayout->addWidget(lineEdit_login);

        lineEdit_password = new QLineEdit(LoginDialog);
        lineEdit_password->setObjectName("lineEdit_password");

        verticalLayout->addWidget(lineEdit_password);

        label_error = new QLabel(LoginDialog);
        label_error->setObjectName("label_error");
        label_error->setVisible(false);
        label_error->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_error);

        pushButton_login = new QPushButton(LoginDialog);
        pushButton_login->setObjectName("pushButton_login");

        verticalLayout->addWidget(pushButton_login);

        pushButton_forgot = new QPushButton(LoginDialog);
        pushButton_forgot->setObjectName("pushButton_forgot");
        pushButton_forgot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: #8ca9ff;\n"
"    border: none;\n"
"    text-decoration: underline;\n"
"    font-weight: 500;\n"
"}\n"
"QPushButton:hover {\n"
"    color: #c5d6ff;\n"
"}"));

        verticalLayout->addWidget(pushButton_forgot);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Authentification", nullptr));
        label_title->setText(QCoreApplication::translate("LoginDialog", "Bienvenue", nullptr));
        label_subtitle->setText(QCoreApplication::translate("LoginDialog", "Connectez-vous pour acc\303\251der \303\240 la gestion des employ\303\251s", nullptr));
        lineEdit_login->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Email", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Mot de passe", nullptr));
        label_error->setText(QString());
        pushButton_login->setText(QCoreApplication::translate("LoginDialog", "Se connecter", nullptr));
        pushButton_forgot->setText(QCoreApplication::translate("LoginDialog", "Mot de passe oubli\303\251 ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
