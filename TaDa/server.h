#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

private:
    QSqlDatabase mDB;
};

#endif // SERVER_H
