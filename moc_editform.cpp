/****************************************************************************
** Meta object code from reading C++ file 'editform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ViewManager/editform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EditForm_t {
    QByteArrayData data[22];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditForm_t qt_meta_stringdata_EditForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "EditForm"
QT_MOC_LITERAL(1, 9, 16), // "firstNameChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "lastNameChanged"
QT_MOC_LITERAL(4, 43, 12), // "emailChanged"
QT_MOC_LITERAL(5, 56, 12), // "groupChanged"
QT_MOC_LITERAL(6, 69, 17), // "assesmentsChanged"
QT_MOC_LITERAL(7, 87, 16), // "homework1Changed"
QT_MOC_LITERAL(8, 104, 16), // "homework2Changed"
QT_MOC_LITERAL(9, 121, 15), // "labGradeChanged"
QT_MOC_LITERAL(10, 137, 16), // "testGradeChanged"
QT_MOC_LITERAL(11, 154, 18), // "confirmStudentInfo"
QT_MOC_LITERAL(12, 173, 9), // "firstName"
QT_MOC_LITERAL(13, 183, 8), // "lastName"
QT_MOC_LITERAL(14, 192, 5), // "email"
QT_MOC_LITERAL(15, 198, 5), // "group"
QT_MOC_LITERAL(16, 204, 10), // "assesments"
QT_MOC_LITERAL(17, 215, 2), // "id"
QT_MOC_LITERAL(18, 218, 9), // "homework1"
QT_MOC_LITERAL(19, 228, 9), // "homework2"
QT_MOC_LITERAL(20, 238, 8), // "labGrade"
QT_MOC_LITERAL(21, 247, 9) // "testGrade"

    },
    "EditForm\0firstNameChanged\0\0lastNameChanged\0"
    "emailChanged\0groupChanged\0assesmentsChanged\0"
    "homework1Changed\0homework2Changed\0"
    "labGradeChanged\0testGradeChanged\0"
    "confirmStudentInfo\0firstName\0lastName\0"
    "email\0group\0assesments\0id\0homework1\0"
    "homework2\0labGrade\0testGrade"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
      10,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    0,   71,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   73,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,
      14, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      16, QMetaType::Int, 0x00495103,
      17, QMetaType::Int, 0x00095001,
      18, QMetaType::Double, 0x00495103,
      19, QMetaType::Double, 0x00495103,
      20, QMetaType::Double, 0x00495103,
      21, QMetaType::Double, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       0,
       5,
       6,
       7,
       8,

       0        // eod
};

void EditForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditForm *_t = static_cast<EditForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->firstNameChanged(); break;
        case 1: _t->lastNameChanged(); break;
        case 2: _t->emailChanged(); break;
        case 3: _t->groupChanged(); break;
        case 4: _t->assesmentsChanged(); break;
        case 5: _t->homework1Changed(); break;
        case 6: _t->homework2Changed(); break;
        case 7: _t->labGradeChanged(); break;
        case 8: _t->testGradeChanged(); break;
        case 9: _t->confirmStudentInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EditForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditForm::firstNameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (EditForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditForm::lastNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (EditForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditForm::emailChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (EditForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditForm::groupChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (EditForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditForm::assesmentsChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (EditForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditForm::homework1Changed)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (EditForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditForm::homework2Changed)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (EditForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditForm::labGradeChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (EditForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditForm::testGradeChanged)) {
                *result = 8;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        EditForm *_t = static_cast<EditForm *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->firstName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->lastName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->email(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->group(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->assesments(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->id(); break;
        case 6: *reinterpret_cast< double*>(_v) = _t->homework1(); break;
        case 7: *reinterpret_cast< double*>(_v) = _t->homework2(); break;
        case 8: *reinterpret_cast< double*>(_v) = _t->labGrade(); break;
        case 9: *reinterpret_cast< double*>(_v) = _t->testGrade(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        EditForm *_t = static_cast<EditForm *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFirstName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setLastName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setEmail(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setGroup(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setAssesments(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setHomework1(*reinterpret_cast< double*>(_v)); break;
        case 7: _t->setHomework2(*reinterpret_cast< double*>(_v)); break;
        case 8: _t->setLabGrade(*reinterpret_cast< double*>(_v)); break;
        case 9: _t->setTestGrade(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject EditForm::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EditForm.data,
      qt_meta_data_EditForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EditForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EditForm.stringdata0))
        return static_cast<void*>(const_cast< EditForm*>(this));
    return QObject::qt_metacast(_clname);
}

int EditForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void EditForm::firstNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void EditForm::lastNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void EditForm::emailChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void EditForm::groupChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void EditForm::assesmentsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void EditForm::homework1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void EditForm::homework2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void EditForm::labGradeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void EditForm::testGradeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
