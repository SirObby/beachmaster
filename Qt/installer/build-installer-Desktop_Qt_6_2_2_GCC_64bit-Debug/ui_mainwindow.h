/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionExit;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Info;
    QWidget *Partition;
    QWidget *Bootloader;
    QWidget *User;
    QWidget *WindowManager;
    QWidget *AdditionalTools;
    QWidget *Done;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QLabel *label;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuInstaller;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 791, 561));
        Info = new QWidget();
        Info->setObjectName(QString::fromUtf8("Info"));
        tabWidget->addTab(Info, QString());
        Partition = new QWidget();
        Partition->setObjectName(QString::fromUtf8("Partition"));
        tabWidget->addTab(Partition, QString());
        Bootloader = new QWidget();
        Bootloader->setObjectName(QString::fromUtf8("Bootloader"));
        tabWidget->addTab(Bootloader, QString());
        User = new QWidget();
        User->setObjectName(QString::fromUtf8("User"));
        tabWidget->addTab(User, QString());
        WindowManager = new QWidget();
        WindowManager->setObjectName(QString::fromUtf8("WindowManager"));
        tabWidget->addTab(WindowManager, QString());
        AdditionalTools = new QWidget();
        AdditionalTools->setObjectName(QString::fromUtf8("AdditionalTools"));
        tabWidget->addTab(AdditionalTools, QString());
        Done = new QWidget();
        Done->setObjectName(QString::fromUtf8("Done"));
        pushButton = new QPushButton(Done);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 330, 80, 22));
        checkBox = new QCheckBox(Done);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(230, 310, 181, 20));
        checkBox_2 = new QCheckBox(Done);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(230, 230, 291, 20));
        checkBox_3 = new QCheckBox(Done);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(230, 210, 251, 20));
        checkBox_4 = new QCheckBox(Done);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(230, 190, 201, 20));
        checkBox_5 = new QCheckBox(Done);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(230, 170, 211, 20));
        checkBox_6 = new QCheckBox(Done);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(230, 150, 281, 20));
        label = new QLabel(Done);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 124, 281, 20));
        checkBox_7 = new QCheckBox(Done);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(230, 250, 291, 20));
        checkBox_8 = new QCheckBox(Done);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(230, 270, 341, 20));
        tabWidget->addTab(Done, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuInstaller = new QMenu(menubar);
        menuInstaller->setObjectName(QString::fromUtf8("menuInstaller"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuInstaller->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuInstaller->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Info), QCoreApplication::translate("MainWindow", "Info", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Partition), QCoreApplication::translate("MainWindow", "Partition", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Bootloader), QCoreApplication::translate("MainWindow", "Bootloader", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(User), QCoreApplication::translate("MainWindow", "User", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(WindowManager), QCoreApplication::translate("MainWindow", "Window Manager", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AdditionalTools), QCoreApplication::translate("MainWindow", "Additional Tools", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Install", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Know there is no going back.", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Made sure user settings are correct.", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Made sure bootloader settings are correct.", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "Made sure patitioning is correct.", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "Have double checked everything", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", "Want to install Beachmaster linux", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "I am sure I:", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "Made sure window manager settings are correct.", nullptr));
        checkBox_8->setText(QCoreApplication::translate("MainWindow", "Made sure the correct tools and applications will be installed.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Done), QCoreApplication::translate("MainWindow", "Done", nullptr));
        menuInstaller->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
