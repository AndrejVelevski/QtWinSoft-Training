#include "Datum.h"
#include <sstream>

Datum::Datum()
{

}

Datum::Datum(int den, int mesec, int godina)
{
    this->den = den;
    this->mesec = mesec;
    this->godina = godina;
}

bool Datum::isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}

int Datum::daysOfMonth(int month, int year)
{
    switch (month)
    {
        case 1: return 31;
        case 2: return isLeapYear(year)?29:28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
    }
    return -1;
}

int Datum::days(const Datum& d)
    {
        int day = 0;
        for (int i=1;i<d.godina;++i)
        {
            if (isLeapYear(i))
                day += 366;
            else
                day += 365;
        }

        for (int i=1;i<d.mesec;++i)
            day += daysOfMonth(i, d.godina);

        day += d.den;

        return day;
    }

Datum Datum::getDatum(int days)
{
    int d = 1;
    int m = 1;
    int y = 1;

    while(true)
    {
        if (isLeapYear(y))
        {
            if (days >= 366)
            {
                days -= 366;
                ++y;
            }
            else
                break;
        }
        else
        {
            if (days >= 365)
            {
                days -= 365;
                ++y;
            }
            else
                break;
        }
    }

    while(true)
    {
        int dim = daysOfMonth(m, y);

        if (days >= dim)
        {
            days -= dim;
            ++m;
        }
        else
            break;
    }

    d = days;

    return Datum(d, m, y);
}

std::ostream& operator<<(std::ostream& os, const Datum& d)
{
    std::stringstream ss;
    ss << d.den << "." << d.mesec << "." << d.godina;
    return os << ss.str();
}

std::istream& operator>>(std::istream& is, Datum& d)
{
    return is >> d.den >> d.mesec >> d.godina;
}
