/*
 * 程序的主函数
 * 将各个类实例化，并连接槽函数与信号
 * 连接数据库
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
    //  init database
    while(!sf.connect("dataBase.db"))
        sleep(1);
    sf.createTables();

    ldg.show();
    QObject::connect(&ldg, SIGNAL(showRegisterWindow()), &rw, SLOT(receiveRegister()));
    //  login skip
    QObject::connect(&ldg, SIGNAL(showUserMainWindow()), &uw, SLOT(receiveLogin()));
    QObject::connect(&ldg, SIGNAL(showAdminMainWindow()), &aw, SLOT(receiveLogin()));

    QObject::connect(&aw, SIGNAL(showAddNewFilmWindow()), &anf, SLOT(receiveAddNewFilm()));

    //  change user skip
    QObject::connect(&uw, SIGNAL(showLoginWindow()), &ldg, SLOT(userExchange()));
    QObject::connect(&aw, SIGNAL(showLoginWindow()), &ldg, SLOT(userExchange()));

    //  change info skip
    QObject::connect(&aw, SIGNAL(showInfoChangeWindow()), &ifc, SLOT(receiveInfoChange()));
    QObject::connect(&uw, SIGNAL(showInfoChangeWindow()), &ifc, SLOT(receiveInfoChange()));
    QObject::connect(&ifc, SIGNAL(infoChanged()), &aw, SLOT(infoChangeDone()));
    QObject::connect(&ifc, SIGNAL(infoChanged()), &uw, SLOT(infoChangeDone()));

    QObject::connect(&anf, SIGNAL(movieInfoChange()), &aw, SLOT(receiveMovieInfoChange()));

    QObject::connect(&uw, SIGNAL(showPaymentWindow(QString)), &ss, SLOT(receivePayment(QString)));
    QObject::connect(&ss, SIGNAL(balanceChange()), &uw, SLOT(receiveBalanceChange()));

    QObject::connect(&aw, SIGNAL(showAddNewHallWindow()), &anh, SLOT(receiveAddNewHall()));
    QObject::connect(&aw, SIGNAL(showMovieDetail(QString)), &msm, SLOT(receiveMovieDetail(QString)));

    QObject::connect(&anh, SIGNAL(hallAdded()), &aw, SLOT(receiveHallAdded()));

    return a.exec();
}
