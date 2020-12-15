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

class my_exception : public std::exception {
  private:
    std::string err_msg;

  public:
    my_exception(const char *msg) : err_msg(msg) {};
    ~my_exception() throw() {};
    const char *what() const throw() { return this->err_msg.c_str(); };
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

#endif // T08_SPRAVUVANJE_SO_ISKLUCOCI_H
