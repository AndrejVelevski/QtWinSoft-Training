#ifndef T09_POKAZUVACI_H
#define T09_POKAZUVACI_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copy1(char *s1, const char *s2)
{
    int i;
    for ( i = 0; ( s1[ i ] = s2[ i ] ) != '\0'; i++ )
    {

    }
}

void copy2(char *s1, const char *s2)
{
    for ( ; ( *s1 = *s2 ) != '\0'; s1++, s2++ )
    {

    }
}

void zadaca09_01()
{
    char string1[10];
    char *string2 = "Zdravo";
    char string3[10];
    const char string4[] = "Dobar den";
    copy1(string1, string2);
    printf("string1 = %s\n", string1);
    copy2(string3, string4);
    printf("string3 = %s\n", string3);

    printf("Toa znaci deka mora da dodelime dovolno mesto za site\n"
           "karakteri da mozat da se iskoporaat od eden vo drug string.\n"
           "Vtoriot argument vo dvete funkcii e deklariran kako const char*\n"
           "za da kaze deka vtoriot string ne moze da se promeni.\n\n");
}

void meshaj(int wDeck[][13])
{
    int row;
    int column;
    for (int card=1;card<=52;++card)
    {
        do
        {
            row = rand() % 4;
            column = rand() % 13;
        } while(wDeck[row][column] != 0);

        wDeck[row][column] = card;
    }
}

void printCard(const int wDeck[][13], const char *wFace[], const char *wSuit[], int card)
{
    for (int column=0;column<13;++column)
    {
        for (int row=0;row<4;++row)
        {
            if (wDeck[row][column] == card)
            {
                printf("%s %s\n", wFace[column], wSuit[row]);
                break;
            }
        }
    }
}

int sodrziPar(const int wDeck[][13], int cards[])
{
    int brojki[13] = {0};

    for (int column=0;column<13;++column)
    {
        for (int row=0;row<4;++row)
        {
            for (int card=0;card<5;++card)
            {
                if (wDeck[row][column] == cards[card])
                {
                    ++brojki[column];
                }
            }
        }
    }

    for (int i=0;i<13;++i)
    {
        if (brojki[i] >= 2)
            return 1;
    }

    return 0;
}

int sodrziDvaPara(const int wDeck[][13], int cards[])
{
    int brojki[13] = {0};

    for (int column=0;column<13;++column)
    {
        for (int row=0;row<4;++row)
        {
            for (int card=0;card<5;++card)
            {
                if (wDeck[row][column] == cards[card])
                {
                    ++brojki[column];
                }
            }
        }
    }

    int pairs = 0;

    for (int i=0;i<13;++i)
    {
        if (brojki[i] >= 2)
            ++pairs;
    }

    return pairs == 2;
}

int sodrziTriling(const int wDeck[][13], int cards[])
{
    int brojki[13] = {0};

    for (int column=0;column<13;++column)
    {
        for (int row=0;row<4;++row)
        {
            for (int card=0;card<5;++card)
            {
                if (wDeck[row][column] == cards[card])
                {
                    ++brojki[column];
                }
            }
        }
    }

    for (int i=0;i<13;++i)
    {
        if (brojki[i] >= 3)
            return 1;
    }

    return 0;
}

int sodrziCetiri(const int wDeck[][13], int cards[])
{
    int brojki[13] = {0};

    for (int column=0;column<13;++column)
    {
        for (int row=0;row<4;++row)
        {
            for (int card=0;card<5;++card)
            {
                if (wDeck[row][column] == cards[card])
                {
                    ++brojki[column];
                }
            }
        }
    }

    for (int i=0;i<13;++i)
    {
        if (brojki[i] >= 4)
            return 1;
    }

    return 0;
}

int sodrziIstaBoja(const int wDeck[][13], int cards[])
{
    int boi[4] = {0};

    for (int column=0;column<13;++column)
    {
        for (int row=0;row<4;++row)
        {
            for (int card=0;card<5;++card)
            {
                if (wDeck[row][column] == cards[card])
                {
                    ++boi[row];
                }
            }
        }
    }

    for (int i=0;i<4;++i)
    {
        if (boi[i] >= 5)
            return 1;
    }

    return 0;
}

int sodrziKenta(const int wDeck[][13], int cards[])
{
    int brojki[5] = {0};
    int boi[5] = {0};

    for (int column=0;column<13;++column)
    {
        for (int row=0;row<4;++row)
        {
            for (int card=0;card<5;++card)
            {
                if (wDeck[row][column] == cards[card])
                {
                    brojki[card] = column;
                    boi[card] = row;
                }
            }
        }
    }

    for (int i=1;i<5;++i)
    {
        if (boi[i] != boi[0])
            return 0;
        if (brojki[i-1] != brojki[i]+1)
            return 0;
    }

    return 1;
}

void zadaca09_02()
{
    srand(time(NULL));

    const char* boja[4] = { "Srce", "Karo", "List", "Detelina" };
    const char* brojka[13] = { "As", "Dva", "Tri", "Chetiri", "Pet", "Shest", "Sedum", "Osum", "Devet", "Deset", "Dzandar", "Dama", "Pop" };

    int spil[4][13] = {0};
    meshaj(spil);

    int podeleni1[5];
    int podeleni2[5];
    for (int i=0;i<5;++i)
        podeleni1[i] = i+1;
    for (int i=5;i<10;++i)
        podeleni2[i-5] = i+1;

    printf("Karti na igrac 1:\n");
    for (int i=0;i<5;++i)
        printCard(spil, brojka, boja, podeleni1[i]);
    printf("Vo izvlecenite karti %s par.\n", sodrziPar(spil, podeleni1)?"ima":"nema");
    printf("Vo izvlecenite karti %s dva para.\n", sodrziDvaPara(spil, podeleni1)?"ima":"nema");
    printf("Vo izvlecenite karti %s triling.\n", sodrziTriling(spil, podeleni1)?"ima":"nema");
    printf("Vo izvlecenite karti %s cetiri isti.\n", sodrziCetiri(spil, podeleni1)?"ima":"nema");
    printf("Vo izvlecenite karti %s 5 isti po boja.\n", sodrziIstaBoja(spil, podeleni1)?"ima":"nema");
    printf("Vo izvlecenite karti %s kenta.\n", sodrziKenta(spil, podeleni1)?"ima":"nema");

    printf("\n");

    printf("Karti na igrac 2:\n");
    for (int i=0;i<5;++i)
        printCard(spil, brojka, boja, podeleni2[i]);
    printf("Vo izvlecenite karti %s par.\n", sodrziPar(spil, podeleni2)?"ima":"nema");
    printf("Vo izvlecenite karti %s dva para.\n", sodrziDvaPara(spil, podeleni2)?"ima":"nema");
    printf("Vo izvlecenite karti %s triling.\n", sodrziTriling(spil, podeleni2)?"ima":"nema");
    printf("Vo izvlecenite karti %s cetiri isti.\n", sodrziCetiri(spil, podeleni2)?"ima":"nema");
    printf("Vo izvlecenite karti %s 5 isti po boja.\n", sodrziIstaBoja(spil, podeleni2)?"ima":"nema");
    printf("Vo izvlecenite karti %s kenta.\n", sodrziKenta(spil, podeleni2)?"ima":"nema");

    printf("\n");

    int poeni1 = 0;
    if (sodrziKenta(spil, podeleni1)) poeni1 += 6;
    else if (sodrziIstaBoja(spil, podeleni1)) poeni1 += 5;
    else if (sodrziCetiri(spil, podeleni1)) poeni1 += 4;
    else if (sodrziTriling(spil, podeleni1)) poeni1 += 3;
    else if (sodrziDvaPara(spil, podeleni1)) poeni1 += 2;
    else if (sodrziPar(spil, podeleni1)) poeni1 += 1;

    int poeni2 = 0;
    if (sodrziKenta(spil, podeleni2)) poeni2 += 6;
    else if (sodrziIstaBoja(spil, podeleni2)) poeni2 += 5;
    else if (sodrziCetiri(spil, podeleni2)) poeni2 += 4;
    else if (sodrziTriling(spil, podeleni2)) poeni2 += 3;
    else if (sodrziDvaPara(spil, podeleni2)) poeni2 += 2;
    else if (sodrziPar(spil, podeleni2)) poeni2 += 1;

    if (poeni1 > poeni2)
        printf("Igrac 1 pobedi\n\n");
    else if (poeni1 < poeni2)
        printf("Igrac 2 pobedi\n\n");
    else
        printf("Nereseno\n\n");
}

void pecatiNiza(int* grades, int numStudents, int numGrades)
{
    printf("Site ocenki:\n");
    for (int i=0;i<numStudents;++i)
    {
        for (int j=0;j<numGrades;++j)
        {
            int val = ((int*)grades)[i*numGrades+j];
            printf("%d\t", val);
        }
        printf("\n");
    }
}

void minOcena(int* grades, int numStudents, int numGrades)
{
    int min = 10;
    for (int i=0;i<numStudents;++i)
    {
        for (int j=0;j<numGrades;++j)
        {
            int val = ((int*)grades)[i*numGrades+j];
            if (val < min)
                min = val;
        }
    }
    printf("Minimalna ocena: %d\n", min);
}

void maxOcena(int* grades, int numStudents, int numGrades)
{
    int max = 5;
    for (int i=0;i<numStudents;++i)
    {
        for (int j=0;j<numGrades;++j)
        {
            int val = ((int*)grades)[i*numGrades+j];
            if (val > max)
                max = val;
        }
    }
    printf("Maksimalna ocena: %d\n", max);
}

void avgOcena(int* grades, int numStudents, int numGrades)
{
    printf("Prosecni ocenki:\n");
    for (int i=0;i<numStudents;++i)
    {
        float avg = 0;
        for (int j=0;j<numGrades;++j)
        {
            int val = ((int*)grades)[i*numGrades+j];
            avg += val;
        }
        printf("%f\n", avg/numGrades);
    }
    printf("\n");
}

void zadaca09_03()
{
    srand(time(NULL));

    const int numStudents = 6;
    const int numGrades = 5;

    int grades[numStudents][numGrades];
    for (int i=0;i<numStudents;++i)
    {
        for (int j=0;j<numGrades;++j)
        {
            grades[i][j] = rand() % 5 + 6;
        }
    }

    void (*obrabotiOcena[])(int* grades, int numStudents, int numGrades) = { pecatiNiza, maxOcena, minOcena, avgOcena };

    while(1)
    {
        printf("____________________________________________________\n"
               "0 Ispechati ja nizata so oceni\n"
               "1 Najdi ja maksimalnataocena\n"
               "2 Najdi ja minimalnata ocena\n"
               "3 Ispecati ja prosechnata ocena za sekoja student\n"
               "4 Kraj\n"
               "Vnesete izbor: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 4)
            break;

        if (choice >= 0 && choice < 4)
            obrabotiOcena[choice](*grades, numGrades, numStudents);

        printf("\n");
    }

    printf("\n");
}


#endif // T09_POKAZUVACI_H
