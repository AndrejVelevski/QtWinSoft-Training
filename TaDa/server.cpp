#include "server.h"

void test();

Server::Server(QObject *parent) :
    QObject(parent),
    mDB(QSqlDatabase::addDatabase("QSQLITE"))
{
    qDebug() << "Starting server...";

    mDB.setDatabaseName("tada.db");

    if (mDB.open())
    {
        qDebug() << "Connection to SQL server successful";

        QSqlQuery query;
        QString str;

        str = "CREATE TABLE List ( \
                   id INTEGER, \
                   name TEXT, \
                   description TEXT, \
                   PRIMARY KEY(id) \
               );";

        if (!query.exec(str))
        {
            qDebug() << query.lastError().text();
        }

        str = "CREATE TABLE Task ( \
                   id INTEGER, \
                   name TEXT, \
                   completed INTEGER, \
                   PRIMARY KEY(id) \
               );";

        if (!query.exec(str))
        {
            qDebug() << query.lastError().text();
        }

        str = "CREATE TABLE ListTask ( \
                   list INTEGER, \
                   task INTEGER, \
                   FOREIGN KEY(task) REFERENCES Task(id), \
                   FOREIGN KEY(list) REFERENCES List(id) \
               );";

        if (!query.exec(str))
        {
            qDebug() << query.lastError().text();
        }

        test();
    }
    else
    {
        qDebug() << "Failed to connect to SQL server" << mDB.lastError().text();
    }
}

Server::~Server()
{
    mDB.close();
}

void test()
{
    QSqlQuery query;
    QString str;

    if (query.exec("SELECT * FROM List"))
    {
        while (query.next())
        {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            QString desc = query.value(2).toString();
            qDebug() << id << name << desc;
        }
    }
    else
    {
        qDebug() << "Failed to execute";
    }
}
