/****************************************************************************
** Meta object code from reading C++ file 'modelmgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Model/modelmgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelmgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModelMgr_t {
    QByteArrayData data[18];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModelMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModelMgr_t qt_meta_stringdata_ModelMgr = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ModelMgr"
QT_MOC_LITERAL(1, 9, 11), // "sgnRowAdded"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "StudentTerm"
QT_MOC_LITERAL(4, 34, 2), // "st"
QT_MOC_LITERAL(5, 37, 13), // "sgnRowRemoved"
QT_MOC_LITERAL(6, 51, 3), // "row"
QT_MOC_LITERAL(7, 55, 21), // "sgnStudentInfoChanged"
QT_MOC_LITERAL(8, 77, 5), // "index"
QT_MOC_LITERAL(9, 83, 5), // "value"
QT_MOC_LITERAL(10, 89, 4), // "role"
QT_MOC_LITERAL(11, 94, 9), // "sltAddRow"
QT_MOC_LITERAL(12, 104, 12), // "sltRemoveRow"
QT_MOC_LITERAL(13, 117, 20), // "sltChangeStudentInfo"
QT_MOC_LITERAL(14, 138, 25), // "sltPassedConditionChanged"
QT_MOC_LITERAL(15, 164, 4), // "cond"
QT_MOC_LITERAL(16, 169, 16), // "sltFilterChanged"
QT_MOC_LITERAL(17, 186, 6) // "filter"

    },
    "ModelMgr\0sgnRowAdded\0\0StudentTerm\0st\0"
    "sgnRowRemoved\0row\0sgnStudentInfoChanged\0"
    "index\0value\0role\0sltAddRow\0sltRemoveRow\0"
    "sltChangeStudentInfo\0sltPassedConditionChanged\0"
    "cond\0sltFilterChanged\0filter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModelMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       7,    3,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   67,    2, 0x0a /* Public */,
      12,    1,   70,    2, 0x0a /* Public */,
      13,    3,   73,    2, 0x0a /* Public */,
      14,    1,   80,    2, 0x0a /* Public */,
      16,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QVariant, QMetaType::Int,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QVariant, QMetaType::Int,    8,    9,   10,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void ModelMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModelMgr *_t = static_cast<ModelMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sgnRowAdded((*reinterpret_cast< const StudentTerm(*)>(_a[1]))); break;
        case 1: _t->sgnRowRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sgnStudentInfoChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->sltAddRow((*reinterpret_cast< const StudentTerm(*)>(_a[1]))); break;
        case 4: _t->sltRemoveRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sltChangeStudentInfo((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->sltPassedConditionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->sltFilterChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModelMgr::*_t)(const StudentTerm & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelMgr::sgnRowAdded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ModelMgr::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelMgr::sgnRowRemoved)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ModelMgr::*_t)(const QModelIndex & , const QVariant & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModelMgr::sgnStudentInfoChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ModelMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ModelMgr.data,
      qt_meta_data_ModelMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModelMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModelMgr.stringdata0))
        return static_cast<void*>(const_cast< ModelMgr*>(this));
    return QObject::qt_metacast(_clname);
}

int ModelMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ModelMgr::sgnRowAdded(const StudentTerm & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModelMgr::sgnRowRemoved(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ModelMgr::sgnStudentInfoChanged(const QModelIndex & _t1, const QVariant & _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
