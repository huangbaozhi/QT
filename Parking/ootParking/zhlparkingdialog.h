#ifndef ZHLPARKINGDIALOG_H
#define ZHLPARKINGDIALOG_H

#include <QDialog>
#include<QTableWidget>

namespace Ui {
class zhlParkingDialog;
}

class zhlParkingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit zhlParkingDialog(QWidget *parent = nullptr);
    ~zhlParkingDialog();

public slots:
    //定义槽函数
    //增加信息的槽函数
   void addInfoSlot(QString a0,
                    QString a1,
                    QString a2,
                    QString a3);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::zhlParkingDialog *ui;
};

#endif // ZHLPARKINGDIALOG_H
