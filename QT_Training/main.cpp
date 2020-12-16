#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#define qlog qDebug()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QString str = "a,b,c,d,e,f,g";

    QStringList list = str.split(",");

    for(QString& s : list)
        qlog << s;

    QString newStr = list.join("--");

    qlog << newStr;

    return 0;
}
