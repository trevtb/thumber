/****************************************************************************
** Meta object code from reading C++ file 'thumbcreator.h'
**
** Created: Mon Nov 25 16:45:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "thumbcreator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thumbcreator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThumbCreator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      26,   22,   13,   13, 0x0a,
      60,   13,   48,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ThumbCreator[] = {
    "ThumbCreator\0\0start()\0msg\0"
    "printMsg(const char*)\0std::string\0"
    "currentDateTime()\0"
};

void ThumbCreator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThumbCreator *_t = static_cast<ThumbCreator *>(_o);
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->printMsg((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 2: { std::string _r = _t->currentDateTime();
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThumbCreator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThumbCreator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThumbCreator,
      qt_meta_data_ThumbCreator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThumbCreator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThumbCreator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThumbCreator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThumbCreator))
        return static_cast<void*>(const_cast< ThumbCreator*>(this));
    return QObject::qt_metacast(_clname);
}

int ThumbCreator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
