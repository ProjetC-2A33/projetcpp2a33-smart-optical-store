/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QGroupBox *groupBox_email;
    QVBoxLayout *verticalLayout_email;
    QLabel *label_smtp_email;
    QLineEdit *lineEdit_smtp_email;
    QLabel *label_smtp_password;
    QLineEdit *lineEdit_smtp_password;
    QGroupBox *groupBox_sms;
    QVBoxLayout *verticalLayout_sms;
    QLabel *label_sms_account;
    QLineEdit *lineEdit_sms_account;
    QLabel *label_sms_token;
    QLineEdit *lineEdit_sms_token;
    QLabel *label_sms_from;
    QLineEdit *lineEdit_sms_from;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_save;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName("ConfigDialog");
        ConfigDialog->resize(550, 500);
        ConfigDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
"QPushButton#pushButton_cancel {\n"
"    background-color: #3a3f4a;\n"
"    color: #ffffff;\n"
"}\n"
"QPushButton#pushButton_cancel:hover {\n"
"    background-color: #4a4f5a;\n"
"}\n"
"QLabel {\n"
"    color: #ffffff;\n"
"}\n"
"QGroupBox {\n"
"    color: #ffffff;\n"
"    border: 2px solid #253c6f;\n"
"    border-radius: 10px;\n"
"    margin-top: 10px;\n"
"    padding-top: 15px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: marg"
                        "in;\n"
"    left: 10px;\n"
"    padding: 0 5px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(ConfigDialog);
        verticalLayout->setObjectName("verticalLayout");
        label_title = new QLabel(ConfigDialog);
        label_title->setObjectName("label_title");
        label_title->setAlignment(Qt::AlignCenter);
        label_title->setStyleSheet(QString::fromUtf8("font-size: 20px;\n"
"font-weight: 700;\n"
"color: #ffffff;"));

        verticalLayout->addWidget(label_title);

        groupBox_email = new QGroupBox(ConfigDialog);
        groupBox_email->setObjectName("groupBox_email");
        verticalLayout_email = new QVBoxLayout(groupBox_email);
        verticalLayout_email->setObjectName("verticalLayout_email");
        label_smtp_email = new QLabel(groupBox_email);
        label_smtp_email->setObjectName("label_smtp_email");

        verticalLayout_email->addWidget(label_smtp_email);

        lineEdit_smtp_email = new QLineEdit(groupBox_email);
        lineEdit_smtp_email->setObjectName("lineEdit_smtp_email");

        verticalLayout_email->addWidget(lineEdit_smtp_email);

        label_smtp_password = new QLabel(groupBox_email);
        label_smtp_password->setObjectName("label_smtp_password");

        verticalLayout_email->addWidget(label_smtp_password);

        lineEdit_smtp_password = new QLineEdit(groupBox_email);
        lineEdit_smtp_password->setObjectName("lineEdit_smtp_password");
        lineEdit_smtp_password->setEchoMode(QLineEdit::Password);

        verticalLayout_email->addWidget(lineEdit_smtp_password);


        verticalLayout->addWidget(groupBox_email);

        groupBox_sms = new QGroupBox(ConfigDialog);
        groupBox_sms->setObjectName("groupBox_sms");
        verticalLayout_sms = new QVBoxLayout(groupBox_sms);
        verticalLayout_sms->setObjectName("verticalLayout_sms");
        label_sms_account = new QLabel(groupBox_sms);
        label_sms_account->setObjectName("label_sms_account");

        verticalLayout_sms->addWidget(label_sms_account);

        lineEdit_sms_account = new QLineEdit(groupBox_sms);
        lineEdit_sms_account->setObjectName("lineEdit_sms_account");

        verticalLayout_sms->addWidget(lineEdit_sms_account);

        label_sms_token = new QLabel(groupBox_sms);
        label_sms_token->setObjectName("label_sms_token");

        verticalLayout_sms->addWidget(label_sms_token);

        lineEdit_sms_token = new QLineEdit(groupBox_sms);
        lineEdit_sms_token->setObjectName("lineEdit_sms_token");
        lineEdit_sms_token->setEchoMode(QLineEdit::Password);

        verticalLayout_sms->addWidget(lineEdit_sms_token);

        label_sms_from = new QLabel(groupBox_sms);
        label_sms_from->setObjectName("label_sms_from");

        verticalLayout_sms->addWidget(label_sms_from);

        lineEdit_sms_from = new QLineEdit(groupBox_sms);
        lineEdit_sms_from->setObjectName("lineEdit_sms_from");

        verticalLayout_sms->addWidget(lineEdit_sms_from);


        verticalLayout->addWidget(groupBox_sms);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(ConfigDialog);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_save = new QPushButton(ConfigDialog);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ConfigDialog);

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QCoreApplication::translate("ConfigDialog", "Configuration", nullptr));
        label_title->setText(QCoreApplication::translate("ConfigDialog", "Configuration des services", nullptr));
        groupBox_email->setTitle(QCoreApplication::translate("ConfigDialog", "Configuration Email (Gmail SMTP)", nullptr));
        label_smtp_email->setText(QCoreApplication::translate("ConfigDialog", "Adresse Gmail (exp\303\251diteur) :", nullptr));
        lineEdit_smtp_email->setPlaceholderText(QCoreApplication::translate("ConfigDialog", "votre.email@gmail.com", nullptr));
        label_smtp_password->setText(QCoreApplication::translate("ConfigDialog", "Mot de passe d'application Gmail :", nullptr));
        lineEdit_smtp_password->setPlaceholderText(QCoreApplication::translate("ConfigDialog", "Mot de passe d'application (16 caract\303\250res)", nullptr));
        groupBox_sms->setTitle(QCoreApplication::translate("ConfigDialog", "Configuration SMS (Twilio)", nullptr));
        label_sms_account->setText(QCoreApplication::translate("ConfigDialog", "Account SID :", nullptr));
        lineEdit_sms_account->setPlaceholderText(QCoreApplication::translate("ConfigDialog", "Votre Account SID Twilio", nullptr));
        label_sms_token->setText(QCoreApplication::translate("ConfigDialog", "Auth Token :", nullptr));
        lineEdit_sms_token->setPlaceholderText(QCoreApplication::translate("ConfigDialog", "Votre Auth Token Twilio", nullptr));
        label_sms_from->setText(QCoreApplication::translate("ConfigDialog", "Num\303\251ro Twilio (exp\303\251diteur) :", nullptr));
        lineEdit_sms_from->setPlaceholderText(QCoreApplication::translate("ConfigDialog", "+33612345678", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("ConfigDialog", "Annuler", nullptr));
        pushButton_save->setText(QCoreApplication::translate("ConfigDialog", "Sauvegarder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
