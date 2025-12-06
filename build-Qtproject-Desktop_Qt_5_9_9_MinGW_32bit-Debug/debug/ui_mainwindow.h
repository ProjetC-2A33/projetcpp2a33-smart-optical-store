/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdituserr;
    QLabel *label_4;
    QLineEdit *lineEdipasswordd;
    QLabel *label_3;
    QPushButton *forgot_pb;
    QPushButton *pushButtonlog;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *page_2;
    QLineEdit *lineEdit;
    QPushButton *reset_pb;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QWidget *page_3;
    QLineEdit *lineEdit_2;
    QLabel *label_9;
    QPushButton *verify_pb;
    QLabel *label_10;
    QWidget *page_4;
    QLabel *label_11;
    QLineEdit *lineEdipasswordd_2;
    QLineEdit *lineEdituserr_2;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *cont_pb;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1412, 838);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(380, 210, 681, 411));
        stackedWidget->setStyleSheet(QLatin1String("/* styles.qss */\n"
"\n"
"/* Set the default font color to white */\n"
"* {\n"
"    color: white;\n"
"}\n"
"\n"
"/* Style for input boxes (assuming they are QLineEdit or similar) */\n"
"QLineEdit {\n"
"    background-color: white; /* White background */\n"
"    border: 1px solid #ccc; /* Light gray border */\n"
"    border-radius: 10px; /* Larger border radius for smooth edges */\n"
"    padding: 8px; /* Increased padding */\n"
"    color: #333; /* Text color */\n"
"}\n"
"\n"
"/* Style for push buttons (assuming they are QPushButtons or similar) */\n"
"QPushButton {\n"
"    background-color: #3498db; /* Blue color for buttons */\n"
"    border: 1px solid #2980b9; /* Border color for buttons */\n"
"    border-radius: 10px; /* Larger border radius for smooth edges */\n"
"    padding: 8px 16px; /* Adjusted padding */\n"
"    color: white; /* Text color on buttons */\n"
"}\n"
"\n"
"/* Style for QStackedWidget */\n"
"QStackedWidget {\n"
"    background-color: rgba(255, 255, 255, 0.3); /* Semi-transparent white back"
                        "ground */\n"
"    border: 5px solid #ccc; /* Light gray border */\n"
"    border-radius: 10px; /* Larger border radius for smooth edges */\n"
"    padding: 20px; /* Adjusted padding */\n"
"    backdrop-filter: blur(10px); /* Apply blur effect */\n"
"}\n"
"\n"
"/* Style for dialogs */\n"
"QDialog {\n"
"    background-color: #3498db; /* Blue color for dialogs */\n"
"    border: 1px solid #2980b9; /* Border color for dialogs */\n"
"    border-radius: 10px; /* Larger border radius for smooth edges */\n"
"    padding: 10px; /* Adjusted padding */\n"
"    color: white; /* Text color */\n"
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
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        lineEdituserr = new QLineEdit(page);
        lineEdituserr->setObjectName(QStringLiteral("lineEdituserr"));
        lineEdituserr->setGeometry(QRect(240, 150, 231, 31));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 150, 81, 31));
        label_4->setStyleSheet(QStringLiteral("image: url(:/img/img/user_747376.png);"));
        lineEdipasswordd = new QLineEdit(page);
        lineEdipasswordd->setObjectName(QStringLiteral("lineEdipasswordd"));
        lineEdipasswordd->setGeometry(QRect(240, 220, 231, 31));
        lineEdipasswordd->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 220, 81, 31));
        label_3->setStyleSheet(QStringLiteral("image: url(:/img/img/padlock.png);"));
        forgot_pb = new QPushButton(page);
        forgot_pb->setObjectName(QStringLiteral("forgot_pb"));
        forgot_pb->setGeometry(QRect(290, 320, 141, 31));
        pushButtonlog = new QPushButton(page);
        pushButtonlog->setObjectName(QStringLiteral("pushButtonlog"));
        pushButtonlog->setGeometry(QRect(150, 320, 93, 31));
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(490, 270, 141, 91));
        label_6->setStyleSheet(QStringLiteral("border-image: url(:/img/img/99484734571a59fde41fc712a14c32c3.png);"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(-10, -70, 621, 291));
        label_7->setStyleSheet(QStringLiteral("border-image: url(:/img/img/logo1.png);"));
        stackedWidget->addWidget(page);
        label_7->raise();
        lineEdituserr->raise();
        label_4->raise();
        lineEdipasswordd->raise();
        label_3->raise();
        forgot_pb->raise();
        pushButtonlog->raise();
        label_6->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(197, 211, 261, 36));
        reset_pb = new QPushButton(page_2);
        reset_pb->setObjectName(QStringLiteral("reset_pb"));
        reset_pb->setGeometry(QRect(250, 290, 93, 28));
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 110, 481, 51));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 16px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(121, 211, 70, 30));
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 16px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}"));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(170, 20, 261, 41));
        label_8->setStyleSheet(QLatin1String("QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 30px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        lineEdit_2 = new QLineEdit(page_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(180, 200, 281, 31));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(220, 10, 191, 71));
        label_9->setStyleSheet(QLatin1String("QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 30px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}"));
        verify_pb = new QPushButton(page_3);
        verify_pb->setObjectName(QStringLiteral("verify_pb"));
        verify_pb->setGeometry(QRect(230, 280, 211, 61));
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(90, 110, 481, 71));
        label_10->setStyleSheet(QLatin1String("QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 16px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_11 = new QLabel(page_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(120, 30, 341, 71));
        label_11->setStyleSheet(QLatin1String("QLabel {\n"
"    color: black; /* Text color for labels */\n"
"    font-size: 30px; /* Adjust font size as needed */\n"
"    font-weight: bold; /* Make the text bold if desired */\n"
"    margin: 5px; /* Adjust margin as needed */\n"
"}"));
        lineEdipasswordd_2 = new QLineEdit(page_4);
        lineEdipasswordd_2->setObjectName(QStringLiteral("lineEdipasswordd_2"));
        lineEdipasswordd_2->setGeometry(QRect(220, 200, 231, 31));
        lineEdipasswordd_2->setEchoMode(QLineEdit::Password);
        lineEdituserr_2 = new QLineEdit(page_4);
        lineEdituserr_2->setObjectName(QStringLiteral("lineEdituserr_2"));
        lineEdituserr_2->setGeometry(QRect(220, 130, 231, 31));
        label_12 = new QLabel(page_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(150, 130, 81, 31));
        label_12->setStyleSheet(QStringLiteral("image: url(:/img/img/user_747376.png);"));
        label_13 = new QLabel(page_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(150, 200, 81, 31));
        label_13->setStyleSheet(QStringLiteral("image: url(:/img/img/padlock.png);"));
        cont_pb = new QPushButton(page_4);
        cont_pb->setObjectName(QStringLiteral("cont_pb"));
        cont_pb->setGeometry(QRect(250, 260, 141, 31));
        stackedWidget->addWidget(page_4);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 1391, 811));
        label_5->setStyleSheet(QStringLiteral("border-image: url(:/img/img/wallpaperflare.com_wallpaper.jpg);"));
        MainWindow->setCentralWidget(centralwidget);
        label_5->raise();
        stackedWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1412, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_4->setText(QString());
        label_3->setText(QString());
        forgot_pb->setText(QApplication::translate("MainWindow", "forgot password", Q_NULLPTR));
        pushButtonlog->setText(QApplication::translate("MainWindow", "Log in", Q_NULLPTR));
        label_6->setText(QString());
        label_7->setText(QString());
        reset_pb->setText(QApplication::translate("MainWindow", "Continue", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Enter your email associated with your account and<br/>we'll send an emal to reset your password</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Email ", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Reset password", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Verification", Q_NULLPTR));
        verify_pb->setText(QApplication::translate("MainWindow", "Verify and Proceed", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt;\">Please enter the 4 digit code that send to your email adresse</span></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Enter New Password", Q_NULLPTR));
        label_12->setText(QString());
        label_13->setText(QString());
        cont_pb->setText(QApplication::translate("MainWindow", "Continue", Q_NULLPTR));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
