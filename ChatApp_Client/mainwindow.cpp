#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mUI(new Ui::MainWindow),
    mClient(new Client(this, mUI))
{
    mUI->setupUi(this);
    mUI->textEditMessage->installEventFilter(this);
    mUI->splitter_1->setSizes(QList<int>() << 1 << 1000);
    mUI->splitter_2->setSizes(QList<int>() << 1000 << 1);

    mUI->pushButtonTheme->setText("Dark");
    on_pushButtonTheme_clicked();
}

MainWindow::~MainWindow()
{
    delete mUI;
    delete mClient;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == mUI->textEditMessage && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = (QKeyEvent*)event;

        if (keyEvent->key() == Qt::Key_Return)
        {
            mClient->sendMessage();
            mUI->textEditMessage->clear();
            return true;
        }
    }

    return QMainWindow::eventFilter(object, event);
}

void MainWindow::on_pushButtonConnect_clicked()
{
    mClient->connectToServer();
}

void MainWindow::on_pushButtonDisconnect_clicked()
{
    mClient->disconnectFromServer();
}

void MainWindow::on_pushButtonTheme_clicked()
{
    if (mUI->pushButtonTheme->text() == "Light")
    {
        mUI->pushButtonTheme->setText("Dark");
        setStyleSheet(
                        "QWidget { background-color: rgb(16, 16, 16) }"
                        "QWidget { color : rgb(255, 255, 255) }"
                        "QLineEdit, QSpinBox, QListWidget, QTextEdit, #groupBox, #labelStatus { background-color: rgb(44, 44, 44) }"
                     );

    }
    else
    {
        mUI->pushButtonTheme->setText("Light");
        setStyleSheet(
                        "QWidget { background-color: rgb(227, 227, 227) }"
                        "QWidget { color : rgb(0, 0, 0) }"
                        "QLineEdit, QSpinBox, QListWidget, QTextEdit, #groupBox, #labelStatus { background-color: rgb(255, 255, 255) }"
                     );
    }
}
