#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QHash>
#include <QDateTime>

enum PacketType
{
    Connected, TryLogIn, LogInSuccess, LogInFailed, ClientToServerMessage, ServerToClientMessage, GetUsers, Kick, Kicked
};

class Server : public QObject
{
    Q_OBJECT

private:
    QTcpServer *mServer;
    QString mAddress;
    quint16 mPort;
    QHash<QTcpSocket*, QString> mSockets;

private:
    void disconnectUser(QTcpSocket* socket);
    void messageToAllUsers(QTcpSocket *socket, const QString &message);
    void tryLogIn(QTcpSocket *socket, const QString &username);
    void updateUsers();
    void kickUser(QTcpSocket *socket, const QString &username);

private slots:
    void newConnection();
    void readyRead();
    void stateChanged(QAbstractSocket::SocketState socketState);

public:
    explicit Server(const QString& address, quint16 port, QObject *parent=0);
    ~Server();

    void start() const;
};

#endif // SERVER_H
