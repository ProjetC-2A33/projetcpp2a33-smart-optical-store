/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "on_pb_supprimer_clicked",
        "",
        "on_pb_modifier_2_clicked",
        "on_pb_ajouter_clicked",
        "handleMessageBoxResult",
        "result",
        "refreshTable",
        "on_tab_clients_clicked",
        "QModelIndex",
        "index",
        "QSqlQueryModel*",
        "model",
        "on_refrech_pb_clicked",
        "on_Imprimer_clicked",
        "on_pb_pdf_clicked",
        "on_pb_word_clicked",
        "on_lineEdit_textChanged",
        "arg1",
        "on_pushButton_clicked",
        "on_tableWidget_c_cellClicked",
        "row",
        "column",
        "on_comboBox_tri_currentIndexChanged",
        "on_search_textChanged",
        "text",
        "on_stats_clicked",
        "envoyerSMS",
        "telephone",
        "message",
        "onSMSReply",
        "QNetworkReply*",
        "reply",
        "on_pushButton_envoyerSMS_clicked",
        "on_pb_history_clicked",
        "updateStatsLabel",
        "calculatePointOnCircle",
        "QPointF",
        "center",
        "radius",
        "angleDegrees"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_pb_supprimer_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_modifier_2_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_ajouter_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'handleMessageBoxResult'
        QtMocHelpers::SlotData<void(int)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'refreshTable'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_tab_clients_clicked'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Slot 'refreshTable'
        QtMocHelpers::SlotData<void(QSqlQueryModel *)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot 'on_refrech_pb_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_Imprimer_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_pdf_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_word_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_lineEdit_textChanged'
        QtMocHelpers::SlotData<void(const QString &)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 18 },
        }}),
        // Slot 'on_pushButton_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_tableWidget_c_cellClicked'
        QtMocHelpers::SlotData<void(int, int)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 21 }, { QMetaType::Int, 22 },
        }}),
        // Slot 'on_comboBox_tri_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(23, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'on_search_textChanged'
        QtMocHelpers::SlotData<void(const QString &)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 25 },
        }}),
        // Slot 'on_stats_clicked'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'envoyerSMS'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(27, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 28 }, { QMetaType::QString, 29 },
        }}),
        // Slot 'onSMSReply'
        QtMocHelpers::SlotData<void(QNetworkReply *)>(30, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 31, 32 },
        }}),
        // Slot 'on_pushButton_envoyerSMS_clicked'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_history_clicked'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateStatsLabel'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculatePointOnCircle'
        QtMocHelpers::SlotData<QPointF(QPointF, double, double)>(36, 2, QMC::AccessPrivate, 0x80000000 | 37, {{
            { 0x80000000 | 37, 38 }, { QMetaType::Double, 39 }, { QMetaType::Double, 40 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_pb_supprimer_clicked(); break;
        case 1: _t->on_pb_modifier_2_clicked(); break;
        case 2: _t->on_pb_ajouter_clicked(); break;
        case 3: _t->handleMessageBoxResult((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->refreshTable(); break;
        case 5: _t->on_tab_clients_clicked((*reinterpret_cast<std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 6: _t->refreshTable((*reinterpret_cast<std::add_pointer_t<QSqlQueryModel*>>(_a[1]))); break;
        case 7: _t->on_refrech_pb_clicked(); break;
        case 8: _t->on_Imprimer_clicked(); break;
        case 9: _t->on_pb_pdf_clicked(); break;
        case 10: _t->on_pb_word_clicked(); break;
        case 11: _t->on_lineEdit_textChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->on_pushButton_clicked(); break;
        case 13: _t->on_tableWidget_c_cellClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 14: _t->on_comboBox_tri_currentIndexChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->on_search_textChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->on_stats_clicked(); break;
        case 17: _t->envoyerSMS((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 18: _t->onSMSReply((*reinterpret_cast<std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 19: _t->on_pushButton_envoyerSMS_clicked(); break;
        case 20: _t->on_pb_history_clicked(); break;
        case 21: _t->updateStatsLabel(); break;
        case 22: { QPointF _r = _t->calculatePointOnCircle((*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSqlQueryModel* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_WARNING_POP
