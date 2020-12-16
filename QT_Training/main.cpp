#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QList>

#define qlog qDebug()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QList<int> list;

    for (int i=0;i<10;++i)
        list.append(i);

    for (int n : list)
        qlog << n;

    return 0;
}
