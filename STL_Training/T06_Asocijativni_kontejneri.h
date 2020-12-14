#ifndef T06_ASOCIJATIVNI_KONTEJNERI_H
#define T06_ASOCIJATIVNI_KONTEJNERI_H

#include <iostream>
#include <set>
#include "T05_Sekvencijalni_kontejneri.h"
#include <vector>
#include <queue>
#include <sstream>

class Uplata
{
private:
    std::string ime;
    std::string prezime;
    double iznos;

public:
    Uplata(const std::string& ime, const std::string& prezime, double iznos)
    {
        this->ime = ime;
        this->prezime = prezime;
        this->iznos = iznos;
    }

    bool operator==(const Uplata& uplata) const
    {
        return  (ime == uplata.ime && prezime == uplata.prezime);
    }

    bool operator<(const Uplata& uplata) const
    {
        return ime < uplata.ime;
    }

    friend std::ostream& operator<<(std::ostream& os, const Uplata& u)
    {
        return os << u.ime << " " << u.prezime << " " << u.iznos;
    }
};

class Banka
{
private:
    std::multiset<Uplata> mUplati;

public:
    Banka(){}

    void uplati(const Uplata& u)
    {
        mUplati.insert(u);
    }

    void uplati()
    {
        std::string ime, prezime;
        double iznos;

        std::cout << "Vnesete ime: ";
        std::cin >> ime;
        std::cout << "Vnesete prezime: ";
        std::cin >> prezime;
        std::cout << "Vnesete iznos: ";
        std::cin >> iznos;

        uplati(Uplata(ime, prezime, iznos));
    }

    void prikazi()
    {
        std::string ime, prezime;

        std::cout << "Vnesete ime: ";
        std::cin >> ime;
        std::cout << "Vnesete prezime: ";
        std::cin >> prezime;

        Uplata temp(ime, prezime, 0);

        for (const Uplata& u : mUplati)
        {
            if (u == temp)
                std::cout << u << std::endl;
        }
    }
};

void zadaca06_01()
{
    Banka banka;

    banka.uplati(Uplata("Jovan", "Jovanovski", 1234));
    banka.uplati(Uplata("Maja", "Maevska", 378));
    banka.uplati(Uplata("Kosta", "Kostovski", 995));
    banka.uplati(Uplata("Jana", "Janevska", 213));
    banka.uplati(Uplata("Nikola", "Nikolovski", 1540));
    banka.uplati(Uplata("Jovan", "Jovanovski", 738));
    banka.uplati(Uplata("Jovan", "Jovanovski", 246));
    banka.uplati(Uplata("Maja", "Maevska", 378));
    banka.uplati(Uplata("Maja", "Maevska", 613));
    banka.uplati(Uplata("Jana", "Janevska", 666));
    banka.uplati(Uplata("Maja", "Maevska", 1444));

    while(true)
    {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "1 - Dodadi uplata" << std::endl;
        std::cout << "2 - Prikazi uplata" << std::endl;
        std::cout << "3 - Kraj" << std::endl;
        std::cout << "Opcija: ";

        int opcija;
        std::cin >> opcija;

        if (opcija == 3)
            break;

        switch (opcija)
        {
            case 1: banka.uplati(); break;
            case 2: banka.prikazi(); break;
        }
    }

    std::cout << std::endl;
}

class Process
{
private:
    std::string mName;
    unsigned int mPriority;

public:
    Process(const std::string& name, unsigned int priority) :
        mName(name),
        mPriority(priority)
    {

    }

    bool operator<(const Process& p) const
    {
        return mPriority < p.mPriority;
    }

    friend std::ostream& operator<<(std::ostream& os, const Process& p)
    {
        return os << p.mName << "\t" << p.mPriority;
    }
};

void zadaca06_02()
{
    std::priority_queue<Process> processes;

    for (int i=0;i<20;++i)
    {
        std::stringstream ss;
        int len = rand() % 5 + 10;

        for(int j=0;j<len;++j)
        {
            char c = 'a' + rand()%26;
            ss << c;
        }

        processes.push(Process(ss.str(), rand() % 1000));
    }

    while(!processes.empty())
    {
        std::cout << processes.top() << std::endl;

        processes.pop();
    }

    std::cout << std::endl;
}

#endif // T06_ASOCIJATIVNI_KONTEJNERI_H
