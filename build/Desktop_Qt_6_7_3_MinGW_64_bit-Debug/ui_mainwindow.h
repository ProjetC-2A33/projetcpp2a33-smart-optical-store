/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "saliare.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_10;
    QSpinBox *spinBox_2;
    QToolButton *toolButton;
    QProgressBar *progressBar;
    QLabel *label_7;
    QDateEdit *dateEdit_2;
    QLabel *label_8;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton_15;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_16;
    QPushButton *pushButton_6;
    QLabel *label_14;
    saliare *keySequenceEdit;
    QTableWidget *tableWidget;
    QFrame *frame_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1535, 767);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(140, 30, 1331, 411));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: rgba(255, 255, 255, 0.85);   /* blanc l\303\251g\303\250rement transparent */\n"
"    border: 1.5px solid rgba(200, 210, 230, 0.8);  /* bordure pastel douce */\n"
"    border-radius: 15px;                           /* coins arrondis modernes */\n"
"    padding: 12px;\n"
"    box-shadow: 0 4px 12px rgba(0, 0, 0, 0.08);    /* ombre l\303\251g\303\250re et \303\251l\303\251gante */\n"
"    backdrop-filter: blur(10px);                   /* flou subtil pour un effet verre */\n"
"}\n"
"\n"
"/* --- Effet de survol (l\303\251g\303\250rement plus lumineux) --- */\n"
"QFrame:hover {\n"
"    background-color: rgba(255, 255, 255, 0.9);\n"
"    border-color: rgba(180, 200, 255, 0.9);\n"
"    box-shadow: 0 6px 16px rgba(0, 0, 0, 0.12);\n"
"}\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Plain);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 101, 31));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff;              /* m\303\252me fond que les boutons */\n"
"    color: #2e3a59;                         /* texte gris-bleu lisible */\n"
"    border: 1px solid #dcdcdc;              /* bordure claire */\n"
"    border-radius: 12px;                    /* coins arrondis */\n"
"    padding: 8px 16px;                      /* espace int\303\251rieur \303\251quilibr\303\251 */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    qproperty-alignment: 'AlignCenter';     /* centre le texte dans le label */\n"
"    box-shadow: 0 2px 6px rgba(0,0,0,0.05); /* l\303\251g\303\250re ombre comme les boutons */\n"
"}\n"
"\n"
"/* Survol du label (effet doux comme le bouton hover) */\n"
"QLabel:hover {\n"
"    background-color: #f2f6ff;              /* bleu pastel clair */\n"
"    border-color: #b3d1ff;\n"
"    box-shadow: 0 3px 8px rgba(0,0,0,0.1);\n"
"}\n"
""));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 101, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff;              /* m\303\252me fond que les boutons */\n"
"    color: #2e3a59;                         /* texte gris-bleu lisible */\n"
"    border: 1px solid #dcdcdc;              /* bordure claire */\n"
"    border-radius: 12px;                    /* coins arrondis */\n"
"    padding: 8px 16px;                      /* espace int\303\251rieur \303\251quilibr\303\251 */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    qproperty-alignment: 'AlignCenter';     /* centre le texte dans le label */\n"
"    box-shadow: 0 2px 6px rgba(0,0,0,0.05); /* l\303\251g\303\250re ombre comme les boutons */\n"
"}\n"
"\n"
"/* Survol du label (effet doux comme le bouton hover) */\n"
"QLabel:hover {\n"
"    background-color: #f2f6ff;              /* bleu pastel clair */\n"
"    border-color: #b3d1ff;\n"
"    box-shadow: 0 3px 8px rgba(0,0,0,0.1);\n"
"}\n"
""));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 100, 141, 31));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff;              /* m\303\252me fond que les boutons */\n"
"    color: #2e3a59;                         /* texte gris-bleu lisible */\n"
"    border: 1px solid #dcdcdc;              /* bordure claire */\n"
"    border-radius: 12px;                    /* coins arrondis */\n"
"    padding: 8px 16px;                      /* espace int\303\251rieur \303\251quilibr\303\251 */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    qproperty-alignment: 'AlignCenter';     /* centre le texte dans le label */\n"
"    box-shadow: 0 2px 6px rgba(0,0,0,0.05); /* l\303\251g\303\250re ombre comme les boutons */\n"
"}\n"
"\n"
"/* Survol du label (effet doux comme le bouton hover) */\n"
"QLabel:hover {\n"
"    background-color: #f2f6ff;              /* bleu pastel clair */\n"
"    border-color: #b3d1ff;\n"
"    box-shadow: 0 3px 8px rgba(0,0,0,0.1);\n"
"}\n"
""));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 140, 91, 31));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff;              /* m\303\252me fond que les boutons */\n"
"    color: #2e3a59;                         /* texte gris-bleu lisible */\n"
"    border: 1px solid #dcdcdc;              /* bordure claire */\n"
"    border-radius: 12px;                    /* coins arrondis */\n"
"    padding: 8px 16px;                      /* espace int\303\251rieur \303\251quilibr\303\251 */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    qproperty-alignment: 'AlignCenter';     /* centre le texte dans le label */\n"
"    box-shadow: 0 2px 6px rgba(0,0,0,0.05); /* l\303\251g\303\250re ombre comme les boutons */\n"
"}\n"
"\n"
"/* Survol du label (effet doux comme le bouton hover) */\n"
"QLabel:hover {\n"
"    background-color: #f2f6ff;              /* bleu pastel clair */\n"
"    border-color: #b3d1ff;\n"
"    box-shadow: 0 3px 8px rgba(0,0,0,0.1);\n"
"}\n"
""));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 240, 111, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff;              /* m\303\252me fond que les boutons */\n"
"    color: #2e3a59;                         /* texte gris-bleu lisible */\n"
"    border: 1px solid #dcdcdc;              /* bordure claire */\n"
"    border-radius: 12px;                    /* coins arrondis */\n"
"    padding: 8px 16px;                      /* espace int\303\251rieur \303\251quilibr\303\251 */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    qproperty-alignment: 'AlignCenter';     /* centre le texte dans le label */\n"
"    box-shadow: 0 2px 6px rgba(0,0,0,0.05); /* l\303\251g\303\250re ombre comme les boutons */\n"
"}\n"
"\n"
"/* Survol du label (effet doux comme le bouton hover) */\n"
"QLabel:hover {\n"
"    background-color: #f2f6ff;              /* bleu pastel clair */\n"
"    border-color: #b3d1ff;\n"
"    box-shadow: 0 3px 8px rgba(0,0,0,0.1);\n"
"}\n"
""));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 10, 113, 26));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff;              /* fond blanc clair et propre */\n"
"    color: #2e3a59;                         /* texte bien lisible */\n"
"    border: 1.5px solid #dcdcdc;            /* fine bordure douce */\n"
"    border-radius: 10px;                    /* coins arrondis modernes */\n"
"    padding: 6px 10px;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 500;\n"
"    selection-background-color: #cfe2ff;    /* surlignage bleu clair */\n"
"}\n"
"\n"
"/* Effet quand l'utilisateur clique dedans */\n"
"QLineEdit:focus {\n"
"    border: 1.5px solid #b3d1ff;            /* bleu pastel \303\251l\303\251gant */\n"
"    background-color: #f7faff;              /* l\303\251ger contraste clair */\n"
"    box-shadow: 0 0 8px rgba(179, 209, 255, 0.5);\n"
"}\n"
""));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 50, 113, 26));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff;              /* fond blanc clair et propre */\n"
"    color: #2e3a59;                         /* texte bien lisible */\n"
"    border: 1.5px solid #dcdcdc;            /* fine bordure douce */\n"
"    border-radius: 10px;                    /* coins arrondis modernes */\n"
"    padding: 6px 10px;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 500;\n"
"    selection-background-color: #cfe2ff;    /* surlignage bleu clair */\n"
"}\n"
"\n"
"/* Effet quand l'utilisateur clique dedans */\n"
"QLineEdit:focus {\n"
"    border: 1.5px solid #b3d1ff;            /* bleu pastel \303\251l\303\251gant */\n"
"    background-color: #f7faff;              /* l\303\251ger contraste clair */\n"
"    box-shadow: 0 0 8px rgba(179, 209, 255, 0.5);\n"
"}\n"
""));
        dateEdit = new QDateEdit(frame);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(160, 90, 141, 41));
        dateEdit->setStyleSheet(QString::fromUtf8("/* --- QDATEEDIT MODERNE ET \303\211L\303\211GANT --- */\n"
"QDateEdit {\n"
"    background-color: #ffffff;              /* blanc pur */\n"
"    color: #1e1e2f;                         /* texte gris fonc\303\251 \303\251l\303\251gant */\n"
"    border: 1.5px solid #e0e6ed;            /* bordure douce */\n"
"    border-radius: 12px;                    /* coins arrondis modernes */\n"
"    padding: 8px 12px;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    selection-background-color: #cfe3ff;    /* surlignage bleu clair */\n"
"    selection-color: #1e1e2f;\n"
"    transition: all 0.25s ease;             /* animation fluide */\n"
"    box-shadow: 0 2px 5px rgba(0,0,0,0.05); /* ombre subtile */\n"
"}\n"
"\n"
"/* --- SURVOL --- */\n"
"QDateEdit:hover {\n"
"    background-color: #f4f7ff;              /* bleu clair tr\303\250s doux */\n"
"    border-color: #c0d3ff;\n"
"    box-shadow: 0 4px 10px rgba(0,0,0,0.08);\n"
"}\n"
"\n"
"/* --- FOCUS (quand on clique dessus) --- */\n"
"QDateEdit:focus {\n"
""
                        "    border-color: #7aa2ff;                  /* contour bleu vif */\n"
"    box-shadow: 0 0 0 3px rgba(122,162,255,0.2);\n"
"}\n"
"\n"
"/* --- BOUTON D\303\211ROULANT --- */\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 28px;\n"
"    margin-right: 4px;\n"
"}\n"
"\n"
"/* --- FL\303\210CHE MODERNE --- */\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/qt-project.org/styles/commonstyle/images/arrowdown.png);\n"
"    width: 14px;\n"
"    height: 14px;\n"
"}\n"
"\n"
"/* --- Quand le bouton est press\303\251 --- */\n"
"QDateEdit::drop-down:pressed {\n"
"    background-color: #e6efff;\n"
"    border-radius: 8px;\n"
"}\n"
""));
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(160, 150, 113, 26));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff;              /* fond blanc clair et propre */\n"
"    color: #2e3a59;                         /* texte bien lisible */\n"
"    border: 1.5px solid #dcdcdc;            /* fine bordure douce */\n"
"    border-radius: 10px;                    /* coins arrondis modernes */\n"
"    padding: 6px 10px;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 500;\n"
"    selection-background-color: #cfe2ff;    /* surlignage bleu clair */\n"
"}\n"
"\n"
"/* Effet quand l'utilisateur clique dedans */\n"
"QLineEdit:focus {\n"
"    border: 1.5px solid #b3d1ff;            /* bleu pastel \303\251l\303\251gant */\n"
"    background-color: #f7faff;              /* l\303\251ger contraste clair */\n"
"    box-shadow: 0 0 8px rgba(179, 209, 255, 0.5);\n"
"}\n"
""));
        lineEdit_4 = new QLineEdit(frame);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(180, 240, 113, 26));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff;              /* fond blanc clair et propre */\n"
"    color: #2e3a59;                         /* texte bien lisible */\n"
"    border: 1.5px solid #dcdcdc;            /* fine bordure douce */\n"
"    border-radius: 10px;                    /* coins arrondis modernes */\n"
"    padding: 6px 10px;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 500;\n"
"    selection-background-color: #cfe2ff;    /* surlignage bleu clair */\n"
"}\n"
"\n"
"/* Effet quand l'utilisateur clique dedans */\n"
"QLineEdit:focus {\n"
"    border: 1.5px solid #b3d1ff;            /* bleu pastel \303\251l\303\251gant */\n"
"    background-color: #f7faff;              /* l\303\251ger contraste clair */\n"
"    box-shadow: 0 0 8px rgba(179, 209, 255, 0.5);\n"
"}\n"
""));
        label_10 = new QLabel(frame);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 190, 161, 31));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff;              /* m\303\252me fond que les boutons */\n"
"    color: #2e3a59;                         /* texte gris-bleu lisible */\n"
"    border: 1px solid #dcdcdc;              /* bordure claire */\n"
"    border-radius: 12px;                    /* coins arrondis */\n"
"    padding: 8px 16px;                      /* espace int\303\251rieur \303\251quilibr\303\251 */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    qproperty-alignment: 'AlignCenter';     /* centre le texte dans le label */\n"
"    box-shadow: 0 2px 6px rgba(0,0,0,0.05); /* l\303\251g\303\250re ombre comme les boutons */\n"
"}\n"
"\n"
"/* Survol du label (effet doux comme le bouton hover) */\n"
"QLabel:hover {\n"
"    background-color: #f2f6ff;              /* bleu pastel clair */\n"
"    border-color: #b3d1ff;\n"
"    box-shadow: 0 3px 8px rgba(0,0,0,0.1);\n"
"}\n"
""));
        spinBox_2 = new QSpinBox(frame);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(190, 190, 91, 31));
        spinBox_2->setStyleSheet(QString::fromUtf8("/* --- SPINBOX MODERNE AVEC FL\303\210CHES --- */\n"
"QSpinBox {\n"
"    background-color: #ffffff;\n"
"    color: #1e1e2f;\n"
"    border: 1.5px solid #e0e6ed;\n"
"    border-radius: 12px;\n"
"    padding-right: 28px;                    /* espace r\303\251serv\303\251 aux fl\303\250ches */\n"
"    padding-left: 10px;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    selection-background-color: #cfe3ff;\n"
"    selection-color: #1e1e2f;\n"
"    transition: all 0.25s ease;\n"
"    box-shadow: 0 2px 5px rgba(0,0,0,0.05);\n"
"}\n"
"\n"
"/* --- SURVOL --- */\n"
"QSpinBox:hover {\n"
"    background-color: #f4f7ff;\n"
"    border-color: #c0d3ff;\n"
"    box-shadow: 0 4px 10px rgba(0,0,0,0.08);\n"
"}\n"
"\n"
"/* --- FOCUS (clic dans la zone) --- */\n"
"QSpinBox:focus {\n"
"    border-color: #7aa2ff;\n"
"    box-shadow: 0 0 0 3px rgba(122,162,255,0.2);\n"
"}\n"
"\n"
"/* --- BOUTONS DE CONTR\303\224LE (FL\303\210CHES) --- */\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    subcontrol-origin: b"
                        "order;\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    width: 22px;\n"
"    margin: 2px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"/* --- Position des boutons --- */\n"
"QSpinBox::up-button {\n"
"    subcontrol-position: top right;\n"
"}\n"
"QSpinBox::down-button {\n"
"    subcontrol-position: bottom right;\n"
"}\n"
"\n"
"/* --- Fl\303\250che HAUT --- */\n"
"QSpinBox::up-arrow {\n"
"    image: url(:/qt-project.org/styles/commonstyle/images/arrowup.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"/* --- Fl\303\250che BAS --- */\n"
"QSpinBox::down-arrow {\n"
"    image: url(:/qt-project.org/styles/commonstyle/images/arrowdown.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"/* --- Hover sur les fl\303\250ches --- */\n"
"QSpinBox::up-button:hover,\n"
"QSpinBox::down-button:hover {\n"
"    background-color: #e8f0ff;\n"
"}\n"
"\n"
"/* --- Pressed --- */\n"
"QSpinBox::up-button:pressed,\n"
"QSpinBox::down-button:pressed {\n"
"    background-color: #dbe7ff;\n"
"}\n"
""));
        toolButton = new QToolButton(frame);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(640, 10, 24, 26));
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(520, 20, 91, 20));
        progressBar->setValue(24);
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 290, 151, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff;              /* m\303\252me fond que les boutons */\n"
"    color: #2e3a59;                         /* texte gris-bleu lisible */\n"
"    border: 1px solid #dcdcdc;              /* bordure claire */\n"
"    border-radius: 12px;                    /* coins arrondis */\n"
"    padding: 8px 16px;                      /* espace int\303\251rieur \303\251quilibr\303\251 */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    qproperty-alignment: 'AlignCenter';     /* centre le texte dans le label */\n"
"    box-shadow: 0 2px 6px rgba(0,0,0,0.05); /* l\303\251g\303\250re ombre comme les boutons */\n"
"}\n"
"\n"
"/* Survol du label (effet doux comme le bouton hover) */\n"
"QLabel:hover {\n"
"    background-color: #f2f6ff;              /* bleu pastel clair */\n"
"    border-color: #b3d1ff;\n"
"    box-shadow: 0 3px 8px rgba(0,0,0,0.1);\n"
"}\n"
""));
        dateEdit_2 = new QDateEdit(frame);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(190, 290, 141, 41));
        dateEdit_2->setStyleSheet(QString::fromUtf8("/* --- QDATEEDIT MODERNE ET \303\211L\303\211GANT --- */\n"
"QDateEdit {\n"
"    background-color: #ffffff;              /* blanc pur */\n"
"    color: #1e1e2f;                         /* texte gris fonc\303\251 \303\251l\303\251gant */\n"
"    border: 1.5px solid #e0e6ed;            /* bordure douce */\n"
"    border-radius: 12px;                    /* coins arrondis modernes */\n"
"    padding: 8px 12px;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    selection-background-color: #cfe3ff;    /* surlignage bleu clair */\n"
"    selection-color: #1e1e2f;\n"
"    transition: all 0.25s ease;             /* animation fluide */\n"
"    box-shadow: 0 2px 5px rgba(0,0,0,0.05); /* ombre subtile */\n"
"}\n"
"\n"
"/* --- SURVOL --- */\n"
"QDateEdit:hover {\n"
"    background-color: #f4f7ff;              /* bleu clair tr\303\250s doux */\n"
"    border-color: #c0d3ff;\n"
"    box-shadow: 0 4px 10px rgba(0,0,0,0.08);\n"
"}\n"
"\n"
"/* --- FOCUS (quand on clique dessus) --- */\n"
"QDateEdit:focus {\n"
""
                        "    border-color: #7aa2ff;                  /* contour bleu vif */\n"
"    box-shadow: 0 0 0 3px rgba(122,162,255,0.2);\n"
"}\n"
"\n"
"/* --- BOUTON D\303\211ROULANT --- */\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 28px;\n"
"    margin-right: 4px;\n"
"}\n"
"\n"
"/* --- FL\303\210CHE MODERNE --- */\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/qt-project.org/styles/commonstyle/images/arrowdown.png);\n"
"    width: 14px;\n"
"    height: 14px;\n"
"}\n"
"\n"
"/* --- Quand le bouton est press\303\251 --- */\n"
"QDateEdit::drop-down:pressed {\n"
"    background-color: #e6efff;\n"
"    border-radius: 8px;\n"
"}\n"
""));
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 350, 101, 31));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff;              /* m\303\252me fond que les boutons */\n"
"    color: #2e3a59;                         /* texte gris-bleu lisible */\n"
"    border: 1px solid #dcdcdc;              /* bordure claire */\n"
"    border-radius: 12px;                    /* coins arrondis */\n"
"    padding: 8px 16px;                      /* espace int\303\251rieur \303\251quilibr\303\251 */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    qproperty-alignment: 'AlignCenter';     /* centre le texte dans le label */\n"
"    box-shadow: 0 2px 6px rgba(0,0,0,0.05); /* l\303\251g\303\250re ombre comme les boutons */\n"
"}\n"
"\n"
"/* Survol du label (effet doux comme le bouton hover) */\n"
"QLabel:hover {\n"
"    background-color: #f2f6ff;              /* bleu pastel clair */\n"
"    border-color: #b3d1ff;\n"
"    box-shadow: 0 3px 8px rgba(0,0,0,0.1);\n"
"}\n"
""));
        radioButton = new QRadioButton(frame);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(130, 350, 101, 24));
        radioButton->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: #2e3a59;                     /* texte lisible */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    spacing: 8px;                       /* espace entre le rond et le texte */\n"
"}\n"
"\n"
"/* Rond non s\303\251lectionn\303\251 */\n"
"QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border-radius: 9px;                 /* forme circulaire */\n"
"    border: 2px solid #b3d1ff;          /* contour bleu pastel */\n"
"    background-color: #ffffff;          /* fond blanc clair */\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"/* Rond s\303\251lectionn\303\251 */\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #b3d1ff;          /* bleu pastel rempli */\n"
"    border: 2px solid #7aaaff;\n"
"}\n"
"\n"
"/* Survol */\n"
"QRadioButton::indicator:hover {\n"
"    border-color: #7aaaff;\n"
"    background-color: #f2f6ff;\n"
"}\n"
""));
        radioButton_2 = new QRadioButton(frame);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(260, 350, 131, 24));
        radioButton_2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: #2e3a59;                     /* texte lisible */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    spacing: 8px;                       /* espace entre le rond et le texte */\n"
"}\n"
"\n"
"/* Rond non s\303\251lectionn\303\251 */\n"
"QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border-radius: 9px;                 /* forme circulaire */\n"
"    border: 2px solid #b3d1ff;          /* contour bleu pastel */\n"
"    background-color: #ffffff;          /* fond blanc clair */\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"/* Rond s\303\251lectionn\303\251 */\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #b3d1ff;          /* bleu pastel rempli */\n"
"    border: 2px solid #7aaaff;\n"
"}\n"
"\n"
"/* Survol */\n"
"QRadioButton::indicator:hover {\n"
"    border-color: #7aaaff;\n"
"    background-color: #f2f6ff;\n"
"}\n"
""));
        radioButton_3 = new QRadioButton(frame);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(380, 350, 131, 24));
        radioButton_3->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: #2e3a59;                     /* texte lisible */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    spacing: 8px;                       /* espace entre le rond et le texte */\n"
"}\n"
"\n"
"/* Rond non s\303\251lectionn\303\251 */\n"
"QRadioButton::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border-radius: 9px;                 /* forme circulaire */\n"
"    border: 2px solid #b3d1ff;          /* contour bleu pastel */\n"
"    background-color: #ffffff;          /* fond blanc clair */\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"/* Rond s\303\251lectionn\303\251 */\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #b3d1ff;          /* bleu pastel rempli */\n"
"    border: 2px solid #7aaaff;\n"
"}\n"
"\n"
"/* Survol */\n"
"QRadioButton::indicator:hover {\n"
"    border-color: #7aaaff;\n"
"    background-color: #f2f6ff;\n"
"}\n"
""));
        pushButton_15 = new QPushButton(frame);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(530, 350, 93, 41));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(1020, 350, 191, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(630, 350, 93, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        pushButton_16 = new QPushButton(frame);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(740, 350, 111, 41));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(860, 350, 121, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        label_14 = new QLabel(frame);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(930, 10, 91, 41));
        label_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        keySequenceEdit = new saliare(frame);
        keySequenceEdit->setObjectName("keySequenceEdit");
        keySequenceEdit->setGeometry(QRect(1030, 20, 131, 26));
        keySequenceEdit->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #ffffff;              /* m\303\252me fond que les boutons */\n"
"    color: #2e3a59;                         /* texte gris-bleu lisible */\n"
"    border: 1px solid #dcdcdc;              /* bordure claire */\n"
"    border-radius: 12px;                    /* coins arrondis */\n"
"    padding: 8px 16px;                      /* espace int\303\251rieur \303\251quilibr\303\251 */\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 14px;\n"
"    font-weight: 600;\n"
"    qproperty-alignment: 'AlignCenter';     /* centre le texte dans le label */\n"
"    box-shadow: 0 2px 6px rgba(0,0,0,0.05); /* l\303\251g\303\250re ombre comme les boutons */\n"
"}\n"
"\n"
"/* Survol du label (effet doux comme le bouton hover) */\n"
"QLabel:hover {\n"
"    background-color: #f2f6ff;              /* bleu pastel clair */\n"
"    border-color: #b3d1ff;\n"
"    box-shadow: 0 3px 8px rgba(0,0,0,0.1);\n"
"}\n"
""));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(260, 440, 1001, 241));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #f8faff;              /* fond tr\303\250s clair bleu-gris */\n"
"    border: 1px solid #d0d7e2;              /* bord doux et \303\251l\303\251gant */\n"
"    border-radius: 8px;\n"
"    gridline-color: #d0d7e2;\n"
"    color: #2e2e2e;                         /* texte bien visible */\n"
"    font-family: \"Segoe UI\", Arial;\n"
"    font-size: 14px;\n"
"    alternate-background-color: #eef3ff;    /* alternance l\303\251g\303\250re */\n"
"    selection-background-color: #bcd4ff;    /* s\303\251lection moderne */\n"
"    selection-color: #000;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #e6eeff;              /* en-t\303\252te bleu clair */\n"
"    color: #1a1a1a;\n"
"    padding: 6px;\n"
"    border: 1px solid #d0d7e2;\n"
"    font-weight: bold;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #dbe7ff;              /* survol */\n"
"    color: #000;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    backgr"
                        "ound-color: #a7c4ff;              /* s\303\251lection active */\n"
"    color: #000;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f1f4f9;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #bcd4ff;\n"
"    min-height: 25px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #a3c4ff;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    background: none;\n"
"}\n"
""));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(-30, 30, 171, 291));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_8 = new QPushButton(frame_4);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(0, 50, 171, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        pushButton_9 = new QPushButton(frame_4);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(0, 130, 171, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        pushButton_10 = new QPushButton(frame_4);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(0, 90, 171, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
"\n"
""));
        pushButton_11 = new QPushButton(frame_4);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(0, 10, 171, 41));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        pushButton_12 = new QPushButton(frame_4);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(0, 170, 171, 41));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        pushButton_13 = new QPushButton(frame_4);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(0, 210, 171, 41));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        pushButton_14 = new QPushButton(frame_4);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(0, 250, 171, 41));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e3f2fd;  /* bleu clair pastel */\n"
"    color: #0d47a1;\n"
"    border: 1px solid #bbdefb;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #bbdefb;  /* devient un peu plus bleu au survol */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #90caf9;\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1535, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Date d'embauche", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Ann\303\251e d'experiences", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Date de naissances", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Etat civil", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "C\303\251libataire", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Mari\303\251(e)", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Divorc\303\251(e)", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Recherche emlpoy\303\251es", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Export\303\251 PDF", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Trier par", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date d'embauche", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Ann\303\251e d'experiences", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Date de naissances", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Etat civil", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "clients", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Produits", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Employ\303\251es", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Sponsor", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Fournisseur", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Se deconnecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
