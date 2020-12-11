#ifndef T02_KLASI_H
#define T02_KLASI_H

#include <iomanip>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Datum.h"

class Kvadar
{
private:
    int mDolzina;
    int mSirina;
    int mVisina;

public:
    Kvadar()
    {

    }

    Kvadar(int dolzina, int sirina, int visina) :
        mDolzina(dolzina),
        mSirina(sirina),
        mVisina(visina)
    {

    }

    int Plostina()
    {
        return 2*mDolzina*mSirina + 2*mSirina*mVisina + 2*mVisina*mDolzina;
    }

    int Volumen()
    {
        return mDolzina*mSirina*mVisina;
    }

    bool Kocka()
    {
        return (mDolzina == mSirina) && (mDolzina == mVisina) && (mSirina == mVisina);
    }

    friend std::ostream& operator<<(std::ostream& o, Kvadar& k)
    {
        return o << std::setw(10) << std::left << k.mDolzina
                 << std::setw(10) << std::left << k.mSirina
                 << std::setw(10) << std::left << k.mVisina;
    }
};

Kvadar kreirajKvadar()
{
    int dolzina, sirina, visina;
    std::cout << "Vnesete dolzina: ";
    std::cin >> dolzina;
    std::cout << "Vnesete sirina: ";
    std::cin >> sirina;
    std::cout << "Vnesete visina: ";
    std::cin >> visina;

    return Kvadar(dolzina, sirina, visina);
}

void pecatiHeaderKvadar()
{
    std::cout << std::setw(10) << std::left << "ID"
              << std::setw(10) << std::left << "Dolzina"
              << std::setw(10) << std::left << "Sirina"
              << std::setw(10) << std::left << "Visina"
              << std::endl;
}

void pecatiKvadari(Kvadar* kvadari, int size)
{
    pecatiHeaderKvadar();

    for (int i=0;i<size;++i)
    {
        std::cout << std::setw(10) << std::left << i << kvadari[i] << std::endl;
    }
}

void pecatiEdenKvadar(Kvadar* kvadari, int size)
{
    int id;
    std::cout << "Vnesete ID na kvadarot: ";
    std::cin >> id;

    if (id < 0 || id >= size)
        std::cout << "Ne postoi kvadar so toa id" << std::endl;
    else
    {
        pecatiHeaderKvadar();
        std::cout << std::setw(10) << std::left << id << kvadari[id] << std::endl;
    }
}

void pecatiNajmalKvadar(Kvadar* kvadari, int size)
{
    if (size == 0)
        return;

    int idx = 0;

    for (int i=1;i<size;++i)
    {
        if (!kvadari[i].Kocka() && kvadari[i].Plostina() < kvadari[idx].Plostina())
        {
            idx = i;
        }
    }

    pecatiHeaderKvadar();
    std::cout << std::setw(10) << std::left << idx << kvadari[idx] << std::endl;
}

void zadaca02_01()
{
    int maxElements = 1000;
    int idx = 0;
    Kvadar* kvadari = new Kvadar[maxElements];
    kvadari[idx++] = Kvadar(15, 4, 36);
    kvadari[idx++] = Kvadar(13, 24, 8);
    kvadari[idx++] = Kvadar(4, 13, 8);
    kvadari[idx++] = Kvadar(5, 3, 12);
    kvadari[idx++] = Kvadar(10, 20, 30);
    kvadari[idx++] = Kvadar(13, 14, 17);

    while(true)
    {
        std::cout << "_________________________________" << std::endl;
        std::cout << "0 - Izlez" << std::endl;
        std::cout << "1 - Kreiraj nov objekt" << std::endl;
        std::cout << "2 - Pecati gi dimenziite na site objekti" << std::endl;
        std::cout << "3 - Pecati gi dimenziite na poedin objekt" << std::endl;
        std::cout << "4 - Pecati go toj so najmala plostina a ne e kocka" << std::endl;
        std::cout << "Opcija: ";
        int opcija;
        std::cin >> opcija;

        if (opcija == 0)
            break;

        switch (opcija)
        {
            case 1: kvadari[idx++] = kreirajKvadar(); break;
            case 2: pecatiKvadari(kvadari, idx); break;
            case 3: pecatiEdenKvadar(kvadari, idx); break;
            case 4: pecatiNajmalKvadar(kvadari, idx); break;
        }
    }

    delete[] kvadari;

    std::cout << std::endl;
}

class Stedac
{
private:
    int broj;
    char imeprezime[30], adresa[50];
    long saldo;

public:
    Stedac() {}

    Stedac(int broj, const char* imeprezime, const char* adresa, long saldo)
    {
        this->broj = broj;
        std::strcpy(this->imeprezime, imeprezime);
        std::strcpy(this->adresa, adresa);
        this->saldo = saldo;
    }

    int getBroj()
    {
        return broj;
    }

    char* getImeprezizme()
    {
        return imeprezime;
    }

    long getSaldo()
    {
        return saldo;
    }

    void vnesi_podatoci()
    {
        std::cout << "Vnesete broj: ";
        std::cin >> broj;
        std::cin.ignore();
        std::cout << "Vnesete ime i prezime: ";
        std::cin.getline(imeprezime, sizeof(imeprezime));
        std::cout << "Vnesete adresa: ";
        std::cin.getline(adresa, sizeof(adresa));
        std::cout << "Vnesete saldo: ";
        std::cin >> saldo;
        std::cin.ignore();
    }
    void prikazi_podatoci()
    {
        std::cout << std::setw(10) << std::left << broj
                  << std::setw(30) << std::left << imeprezime
                  << std::setw(50) << std::left << adresa
                  << std::setw(20) << std::left << saldo << std::endl;

    }
    void uplata(unsigned long i)
    {
        saldo += i;
    }

    void isplata(unsigned long i)
    {
        if (saldo < (long)i)
            std::cout << "Stedacot " << imeprezime << " nema dovolno sredstva za isplata." << std::endl;
        else
            saldo -= i;
    }
    long sostojba();

};

void pecatiHeaderStedac()
{
    std::cout << std::setw(10) << std::left << "Broj"
              << std::setw(30) << std::left << "Ime i prezime"
              << std::setw(50) << std::left << "Adresa"
              << std::setw(20) << std::left << "Saldo"
              << std::endl;
}

Stedac kreirajStedac()
{
    Stedac s;
    s.vnesi_podatoci();
    return s;
}

void uplataStedac(Stedac* stedaci, int size)
{
    int broj;
    std::cout << "Vnesete broj na stedac: ";
    std::cin >> broj;

    for (int i=0;i<size;++i)
    {
        if (stedaci[i].getBroj() == broj)
        {
            unsigned long uplata;
            std::cout << "Vnesete iznos za uplata: ";
            std::cin >> uplata;
            stedaci[i].uplata(uplata);
            return;
        }
    }
    std::cout << "Ne e pronajden stedac so toj broj." << std::endl;
}

void isplataStedac(Stedac* stedaci, int size)
{
    int broj;
    std::cout << "Vnesete broj na stedac: ";
    std::cin >> broj;

    for (int i=0;i<size;++i)
    {
        if (stedaci[i].getBroj() == broj)
        {
            unsigned long isplata;
            std::cout << "Vnesete iznos za isplata: ";
            std::cin >> isplata;
            stedaci[i].isplata(isplata);
            return;
        }
    }
    std::cout << "Ne e pronajden stedac so toj broj." << std::endl;
}

void prikaziSaldo(Stedac* stedaci, int size)
{
    int broj;
    std::cout << "Vnesete broj na stedac: ";
    std::cin >> broj;

    for (int i=0;i<size;++i)
    {
        if (stedaci[i].getBroj() == broj)
        {
            std::cout << "Saldoto na stedacot " << stedaci[i].getImeprezizme() << " iznesuva " << stedaci[i].getSaldo() << std::endl;
            return;
        }
    }
    std::cout << "Ne e pronajden stedac so toj broj." << std::endl;
}

void pecatiStedaci(Stedac* stedaci, int size)
{
    pecatiHeaderStedac();

    for (int i=0;i<size;++i)
    {
        stedaci[i].prikazi_podatoci();
    }
}

void zadaca02_02()
{
    int maxElements = 1000;
    int idx = 0;
    Stedac* stedaci = new Stedac[maxElements];
    stedaci[idx++] = Stedac(15, "Jovan Jovanovski",    "st. SomeAddress 123/1", 17800);
    stedaci[idx++] = Stedac(13,      "Ana Anevska", "st. SomeAddress 41\\5\\7", 38400);
    stedaci[idx++] = Stedac( 4, "Angel Angelovski", "st. SomeAddress 41\\5\\7", 30000);
    stedaci[idx++] = Stedac( 5,     "Maja Maevska",       "st. SomeAddress 30", 23480);
    stedaci[idx++] = Stedac(10,  "Kosta Kostovski",   "st. SomeAddress 12.58A", 25700);
    stedaci[idx++] = Stedac( 1,    "Jana Janevska",   "st. SomeAddress 222HB2", 31500);

    while(true)
    {
        std::cout << "_________________________________" << std::endl;
        std::cout << "0 - Izlez" << std::endl;
        std::cout << "1 - Kreiraj nov stedac" << std::endl;
        std::cout << "2 - Prikazi gi site stedaci" << std::endl;
        std::cout << "3 - Uplata" << std::endl;
        std::cout << "4 - Isplata" << std::endl;
        std::cout << "5 - Prikaz na saldo na stedac" << std::endl;
        std::cout << "Opcija: ";
        int opcija;
        std::cin >> opcija;

        if (opcija == 0)
            break;

        switch (opcija)
        {
            case 1: stedaci[idx++] = kreirajStedac(); break;
            case 2: pecatiStedaci(stedaci, idx); break;
            case 3: uplataStedac(stedaci, idx); break;
            case 4: isplataStedac(stedaci, idx); break;
            case 5: prikaziSaldo(stedaci, idx); break;
        }
    }

    delete[] stedaci;

    std::cout << std::endl;
}

class Fraction
{
private:
    int mNumerator;
    int mDenominator;

    int GCD(int num1, int num2)
    {
        while(1)
        {
            if (num2 == 0)
                return num1;

            int temp = num1%num2;
            num1 = num2;
            num2 = temp;
        }
    }

    int LCM(int num1, int num2)
    {
        return (num1 * num2) / GCD(num1, num2);
    }

public:
    Fraction(int numerator, int denominator) :
        mNumerator(numerator),
        mDenominator(denominator)
    {

    }

    Fraction& reduce()
    {
        int gcd = GCD(mNumerator, mDenominator);
        mNumerator /= gcd;
        mDenominator /= gcd;
        return *this;
    }

    Fraction operator+(const Fraction& f)
    {
        int d = LCM(mDenominator, f.mDenominator);
        int n = (d/mDenominator)*mNumerator + (d/f.mDenominator)*f.mNumerator;
        return Fraction(n, d).reduce();
    }

    Fraction operator-(const Fraction& f)
    {
        int d = LCM(mDenominator, f.mDenominator);
        int n = (d/mDenominator)*mNumerator - (d/f.mDenominator)*f.mNumerator;
        return Fraction(n, d).reduce();
    }

    Fraction operator*(const Fraction& f)
    {
        return Fraction(mNumerator * f.mNumerator, mDenominator * f.mDenominator).reduce();
    }

    Fraction operator/(const Fraction& f)
    {
        return Fraction(mNumerator * f.mDenominator, mDenominator * f.mNumerator).reduce();
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f)
    {
        return os << f.mNumerator << "/" << f.mDenominator;
    }

    double real()
    {
        return (double)mNumerator / mDenominator;
    }
};

void zadaca02_03()
{
    srand(time(NULL));

    int num;

    std::cout << "Vnesete broj na simulacii na dropki: ";
    std::cin >> num;

    for (int i=0;i<num;++i)
    {
        int n1, d1, n2, d2;

        while(true)
        {
            n1 = rand()%198-99;
            n2 = rand()%198-99;
            d1 = rand()%198-99;
            d2 = rand()%198-99;

            if (d1 != 0 && d2 !=0)
                break;
        }

        Fraction f1(n1, d1);
        Fraction f2(n2, d2);

        std::cout << f1 << " + " << f2 << " = " << f1+f2 << " = " << (f1+f2).real() << " = " << (double)n1/d1 + (double)n2/d2 << std::endl;
        std::cout << f1 << " - " << f2 << " = " << f1-f2 << " = " << (f1-f2).real() << " = " << (double)n1/d1 - (double)n2/d2 << std::endl;
        std::cout << f1 << " * " << f2 << " = " << f1*f2 << " = " << (f1*f2).real() << " = " << ((double)n1/d1) * ((double)n2/d2) << std::endl;
        std::cout << f1 << " / " << f2 << " = " << f1/f2 << " = " << (f1/f2).real() << " = " << ((double)n1/d1) / ((double)n2/d2) << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

class Zivotno
{
private:
    Datum ragjanje;
    Datum donesuvanje;
    char tip;
    char pol;
    char ime[15];
    Datum vakcina;

public:
    char getTip()
    {
        return tip;
    }

    Datum getVakcina()
    {
        return vakcina;
    }

public:
    Zivotno(const Datum& ragjanje, const Datum& donesuvanje, char tip, char pol, const char* ime, const Datum& vakcina)
    {
        this->ragjanje = ragjanje;
        this->donesuvanje = donesuvanje;
        this->tip = tip;
        this->pol = pol;
        std::strcpy(this->ime, ime);
        this->vakcina = vakcina;
    }

    friend std::ostream& operator<<(std::ostream& os, const Zivotno& z)
    {
        return os << std::setw(15) << std::left << z.ragjanje
                  << std::setw(15) << std::left << z.donesuvanje
                  << std::setw(5) << std::left << z.tip
                  << std::setw(5) << std::left << z.pol
                  << std::setw(20) << std::left << z.ime
                  << std::setw(15) << std::left << z.vakcina;
    }

    static void printHeader()
    {
        std::cout << std::setw(15) << std::left << "Ragjanje"
                  << std::setw(15) << std::left << "Donesuvanje"
                  << std::setw(5) << std::left << "Tip"
                  << std::setw(5) << std::left << "Pol"
                  << std::setw(20) << std::left << "Ime"
                  << std::setw(15) << std::left << "Vakcina" << std::endl;
    }
};

class Zooloska
{
private:
    Zivotno** zivotni;
    int brojZivotni;

public:
    Zooloska()
    {
        brojZivotni = 0;
        zivotni = new Zivotno*[1000];

    }

    ~Zooloska()
    {
        for (int i=0;i<brojZivotni;++i)
            delete zivotni[i];
        delete[] zivotni;
    }

    Zooloska(const Zooloska& z) = delete;
    Zooloska& operator=(const Zooloska& z) = delete;

    void dodadiZivotno(Zivotno* z)
    {
        zivotni[brojZivotni++] = z;
    }

    void pecatiBrojZivotni()
    {
        std::cout << "Broj na zivotni: " << brojZivotni << std::endl;
    }

    void pecatiSiteZivotni()
    {
        if (brojZivotni > 0)
        {
            Zivotno::printHeader();
            for (int i=0;i<brojZivotni;++i)
            {
                Zivotno* z = zivotni[i];
                std::cout << *z << std::endl;
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
            Zivotno::printHeader();
            for (int i=0;i<brojZivotni;++i)
            {
                Zivotno* z = zivotni[i];
                if (z->getTip() == grupa)
                    std::cout << *z << std::endl;
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
            Datum d;
            std::cout << "Vnesete denesen datum (dd mm yyyy): ";
            std::cin >> d;

            Zivotno::printHeader();
            for (int i=0;i<brojZivotni;++i)
            {
                Zivotno* z = zivotni[i];

                int daysDate = Datum::days(d);
                int daysVak = Datum::days(z->getVakcina());

                switch (z->getTip())
                {
                    case 'c':
                    {
                        if ((daysDate - daysVak) - 365 - 7 <= 0)
                            std::cout << *z << std::endl;
                        break;
                    }
                    case 'v':
                    {
                        if ((daysDate - daysVak) - 243 - 7 <= 0)
                            std::cout << *z << std::endl;
                        break;
                    }
                    case 'p':
                    {
                        if ((daysDate - daysVak) - 182 - 7 <= 0)
                            std::cout << *z << std::endl;
                        break;
                    }
                }
            }
        }
        else
        {
            std::cout << "Nema nitu edno zivotno vo zooloskata" << std::endl;
        }
    }

    void novoZivotno()
    {
        Datum ragjanje;
        Datum donesuvanje;
        char tip;
        char pol;
        char ime[15];
        Datum vakcinacija;

        std::cout << "Vnesete datum na ragjanje (dd mm yyyy): ";
        std::cin >> ragjanje;
        std::cout << "Vnesete datum na donesuvanje (dd mm yyyy): ";
        std::cin >> donesuvanje;
        std::cout << "Vnesete tip (c-cicaci, v-vlekaci, p-ptici): ";
        std::cin >> tip;
        std::cout << "Vnesete pol (m-masko, z-zensko): ";
        std::cin >> pol;
        std::cout << "Vnesete pol ime: ";
        std::cin >> ime;
        std::cout << "Vnesete datum na posledna vakcinacija (dd mm yyyy): ";
        std::cin >> vakcinacija;

        dodadiZivotno(new Zivotno(ragjanje, donesuvanje, tip, pol, ime, vakcinacija));
    }
};

void zadaca02_04()
{
    Zooloska zoo;
    zoo.dodadiZivotno(new Zivotno(Datum(13, 6, 2020), Datum(18, 8, 2020), 'c', 'm',     "Foka", Datum(27, 7, 2020)));
    zoo.dodadiZivotno(new Zivotno(Datum( 2, 7, 2020), Datum(18, 8, 2020), 'p', 'z',     "Orel", Datum(23, 8, 2020)));
    zoo.dodadiZivotno(new Zivotno(Datum( 8, 2, 2020), Datum(18, 8, 2020), 'v', 'z',    "Zmija", Datum( 4, 3, 2020)));
    zoo.dodadiZivotno(new Zivotno(Datum(24, 1, 2020), Datum(18, 8, 2020), 'c', 'z',    "Tigar", Datum(13, 2, 2020)));
    zoo.dodadiZivotno(new Zivotno(Datum(28, 3, 2020), Datum(18, 8, 2020), 'p', 'm',      "Buv", Datum( 8, 4, 2020)));
    zoo.dodadiZivotno(new Zivotno(Datum(16, 3, 2020), Datum(18, 8, 2020), 'v', 'm', "Krokodil", Datum(16, 4, 2020)));

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
            case 1: zoo.novoZivotno(); break;
            case 2: zoo.pecatiBrojZivotni(); break;
            case 3: zoo.pecatiZivotniGrupa(); break;
            case 4: zoo.pecatiSiteZivotni(); break;
            case 5: zoo.pecatiZivotniVakcinacija(); break;
        }
    }

    std::cout << std::endl;

}

#endif // T02_KLASI_H
