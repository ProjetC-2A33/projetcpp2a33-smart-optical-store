/********************************************************************************
** Form generated from reading UI file 'forgotpassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOTPASSWORDDIALOG_H
#define UI_FORGOTPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ForgotPasswordDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QLabel *label_description;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QLabel *label_error;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_send;

    void setupUi(QDialog *ForgotPasswordDialog)
    {
        if (ForgotPasswordDialog->objectName().isEmpty())
            ForgotPasswordDialog->setObjectName("ForgotPasswordDialog");
        ForgotPasswordDialog->resize(480, 320);
        ForgotPasswordDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
"QLabel#label_error {\n"
"    color: #ff8a80;\n"
"}\n"
"QRadioButton {\n"
"    color: #ffffff;\n"
"    font-weight: 500;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"QRadioButton::indicator:unchecked {\n"
"    bor"
                        "der: 2px solid #253c6f;\n"
"    border-radius: 9px;\n"
"    background-color: #0f1c3b;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"    border: 2px solid #2d5bff;\n"
"    border-radius: 9px;\n"
"    background-color: #2d5bff;\n"
"}\n"
"QComboBox {\n"
"    background-color: #0f1c3b;\n"
"    color: #ffffff;\n"
"    border: 1.5px solid #253c6f;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    background-color: #2d5bff;\n"
"    border-radius: 5px;\n"
"    width: 30px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: none;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 5px solid #ffffff;\n"
"    margin-right: 5px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #0f1c3b;\n"
"    color: #ffffff;\n"
"    selection-background-color: #2d5bff;\n"
"    border: 1px solid #253c6f;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(ForgotPasswordDialog);
        verticalLayout->setObjectName("verticalLayout");
        label_title = new QLabel(ForgotPasswordDialog);
        label_title->setObjectName("label_title");
        label_title->setAlignment(Qt::AlignCenter);
        label_title->setStyleSheet(QString::fromUtf8("font-size: 20px;\n"
"font-weight: 700;\n"
"color: #ffffff;"));

        verticalLayout->addWidget(label_title);

        label_description = new QLabel(ForgotPasswordDialog);
        label_description->setObjectName("label_description");
        label_description->setAlignment(Qt::AlignCenter);
        label_description->setWordWrap(true);
        label_description->setStyleSheet(QString::fromUtf8("color: #ffffff;\n"
"padding: 10px;"));

        verticalLayout->addWidget(label_description);

        label_email = new QLabel(ForgotPasswordDialog);
        label_email->setObjectName("label_email");
        label_email->setStyleSheet(QString::fromUtf8("color: #ffffff;\n"
"font-weight: 500;"));

        verticalLayout->addWidget(label_email);

        lineEdit_email = new QLineEdit(ForgotPasswordDialog);
        lineEdit_email->setObjectName("lineEdit_email");

        verticalLayout->addWidget(lineEdit_email);

        label_error = new QLabel(ForgotPasswordDialog);
        label_error->setObjectName("label_error");
        label_error->setVisible(false);
        label_error->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_error);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(ForgotPasswordDialog);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_send = new QPushButton(ForgotPasswordDialog);
        pushButton_send->setObjectName("pushButton_send");

        horizontalLayout->addWidget(pushButton_send);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ForgotPasswordDialog);

        QMetaObject::connectSlotsByName(ForgotPasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *ForgotPasswordDialog)
    {
        ForgotPasswordDialog->setWindowTitle(QCoreApplication::translate("ForgotPasswordDialog", "Mot de passe oubli\303\251", nullptr));
        label_title->setText(QCoreApplication::translate("ForgotPasswordDialog", "R\303\251cup\303\251ration de mot de passe", nullptr));
        label_description->setText(QCoreApplication::translate("ForgotPasswordDialog", "Veuillez saisir votre adresse email. Le mot de passe sera automatiquement envoy\303\251 \303\240 cette adresse.", nullptr));
        label_email->setText(QCoreApplication::translate("ForgotPasswordDialog", "Adresse Gmail :", nullptr));
        lineEdit_email->setPlaceholderText(QCoreApplication::translate("ForgotPasswordDialog", "votre.email@gmail.com", nullptr));
        label_error->setText(QString());
        pushButton_cancel->setText(QCoreApplication::translate("ForgotPasswordDialog", "Annuler", nullptr));
        pushButton_send->setText(QCoreApplication::translate("ForgotPasswordDialog", "Envoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForgotPasswordDialog: public Ui_ForgotPasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTPASSWORDDIALOG_H
