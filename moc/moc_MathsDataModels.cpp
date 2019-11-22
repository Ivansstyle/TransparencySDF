/****************************************************************************
** Meta object code from reading C++ file 'MathsDataModels.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/nodes/MathsDataModels.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MathsDataModels.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScalarDataModel_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScalarDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScalarDataModel_t qt_meta_stringdata_ScalarDataModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ScalarDataModel"
QT_MOC_LITERAL(1, 16, 9), // "valueEdit"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "ScalarDataModel\0valueEdit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScalarDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void ScalarDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScalarDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueEdit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScalarDataModel::staticMetaObject = { {
    &NodeDataModel::staticMetaObject,
    qt_meta_stringdata_ScalarDataModel.data,
    qt_meta_data_ScalarDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScalarDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScalarDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScalarDataModel.stringdata0))
        return static_cast<void*>(this);
    return NodeDataModel::qt_metacast(_clname);
}

int ScalarDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NodeDataModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_VectorDataModel_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VectorDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VectorDataModel_t qt_meta_stringdata_VectorDataModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "VectorDataModel"
QT_MOC_LITERAL(1, 16, 9), // "valueEdit"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "VectorDataModel\0valueEdit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VectorDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void VectorDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VectorDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueEdit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VectorDataModel::staticMetaObject = { {
    &NodeDataModel::staticMetaObject,
    qt_meta_stringdata_VectorDataModel.data,
    qt_meta_data_VectorDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VectorDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VectorDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VectorDataModel.stringdata0))
        return static_cast<void*>(this);
    return NodeDataModel::qt_metacast(_clname);
}

int VectorDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NodeDataModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SineDataModel_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SineDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SineDataModel_t qt_meta_stringdata_SineDataModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SineDataModel"
QT_MOC_LITERAL(1, 14, 9), // "valueEdit"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "SineDataModel\0valueEdit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SineDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void SineDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SineDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueEdit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SineDataModel::staticMetaObject = { {
    &NodeDataModel::staticMetaObject,
    qt_meta_stringdata_SineDataModel.data,
    qt_meta_data_SineDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SineDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SineDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SineDataModel.stringdata0))
        return static_cast<void*>(this);
    return NodeDataModel::qt_metacast(_clname);
}

int SineDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NodeDataModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_CosineDataModel_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CosineDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CosineDataModel_t qt_meta_stringdata_CosineDataModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CosineDataModel"
QT_MOC_LITERAL(1, 16, 9), // "valueEdit"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "CosineDataModel\0valueEdit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CosineDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void CosineDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CosineDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueEdit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CosineDataModel::staticMetaObject = { {
    &NodeDataModel::staticMetaObject,
    qt_meta_stringdata_CosineDataModel.data,
    qt_meta_data_CosineDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CosineDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CosineDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CosineDataModel.stringdata0))
        return static_cast<void*>(this);
    return NodeDataModel::qt_metacast(_clname);
}

int CosineDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NodeDataModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_MultiplyDataModel_t {
    QByteArrayData data[3];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MultiplyDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MultiplyDataModel_t qt_meta_stringdata_MultiplyDataModel = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MultiplyDataModel"
QT_MOC_LITERAL(1, 18, 9), // "valueEdit"
QT_MOC_LITERAL(2, 28, 0) // ""

    },
    "MultiplyDataModel\0valueEdit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultiplyDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void MultiplyDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MultiplyDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueEdit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MultiplyDataModel::staticMetaObject = { {
    &NodeDataModel::staticMetaObject,
    qt_meta_stringdata_MultiplyDataModel.data,
    qt_meta_data_MultiplyDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MultiplyDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultiplyDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MultiplyDataModel.stringdata0))
        return static_cast<void*>(this);
    return NodeDataModel::qt_metacast(_clname);
}

int MultiplyDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NodeDataModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_DivideDataModel_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DivideDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DivideDataModel_t qt_meta_stringdata_DivideDataModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DivideDataModel"
QT_MOC_LITERAL(1, 16, 9), // "valueEdit"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "DivideDataModel\0valueEdit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DivideDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void DivideDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DivideDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueEdit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DivideDataModel::staticMetaObject = { {
    &NodeDataModel::staticMetaObject,
    qt_meta_stringdata_DivideDataModel.data,
    qt_meta_data_DivideDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DivideDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DivideDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DivideDataModel.stringdata0))
        return static_cast<void*>(this);
    return NodeDataModel::qt_metacast(_clname);
}

int DivideDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NodeDataModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_AdditionDataModel_t {
    QByteArrayData data[3];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdditionDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdditionDataModel_t qt_meta_stringdata_AdditionDataModel = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AdditionDataModel"
QT_MOC_LITERAL(1, 18, 9), // "valueEdit"
QT_MOC_LITERAL(2, 28, 0) // ""

    },
    "AdditionDataModel\0valueEdit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdditionDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void AdditionDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdditionDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueEdit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdditionDataModel::staticMetaObject = { {
    &NodeDataModel::staticMetaObject,
    qt_meta_stringdata_AdditionDataModel.data,
    qt_meta_data_AdditionDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdditionDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdditionDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdditionDataModel.stringdata0))
        return static_cast<void*>(this);
    return NodeDataModel::qt_metacast(_clname);
}

int AdditionDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NodeDataModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SubtractionDataModel_t {
    QByteArrayData data[3];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SubtractionDataModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SubtractionDataModel_t qt_meta_stringdata_SubtractionDataModel = {
    {
QT_MOC_LITERAL(0, 0, 20), // "SubtractionDataModel"
QT_MOC_LITERAL(1, 21, 9), // "valueEdit"
QT_MOC_LITERAL(2, 31, 0) // ""

    },
    "SubtractionDataModel\0valueEdit\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SubtractionDataModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void SubtractionDataModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SubtractionDataModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueEdit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SubtractionDataModel::staticMetaObject = { {
    &NodeDataModel::staticMetaObject,
    qt_meta_stringdata_SubtractionDataModel.data,
    qt_meta_data_SubtractionDataModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SubtractionDataModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SubtractionDataModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SubtractionDataModel.stringdata0))
        return static_cast<void*>(this);
    return NodeDataModel::qt_metacast(_clname);
}

int SubtractionDataModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NodeDataModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
