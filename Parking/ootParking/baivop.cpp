//#include "baivop.h"

//BaiVop::BaiVop(QObject *parent) : QObject(parent)
//{

//}


#include "baivop.h"
#include <QDebug>

BaiVop::BaiVop()
{

}
BaiVop::BaiVop(QString apiKey, QString secretKey):
    bai_apiKey(apiKey),
    bai_secretKey(secretKey)
{
    bai_token = getBaiVop_token(bai_apiKey, bai_secretKey);
    qDebug()<<"Got Access Token: "<<bai_token;
    //获取输入设备
    const auto &availableDevices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    if(!availableDevices.isEmpty())
    {
        m_currentDevice = availableDevices.first();

        QAudioFormat format;
        format.setSampleRate(16000);//设置声音的采样频率
        format.setChannelCount(1);//设置声音的声道
        format.setSampleSize(16);//16位深
        format.setSampleType(QAudioFormat::SignedInt);
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setCodec("audio/pcm");

        m_audioInput = new QAudioInput(m_currentDevice, format, this);
    }
}

QString BaiVop::getBaiVop_token(QString ApiKey, QString SecretKey)
{
    QString Url = "http://openapi.baidu.com/oauth/2.0/token?";
    QByteArray append = QString("grant_type=client_credentials&client_id=%1&client_secret=%2&").arg(ApiKey).arg(SecretKey).toLatin1();

    QByteArray target;
    QEventLoop eventLoop;

    Access_to_http(Url, append);//请求百度语音识别服务

    auto c1 = connect(this, &BaiVop::finish, [&](const QByteArray &data){
        target = data;
        eventLoop.exit(1);
    });
    eventLoop.exec();//事件循环等待finish信号的发生，得到数据
    disconnect(c1);//注销信号与曹

    const auto &&data = QJsonDocument::fromJson(target).object(); //使用json解析百度语音识别服务器返回的token
    if(data.isEmpty() || !data.contains("access_token")) {
        return "error";
    }
    return data["access_token"].toString();
}

QString BaiVop::getBaiVop_data(QByteArray speech, QString m_token)
{
    QString Url = "http://vop.baidu.com/server_api";
    QJsonObject JsonData = Assemble_Json(speech, m_token);

    Access_to_http(Url, QJsonDocument(JsonData).toJson());

    QByteArray target;
    QEventLoop eventLoop;
    auto c1 = connect(this, &BaiVop::finish, [&](const QByteArray &data)
    {
        target = data;
        eventLoop.exit(1);
    });
    eventLoop.exec();
    disconnect(c1);

    QJsonObject jsonData = QJsonDocument::fromJson(target).object();
    if(target.isEmpty() || jsonData.isEmpty()|| !jsonData.contains("result")){
        return "请重说";
    }
    const auto &&message = jsonData["result"].toArray()[0].toString();

    return message.mid(0, message.size()-1);
}

QJsonObject BaiVop::Assemble_Json(QByteArray speech, QString m_token)
{
    QJsonObject json;
    json.insert("format", "pcm");
    json.insert("rate", "16000");
    json.insert("channel", "1");
    json.insert("cuid", "baidu_workshop");
    json.insert("token", m_token);
    json.insert("dev_pid", "1537");//普通话
    json.insert("dev_pid", "1637");//粤语
    json.insert("dev_pid", "1737");//英语
    json.insert("dev_pid", "1837");//四川话
    json.insert("speech", QString(speech.toBase64()));
    json.insert("len", speech.size());

    return json;
}


void BaiVop::Access_to_http(QString Url, QByteArray data)
{
    // 构造请求
    QNetworkRequest request((QUrl(Url)));
    manager = new QNetworkAccessManager(this);
    //设置头信息
    request.setHeader(QNetworkRequest::ContentTypeHeader, "Content-Type:application/json");
    // 发送请求
    manager->post(request, data);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getHttpComReply(QNetworkReply*)));
}

void BaiVop::getHttpComReply(QNetworkReply *pReplay)
{
    // 获取响应信息
    QByteArray httpReplyData = pReplay->readAll();
    emit finish(httpReplyData);
}


void BaiVop::Vop_start()
{
    m_buffer = new QBuffer;
    m_buffer->open(QIODevice::ReadWrite);
    m_audioInput->start(m_buffer);
}
QString BaiVop::Vop_stop()
{
    m_audioInput->stop();
    const auto &sendData = m_buffer->data();
    m_buffer->deleteLater();
    if (bai_token == "error")
        qDebug() << " token error" << endl;
//    qDebug() << bai_vop.getBaiVop_data(sendData, bai_token) << endl;
    return getBaiVop_data(sendData, bai_token);
}
