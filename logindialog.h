#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    Ui::LoginDialog *ui;

private slots:
    void on_pushButton_login_clicked();
    void userExchange();

signals:
    void showUserMainWindow();
    void showAdminMainWindow();

};

#endif // LOGINDIALOG_H
