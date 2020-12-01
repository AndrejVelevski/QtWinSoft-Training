#ifndef T04_KONTROLA_NA_TEKOT_NA_PROGRAMITE_H
#define T04_KONTROLA_NA_TEKOT_NA_PROGRAMITE_H

#include <stdio.h>
#include <math.h>

void zadaca04_01()
{
    int mesec;

     printf("Vnesi go mesecot so negoviot reden broj: ");
     scanf("%d", &mesec);

     switch (mesec)
     {
         case 1:
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12:
             printf("Ima 31 den\n");
             //break;
         case 4:
         case 6:
         case 9:
         case 11:
             printf("Ima 30 dena\n");
             //break;
         case 2:
             printf("Vo prestapni godini ima 29, a vo obichni 28 dena\n");
             //break;
         default:
            printf("Greshen broj na mesec!\n");
     }

     printf("\n");

     printf("Dokolku se ispustat break naredbite, kje se izvrshat site naredbi nadolu\n");
     printf("pocnuvajki od vneseniot case.\n\n");
}

void zadaca04_02()
{
    int counter;
    int grade;
    int total;
    int average;
    int numStudents;

    printf("Vnesete broj na studenti: ");
    scanf("%d", &numStudents);

    total = 0;
    counter = 1;

    while (counter <= numStudents)
    {
        printf("Vnesi ocena: ");
        scanf("%d", &grade);
        total = total + grade;
        counter = counter + 1;
    }

    average = total / numStudents;
    printf("Srednata vrednost na klasot e %d\n\n", average);
}

void zadaca04_03()
{
    int counter;
    int grade;
    int total;
    float average;
    int numStudents;

    printf("Vnesete broj na studenti: ");
    scanf("%d", &numStudents);

    total = 0;
    counter = 1;

    while (counter <= numStudents)
    {
        printf("Vnesi ocena: ");
        scanf("%d", &grade);
        total = total + grade;
        counter = counter + 1;
    }

    average = (float)total / numStudents;
    printf("Srednata vrednost na klasot e %.3f\n\n", average);
}

void zadaca04_04()
{
    int i = 1;
    int sum = 0;

    while (i <= 10)
    {
        sum += i;

        ++i;
    }

    printf("Sumata na broevite od [1 do 10] e: %d\n\n", sum);
}

void zadaca04_05()
{
    int product = 1;

    int i = 0;

    while (i < 10)
    {
        int num;
        printf("Vnesete broj: ");
        scanf("%d", &num);

        product *= num;
        ++i;
    }

    printf("Proizvodot e %d\n\n", product);
}

void zadaca04_06()
{
    int sum = 0;

    while(1)
    {
        int num;
        printf("Vnesete broj: ");
        scanf("%d", &num);

        if (num == -1)
            break;

        sum += num;
    }

    printf("Sumata e %d\n\n", sum);
}

void zadaca04_07()
{
    int sum = 0;

    while(1)
    {
        int num;
        printf("Vnesete broj: ");
        scanf("%d", &num);

        sum += num;

        char c;
        printf("Ushte? (d/n) ");
        scanf(" %c", &c);

        if (c == 'n')
            break;
    }

    printf("Sumata e %d\n\n", sum);
}

void zadaca04_08()
{
    double sumProduct[5];
    int i = 0;
    while (i < 5)
    {
        sumProduct[i] = 0;
        ++i;
    }


    while (1)
    {
        int productNumber, quantity;

        printf("Vnesete broj na proizvod (nevaliden za kraj): ");
        scanf("%d", &productNumber);

        if (productNumber < 1 || productNumber > 5)
            break;

        printf("Vnesete kolocina prodadena: ");
        scanf("%d", &quantity);

        switch (productNumber)
        {
            case 1: sumProduct[0] += 50.5 * quantity; break;
            case 2: sumProduct[1] += 45.6 * quantity; break;
            case 3: sumProduct[2] += 32.8 * quantity; break;
            case 4: sumProduct[3] += 65.3 * quantity; break;
            case 5: sumProduct[4] += 20.0 * quantity; break;
        }
    }

    i = 0;
    double total = 0;
    while (i < 5)
    {
        printf("Suma na proizvodot %d iznesuva %f\n", i+1, sumProduct[i]);
        total += sumProduct[i];
        ++i;
    }

    printf("Vkupnata suma na site proizvodi iznesuva %f\n\n", total);
}

void zadaca04_09()
{
    while(1)
    {
        double promet;
        printf("Vnesi promet vo evra(-1 za kraj): ");
        scanf("%lf", &promet);

        if (promet == -1.0)
            break;

        double paycheck = 200.0 + 0.09*promet;
        printf("Platata e %.2f evra\n", paycheck);
    }

    printf("\n");
}

void zadaca04_10()
{
    int sum;
    int number;
    for (sum = 0, number = 2; number <= 100; number += 2)
    {
        sum += number;
    }
    printf("Sumata e %d\n\n", sum);
}

void zadaca04_11()
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

void zadaca04_12()
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

void zadaca04_13()
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

void zadaca04_14()
{
    for (int i=1;i<=100;++i)
    {
        if (i%3 == 0)
            continue;

        printf("%3d ne e deliv so 3\n", i);
    }

    printf("\n");
}

#endif // T04_KONTROLA_NA_TEKOT_NA_PROGRAMITE_H
