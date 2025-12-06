/****************************************************************************
** Meta object code from reading C++ file 'pageactivite.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Qtproject/pageactivite.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pageactivite.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pageactivite_t {
    QByteArrayData data[17];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pageactivite_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pageactivite_t qt_meta_stringdata_Pageactivite = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Pageactivite"
QT_MOC_LITERAL(1, 13, 23), // "on_pb_supprimer_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 24), // "on_pb_modifier_2_clicked"
QT_MOC_LITERAL(4, 63, 21), // "on_pb_ajouter_clicked"
QT_MOC_LITERAL(5, 85, 22), // "handleMessageBoxResult"
QT_MOC_LITERAL(6, 108, 6), // "result"
QT_MOC_LITERAL(7, 115, 12), // "refreshTable"
QT_MOC_LITERAL(8, 128, 20), // "on_logoutpb3_clicked"
QT_MOC_LITERAL(9, 149, 20), // "on_client3pb_clicked"
QT_MOC_LITERAL(10, 170, 21), // "on_employe3pb_clicked"
QT_MOC_LITERAL(11, 192, 24), // "on_abonnement3pb_clicked"
QT_MOC_LITERAL(12, 217, 22), // "on_planning3pb_clicked"
QT_MOC_LITERAL(13, 240, 18), // "on_back3pb_clicked"
QT_MOC_LITERAL(14, 259, 27), // "on_tab_activite_itemClicked"
QT_MOC_LITERAL(15, 287, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(16, 305, 4) // "item"

    },
    "Pageactivite\0on_pb_supprimer_clicked\0"
    "\0on_pb_modifier_2_clicked\0"
    "on_pb_ajouter_clicked\0handleMessageBoxResult\0"
    "result\0refreshTable\0on_logoutpb3_clicked\0"
    "on_client3pb_clicked\0on_employe3pb_clicked\0"
    "on_abonnement3pb_clicked\0"
    "on_planning3pb_clicked\0on_back3pb_clicked\0"
    "on_tab_activite_itemClicked\0"
    "QTableWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pageactivite[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    1,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void Pageactivite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Pageactivite *_t = static_cast<Pageactivite *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pb_supprimer_clicked(); break;
        case 1: _t->on_pb_modifier_2_clicked(); break;
        case 2: _t->on_pb_ajouter_clicked(); break;
        case 3: _t->handleMessageBoxResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->refreshTable(); break;
        case 5: _t->on_logoutpb3_clicked(); break;
        case 6: _t->on_client3pb_clicked(); break;
        case 7: _t->on_employe3pb_clicked(); break;
        case 8: _t->on_abonnement3pb_clicked(); break;
        case 9: _t->on_planning3pb_clicked(); break;
        case 10: _t->on_back3pb_clicked(); break;
        case 11: _t->on_tab_activite_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Pageactivite::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Pageactivite.data,
      qt_meta_data_Pageactivite,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Pageactivite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pageactivite::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pageactivite.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Pageactivite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
