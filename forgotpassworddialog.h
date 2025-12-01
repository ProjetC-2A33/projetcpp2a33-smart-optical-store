#ifndef FORGOTPASSWORDDIALOG_H
#define FORGOTPASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class ForgotPasswordDialog;
}

class ForgotPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ForgotPasswordDialog(QWidget *parent = nullptr);
    ~ForgotPasswordDialog();

    QString getEmail() const;
    bool emailEnvoye() const { return m_emailEnvoye; }

private slots:
    void onSendClicked();
    void onCancelClicked();
    void onEmailTextChanged();
    void onEmailReturnPressed();

private:
    void afficherMessageErreur(const QString& message);
    bool validerEmail(const QString& email);
    void envoyerEmailAutomatiquement(const QString& email);
    void envoyerEmailTest(const QString& email);

    Ui::ForgotPasswordDialog *ui;
    bool m_emailEnvoye;
};

#endif // FORGOTPASSWORDDIALOG_H

