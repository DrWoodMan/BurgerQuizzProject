/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[354];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "slot_windowSize"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "state"
QT_MOC_LITERAL(4, 34, 15), // "slot_connection"
QT_MOC_LITERAL(5, 50, 11), // "slot_logout"
QT_MOC_LITERAL(6, 62, 13), // "slot_addTheme"
QT_MOC_LITERAL(7, 76, 16), // "slot_modifyTheme"
QT_MOC_LITERAL(8, 93, 16), // "slot_deleteTheme"
QT_MOC_LITERAL(9, 110, 21), // "slot_relatedQuestions"
QT_MOC_LITERAL(10, 132, 32), // "slot_copyQuestionInWritingFields"
QT_MOC_LITERAL(11, 165, 5), // "index"
QT_MOC_LITERAL(12, 171, 16), // "slot_addQuestion"
QT_MOC_LITERAL(13, 188, 19), // "slot_modifyQuestion"
QT_MOC_LITERAL(14, 208, 19), // "slot_deleteQuestion"
QT_MOC_LITERAL(15, 228, 24), // "slot_relatedPropositions"
QT_MOC_LITERAL(16, 253, 34), // "slot_copyPropositionInWriting..."
QT_MOC_LITERAL(17, 288, 19), // "slot_addProposition"
QT_MOC_LITERAL(18, 308, 22), // "slot_modifyProposition"
QT_MOC_LITERAL(19, 331, 22) // "slot_deleteProposition"

    },
    "MainWindow\0slot_windowSize\0\0state\0"
    "slot_connection\0slot_logout\0slot_addTheme\0"
    "slot_modifyTheme\0slot_deleteTheme\0"
    "slot_relatedQuestions\0"
    "slot_copyQuestionInWritingFields\0index\0"
    "slot_addQuestion\0slot_modifyQuestion\0"
    "slot_deleteQuestion\0slot_relatedPropositions\0"
    "slot_copyPropositionInWritingField\0"
    "slot_addProposition\0slot_modifyProposition\0"
    "slot_deleteProposition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x0a /* Public */,
       4,    0,   97,    2, 0x0a /* Public */,
       5,    0,   98,    2, 0x0a /* Public */,
       6,    0,   99,    2, 0x0a /* Public */,
       7,    0,  100,    2, 0x0a /* Public */,
       8,    0,  101,    2, 0x0a /* Public */,
       9,    0,  102,    2, 0x0a /* Public */,
      10,    1,  103,    2, 0x0a /* Public */,
      12,    0,  106,    2, 0x0a /* Public */,
      13,    0,  107,    2, 0x0a /* Public */,
      14,    0,  108,    2, 0x0a /* Public */,
      15,    0,  109,    2, 0x0a /* Public */,
      16,    1,  110,    2, 0x0a /* Public */,
      17,    0,  113,    2, 0x0a /* Public */,
      18,    0,  114,    2, 0x0a /* Public */,
      19,    0,  115,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_windowSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slot_connection(); break;
        case 2: _t->slot_logout(); break;
        case 3: _t->slot_addTheme(); break;
        case 4: _t->slot_modifyTheme(); break;
        case 5: _t->slot_deleteTheme(); break;
        case 6: _t->slot_relatedQuestions(); break;
        case 7: _t->slot_copyQuestionInWritingFields((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slot_addQuestion(); break;
        case 9: _t->slot_modifyQuestion(); break;
        case 10: _t->slot_deleteQuestion(); break;
        case 11: _t->slot_relatedPropositions(); break;
        case 12: _t->slot_copyPropositionInWritingField((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->slot_addProposition(); break;
        case 14: _t->slot_modifyProposition(); break;
        case 15: _t->slot_deleteProposition(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
