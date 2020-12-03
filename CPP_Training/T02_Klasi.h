#ifndef T02_KLASI_H
#define T02_KLASI_H

#include <iomanip>
#include <iostream>
#include <cstring>

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

#endif // T02_KLASI_H
