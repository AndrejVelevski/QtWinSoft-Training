#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#define qlog qDebug()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QMap<QString, int> map;
    QHash<QString, int> hash;

    map.insert("Andrej", 23);
    map.insert("Maja", 20);
    map.insert("Jovan", 30);
    map.insert("Kosta", 14);

    hash.insert("Andrej", 23);
    hash.insert("Maja", 20);
    hash.insert("Jovan", 30);
    hash.insert("Kosta", 14);

    QMapIterator<QString, int> mapit(map);
    QHashIterator<QString, int> hashit(hash);

    while(mapit.hasNext())
    {
        mapit.next();
        qlog << mapit.key() << mapit.value();
    }

    qlog << map.contains("Ana");
    qlog << map["Andrej"];

    while(hashit.hasNext())
    {
        hashit.next();
        qlog << hashit.key() << hashit.value();
    }

    qlog << hash.contains("Ana");
    qlog << hash["Andrej"];

    return 0;
}
