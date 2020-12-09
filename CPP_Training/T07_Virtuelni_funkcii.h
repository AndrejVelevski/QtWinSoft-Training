#ifndef T07_VIRTUELNI_FUNKCII_H
#define T07_VIRTUELNI_FUNKCII_H

#include <iomanip>
#include <iostream>
#include <cstring>
#include <sstream>

class Datum3
{
private:
    int den;
    int godina;
    int mesec;

public:
    Datum3() {}

    Datum3(int den, int mesec, int godina)
    {
        this->den = den;
        this->mesec = mesec;
        this->godina = godina;
    }

    static bool isLeapYear(int year)
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

    static int daysOfMonth(int month, int year)
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

    static int days(const Datum3& d)
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

    static Datum3 getDatum(int days)
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

        return Datum3(d, m, y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Datum3& d)
    {
        std::stringstream ss;
        ss << d.den << "." << d.mesec << "." << d.godina;
        return os << ss.str();
    }

    friend std::istream& operator>>(std::istream& is, Datum3& d)
    {
        return is >> d.den >> d.mesec >> d.godina;
    }
};

class Zivotno2
{
protected:
    Datum3 ragjanje;
    Datum3 donesuvanje;
    char pol;
    char ime[15];
    Datum3 vakcina;

public:
    Datum3 getVakcina()
    {
        return vakcina;
    }

public:
    virtual char getTip() = 0;

    Zivotno2(const Datum3& ragjanje, const Datum3& donesuvanje, char pol, const char* ime, const Datum3& vakcina)
    {
        this->ragjanje = ragjanje;
        this->donesuvanje = donesuvanje;
        this->pol = pol;
        std::strcpy(this->ime, ime);
        this->vakcina = vakcina;
    }

    virtual ~Zivotno2() {}

    virtual void prikaziPodatoci()
    {
        std::cout << std::setw(15) << std::left << ragjanje
                  << std::setw(15) << std::left << donesuvanje
                  << std::setw(5) << std::left << pol
                  << std::setw(20) << std::left << ime
                  << std::setw(15) << std::left << vakcina << std::endl;
    }

    static void prikaziHeader()
    {
        std::cout << std::setw(15) << std::left << "Ragjanje"
                  << std::setw(15) << std::left << "Donesuvanje"
                  << std::setw(5) << std::left << "Pol"
                  << std::setw(20) << std::left << "Ime"
                  << std::setw(15) << std::left << "Vakcina"
                  << std::setw(20) << std::left << "Sledna Vakcina"
                  << std::setw(15) << std::left << "Letac"
                  << std::setw(15) << std::left << "Prezivar" << std::endl;
    }

    virtual bool presmetajVakcinacija(const Datum3& d) = 0;
};

class Vlekaci : public Zivotno2
{
private:
    Datum3 slednaVakcina;

public:
    inline static const char tip = 'v';

    char getTip() override
    {
        return tip;
    }

    Vlekaci(const Datum3& ragjanje, const Datum3& donesuvanje, char pol, const char* ime, const Datum3& vakcina, const Datum3& slednaVakcina) :
        Zivotno2(ragjanje, donesuvanje, pol, ime, vakcina)
    {
        this->slednaVakcina = slednaVakcina;
    }

    void prikaziPodatoci() override
    {
        std::cout << std::setw(15) << std::left << ragjanje
                  << std::setw(15) << std::left << donesuvanje
                  << std::setw(5) << std::left << pol
                  << std::setw(20) << std::left << ime
                  << std::setw(15) << std::left << vakcina
                  << std::setw(20) << std::left << slednaVakcina << std::endl;
    }

    bool presmetajVakcinacija(const Datum3& d) override
    {
        return ((Datum3::days(d) - Datum3::days(vakcina)) - 243 - 7 <= 0);
    }
};

class Ptici : public Zivotno2
{
private:
    char letac;

public:
    inline static const char tip = 'p';

    char getTip() override
    {
        return tip;
    }

    Ptici(const Datum3& ragjanje, const Datum3& donesuvanje, char pol, const char* ime, const Datum3& vakcina, char letac) :
        Zivotno2(ragjanje, donesuvanje, pol, ime, vakcina)
    {
        this->letac = letac;
    }

    void prikaziPodatoci() override
    {
        std::cout << std::setw(15) << std::left << ragjanje
                  << std::setw(15) << std::left << donesuvanje
                  << std::setw(5) << std::left << pol
                  << std::setw(20) << std::left << ime
                  << std::setw(35) << std::left << vakcina
                  << std::setw(15) << std::left << letac << std::endl;
    }

    bool presmetajVakcinacija(const Datum3& d) override
    {
        return ((Datum3::days(d) - Datum3::days(vakcina)) - 182 - 7 <= 0);
    }
};

class Cicaci : public Zivotno2
{
private:
    char prezivar;

public:
    inline static const char tip = 'c';

    char getTip() override
    {
        return tip;
    }

    Cicaci(const Datum3& ragjanje, const Datum3& donesuvanje, char pol, const char* ime, const Datum3& vakcina, char prezivar) :
        Zivotno2(ragjanje, donesuvanje, pol, ime, vakcina)
    {
        this->prezivar = prezivar;
    }

    void prikaziPodatoci() override
    {
        std::cout << std::setw(15) << std::left << ragjanje
                  << std::setw(15) << std::left << donesuvanje
                  << std::setw(5) << std::left << pol
                  << std::setw(20) << std::left << ime
                  << std::setw(50) << std::left << vakcina
                  << std::setw(15) << std::left << prezivar << std::endl;
    }

    bool presmetajVakcinacija(const Datum3& d) override
    {
        return ((Datum3::days(d) - Datum3::days(vakcina)) - 365 - 7 <= 0);
    }
};

class Zooloska2
{
private:
    Zivotno2** zivotni;
    int brojZivotni;

public:
    Zooloska2()
    {
        brojZivotni = 0;
        zivotni = new Zivotno2*[1000];

    }

    ~Zooloska2()
    {
        for (int i=0;i<brojZivotni;++i)
            delete zivotni[i];
        delete[] zivotni;
    }

    Zooloska2(const Zooloska2& z) = delete;
    Zooloska2& operator=(const Zooloska2& z) = delete;

    void dodadiZivotno(Zivotno2* z)
    {
        zivotni[brojZivotni++] = z;
    }

    void pecatiBrojZivotni()
    {
        std::cout << "Broj na zivotni: " << brojZivotni << std::endl;
    }

    void dodadiZivotno()
    {
        Datum3 ragjanje;
        Datum3 donesuvanje;
        char tip;
        char pol;
        char ime[15];
        Datum3 vakcinacija;
        Datum3 sledna;
        char letac;
        char prezivar;

        std::cout << "Vnesete tip (c-cicaci, v-vlekaci, p-ptici): ";
        std::cin >> tip;

        std::cout << "Vnesete datum na ragjanje (dd mm yyyy): ";
        std::cin >> ragjanje;
        std::cout << "Vnesete datum na donesuvanje (dd mm yyyy): ";
        std::cin >> donesuvanje;
        std::cout << "Vnesete pol (m-masko, z-zensko): ";
        std::cin >> pol;
        std::cout << "Vnesete pol ime: ";
        std::cin >> ime;
        std::cout << "Vnesete datum na posledna vakcinacija (dd mm yyyy): ";
        std::cin >> vakcinacija;

        if (tip == 'c')
        {
            std::cout << "Vnesete dali e prezivar (d/n): ";
            std::cin >> prezivar;
            dodadiZivotno(new Cicaci(ragjanje, donesuvanje, pol, ime, vakcinacija, prezivar));
            return;
        }

        if (tip == 'p')
        {
            std::cout << "Vnesete dali e letac (d/n): ";
            std::cin >> letac;
            dodadiZivotno(new Ptici(ragjanje, donesuvanje, pol, ime, vakcinacija, letac));
            return;
        }

        if (tip == 'v')
        {
            std::cout << "Vnesete datum na sledna vakcinacija (dd mm yyyy): ";
            std::cin >> sledna;
            dodadiZivotno(new Vlekaci(ragjanje, donesuvanje, pol, ime, vakcinacija, sledna));
            return;
        }
    }

    void pecatiSiteZivotni()
    {
        if (brojZivotni > 0)
        {
            Zivotno2::prikaziHeader();
            for (int i=0;i<brojZivotni;++i)
            {
                zivotni[i]->prikaziPodatoci();
            }
        }
        else
        {
            std::cout << "Nema nitu edno zivotno vo zooloskata" << std::endl;
        }
    }

    void pecatiZivotniGrupa()
    {
        char grupa;

        std::cout << "Vnesete grupa: (c-cicaci, v-vlekaci, p-ptici): ";
        std::cin >> grupa;

        if (brojZivotni > 0)
        {
            Zivotno2::prikaziHeader();
            for (int i=0;i<brojZivotni;++i)
            {
                if (zivotni[i]->getTip() == grupa)
                    zivotni[i]->prikaziPodatoci();
            }
        }
        else
        {
            std::cout << "Nema nitu edno zivotno vo zooloskata" << std::endl;
        }
    }

    void pecatiZivotniVakcinacija()
    {
        if (brojZivotni > 0)
        {
            Datum3 d;
            std::cout << "Vnesete denesen datum (dd mm yyyy): ";
            std::cin >> d;

            Zivotno2::prikaziHeader();
            for (int i=0;i<brojZivotni;++i)
            {
                if (zivotni[i]->presmetajVakcinacija(d))
                    zivotni[i]->prikaziPodatoci();
            }
        }
        else
        {
            std::cout << "Nema nitu edno zivotno vo zooloskata" << std::endl;
        }
    }
};

void zadaca07_01()
{
    Zooloska2 zoo;
    zoo.dodadiZivotno(new Cicaci (Datum3(13, 6, 2020), Datum3(18, 8, 2020), 'm',     "Foka", Datum3(27, 7, 2020), 'n'));
    zoo.dodadiZivotno(new Ptici  (Datum3( 2, 7, 2020), Datum3(18, 8, 2020), 'z',     "Orel", Datum3(23, 8, 2020), 'd'));
    zoo.dodadiZivotno(new Vlekaci(Datum3( 8, 2, 2020), Datum3(18, 8, 2020), 'z',    "Zmija", Datum3( 4, 3, 2020), Datum3(25, 9, 2020)));
    zoo.dodadiZivotno(new Cicaci (Datum3(24, 1, 2020), Datum3(18, 8, 2020), 'z',    "Tigar", Datum3(13, 2, 2020), 'n'));
    zoo.dodadiZivotno(new Ptici  (Datum3(28, 3, 2020), Datum3(18, 8, 2020), 'm',      "Buv", Datum3( 8, 4, 2020), 'd'));
    zoo.dodadiZivotno(new Vlekaci(Datum3(16, 3, 2020), Datum3(18, 8, 2020), 'm', "Krokodil", Datum3(16, 4, 2020), Datum3(4, 9, 2020)));

    while(true)
    {
        std::cout << "__________________________________________________________________" << std::endl;
        std::cout << "1 - Dodadi zivotno" << std::endl;
        std::cout << "2 - Prikazi broj na zivotni" << std::endl;
        std::cout << "3 - Prikazi zivotni od dadena grupa (c-cicaci, v-vlekaci, p-ptici)" << std::endl;
        std::cout << "4 - Prikazi cela lista na zivotni" << std::endl;
        std::cout << "5 - Prikazi zivotni koi treba da se vakciniraat vo rok od 1 nedela" << std::endl;
        std::cout << "6 - Izlez" << std::endl;
        std::cout << "Opcija: ";
        int opcija;
        std::cin >> opcija;

        if (opcija == 6)
            break;

        switch(opcija)
        {
            case 1: zoo.dodadiZivotno(); break;
            case 2: zoo.pecatiBrojZivotni(); break;
            case 3: zoo.pecatiZivotniGrupa(); break;
            case 4: zoo.pecatiSiteZivotni(); break;
            case 5: zoo.pecatiZivotniVakcinacija(); break;
        }
    }

    std::cout << std::endl;

}

#endif // T07_VIRTUELNI_FUNKCII_H
