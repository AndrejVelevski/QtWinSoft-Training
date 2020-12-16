#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(myExitFunction()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked() //AUTO GENERATED
{
    close();
}

void MainWindow::myExitFunction()
{
    close();
}
