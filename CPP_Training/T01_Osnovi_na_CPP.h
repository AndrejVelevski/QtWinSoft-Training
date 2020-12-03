#ifndef T01_OSNOVI_NA_CPP_H
#define T01_OSNOVI_NA_CPP_H

#include <iostream>
#include <cmath>

inline double circleArea(double radius)
{
       return radius*radius * M_PI;
}

int tripleCallByValue(int number)
{
    return 3 * number;
}

void tripleCallByReference(int& number)
{
    number *= 3;
}

void zadaca01_01()
{
    double radius;
    std::cout << "Vnesete broj: ";
    std::cin >> radius;
    std::cout << "Plostinata iznesuva: " << circleArea(radius) << std::endl;
}

void zadaca01_02()
{
    int number;
    std::cout << "Vnesete broj: ";
    std::cin >> number;

    std::cout << "Pred povik na tripleCallByValue: " << number << std::endl;
    number = tripleCallByValue(number);
    std::cout << "number = tripleCallByValue(number);\n"
                 "Po povik na tripleCallByValue: " << number << std::endl;
    tripleCallByReference(number);
    std::cout << "tripleCallByReference(number);\n"
                 "Po povik na tripleCallByReference: " << number << std::endl;
    std::cout << std::endl;
}

template <typename T>
T min(T val1, T val2)
{
    return val1<val2?val1:val2;
}

void zadaca01_03()
{
    int i1 = 7;
    int i2 = 5;
    float f1 = 4.572f;
    float f2 = 4.11235f;
    double d1 = 0.000001;
    double d2 = 0.000002;
    char c1 = 'A';
    char c2 = 'B';
    std::cout << "int: " << min(i1, i2) << ", " << min(i2, i1) << std::endl;
    std::cout << "float: " << min(f1, f2) << ", " << min(f2, f1) << std::endl;
    std::cout << "double: " << min(d1, d2) << ", " << min(d2, d1) << std::endl;
    std::cout << "char: " << min(c1, c2) << ", " << min(c2, c1) << std::endl;
    std::cout << std::endl;
}

#endif // T01_OSNOVI_NA_CPP_H
