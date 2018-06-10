/****************************************************************************
** Meta object code from reading C++ file 'Controls.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Controls.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controls.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Controls_t {
    QByteArrayData data[10];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controls_t qt_meta_stringdata_Controls = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Controls"
QT_MOC_LITERAL(1, 9, 17), // "slot_showPassword"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "state"
QT_MOC_LITERAL(4, 34, 28), // "slot_copyThemeInWritingField"
QT_MOC_LITERAL(5, 63, 3), // "str"
QT_MOC_LITERAL(6, 67, 17), // "slot_backToThemes"
QT_MOC_LITERAL(7, 85, 24), // "slot_relatedPropositions"
QT_MOC_LITERAL(8, 110, 34), // "slot_copyPropositionInWriting..."
QT_MOC_LITERAL(9, 145, 20) // "slot_backToQuestions"

    },
    "Controls\0slot_showPassword\0\0state\0"
    "slot_copyThemeInWritingField\0str\0"
    "slot_backToThemes\0slot_relatedPropositions\0"
    "slot_copyPropositionInWritingField\0"
    "slot_backToQuestions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    1,   47,    2, 0x0a /* Public */,
       6,    0,   50,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,
       8,    1,   52,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void Controls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controls *_t = static_cast<Controls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_showPassword((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slot_copyThemeInWritingField((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slot_backToThemes(); break;
        case 3: _t->slot_relatedPropositions(); break;
        case 4: _t->slot_copyPropositionInWritingField((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slot_backToQuestions(); break;
        default: ;
        }
    }
}

const QMetaObject Controls::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Controls.data,
      qt_meta_data_Controls,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Controls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controls::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Controls.stringdata0))
        return static_cast<void*>(const_cast< Controls*>(this));
    return QWidget::qt_metacast(_clname);
}

int Controls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
