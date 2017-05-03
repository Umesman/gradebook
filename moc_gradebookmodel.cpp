/****************************************************************************
** Meta object code from reading C++ file 'gradebookmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Model/gradebookmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gradebookmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GradebookModel_t {
    QByteArrayData data[18];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GradebookModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GradebookModel_t qt_meta_stringdata_GradebookModel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GradebookModel"
QT_MOC_LITERAL(1, 15, 10), // "headerData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "section"
QT_MOC_LITERAL(4, 35, 15), // "Qt::Orientation"
QT_MOC_LITERAL(5, 51, 11), // "orientation"
QT_MOC_LITERAL(6, 63, 4), // "role"
QT_MOC_LITERAL(7, 68, 13), // "HeaderSection"
QT_MOC_LITERAL(8, 82, 9), // "FirstName"
QT_MOC_LITERAL(9, 92, 8), // "LastName"
QT_MOC_LITERAL(10, 101, 5), // "Final"
QT_MOC_LITERAL(11, 107, 5), // "Email"
QT_MOC_LITERAL(12, 113, 9), // "Homework1"
QT_MOC_LITERAL(13, 123, 9), // "Homework2"
QT_MOC_LITERAL(14, 133, 8), // "Labgrade"
QT_MOC_LITERAL(15, 142, 9), // "TestGrade"
QT_MOC_LITERAL(16, 152, 7), // "Actions"
QT_MOC_LITERAL(17, 160, 11) // "LastSection"

    },
    "GradebookModel\0headerData\0\0section\0"
    "Qt::Orientation\0orientation\0role\0"
    "HeaderSection\0FirstName\0LastName\0Final\0"
    "Email\0Homework1\0Homework2\0Labgrade\0"
    "TestGrade\0Actions\0LastSection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GradebookModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       1,   44, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x02 /* Public */,
       1,    2,   36,    2, 0x22 /* Public | MethodCloned */,
       1,    1,   41,    2, 0x22 /* Public | MethodCloned */,

 // methods: parameters
    QMetaType::QVariant, QMetaType::Int, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::QVariant, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::QVariant, QMetaType::Int,    3,

 // enums: name, flags, count, data
       7, 0x0,   10,   48,

 // enum data: key, value
       8, uint(GradebookModel::FirstName),
       9, uint(GradebookModel::LastName),
      10, uint(GradebookModel::Final),
      11, uint(GradebookModel::Email),
      12, uint(GradebookModel::Homework1),
      13, uint(GradebookModel::Homework2),
      14, uint(GradebookModel::Labgrade),
      15, uint(GradebookModel::TestGrade),
      16, uint(GradebookModel::Actions),
      17, uint(GradebookModel::LastSection),

       0        // eod
};

void GradebookModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GradebookModel *_t = static_cast<GradebookModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->headerData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::Orientation(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 1: { QVariant _r = _t->headerData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::Orientation(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 2: { QVariant _r = _t->headerData((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject GradebookModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_GradebookModel.data,
      qt_meta_data_GradebookModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GradebookModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GradebookModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GradebookModel.stringdata0))
        return static_cast<void*>(const_cast< GradebookModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int GradebookModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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
