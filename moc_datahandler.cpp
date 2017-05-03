/****************************************************************************
** Meta object code from reading C++ file 'datahandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Model/datahandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datahandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataHandler_t {
    QByteArrayData data[11];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataHandler_t qt_meta_stringdata_DataHandler = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DataHandler"
QT_MOC_LITERAL(1, 12, 11), // "sltRowAdded"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "StudentTerm"
QT_MOC_LITERAL(4, 37, 2), // "st"
QT_MOC_LITERAL(5, 40, 13), // "sltRowRemoved"
QT_MOC_LITERAL(6, 54, 3), // "row"
QT_MOC_LITERAL(7, 58, 21), // "sltStudentInfoChanged"
QT_MOC_LITERAL(8, 80, 5), // "index"
QT_MOC_LITERAL(9, 86, 5), // "value"
QT_MOC_LITERAL(10, 92, 4) // "role"

    },
    "DataHandler\0sltRowAdded\0\0StudentTerm\0"
    "st\0sltRowRemoved\0row\0sltStudentInfoChanged\0"
    "index\0value\0role"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    1,   32,    2, 0x0a /* Public */,
       7,    3,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QVariant, QMetaType::Int,    8,    9,   10,

       0        // eod
};

void DataHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataHandler *_t = static_cast<DataHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sltRowAdded((*reinterpret_cast< const StudentTerm(*)>(_a[1]))); break;
        case 1: _t->sltRowRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sltStudentInfoChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject DataHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataHandler.data,
      qt_meta_data_DataHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataHandler.stringdata0))
        return static_cast<void*>(const_cast< DataHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int DataHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
