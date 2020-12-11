#ifndef DATUM_H
#define DATUM_H

#include <iostream>

class Datum
{
private:
    int den;
    int godina;
    int mesec;

public:
    Datum();
    Datum(int den, int mesec, int godina);
    static bool isLeapYear(int year);
    static int daysOfMonth(int month, int year);

    static int days(const Datum& d)
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

    static Datum getDatum(int days);

    friend std::ostream& operator<<(std::ostream& os, const Datum& d);

    friend std::istream& operator>>(std::istream& is, Datum& d);
};

#endif // DATUM_H
