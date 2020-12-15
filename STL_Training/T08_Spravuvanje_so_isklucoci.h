#ifndef T08_SPRAVUVANJE_SO_ISKLUCOCI_H
#define T08_SPRAVUVANJE_SO_ISKLUCOCI_H

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <windows.h>

class SizeMismatchException : public std::exception
{
private:
    std::string mMsg;

public:
    SizeMismatchException(const std::string& msg) :
        mMsg(msg)
    {

    }

    ~SizeMismatchException() throw()
    {

    };

    const char* what() const throw() override
    {
        return mMsg.c_str();
    };
};

template<typename T>
void copy(std::vector<T>& dest, std::vector<T> source)
{
    if (source.size() > dest.size())
    {
        std::stringstream ss;
        ss << "Vector 1 size(" << dest.size() << ") is smaller than Vector 2 size(" << source.size() << ")." << std::endl;
        throw SizeMismatchException(ss.str());
    }

    std::copy(source.begin(), source.end(), dest.begin());
}

void zadaca08_01()
{
    srand(time(0));

    int s1 = rand()%50+1;
    int s2 = rand()%50+1;

    std::vector<int> v1(s1);
    std::vector<int> v2(s2);

    std::fill(v1.begin(), v1.end(), 1);
    std::fill(v2.begin(), v2.end(), 2);

    std::cout << "Before trying to copy..." << std::endl;
    std::cout << "Vector 1: ";
    for (int i : v1)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "Vector 2: ";
    for (int i : v2)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "After trying to copy..." << std::endl;
    try
    {
        copy(v1, v2);
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 2);
        std::cout << "Success: Successful copying from Vector 2 to Vector 1." << std::endl;
        SetConsoleTextAttribute(hConsole, 7);

        std::cout << "Vector 1: ";
        for (int i : v1)
            std::cout << i << " ";
        std::cout << std::endl;

        std::cout << "Vector 2: ";
        for (int i : v2)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    catch (std::exception& e)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "Error: " << e.what() << std::endl;
        SetConsoleTextAttribute(hConsole, 7);
        return;
    }

    std::cout << std::endl;
}

class Foo
{
public:
    Foo()
    {
        std::cout << "Constructor" << std::endl;
    }

    ~Foo()
    {
        std::cout << "Destructor" << std::endl;
    }
};

void zadaca08_02()
{
    Foo* f = new Foo();

    try
    {
        throw f;
    }
    catch (Foo* f)
    {
        std::cout << "Pred da se ispecati ovaa linija imame throw f, i gledame deka ne e povikan destruktorot." << std::endl;
    }

    std::cout << std::endl;
}

class Motor
{
public:
    Motor()
    {
        std::cout << "Konstruktor na Motor" << std::endl;
        throw std::runtime_error("Isklucok frlen od Motor");
    }
};

class Avtomobil
{
public:
    Avtomobil()
    {
        std::cout << "Konstruktor na Avtomobil" << std::endl;
        Motor m;
    }
};

class Garaza
{
public:
    Garaza()
    {
        std::cout << "Konstruktor na Garaza" << std::endl;

        try {
            Avtomobil a;
        }  catch (std::exception& e) {
            std::cerr << "Catch vo Garaza: " << e.what() << std::endl;
            throw std::runtime_error("Isklucok frlen od Garaza");
        }
    }
};

void zadaca08_03()
{
    try {
        Garaza();
    }  catch (std::exception& e) {
        std::cout << "Catch vo main: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

#endif // T08_SPRAVUVANJE_SO_ISKLUCOCI_H
