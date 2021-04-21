/********************************************************************************
** Form generated from reading UI file 'zhlparkingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHLPARKINGDIALOG_H
#define UI_ZHLPARKINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_zhlParkingDialog
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *zhlParkingDialog)
    {
        if (zhlParkingDialog->objectName().isEmpty())
            zhlParkingDialog->setObjectName(QString::fromUtf8("zhlParkingDialog"));
        zhlParkingDialog->resize(787, 606);
        tableWidget = new QTableWidget(zhlParkingDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(50, 80, 661, 441));
        pushButton = new QPushButton(zhlParkingDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 550, 93, 28));
        pushButton_2 = new QPushButton(zhlParkingDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 540, 93, 28));
        label = new QLabel(zhlParkingDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 10, 191, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(20);
        label->setFont(font);

        retranslateUi(zhlParkingDialog);

        QMetaObject::connectSlotsByName(zhlParkingDialog);
    } // setupUi

    void retranslateUi(QDialog *zhlParkingDialog)
    {
        zhlParkingDialog->setWindowTitle(QCoreApplication::translate("zhlParkingDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("zhlParkingDialog", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("zhlParkingDialog", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("zhlParkingDialog", "\350\275\246\350\276\206\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zhlParkingDialog: public Ui_zhlParkingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHLPARKINGDIALOG_H
