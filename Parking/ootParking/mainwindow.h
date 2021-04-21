#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//文字识别
#include "hbzbaiocr.h"
#include "baivop.h"
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <string>
//摄像头部分
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QDebug>
#include <QPixmap>
//串口部分
#include <QSerialPort>
#include <QSerialPortInfo>//来获取外设
#include <QTextStream>
#include <QDebug>
//查看成绩
#include "zhlparkingdialog.h"
//显示时间
#include <QTimer>
#include <QMessageBox>
#include <QPainter>
#include <QTime>
#include <QApplication>
//文字转语音
#include <QTextToSpeech>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    //相机
    void captureImage();
    void displayImage(int,QImage);
    void saveImage();
    void imageSaved(int id,const QString &fileName);//槽函数
    //百度AI
    void on_OcrResult(hbzbaiocr::OCR_RET ret,hbzbaiocr::OCR_TYPE mOcrType);

    //时间
    void timerUpdate();//当前时间
    void entryTime();//进入时间
    void leaveTime();//离开时间
    void payParking();//缴费

    void Speech();//提示音

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void recvSlot();

    void on_pushButton_9_pressed();

    void on_pushButton_9_released();

signals:
    //增加停车信息记录
    void addInfo(QString,QString,QString,QString);


private:
    Ui::MainWindow *ui;

    hbzbaiocr * mBaiOCR;//百度AI
    QTextToSpeech *License;

    //照相截图
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;

    QTimer *timer;//定义时间
    QTextToSpeech *tts;//提示音

    QSerialPort* mMyPort;//串口
    zhlParkingDialog *mInfoDlg;//定义对话框成员变量

    //百度语音的指针成员变量
    BaiVop* mBaiVop;
};
#endif // MAINWINDOW_H
