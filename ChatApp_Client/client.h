#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QLabel>
#include <QStackedWidget>
#include <QDateTime>

#include "ui_mainwindow.h"

enum PacketType
{
    Connected, TryLogIn, LogInSuccess, LogInFailed, ClientToServerMessage, ServerToClientMessage, GetUsers, Kick, Kicked
};

class Client : public QObject
{
    Q_OBJECT

private:
    Ui::MainWindow *mUI;
    QTcpSocket *mSocket;

private slots:
    void readyRead();
    void stateChanged(QAbstractSocket::SocketState socketState);

public:
    Client(QObject *parent, Ui::MainWindow *ui);

    void connectToServer();
    void disconnectFromServer();
    void sendMessage();
};

#endif // CLIENT_H
