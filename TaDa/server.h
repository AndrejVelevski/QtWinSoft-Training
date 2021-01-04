#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QVariantList>
#include <QVariantMap>

class Server : public QObject
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

public slots:
    void requestLists();
    void requestTasks(int listid);
    void createNewList(const QString& name);
    void createNewTask(int listid, const QString& name);
    void setTaskCompleted(int taskid, bool completed);

private:
    QSqlQuery exec(const QString& query);

    QSqlDatabase mDB;

signals:
    void getLists(QVariantList lists);
    void getTasks(QVariantMap list, QVariantList tasks);
    void newListCreated(int id);
    void newTaskCreated(int id, const QString& name);
};

#endif // SERVER_H
