/****************************************************************************
** Meta object code from reading C++ file 'addnewfilm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addnewfilm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addnewfilm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddNewFilm_t {
    QByteArrayData data[7];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddNewFilm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddNewFilm_t qt_meta_stringdata_AddNewFilm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "AddNewFilm"
QT_MOC_LITERAL(1, 11, 15), // "movieInfoChange"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 29), // "on_pushButton_confirm_clicked"
QT_MOC_LITERAL(4, 58, 17), // "receiveAddNewFilm"
QT_MOC_LITERAL(5, 76, 35), // "on_comboBox_hall_currentTextC..."
QT_MOC_LITERAL(6, 112, 4) // "arg1"

    },
    "AddNewFilm\0movieInfoChange\0\0"
    "on_pushButton_confirm_clicked\0"
    "receiveAddNewFilm\0on_comboBox_hall_currentTextChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddNewFilm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void AddNewFilm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddNewFilm *_t = static_cast<AddNewFilm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->movieInfoChange(); break;
        case 1: _t->on_pushButton_confirm_clicked(); break;
        case 2: _t->receiveAddNewFilm(); break;
        case 3: _t->on_comboBox_hall_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AddNewFilm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddNewFilm::movieInfoChange)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AddNewFilm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddNewFilm.data,
      qt_meta_data_AddNewFilm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AddNewFilm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddNewFilm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddNewFilm.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddNewFilm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddNewFilm::movieInfoChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
