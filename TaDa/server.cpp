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
                  description TEXT NOT NULL DEFAULT \"\", \
                  numTasks INTEGER NOT NULL DEFAULT 0, \
                  numCompletedTasks INTEGER NOT NULL DEFAULT 0, \
                  sharing INTEGER NOT NULL DEFAULT 0, \
                  PRIMARY KEY(id) \
              );");

        exec("CREATE TABLE Task ( \
                  id INTEGER, \
                  list INTEGER NOT NULL, \
                  name TEXT NOT NULL, \
                  completed INTEGER NOT NULL DEFAULT 0, \
                  PRIMARY KEY(id), \
                  FOREIGN KEY(list) REFERENCES List(id) ON DELETE CASCADE\
              );");

        exec("CREATE TRIGGER CreateTask \
              AFTER INSERT ON Task \
              BEGIN \
                  UPDATE List \
                  SET numTasks = numTasks + 1, numCompletedTasks = numCompletedTasks + NEW.completed \
                  WHERE id = NEW.list; \
              END;");

        exec("CREATE TRIGGER DeleteTask \
              AFTER DELETE ON Task \
              BEGIN \
                  UPDATE List \
                  SET numTasks = numTasks - 1, numCompletedTasks = numCompletedTasks - OLD.completed \
                  WHERE id = OLD.list; \
              END;");

        exec("CREATE TRIGGER UpdateTask \
              AFTER UPDATE OF completed ON Task \
              BEGIN \
                  UPDATE List \
                  SET numCompletedTasks = numCompletedTasks - OLD.completed + NEW.completed \
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
    QVariantList lists;

    while (q.next())
    {
        QVariantMap map;
        map.insert("id", q.value(0).toInt());
        map.insert("name", q.value(1).toString());
        map.insert("description", q.value(2).toString());
        map.insert("numTasks", q.value(3).toInt());
        map.insert("numCompletedTasks", q.value(4).toInt());
        map.insert("sharing", q.value(5).toBool());
        lists.append(map);
    }

    emit getLists(lists);
}

void Server::requestTasks(int listid)
{
    QSqlQuery q1 = exec(QString("SELECT name, description FROM List WHERE id = %1").arg(listid));
    QSqlQuery q2 = exec(QString("SELECT * FROM Task WHERE list = %1").arg(listid));
    QVariantMap list;
    QVariantList tasks;

    q1.next();
    list.insert("name", q1.value(0).toString());
    list.insert("description", q1.value(1).toString());

    while (q2.next())
    {
        QVariantMap map;
        map.insert("id", q2.value(0).toInt());
        map.insert("name", q2.value(2).toString());
        map.insert("completed", q2.value(3).toBool());
        tasks.append(map);
    }

    emit getTasks(list, tasks);
}



void Server::createNewList(const QString& name)
{
    exec(QString("INSERT INTO List(name) VALUES(\"%1\")").arg(name));
    QSqlQuery q = exec("SELECT MAX(id) FROM List");

    q.next();

    emit newListCreated(q.value(0).toInt());
}

void Server::createNewTask(int listid, const QString& name)
{
    exec(QString("INSERT INTO Task(list, name) VALUES(%1, \"%2\")").arg(listid).arg(name));
    QSqlQuery q = exec("SELECT MAX(id), name FROM Task");

    q.next();

    emit newTaskCreated(q.value(0).toInt(), q.value(1).toString());
}

void Server::setTaskCompleted(int taskid, bool completed)
{
    exec(QString("UPDATE Task SET completed = %1 WHERE id = %2").arg(completed).arg(taskid));
}

QSqlQuery Server::exec(const QString& query)
{
    QSqlQuery q;
    if (!q.exec(query))
        qDebug() << q.lastError().text();

    return q;
}
