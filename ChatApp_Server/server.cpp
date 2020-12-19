#include "server.h"

Server::Server(const QString& address, quint16 port, QObject *parent) :
    QObject(parent),
    mServer(new QTcpServer()),
    mAddress(address),
    mPort(port)
{
    connect(mServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

Server::~Server()
{
    delete mServer;
}

void Server::start() const
{
    if (mServer->listen(QHostAddress::Any, mPort))
    {
        qDebug() << "Server started";
        qDebug() << "Listening on port" << mPort;
    }
    else
    {
        qDebug() << "Server could not start";
    }
}

void Server::disconnectUser(QTcpSocket* socket)
{
    qDebug() << "Client" << socket->peerAddress().toString() << "disconnected";

    if (socket->state() != QAbstractSocket::SocketState::UnconnectedState)
        socket->waitForBytesWritten();

    mSockets.remove(socket);
    socket->close();
    socket->deleteLater();
}

void Server::messageToAllUsers(QTcpSocket *socket, const QString &message)
{
    QByteArray data;
    QDataStream dataOut(&data, QIODevice::WriteOnly);

    dataOut << PacketType::ServerToClientMessage
            << QDateTime::currentDateTime()
            << mSockets[socket]
            << message;

    for (QTcpSocket *s : mSockets.keys())
    {
        s->write(data);
    }
}

void Server::tryLogIn(QTcpSocket *socket, const QString &username)
{
    QByteArray data;
    QDataStream dataOut(&data, QIODevice::WriteOnly);

    bool exists = false;
    for (QString &user : mSockets.values())
    {
        if (user == username)
        {
            exists = true;
            break;
        }
    }

    mSockets.insert(socket, username);

    if (exists)
    {
        dataOut << PacketType::LogInFailed << QString("Disconnected, username already exists");
        socket->write(data);
        disconnectUser(socket);
    }
    else
    {
        dataOut << PacketType::LogInSuccess;
        socket->write(data);
        updateUsers();
        messageToAllUsers(socket, "Joined the room");
    }
}

void Server::updateUsers()
{
    QByteArray data;
    QDataStream dataOut(&data, QIODevice::WriteOnly);
    QStringList usernames;

    for (QString &username : mSockets.values())
        usernames << username;

    dataOut << PacketType::GetUsers << usernames;

    for (QTcpSocket *socket : mSockets.keys())
    {
        socket->write(data);
    }
}

void Server::kickUser(QTcpSocket *socket, const QString& username)
{
    QHashIterator<QTcpSocket*, QString> it(mSockets);

    while(it.hasNext())
    {
        it.next();

        if (it.value() == username)
        {
            QByteArray data;
            QDataStream dataOut(&data, QIODevice::WriteOnly);

            dataOut << PacketType::Kicked << QString("You have been kicked by %1").arg(mSockets[socket]);
            it.key()->write(data);
            messageToAllUsers(socket, QString("Has kicked %1").arg(it.value()));
            disconnectUser(it.key());
            updateUsers();

            return;
        }
    }
}

void Server::newConnection()
{
    QTcpSocket *socket = mServer->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
    mSockets.insert(socket, nullptr);

    qDebug() << "Client" << socket->peerAddress().toString() << "connected";

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << PacketType::Connected;
    socket->write(data);
}

void Server::readyRead()
{
    QTcpSocket *socket = (QTcpSocket*)sender();

    while(socket->bytesAvailable())
    {
        QDataStream dataIn(socket);

        PacketType type;
        dataIn >> type;

        QByteArray data;
        QDataStream dataOut(&data, QIODevice::WriteOnly);

        switch (type)
        {
            case TryLogIn:
            {
                QString username;
                dataIn >> username;
                tryLogIn(socket, username);
                break;
            }
            case ClientToServerMessage:
            {
                QString message;
                dataIn >> message;
                messageToAllUsers(socket, message);
                break;
            }
            case Kick:
            {
                QString username;
                dataIn >> username;
                kickUser(socket, username);
                break;
            }
            default:
            {
                qDebug() << "Wrong packet type:" << type;
                break;
            }
        }
    }
}

void Server::stateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::SocketState::UnconnectedState)
    {
        QTcpSocket *socket = (QTcpSocket*)sender();
        if (mSockets.contains(socket))
        {
            messageToAllUsers(socket, "Left the room");
            disconnectUser(socket);
            updateUsers();
        }
    }
}
