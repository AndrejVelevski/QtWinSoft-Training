#include "mainwindow.h"
#include "dialogaddnewperson.h"
#include "ui_mainwindow.h"
#include "person.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listWidget->addItem(new Person("Jovan", "Jovanovski", 20));
    ui->listWidget->addItem(new Person("Maja", "Maevska", 23));
    ui->listWidget->addItem(new Person("Kosta", "Kostovski", 26));
    ui->listWidget->addItem(new Person("Jana", "Janevska", 28));
    ui->listWidget->addItem(new Person("Nikola", "Nikolovski", 25));
    ui->listWidget->addItem(new Person("Ana", "Anevska", 23));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAdd_Person_triggered()
{
    DialogAddNewPerson d(this);

    if (d.exec())
        ui->listWidget->addItem(d.getPerson());
}
