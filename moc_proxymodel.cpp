/****************************************************************************
** Meta object code from reading C++ file 'proxymodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Model/proxymodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proxymodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProxyModel_t {
    QByteArrayData data[14];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProxyModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProxyModel_t qt_meta_stringdata_ProxyModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ProxyModel"
QT_MOC_LITERAL(1, 11, 13), // "filterChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "passedChanged"
QT_MOC_LITERAL(4, 40, 9), // "setPassed"
QT_MOC_LITERAL(5, 50, 6), // "passed"
QT_MOC_LITERAL(6, 57, 9), // "setFilter"
QT_MOC_LITERAL(7, 67, 6), // "filter"
QT_MOC_LITERAL(8, 74, 12), // "Proxy_Filter"
QT_MOC_LITERAL(9, 87, 9), // "GROUP_ALL"
QT_MOC_LITERAL(10, 97, 7), // "GROUP_A"
QT_MOC_LITERAL(11, 105, 7), // "GROUP_B"
QT_MOC_LITERAL(12, 113, 7), // "GROUP_C"
QT_MOC_LITERAL(13, 121, 7) // "GROUP_D"

    },
    "ProxyModel\0filterChanged\0\0passedChanged\0"
    "setPassed\0passed\0setFilter\0filter\0"
    "Proxy_Filter\0GROUP_ALL\0GROUP_A\0GROUP_B\0"
    "GROUP_C\0GROUP_D"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProxyModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       2,   42, // properties
       1,   50, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   36,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // properties: name, type, flags
       7, QMetaType::Int, 0x00495103,
       5, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

 // enums: name, flags, count, data
       8, 0x0,    5,   54,

 // enum data: key, value
       9, uint(ProxyModel::GROUP_ALL),
      10, uint(ProxyModel::GROUP_A),
      11, uint(ProxyModel::GROUP_B),
      12, uint(ProxyModel::GROUP_C),
      13, uint(ProxyModel::GROUP_D),

       0        // eod
};

void ProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProxyModel *_t = static_cast<ProxyModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filterChanged(); break;
        case 1: _t->passedChanged(); break;
        case 2: _t->setPassed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ProxyModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProxyModel::filterChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ProxyModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ProxyModel::passedChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ProxyModel *_t = static_cast<ProxyModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->filter(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->passed(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ProxyModel *_t = static_cast<ProxyModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFilter(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setPassed(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ProxyModel::staticMetaObject = {
    { &QSortFilterProxyModel::staticMetaObject, qt_meta_stringdata_ProxyModel.data,
      qt_meta_data_ProxyModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ProxyModel.stringdata0))
        return static_cast<void*>(const_cast< ProxyModel*>(this));
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int ProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ProxyModel::filterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ProxyModel::passedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
