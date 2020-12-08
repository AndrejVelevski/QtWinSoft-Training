#ifndef T06_POVEKJEKRATNO_NASLEDUVANJE_H
#define T06_POVEKJEKRATNO_NASLEDUVANJE_H

#include <iomanip>
#include <iostream>
#include <cstring>
#include <sstream>

class Oblik
{
private:
    inline static int broj = 0;
protected:
    char ime[20];

public:
    Oblik(const char* ime)
    {
        std::strcpy(this->ime, ime);
        ++broj;
    }

    virtual ~Oblik(){}

    virtual void printName()
    {
        std::cout << ime << std::endl;
    }

    static int getBroj()
    {
        return broj;
    }
};

class DvoDimenzionalni : public Oblik
{
private:
    inline static int broj = 0;

public:
    DvoDimenzionalni(const char* ime) :
        Oblik(ime)
    {
        ++broj;
    }

    virtual ~DvoDimenzionalni(){}

    static int getBroj()
    {
        return broj;
    }
};

class TroDimenzionalni : public Oblik
{
private:
    inline static int broj = 0;

public:
    TroDimenzionalni(const char* ime) :
        Oblik(ime)
    {
        ++broj;
    }

    virtual ~TroDimenzionalni(){}

    static int getBroj()
    {
        return broj;
    }
};

class Kvadrat : public DvoDimenzionalni
{
private:
    inline static int broj = 0;

public:
    Kvadrat(const char* ime) :
        DvoDimenzionalni(ime)
    {
        ++broj;
    }

    static int getBroj()
    {
        return broj;
    }
};

class Krug : public DvoDimenzionalni
{
private:
    inline static int broj = 0;

public:
    Krug(const char* ime) :
        DvoDimenzionalni(ime)
    {
        ++broj;
    }

    static int getBroj()
    {
        return broj;
    }
};

class Triagolnik : public DvoDimenzionalni
{
private:
    inline static int broj = 0;

public:
    Triagolnik(const char* ime) :
        DvoDimenzionalni(ime)
    {
        ++broj;
    }

    static int getBroj()
    {
        return broj;
    }
};

class Pravoagolnik : public DvoDimenzionalni
{
private:
    inline static int broj = 0;

public:
    Pravoagolnik(const char* ime) :
        DvoDimenzionalni(ime)
    {
        ++broj;
    }

    static int getBroj()
    {
        return broj;
    }
};

class Prsten : public DvoDimenzionalni
{
private:
    inline static int broj = 0;

public:
    Prsten(const char* ime) :
        DvoDimenzionalni(ime)
    {
        ++broj;
    }

    static int getBroj()
    {
        return broj;
    }
};

class Kocka : public TroDimenzionalni
{
private:
    inline static int broj = 0;

public:
    Kocka(const char* ime) :
        TroDimenzionalni(ime)
    {
        ++broj;
    }

    static int getBroj()
    {
        return broj;
    }
};

class Sfera : public TroDimenzionalni
{
private:
    inline static int broj = 0;

public:
    Sfera(const char* ime) :
        TroDimenzionalni(ime)
    {
        ++broj;
    }

    static int getBroj()
    {
        return broj;
    }
};

class Cilinder : public TroDimenzionalni
{
private:
    inline static int broj = 0;

public:
    Cilinder(const char* ime) :
        TroDimenzionalni(ime)
    {
        ++broj;
    }

    static int getBroj()
    {
        return broj;
    }
};

class Konus : public TroDimenzionalni
{
private:
    inline static int broj = 0;

public:
    Konus(const char* ime) :
        TroDimenzionalni(ime)
    {
        ++broj;
    }

    static int getBroj()
    {
        return broj;
    }
};

class Torus : public TroDimenzionalni
{
private:
    inline static int broj = 0;

public:
    Torus(const char* ime) :
        TroDimenzionalni(ime)
    {
        ++broj;
    }

    static int getBroj()
    {
        return broj;
    }
};

void zadaca06_01()
{
    int idx = 0;
    Oblik** oblici = new Oblik*[100];

    for (int i=0;i<100;++i)
    {
        int r = std::rand() % 10;

        switch (r)
        {
            case 0: oblici[idx++] = new Kvadrat("Kvadrat"); break;
            case 1: oblici[idx++] = new Krug("Krug"); break;
            case 2: oblici[idx++] = new Triagolnik("Triagolnik"); break;
            case 3: oblici[idx++] = new Pravoagolnik("Pravoagolnik"); break;
            case 4: oblici[idx++] = new Prsten("Prsten"); break;

            case 5: oblici[idx++] = new Kocka("Kocka"); break;
            case 6: oblici[idx++] = new Sfera("Sfera"); break;
            case 7: oblici[idx++] = new Cilinder("Cilinder"); break;
            case 8: oblici[idx++] = new Konus("Konus"); break;
            case 9: oblici[idx++] = new Torus("Torus"); break;
        }
    }

    for (int i=0;i<idx;++i)
        oblici[i]->printName();

    std::cout << "Broj na Oblici: " << Oblik::getBroj() << std::endl;
    std::cout << "Broj na Dvodimenzionalni oblici: " << DvoDimenzionalni::getBroj() << std::endl;
    std::cout << "Broj na Trodimenzionalni oblici: " << TroDimenzionalni::getBroj() << std::endl;

    std::cout << "Broj na Kvadrati: " << Kvadrat::getBroj() << std::endl;
    std::cout << "Broj na Krugovi: " << Krug::getBroj() << std::endl;
    std::cout << "Broj na Triagolnici: " << Triagolnik::getBroj() << std::endl;
    std::cout << "Broj na Pravoagolnici: " << Pravoagolnik::getBroj() << std::endl;
    std::cout << "Broj na Prsteni: " << Prsten::getBroj() << std::endl;

    std::cout << "Broj na Kocki: " << Kocka::getBroj() << std::endl;
    std::cout << "Broj na Sferi: " << Sfera::getBroj() << std::endl;
    std::cout << "Broj na Cilindri: " << Cilinder::getBroj() << std::endl;
    std::cout << "Broj na Konusi: " << Konus::getBroj() << std::endl;
    std::cout << "Broj na Torusi: " << Torus::getBroj() << std::endl;

    for (int i=0;i<idx;++i)
        delete oblici[i];
    delete[] oblici;

    std::cout << std::endl;
}

#endif // T06_POVEKJEKRATNO_NASLEDUVANJE_H
