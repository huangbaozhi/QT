#ifndef BAIVOP_H
#define BAIVOP_H

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>

#include <QEventLoop>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include <QAudioInput>
#include <QAudioDeviceInfo>
#include <QBuffer>

class BaiVop:public QObject
{
    Q_OBJECT
public:
    BaiVop();//并初始化麦克风
    BaiVop(QString, QString);//构造函数通过参数传入 apiKey、secretKey获得百度语音的 token， 并初始化麦克风

public slots:
    QString getBaiVop_token(QString , QString);//通过参数传入 apiKey、secretKey 返回 百度语音的 token
    QString getBaiVop_data(QByteArray , QString );//通过参数传入 音频数据、token 返回 百度语音的识别后的数据

    //开始麦克风录音
    void Vop_start();
    //停止录音，并且得到 语音识别后的数据，注意：该函数被调用之前，必须 BaiVop(QString, QString) 这个构造函数构造对象
    QString Vop_stop();
private slots:
    QJsonObject Assemble_Json(QByteArray, QString);
    void Access_to_http(QString , QByteArray );
    void getHttpComReply(QNetworkReply *);

signals:
    void finish(QByteArray);

private:

    QString bai_apiKey, bai_secretKey, bai_token;

    QNetworkAccessManager *manager;
    QNetworkReply *pReplay;

    QAudioDeviceInfo m_currentDevice;
    QAudioInput *m_audioInput;
    QBuffer *m_buffer;
};

#endif // BAIVOP_H
