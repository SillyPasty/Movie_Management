#include "usermainwindow.h"
#include "adminmainwindow.h"
#include "usermainwindow.h"
#include "infochange.h"
#include "logindialog.h"
#include "registerwindow.h"
#include "sqlfuns.h"
#include "addnewfilm.h"
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

    QObject::connect(&anf, SIGNAL(infoChanged()), &aw, SLOT(infoChangeDone()));




    return a.exec();
}
