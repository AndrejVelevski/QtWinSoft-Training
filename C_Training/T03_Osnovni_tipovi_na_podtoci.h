#ifndef T03_OSNOVNI_TIPOVI_NA_PODTOCI_H
#define T03_OSNOVNI_TIPOVI_NA_PODTOCI_H

#include <stdio.h>

void zadaca03_01()
{
    int num1, num2;

    printf("Vnesi dva celi broja:\n");
    scanf("%d %d", &num1, &num2);

    if (num1 == num2)
        printf("Broevite se ednakvi\n\n");
    else
        printf("%d e pogolem od %d\n\n", num1>num2?num1:num2, num1>num2?num2:num1);
}

void zadaca03_02()
{
    int num1, num2;

    printf("Vnesi dva celi broja:\n");
    scanf("%d %d", &num1, &num2);

    printf("Brojot %d e %sparen\n", num1, (num1&1) == 0?"":"ne");
    printf("Brojot %d e %sparen\n", num2, (num2&1) == 0?"":"ne");
}

void zadaca03_03()
{
    printf("%d %d %d %d %d %d %d %d %d %d\n", 'A', 'b', 'c', '0', '2', '$', '*', '+', '/', ' ');
    printf("Na ovoj nacin se pecatat ascii kodovite na karakterite\n\n");
}

void zadaca03_04()
{
    float result;
    result = 7.0 / 22.0;
    printf("Rezultatot e %f\n", result);
    printf("Rezultatot e %d\n", result);
    printf("%s", "Zatoa sto %d e namenet za pecatenje celi vrednosti\n");
    printf("%s", "%d probuva da ja konvertira vrednosta od float vo int\n");
    printf("Pritoa nastanuva greska bidejki prviot bit pretstavuva znakot,\n");
    printf("slednite 8 bitovi pretstavuvaat eksponent i ostanatite 23\n");
    printf("pretstavuvaat mantisa (spored IEEE 754) za pretstavuvanje na floating\n");
    printf("point broevi.\n\n");
}

void zadaca03_05()
{
    float radius;
    float pi = 3.1415927;
    printf("Vnesete radius: ");
    scanf("%f", &radius);
    printf("Plostina na krug: %f\n", radius*radius*pi);
    printf("Perimetar na krug: %f\n\n", 2*radius*pi);
}

void zadaca03_06()
{
    char letters[5];

    printf("Prva bukva: ");
    scanf(" %c", &letters[0]);

    printf("Vtora bukva: ");
    scanf(" %c", &letters[1]);

    printf("Treta bukva: ");
    scanf(" %c", &letters[2]);

    printf("Cetvrta bukva: ");
    scanf(" %c", &letters[3]);

    printf("Petta bukva: ");
    scanf(" %c", &letters[4]);

    printf("Se dobi: %c%c%c%c%c\n\n", letters[4], letters[2], letters[1], letters[0], letters[3]);
}

void zadaca03_07()
{
    float data[5];
    float total;
    float average;

    data[0] = 34.0;
    data[1] = 27.0;
    data[2] = 45.0;
    data[3] = 82.0;
    data[4] = 22.0;
    total = data[0] + data[1] + data[2] + data[3] + data[4];
    average = total / 5.0;
    printf("Vkupno %.3f Sredna vrednost %.3f\n\n", total, average);
}

void zadaca03_08()
{
    int x = 1;
    printf("%d\n", x);
    ++x;
    printf("%d\n", x);
    x++;
    printf("%d\n", x);
    x += 1;
    printf("%d\n", x);
    x = x + 1;
    printf("%d\n\n", x);
}

#endif // T03_OSNOVNI_TIPOVI_NA_PODTOCI_H
