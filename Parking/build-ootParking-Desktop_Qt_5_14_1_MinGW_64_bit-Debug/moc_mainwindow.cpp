/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ootParking/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[386];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "addInfo"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 42, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 66, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(6, 90, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(7, 114, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(8, 138, 12), // "captureImage"
QT_MOC_LITERAL(9, 151, 12), // "displayImage"
QT_MOC_LITERAL(10, 164, 9), // "saveImage"
QT_MOC_LITERAL(11, 174, 10), // "imageSaved"
QT_MOC_LITERAL(12, 185, 2), // "id"
QT_MOC_LITERAL(13, 188, 8), // "fileName"
QT_MOC_LITERAL(14, 197, 12), // "on_OcrResult"
QT_MOC_LITERAL(15, 210, 18), // "hbzbaiocr::OCR_RET"
QT_MOC_LITERAL(16, 229, 3), // "ret"
QT_MOC_LITERAL(17, 233, 19), // "hbzbaiocr::OCR_TYPE"
QT_MOC_LITERAL(18, 253, 8), // "mOcrType"
QT_MOC_LITERAL(19, 262, 11), // "timerUpdate"
QT_MOC_LITERAL(20, 274, 9), // "entryTime"
QT_MOC_LITERAL(21, 284, 9), // "leaveTime"
QT_MOC_LITERAL(22, 294, 10), // "payParking"
QT_MOC_LITERAL(23, 305, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(24, 329, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(25, 353, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(26, 377, 8) // "recvSlot"

    },
    "MainWindow\0addInfo\0\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_5_clicked\0"
    "captureImage\0displayImage\0saveImage\0"
    "imageSaved\0id\0fileName\0on_OcrResult\0"
    "hbzbaiocr::OCR_RET\0ret\0hbzbaiocr::OCR_TYPE\0"
    "mOcrType\0timerUpdate\0entryTime\0leaveTime\0"
    "payParking\0on_pushButton_6_clicked\0"
    "on_pushButton_7_clicked\0on_pushButton_8_clicked\0"
    "recvSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  118,    2, 0x08 /* Private */,
       4,    0,  119,    2, 0x08 /* Private */,
       5,    0,  120,    2, 0x08 /* Private */,
       6,    0,  121,    2, 0x08 /* Private */,
       7,    0,  122,    2, 0x08 /* Private */,
       8,    0,  123,    2, 0x08 /* Private */,
       9,    2,  124,    2, 0x08 /* Private */,
      10,    0,  129,    2, 0x08 /* Private */,
      11,    2,  130,    2, 0x08 /* Private */,
      14,    2,  135,    2, 0x08 /* Private */,
      19,    0,  140,    2, 0x08 /* Private */,
      20,    0,  141,    2, 0x08 /* Private */,
      21,    0,  142,    2, 0x08 /* Private */,
      22,    0,  143,    2, 0x08 /* Private */,
      23,    0,  144,    2, 0x08 /* Private */,
      24,    0,  145,    2, 0x08 /* Private */,
      25,    0,  146,    2, 0x08 /* Private */,
      26,    0,  147,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   12,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_pushButton_5_clicked(); break;
        case 6: _t->captureImage(); break;
        case 7: _t->displayImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 8: _t->saveImage(); break;
        case 9: _t->imageSaved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 10: _t->on_OcrResult((*reinterpret_cast< hbzbaiocr::OCR_RET(*)>(_a[1])),(*reinterpret_cast< hbzbaiocr::OCR_TYPE(*)>(_a[2]))); break;
        case 11: _t->timerUpdate(); break;
        case 12: _t->entryTime(); break;
        case 13: _t->leaveTime(); break;
        case 14: _t->payParking(); break;
        case 15: _t->on_pushButton_6_clicked(); break;
        case 16: _t->on_pushButton_7_clicked(); break;
        case 17: _t->on_pushButton_8_clicked(); break;
        case 18: _t->recvSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::addInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::addInfo(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
