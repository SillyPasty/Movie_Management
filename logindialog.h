/*
 * 代码完成了对登陆功能的实现，与数据库进行了交互
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "sqlfuns.h"

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
    void on_pushButton_register_clicked();

signals:
    void showUserMainWindow();
    void showAdminMainWindow();
    void showRegisterWindow();

};

#endif // LOGINDIALOG_H
