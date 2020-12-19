#include "client.h"

Client::Client(QObject *parent, Ui::MainWindow *ui) :
    QObject(parent),
    mUI(ui),
    mSocket(new QTcpSocket(this))
{
    connect(mSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(mSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
}

void Client::connectToServer()
{
    QString username = mUI->lineEditUsername->text();
    if (username.length() == 0)
    {
        mUI->labelStatus->setStyleSheet("QLabel { color: red; }");
        mUI->labelStatus->setText("Username can't be empty");
        return;
    }
    if (username.contains(' '))
    {
        mUI->labelStatus->setStyleSheet("QLabel { color: red; }");
        mUI->labelStatus->setText("Username can't contain whitespace characters");
        return;
    }

    mUI->lineEditUsername->setText(username);

    mSocket->connectToHost(mUI->lineEditAddress->text(), mUI->spinBoxPort->value());

    if (mSocket->waitForConnected(5000))
    {
        mUI->labelStatus->setStyleSheet("QLabel { color: green; }");
        mUI->labelStatus->setText("Connected");
    }
    else
    {
        mUI->labelStatus->setStyleSheet("QLabel { color: red; }");
        mUI->labelStatus->setText("Can't connect to server");
        mSocket->close();
    }
}

void Client::sendMessage()
{
    QString message = mUI->textEditMessage->toPlainText();

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
                QByteArray data;
                QDataStream out(&data, QIODevice::WriteOnly);
                out << PacketType::TryLogIn << mUI->lineEditUsername->text();
                socket->write(data);
                break;
            }
            case LogInSuccess:
            {
                mUI->stackedWidgetMenu->setCurrentIndex(1);
                break;
            }
            case LogInFailed:
            {
                QString message;
                dataIn >> message;
                mUI->labelStatus->setStyleSheet("QLabel { color: red; }");
                mUI->labelStatus->setText(message);
                break;
            }
            case ServerToClientMessage:
            {
                QDateTime dateTime;
                QString username, message;
                dataIn >> dateTime >> username >> message;
                mUI->listWidgetChat->addItem(QString("[%1] %2: %3").arg(dateTime.time().toString(), username, message));
                mUI->listWidgetChat->scrollToBottom();
                break;
            }
            case GetUsers:
            {
                QStringList users;
                dataIn >> users;
                mUI->listWidgetUsers->clear();
                mUI->listWidgetUsers->addItems(users);
                break;
            }
            case Kicked:
            {
                QString message;
                dataIn >> message;

                mSocket->close();
                mUI->labelStatus->setStyleSheet("QLabel { color: red; }");
                mUI->labelStatus->setText(message);
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
        mSocket->close();
        mUI->listWidgetChat->clear();
        mUI->listWidgetUsers->clear();
        mUI->textEditMessage->clear();
        mUI->stackedWidgetMenu->setCurrentIndex(0);
        if (mUI->labelStatus->styleSheet() != "QLabel { color: red; }")
        {
            mUI->labelStatus->setStyleSheet("QLabel { color: red; }");
            mUI->labelStatus->setText("Server closed");
        }
    }
}

void Client::disconnectFromServer()
{
    mSocket->close();
    mUI->labelStatus->setStyleSheet("QLabel { color: green; }");
    mUI->labelStatus->setText("Logged out");
}


