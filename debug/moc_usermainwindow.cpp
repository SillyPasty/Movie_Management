/****************************************************************************
** Meta object code from reading C++ file 'usermainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usermainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usermainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserMainWindow_t {
    QByteArrayData data[9];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserMainWindow_t qt_meta_stringdata_UserMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "UserMainWindow"
QT_MOC_LITERAL(1, 15, 15), // "showLoginWindow"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "timeout"
QT_MOC_LITERAL(4, 40, 20), // "showInfoChangeWindow"
QT_MOC_LITERAL(5, 61, 32), // "on_pushButton_changeUser_clicked"
QT_MOC_LITERAL(6, 94, 12), // "receiveLogin"
QT_MOC_LITERAL(7, 107, 11), // "timerUpdate"
QT_MOC_LITERAL(8, 119, 38) // "on_pushButton_editPersonalInf..."

    },
    "UserMainWindow\0showLoginWindow\0\0timeout\0"
    "showInfoChangeWindow\0"
    "on_pushButton_changeUser_clicked\0"
    "receiveLogin\0timerUpdate\0"
    "on_pushButton_editPersonalInfo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserMainWindow *_t = static_cast<UserMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showLoginWindow(); break;
        case 1: _t->timeout(); break;
        case 2: _t->showInfoChangeWindow(); break;
        case 3: _t->on_pushButton_changeUser_clicked(); break;
        case 4: _t->receiveLogin(); break;
        case 5: _t->timerUpdate(); break;
        case 6: _t->on_pushButton_editPersonalInfo_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (UserMainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserMainWindow::showLoginWindow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UserMainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserMainWindow::timeout)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UserMainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserMainWindow::showInfoChangeWindow)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UserMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UserMainWindow.data,
      qt_meta_data_UserMainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int UserMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void UserMainWindow::showLoginWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UserMainWindow::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UserMainWindow::showInfoChangeWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
