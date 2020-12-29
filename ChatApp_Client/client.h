#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDateTime>

class Client : public QObject
{
    Q_OBJECT

    enum PacketType
    {
        Connected, TryLogIn, LogInSuccess, LogInFailed, ClientToServerMessage, ServerToClientMessage, GetUsers, Kick, Kicked
    };

public:
    Client(QObject *parent=nullptr);

signals:
    void connectionSuccess();
    void logInSuccess();
    void logOut();
    void errorMessage(const QString& message);
    void chatMessage(const QString& dateTime, const QString& username, const QString& message);
    void getUsers(const QStringList& users);

public slots:
    void connectToServer(const QString& address, const QString& port);
    void disconnectFromServer();
    void sendMessage(const QString& message);
    void tryLogIn(const QString& username);

private:
    QTcpSocket *mSocket;
    bool mLastError;

private slots:
    void readyRead();
    void stateChanged(QAbstractSocket::SocketState socketState);
};

#endif // CLIENT_H
