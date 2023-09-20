/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pkg01/widget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWidgetENDCLASS = QtMocHelpers::stringData(
    "Widget",
    "Color",
    "",
    "color",
    "LeftLabels_Names",
    "text",
    "MidLabels_Names",
    "RightLabels_Names",
    "getValues",
    "QList<int>",
    "space_name",
    "value_id",
    "setColor",
    "a",
    "b",
    "c",
    "d",
    "slidersMoved",
    "spinsChanged",
    "setSpacesAndLabel",
    "setColorLabel",
    "setSpinBoxes",
    "valuesLeft",
    "valuesMid",
    "valuesRight",
    "setSliders",
    "setSpinsAndLabel",
    "RGB_To_XYZ",
    "XYZ_To_LAB",
    "XYZ_To_RGB",
    "LAB_To_XYZ"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {
    uint offsetsAndSizes[62];
    char stringdata0[7];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[17];
    char stringdata5[5];
    char stringdata6[16];
    char stringdata7[18];
    char stringdata8[10];
    char stringdata9[11];
    char stringdata10[11];
    char stringdata11[9];
    char stringdata12[9];
    char stringdata13[2];
    char stringdata14[2];
    char stringdata15[2];
    char stringdata16[2];
    char stringdata17[13];
    char stringdata18[13];
    char stringdata19[18];
    char stringdata20[14];
    char stringdata21[13];
    char stringdata22[11];
    char stringdata23[10];
    char stringdata24[12];
    char stringdata25[11];
    char stringdata26[17];
    char stringdata27[11];
    char stringdata28[11];
    char stringdata29[11];
    char stringdata30[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWidgetENDCLASS_t qt_meta_stringdata_CLASSWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Widget"
        QT_MOC_LITERAL(7, 5),  // "Color"
        QT_MOC_LITERAL(13, 0),  // ""
        QT_MOC_LITERAL(14, 5),  // "color"
        QT_MOC_LITERAL(20, 16),  // "LeftLabels_Names"
        QT_MOC_LITERAL(37, 4),  // "text"
        QT_MOC_LITERAL(42, 15),  // "MidLabels_Names"
        QT_MOC_LITERAL(58, 17),  // "RightLabels_Names"
        QT_MOC_LITERAL(76, 9),  // "getValues"
        QT_MOC_LITERAL(86, 10),  // "QList<int>"
        QT_MOC_LITERAL(97, 10),  // "space_name"
        QT_MOC_LITERAL(108, 8),  // "value_id"
        QT_MOC_LITERAL(117, 8),  // "setColor"
        QT_MOC_LITERAL(126, 1),  // "a"
        QT_MOC_LITERAL(128, 1),  // "b"
        QT_MOC_LITERAL(130, 1),  // "c"
        QT_MOC_LITERAL(132, 1),  // "d"
        QT_MOC_LITERAL(134, 12),  // "slidersMoved"
        QT_MOC_LITERAL(147, 12),  // "spinsChanged"
        QT_MOC_LITERAL(160, 17),  // "setSpacesAndLabel"
        QT_MOC_LITERAL(178, 13),  // "setColorLabel"
        QT_MOC_LITERAL(192, 12),  // "setSpinBoxes"
        QT_MOC_LITERAL(205, 10),  // "valuesLeft"
        QT_MOC_LITERAL(216, 9),  // "valuesMid"
        QT_MOC_LITERAL(226, 11),  // "valuesRight"
        QT_MOC_LITERAL(238, 10),  // "setSliders"
        QT_MOC_LITERAL(249, 16),  // "setSpinsAndLabel"
        QT_MOC_LITERAL(266, 10),  // "RGB_To_XYZ"
        QT_MOC_LITERAL(277, 10),  // "XYZ_To_LAB"
        QT_MOC_LITERAL(288, 10),  // "XYZ_To_RGB"
        QT_MOC_LITERAL(299, 10)   // "LAB_To_XYZ"
    },
    "Widget",
    "Color",
    "",
    "color",
    "LeftLabels_Names",
    "text",
    "MidLabels_Names",
    "RightLabels_Names",
    "getValues",
    "QList<int>",
    "space_name",
    "value_id",
    "setColor",
    "a",
    "b",
    "c",
    "d",
    "slidersMoved",
    "spinsChanged",
    "setSpacesAndLabel",
    "setColorLabel",
    "setSpinBoxes",
    "valuesLeft",
    "valuesMid",
    "valuesRight",
    "setSliders",
    "setSpinsAndLabel",
    "RGB_To_XYZ",
    "XYZ_To_LAB",
    "XYZ_To_RGB",
    "LAB_To_XYZ"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  122,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,  125,    2, 0x0a,    3 /* Public */,
       6,    1,  128,    2, 0x0a,    5 /* Public */,
       7,    1,  131,    2, 0x0a,    7 /* Public */,
       8,    1,  134,    2, 0x0a,    9 /* Public */,
      12,    5,  137,    2, 0x0a,   11 /* Public */,
      12,    4,  148,    2, 0x2a,   17 /* Public | MethodCloned */,
      17,    1,  157,    2, 0x0a,   22 /* Public */,
      18,    1,  160,    2, 0x0a,   24 /* Public */,
      19,    0,  163,    2, 0x0a,   26 /* Public */,
      20,    0,  164,    2, 0x0a,   27 /* Public */,
      21,    3,  165,    2, 0x0a,   28 /* Public */,
      25,    1,  172,    2, 0x0a,   32 /* Public */,
      26,    0,  175,    2, 0x0a,   34 /* Public */,
      27,    1,  176,    2, 0x0a,   35 /* Public */,
      28,    1,  179,    2, 0x0a,   37 /* Public */,
      29,    1,  182,    2, 0x0a,   39 /* Public */,
      30,    1,  185,    2, 0x0a,   41 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    0x80000000 | 9, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   13,   14,   15,   16,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   13,   14,   15,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9,   22,   23,   24,
    QMetaType::Void, 0x80000000 | 9,   22,
    QMetaType::Void,
    QMetaType::Double, QMetaType::Double,   13,
    QMetaType::Double, QMetaType::Double,   13,
    QMetaType::Double, QMetaType::Double,   13,
    QMetaType::Double, QMetaType::Double,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget, std::true_type>,
        // method 'Color'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QColor, std::false_type>,
        // method 'LeftLabels_Names'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'MidLabels_Names'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'RightLabels_Names'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getValues'
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        QtPrivate::TypeAndForceComplete<space_name, std::false_type>,
        // method 'setColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<space_name, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<space_name, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slidersMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'spinsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSpacesAndLabel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setColorLabel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setSpinBoxes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        // method 'setSliders'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        // method 'setSpinsAndLabel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RGB_To_XYZ'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'XYZ_To_LAB'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'XYZ_To_RGB'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'LAB_To_XYZ'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>
    >,
    nullptr
} };

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Color((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 1: _t->LeftLabels_Names((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->MidLabels_Names((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->RightLabels_Names((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: { QList<int> _r = _t->getValues((*reinterpret_cast< std::add_pointer_t<space_name>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setColor((*reinterpret_cast< std::add_pointer_t<space_name>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 6: _t->setColor((*reinterpret_cast< std::add_pointer_t<space_name>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 7: _t->slidersMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->spinsChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->setSpacesAndLabel(); break;
        case 10: _t->setColorLabel(); break;
        case 11: _t->setSpinBoxes((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[3]))); break;
        case 12: _t->setSliders((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 13: _t->setSpinsAndLabel(); break;
        case 14: { double _r = _t->RGB_To_XYZ((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 15: { double _r = _t->XYZ_To_LAB((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 16: { double _r = _t->XYZ_To_RGB((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 17: { double _r = _t->LAB_To_XYZ((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(QColor );
            if (_t _q_method = &Widget::Color; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Widget::Color(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
