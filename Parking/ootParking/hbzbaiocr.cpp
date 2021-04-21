#include "hbzbaiocr.h"

#include <QDebug>
#include <QFile>
#include <QUrlQuery>

hbzbaiocr::hbzbaiocr()
{

}

hbzbaiocr::hbzbaiocr(QString apiKey, QString secretKey):
    bai_apiKey(apiKey),
    bai_secretKey(secretKey)
{
    bai_token = getBaiOCR_token(bai_apiKey, bai_secretKey);
    qDebug()<<"Got Access Token: "<<bai_token;

    //新建QNetworkAccessManager对象
    manager = new QNetworkAccessManager;
    //QNetworkAccessManager有一个异步的API，当replyFinished槽被呼叫了后，它带有的参数是QNetworkReply对象包含下载的数据以及元数据
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

QString hbzbaiocr::getBaiOCR_token(QString ApiKey, QString SecretKey)
{
    //获取Access Token
    QString Url = "http://openapi.baidu.com/oauth/2.0/token?";//向服务器发送请求
    QByteArray append = QString("grant_type=client_credentials&client_id=%1&client_secret=%2&").arg(ApiKey).arg(SecretKey).toLatin1();//QString转QByteArray的方法，Latin1代表ASCII

    QByteArray target;//目标
    QEventLoop eventLoop;//事件循环

    Access_to_http(Url, append);//请求百度服务

    auto c1 = connect(this, httpFinish, [&](const QByteArray &data){
        target = data;
        eventLoop.exit(1);
    });
    eventLoop.exec();//事件循环等待finish信号的发生，得到数据
    disconnect(c1);//注销信号与槽

    //使用json解析百度语音识别服务器返回的token
    //将基于JSON文档的文本形式转换为QJsonDocument对象
    const auto &&data = QJsonDocument::fromJson(target).object();//object()可以将包含在文档中的数组，const修饰符，auto指定字符
    if(data.isEmpty() || !data.contains("access_token")) {
        return "error";
    }
    return data["access_token"].toString();
}

//获取识别结果
hbzbaiocr::LicensePlate* hbzbaiocr::getLicensePlate() const
{
    return (LicensePlate*)(&mLicensePlate);
}
//车牌识别
bool hbzbaiocr::recgLicensePlate(QString fpath)
{
    if(fpath.isNull() || fpath.isEmpty()){
        return false;
    }
    mOcrType = OCR_LICENSE_PLATE;
    recgImage("https://aip.baidubce.com/rest/2.0/ocr/v1/license_plate", fpath);
    return true;
}

void hbzbaiocr::recgImage(QString baiUrl, QString fpath)
{
    QFile file(fpath);
    if (!file.open(QIODevice::ReadOnly)||file.size()==0)//QIODevice::ReadOnly 以只读方式打开
    {
        file.close();
        qDebug()<<"Open file failed! imgPath="<<fpath;
        return ;
    }
    QByteArray fdata = file.readAll();
    file.close();

    //配置请求参数
    QUrlQuery params;//QUrlQuery解析URL中查询字符串
    params.addQueryItem("image", fdata.toBase64().toPercentEncoding());// Base64数字编码，toPercentEncoding()转换成正常的URL格式

    //post request
    QUrl url(baiUrl+"?access_token="+ bai_token);
    QNetworkRequest request(url);
    //设置数据提交格式，
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/x-www-form-urlencoded;charset=utf-8"));
    manager->post(request, params.toString().toUtf8());//获取Header
}

void hbzbaiocr::Access_to_http(QString Url, QByteArray data)
{
    // 构造请求
    QNetworkRequest request((QUrl(Url)));
    manager = new QNetworkAccessManager(this); //新建QNetworkAccessManager对象
    //设置头信息
    request.setHeader(QNetworkRequest::ContentTypeHeader, "Content-Type:application/json");
    // 发送请求
    manager->post(request, data);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getHttpComReply(QNetworkReply*)));
}

void hbzbaiocr::getHttpComReply(QNetworkReply *pReplay)
{
    // 获取响应信息
    QByteArray httpReplyData = pReplay->readAll();
    emit httpFinish(httpReplyData);
}


void hbzbaiocr::replyFinished(QNetworkReply *reply){

    //反馈数据解析
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();//属性
    if(200 != statusCode)
    {
        qDebug() << "BaiOCR::replyFinished: Status code is error:" << statusCode;
        emit ocrResult(OCR_ERROR_COMMU,mOcrType);
        return;
    }
    QByteArray replyData = reply->readAll();
    qDebug()<<"BaiOCR::replyFinished: reply data = \n"<<QString(replyData);

    QJsonParseError json_error;
    QJsonDocument document = QJsonDocument::fromJson(replyData, &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        //判断是否是对象,然后开始解析数据
        QJsonObject rootObj = document.object();
        //JSON数据格式
        if(rootObj.contains("words_result"))
        {
            QJsonObject subObj = rootObj.value("words_result").toObject();

            bool ret = false;
            switch (mOcrType) {
            case OCR_LICENSE_PLATE://车牌
                ret = parseJsonLicensePlate(subObj);
                break;
            default:
                break;
            }

            if(!ret){
                qDebug()<<"BaiOCR::replyFinished: unknown reply data.";
                emit ocrResult(OCR_ERROR_NOTHING,mOcrType);
            }

        }else{
            qDebug()<<"BaiOCR::replyFinished: error reply data.";
            if(rootObj.contains("error_code")){
                qDebug()<<"BaiOCR::replyFinished: error_code = "<<rootObj["error_code"].toInt();
                qDebug()<<"BaiOCR::replyFinished: error_msg = "<<rootObj["error_msg"].toString();
            }
            emit ocrResult(OCR_ERROR_RECG,mOcrType);
        }
    }else{
        qDebug()<<"BaiOCR::replyFinished: json parse error.";
        emit ocrResult(OCR_ERROR_RECG,mOcrType);

    }
    reply->deleteLater();
}

//车牌识别解析
bool hbzbaiocr::parseJsonLicensePlate(QJsonObject &subObj)
{
    mLicensePlate.clear();
    mLicensePlate.number=subObj["number"].toString();

    qDebug().noquote()<<mLicensePlate.toString();//noquote()解码

    emit ocrResult(OCR_SUCCESS, OCR_LICENSE_PLATE);

    return true;
}

