#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#define qlog qDebug()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QMultiMap<QString, int> map;

    map.insert("Andrej", 23);
    map.insert("Maja", 20);
    map.insert("Jovan", 30);
    map.insert("Kosta", 14);
    map.insert("Andrej", 20);

    QMultiMapIterator<QString, int> it(map);

    while(it.hasNext())
    {
        it.next();
        qlog << it.key() << it.value();
    }

    qlog << map.contains("Ana");
    qlog << map.find("Andrej").value();

    return 0;
}
