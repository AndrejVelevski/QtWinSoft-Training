#ifndef T08_DOMASNO_H
#define T08_DOMASNO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void zadaca08_01()
{
    int n;
    printf("Vnesete broj na strani na mnoguagolnikot: ");
    scanf("%d", &n);

    float perimeter = 2 * n * sin(M_PI / n);
    float area = (n / 2.0) * sin(2 * M_PI / n);

    printf("Perimetar: %f\n", perimeter);
    printf("Area: %f\n\n", area);
}

double determinant2x2(double a, double b, double c, double d)
{
    return a*d - c*b;
}

double determinant3x3(double m[3][3])
{
    double r1 = m[0][0] * determinant2x2(m[1][1], m[2][1], m[1][2], m[2][2]);
    double r2 = m[1][0] * determinant2x2(m[0][1], m[0][2], m[2][1], m[2][2]);
    double r3 = m[2][0] * determinant2x2(m[0][1], m[0][2], m[1][1], m[1][2]);

    return r1 - r2 + r3;
}

void zadaca08_02()
{
    //https://www.intmath.com/matrices-determinants/1-determinants.php

    srand(time(NULL));

    printf("a1x + b1y + c1z = d1\n");
    printf("a2x + b2y + c2z = d2\n");
    printf("a3x + b3y + c3z = d3\n");

    double n[3][4];

    int autog;
    printf("Auto-generated broevi(1/0)? ");
    scanf("%d", &autog);

    if (autog)
    {
        for (int i=0;i<3;++i)
        {
            for (int j=0;j<4;++j)
            {
                double num = rand() % 100;
                printf("Vnesete broj za %c%d: %f\n", 'a'+j, i+1, num);
                n[i][j] = num;
            }
        }
    }
    else
    {
        for (int i=0;i<3;++i)
        {
            for (int j=0;j<4;++j)
            {
                printf("Vnesete broj za %c%d: ", 'a'+j, i+1);
                scanf("%lf", &n[i][j]);
            }
        }
    }

    double d[3][3] = {{n[0][0], n[0][1], n[0][2]},
                      {n[1][0], n[1][1], n[1][2]},
                      {n[2][0], n[2][1], n[2][2]}};
    double dx[3][3] = {{n[0][3], n[0][1], n[0][2]},
                       {n[1][3], n[1][1], n[1][2]},
                       {n[2][3], n[2][1], n[2][2]}};
    double dy[3][3] = {{n[0][0], n[0][3], n[0][2]},
                       {n[1][0], n[1][3], n[1][2]},
                       {n[2][0], n[2][3], n[2][2]}};
    double dz[3][3] = {{n[0][0], n[0][1], n[0][3]},
                       {n[1][0], n[1][1], n[1][3]},
                       {n[2][0], n[2][1], n[2][3]}};

    printf("%.0fx + %.0fy + %.0fz = %.0f\n", n[0][0], n[0][1], n[0][2], n[0][3]);
    printf("%.0fx + %.0fy + %.0fz = %.0f\n", n[1][0], n[1][1], n[1][2], n[1][3]);
    printf("%.0fx + %.0fy + %.0fz = %.0f\n", n[2][0], n[2][1], n[2][2], n[2][3]);

    double dd = determinant3x3(d);
    double x = determinant3x3(dx)/dd;
    double y = determinant3x3(dy)/dd;
    double z = determinant3x3(dz)/dd;

    printf("x = %f, y = %f, z = %f\n\n", x, y, z);
}

int reversed(int number)
{
    int reversed = 0;
    while(number != 0)
    {
        reversed = reversed*10 + number%10;
        number /= 10;
    }
    return reversed;
}

void zadaca08_03()
{
    int num;
    printf("Vnesete broj: ");
    scanf("%d", &num);

    printf("Sprotiven broj: %d\n\n", reversed(num));
}

int perfect(int number)
{
    int sum = 0;
    for (int i=1;i<number;++i)
        if (number % i == 0)
            sum += i;
    return sum == number;
}

void zadaca08_04()
{
    int num;
    printf("Vnesete broj: ");
    scanf("%d", &num);
    printf("Sovrseni broevi pomali od %d: ", num);
    for (int i=1;i<num;++i)
        if (perfect(i))
            printf("%d ", i);
    printf("\n\n");
}

void zadaca08_05()
{
    int number;
    printf("Vnesete broj: ");
    scanf("%d", &number);

    int bases[1000] = {0};
    int basesSize = 0;

    int num = number;

    while (num != 1)
    {
        for (int i=2;i<=num;++i)
        {
            if (num % i == 0)
            {
                bases[basesSize++] = i;
                num /= i;
                break;
            }
        }
    }

    int exp = bases[0];
    int expc = 1;
    printf("%d = ", number);
    for (int i=0;i<basesSize;++i)
    {
        if (bases[i+1] == exp)
        {
            ++expc;
            exp = bases[i+1];
        }
        else
        {
            printf("%d^%d ", bases[i], expc);
            expc = 1;
            exp = bases[i+1];
        }
    }

    printf("\n\n");
}

int digitCubeSum(int number)
{
    int sum = 0;

    while (number != 0)
    {
        int d = number%10;
        sum += d*d*d;
        number /= 10;
    }

    return sum;
}

void zadaca08_06()
{
    int num;
    printf("Vnesete broj: ");
    scanf("%d", &num);

    printf("Broevi cija suma od kubot na cifrite e ista: ");
    for (int i=0;i<num;++i)
        if (digitCubeSum(i) == i)
            printf("%d ", i);

    printf("\n\n");
}

void zadaca08_07()
{
    int n1, n2;
    printf("Vnesete interval [n1, n2]: ");
    scanf("%d %d", &n1, &n2);

    printf("Broevi koi se delivi so nivniot sprotiven broj: ");
    for (int i=n1;i<=n2;++i)
    {
        if (i % reversed(i) == 0)
            printf("%d ", i);
    }

    printf("\n\n");
}

int containsSquaredCubedDigitOnce(int squared, int cubed)
{
    int contain[10] = {0};

    while (squared != 0)
    {
        int d = squared % 10;
        ++contain[d];
        squared /= 10;
    }
    while (cubed != 0)
    {
        int d = cubed % 10;
        ++contain[d];
        cubed /= 10;
    }

    for (int i=0;i<10;++i)
        if (contain[i] != 1)
            return 0;
    return 1;
}

void zadaca08_08()
{
    printf("Broevi cij kvadrat i kub zaedno gi sodrzat site cifri(0-9) samo ednas: ");
    for (int i=0;i<10000;++i)
        if (containsSquaredCubedDigitOnce(i*i, i*i*i))
            printf("%d ", i);
    printf("\n\n");
}

void zadaca08_09()
{
    int n, i, j, x, k;
    printf("Vnesete broj na bakterii: ");
    scanf("%d", &n);
    printf("Vnesete na kolku minuti se delat: ");
    scanf("%d", &i);
    printf("Vnesete na kolku minuti umiraat: ");
    scanf("%d", &j);
    printf("Vnesete procent na bakterii koi umiraat: ");
    scanf("%d", &x);
    printf("Vnesete minuti: ");
    scanf("%d", &k);

    for (int g=0;g<k;++g)
    {
        if (g % i == 0)
            n *= 2;
        if (g % j == 0)
            n -= n * (x/100.0);
    }

    printf("Brojot na bakterii posle %d minuti iznesuva: %d\n\n", k, n);
}

int isIncremental(int array[], int start, int end)
{
    if (start >= end)
        return 0;
    if (end - start < 2)
        return 0;
    for (int i=start;i<end-1;++i)
        if (array[i] >= array[i+1])
            return 0;
    return 1;
}

int isDecremental(int array[], int start, int end)
{
    if (start >= end)
        return 0;
    if (end - start < 2)
        return 0;
    for (int i=start;i<end-1;++i)
        if (array[i] <= array[i+1])
            return 0;
    return 1;
}

void printSubArray(int array[], int start, int end)
{
    for (int i=start;i<end;++i)
        printf("%d ", array[i]);
    printf("\n");
}

void zadaca08_10()
{
    srand(time(NULL));

    int size, autog;
    printf("Vnesete golemina na niza (n < 100): ");
    scanf("%d", &size);
    printf("Auto-generated broevi(1/0)? ");
    scanf("%d", &autog);

    int array[100];

    if (autog)
    {
        for (int i=0;i<size;++i)
        {
            int num = rand() % 100;
            printf("Vnesete broj za array[%d]: %d\n", i, num);
            array[i] = num;
        }
    }
    else
    {
        for (int i=0;i<size;++i)
        {
            printf("Vnesete broj za array[%d]: ", i);
            scanf("%d", &array[i]);
        }
    }

    printSubArray(array, 0, size);


    for (int i=0;i<size;++i)
    {
        int start = 0;
        int end = 0;
        int changed = 0;
        for (int j=i;j<size;++j)
        {
            if (isIncremental(array, i, j+1))
            {
                if (j+1-i > end-start)
                {
                    start = i;
                    end = j+1;
                    changed = 1;
                }
            }
        }

        if (changed)
        {
            printSubArray(array, start, end);
            i = end - 1;
        }
    }
}

void zadaca08_11()
{
    srand(time(NULL));

    int size, autog;
    printf("Vnesete golemina na niza (n < 100): ");
    scanf("%d", &size);
    printf("Auto-generated broevi(1/0)? ");
    scanf("%d", &autog);

    int array[100];

    if (autog)
    {
        for (int i=0;i<size;++i)
        {
            int num = rand() % 100;
            printf("Vnesete broj za array[%d]: %d\n", i, num);
            array[i] = num;
        }
    }
    else
    {
        for (int i=0;i<size;++i)
        {
            printf("Vnesete broj za array[%d]: ", i);
            scanf("%d", &array[i]);
        }
    }

    printSubArray(array, 0, size);


    for (int i=0;i<size;++i)
    {
        int start = 0;
        int end = 0;
        int changed = 0;
        for (int j=i;j<size;++j)
        {
            if (isIncremental(array, i, j+1) || isDecremental(array, i, j+1))
            {
                if (j+1-i > end-start)
                {
                    start = i;
                    end = j+1;
                    changed = 1;
                }
            }
        }

        if (changed)
        {
            printSubArray(array, start, end);
            i = end - 1;
        }
    }
}

void printPolynom(int k[], int size)
{
    for (int i=0;i<size;++i)
        printf("%dx^%d%s", k[i], size-i-1, i<size-1?" + ":"");
    printf("\n");
}

void zadaca08_12()
{
    int m, n;
    printf("Vnesete najgolem koeficient za prviot polinom: ");
    scanf("%d", &m);
    printf("Vnesete najgolem koeficient za vtoriot polinom: ");
    scanf("%d", &n);

    int k1[100];
    int k2[100];

    for (int i=0;i<m;++i)
    {
        printf("Vnesete koeficient %c za prviot polinom: ", 'a'+i);
        scanf("%d", &k1[i]);
    }
    for (int i=0;i<n;++i)
    {
        printf("Vnesete koeficient %c za vtoriot polinom: ", 'a'+i);
        scanf("%d", &k2[i]);
    }

    printf("Polinom 1: ");
    printPolynom(k1, m);
    printf("Polinom 2: ");
    printPolynom(k2, n);

    printf("Rezultat: ");
    if (m > n)
    {
        for (int i=0;i<n;++i)
            k1[m-n+i] += k2[i];
        printPolynom(k1, m);
    }
    else
    {
        for (int i=0;i<m;++i)
            k2[n-m+i] += k1[i];
        printPolynom(k2, n);
    }

    printf("\n");
}

void zadaca08_13()
{
    int rows, cols;
    printf("Vnesete redici (m < 100): ");
    scanf("%d", &rows);
    printf("Vnesete koloni (n < 100): ");
    scanf("%d", &cols);

    int matrix[100][100];

    for (int i=0;i<rows;++i)
    {
        for (int j=0;j<cols;++j)
        {
            matrix[i][j] = j*rows+(((j&1) == 0)?i+1:rows-i);
        }

    }

    for (int i=0;i<rows;++i)
    {
        for (int j=0;j<cols;++j)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void printRecursively(int number, int amount, int inc)
{
    if (number <= 1)
    {
        printf("%d", number);
        return;
    }

    for (int i=amount;i<=number;++i)
    {
        printf("%d ", i);
    }
    printf("\n");

    if (inc)
    {
        if (--amount == 1)
            inc = 0;
        printRecursively(number, amount, inc);
    }
    else
    {
        if (++amount == number)
        {
            printf("%d ", number);
            return;
        }
        printRecursively(number, amount, inc);
    }
}

void zadaca08_14()
{
    int num;
    printf("Vnesete broj: ");
    scanf("%d", &num);

    printRecursively(num, num, 1);

    printf("\n\n");
}

#endif // T08_DOMASNO_H
