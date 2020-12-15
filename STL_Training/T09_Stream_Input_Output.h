#ifndef T09_STREAM_INPUT_OUTPUT_H
#define T09_STREAM_INPUT_OUTPUT_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

void zadaca09_01()
{
    int m, n;
    std::cout << "Vnesete broj na vrednosti: ";
    std::cin >> n;
    std::cout << "Vnesete sirina na kolonite: ";
    std::cin >> m;


    auto w = std::setw(m);
    auto f = std::left;

    for (int i=1;i<=n;++i)
    {
        std::cout << w << f << i
                  << w << f << i*i
                  << w << f << std::sqrt(i)
                  << w << f << std::pow(i, 1.0/3.0)
                  << std::endl;
    }

    std::cout << std::endl;
}

void zadaca09_02()
{
    std::ifstream is("../STL_Training/zadaca09_02_source.txt");
    std::ofstream os("../STL_Training/zadaca09_02_dest.txt");

    std::string word;
    std::string line;

    while(std::getline(is, line))
    {
        std::stringstream ss(line);

        while(ss >> word)
        {
            if (word.length() <= 5)
            {
                std::cout << word << " ";
                os << word << " ";
            }
        }

        std::cout << std::endl;
        os << std::endl;
    }

    is.close();
    os.close();

    std::cout << std::endl;
}

#endif // T09_STREAM_INPUT_OUTPUT_H
