QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    saliare.cpp\
    connection.cpp \
    logindialog.cpp \
    smtpclient.cpp \
    gmailclient.cpp \
    smsclient.cpp \
    forgotpassworddialog.cpp \
    resendclient.cpp \
    curlemailer.cpp

HEADERS += \
    mainwindow.h \
    saliare.h\
    connection.h \
    logindialog.h \
    smtpclient.h \
    gmailclient.h \
    smsclient.h \
    forgotpassworddialog.h \
    resendclient.h \
    curlemailer.h

FORMS += \
    mainwindow.ui \
    logindialog.ui \
    forgotpassworddialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
