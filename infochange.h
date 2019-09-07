/*
 * 代码完成了对修改个人信息功能的实现，与数据库进行了交互
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#ifndef INFOCHANGE_H
#define INFOCHANGE_H

#include <QDialog>
#include "sqlfuns.h"

namespace Ui {
class InfoChange;
}

class InfoChange : public QDialog
{
    Q_OBJECT

public:
    explicit InfoChange(QWidget *parent = nullptr);
    ~InfoChange();

private:
    Ui::InfoChange *ui;

private slots:
    void receiveInfoChange();
    void on_pushButton_confirm_clicked();

signals:
    void infoChanged();
};

#endif // INFOCHANGE_H
