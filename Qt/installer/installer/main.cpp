#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QObject>
#include <QAction>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
