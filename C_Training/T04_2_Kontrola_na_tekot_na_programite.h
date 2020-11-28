#ifndef T04_2_KONTROLA_NA_TEKOT_NA_PROGRAMITE_H
#define T04_2_KONTROLA_NA_TEKOT_NA_PROGRAMITE_H

#include <stdio.h>
#include <math.h>

void zadaca04_2_01()
{
    int sum;
    int number;
    for (sum = 0, number = 2; number <= 100; number += 2)
    {
        sum += number;
    }
    printf("Sumata e %d\n\n", sum);
}

void zadaca04_2_02()
{
    double amount;
    double principal = 1000.0;
    double rate = 0.05;
    int year;

    printf("%6s%25s\n", "Godina", "Vrednost na depozitot" );
    for (year = 1; year <= 10; year++)
    {
        amount = principal * pow(1.0 + rate, year);
        printf("%6d    %.2f\n", year, amount);
    }
    printf("\n");
}

void zadaca04_2_03()
{
    for (int a=1;a<=100;++a)
    {
        for (int b=1;b<=100;++b)
        {
            for (int c=1;c<=100;++c)
            {
                if (a*a + b*b == c*c)
                {
                    printf("%d^2 + %d^2 = %d^2\n", a, b, c);
                }
            }
        }
    }
    printf("\n");
}

void zadaca04_2_04()
{
    while(1)
    {
        int num;
        printf("Vnesete broj: ");
        scanf("%d", &num);

        if (num < 1 || num > 9999)
        {
            printf("Mora da vnesete 4 cifren broj pogolem od 0\n");
            continue;
        }

        printf("Rimski broj: ");
        while (num >= 1000)
        {
            printf("M");
            num -= 1000;
        }

        if (num >= 900)
        {
            printf("CM");
            num -= 900;
        }
        if (num >= 500)
        {
            printf("D");
            num -= 500;
        }
        if (num >= 400)
        {
            printf("CD");
            num -= 400;
        }
        while (num >= 100)
        {
            printf("C");
            num -= 100;
        }

        if (num >= 90)
        {
            printf("XC");
            num -= 90;
        }
        if (num >= 50)
        {
            printf("L");
            num -= 50;
        }
        if (num >= 40)
        {
            printf("XL");
            num -= 40;
        }
        while (num >= 10)
        {
            printf("X");
            num -= 10;
        }

        if (num >= 9)
        {
            printf("IX");
            num -= 9;
        }
        if (num >= 5)
        {
            printf("V");
            num -= 5;
        }
        if (num >= 4)
        {
            printf("IV");
            num -= 4;
        }
        while (num >= 1)
        {
            printf("I");
            num -= 1;
        }

        break;
    }

    printf("\n\n");
}

void zadaca04_2_05()
{
    for (int i=1;i<=100;++i)
    {
        if (i%3 == 0)
            continue;

        printf("%3d ne e deliv so 3\n", i);
    }

    printf("\n");
}


#endif // T04_2_KONTROLA_NA_TEKOT_NA_PROGRAMITE_H
