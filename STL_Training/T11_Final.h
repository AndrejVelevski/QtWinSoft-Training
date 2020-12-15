#ifndef T11_FINAL_H
#define T11_FINAL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>

template<typename T>
class Pole
{
private:
    T* mData;
    int mSize;

public:
    int getSize() const
    {
        return mSize;
    }

    Pole(int size) :
        mSize(size)
    {
        mData = new T[size];
    }

    Pole(std::initializer_list<T> data)
    {
        mSize = data.size();
        mData = new T[mSize];

        std::copy(data.begin(), data.end(), mData);
    }

    ~Pole()
    {
        delete[] mData;
    }

    T& operator[](int index) const
    {
        return mData[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const Pole& p)
    {
        os << "(";
        for (int i=0;i<p.getSize();++i)
        {
            os << p[i];

            if (i == p.getSize()-1)
                os << ")";
            else
                os << ", ";
        }

        return os;
    }
};

template<typename T>
T max(Pole<T>& p)
{
    int maxIdx = 0;

    for (int i=1;i<p.getSize();++i)
    {
        if (p[i] > p[maxIdx])
            maxIdx = i;
    }

    return p[maxIdx];
}

void zadaca11_01()
{
    Pole intPole({4, 7, 2, 1, 6, 8, 2, 5, 7, 0});
    Pole charPole({'A', 'n', 'd', 'r', 'e', 'j'});
    Pole<std::string> stringPole({"Andrej", "Maja", "Kristina", "Marko", "Kosta", "Jovan", "Ana", "David" });
    //dokolku ne specifirav std::string kje gi zemeshe kako char* i kje go vrakjashe celo vreme posledniot element

    std::cout << intPole << std::endl;
    std::cout << charPole << std::endl;
    std::cout << stringPole << std::endl;

    std::cout << "Max value: " << max(intPole) << std::endl;
    std::cout << "Max value: " << max(charPole) << std::endl;
    std::cout << "Max value: " << max(stringPole) << std::endl;

    std::cout << std::endl;
}

class Artikl
{
private:
    int id;
    int kolicestvo;
    double cena;

public:
    int getKolicestvo() const
    {
        return kolicestvo;
    }

    double getCena() const
    {
        return cena;
    }

    Artikl(int id, int kolicestvo, double cena)
    {
        this->id = id;
        this->kolicestvo = kolicestvo;
        this->cena = cena;
    }

    static void printHeader()
    {
        std::cout << "id\tkolicestvo\tcena";
    }

    friend std::ostream& operator<<(std::ostream& os, const Artikl& a)
    {
        return os << a.id << "\t" << a.kolicestvo << "\t\t" << a.cena;
    }
};

void loadInventory(const std::string& path, std::vector<Artikl>& artikli)
{
    std::ifstream is(path);

    if (!is.good())
    {
        std::stringstream ss;
        ss << "Error loading file: " << path;
        throw std::runtime_error(ss.str());
    }

    int id, kolicestvo;
    double cena;

    while(is >> id >> kolicestvo >> cena)
    {
        artikli.push_back(Artikl(id, kolicestvo, cena));
    }

    is.close();
}

void zadaca11_02()
{
    std::vector<Artikl> artikli;

    try {
        loadInventory("../STL_Training/zadaca11_02_inventar.txt", artikli);
    }  catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }

    Artikl::printHeader();
    std::cout << std::endl;
    for (Artikl& a : artikli)
        std::cout << a << std::endl;

    std::cout << std::endl << "Artikli so kolicestvo pomalo od 10 i vkupna cena:" << std::endl;
    Artikl::printHeader();
    std::cout << "\tvkupno" << std::endl;
    std::for_each(artikli.begin(), artikli.end(), [](Artikl& a){
        if (a.getKolicestvo() < 10)
            std::cout << a << "\t" << a.getCena()*a.getKolicestvo() << std::endl;
    });

    std::cout << std::endl;
}

#endif // T11_FINAL_H
