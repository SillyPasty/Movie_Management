/*
 * 代码完成了普通用户界面各项功能的实现，与购票界面和数据库进行了交互
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#ifndef USERMAINWINDOW_H
#define USERMAINWINDOW_H

#include <QMainWindow>
#include "sqlfuns.h"

namespace Ui {
class UserMainWindow;
}

class UserMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMainWindow(QWidget *parent = nullptr);
    // 输入一个模型指针，更新电影表格
    void updateMovieTable(QSqlTableModel *model);
    // 输入一个模型指针，更新订单表格
    void updateOrdersTable(QSqlTableModel *model);

    ~UserMainWindow();

private:
    Ui::UserMainWindow *ui;

private slots:
    void on_pushButton_changeUser_clicked();
    void receiveLogin();
    void receiveBalanceChange();
    void timerUpdate();
    void infoChangeDone();

    void on_pushButton_editPersonalInfo_clicked();

    void on_pushButton_confirmTopUp_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_buy_clicked();

    void on_pushButton_search_2_clicked();

    void on_pushButton_pay_clicked();

    void on_pushButton_cancelOrder_clicked();

    void orderCheck();


signals:
    void showLoginWindow();
    void timeout();
    void showInfoChangeWindow();
    void showPaymentWindow(QString movieId);
};

#endif // USERMAINWINDOW_H
