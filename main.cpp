/*
 * 程序的主函数
 * 将各个类实例化，并连接槽函数与信号
 * 连接数据库
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#include "usermainwindow.h"
#include "adminmainwindow.h"
#include "usermainwindow.h"
#include "infochange.h"
#include "logindialog.h"
#include "registerwindow.h"
#include "sqlfuns.h"
#include "addnewfilm.h"
#include "seatsselect.h"
#include "addnewhall.h"
#include "movieseatmap.h"
#include <unistd.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserMainWindow uw;
    AdminMainWindow aw;
    LoginDialog ldg;
    InfoChange ifc;
    RegisterWindow rw;
    AddNewFilm anf;
    SqlFuns sf;
    SeatsSelect ss;
    AddNewHall anh;
    MovieSeatMap msm;

    while(!sf.connect("dataBase.db")) //  初始化数据库
        sleep(1);
    sf.createTables();

    ldg.show();                      // 显示登陆窗口

    // 连接不同窗口之间的信号与槽
    QObject::connect(&ldg, SIGNAL(showRegisterWindow()), &rw, SLOT(receiveRegister()));
    // 登陆信号
    QObject::connect(&ldg, SIGNAL(showUserMainWindow()), &uw, SLOT(receiveLogin()));
    QObject::connect(&ldg, SIGNAL(showAdminMainWindow()), &aw, SLOT(receiveLogin()));
    // 添加新电影
    QObject::connect(&aw, SIGNAL(showAddNewFilmWindow()), &anf, SLOT(receiveAddNewFilm()));
    // 切换用户
    QObject::connect(&uw, SIGNAL(showLoginWindow()), &ldg, SLOT(userExchange()));
    QObject::connect(&aw, SIGNAL(showLoginWindow()), &ldg, SLOT(userExchange()));
    // 信息更改
    QObject::connect(&aw, SIGNAL(showInfoChangeWindow()), &ifc, SLOT(receiveInfoChange()));
    QObject::connect(&uw, SIGNAL(showInfoChangeWindow()), &ifc, SLOT(receiveInfoChange()));
    QObject::connect(&ifc, SIGNAL(infoChanged()), &aw, SLOT(infoChangeDone()));
    QObject::connect(&ifc, SIGNAL(infoChanged()), &uw, SLOT(infoChangeDone()));
    // 添加新电影
    QObject::connect(&anf, SIGNAL(movieInfoChange()), &aw, SLOT(receiveMovieInfoChange()));
    // 付款、余额改变
    QObject::connect(&uw, SIGNAL(showPaymentWindow(QString)), &ss, SLOT(receivePayment(QString)));
    QObject::connect(&ss, SIGNAL(balanceChange()), &uw, SLOT(receiveBalanceChange()));
    // 添加新影厅
    QObject::connect(&aw, SIGNAL(showAddNewHallWindow()), &anh, SLOT(receiveAddNewHall()));
    QObject::connect(&anh, SIGNAL(hallAdded()), &aw, SLOT(receiveHallAdded()));
    // 展示细节
    QObject::connect(&aw, SIGNAL(showMovieDetail(QString)), &msm, SLOT(receiveMovieDetail(QString)));



    return a.exec();
}
