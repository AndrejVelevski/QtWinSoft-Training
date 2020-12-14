#ifndef T05_SEKVENCIJALNI_KONTEJNERI_H
#define T05_SEKVENCIJALNI_KONTEJNERI_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>
#include <cmath>
#include <set>

template<typename T>
bool palindrom(const std::vector<T>& v)
{
    int s = v.size();
    for (int i=0;i<s/2;++i)
        if (v[i] != v[s-1-i])
            return false;

    return true;
}

template<typename T>
void print(const T& container)
{
    for (auto i=container.begin(); i!= container.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
}

void zadaca05_01()
{
    std::vector<int> a = { 1, 2, 3, 4, 4, 3, 2, 1 };
    std::vector<int> b = { 1, 2, 3, 4, 5, 3, 2, 1 };

    std::vector<std::string> c = { "ab", "dsad", "aaa", "asdsad", "aaa", "dsad", "ab" };
    std::vector<std::string> d = { "ab", "dsad", "aaa", "asdsad", "bbb", "dsad", "ab" };

    std::cout << "A: "; print(a);
    std::cout << "B: "; print(b);
    std::cout << "C: "; print(c);
    std::cout << "D: "; print(d);

    std::cout << "Palindrom A: " << palindrom(a) << std::endl;
    std::cout << "Palindrom B: " << palindrom(b) << std::endl;
    std::cout << "Palindrom C: " << palindrom(c) << std::endl;
    std::cout << "Palindrom D: " << palindrom(d) << std::endl;

    std::cout << std::endl;
}

void zadaca05_02()
{
    std::list<std::string> a = { "something@domain.com", "hello@domain.com", "standard@domain.com", "template@domain.com", "library@domain.com", "hello@domain.com"};
    std::list<std::string> b = { "sequential@domain.com", "container@domain.com", "sequential@domain.com", "container@domain.com", "adapter@domain.com", "hello@domain.com"};
    std::list<std::string> c = { "michael@domain.com", "james@domain.com", "thomas@domain.com", "hello@domain.com", "richard@domain.com", "jason@domain.com", "thomas@domain.com"};
    std::list<std::string> result;

    for(const std::string& s : a)
        if (!(std::find(result.begin(), result.end(), s) != result.end()))
            result.push_back(s);
    for(const std::string& s : b)
        if (!(std::find(result.begin(), result.end(), s) != result.end()))
            result.push_back(s);
    for(const std::string& s : c)
        if (!(std::find(result.begin(), result.end(), s) != result.end()))
            result.push_back(s);

    std::cout << "A: "; print(a);
    std::cout << "B: "; print(b);
    std::cout << "C: "; print(c);
    std::cout << "Result: "; print(result);

    std::cout << std::endl;
}

void zadaca05_03()
{
    std::deque<int> d = { 3, 8, 1, 2, 9, 0, 4, 7, 2 };
    std::vector<int> v;

    std::cout << "deque: "; print(d);

    while (!d.empty())
    {
        v.push_back(d.back());
        d.pop_back();
    }

    std::cout << "vector reversed: "; print(v);

    std::cout << std::endl;
}

template<class T>
class Oblik
{
    virtual T plostina() const = 0;
};

template<class T>
class Kvadrat2 : public Oblik<T>
{
private:
    T strana;

public:
    Kvadrat2(T strana)
    {
        this->strana = strana;
    }

    T plostina() const override
    {
        return strana * strana;
    }

    bool operator<(Kvadrat2 k) const
    {
        return strana < k.strana;
    }

    friend std::ostream& operator<<(std::ostream& os, const Kvadrat2& k)
    {
        return os << "Kvad(" << k.strana << ")";
    }
};

template<class T>
class Pravoagolnik2 : public Oblik<T>
{
private:
    T sirina;
    T dolzina;

public:
    Pravoagolnik2(T sirina, T dolzina)
    {
        this->sirina = sirina;
        this->dolzina = dolzina;
    }

    T plostina() const override
    {
        return sirina * dolzina;
    }

    bool operator<(Pravoagolnik2 p) const
    {
        return plostina() < p.plostina();
    }

    friend std::ostream& operator<<(std::ostream& os, const Pravoagolnik2& p)
    {
        return os << "Prav(" << p.sirina << ", " << p.dolzina << ")";
    }
};

template<class T>
class Krug2 : public Oblik<T>
{
private:
    T radius;

public:
    Krug2(T radius)
    {
        this->radius = radius;
    }

    T plostina() const override
    {
        return radius * radius * M_PI;
    }

    bool operator<(Krug2 k) const
    {
        return radius < k.radius;
    }

    friend std::ostream& operator<<(std::ostream& os, const Krug2& k)
    {
        return os << "Krug(" << k.radius << ")";
    }
};

template<class T>
class Mnozestvo2
{
private:
    std::set<T> set;

public:
    Mnozestvo2(){};

    void add(const T& value)
    {
        set.insert(value);
    }

    void print() const
    {
        ::print(set);
    }

    int size() const
    {
        return set.size();
    }

    T max() const
    {
        return *set.rbegin();
    }
};

void zadaca05_04()
{
    Mnozestvo2<Kvadrat2<double>> kvadrati;
    Mnozestvo2<Pravoagolnik2<double>> pravoagolnici;
    Mnozestvo2<Krug2<double>> krugovi;

    kvadrati.add(Kvadrat2<double>(9));
    kvadrati.add(Kvadrat2<double>(4));
    kvadrati.add(Kvadrat2<double>(3));
    kvadrati.add(Kvadrat2<double>(8));

    pravoagolnici.add(Pravoagolnik2<double>(1, 3));
    pravoagolnici.add(Pravoagolnik2<double>(3, 7));
    pravoagolnici.add(Pravoagolnik2<double>(6, 2));
    pravoagolnici.add(Pravoagolnik2<double>(5, 9));

    krugovi.add(Krug2<double>(6));
    krugovi.add(Krug2<double>(7));
    krugovi.add(Krug2<double>(2));
    krugovi.add(Krug2<double>(5));

    kvadrati.max();

    while(true)
    {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "1. Dodadi kvadrat" << std::endl;
        std::cout << "2. Dodadi pravoagolnik" << std::endl;
        std::cout << "3. Dodadi krug" << std::endl;
        std::cout << "4. Prikazi kvadrati" << std::endl;
        std::cout << "5. Prikazi pravoagolnici" << std::endl;
        std::cout << "6. Prikazi krugovi" << std::endl;
        std::cout << "7. Prikazi najgolemi elementi" << std::endl;
        std::cout << "8. Prikazi broj na elementi" << std::endl;
        std::cout << "9. Izlez" << std::endl;
        std::cout << "Opcija: ";

        int opcija;
        std::cin >> opcija;

        if (opcija == 9)
            break;

        switch (opcija)
        {
            case 1:
            {
                double strana;
                std::cout << "Vnesete strana: ";
                std::cin >> strana;
                kvadrati.add(Kvadrat2<double>(strana));
                break;
            }
            case 2:
            {
                double sirina, dolzina;
                std::cout << "Vnesete sirina: ";
                std::cin >> sirina;
                std::cout << "Vnesete dolzina: ";
                std::cin >> dolzina;
                pravoagolnici.add(Pravoagolnik2<double>(sirina, dolzina));
                break;
            }
            case 3:
            {
                double radius;
                std::cout << "Vnesete radius: ";
                std::cin >> radius;
                krugovi.add(Krug2<double>(radius));
                break;
            }
            case 4: kvadrati.print(); break;
            case 5: pravoagolnici.print(); break;
            case 6: krugovi.print(); break;
            case 7: std::cout << "Kvadrat: " << kvadrati.max() << ", Pravoagolnik: " << pravoagolnici.max() << ", Krug: " << krugovi.max() << std::endl; break;
            case 8: std::cout << "Kvadrati: " << kvadrati.size() << ", Pravoagolnici: " << pravoagolnici.size() << ", Krugovi: " << krugovi.size() << std::endl; break;
        }
    }

    kvadrati.print();
    pravoagolnici.print();
    krugovi.print();
}

#endif // T05_SEKVENCIJALNI_KONTEJNERI_H
