/****************************************************************************
** Meta object code from reading C++ file 'ass2widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ass2widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ass2widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ass2Widget_t {
    QByteArrayData data[18];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ass2Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ass2Widget_t qt_meta_stringdata_Ass2Widget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Ass2Widget"
QT_MOC_LITERAL(1, 11, 23), // "on_btn_parallel_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "checked"
QT_MOC_LITERAL(4, 44, 26), // "on_btn_perspective_clicked"
QT_MOC_LITERAL(5, 71, 24), // "on_spin_top_valueChanged"
QT_MOC_LITERAL(6, 96, 3), // "top"
QT_MOC_LITERAL(7, 100, 26), // "on_spin_plfar_valueChanged"
QT_MOC_LITERAL(8, 127, 5), // "plfar"
QT_MOC_LITERAL(9, 133, 29), // "on_spin_oblscale_valueChanged"
QT_MOC_LITERAL(10, 163, 5), // "scale"
QT_MOC_LITERAL(11, 169, 29), // "on_spin_oblangle_valueChanged"
QT_MOC_LITERAL(12, 199, 5), // "angle"
QT_MOC_LITERAL(13, 205, 24), // "on_spin_fov_valueChanged"
QT_MOC_LITERAL(14, 230, 3), // "fov"
QT_MOC_LITERAL(15, 234, 26), // "on_spin_pefar_valueChanged"
QT_MOC_LITERAL(16, 261, 5), // "pefar"
QT_MOC_LITERAL(17, 267, 20) // "on_push_file_clicked"

    },
    "Ass2Widget\0on_btn_parallel_clicked\0\0"
    "checked\0on_btn_perspective_clicked\0"
    "on_spin_top_valueChanged\0top\0"
    "on_spin_plfar_valueChanged\0plfar\0"
    "on_spin_oblscale_valueChanged\0scale\0"
    "on_spin_oblangle_valueChanged\0angle\0"
    "on_spin_fov_valueChanged\0fov\0"
    "on_spin_pefar_valueChanged\0pefar\0"
    "on_push_file_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ass2Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       5,    1,   65,    2, 0x08 /* Private */,
       7,    1,   68,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      13,    1,   77,    2, 0x08 /* Private */,
      15,    1,   80,    2, 0x08 /* Private */,
      17,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,

       0        // eod
};

void Ass2Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ass2Widget *_t = static_cast<Ass2Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_parallel_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_btn_perspective_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_spin_top_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_spin_plfar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spin_oblscale_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_spin_oblangle_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_spin_fov_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_spin_pefar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_push_file_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Ass2Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Ass2Widget.data,
      qt_meta_data_Ass2Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ass2Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ass2Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ass2Widget.stringdata0))
        return static_cast<void*>(const_cast< Ass2Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Ass2Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
