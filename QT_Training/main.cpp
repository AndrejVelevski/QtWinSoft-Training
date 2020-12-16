#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QDir>

#define qlog qDebug()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QDir dir("D:/");

    for(QFileInfo& q : dir.entryInfoList())
        qlog << q.absoluteFilePath();

    return a.exec();
}
