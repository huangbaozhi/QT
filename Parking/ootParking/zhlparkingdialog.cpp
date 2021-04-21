#include "zhlparkingdialog.h"
#include "ui_zhlparkingdialog.h"

zhlParkingDialog::zhlParkingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zhlParkingDialog)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);
    QTableWidgetItem *item = new QTableWidgetItem("车牌号");
    ui->tableWidget->setHorizontalHeaderItem(0,item);
    item=new QTableWidgetItem("进入时间");
    ui->tableWidget->setHorizontalHeaderItem(1,item);
    item=new QTableWidgetItem("离开时间");
    ui->tableWidget->setHorizontalHeaderItem(2,item);
    item=new QTableWidgetItem("应缴费");
    ui->tableWidget->setHorizontalHeaderItem(3,item);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));//导出的槽链接
}

zhlParkingDialog::~zhlParkingDialog()
{
    delete ui;
}

#include<QTableWidget>
void zhlParkingDialog::addInfoSlot(QString a0, QString a1, QString a2, QString a3)
{
    //把接受到的信息，显示到表格中
    //1.建立各个单元格
    QTableWidgetItem *i0=new QTableWidgetItem(a0);
    QTableWidgetItem *i1=new QTableWidgetItem(a1);
    QTableWidgetItem *i2=new QTableWidgetItem(a2);
    QTableWidgetItem *i3=new QTableWidgetItem(a3);
    //2.在表格中增加一行
    ui->tableWidget->insertRow(0);
    //3.在新增行中，添加单元格
    ui->tableWidget->setItem(0,0,i0);
    ui->tableWidget->setItem(0,1,i1);
    ui->tableWidget->setItem(0,2,i2);
    ui->tableWidget->setItem(0,3,i3);
}

//导出数据
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
#include<QDesktopServices>
//将数据导入excel文件
void zhlParkingDialog::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),"",tr("file (*.csv)"));
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        bool ret =file.open(QIODevice::Truncate|QIODevice::WriteOnly);
        if(!ret)
            return;
        QTextStream stream(&file);
        QString conTents;
        QHeaderView *header=ui->tableWidget->horizontalHeader();
        if(header)
        {
            for(int i=0;i<header->count();i++)
            {
                QTableWidgetItem *item=ui->tableWidget->horizontalHeaderItem(i);
                if(!item)
                {
                    continue;
                }
                conTents +=item->text()+",";
            }
            conTents +="\n";
        }
        for (int i=0;i<ui->tableWidget->rowCount();i++)
        {
            for (int j=0;j<ui->tableWidget->columnCount();j++)
            {
               QTableWidgetItem *item=ui->tableWidget->item(i,j);
               if(!item)
                   continue;
               QString str=item->text();
               str.replace(",","");
               conTents +=str + ",";
            }
           conTents +="\n";
        }
        stream << conTents;
        file.close();

    } //自动打开文件
    if(QMessageBox::Yes == QMessageBox::information(0,QObject::tr("文件导出"),QString("文件导出成功，是否打开文件？"),QMessageBox::Yes,QMessageBox::No))
    {
        QDesktopServices::openUrl(QUrl("file:///"+QDir::toNativeSeparators(fileName)));
    }
    else
    {
        QMessageBox::warning(NULL,"错误","未能创建Excel对象，请安装Microsoft Excel。",QMessageBox::Apply);

    }
}
//返回
void zhlParkingDialog::on_pushButton_2_clicked()
{
    close();
}
