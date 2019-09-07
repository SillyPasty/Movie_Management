/*
 * 代码完成了对添加影厅界面各项配置的实现，与管理员用户和数据库进行了交互
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#ifndef ADDNEWHALL_H
#define ADDNEWHALL_H

#include <QWidget>
#include "sqlfuns.h"

namespace Ui {
class AddNewHall;
}

class AddNewHall : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewHall(QWidget *parent = nullptr);
    // 展示座位 输入座位图字符串
    void showSeat(QString seatMap);
    ~AddNewHall();
private slots:
    void on_comboBox_type_currentTextChanged(const QString &arg1);

    void on_pushButton_confirm_clicked();

private:
    Ui::AddNewHall *ui;

private slots:
    void receiveAddNewHall();

signals:
    void hallAdded();
};

#endif // ADDNEWHALL_H
