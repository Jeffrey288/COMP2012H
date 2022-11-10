/****************************************************************************
** Meta object code from reading C++ file 'tst_testtask2.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../PA7-solution/tests/testtask2/tst_testtask2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_testtask2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestTask2_t {
    uint offsetsAndSizes[16];
    char stringdata0[10];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[22];
    char stringdata5[31];
    char stringdata6[29];
    char stringdata7[35];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TestTask2_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_TestTask2_t qt_meta_stringdata_TestTask2 = {
    {
        QT_MOC_LITERAL(0, 9),  // "TestTask2"
        QT_MOC_LITERAL(10, 18),  // "verifyInvalidPopup"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 14),  // "testKeyPresses"
        QT_MOC_LITERAL(45, 21),  // "testKeyPressesWithDel"
        QT_MOC_LITERAL(67, 30),  // "testKeyPressesWithEnterSuccess"
        QT_MOC_LITERAL(98, 28),  // "testKeyPressesWithEnterEarly"
        QT_MOC_LITERAL(127, 34)   // "testKeyPressesWithEnterInvali..."
    },
    "TestTask2",
    "verifyInvalidPopup",
    "",
    "testKeyPresses",
    "testKeyPressesWithDel",
    "testKeyPressesWithEnterSuccess",
    "testKeyPressesWithEnterEarly",
    "testKeyPressesWithEnterInvalidWord"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestTask2[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestTask2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestTask2 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->verifyInvalidPopup(); break;
        case 1: _t->testKeyPresses(); break;
        case 2: _t->testKeyPressesWithDel(); break;
        case 3: _t->testKeyPressesWithEnterSuccess(); break;
        case 4: _t->testKeyPressesWithEnterEarly(); break;
        case 5: _t->testKeyPressesWithEnterInvalidWord(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TestTask2::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestTask2.offsetsAndSizes,
    qt_meta_data_TestTask2,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TestTask2_t
, QtPrivate::TypeAndForceComplete<TestTask2, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TestTask2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestTask2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestTask2.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestTask2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
