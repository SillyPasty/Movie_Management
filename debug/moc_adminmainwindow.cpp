/****************************************************************************
** Meta object code from reading C++ file 'adminmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../adminmainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminMainWindow_t {
    QByteArrayData data[22];
    char stringdata0[463];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminMainWindow_t qt_meta_stringdata_AdminMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AdminMainWindow"
QT_MOC_LITERAL(1, 16, 15), // "showLoginWindow"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "timeout"
QT_MOC_LITERAL(4, 41, 20), // "showInfoChangeWindow"
QT_MOC_LITERAL(5, 62, 20), // "showAddNewFilmWindow"
QT_MOC_LITERAL(6, 83, 20), // "showAddNewHallWindow"
QT_MOC_LITERAL(7, 104, 32), // "on_pushButton_changeUser_clicked"
QT_MOC_LITERAL(8, 137, 12), // "receiveLogin"
QT_MOC_LITERAL(9, 150, 11), // "timerUpdate"
QT_MOC_LITERAL(10, 162, 14), // "infoChangeDone"
QT_MOC_LITERAL(11, 177, 38), // "on_pushButton_editPersonalInf..."
QT_MOC_LITERAL(12, 216, 33), // "on_pushButton_addNewMovie_cli..."
QT_MOC_LITERAL(13, 250, 32), // "on_pushButton_addNewHall_clicked"
QT_MOC_LITERAL(14, 283, 30), // "on_pushButton_search_2_clicked"
QT_MOC_LITERAL(15, 314, 35), // "on_comboBox_hall_currentTextC..."
QT_MOC_LITERAL(16, 350, 4), // "arg1"
QT_MOC_LITERAL(17, 355, 28), // "on_pushButton_search_clicked"
QT_MOC_LITERAL(18, 384, 22), // "receiveMovieInfoChange"
QT_MOC_LITERAL(19, 407, 16), // "receiveHallAdded"
QT_MOC_LITERAL(20, 424, 32), // "on_tableView_currentHall_clicked"
QT_MOC_LITERAL(21, 457, 5) // "index"

    },
    "AdminMainWindow\0showLoginWindow\0\0"
    "timeout\0showInfoChangeWindow\0"
    "showAddNewFilmWindow\0showAddNewHallWindow\0"
    "on_pushButton_changeUser_clicked\0"
    "receiveLogin\0timerUpdate\0infoChangeDone\0"
    "on_pushButton_editPersonalInfo_clicked\0"
    "on_pushButton_addNewMovie_clicked\0"
    "on_pushButton_addNewHall_clicked\0"
    "on_pushButton_search_2_clicked\0"
    "on_comboBox_hall_currentTextChanged\0"
    "arg1\0on_pushButton_search_clicked\0"
    "receiveMovieInfoChange\0receiveHallAdded\0"
    "on_tableView_currentHall_clicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    0,  107,    2, 0x06 /* Public */,
       6,    0,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    1,  117,    2, 0x08 /* Private */,
      17,    0,  120,    2, 0x08 /* Private */,
      18,    0,  121,    2, 0x08 /* Private */,
      19,    0,  122,    2, 0x08 /* Private */,
      20,    1,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   21,

       0        // eod
};

void AdminMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdminMainWindow *_t = static_cast<AdminMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showLoginWindow(); break;
        case 1: _t->timeout(); break;
        case 2: _t->showInfoChangeWindow(); break;
        case 3: _t->showAddNewFilmWindow(); break;
        case 4: _t->showAddNewHallWindow(); break;
        case 5: _t->on_pushButton_changeUser_clicked(); break;
        case 6: _t->receiveLogin(); break;
        case 7: _t->timerUpdate(); break;
        case 8: _t->infoChangeDone(); break;
        case 9: _t->on_pushButton_editPersonalInfo_clicked(); break;
        case 10: _t->on_pushButton_addNewMovie_clicked(); break;
        case 11: _t->on_pushButton_addNewHall_clicked(); break;
        case 12: _t->on_pushButton_search_2_clicked(); break;
        case 13: _t->on_comboBox_hall_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_search_clicked(); break;
        case 15: _t->receiveMovieInfoChange(); break;
        case 16: _t->receiveHallAdded(); break;
        case 17: _t->on_tableView_currentHall_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AdminMainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminMainWindow::showLoginWindow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AdminMainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminMainWindow::timeout)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AdminMainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminMainWindow::showInfoChangeWindow)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AdminMainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminMainWindow::showAddNewFilmWindow)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (AdminMainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminMainWindow::showAddNewHallWindow)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject AdminMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AdminMainWindow.data,
      qt_meta_data_AdminMainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AdminMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AdminMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void AdminMainWindow::showLoginWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdminMainWindow::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AdminMainWindow::showInfoChangeWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AdminMainWindow::showAddNewFilmWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AdminMainWindow::showAddNewHallWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
