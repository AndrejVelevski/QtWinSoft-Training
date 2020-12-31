#include "server.h"

Server::Server(QObject *parent) :
    QObject(parent),
    mDB(QSqlDatabase::addDatabase("QSQLITE"))
{
    qDebug() << "Starting server...";

    mDB.setDatabaseName("tada.db");

    if (mDB.open())
    {
        qDebug() << "Connection to SQL server successful";

        exec("CREATE TABLE List ( \
                  id INTEGER, \
                  name TEXT NOT NULL, \
                  description TEXT NOT NULL, \
                  numTasks INTEGER NOT NULL DEFAULT 0, \
                  PRIMARY KEY(id) \
              );");

        exec("CREATE TABLE Task ( \
                  id INTEGER, \
                  list INTEGER NOT NULL, \
                  name TEXT NOT NULL, \
                  completed INTEGER NOT NULL, \
                  PRIMARY KEY(id), \
                  FOREIGN KEY(list) REFERENCES List(id) ON DELETE CASCADE\
              );");

        exec("CREATE TRIGGER CreateTask \
              AFTER INSERT ON Task \
              BEGIN \
                  UPDATE List \
                  SET numTasks = numTasks + 1 \
                  WHERE id = NEW.list; \
              END;");

        exec("CREATE TRIGGER DeleteTask \
              AFTER DELETE ON Task \
              BEGIN \
                  UPDATE List \
                  SET numTasks = numTasks - 1 \
                  WHERE id = OLD.list; \
              END;");
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

void Server::requestLists()
{
    QSqlQuery q = exec("SELECT * FROM List");
    QVariantList list;

    while (q.next())
    {
        int id = q.value(0).toInt();
        QString name = q.value(1).toString();
        QString description = q.value(2).toString();
        int numTasks = q.value(3).toInt();
        QVariantMap map;
        map.insert("id", id);
        map.insert("name", name);
        map.insert("description", description);
        map.insert("numTasks", numTasks);
        list.append(map);
    }

    emit getLists(list);
}

QSqlQuery Server::exec(const QString& query)
{
    QSqlQuery q;
    if (!q.exec(query))
        qDebug() << q.lastError().text();

    return q;
}
