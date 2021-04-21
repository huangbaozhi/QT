/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *ImageView;
    QPushButton *buttonCapture;
    QLabel *image;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *dateTime;
    QTextBrowser *textBrowser;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *tab2;
    QTextBrowser *textBrowser_2;
    QTextEdit *textEdit;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1039, 717);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 80, 181, 121));
        ImageView = new QHBoxLayout(horizontalLayoutWidget);
        ImageView->setObjectName(QString::fromUtf8("ImageView"));
        ImageView->setContentsMargins(0, 0, 0, 0);
        buttonCapture = new QPushButton(centralwidget);
        buttonCapture->setObjectName(QString::fromUtf8("buttonCapture"));
        buttonCapture->setGeometry(QRect(70, 30, 93, 28));
        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(50, 250, 161, 121));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(280, 0, 731, 671));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        dateTime = new QLabel(tab);
        dateTime->setObjectName(QString::fromUtf8("dateTime"));
        dateTime->setGeometry(QRect(120, 50, 381, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(20);
        dateTime->setFont(font);
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(115, 180, 321, 91));
        textBrowser->setFont(font);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 290, 221, 61));
        label->setFont(font);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 360, 251, 61));
        label_2->setFont(font);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 450, 231, 71));
        label_3->setFont(font);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 530, 231, 81));
        label_4->setFont(font);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(540, 60, 111, 61));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(540, 190, 121, 61));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(540, 380, 111, 61));
        tabWidget->addTab(tab, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        textBrowser_2 = new QTextBrowser(tab2);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(40, 30, 256, 192));
        textEdit = new QTextEdit(tab2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(40, 280, 251, 201));
        comboBox = new QComboBox(tab2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(420, 40, 87, 22));
        comboBox_2 = new QComboBox(tab2);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(420, 90, 87, 22));
        comboBox_3 = new QComboBox(tab2);
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(420, 140, 87, 22));
        comboBox_4 = new QComboBox(tab2);
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(420, 190, 87, 22));
        comboBox_5 = new QComboBox(tab2);
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(420, 250, 87, 22));
        label_5 = new QLabel(tab2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(340, 40, 68, 15));
        label_6 = new QLabel(tab2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(340, 90, 68, 15));
        label_7 = new QLabel(tab2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(340, 140, 68, 15));
        label_8 = new QLabel(tab2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(340, 190, 68, 15));
        label_9 = new QLabel(tab2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(340, 250, 68, 15));
        pushButton_6 = new QPushButton(tab2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(420, 300, 93, 28));
        pushButton_7 = new QPushButton(tab2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(420, 350, 93, 28));
        pushButton_8 = new QPushButton(tab2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(330, 450, 93, 28));
        tabWidget->addTab(tab2, QString());
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 490, 93, 28));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(150, 490, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1039, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonCapture->setText(QCoreApplication::translate("MainWindow", "Capture", nullptr));
        image->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        dateTime->setText(QCoreApplication::translate("MainWindow", "          \347\216\260\345\234\250\346\227\266\351\227\264", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\205\245\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\246\273\345\274\200\346\227\266\351\227\264", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\274\264\350\264\271", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\350\256\260\345\275\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\350\257\206\345\210\253", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\347\225\214\351\235\242", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "115200", nullptr));

        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));

        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\351\200\211\344\270\262\345\217\243", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\345\274\200\351\227\250", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
