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
    QByteArrayData data[20];
    char stringdata0[412];
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
QT_MOC_LITERAL(5, 61, 17), // "showPaymentWindow"
QT_MOC_LITERAL(6, 79, 7), // "movieId"
QT_MOC_LITERAL(7, 87, 32), // "on_pushButton_changeUser_clicked"
QT_MOC_LITERAL(8, 120, 12), // "receiveLogin"
QT_MOC_LITERAL(9, 133, 20), // "receiveBalanceChange"
QT_MOC_LITERAL(10, 154, 11), // "timerUpdate"
QT_MOC_LITERAL(11, 166, 14), // "infoChangeDone"
QT_MOC_LITERAL(12, 181, 38), // "on_pushButton_editPersonalInf..."
QT_MOC_LITERAL(13, 220, 34), // "on_pushButton_confirmTopUp_cl..."
QT_MOC_LITERAL(14, 255, 28), // "on_pushButton_search_clicked"
QT_MOC_LITERAL(15, 284, 25), // "on_pushButton_buy_clicked"
QT_MOC_LITERAL(16, 310, 30), // "on_pushButton_search_2_clicked"
QT_MOC_LITERAL(17, 341, 25), // "on_pushButton_pay_clicked"
QT_MOC_LITERAL(18, 367, 33), // "on_pushButton_cancelOrder_cli..."
QT_MOC_LITERAL(19, 401, 10) // "orderCheck"

    },
    "UserMainWindow\0showLoginWindow\0\0timeout\0"
    "showInfoChangeWindow\0showPaymentWindow\0"
    "movieId\0on_pushButton_changeUser_clicked\0"
    "receiveLogin\0receiveBalanceChange\0"
    "timerUpdate\0infoChangeDone\0"
    "on_pushButton_editPersonalInfo_clicked\0"
    "on_pushButton_confirmTopUp_clicked\0"
    "on_pushButton_search_clicked\0"
    "on_pushButton_buy_clicked\0"
    "on_pushButton_search_2_clicked\0"
    "on_pushButton_pay_clicked\0"
    "on_pushButton_cancelOrder_clicked\0"
    "orderCheck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  105,    2, 0x08 /* Private */,
       8,    0,  106,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

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
        case 3: _t->showPaymentWindow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_changeUser_clicked(); break;
        case 5: _t->receiveLogin(); break;
        case 6: _t->receiveBalanceChange(); break;
        case 7: _t->timerUpdate(); break;
        case 8: _t->infoChangeDone(); break;
        case 9: _t->on_pushButton_editPersonalInfo_clicked(); break;
        case 10: _t->on_pushButton_confirmTopUp_clicked(); break;
        case 11: _t->on_pushButton_search_clicked(); break;
        case 12: _t->on_pushButton_buy_clicked(); break;
        case 13: _t->on_pushButton_search_2_clicked(); break;
        case 14: _t->on_pushButton_pay_clicked(); break;
        case 15: _t->on_pushButton_cancelOrder_clicked(); break;
        case 16: _t->orderCheck(); break;
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
        {
            typedef void (UserMainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserMainWindow::showPaymentWindow)) {
                *result = 3;
                return;
            }
        }
    }
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
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

// SIGNAL 3
void UserMainWindow::showPaymentWindow(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
