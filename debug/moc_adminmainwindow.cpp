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
    QByteArrayData data[17];
    char stringdata0[357];
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
QT_MOC_LITERAL(6, 83, 32), // "on_pushButton_changeUser_clicked"
QT_MOC_LITERAL(7, 116, 12), // "receiveLogin"
QT_MOC_LITERAL(8, 129, 11), // "timerUpdate"
QT_MOC_LITERAL(9, 141, 14), // "infoChangeDone"
QT_MOC_LITERAL(10, 156, 38), // "on_pushButton_editPersonalInf..."
QT_MOC_LITERAL(11, 195, 33), // "on_pushButton_addNewMovie_cli..."
QT_MOC_LITERAL(12, 229, 32), // "on_pushButton_addNewHall_clicked"
QT_MOC_LITERAL(13, 262, 22), // "receiveMovieInfoChange"
QT_MOC_LITERAL(14, 285, 30), // "on_pushButton_search_2_clicked"
QT_MOC_LITERAL(15, 316, 35), // "on_comboBox_hall_currentTextC..."
QT_MOC_LITERAL(16, 352, 4) // "arg1"

    },
    "AdminMainWindow\0showLoginWindow\0\0"
    "timeout\0showInfoChangeWindow\0"
    "showAddNewFilmWindow\0"
    "on_pushButton_changeUser_clicked\0"
    "receiveLogin\0timerUpdate\0infoChangeDone\0"
    "on_pushButton_editPersonalInfo_clicked\0"
    "on_pushButton_addNewMovie_clicked\0"
    "on_pushButton_addNewHall_clicked\0"
    "receiveMovieInfoChange\0"
    "on_pushButton_search_2_clicked\0"
    "on_comboBox_hall_currentTextChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

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
        case 4: _t->on_pushButton_changeUser_clicked(); break;
        case 5: _t->receiveLogin(); break;
        case 6: _t->timerUpdate(); break;
        case 7: _t->infoChangeDone(); break;
        case 8: _t->on_pushButton_editPersonalInfo_clicked(); break;
        case 9: _t->on_pushButton_addNewMovie_clicked(); break;
        case 10: _t->on_pushButton_addNewHall_clicked(); break;
        case 11: _t->receiveMovieInfoChange(); break;
        case 12: _t->on_pushButton_search_2_clicked(); break;
        case 13: _t->on_comboBox_hall_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
