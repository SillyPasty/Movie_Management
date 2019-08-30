#include "usermainwindow.h"
#include "adminmainwindow.h"
#include "usermainwindow.h"
#include "infochange.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserMainWindow uw;
    AdminMainWindow aw;
    LoginDialog ldg;
    InfoChange ifc;

    ldg.show();

    //  login skip
    QObject::connect(&ldg, SIGNAL(showUserMainWindow()), &uw, SLOT(receiveLogin()));
    QObject::connect(&ldg, SIGNAL(showAdminMainWindow()), &aw, SLOT(receiveLogin()));

    //  change user skip
    QObject::connect(&uw, SIGNAL(showLoginWindow()), &ldg, SLOT(userExchange()));
    QObject::connect(&aw, SIGNAL(showLoginWindow()), &ldg, SLOT(userExchange()));

    //  change info skip
    QObject::connect(&aw, SIGNAL(showInfoChangeWindow()), &ifc, SLOT(receiveInfoChange()));
    QObject::connect(&uw, SIGNAL(showInfoChangeWindow()), &ifc, SLOT(receiveInfoChange()));



    return a.exec();
}
