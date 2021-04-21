#ifndef HBZBAIOCR_H
#define HBZBAIOCR_H

#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>//QNetworkAccessManager类用于协调网络操作
#include <QNetworkReply>//网络请求的结果与返回的数据就存放
#include <QByteArray>//字节数组
#include <QEventLoop>//事件循环
#include <QJsonObject>//用于封装JSON对象
#include <QJsonArray>
#include <QJsonDocument>//读取JSON文档

class hbzbaiocr : public QObject
{
    Q_OBJECT
public:
//    explicit hbzbaiocr(QObject *parent = nullptr);

    enum OCR_RET
    {
        OCR_SUCCESS,
        OCR_ERROR,
        OCR_ERROR_RECG,//识别错误
        OCR_ERROR_NOTHING,//没有要识别的信息
        OCR_ERROR_IMG,
        OCR_ERROR_PARAM,//参数错误
        OCR_ERROR_BUSY,//繁忙
        OCR_ERROR_COMMU,//通信错误
        OCR_ERROR_TIMEOUT,//执行超时
        OCR_ERROR_OTHER,//其余错误，
    };
    Q_ENUM(OCR_RET)

    //识别类型
    enum OCR_TYPE
    {
        OCR_LICENSE_PLATE,//车牌
    };
    Q_ENUM(OCR_TYPE)

    //车牌识别
    class LicensePlate
    {
    public:
        QString number;
        LicensePlate(){}
        QString toString()
        {
            QString str = "";
            str +=  number;//车牌号
            return str;
        }
        void clear()
        {
            number.clear();
        }
    };

    //构造函数
    hbzbaiocr();
    hbzbaiocr(QString apiKey, QString secretKey);

    //获取识别结果的函数
    LicensePlate* getLicensePlate() const;//车牌

private:
    QString bai_apiKey, bai_secretKey, bai_token;
    QNetworkAccessManager *manager;
    QNetworkReply *pReplay;
    QString  data[10];

    void Access_to_http(QString Url, QByteArray data);
    QString getBaiOCR_token(QString ApiKey, QString SecretKey);

    OCR_TYPE mOcrType;//识别类型
    LicensePlate mLicensePlate;//保存车牌结果

    //解析百度ai返回结果函数
    bool parseJsonLicensePlate(QJsonObject& subObj);//车牌识别

signals:
    void httpFinish(QByteArray);
    void ocrResult(OCR_RET ret,OCR_TYPE mOcrType);


public slots:
    bool recgLicensePlate(QString fpath);//车牌识别
    void recgImage(QString baiUrl, QString fpath);

private slots:
    void getHttpComReply(QNetworkReply *pReplay);
    void replyFinished(QNetworkReply *reply);
};

#endif // HBZBAIOCR_H



