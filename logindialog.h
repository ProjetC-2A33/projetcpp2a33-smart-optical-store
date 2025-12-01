#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void onLoginClicked();
    void onForgotPasswordClicked();

private:
    bool verifierIdentifiants(const QString& login, const QString& motDePasse);
    bool verifierCodeAuthentification(const QString& email);
    void afficherMessageErreur(const QString& message);
    QString genererCodeAuthentification();
    bool envoyerCodeParEmail(const QString& email, const QString& code);
    void reinitialiserMotDePasse(const QString& email);
    static QString getDialogStyleSheet();

    Ui::LoginDialog *ui;
    QString codeAuthentification;
    QString emailPourReinitialisation;
};

#endif // LOGINDIALOG_H


