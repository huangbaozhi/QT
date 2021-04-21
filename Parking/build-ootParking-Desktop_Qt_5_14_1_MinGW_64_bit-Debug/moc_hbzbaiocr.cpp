/****************************************************************************
** Meta object code from reading C++ file 'hbzbaiocr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ootParking/hbzbaiocr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hbzbaiocr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hbzbaiocr_t {
    QByteArrayData data[32];
    char stringdata0[398];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hbzbaiocr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hbzbaiocr_t qt_meta_stringdata_hbzbaiocr = {
    {
QT_MOC_LITERAL(0, 0, 9), // "hbzbaiocr"
QT_MOC_LITERAL(1, 10, 10), // "httpFinish"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "ocrResult"
QT_MOC_LITERAL(4, 32, 7), // "OCR_RET"
QT_MOC_LITERAL(5, 40, 3), // "ret"
QT_MOC_LITERAL(6, 44, 8), // "OCR_TYPE"
QT_MOC_LITERAL(7, 53, 8), // "mOcrType"
QT_MOC_LITERAL(8, 62, 16), // "recgLicensePlate"
QT_MOC_LITERAL(9, 79, 5), // "fpath"
QT_MOC_LITERAL(10, 85, 9), // "recgImage"
QT_MOC_LITERAL(11, 95, 6), // "baiUrl"
QT_MOC_LITERAL(12, 102, 15), // "getHttpComReply"
QT_MOC_LITERAL(13, 118, 14), // "QNetworkReply*"
QT_MOC_LITERAL(14, 133, 7), // "pReplay"
QT_MOC_LITERAL(15, 141, 13), // "replyFinished"
QT_MOC_LITERAL(16, 155, 5), // "reply"
QT_MOC_LITERAL(17, 161, 11), // "OCR_SUCCESS"
QT_MOC_LITERAL(18, 173, 9), // "OCR_ERROR"
QT_MOC_LITERAL(19, 183, 14), // "OCR_ERROR_RECG"
QT_MOC_LITERAL(20, 198, 17), // "OCR_ERROR_NOTHING"
QT_MOC_LITERAL(21, 216, 13), // "OCR_ERROR_IMG"
QT_MOC_LITERAL(22, 230, 15), // "OCR_ERROR_PARAM"
QT_MOC_LITERAL(23, 246, 14), // "OCR_ERROR_BUSY"
QT_MOC_LITERAL(24, 261, 15), // "OCR_ERROR_COMMU"
QT_MOC_LITERAL(25, 277, 17), // "OCR_ERROR_TIMEOUT"
QT_MOC_LITERAL(26, 295, 15), // "OCR_ERROR_OTHER"
QT_MOC_LITERAL(27, 311, 16), // "OCR_UNKNOWN_TYPE"
QT_MOC_LITERAL(28, 328, 11), // "OCR_ID_CARD"
QT_MOC_LITERAL(29, 340, 19), // "OCR_VEHICLE_LICENSE"
QT_MOC_LITERAL(30, 360, 19), // "OCR_DRIVING_LICENSE"
QT_MOC_LITERAL(31, 380, 17) // "OCR_LICENSE_PLATE"

    },
    "hbzbaiocr\0httpFinish\0\0ocrResult\0OCR_RET\0"
    "ret\0OCR_TYPE\0mOcrType\0recgLicensePlate\0"
    "fpath\0recgImage\0baiUrl\0getHttpComReply\0"
    "QNetworkReply*\0pReplay\0replyFinished\0"
    "reply\0OCR_SUCCESS\0OCR_ERROR\0OCR_ERROR_RECG\0"
    "OCR_ERROR_NOTHING\0OCR_ERROR_IMG\0"
    "OCR_ERROR_PARAM\0OCR_ERROR_BUSY\0"
    "OCR_ERROR_COMMU\0OCR_ERROR_TIMEOUT\0"
    "OCR_ERROR_OTHER\0OCR_UNKNOWN_TYPE\0"
    "OCR_ID_CARD\0OCR_VEHICLE_LICENSE\0"
    "OCR_DRIVING_LICENSE\0OCR_LICENSE_PLATE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hbzbaiocr[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       2,   66, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    2,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   52,    2, 0x0a /* Public */,
      10,    2,   55,    2, 0x0a /* Public */,
      12,    1,   60,    2, 0x08 /* Private */,
      15,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,    9,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   16,

 // enums: name, alias, flags, count, data
       4,    4, 0x0,   10,   76,
       6,    6, 0x0,    5,   96,

 // enum data: key, value
      17, uint(hbzbaiocr::OCR_SUCCESS),
      18, uint(hbzbaiocr::OCR_ERROR),
      19, uint(hbzbaiocr::OCR_ERROR_RECG),
      20, uint(hbzbaiocr::OCR_ERROR_NOTHING),
      21, uint(hbzbaiocr::OCR_ERROR_IMG),
      22, uint(hbzbaiocr::OCR_ERROR_PARAM),
      23, uint(hbzbaiocr::OCR_ERROR_BUSY),
      24, uint(hbzbaiocr::OCR_ERROR_COMMU),
      25, uint(hbzbaiocr::OCR_ERROR_TIMEOUT),
      26, uint(hbzbaiocr::OCR_ERROR_OTHER),
      27, uint(hbzbaiocr::OCR_UNKNOWN_TYPE),
      28, uint(hbzbaiocr::OCR_ID_CARD),
      29, uint(hbzbaiocr::OCR_VEHICLE_LICENSE),
      30, uint(hbzbaiocr::OCR_DRIVING_LICENSE),
      31, uint(hbzbaiocr::OCR_LICENSE_PLATE),

       0        // eod
};

void hbzbaiocr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<hbzbaiocr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->httpFinish((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->ocrResult((*reinterpret_cast< OCR_RET(*)>(_a[1])),(*reinterpret_cast< OCR_TYPE(*)>(_a[2]))); break;
        case 2: { bool _r = _t->recgLicensePlate((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->recgImage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->getHttpComReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hbzbaiocr::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hbzbaiocr::httpFinish)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (hbzbaiocr::*)(OCR_RET , OCR_TYPE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hbzbaiocr::ocrResult)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hbzbaiocr::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_hbzbaiocr.data,
    qt_meta_data_hbzbaiocr,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *hbzbaiocr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hbzbaiocr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hbzbaiocr.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int hbzbaiocr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void hbzbaiocr::httpFinish(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void hbzbaiocr::ocrResult(OCR_RET _t1, OCR_TYPE _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
