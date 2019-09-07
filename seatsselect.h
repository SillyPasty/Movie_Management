/*
 * 代码完成了座位选择的实现，与普通用户和数据库进行了交互
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#ifndef SEATSSELECT_H
#define SEATSSELECT_H

#include <QWidget>
#include "sqlfuns.h"

namespace Ui {
class SeatsSelect;
}

class SeatsSelect : public QWidget
{
    Q_OBJECT

public:
    explicit SeatsSelect(QWidget *parent = nullptr);
    // 公有变量，储存当前电影ID
    QString movieIdStore;
    // 储存实际位置和座位图中位置的偏移量
    int xAxis, yAxis;

    // 输入价格和票数，返回进行优惠活动后的总价格
    float calTotal(float price, int tickets);

    ~SeatsSelect();

    // 输入座位图字符串，展示座位
    void showSeat(QString seatMap);
    // 计算偏移量
    void calAxis();

private:
    Ui::SeatsSelect *ui;

private slots:
    void receivePayment(QString movieId);
    void on_tableWidget_clicked(const QModelIndex &index);
    void on_pushButton_puchase_clicked();

    void on_radioButton_one_clicked();

    void on_radioButton_two_clicked();

    void on_radioButton_three_clicked();

signals:
    void balanceChange();
};

#endif // SEATSSELECT_H
