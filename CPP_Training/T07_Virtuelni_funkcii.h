#ifndef T07_VIRTUELNI_FUNKCII_H
#define T07_VIRTUELNI_FUNKCII_H

#include <iomanip>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Datum.h"

class Zivotno2
{
protected:
    Datum ragjanje;
    Datum donesuvanje;
    char pol;
    char ime[15];
    Datum vakcina;

public:
    Datum getVakcina()
    {
        return vakcina;
    }

public:
    virtual char getTip() = 0;

    Zivotno2(const Datum& ragjanje, const Datum& donesuvanje, char pol, const char* ime, const Datum& vakcina)
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

    virtual bool presmetajVakcinacija(const Datum& d) = 0;
};

class Vlekaci : public Zivotno2
{
private:
    Datum slednaVakcina;

public:
    inline static const char tip = 'v';

    char getTip() override
    {
        return tip;
    }

    Vlekaci(const Datum& ragjanje, const Datum& donesuvanje, char pol, const char* ime, const Datum& vakcina, const Datum& slednaVakcina) :
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

    bool presmetajVakcinacija(const Datum& d) override
    {
        return ((Datum::days(d) - Datum::days(vakcina)) - 243 - 7 <= 0);
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

    Ptici(const Datum& ragjanje, const Datum& donesuvanje, char pol, const char* ime, const Datum& vakcina, char letac) :
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

    bool presmetajVakcinacija(const Datum& d) override
    {
        return ((Datum::days(d) - Datum::days(vakcina)) - 182 - 7 <= 0);
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

    Cicaci(const Datum& ragjanje, const Datum& donesuvanje, char pol, const char* ime, const Datum& vakcina, char prezivar) :
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

    bool presmetajVakcinacija(const Datum& d) override
    {
        return ((Datum::days(d) - Datum::days(vakcina)) - 365 - 7 <= 0);
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
        Datum ragjanje;
        Datum donesuvanje;
        char tip;
        char pol;
        char ime[15];
        Datum vakcinacija;
        Datum sledna;
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
            Datum d;
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
    zoo.dodadiZivotno(new Cicaci (Datum(13, 6, 2020), Datum(18, 8, 2020), 'm',     "Foka", Datum(27, 7, 2020), 'n'));
    zoo.dodadiZivotno(new Ptici  (Datum( 2, 7, 2020), Datum(18, 8, 2020), 'z',     "Orel", Datum(23, 8, 2020), 'd'));
    zoo.dodadiZivotno(new Vlekaci(Datum( 8, 2, 2020), Datum(18, 8, 2020), 'z',    "Zmija", Datum( 4, 3, 2020), Datum(25, 9, 2020)));
    zoo.dodadiZivotno(new Cicaci (Datum(24, 1, 2020), Datum(18, 8, 2020), 'z',    "Tigar", Datum(13, 2, 2020), 'n'));
    zoo.dodadiZivotno(new Ptici  (Datum(28, 3, 2020), Datum(18, 8, 2020), 'm',      "Buv", Datum( 8, 4, 2020), 'd'));
    zoo.dodadiZivotno(new Vlekaci(Datum(16, 3, 2020), Datum(18, 8, 2020), 'm', "Krokodil", Datum(16, 4, 2020), Datum(4, 9, 2020)));

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
