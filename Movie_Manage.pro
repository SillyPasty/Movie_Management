#-------------------------------------------------
#
# Project created by QtCreator 2019-08-28T15:30:27
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Movie_Manage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        usermainwindow.cpp \
    adminmainwindow.cpp \
    logindialog.cpp \
    infochange.cpp \
    registerwindow.cpp \
    sqlfuns.cpp \
    addnewfilm.cpp \
    seatsselect.cpp \
    addnewhall.cpp \
    movieseatmap.cpp

HEADERS += \
        usermainwindow.h \
    adminmainwindow.h \
    logindialog.h \
    infochange.h \
    registerwindow.h \
    sqlfuns.h \
    addnewfilm.h \
    seatsselect.h \
    addnewhall.h \
    movieseatmap.h

FORMS += \
        usermainwindow.ui \
    adminmainwindow.ui \
    logindialog.ui \
    infochange.ui \
    registerwindow.ui \
    addnewfilm.ui \
    seatsselect.ui \
    addnewhall.ui \
    movieseatmap.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resourse/png.qrc \
    resourse/png.qrc
