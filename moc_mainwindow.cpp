/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "signalNuevaBola"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "Bola*"
QT_MOC_LITERAL(4, 34, 4), // "bola"
QT_MOC_LITERAL(5, 39, 14), // "jugadorChoqued"
QT_MOC_LITERAL(6, 54, 12), // "slotRepintar"
QT_MOC_LITERAL(7, 67, 16), // "slotDInformacion"
QT_MOC_LITERAL(8, 84, 14), // "slotDInfoBolas"
QT_MOC_LITERAL(9, 99, 14), // "slotDInfoTabla"
QT_MOC_LITERAL(10, 114, 17), // "slotDControlBolas"
QT_MOC_LITERAL(11, 132, 15), // "slotDArbolBolas"
QT_MOC_LITERAL(12, 148, 10), // "slotChocar"
QT_MOC_LITERAL(13, 159, 18), // "slotGuardarPartida"
QT_MOC_LITERAL(14, 178, 17) // "slotCargarPartida"

    },
    "MainWindow\0signalNuevaBola\0\0Bola*\0"
    "bola\0jugadorChoqued\0slotRepintar\0"
    "slotDInformacion\0slotDInfoBolas\0"
    "slotDInfoTabla\0slotDControlBolas\0"
    "slotDArbolBolas\0slotChocar\0"
    "slotGuardarPartida\0slotCargarPartida"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,
      13,    0,   80,    2, 0x0a /* Public */,
      14,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalNuevaBola((*reinterpret_cast< Bola*(*)>(_a[1]))); break;
        case 1: _t->jugadorChoqued(); break;
        case 2: _t->slotRepintar(); break;
        case 3: _t->slotDInformacion(); break;
        case 4: _t->slotDInfoBolas(); break;
        case 5: _t->slotDInfoTabla(); break;
        case 6: _t->slotDControlBolas(); break;
        case 7: _t->slotDArbolBolas(); break;
        case 8: _t->slotChocar(); break;
        case 9: _t->slotGuardarPartida(); break;
        case 10: _t->slotCargarPartida(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(Bola * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalNuevaBola)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::jugadorChoqued)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalNuevaBola(Bola * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::jugadorChoqued()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
