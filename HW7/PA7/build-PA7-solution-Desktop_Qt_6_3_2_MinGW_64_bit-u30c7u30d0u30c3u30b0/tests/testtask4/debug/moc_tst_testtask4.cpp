/****************************************************************************
** Meta object code from reading C++ file 'tst_testtask4.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../PA7-solution/tests/testtask4/tst_testtask4.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_testtask4.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestTask4_t {
    uint offsetsAndSizes[22];
    char stringdata0[10];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[20];
    char stringdata5[20];
    char stringdata6[19];
    char stringdata7[19];
    char stringdata8[19];
    char stringdata9[19];
    char stringdata10[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TestTask4_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_TestTask4_t qt_meta_stringdata_TestTask4 = {
    {
        QT_MOC_LITERAL(0, 9),  // "TestTask4"
        QT_MOC_LITERAL(10, 21),  // "testSelectModeRegular"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 20),  // "testSelectModeAbsurd"
        QT_MOC_LITERAL(54, 19),  // "testSelectModeMulti"
        QT_MOC_LITERAL(74, 19),  // "testSelectModeTimed"
        QT_MOC_LITERAL(94, 18),  // "testSwitchModeRAMT"
        QT_MOC_LITERAL(113, 18),  // "testSwitchModeRMAT"
        QT_MOC_LITERAL(132, 18),  // "testSwitchModeRTAM"
        QT_MOC_LITERAL(151, 18),  // "testSwitchModeRTMA"
        QT_MOC_LITERAL(170, 21)   // "testStartRegularRound"
    },
    "TestTask4",
    "testSelectModeRegular",
    "",
    "testSelectModeAbsurd",
    "testSelectModeMulti",
    "testSelectModeTimed",
    "testSwitchModeRAMT",
    "testSwitchModeRMAT",
    "testSwitchModeRTAM",
    "testSwitchModeRTMA",
    "testStartRegularRound"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestTask4[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    0,   76,    2, 0x08,    9 /* Private */,

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

void TestTask4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestTask4 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->testSelectModeRegular(); break;
        case 1: _t->testSelectModeAbsurd(); break;
        case 2: _t->testSelectModeMulti(); break;
        case 3: _t->testSelectModeTimed(); break;
        case 4: _t->testSwitchModeRAMT(); break;
        case 5: _t->testSwitchModeRMAT(); break;
        case 6: _t->testSwitchModeRTAM(); break;
        case 7: _t->testSwitchModeRTMA(); break;
        case 8: _t->testStartRegularRound(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TestTask4::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestTask4.offsetsAndSizes,
    qt_meta_data_TestTask4,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TestTask4_t
, QtPrivate::TypeAndForceComplete<TestTask4, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TestTask4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestTask4::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestTask4.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestTask4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
