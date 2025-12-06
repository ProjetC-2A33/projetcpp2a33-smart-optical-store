/****************************************************************************
** Meta object code from reading C++ file 'pageplanning.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Qtproject/pageplanning.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pageplanning.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pageplanning_t {
    QByteArrayData data[14];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pageplanning_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pageplanning_t qt_meta_stringdata_pageplanning = {
    {
QT_MOC_LITERAL(0, 0, 12), // "pageplanning"
QT_MOC_LITERAL(1, 13, 20), // "on_logoutpb5_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "on_client5pb_clicked"
QT_MOC_LITERAL(4, 56, 21), // "on_employe5pb_clicked"
QT_MOC_LITERAL(5, 78, 24), // "on_abonnement5pb_clicked"
QT_MOC_LITERAL(6, 103, 22), // "on_activite5pb_clicked"
QT_MOC_LITERAL(7, 126, 18), // "on_back5pb_clicked"
QT_MOC_LITERAL(8, 145, 24), // "on_pb_supprimerr_clicked"
QT_MOC_LITERAL(9, 170, 23), // "on_pb_modifierr_clicked"
QT_MOC_LITERAL(10, 194, 22), // "on_pb_ajouterr_clicked"
QT_MOC_LITERAL(11, 217, 22), // "handleMessageBoxResult"
QT_MOC_LITERAL(12, 240, 6), // "result"
QT_MOC_LITERAL(13, 247, 12) // "refreshTable"

    },
    "pageplanning\0on_logoutpb5_clicked\0\0"
    "on_client5pb_clicked\0on_employe5pb_clicked\0"
    "on_abonnement5pb_clicked\0"
    "on_activite5pb_clicked\0on_back5pb_clicked\0"
    "on_pb_supprimerr_clicked\0"
    "on_pb_modifierr_clicked\0on_pb_ajouterr_clicked\0"
    "handleMessageBoxResult\0result\0"
    "refreshTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pageplanning[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

void pageplanning::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pageplanning *_t = static_cast<pageplanning *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_logoutpb5_clicked(); break;
        case 1: _t->on_client5pb_clicked(); break;
        case 2: _t->on_employe5pb_clicked(); break;
        case 3: _t->on_abonnement5pb_clicked(); break;
        case 4: _t->on_activite5pb_clicked(); break;
        case 5: _t->on_back5pb_clicked(); break;
        case 6: _t->on_pb_supprimerr_clicked(); break;
        case 7: _t->on_pb_modifierr_clicked(); break;
        case 8: _t->on_pb_ajouterr_clicked(); break;
        case 9: _t->handleMessageBoxResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->refreshTable(); break;
        default: ;
        }
    }
}

const QMetaObject pageplanning::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_pageplanning.data,
      qt_meta_data_pageplanning,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *pageplanning::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pageplanning::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pageplanning.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int pageplanning::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
