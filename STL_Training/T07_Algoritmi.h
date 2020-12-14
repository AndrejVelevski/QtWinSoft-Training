#ifndef T07_ALGORITMI_H
#define T07_ALGORITMI_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

void zadaca07_01()
{
    std::vector<int> vector(10000);
    std::mt19937 generator(time(0));
    std::uniform_int_distribution<int> distribution(0, 9999);

    std::generate(vector.begin(), vector.end(), [&distribution, &generator]{
        return distribution(generator);
    });

    int parni = 0;
    int interval[5] = { 0 };
    int suma = 0;

    std::for_each(vector.begin(), vector.end(), [&parni, &interval, &suma](const int& v){
       if ((v&1) == 0)
           ++parni;

       ++interval[v/2000];
       suma += v;
    });

    std::cout << "Broj na parni elementi: " << parni << std::endl;
    std::cout << "Broj na elementi vo interval[   0 -  2000): " << interval[0] << std::endl;
    std::cout << "Broj na elementi vo interval[2000 -  4000): " << interval[1] << std::endl;
    std::cout << "Broj na elementi vo interval[4000 -  6000): " << interval[2] << std::endl;
    std::cout << "Broj na elementi vo interval[6000 -  8000): " << interval[3] << std::endl;
    std::cout << "Broj na elementi vo interval[8000 - 10000): " << interval[4] << std::endl;
    std::cout << "Sredna vrednost: " << suma / 10000.0 << std::endl;

    std::cout << std::endl;
}

namespace crd
{
    static std::string values[13] = {  };
    static std::string types[4] = {  };
}

enum Value
{
    Two=2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Ace=1, Jack=12, Queen, King
};

enum Type
{
    Spade, Heart, Clover, Diamond
};

class Card
{
private:
    Value mValue;
    Type mType;

public:
    Card(Value value, Type type) :
        mValue(value),
        mType(type)
    {

    }

    Value getValue() const
    {
        return mValue;
    }

    Type getType() const
    {
        return mType;
    }

    friend std::ostream& operator<<(std::ostream& os, const Card& c)
    {
        os << "(";

        switch (c.mValue)
        {
            case Two: os << "Two"; break;
            case Three: os << "Three"; break;
            case Four: os << "Four"; break;
            case Five: os << "Five"; break;
            case Six: os << "Six"; break;
            case Seven: os << "Seven"; break;
            case Eight: os << "Eight"; break;
            case Nine: os << "Nine"; break;
            case Ten: os << "Ten"; break;
            case Ace: os << "Ace"; break;
            case Jack: os << "Jack"; break;
            case Queen: os << "Queen"; break;
            case King: os << "King"; break;
        }

        os << " of ";


        switch (c.mType)
        {
            case Spade: os << "Spade"; break;
            case Heart: os << "Heart"; break;
            case Clover: os << "Clover"; break;
            case Diamond: os << "Diamond"; break;
        }

        return os << "s)";
    }
};

class Deck
{
private:
    std::vector<Card*> mDeck;

public:
    Deck()
    {
        mDeck.reserve(52);

        for (int i=1;i<=14;++i)
        {
            if (i == 11)
                continue;

            for (int j=0;j<4;++j)
            {
                mDeck.push_back(new Card((Value) i, (Type) j));
            }
        }

        srand(time(0));

        std::random_shuffle(mDeck.begin(), mDeck.end());
    }

    ~Deck()
    {
        for(Card* c : mDeck)
            delete c;
    }

    friend std::ostream& operator<<(std::ostream& os, const Deck& d)
    {
        for(const Card* c : d.mDeck)
            os << *c << std::endl;
        return os;
    }

    bool empty() const
    {
        return mDeck.empty();
    }

    Card* deal()
    {
        Card* c = mDeck.back();
        mDeck.pop_back();
        return c;
    }
};

class Player
{
private:
    std::vector<Card*> mCards;

public:
    Player(){}

    void addCard(Card* card)
    {
        mCards.push_back(card);
    }

    friend std::ostream& operator<<(std::ostream& os, const Player& p)
    {
        for (const Card* c : p.mCards)
            os << *c << std::endl;
        return os;
    }

    int totalA() const
    {
        return std::accumulate(mCards.begin(), mCards.end(), 0, [&](int sum, Card* c2){
            return sum + c2->getValue();
        });
    }

    int totalB() const
    {
        return std::accumulate(mCards.begin(), mCards.end(), 0, [&](int sum, Card* c2){
            return sum + (c2->getType() == Type::Heart?2:1) * c2->getValue();
        });
    }
};

void zadaca07_02()
{
    std::cout << "Number of players: ";
    int numPlayers;
    std::cin >> numPlayers;

    Deck deck;
    std::vector<Player*> players(numPlayers);

    std::generate(players.begin(), players.end(), []{
        return new Player;
    });

    for (int i=0;!deck.empty();)
        players[(i++)%numPlayers]->addCard(deck.deal());

    for (int i=0;i<numPlayers;++i)
        std::cout << "Player " << i+1 << "'s cards:\n" << *players[i] << std::endl;

    std::cout << "A)" << std::endl;
    for (int i=0;i<numPlayers;++i)
        std::cout << "Player " << i+1 << " total: " << players[i]->totalA() << std::endl;
    std::cout << std::endl;

    std::cout << "B)" << std::endl;
    for (int i=0;i<numPlayers;++i)
        std::cout << "Player " << i+1 << " total: " << players[i]->totalB() << std::endl;
    std::cout << std::endl;

    for (Player* p : players)
        delete p;

    std::cout << std::endl;
}

class Vraboten
{
private:
    std::string ime;
    std::vector<int> bodovi;

public:
    Vraboten(const std::string& ime)
    {
        this->ime = ime;

        bodovi.reserve(8);

        int num = rand()%4 + 4;

        for (int i=0;i<num;++i)
            bodovi.push_back(rand()%50);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vraboten& v)
    {
        os << v.ime;

        os << "\t" << v.presmetajBodovi();

        for (int b : v.bodovi)
            os << "\t" << b;

        return os;
    }

    int presmetajBodovi() const
    {
        return std::accumulate(bodovi.begin(), bodovi.end(), 0, [&](int a, int c){
            return a + c*bodovi.size();
        });
    }
};

void zadaca07_03()
{
    srand(time(0));

    std::vector<Vraboten> vraboteni = { Vraboten("Jovan"), Vraboten("Marko"), Vraboten("Martin"),
                                        Vraboten("Andrej"), Vraboten("David"), Vraboten("Martina"),
                                        Vraboten("Sara"), Vraboten("Jovana"), Vraboten("Viktor"),
                                        Vraboten("Maja"), Vraboten("Ana"), Vraboten("Filip") };


    std::sort(vraboteni.begin(), vraboteni.end(), [](Vraboten& v1, Vraboten& v2){
        return v1.presmetajBodovi() > v2.presmetajBodovi();
    });

    std::cout << "Ime\tVkupno\tBodovi..." << std::endl;
    for (Vraboten& v : vraboteni)
        std::cout << v << std::endl;


}

#endif // T07_ALGORITMI_H
