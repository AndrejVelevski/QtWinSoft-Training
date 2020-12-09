#ifndef T08_VEKTORI_I_STRINGOVI_H
#define T08_VEKTORI_I_STRINGOVI_H

#include <iostream>
#include <vector>
#include <algorithm>


int custom(std::string a, std::string b)
{
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    return a < b;
}

void printList(const std::vector<std::string>& list)
{
    for (std::string ime : list)
        std::cout << ime << " ";
    std::cout << std::endl;
}

//nemashe zadaci od ovoj del
void zadaca08_01()
{
    std::vector<std::string> list = { "Maja", "Jana", "Marko", "David", "Angela", "Andrej" };
    list.push_back("Bojan");
    list.push_back("Marija");
    list.push_back("Kristijan");
    list.push_back("Ana");

    printList(list);

    std::sort(list.begin(), list.end());
    printList(list);

    std::sort(list.begin(), list.end(), std::greater<std::string>());
    printList(list);

    std::sort(list.begin(), list.end(), custom);
    printList(list);

    std::cout << std::endl;
}

#endif // T08_VEKTORI_I_STRINGOVI_H
