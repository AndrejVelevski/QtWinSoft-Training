#ifndef PERSON_H
#define PERSON_H

#include <QListWidgetItem>

class Person : public QListWidgetItem
{
public:
    Person();
    Person(const QString& firstName, const QString& lastName, int age);

    QString getFirstName();
    QString getLastName();
    int getAge();

    QString ToString() const;

private:
    QString mFirstName;
    QString mLastName;
    int mAge;
};

#endif // PERSON_H
