#include "dialogaddnewperson.h"
#include "ui_dialogaddnewperson.h"

DialogAddNewPerson::DialogAddNewPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddNewPerson)
{
    ui->setupUi(this);

    //layout()->setSizeConstraint(QLayout::SetFixedSize);
}

DialogAddNewPerson::~DialogAddNewPerson()
{
    delete ui;
}

Person* DialogAddNewPerson::getPerson() const
{
    return new Person(ui->lineEditFirstName->text(), ui->lineEditLastName->text(), ui->spinBoxAge->value());
}
