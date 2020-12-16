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

    QMutableListIterator<int> it(list);

    while(it.hasNext())
    {
        int i = it.next();
        if (i > 4 && i < 8)
            it.remove();
    }

    it.toFront();

    while(it.hasNext())
        qlog << it.next();

    return 0;
}
