#ifndef DIALOGADDNEWPERSON_H
#define DIALOGADDNEWPERSON_H

#include <QDialog>
#include "person.h"

namespace Ui {
    class DialogAddNewPerson;
}

class DialogAddNewPerson : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddNewPerson(QWidget *parent = nullptr);

    ~DialogAddNewPerson();

    Person* getPerson() const;

private:
    Ui::DialogAddNewPerson *ui;
};

#endif // DIALOGADDNEWPERSON_H
