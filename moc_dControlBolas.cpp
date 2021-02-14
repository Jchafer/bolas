/****************************************************************************
** Meta object code from reading C++ file 'dControlBolas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dControlBolas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dControlBolas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DControlBolas_t {
    QByteArrayData data[8];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DControlBolas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DControlBolas_t qt_meta_stringdata_DControlBolas = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DControlBolas"
QT_MOC_LITERAL(1, 14, 14), // "slotBotonParar"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "slotBolaNueva"
QT_MOC_LITERAL(4, 44, 5), // "Bola*"
QT_MOC_LITERAL(5, 50, 4), // "bola"
QT_MOC_LITERAL(6, 55, 20), // "slotBotonAumentarVel"
QT_MOC_LITERAL(7, 76, 19) // "slotBotonReducirVel"

    },
    "DControlBolas\0slotBotonParar\0\0"
    "slotBolaNueva\0Bola*\0bola\0slotBotonAumentarVel\0"
    "slotBotonReducirVel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DControlBolas[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DControlBolas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DControlBolas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotBotonParar(); break;
        case 1: _t->slotBolaNueva((*reinterpret_cast< Bola*(*)>(_a[1]))); break;
        case 2: _t->slotBotonAumentarVel(); break;
        case 3: _t->slotBotonReducirVel(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DControlBolas::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_DControlBolas.data,
    qt_meta_data_DControlBolas,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DControlBolas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DControlBolas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DControlBolas.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::DControlBolas"))
        return static_cast< Ui::DControlBolas*>(this);
    return QDialog::qt_metacast(_clname);
}

int DControlBolas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
