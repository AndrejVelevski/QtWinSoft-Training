#include "person.h"

Person::Person()
{

}

Person::Person(const QString& firstName, const QString& lastName, int age) :
    mFirstName(firstName),
    mLastName(lastName),
    mAge(age)
{
    this->setText(ToString());
}

QString Person::ToString() const
{
    return mFirstName + " " + mLastName + " " + QString::number(mAge);
}

QString Person::getFirstName()
{
    return mFirstName;
}

QString Person::getLastName()
{
    return mLastName;
}

int Person::getAge()
{
    return mAge;
}
