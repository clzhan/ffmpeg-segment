/****************************************************************************
** Meta object code from reading C++ file 'pathprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pathprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pathprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PathProcess_t {
    QByteArrayData data[11];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PathProcess_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PathProcess_t qt_meta_stringdata_PathProcess = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PathProcess"
QT_MOC_LITERAL(1, 12, 16), // "commandSuccessed"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 2), // "ip"
QT_MOC_LITERAL(4, 33, 13), // "commandFailed"
QT_MOC_LITERAL(5, 47, 3), // "Log"
QT_MOC_LITERAL(6, 51, 8), // "sMessage"
QT_MOC_LITERAL(7, 60, 16), // "ThreadProcessBar"
QT_MOC_LITERAL(8, 77, 5), // "value"
QT_MOC_LITERAL(9, 83, 23), // "readyReadStandardOutput"
QT_MOC_LITERAL(10, 107, 15) // "ConvertFinished"

    },
    "PathProcess\0commandSuccessed\0\0ip\0"
    "commandFailed\0Log\0sMessage\0ThreadProcessBar\0"
    "value\0readyReadStandardOutput\0"
    "ConvertFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PathProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,
       7,    1,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PathProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PathProcess *_t = static_cast<PathProcess *>(_o);
        switch (_id) {
        case 0: _t->commandSuccessed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->commandFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->ThreadProcessBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->readyReadStandardOutput(); break;
        case 5: _t->ConvertFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PathProcess::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PathProcess::commandSuccessed)) {
                *result = 0;
            }
        }
        {
            typedef void (PathProcess::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PathProcess::commandFailed)) {
                *result = 1;
            }
        }
        {
            typedef void (PathProcess::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PathProcess::Log)) {
                *result = 2;
            }
        }
        {
            typedef void (PathProcess::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PathProcess::ThreadProcessBar)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject PathProcess::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PathProcess.data,
      qt_meta_data_PathProcess,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PathProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PathProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PathProcess.stringdata))
        return static_cast<void*>(const_cast< PathProcess*>(this));
    return QThread::qt_metacast(_clname);
}

int PathProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PathProcess::commandSuccessed(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PathProcess::commandFailed(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PathProcess::Log(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PathProcess::ThreadProcessBar(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
