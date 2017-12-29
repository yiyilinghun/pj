/****************************************************************************
** Meta object code from reading C++ file 'pj_groupbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pj_groupbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pj_groupbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pj_groupbox_t {
    QByteArrayData data[4];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pj_groupbox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pj_groupbox_t qt_meta_stringdata_pj_groupbox = {
    {
QT_MOC_LITERAL(0, 0, 11), // "pj_groupbox"
QT_MOC_LITERAL(1, 12, 14), // "auto_back_size"
QT_MOC_LITERAL(2, 27, 11), // "resFileName"
QT_MOC_LITERAL(3, 39, 6) // "resKey"

    },
    "pj_groupbox\0auto_back_size\0resFileName\0"
    "resKey"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pj_groupbox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Bool, 0x00095103,
       2, QMetaType::QString, 0x00095103,
       3, QMetaType::UInt, 0x00095103,

       0        // eod
};

void pj_groupbox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        pj_groupbox *_t = static_cast<pj_groupbox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->auto_back_size(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->resFileName(); break;
        case 2: *reinterpret_cast< quint32*>(_v) = _t->resKey(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        pj_groupbox *_t = static_cast<pj_groupbox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAuto_back_size(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setResFileName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setResKey(*reinterpret_cast< quint32*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject pj_groupbox::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_pj_groupbox.data,
      qt_meta_data_pj_groupbox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *pj_groupbox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pj_groupbox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pj_groupbox.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int pj_groupbox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
