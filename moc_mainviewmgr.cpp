/****************************************************************************
** Meta object code from reading C++ file 'mainviewmgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ViewManager/mainviewmgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainviewmgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainViewMgr_t {
    QByteArrayData data[29];
    char stringdata0[335];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainViewMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainViewMgr_t qt_meta_stringdata_MainViewMgr = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MainViewMgr"
QT_MOC_LITERAL(1, 12, 13), // "passedChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "modelChanged"
QT_MOC_LITERAL(4, 40, 17), // "modelProxyChanged"
QT_MOC_LITERAL(5, 58, 15), // "editModeChanged"
QT_MOC_LITERAL(6, 74, 18), // "groupFilterChanged"
QT_MOC_LITERAL(7, 93, 9), // "sgnAddRow"
QT_MOC_LITERAL(8, 103, 11), // "StudentTerm"
QT_MOC_LITERAL(9, 115, 2), // "st"
QT_MOC_LITERAL(10, 118, 12), // "sgnRemoveRow"
QT_MOC_LITERAL(11, 131, 3), // "row"
QT_MOC_LITERAL(12, 135, 20), // "sgnChangeStudentInfo"
QT_MOC_LITERAL(13, 156, 5), // "index"
QT_MOC_LITERAL(14, 162, 5), // "value"
QT_MOC_LITERAL(15, 168, 4), // "role"
QT_MOC_LITERAL(16, 173, 25), // "sgnPassedConditionChanged"
QT_MOC_LITERAL(17, 199, 4), // "cond"
QT_MOC_LITERAL(18, 204, 16), // "sgnFilterChanged"
QT_MOC_LITERAL(19, 221, 6), // "filter"
QT_MOC_LITERAL(20, 228, 15), // "editStudentInfo"
QT_MOC_LITERAL(21, 244, 2), // "id"
QT_MOC_LITERAL(22, 247, 6), // "passed"
QT_MOC_LITERAL(23, 254, 5), // "model"
QT_MOC_LITERAL(24, 260, 19), // "QAbstractItemModel*"
QT_MOC_LITERAL(25, 280, 10), // "modelProxy"
QT_MOC_LITERAL(26, 291, 22), // "QSortFilterProxyModel*"
QT_MOC_LITERAL(27, 314, 8), // "editMode"
QT_MOC_LITERAL(28, 323, 11) // "groupFilter"

    },
    "MainViewMgr\0passedChanged\0\0modelChanged\0"
    "modelProxyChanged\0editModeChanged\0"
    "groupFilterChanged\0sgnAddRow\0StudentTerm\0"
    "st\0sgnRemoveRow\0row\0sgnChangeStudentInfo\0"
    "index\0value\0role\0sgnPassedConditionChanged\0"
    "cond\0sgnFilterChanged\0filter\0"
    "editStudentInfo\0id\0passed\0model\0"
    "QAbstractItemModel*\0modelProxy\0"
    "QSortFilterProxyModel*\0editMode\0"
    "groupFilter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainViewMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       5,   96, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,
       7,    1,   74,    2, 0x06 /* Public */,
      10,    1,   77,    2, 0x06 /* Public */,
      12,    3,   80,    2, 0x06 /* Public */,
      16,    1,   87,    2, 0x06 /* Public */,
      18,    1,   90,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      20,    1,   93,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QVariant, QMetaType::Int,   13,   14,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Int,   19,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   21,

 // properties: name, type, flags
      22, QMetaType::Bool, 0x00495103,
      23, 0x80000000 | 24, 0x00495009,
      25, 0x80000000 | 26, 0x00495009,
      27, QMetaType::Bool, 0x00495103,
      28, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void MainViewMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainViewMgr *_t = static_cast<MainViewMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->passedChanged(); break;
        case 1: _t->modelChanged(); break;
        case 2: _t->modelProxyChanged(); break;
        case 3: _t->editModeChanged(); break;
        case 4: _t->groupFilterChanged(); break;
        case 5: _t->sgnAddRow((*reinterpret_cast< const StudentTerm(*)>(_a[1]))); break;
        case 6: _t->sgnRemoveRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sgnChangeStudentInfo((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->sgnPassedConditionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->sgnFilterChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->editStudentInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainViewMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainViewMgr::passedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainViewMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainViewMgr::modelChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainViewMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainViewMgr::modelProxyChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainViewMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainViewMgr::editModeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainViewMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainViewMgr::groupFilterChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainViewMgr::*_t)(const StudentTerm & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainViewMgr::sgnAddRow)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainViewMgr::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainViewMgr::sgnRemoveRow)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainViewMgr::*_t)(const QModelIndex & , const QVariant & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainViewMgr::sgnChangeStudentInfo)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MainViewMgr::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainViewMgr::sgnPassedConditionChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MainViewMgr::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainViewMgr::sgnFilterChanged)) {
                *result = 9;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractItemModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MainViewMgr *_t = static_cast<MainViewMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->passed(); break;
        case 1: *reinterpret_cast< QAbstractItemModel**>(_v) = _t->model(); break;
        case 2: *reinterpret_cast< QSortFilterProxyModel**>(_v) = _t->modelProxy(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->editMode(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->groupFilter(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MainViewMgr *_t = static_cast<MainViewMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPassed(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setEditMode(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setGroupFilter(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject MainViewMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainViewMgr.data,
      qt_meta_data_MainViewMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainViewMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainViewMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainViewMgr.stringdata0))
        return static_cast<void*>(const_cast< MainViewMgr*>(this));
    return QObject::qt_metacast(_clname);
}

int MainViewMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MainViewMgr::passedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainViewMgr::modelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainViewMgr::modelProxyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainViewMgr::editModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainViewMgr::groupFilterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainViewMgr::sgnAddRow(const StudentTerm & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainViewMgr::sgnRemoveRow(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainViewMgr::sgnChangeStudentInfo(const QModelIndex & _t1, const QVariant & _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainViewMgr::sgnPassedConditionChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainViewMgr::sgnFilterChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
