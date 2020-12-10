#ifndef T02_PARAMETRI_KAJ_TEMPLEJTI_H
#define T02_PARAMETRI_KAJ_TEMPLEJTI_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include "T01_Templejti.h"

template<typename T>
T sum(T* array, int begin, int end, T optional = (T)0)
{
    for(int i=begin;i<end;++i)
        optional += array[i];
    return optional;
}

void zadaca02_01()
{
    double a[10];
    for (int i=0;i<10;++i)
        a[i] = ((double)rand()/RAND_MAX) * 100;

    printArray(a, 10);

    std::cout << "sum(a, 0, 10): " << sum(a, 0, 10) << std::endl;
    std::cout << "sum(a, 9, 10): " << sum(a, 9, 10) << std::endl;
    std::cout << "sum(a, 0, 10, 100): " << sum(a, 0, 10, 100.0) << std::endl;
    std::cout << "sum(a, 3, 7, 1000): " << sum(a, 3, 70, 1000.0) << std::endl;

    std::cout << std::endl;
}

template<class T>
class Kvadrat
{
private:
    T strana;

public:
    Kvadrat(){}

    Kvadrat(T strana)
    {
        this->strana = strana;
    }

    T plostina() const
    {
        return strana * strana;
    }

    friend std::ostream& operator<<(std::ostream& os, const Kvadrat& k)
    {
        return os << k.plostina();
    }
};

template<class T>
class Pravoagolnik
{
private:
    T sirina;
    T dolzina;

public:
    Pravoagolnik() {}

    Pravoagolnik(T sirina, T dolzina)
    {
        this->sirina = sirina;
        this->dolzina = dolzina;
    }

    T plostina() const
    {
        return sirina * dolzina;
    }

    friend std::ostream& operator<<(std::ostream& os, const Pravoagolnik& p)
    {
        return os << p.plostina();
    }
};


template<typename T>
void pecatiPole(T* array, int size)
{
    for (int i=0;i<size;++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

template <typename T>
void sortirajPole(T* array, int size)
{
    for (int i=0;i<size;++i)
    {
        int k = i;
        for (int j=i;j<size;++j)
        {
            if (array[j].plostina() < array[k].plostina())
                k = j;
        }

        T temp = array[i];
        array[i] = array[k];
        array[k] = temp;
    }
}

void zadaca02_02()
{
    Kvadrat<int> kvadrati[10];
    Pravoagolnik<int> pravoagolnici[10];

    for (int i=0;i<10;++i)
    {
        kvadrati[i] = Kvadrat<int>(rand()%9+1);
        pravoagolnici[i] = Pravoagolnik<int>(rand()%10, rand()%10);
    }

    std::cout << "Plostina na site kvadrati: " << std::endl;
    pecatiPole(kvadrati, 10);
    std::cout << "Plostina na site pravoagolnici: " << std::endl;
    pecatiPole(pravoagolnici, 10);

    std::cout << "Sortiranje po plostina..." << std::endl;
    sortirajPole(kvadrati, 10);
    sortirajPole(pravoagolnici, 10);

    std::cout << "Plostina na site kvadrati: " << std::endl;
    pecatiPole(kvadrati, 10);
    std::cout << "Plostina na site pravoagolnici: " << std::endl;
    pecatiPole(pravoagolnici, 10);

    std::cout << std::endl;
}

template<class T>
class Lice
{
private:


public:
    T kod;
    char* ime;
    char* prezime;

    Lice() {}

    Lice(T kod, char* ime, char* prezime)
    {
        this->kod = kod;
        this->ime = ime;
        this->prezime = prezime;
    }

    friend std::ostream& operator<<(std::ostream& os, const Lice<T>& l)
    {
        return os << "(" << l.kod << " " << l.ime << " " << l.prezime << ")";
    }
};

Lice<int> createLice(int kod, const char* ime, const char* prezime)
{
    int* k = new int;
    *k = kod;

    int li = std::strlen(ime);
    char* i = new char[li];
    std::strcpy(i, ime);

    int lp = std::strlen(prezime);
    char* p = new char[lp];
    std::strcpy(p, prezime);

    return Lice<int>(*k, i, p);
}

Lice<char*> createLice(const char* kod, const char* ime, const char* prezime)
{
    int lk = std::strlen(kod);
    char* k = new char[lk];
    std::strcpy(k, kod);

    int li = std::strlen(ime);
    char* i = new char[li];
    std::strcpy(i, ime);

    int lp = std::strlen(prezime);
    char* p = new char[lp];
    std::strcpy(p, prezime);

    return Lice<char*>(k, i, p);
}

void zadaca02_03()
{
    int iv = 0;
    int ik = 0;

    Lice<int> vraboteni[20];
    Lice<char*> klienti[20];

    vraboteni[iv++] = createLice(13, "Jovan", "Jovanovski");
    vraboteni[iv++] = createLice(6, "Maja", "Maevska");
    vraboteni[iv++] = createLice(782, "Kosta", "Kostovski");

    klienti[ik++] = createLice("AB123C", "Jovan", "Jovanovski");
    klienti[ik++] = createLice("kjsad", "Maja", "Maevska");
    klienti[ik++] = createLice("As231d", "Kosta", "Kostovski");

    std::cout << "Vraboteni: " << std::endl;
    pecatiPole(vraboteni, iv);

    std::cout << "Vraboteni: " << std::endl;
    pecatiPole(klienti, ik);

    std::cout << std::endl;
}

#endif // T02_PARAMETRI_KAJ_TEMPLEJTI_H
