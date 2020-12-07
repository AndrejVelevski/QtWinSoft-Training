#ifndef T03_PRIJATELSKI_FUNKCII_I_DINAMICHKA_ALOKACIJA_H
#define T03_PRIJATELSKI_FUNKCII_I_DINAMICHKA_ALOKACIJA_H

#include <iostream>
#include <sstream>
#include <cstring>

class Covek
{
private:
    char ime[15];
    char prezime[20];
    char adresa[30];
    char broj[15];

public:
    Covek() {}

    Covek(const char* ime, const char* prezime, const char* adresa, const char* broj)
    {
        std::strcpy(this->ime, ime);
        std::strcpy(this->prezime, prezime);
        std::strcpy(this->adresa, adresa);
        std::strcpy(this->broj, broj);
    }

    friend std::ostream& operator<<(std::ostream& os, const Covek& c)
    {
        return os << c.ime << " " << c.prezime << " " << c.adresa << " " << c.broj;
    }
};

class Stedac2
{
private:
    Covek lice;
    double bilans;
    double kredit;

public:
    inline static double kamata;
    inline static int brojStedaci;

    Stedac2(const char* ime, const char* prezime, const char* adresa, const char* broj, double bilans, double kredit)
    {
        lice = Covek(ime, prezime, adresa, broj);
        this->bilans = bilans;
        this->kredit = kredit;

        ++brojStedaci;
        kamata += bilans*kredit;
    }

    ~Stedac2()
    {
        --brojStedaci;
        kamata -= bilans*kredit;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stedac2& s)
    {
        return os << s.lice << " " << s.bilans << " " << s.kredit;
    }
};

void zadaca03_01()
{
    Stedac2 s1("Jovan", "Jovanovski", "st. SomeAddress 123/1", "071-234-567", 17800, 1.14);
    std::cout << s1 << " | Vkupna kamata: " << Stedac2::kamata << " | Vkupno stedaci: " << Stedac2::brojStedaci << std::endl;
    Stedac2 s2("Ana", "Anevska", "st. st. SomeAddress 41\\5\\7", "071/234/567", 38400, 0.68);
    std::cout << s2 << " | Vkupna kamata: " << Stedac2::kamata << " | Vkupno stedaci: " << Stedac2::brojStedaci << std::endl;
    Stedac2 s3("Angel", "Angelovski", "st. SomeAddress 41\\5\\7", "071 234 567", 30000, 3.1);
    std::cout << s3 << " | Vkupna kamata: " << Stedac2::kamata << " | Vkupno stedaci: " << Stedac2::brojStedaci << std::endl;
    std::cout << "Nov scope" << std::endl;
    {
        Stedac2 s4("Maja", "Maevska", "st. SomeAddress 30", "071-234-567", 23480, 2.14);
        std::cout << s3 << " | Vkupna kamata: " << Stedac2::kamata << " | Vkupno stedaci: " << Stedac2::brojStedaci << std::endl;
        Stedac2 s5("Kosta", "Kostovski", "st. SomeAddress 12.58A", "071/234/567", 25700, 0.07);
        std::cout << s4 << " | Vkupna kamata: " << Stedac2::kamata << " | Vkupno stedaci: " << Stedac2::brojStedaci << std::endl;
        Stedac2 s6("Jana", "Janevska", "st. SomeAddress 222HB2", "071 234 567", 31500, 0.93);
        std::cout << s5 << " | Vkupna kamata: " << Stedac2::kamata << " | Vkupno stedaci: " << Stedac2::brojStedaci << std::endl;
    }
    std::cout << "Izlez od scope" << std::endl;
    std::cout << "Vkupna kamata: " << Stedac2::kamata << " | Vkupno stedaci: " << Stedac2::brojStedaci << std::endl;

    std::cout << std::endl;
}


#endif // T03_PRIJATELSKI_FUNKCII_I_DINAMICHKA_ALOKACIJA_H
