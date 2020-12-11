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
    static int days(const Datum& d);
    static Datum getDatum(int days);
    friend std::ostream& operator<<(std::ostream& os, const Datum& d);
    friend std::istream& operator>>(std::istream& is, Datum& d);
};

#endif // DATUM_H
