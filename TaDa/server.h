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
    void requestCompleteLists();
    void requestIncompleteLists();

private:
    QSqlQuery exec(const QString& query);

    QSqlDatabase mDB;

signals:
    void getCompleteLists(QVariantList list);
    void getIncompleteLists(QVariantList list);
};

#endif // SERVER_H
