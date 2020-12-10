#ifndef T01_TEMPLEJTI_H
#define T01_TEMPLEJTI_H

#include <iostream>

template <typename T>
void inputArray(T* list, int size)
{
    std::cout << "Vnesete " << size << " elementi: ";
    for (int i=0;i<size;++i)
        std::cin >> list[i];
}

template <typename T>
void printArray(T* list, int size)
{
    for (int i=0;i<size;++i)
        std::cout << list[i] << " ";
    std::cout << std::endl;
}

template <typename T>
void sortArray(T* list, int size)
{
    for (int i=0;i<size;++i)
    {
        int k = i;
        for (int j=i;j<size;++j)
        {
            if (list[j] < list[k])
                k = j;
        }

        T temp = list[i];
        list[i] = list[k];
        list[k] = temp;
    }
}

void zadaca01_01()
{
    int size;
    std::cout << "Vnesete golemina na nizata: ";
    std::cin >> size;

    int* intList = new int[size];
    double* doubleList = new double[size];

    inputArray(intList, size);
    inputArray(doubleList, size);

    std::cout << "Lista od int: " << std::endl;
    printArray(intList, size);
    std::cout << "Lista od double: " << std::endl;
    printArray(doubleList, size);

    std::cout << "Sortiranje..." << std::endl;
    sortArray(intList, size);
    sortArray(doubleList, size);

    std::cout << "Lista od int: " << std::endl;
    printArray(intList, size);
    std::cout << "Lista od double: " << std::endl;
    printArray(doubleList, size);

    delete[] intList;
    delete[] doubleList;

    std::cout << std::endl;
}

template <typename T>
int printArray(T* list, int size, int begin, int end)
{
    if (begin < 0 || end > size || begin >= end)
        return 0;

    for (int i=begin;i<end;++i)
        std::cout << list[i] << " ";
    std::cout << std::endl;

    return end - begin;
}

void zadaca01_02()
{
    int a[10], b[10], c[10];

    for (int i=0;i<10;++i)
    {
        a[i] = std::rand() % 100;
        b[i] = std::rand() % 100;
        c[i] = std::rand() % 100;
    }

    printArray(a, 10);
    printArray(b, 10);
    printArray(c, 10);

    int t1 = printArray(a, 10,  2,  8); std::cout << "Result a( 2,  8) = " << t1 << std::endl;
    int t2 = printArray(b, 10,  0, 10); std::cout << "Result b( 0, 10) = " << t2 << std::endl;
    int t3 = printArray(c, 10,  7,  3); std::cout << "Result c( 7,  3) = " << t3 << std::endl;
    int t4 = printArray(a, 10,  4,  4); std::cout << "Result a( 4,  4) = " << t4 << std::endl;
    int t5 = printArray(b, 10, -5,  3); std::cout << "Result b(-5,  3) = " << t5 << std::endl;
    int t6 = printArray(c, 10,  6, 12); std::cout << "Result c( 6, 12) = " << t6 << std::endl;

    std::cout << std::endl;
}

template<typename R, typename P>
//template<typename P, typename R>
R implicit_cast(const P& p)
{
    return p;
}

void zadaca01_03()
{
    int i = 1;
    float x = implicit_cast<float>(i);
    int j = implicit_cast<int>(x);

    j += 1;

    std::cout << "Ako gi zamenime gornite R i P, togas funkcijata implicit_cast\n"
                 "kje ocekuva objekt od tip P no dobiva objekt od tip R\n" << std::endl;
}

void printArray(int* list, int size, int columns)
{
    for (int i=0;i<size;++i)
    {
        std::cout << list[i] << "\t";
        if ((i+1)%columns == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

void zadaca01_04()
{
    int a[10];

    for (int i=0;i<10;++i)
        a[i] = std::rand() % 100;

    printArray(a, 10, 4);

    std::cout << std::endl;
}

template<class T>
class Array
{
private:
    T* data;
    int size;

public:
    Array(int size, bool random=false)
    {
        data = new T[size];
        this->size = size;

        if (random)
        {
            for (int i=0;i<size;++i)
                data[i] = ((float)rand()/RAND_MAX - 0.5f) * 200;
        }
    }

    ~Array()
    {
        delete[] data;
    }

    T& operator[](int i) const
    {
        return data[i];
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& a)
    {
        for (int i=0;i<a.size;++i)
            os << a[i] << " ";
        return os;
    }
};

void zadaca01_05()
{
    Array<int> intArray(10, true);
    Array<double> doubleArray(10, true);

    std::cout << intArray << std::endl;
    std::cout << doubleArray << std::endl;

    std::cout << std::endl;
}

#endif // T01_TEMPLEJTI_H
