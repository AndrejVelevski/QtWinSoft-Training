#ifndef T05_NASLEDUVANJE_H
#define T05_NASLEDUVANJE_H

#include <iomanip>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Datum.h"

class Profesor;

class Vraboten
{
protected:
    char ime[15];
    char prezime[20];
    int godinaVrabotuvanje;

public:
    Vraboten(const char* ime, const char* prezime, int godinaVrabotuvanje)
    {
        std::strcpy(this->ime, ime);
        std::strcpy(this->prezime, prezime);
        this->godinaVrabotuvanje = godinaVrabotuvanje;
    }

    virtual ~Vraboten() {}

    virtual void prikazi_podatoci() = 0;
};

class Profesor : public Vraboten
{
private:
    char zvanje[20];
    char oblast[20];
    int brojPredmeti;
public:
    Profesor(const char* ime, const char* prezime, int godinaVrabotuvanje, const char* zvanje, const char* oblast, int brojPredmeti) :
        Vraboten(ime, prezime, godinaVrabotuvanje)
    {
        std::strcpy(this->zvanje, zvanje);
        std::strcpy(this->oblast, oblast);
        this->brojPredmeti = brojPredmeti;
    }

    void prikazi_podatoci() override
    {
        std::cout << std::setw(15) << std::left << ime
                  << std::setw(20) << std::left << prezime
                  << std::setw(10) << std::left << godinaVrabotuvanje
                  << std::setw(20) << std::left << zvanje
                  << std::setw(20) << std::left << oblast
                  << std::setw(10) << std::left << brojPredmeti << std::endl;
    }
};

class Asistent : public Vraboten
{
private:
    char zvanje[20];
    char mentor[20];
    int brojPredmeti;
public:
    Asistent(const char* ime, const char* prezime, int godinaVrabotuvanje, const char* zvanje, const char* mentor, int brojPredmeti) :
        Vraboten(ime, prezime, godinaVrabotuvanje)
    {
        std::strcpy(this->zvanje, zvanje);
        std::strcpy(this->mentor, mentor);
        this->brojPredmeti = brojPredmeti;
    }

    void prikazi_podatoci() override
    {
        std::cout << std::setw(15) << std::left << ime
                  << std::setw(20) << std::left << prezime
                  << std::setw(10) << std::left << godinaVrabotuvanje
                  << std::setw(20) << std::left << zvanje
                  << std::setw(20) << std::left << mentor
                  << std::setw(10) << std::left << brojPredmeti << std::endl;
    }
};

class Demonstrator : public Vraboten
{
private:
    char rabotnoVreme[20];
public:
    Demonstrator(const char* ime, const char* prezime, int godinaVrabotuvanje, const char* rabotnoVreme) :
        Vraboten(ime, prezime, godinaVrabotuvanje)
    {
        std::strcpy(this->rabotnoVreme, rabotnoVreme);
    }

    void prikazi_podatoci() override
    {
        std::cout << std::setw(15) << std::left << ime
                  << std::setw(20) << std::left << prezime
                  << std::setw(10) << std::left << godinaVrabotuvanje
                  << std::setw(20) << std::left << rabotnoVreme << std::endl;
    }
};

void printVraboteni(Vraboten** vraboteni, int size)
{
    for (int i=0;i<size;++i)
    {
        Vraboten* v = vraboteni[i];
        v->prikazi_podatoci();
    }
}

void addVraboten(Vraboten** vraboteni, int& idx)
{
    std::cout << "Vnesetre tip na vraboten (0-profesor, 1-asistent, 2-demonstrator): ";
    int opcija;
    std::cin >> opcija;

    if (opcija < 0 || opcija > 2)
    {
        std::cout << "Pogresna opcija" << std::endl;
        return;
    }

    char ime[15];
    char prezime[20];
    int godina;

    char zvanje[20];
    char oblast[20];
    int brojPredmeti;

    char mentor[20];
    char rabotnoVreme[20];

    std::cout << "Vnesete ime: ";
    std::cin >> ime;
    std::cout << "Vnesete prezime: ";
    std::cin >> prezime;
    std::cout << "Vnesete godina: ";
    std::cin >> godina;



    if (opcija == 0)
    {
        std::cout << "Vnesete zvanje: ";
        std::cin >> zvanje;
        std::cout << "Vnesete oblast: ";
        std::cin >> oblast;
        std::cout << "Vnesete broj predmeti: ";
        std::cin >> brojPredmeti;
        vraboteni[idx++] = new Profesor(ime, prezime, godina, zvanje, oblast, brojPredmeti);
        return;
    }

    if (opcija == 1)
    {
        std::cout << "Vnesete zvanje: ";
        std::cin >> zvanje;
        std::cout << "Vnesete mentor: ";
        std::cin >> mentor;
        std::cout << "Vnesete broj predmeti: ";
        std::cin >> brojPredmeti;
        vraboteni[idx++] = new Asistent(ime, prezime, godina, zvanje, mentor, brojPredmeti);
        return;
    }

    if (opcija == 2)
    {
        std::cin.ignore();
        std::cout << "Vnesete rabotno vreme: ";
        std::cin.getline(rabotnoVreme, sizeof(rabotnoVreme));
        vraboteni[idx++] = new Demonstrator(ime, prezime, godina, rabotnoVreme);
        return;
    }
}

void zadaca05_01()
{
    int idx = 0;
    Vraboten** vraboteni = new Vraboten*[100];

    vraboteni[idx++] = new Profesor("Jovan", "Jovanovski", 2013, "Doktor", "Mrezi", 8);
    vraboteni[idx++] = new Asistent("Ana", "Anevska", 2015, "Magister", "Jovan", 3);
    vraboteni[idx++] = new Demonstrator("Angel", "Angelovski", 2017, "08:00 - 14:00");
    vraboteni[idx++] = new Profesor("Maja", "Maevska", 2011, "Doktor", "Kriptografija", 6);
    vraboteni[idx++] = new Asistent("Kosta", "Kostovski", 2019, "Magister", "Maja", 4);
    vraboteni[idx++] = new Demonstrator("Jana", "Janevska", 2020, "12:00 - 20:00");

    while(true)
    {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "1 - pecati vraboteni" << std::endl;
        std::cout << "2 - dodadi vraboten" << std::endl;
        std::cout << "3 - kraj" << std::endl;
        std::cout << "Opcija: ";
        int opcija;
        std::cin >> opcija;

        if (opcija == 3)
            break;

        switch (opcija)
        {
            case 1: printVraboteni(vraboteni, idx); break;
            case 2: addVraboten(vraboteni, idx); break;
        }

    }

    for (int i=0;i<idx;++i)
        delete vraboteni[i];
    delete[] vraboteni;

    std::cout << std::endl;
}

class Artikl
{
protected:
    char ime[20];
    int golemina;
    double cena;
    Datum donesen;

public:
    double getCena()
    {
        return cena;
    }

    Artikl(const char* ime, int golemina, double cena, const Datum& donesen)
    {
        std::strcpy(this->ime, ime);
        this->golemina = golemina;
        this->cena = cena;
        this->donesen = donesen;
    }

    virtual ~Artikl()
    {

    }

    static void prikazi_header()
    {
        std::cout << std::setw(20) << std::left << "Ime"
                  << std::setw(10) << std::left << "Golemina"
                  << std::setw(10) << std::left << "Cena"
                  << std::setw(20) << std::left << "Datum donesen"
                  << std::setw(20) << std::left << "Datum nabavka" << std::endl;


    }

    virtual void prikazi_podatoci()
    {
        std::cout << std::setw(20) << std::left << ime
                  << std::setw(10) << std::left << golemina
                  << std::setw(10) << std::left << cena
                  << std::setw(20) << std::left << donesen << std::endl;
    }

    virtual int getTip() = 0;

    bool presmetaj_nabavka(const Datum& d)
    {
        int daysDate = Datum::days(d);
        int daysNabavka = Datum::days(donesen);

        return ((daysDate - daysNabavka) - 7 <= 0);
    }

};

class Pantaloni : public Artikl
{
private:
    Datum nabavka;

public:
    inline const static int tip = 0;

    Pantaloni(const char* ime, int golemina, double cena, const Datum& donesen, const Datum& nabavka) :
        Artikl(ime, golemina, cena, donesen)
    {
        this->nabavka = nabavka;
    }

    void prikazi_podatoci() override
    {
        std::cout << std::setw(20) << std::left << ime
                  << std::setw(10) << std::left << golemina
                  << std::setw(10) << std::left << cena
                  << std::setw(20) << std::left << donesen
                  << std::setw(20) << std::left << nabavka << std::endl;
    }

    int getTip() override
    {
        return tip;
    }
};

class Kosuli : public Artikl
{
public:
    inline const static int tip = 1;

    Kosuli(const char* ime, int golemina, double cena, const Datum& donesen) :
        Artikl(ime, golemina, cena, donesen)
    {

    }

    int getTip() override
    {
        return tip;
    }
};

class Prodavnica
{
private:
    Artikl** artikli;
    int size;
public:
    Prodavnica()
    {
        artikli = new Artikl*[100];
        size = 0;
    }

    ~Prodavnica()
    {
        for (int i=0;i<size;++i)
            delete artikli[i];
        delete[] artikli;
    }

    void dodadiArtikl(Artikl* artikl)
    {
        artikli[size++] = artikl;
    }

    void dodadiArtikl()
    {
        std::cout << "Vnesete tip na artikl(0-pantaloni, 1-kosuli): ";
        int tip;
        std::cin >> tip;

        if (tip < 0 || tip > 1)
        {
            std::cout << "Pogresen tip" << std::endl;
            return;
        }

        char ime[20];
        int golemina;
        double cena;
        Datum donesen;
        Datum nabavka;

        std::cout << "Vnesete ime: ";
        std::cin >> ime;
        std::cout << "Vnesete golemina: ";
        std::cin >> golemina;
        std::cout << "Vnesete cena: ";
        std::cin >> cena;
        std::cout << "Vnesete datum koga e donesen (dd mm yyyy): ";
        std::cin >> donesen;

        if (tip == 0)
        {
            std::cout << "Vnesete datum na sledna nabavka (dd mm yyyy): ";
            std::cin >> nabavka;
            dodadiArtikl(new Pantaloni(ime, golemina, cena, donesen, nabavka));
            return;
        }
        dodadiArtikl(new Kosuli(ime, golemina, cena, donesen));
    }

    void prikaziArtikli()
    {
        Artikl::prikazi_header();
        double total = 0;
        for (int i=0;i<size;++i)
        {
            artikli[i]->prikazi_podatoci();
            total += artikli[i]->getCena();
        }
        std::cout << "Vkupnata cena na site artikli iznesuva " << total << std::endl;
    }

    void prikaziArtikliGrupa()
    {
        std::cout << "Vnesete tip na artikl(0-pantaloni, 1-kosuli): ";
        int tip;
        std::cin >> tip;

        if (tip < 0 || tip > 1)
        {
            std::cout << "Pogresen tip" << std::endl;
            return;
        }

        Artikl::prikazi_header();
        double total = 0;
        for (int i=0;i<size;++i)
        {
            if (artikli[i]->getTip() == tip)
            {
                artikli[i]->prikazi_podatoci();
                total += artikli[i]->getCena();
            }
        }
        std::cout << "Vkupnata cena na artiklite od ovaa grupa iznesuva " << total << std::endl;
    }

    void prikaziArtikliNabavkaNedela()
    {
        Datum d;
        std::cout << "Vnesete denesen datum (dd mm yyyy): ";
        std::cin >> d;

        Artikl::prikazi_header();
        double total = 0;
        for (int i=0;i<size;++i)
        {
            if (artikli[i]->presmetaj_nabavka(d))
            {
                artikli[i]->prikazi_podatoci();
                total += artikli[i]->getCena();
            }
        }
        std::cout << "Vkupnata cena na artiklite koi treba da se nabavat iznesuva " << total << std::endl;
    }
};

void zadaca05_02()
{
    Prodavnica prodavnica;

    prodavnica.dodadiArtikl(new Pantaloni("Pant A", 36, 36.84, Datum(24,3,2020), Datum(13,5,2020)));
    prodavnica.dodadiArtikl(new Kosuli("Kosula A", 32, 38.29, Datum(13,4,2020)));
    prodavnica.dodadiArtikl(new Pantaloni("Pant B", 31, 28.32, Datum(8,2,2020), Datum(23,8,2020)));
    prodavnica.dodadiArtikl(new Kosuli("Kosula B", 33, 29.99, Datum(5,7,2020)));
    prodavnica.dodadiArtikl(new Pantaloni("Pant C", 40, 33.51, Datum(7,6,2020), Datum(5,10,2020)));
    prodavnica.dodadiArtikl(new Kosuli("Kosula C", 38, 40.49, Datum(6,6,2020)));

    while(true)
    {
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "1 - dodadi nov artikl" << std::endl;
        std::cout << "2 - prikazi artikl od grupa" << std::endl;
        std::cout << "3 - prikazi cela lista" << std::endl;
        std::cout << "4 - prikazi artikli koi treba da se nabavat za 1 nedela" << std::endl;
        std::cout << "5 - izlez" << std::endl;
        std::cout << "Opcija: ";

        int opcija;
        std::cin >> opcija;

        if (opcija == 5)
        {
            break;
        }

        switch (opcija)
        {
            case 1: prodavnica.dodadiArtikl(); break;
            case 2: prodavnica.prikaziArtikliGrupa(); break;
            case 3: prodavnica.prikaziArtikli(); break;
            case 4: prodavnica.prikaziArtikliNabavkaNedela(); break;
        }
    }
}

#endif // T05_NASLEDUVANJE_H
