#ifndef T03_EKSPLICITNA_SPECIJALIZACIJA_H
#define T03_EKSPLICITNA_SPECIJALIZACIJA_H

#include <iostream>
#include <cstring>

template<class T>
class Zapis
{
private:
    T x;
    T y;
    T z;

public:
    Zapis(T x, T y, T z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    T getX() const { return x; }
    T getY() const { return y; }
    T getZ() const { return z; }

    friend std::ostream& operator<<(std::ostream& os, const Zapis& z)
    {
        return os << "(" << z.x << ", " << z.y << ", " << z.z << ")";
    }
};

template<typename T>
bool kontroler(const Zapis<T>& zapis)
{
    return (zapis.getX() + zapis.getY() + zapis.getZ()) > 10000;
}

void zadaca03_01()
{
    for (int i=0;i<10;++i)
    {
        Zapis<int> z(rand()%6666, rand()%6666, rand()%6666);
        bool k = kontroler(z);
        std::cout << z << "\t" << k << std::endl;
    }

    for (int i=0;i<10;++i)
    {
        Zapis<double> z(((double)rand()/RAND_MAX)*6666.666, ((double)rand()/RAND_MAX)*6666.666, ((double)rand()/RAND_MAX)*6666.666);
        bool k = kontroler(z);
        std::cout << z << "\t" << k << std::endl;
    }

    std::cout << std::endl;
}

template<class T>
class Mnozestvo
{
private:
    T* data;
    int size; //nema smisla static da bide

public:
    int getSize() const
    {
        return size;
    }

    Mnozestvo()
    {
        data = nullptr;
        size = 0;
    }

    ~Mnozestvo()
    {
        delete[] data;
    }

    T& operator[](int i) const
    {
        return data[i];
    }

    bool exists(T value) const
    {
        if (data == nullptr)
            return false;

        for (int i=0;i<size;++i)
            if (data[i] == value)
                return true;
        return false;
    }

    T max() const
    {
        if (data == nullptr)
            throw "Nema elementi vo mnozestvoto";

        T m = data[0];

        for (int i=1;i<size;++i)
            if (data[i] > m)
                m = data[i];

        return m;
    }

    void add(T value)
    {
        if (data == nullptr)
        {
            data = new T[size+1];
            data[size++] = value;
            return;
        }

        if (exists(value))
            return;

        T* newData = new T[size+1];

        for (int i=0;i<size;++i)
            newData[i] = data[i];
        newData[size++] = value;

        delete[] data;

        data = newData;
    }


    friend std::ostream& operator<<(std::ostream& os, const Mnozestvo& m)
    {
        if (m.data == nullptr)
            return os;

        for (int i=0;i<m.size;++i)
            os << m[i] << " ";
        return os;
    }
};

template<>
class Mnozestvo<char*>
{
private:
    char** data;
    int size; //nema smisla static da bide

public:
    int getSize() const
    {
        return size;
    }

    Mnozestvo()
    {
        data = nullptr;
        size = 0;
    }

    ~Mnozestvo()
    {
        for (int i=0;i<size;++i)
            delete data[i];
        delete[] data;
    }

    char*& operator[](int i) const
    {
        return data[i];
    }

    bool exists(const char* value) const
    {
        if (data == nullptr)
            return false;

        for (int i=0;i<size;++i)
            if (std::strcmp(data[i], value) == 0)
                return true;
        return false;
    }

    char* max() const
    {
        if (data == nullptr)
            throw "Nema elementi vo mnozestvoto";

        char* m = data[0];

        for (int i=1;i<size;++i)
            if (std::strcmp(data[i], m) > 0)
                m = data[i];

        return m;
    }

    void add(const char* value)
    {
        int len = std::strlen(value);

        if (data == nullptr)
        {
            data = new char*[size+1];
            data[size] = new char[len+1];
            std::strcpy(data[size++], value);
            return;
        }


        if (exists(value))
            return;

        char** newData = new char*[size+1];

        for (int i=0;i<size;++i)
            newData[i] = data[i];

        newData[size] = new char[len+1];
        std::strcpy(newData[size++], value);

        delete[] data;

        data = newData;
    }


    friend std::ostream& operator<<(std::ostream& os, const Mnozestvo& m)
    {
        if (m.data == nullptr)
            return os;

        for (int i=0;i<m.size;++i)
            os << m[i] << " ";
        return os;
    }
};

void zadaca03_02()
{
    Mnozestvo<int> a;
    Mnozestvo<double> b;
    Mnozestvo<char*> c;

    a.add(4);
    a.add(8);
    a.add(2);
    a.add(13);

    b.add(3.64);
    b.add(3.14);
    b.add(5.82);
    b.add(0.36);

    c.add("Jovan");
    c.add("Maja");
    c.add("Kosta");
    c.add("Andrej");

    while(true)
    {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "1. Dodadi vo A" << std::endl;
        std::cout << "2. Dodadi vo B" << std::endl;
        std::cout << "3. Dodadi vo C" << std::endl;
        std::cout << "4. Prikazi go A" << std::endl;
        std::cout << "5. Prikazi go B" << std::endl;
        std::cout << "6. Prikazi go C" << std::endl;
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
                int value;
                std::cout << "Vnesete int: ";
                std::cin >> value;
                a.add(value);
                break;
            }
            case 2:
            {
                double value;
                std::cout << "Vnesete double: ";
                std::cin >> value;
                b.add(value);
                break;
            }
            case 3:
            {
                char value[1000];
                std::cout << "Vnesete string: ";
                std::cin >> value;
                c.add(value);
                break;
            }
            case 4: std::cout << a << std::endl; break;
            case 5: std::cout << b << std::endl; break;
            case 6: std::cout << c << std::endl; break;
            case 7: std::cout << "A: " << a.max() << ", B: " << b.max() << ", C: " << c.max() << std::endl; break;
            case 8: std::cout << "A: " << a.getSize() << ", B: " << b.getSize() << ", C: " << c.getSize() << std::endl; break;
        }
    }

    std::cout << std::endl;
}

#endif // T03_EKSPLICITNA_SPECIJALIZACIJA_H
