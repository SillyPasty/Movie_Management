/*
 * 代码完成了对管理员页面的各项功能的实现，与新增影厅页面、新增场次界面、数据库进行了交互
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>
#include <sqlfuns.h>
#include <QTimer>
#include <QDateTime>
#include <QAbstractItemView>
#include <QTableWidgetItem>

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = nullptr);
    // 输入一个模型指针，更新电影表格
    void updateMovieTable(QSqlTableModel *model);

    // 输入一个模型指针，更新影厅表格
    void updateHallTable(QSqlTableModel *model);

    // 输入一个模型指针，更新订单表格
    void updateOrdersTable(QSqlTableModel *model);

    // 输入座位图字符串，展示当前座位图
    void showSeat(QString seatMap);
    ~AdminMainWindow();

private:
    Ui::AdminMainWindow *ui;

private slots:
    void on_pushButton_changeUser_clicked();
    void receiveLogin();
    void timerUpdate();
    void infoChangeDone();
    void on_pushButton_editPersonalInfo_clicked();
    void on_pushButton_addNewMovie_clicked();
    void on_pushButton_addNewHall_clicked();
    void on_pushButton_search_2_clicked();
    void on_comboBox_hall_currentTextChanged(const QString &arg1);
    void on_pushButton_search_clicked();
    void receiveMovieInfoChange();
    void receiveHallAdded();
    void on_tableView_currentHall_clicked(const QModelIndex &index);
    void on_pushButton_viewDetail_clicked();
    void checkIsPlayed();

signals:
    void showLoginWindow();
    void timeout();
    void showInfoChangeWindow();
    void showAddNewFilmWindow();
    void showAddNewHallWindow();
    void showMovieDetail(QString movieId);
};

#endif // ADMINMAINWINDOW_H
