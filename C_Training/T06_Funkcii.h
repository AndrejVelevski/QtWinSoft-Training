#ifndef T06_FUNKCII_H
#define T06_FUNKCII_H

#include <stdio.h>

int paren(int number)
{
    return !((number&1) == 0);
}

void zadaca06_01()
{
    for (int i=0;i<10;++i)
    {
        int number;
        printf("Vnesete broj: ");
        scanf("%d", &number);

        int result = paren(number);
        printf("Brojot %d e %sparen\n", number,result?"ne":"");
    }

    printf("\n");
}

int vreme(int hours, int minutes, int seconds)
{
    int totalSeconds = 60*60*12;
    totalSeconds -= hours*60*60;
    totalSeconds -= minutes*60;
    totalSeconds -= seconds;
    return totalSeconds;
}

void zadaca06_02()
{
    int hours, minutes, seconds;
    printf("Vnesete vreme (hh mm ss): ");
    scanf("%d %d %d", &hours, &minutes, &seconds);
    printf("Ima uste %d sekundi do 12 casot\n\n", vreme(hours, minutes, seconds));
}

int obratno(int number)
{
    int new = 0;

    while(number != 0)
    {
        new = new * 10 + number%10;
        number /= 10;
    }

    return new;
}

void zadaca06_03()
{
    int number;
    printf("Vnesete broj: ");
    scanf("%d", &number);
    printf("Obratno: %d\n\n", obratno(number));
}

int nzd_iterative(int num1, int num2)
{
    while(1)
    {
        if (num2 == 0)
            return num1;

        int temp = num1%num2;
        num1 = num2;
        num2 = temp;
    }
}

void zadaca06_04()
{
    int num1, num2;
    printf("Vnesete 2 celi broja: ");
    scanf("%d %d", &num1, &num2);
    printf("Najgolem zaednicki delitel na %d i %d e %d\n\n", num1, num2, nzd_iterative(num1, num2));
}

int fibonacci_itterative(int number)
{
    int n1 = 0;
    int n2 = 1;
    int f = n1 + n2;
    for (int i=0;i<number;++i)
    {
        f = n1 + n2;
        n1 = n2;
        n2 = f;
    }
    return n1;
}

void zadaca06_05()
{
    int number;
    printf("Vnesete cel broj: ");
    scanf("%d", &number );
    printf("Fibonnaci(%d) = %d\n\n", number, fibonacci_itterative(number));
}

int nzd_recursive(int num1, int num2)
{
    if (num2 == 0)
        return num1;
    return nzd_recursive(num2, num1%num2);
}

void zadaca06_06()
{
    int num1, num2;
    printf("Vnesete 2 celi broja: ");
    scanf("%d %d", &num1, &num2);
    printf("Najgolem zaednicki delitel na %d i %d e %d\n\n", num1, num2, nzd_recursive(num1, num2));
}

void dzvezdi(int n)
{
    if (n == 1)
    {
        printf("*");
        return;
    }
    for (int i=0;i<n;++i)
    {
        printf("*");
    }
    printf("\n");
    dzvezdi(n-1);
}

void zadaca06_07()
{
    dzvezdi(5);

    printf("\n\n");
}

#endif // T06_FUNKCII_H
