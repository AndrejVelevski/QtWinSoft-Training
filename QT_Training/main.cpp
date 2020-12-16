#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QLinkedList>

#define qlog qDebug()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QLinkedList<int> list;

    for (int i=0;i<10;++i)
        list.append(i);

    for (int i : list)
        qlog << i;

    return 0;
}
