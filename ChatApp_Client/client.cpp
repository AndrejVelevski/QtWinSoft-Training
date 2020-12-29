#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent),
    mSocket(new QTcpSocket(this)),
    mLastError(false)
{
    connect(mSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(mSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
}

void Client::connectToServer(const QString& address, const QString& port)
{
    mSocket->connectToHost(address, port.toInt());

    if (!mSocket->waitForConnected(5000))
    {
        emit errorMessage("Couldn't connect to server");
        mSocket->close();
    }
}


void Client::sendMessage(const QString& message)
{
    if (message.trimmed().length() == 0)
        return;

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);

    if (message[0] == '/')
    {
        QStringList sub = message.trimmed().split(" ");

        if (sub[0] == "/disconnect")
        {
            disconnectFromServer();
            return;
        }
        if (sub[0] == "/kick")
        {
            if (sub.length() == 2)
            {
                out << PacketType::Kick << sub[1];
                mSocket->write(data);
            }

            return;
        }
    }

    out << PacketType::ClientToServerMessage << message;

    mSocket->write(data);
}

void Client::tryLogIn(const QString& username)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << PacketType::TryLogIn << username;
    mSocket->write(data);
}

void Client::readyRead()
{
    QTcpSocket *socket = (QTcpSocket*)sender();

    while(socket->bytesAvailable())
    {
        QDataStream dataIn(socket);

        PacketType type;

        dataIn >> type;

        switch (type)
        {
            case Connected:
            {
                emit connectionSuccess();
                mLastError = false;
                break;
            }
            case LogInSuccess:
            {
                emit logInSuccess();
                mLastError = false;
                break;
            }
            case LogInFailed:
            {
                QString message;
                dataIn >> message;
                emit errorMessage(message);
                mLastError = true;
                break;
            }
            case ServerToClientMessage:
            {
                QDateTime dateTime;
                QString username, message;
                dataIn >> dateTime >> username >> message;
                emit chatMessage(dateTime.toString("yyyy.MM.dd hh:mm:ss"), username, message);
                break;
            }
            case GetUsers:
            {
                QStringList users;
                dataIn >> users;
                emit getUsers(users);
                break;
            }
            case Kicked:
            {
                QString message;
                dataIn >> message;

                mSocket->close();
                emit errorMessage(message);
                mLastError = true;
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

void Client::stateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::SocketState::UnconnectedState)
    {
        if (!mLastError)
            emit errorMessage("Server closed");
    }
}

void Client::disconnectFromServer()
{
    mSocket->close();
    emit logOut();
}

