#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QObject>
#include <QAction>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::exit);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exit()
{
    QCoreApplication::quit();
}

void MainWindow::about()
{
    QMessageBox msgBox;
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText("Beachmaster Installer Window.<br /><a href=\"https://github.com/SirObby/beachmaster\">GitHub</a>");
    msgBox.exec();

}
