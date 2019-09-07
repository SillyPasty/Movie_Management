/*
 * 代码完成了对注册用户功能的实现，与数据库进行了交互
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include "sqlfuns.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_checkBox_isAdmin_clicked(bool checked);
    void receiveRegister();
    void on_pushButton_confirm_clicked();

private:
    Ui::RegisterWindow *ui;

};

#endif // REGISTERWINDOW_H
