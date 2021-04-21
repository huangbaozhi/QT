#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建百度识别类的对象
    //百度AI初始化
    //文字识别
    QString apiKey = "你的密钥";
    QString secretKey = "你的密码";
    mBaiOCR = new hbzbaiocr(apiKey,secretKey);
    connect(mBaiOCR,&hbzbaiocr::ocrResult,this,&MainWindow::on_OcrResult);

    //语音识别
    QString key="你的密钥";
    QString skey="你的密码";
    mBaiVop = new BaiVop(key,skey);//创建对象

    //摄像头获取
    camera = new QCamera(this);
    viewfinder = new QCameraViewfinder(this);
    imageCapture = new QCameraImageCapture(camera);
    ui->ImageView->addWidget(viewfinder);
    ui->image->setScaledContents(true);//图片自适应label大小
    camera->setViewfinder(viewfinder);
    camera->start();
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
    connect(ui->buttonCapture, SIGNAL(clicked()), this, SLOT(captureImage()));
    connect(imageCapture,&QCameraImageCapture::imageSaved,this,&MainWindow::imageSaved);

    //通过QLabel控件来显示日期时间
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);

    // 串口
    //获取电脑所有的串口列表
    QList<QSerialPortInfo> infos =
            QSerialPortInfo::availablePorts();
    //把所有的串口显示到下拉列表中
    foreach(QSerialPortInfo i,infos)
    {
        ui->comboBox->addItem(i.portName());
    }
    on_pushButton_6_clicked();

    //查看成绩
    mInfoDlg=new zhlParkingDialog(this);
    //链接信号和槽
    connect(this,&MainWindow::addInfo,
            mInfoDlg,&zhlParkingDialog::addInfoSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//查看记录
void MainWindow::on_pushButton_clicked()
{
    //发射增加信号
    emit addInfo(
                ui->textBrowser->toPlainText(),
                ui->label_2->text(),
                ui->label_3->text(),
                ui->label_4->text());
    //弹出子对话框

      mInfoDlg->exec();//模态对话框
}
//关闭红外识别
void MainWindow::on_pushButton_2_clicked()
{

  on_pushButton_7_clicked();
}

//启动语音识别
void MainWindow::on_pushButton_9_pressed()
{
    mBaiVop->Vop_start();
}
//语音识别
void MainWindow::on_pushButton_9_released()
{
    //松开发送语音数据，并获取识别结果
    QString text =mBaiVop->Vop_stop();
    int length=text.length();
   //显示识别结果到文本框
   //ui->textBrowser->setText(text);
   for(int i=0;i<length;i++)
   {
       if(text[i]=="开"&&text[i+1]=="门")
       {
           qDebug("开门");
       on_pushButton_4_clicked();
       }
       else if(text[i]=="关"&&text[i+1]=="门")
       {
           qDebug("关门");
           on_pushButton_5_clicked();
       }
   }
}


//退出系统
void MainWindow::on_pushButton_3_clicked()
{
    close();
}
//手动开门
void MainWindow::on_pushButton_4_clicked()
{
    //安全判断
    if(mMyPort==nullptr || !mMyPort->isOpen())
        return;
    //发送串口数据
    //1.获取发送数据，转换格式
    QByteArray a="B";
    //2.发送数据
    mMyPort->write(a);
    entryTime();//进入时间
    Speech();

}
//手动关门
void MainWindow::on_pushButton_5_clicked()
{

    //安全判断
    if(mMyPort==nullptr || !mMyPort->isOpen())
        return;
    //发送串口数据
    //1.获取发送数据，转换格式
    QByteArray a="C";
    //2.发送数据
    mMyPort->write(a);

    leaveTime();//离开时间

}

//相机部分
//摄像头截图
void MainWindow::captureImage()
{
    imageCapture->capture();
}
//显示摄像头截取图片
void MainWindow::displayImage(int, QImage image)
{
    ui->image->setPixmap(QPixmap::fromImage(image));//显示图片
    ui->statusbar->showMessage(tr("capture OK!"),5000);
}
//自动保存
void MainWindow::saveImage()
{
    //保存路径
    QString fileName = QApplication::applicationDirPath()
            +"/112/"
            +QDateTime::currentDateTime().toString("yyyymmdd-hhmmss.jpg");
    qDebug()<<"saved image name="<<fileName;
    if(fileName.isEmpty())
    {
        ui->statusbar->showMessage(tr("save cancel"),5000);
        return;
    }
    const QPixmap* pixmp = ui->image->pixmap();
    if(pixmp)
    {
        pixmp->save(fileName);
        ui->statusbar->showMessage(tr("save OK"),5000);
    }
}

void MainWindow::imageSaved(int id, const QString &fileName)
{
    qDebug()<<"MainWindow::imageSaved:"<<fileName;
    //处理保存之后的图片
    //1.显示到界面
    ui->image->setPixmap(QPixmap(fileName));
    //2.进行百度ai的识别
    mBaiOCR->recgLicensePlate(fileName);
}

//百度AI
//识别结果的槽函数
void MainWindow::on_OcrResult(hbzbaiocr::OCR_RET ret, hbzbaiocr::OCR_TYPE type)
{
    if(ret == hbzbaiocr::OCR_SUCCESS){

        switch (type) {
        case hbzbaiocr::OCR_LICENSE_PLATE:
            ui->textBrowser->setText(mBaiOCR->getLicensePlate()->toString());
            break;
        default:
            break;
        }
        QByteArray a="A";
        //2.发送数据
        mMyPort->write(a); //安全判断
        if(mMyPort==nullptr || !mMyPort->isOpen())
            return;
        //发送串口数据
        //1.获取发送数据，转换格式
        entryTime();//进入时间
        Speech();


    }else{
        //安全判断
        if(mMyPort==nullptr || !mMyPort->isOpen())
            return;
        //发送串口数据
        //1.获取发送数据，转换格式
        QByteArray a="0";
        //2.发送数据
        mMyPort->write(a);

        ui->textBrowser->setText("识别失败");
    }
}

//当前时间
void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("现在时间:yyyy-MM-dd hh:mm:ss  dddd");
    ui->dateTime->setText(str);
}
//进入时间
void MainWindow::entryTime()
{
//    ui->label->setText("欢迎光临");
    QDateTime time = QDateTime::currentDateTime();
    QString str2 = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->label_2->setText(str2);
}
//离开时间
void MainWindow::leaveTime()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str3 = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->label_3->setText(str3);
    payParking();//应缴费
}
//应缴费
void MainWindow::payParking()
{
    QString stime=ui->label_2->text();
    QDateTime starttime=QDateTime::fromString(stime,"yyyy-MM-dd hh:mm:ss");
    QString etime=ui->label_3->text();
    QDateTime endtime=QDateTime::fromString(etime,"yyyy-MM-dd hh:mm:ss");
    uint end=endtime.toTime_t();//将时间转为时间戳
    uint start=starttime.toTime_t();
    int second=(end-start)*2;
    QString ti=QString::number(second,10);
    ui->label_4->setText(ti);
}

//串口部分
//打开串口
void MainWindow::on_pushButton_6_clicked()
{
    //1.创建一个串口对象
    mMyPort = new QSerialPort(ui->comboBox->currentText());
    //设置参数
    mMyPort->setBaudRate(ui->comboBox_2->currentText().toInt());//.toInt()表示转成int类型
    //停止位
    mMyPort->setStopBits((QSerialPort::StopBits)ui->comboBox_3->currentText().toInt());
    //奇偶效验
    mMyPort->setParity(QSerialPort::Parity::NoParity);
    //打开串口
    if(mMyPort->open(QSerialPort::ReadWrite))
    {
        //打开成功
        qDebug("串口打开成功！");
        //绑定接收槽函数
        connect(mMyPort,&QSerialPort::readyRead,
                this,&MainWindow::recvSlot);
    }
    else
    {
        //打开失败
        qDebug("串口打开失败！");
    }
}
//关闭串口
void MainWindow::on_pushButton_7_clicked()
{
    if(mMyPort!=nullptr)
    {
        mMyPort->close();
        qDebug("串口关闭成功！");
    }
}
//串口发送
void MainWindow::on_pushButton_8_clicked()
{
    //安全判断
    if(mMyPort==nullptr || !mMyPort->isOpen())
        return;
    //发送串口数据
    //1.获取发送数据，转换格式
    QByteArray a=ui->textEdit->toPlainText().toUtf8();
    //2.发送数据
    mMyPort->write(a);
}
//读取串口数据
void MainWindow::recvSlot()
{
    //读取串口数据
    QByteArray byte_data = mMyPort->readAll();
    ui->textBrowser_2->append(byte_data);
    if(byte_data.contains("1"))
    {
    captureImage();
    qDebug()<<"获取1成功";
    }
    else if(byte_data.contains("2"))
    {

    qDebug()<<"获取2成功";
    }
    else qDebug()<<"获取失败";
}

//提示音
void MainWindow::Speech()
{
    //创建对象
    tts = new QTextToSpeech(this);
    License = new QTextToSpeech(this);
    if(tts->state()==QTextToSpeech::Ready&&License->state()==QTextToSpeech::Ready)
    {
        tts->say(ui->textEdit_2->toPlainText());
        License->say(ui->textBrowser->toPlainText());
    }
}
