/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
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
        "on_pushButton_clicked",
        "",
        "onLoginClicked",
        "on_btnGestionClients_PageStock_clicked",
        "on_btnGestionEmployes_PageStock_clicked",
        "on_btnBack_PageStock_clicked",
        "on_btnGestionStock_PageClients_clicked",
        "on_btnGestionEmployes_PageClients_clicked",
        "on_btnBack_PageClients_clicked",
        "on_btnGestionStock_Page_Employes_clicked",
        "on_btnGestionClients_Page_Employes_clicked",
        "on_btnBack_Page_Employes_clicked",
        "on_btnGestionSponsors_PageStock_clicked",
        "on_btnGestionFournisseurs_PageStock_clicked",
        "on_btnGestionSponsors_PageClients_clicked",
        "on_btnGestionFournisseurs_PageClients_clicked",
        "on_btnGestionSponsors_Page_Employes_clicked",
        "on_btnGestionFournisseurs_Page_Employes_clicked",
        "on_btnGestionStock_Page_Sponsors_clicked",
        "on_btnGestionClients_Page_Sponsors_clicked",
        "on_btnGestionEmployes_Page_Sponsors_clicked",
        "on_btnGestionFournisseurs_Page_Sponsors_clicked",
        "on_btnBack_Page_Sponsors_clicked",
        "on_btnGestionStock_Page_Fournisseurs_clicked",
        "on_btnGestionClients_Page_Fournisseurs_clicked",
        "on_btnGestionEmployes_PageFournisseurs_clicked",
        "on_btnGestionSponsors_Page_Fournisseurs_clicked",
        "on_btnBack_Page_Fournisseurs_clicked",
        "on_tableWidget_itemClicked",
        "QTableWidgetItem*",
        "item",
        "on_btnAjouter_clicked",
        "on_btnModifier_clicked",
        "on_btnSupprimer_clicked",
        "afficherProduits",
        "viderChamps",
        "chargerFournisseurs",
        "on_btnAjouterEmploye_clicked",
        "on_btnModifierEmploye_clicked",
        "on_btnSupprimerEmploye_clicked",
        "on_tableWidgetEmployes_itemClicked",
        "afficherEmployes",
        "viderChampsEmploye",
        "on_btnAjouterFournisseur_clicked",
        "on_btnModifierFournisseur_clicked",
        "on_btnSupprimerFournisseur_clicked",
        "on_btnRechercherFournisseur_clicked",
        "on_btnTrierFournisseur_clicked",
        "on_btnStatFournisseur_clicked",
        "on_btnExportPdfFournisseur_clicked",
        "on_btnCallFournisseur_clicked",
        "on_btnAIAgent_clicked",
        "on_btnAdvancedFeatures_clicked",
        "afficherFournisseurs",
        "viderChampsFournisseur",
        "on_pb_supprimer_clicked",
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
        // Slot 'on_pushButton_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onLoginClicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionClients_PageStock_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionEmployes_PageStock_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnBack_PageStock_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionStock_PageClients_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionEmployes_PageClients_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnBack_PageClients_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionStock_Page_Employes_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionClients_Page_Employes_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnBack_Page_Employes_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionSponsors_PageStock_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionFournisseurs_PageStock_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionSponsors_PageClients_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionFournisseurs_PageClients_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionSponsors_Page_Employes_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionFournisseurs_Page_Employes_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionStock_Page_Sponsors_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionClients_Page_Sponsors_clicked'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionEmployes_Page_Sponsors_clicked'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionFournisseurs_Page_Sponsors_clicked'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnBack_Page_Sponsors_clicked'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionStock_Page_Fournisseurs_clicked'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionClients_Page_Fournisseurs_clicked'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionEmployes_PageFournisseurs_clicked'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnGestionSponsors_Page_Fournisseurs_clicked'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnBack_Page_Fournisseurs_clicked'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_tableWidget_itemClicked'
        QtMocHelpers::SlotData<void(QTableWidgetItem *)>(29, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 30, 31 },
        }}),
        // Slot 'on_btnAjouter_clicked'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnModifier_clicked'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSupprimer_clicked'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'afficherProduits'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'viderChamps'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'chargerFournisseurs'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAjouterEmploye_clicked'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnModifierEmploye_clicked'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSupprimerEmploye_clicked'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_tableWidgetEmployes_itemClicked'
        QtMocHelpers::SlotData<void(QTableWidgetItem *)>(41, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 30, 31 },
        }}),
        // Slot 'afficherEmployes'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'viderChampsEmploye'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAjouterFournisseur_clicked'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnModifierFournisseur_clicked'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSupprimerFournisseur_clicked'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnRechercherFournisseur_clicked'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnTrierFournisseur_clicked'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnStatFournisseur_clicked'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnExportPdfFournisseur_clicked'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnCallFournisseur_clicked'
        QtMocHelpers::SlotData<void()>(51, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAIAgent_clicked'
        QtMocHelpers::SlotData<void()>(52, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAdvancedFeatures_clicked'
        QtMocHelpers::SlotData<void()>(53, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'afficherFournisseurs'
        QtMocHelpers::SlotData<void()>(54, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'viderChampsFournisseur'
        QtMocHelpers::SlotData<void()>(55, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_supprimer_clicked'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_modifier_2_clicked'
        QtMocHelpers::SlotData<void()>(57, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_ajouter_clicked'
        QtMocHelpers::SlotData<void()>(58, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'handleMessageBoxResult'
        QtMocHelpers::SlotData<void(int)>(59, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 60 },
        }}),
        // Slot 'refreshTable'
        QtMocHelpers::SlotData<void()>(61, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_tab_clients_clicked'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(62, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 63, 64 },
        }}),
        // Slot 'refreshTable'
        QtMocHelpers::SlotData<void(QSqlQueryModel *)>(61, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 65, 66 },
        }}),
        // Slot 'on_refrech_pb_clicked'
        QtMocHelpers::SlotData<void()>(67, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_Imprimer_clicked'
        QtMocHelpers::SlotData<void()>(68, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_pdf_clicked'
        QtMocHelpers::SlotData<void()>(69, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_word_clicked'
        QtMocHelpers::SlotData<void()>(70, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_lineEdit_textChanged'
        QtMocHelpers::SlotData<void(const QString &)>(71, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 72 },
        }}),
        // Slot 'on_tableWidget_c_cellClicked'
        QtMocHelpers::SlotData<void(int, int)>(73, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 74 }, { QMetaType::Int, 75 },
        }}),
        // Slot 'on_comboBox_tri_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(76, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 64 },
        }}),
        // Slot 'on_search_textChanged'
        QtMocHelpers::SlotData<void(const QString &)>(77, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 78 },
        }}),
        // Slot 'on_stats_clicked'
        QtMocHelpers::SlotData<void()>(79, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'envoyerSMS'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(80, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 81 }, { QMetaType::QString, 82 },
        }}),
        // Slot 'onSMSReply'
        QtMocHelpers::SlotData<void(QNetworkReply *)>(83, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 84, 85 },
        }}),
        // Slot 'on_pushButton_envoyerSMS_clicked'
        QtMocHelpers::SlotData<void()>(86, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pb_history_clicked'
        QtMocHelpers::SlotData<void()>(87, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateStatsLabel'
        QtMocHelpers::SlotData<void()>(88, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculatePointOnCircle'
        QtMocHelpers::SlotData<QPointF(QPointF, double, double)>(89, 2, QMC::AccessPrivate, 0x80000000 | 90, {{
            { 0x80000000 | 90, 91 }, { QMetaType::Double, 92 }, { QMetaType::Double, 93 },
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
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
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
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->onLoginClicked(); break;
        case 2: _t->on_btnGestionClients_PageStock_clicked(); break;
        case 3: _t->on_btnGestionEmployes_PageStock_clicked(); break;
        case 4: _t->on_btnBack_PageStock_clicked(); break;
        case 5: _t->on_btnGestionStock_PageClients_clicked(); break;
        case 6: _t->on_btnGestionEmployes_PageClients_clicked(); break;
        case 7: _t->on_btnBack_PageClients_clicked(); break;
        case 8: _t->on_btnGestionStock_Page_Employes_clicked(); break;
        case 9: _t->on_btnGestionClients_Page_Employes_clicked(); break;
        case 10: _t->on_btnBack_Page_Employes_clicked(); break;
        case 11: _t->on_btnGestionSponsors_PageStock_clicked(); break;
        case 12: _t->on_btnGestionFournisseurs_PageStock_clicked(); break;
        case 13: _t->on_btnGestionSponsors_PageClients_clicked(); break;
        case 14: _t->on_btnGestionFournisseurs_PageClients_clicked(); break;
        case 15: _t->on_btnGestionSponsors_Page_Employes_clicked(); break;
        case 16: _t->on_btnGestionFournisseurs_Page_Employes_clicked(); break;
        case 17: _t->on_btnGestionStock_Page_Sponsors_clicked(); break;
        case 18: _t->on_btnGestionClients_Page_Sponsors_clicked(); break;
        case 19: _t->on_btnGestionEmployes_Page_Sponsors_clicked(); break;
        case 20: _t->on_btnGestionFournisseurs_Page_Sponsors_clicked(); break;
        case 21: _t->on_btnBack_Page_Sponsors_clicked(); break;
        case 22: _t->on_btnGestionStock_Page_Fournisseurs_clicked(); break;
        case 23: _t->on_btnGestionClients_Page_Fournisseurs_clicked(); break;
        case 24: _t->on_btnGestionEmployes_PageFournisseurs_clicked(); break;
        case 25: _t->on_btnGestionSponsors_Page_Fournisseurs_clicked(); break;
        case 26: _t->on_btnBack_Page_Fournisseurs_clicked(); break;
        case 27: _t->on_tableWidget_itemClicked((*reinterpret_cast<std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 28: _t->on_btnAjouter_clicked(); break;
        case 29: _t->on_btnModifier_clicked(); break;
        case 30: _t->on_btnSupprimer_clicked(); break;
        case 31: _t->afficherProduits(); break;
        case 32: _t->viderChamps(); break;
        case 33: _t->chargerFournisseurs(); break;
        case 34: _t->on_btnAjouterEmploye_clicked(); break;
        case 35: _t->on_btnModifierEmploye_clicked(); break;
        case 36: _t->on_btnSupprimerEmploye_clicked(); break;
        case 37: _t->on_tableWidgetEmployes_itemClicked((*reinterpret_cast<std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 38: _t->afficherEmployes(); break;
        case 39: _t->viderChampsEmploye(); break;
        case 40: _t->on_btnAjouterFournisseur_clicked(); break;
        case 41: _t->on_btnModifierFournisseur_clicked(); break;
        case 42: _t->on_btnSupprimerFournisseur_clicked(); break;
        case 43: _t->on_btnRechercherFournisseur_clicked(); break;
        case 44: _t->on_btnTrierFournisseur_clicked(); break;
        case 45: _t->on_btnStatFournisseur_clicked(); break;
        case 46: _t->on_btnExportPdfFournisseur_clicked(); break;
        case 47: _t->on_btnCallFournisseur_clicked(); break;
        case 48: _t->on_btnAIAgent_clicked(); break;
        case 49: _t->on_btnAdvancedFeatures_clicked(); break;
        case 50: _t->afficherFournisseurs(); break;
        case 51: _t->viderChampsFournisseur(); break;
        case 52: _t->on_pb_supprimer_clicked(); break;
        case 53: _t->on_pb_modifier_2_clicked(); break;
        case 54: _t->on_pb_ajouter_clicked(); break;
        case 55: _t->handleMessageBoxResult((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 56: _t->refreshTable(); break;
        case 57: _t->on_tab_clients_clicked((*reinterpret_cast<std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 58: _t->refreshTable((*reinterpret_cast<std::add_pointer_t<QSqlQueryModel*>>(_a[1]))); break;
        case 59: _t->on_refrech_pb_clicked(); break;
        case 60: _t->on_Imprimer_clicked(); break;
        case 61: _t->on_pb_pdf_clicked(); break;
        case 62: _t->on_pb_word_clicked(); break;
        case 63: _t->on_lineEdit_textChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 64: _t->on_tableWidget_c_cellClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 65: _t->on_comboBox_tri_currentIndexChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 66: _t->on_search_textChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 67: _t->on_stats_clicked(); break;
        case 68: _t->envoyerSMS((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 69: _t->onSMSReply((*reinterpret_cast<std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 70: _t->on_pushButton_envoyerSMS_clicked(); break;
        case 71: _t->on_pb_history_clicked(); break;
        case 72: _t->updateStatsLabel(); break;
        case 73: { QPointF _r = _t->calculatePointOnCircle((*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 58:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSqlQueryModel* >(); break;
            }
            break;
        case 69:
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
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 74)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 74;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 74)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 74;
    }
    return _id;
}
QT_WARNING_POP
