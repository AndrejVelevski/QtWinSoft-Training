#ifndef T10_ZADACI_VEZBANJE_H
#define T10_ZADACI_VEZBANJE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>

class Pravoagolnik3
{
private:
    double sirina;
    double dolzina;

public:
    Pravoagolnik3(double sirina, double dolzina)
    {
        this->sirina = sirina;
        this->dolzina = dolzina;
    }

    double plostina() const
    {
        return sirina * dolzina;
    }

    friend std::ostream& operator<<(std::ostream& os, const Pravoagolnik3 p)
    {
        return os << "Pravoagolnik(" << p.sirina << ", " << p.dolzina << ")";
    }
};

class Kvadrat3
{
private:
    double strana;

public:
    Kvadrat3(double strana)
    {
        this->strana = strana;
    }

    double plostina() const
    {
        return strana * strana;
    }

    friend std::ostream& operator<<(std::ostream& os, const Kvadrat3 k)
    {
        return os << "Kvadrat(" << k.strana << ")";
    }
};

void load(std::ifstream& is, std::vector<Kvadrat3>& kvadrati, std::vector<Pravoagolnik3>& pravoagolnici)
{
    int tip;

    while(is >> tip)
    {
        switch (tip)
        {
            case 1:
            {
                double sirina, dolzina;
                is >> sirina >> dolzina;
                pravoagolnici.push_back(Pravoagolnik3(sirina, dolzina));
                break;
            }
            case 2:
            {
                double strana;
                is >> strana;
                kvadrati.push_back(Kvadrat3(strana));
                break;
            }
            default:
            {
                std::stringstream ss;
                ss << "Nastana greska pri vcituvanje, tip mora da ima vrednost 1 ili 2, dobiena e " << tip;
                throw std::runtime_error(ss.str());
            }
        }
    }
}

void zadaca10_01()
{
    std::ifstream is("../STL_Training/zadaca10_01_source.txt");

    std::vector<Kvadrat3> kvadrati;
    std::vector<Pravoagolnik3> pravoagolnici;

    try
    {
        load(is, kvadrati, pravoagolnici);
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }

    for (Pravoagolnik3& p : pravoagolnici)
        std::cout << p << std::endl;

    for (Kvadrat3& k : kvadrati)
        std::cout << k << std::endl;
}

std::string pogodi(const std::string& zbor, const std::string& original)
{
    std::stringstream ss;

    for (char c : zbor)
    {
        if (c < 'a' || c > 'z')
        {
            std::stringstream es;
            es << "Zborot sodrzi drugi karakteri osven mali bukvi: " << c;
            throw std::logic_error(es.str());
        }

        if (std::find(original.begin(), original.end(), c) != original.end())
        {
            ss << c;
        }
        else
        {
            ss << '-';
        }
    }

    return ss.str();
}

void zadaca10_02()
{
    srand(time(0));

    int zivoti = 10;

    std::vector<std::string> zborovi = { "templejti", "parametri", "eksplicitna", "specijalizacija", "sekvencijalni", "kontejneri", "asocijativni",
                                         "algoritmi", "spravuvanje", "isklucoci", "stream", "input", "output", "zadaci", "vezbanje" };

    std::random_shuffle(zborovi.begin(), zborovi.end());

    std::string original = zborovi[0];

    while(true)
    {
        std::string zbor;

        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "Zivoti: " << zivoti << std::endl;
        std::cout << "Vnesi zbor: ";
        std::cin >> zbor;

        try {
            zbor = pogodi(zbor, original);
        }  catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            continue;
        }

        std::cout << "Vnesovte: " << zbor << std::endl;

        if (zbor == original)
        {
            std::cout << "Pobedivte!" << std::endl;
            break;
        }

        if (--zivoti == 0)
        {
            std::cout << "Izgubivte. Zborot beshe: " << original << std::endl;
            break;
        }
    }

    std::cout << std::endl;
}

#endif // T10_ZADACI_VEZBANJE_H
