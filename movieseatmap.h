/*
 * 代码完成了对展示信息详情功能的实现，与管理员用户和数据库进行了交互
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#ifndef MOVIESEATMAP_H
#define MOVIESEATMAP_H

#include <QWidget>
#include "sqlfuns.h"

namespace Ui {
class MovieSeatMap;
}

class MovieSeatMap : public QWidget
{
    Q_OBJECT

public:
    explicit MovieSeatMap(QWidget *parent = nullptr);
    // 输入一个座位图字符串，展示当前可用座位
    void showSeat(QString seatMap);
    ~MovieSeatMap();

private:
    Ui::MovieSeatMap *ui;

private slots:
    void receiveMovieDetail(QString movieId);
};

#endif // MOVIESEATMAP_H
