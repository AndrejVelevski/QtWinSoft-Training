#ifndef T04_STANDARD_TEMPLATE_LIBRARY_H
#define T04_STANDARD_TEMPLATE_LIBRARY_H

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Imenik
{
private:
    std::string ime;
    std::string broj;

public:
    std::string getIme() const
    {
        return ime;
    }

    Imenik(const std::string& ime, const std::string& broj)
    {
        this->ime = ime;
        this->broj = broj;
    }

    friend std::ostream& operator<<(std::ostream& os, const Imenik& i)
    {
        return os << i.ime << " " << i.broj;
    }
};

void zadaca04_01()
{
    std::vector<Imenik> imenik = { Imenik("Jovan", "071 123 546"),
                                   Imenik("Maja", "072-123-546"),
                                   Imenik("David", "073/123/546"),
                                   Imenik("Kosta", "074123546"),
                                   Imenik("Andrej", "075\\123\\546") };

    std::cout << "Pre - sort" << std::endl;
    for (Imenik& i : imenik)
        std::cout << i << std::endl;
    std::cout << std::endl;

    std::sort(imenik.begin(), imenik.end(), [] (Imenik& a, Imenik& b)
    {
        return a.getIme() < b.getIme();
    });

    std::cout << "Post - sort" << std::endl;
    for (Imenik& i : imenik)
        std::cout << i << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
}

bool anagram(std::string s1, std::string& s2)
{
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    return std::equal(s1.begin(), s1.end(), s2.begin());
}

void zadaca04_02()
{
    std::string s1, s2;

    std::cout << "Vnesete zbor 1: ";
    std::cin >> s1;
    std::cout << "Vnesete zbor 2: ";
    std::cin >> s2;

    std::cout << "Zborovite" << (anagram(s1,s2)?" ":" ne ") << "se anagrami" << std::endl;

    std::cout << std::endl;
}

std::set<std::string>* string_split_unique_sorted(const std::string& text, const std::string& delimiter=" ")
{
    std::set<std::string>* split = new std::set<std::string>;

    size_t start = 0;
    size_t end = text.find(delimiter);

    std::string s;

    while (end != std::string::npos)
    {
        s = text.substr(start, end - start);
        if (s.length() > 0)
            split->insert(s);
        start = end + delimiter.length();
        end = text.find(delimiter, start);
    }

    s = text.substr(start, end);
    if (s.length() > 0)
        split->insert(s);

    return split;
}

void zadaca04_03()
{
    std::string text;
    std::cout << "Vnesete tekst: ";
    std::getline(std::cin, text);

    std::set<std::string>* split = string_split_unique_sorted(text);

    for (const std::string& s : *split)
        std::cout << s << std::endl;

    delete split;

    std::cout << std::endl;
}

#endif // T04_STANDARD_TEMPLATE_LIBRARY_H
