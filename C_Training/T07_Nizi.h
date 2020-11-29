#ifndef T07_NIZI_H
#define T07_NIZI_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void zadaca07_01()
{
    srand(time(NULL));

    int month;
    printf("Vnesete mesec(1-12): ");
    scanf("%d", &month);

    int autog;
    printf("Auto-generated temperaturi(1/0)? ");
    scanf("%d", &autog);

    int days;
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            days = 28;
            break;
        default:
           days = 30;
    }

    /*
        ova raboti i dokolku e temperatures[days]
        no kako shto procitav ova e samo validno za C99
        i najverojatno MinGW go poddrzuva
        so MSVC ova nema da raboti
        https://stackoverflow.com/questions/737240/array-size-at-run-time-without-dynamic-allocation-is-allowed
    */

    int temperatures[31];

    if (autog)
    {
        for(int i=0;i<days;++i)
        {
            int temp = rand() % 30;
            printf("Vnesete temperatura za den %d: %d\n", i+1, temp);
            temperatures[i] = temp;
        }
    }
    else
    {
        for(int i=0;i<days;++i)
        {
            printf("Vnesete temperatura za den %d: ", i+1);
            scanf("%d", &temperatures[i]);
        }
    }

    float average = 0;
    for (int i=0;i<days;++i)
    {
        average += temperatures[i];
    }
    average /= days;

    printf("Prosecnata temperatura iznesuva %f stepeni\n\n", average);
}

int prime(int number)
{
    if (number < 2)
        return 0;

    for (int i=2;i<=(int)sqrt(number);++i)
    {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

void prosti(int array[], int size)
{
    for (int i=0;i<size;++i)
    {
        if (prime(i))
            array[i] = 0;
    }
}

void zadaca07_02()
{
    int size;
    printf("Vnesete broj na elementi (size < 1000): ");
    scanf("%d", &size);

    int array[1000];

    for (int i=0;i<size;++i)
        array[i] = 1;

    prosti(array, size);

    for (int i=0;i<size;++i)
    {
        if (!array[i])
            printf("%d ", i);
    }
    printf("\n\n");
}

int palindrom(const char string[], int size)
{
    for (int i=0;i<size/2;++i)
        if (string[i] != string[size-i-1])
            return 0;
    return 1;
}

void zadaca07_03()
{
    char string[30];
    printf("Vnesete zbor: ");
    scanf("%[^\n]%*c", string);

    int size = 0;
    for (int i=0;string[i] !='\0';++i)
        ++size;

    printf("Zborot %s %se palindrom\n\n", string, palindrom(string, size)?"":"ne ");
}

void vnesiMatricaI(int matrix[100][100], int rows, int cols)
{
    for (int i=0;i<rows;++i)
    {
        for (int j=0;j<cols;++j)
        {
            printf("Vnesete broj za matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void pechatiMatricaI(int matrix[100][100], int rows, int cols)
{
    for (int i=0;i<rows;++i)
    {
        for (int j=0;j<cols;++j)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void vnesiMatricaR(int matrix[100][100], int rows, int cols)
{
    static int i = 0;
    static int j = 0;

    printf("Vnesete broj za matrix[%d][%d]: ", i, j);
    scanf("%d", &matrix[i][j]);

    if (++j == cols)
    {
        if (++i == rows)
        {
            i = 0;
            j = 0;
            return;
        }

        j = 0;
    }

    vnesiMatricaR(matrix, rows, cols);
}

void pechatiMatricaR(int matrix[100][100], int rows, int cols)
{
    static int i = 0;
    static int j = 0;

    printf("%d\t", matrix[i][j]);

    if (++j == cols)
    {
        if (++i == rows)
        {
            i = 0;
            j = 0;
            return;
        }

        printf("\n");
        j = 0;
    }

    pechatiMatricaR(matrix, rows, cols);
}

void zadaca07_04()
{
    int rows, cols;
    printf("Vnesete redici i koloni (m, n < 100): ");
    scanf("%d %d", &rows, &cols);

    int matrix[100][100];

    vnesiMatricaI(matrix, rows, cols);
    pechatiMatricaI(matrix, rows, cols);

    printf("\n");

    vnesiMatricaR(matrix, rows, cols);
    pechatiMatricaR(matrix, rows, cols);

    printf("\n\n");
}

void selectionSortI(int array[], int size)
{
    for (int i=0;i<size;++i)
    {
        int minIdx = i;

        for (int j=i+1;j<size;++j)
            if (array[j] < array[minIdx])
                minIdx = j;

        int temp = array[i];
        array[i] = array[minIdx];
        array[minIdx] = temp;
    }
}

void selectionSortR(int array[], int size)
{
    static int i = 0;
    static int j = 0;
    static int minIdx = 0;

    if (j++ == size-1)
    {
        int temp = array[i];
        array[i] = array[minIdx];
        array[minIdx] = temp;

        j = ++i+1;
        minIdx = i;

        if (i == size-1)
        {
            i = 0;
            j = 0;
            minIdx = 0;
            return;
        }
    }

    if (array[j] < array[minIdx])
            minIdx = j;

    selectionSortR(array, size);
}

void zadaca07_05()
{
    srand(time(NULL));

    int size;
    printf("Vnesete golemina na niza (n < 100): ");
    scanf("%d", &size);

    int array1[100];
    int array2[100];

    int autog;
    printf("Auto-generated broevi(1/0)? ");
    scanf("%d", &autog);

    if (autog)
    {
        for(int i=0;i<size;++i)
        {
            int num = rand() % 100;
            printf("Vnesete broj za array[%d]: %d\n", i, num);
            array1[i] = num;
            array2[i] = num;
        }
    }
    else
    {
        for(int i=0;i<size;++i)
        {
            printf("Vnesete broj za array[%d]: ", i);
            int num;
            scanf("%d", &num);
            array1[i] = num;
            array2[i] = num;
        }
    }

    printf("Original: ");
    for (int i=0;i<size;++i)
        printf("%d ", array1[i]);
    printf("\n");

    printf("Iterative selection sort: ");
    selectionSortI(array1, size);
    for (int i=0;i<size;++i)
        printf("%d ", array1[i]);
    printf("\n");

    printf("Original: ");
    for (int i=0;i<size;++i)
        printf("%d ", array2[i]);
    printf("\n");

    printf("Recursive selection sort: ");
    selectionSortR(array2, size);
    for (int i=0;i<size;++i)
        printf("%d ", array2[i]);

    printf("\n\nIsti se zatoa sto i dvata algoritmi vo prvata iteracija go nosat najmaliot clen\n");
    printf("na pocetok na nizata, pa ja pocnuvaat istata postapka povtorno od naredniot clen. Bubble sort\n");
    printf("pravi size-1 swap na sosedni broevi vo prvata iteracija, dodeka selection sort go bara\n");
    printf("najmaliot broj pri sto treba da pobara niz size-1 clenovi vo prvata iteracija i pravi swap.\n\n");
}

void bubbleSort(int array[], int size)
{
    for (int i=0;i<size-1;++i)
    {
        for (int j=i+1;j<size;++j)
        {
            if (array[j] < array[i])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printArray(int array[], int size)
{
    for (int i=0;i<size;++i)
        printf("%d ", array[i]);
    printf("\n");
}

double average(int array[], int size)
{
    double sum = 0;
    for (int i=0;i<size;++i)
        sum += array[i];
    return sum / size;
}

double median(int array[], int size)
{
    if ((size&1) != 0)
        return (double)array[size/2];
    return (array[size/2-1] + array[size/2]) / 2.0;
}

void calculateHistogram(int array[], int histogram[], int size)
{
    for (int i=0;i<size;++i)
        ++histogram[array[i]];
}

int mostFrequentValue(int histogram[], int size)
{
    int max = 0;
    for (int i=1;i<size;++i)
    {
        if (histogram[i] > histogram[max])
            max = i;
    }
    return max;
}

void zadaca07_06()
{
    srand(time(NULL));

    int size;
    printf("Vnesete golemina na niza (n < 100): ");
    scanf("%d", &size);

    int array[100];
    int histogram[50] = {0};

    int autog;
    printf("Auto-generated broevi(1/0)? ");
    scanf("%d", &autog);

    if (autog)
    {
        for(int i=0;i<size;++i)
        {
            int num = rand() % 50;
            printf("Vnesete broj za array[%d]: %d\n", i, num);
            array[i] = num;
        }
    }
    else
    {
        for(int i=0;i<size;++i)
        {
            printf("Vnesete broj za array[%d]: ", i);
            int num;
            scanf("%d", &num);
            array[i] = num;
        }
    }

    printf("\nJa vnesovte nizata: ");
    printArray(array, size);
    printf("Sortirana niza: ");
    bubbleSort(array, size);
    printArray(array, size);
    printf("Sredna vrednost: %f\n", average(array, size));
    printf("Medijana: %.1f\n", median(array, size));
    calculateHistogram(array, histogram, size);
    printf("Najfrekventra vrednost: %d\n", mostFrequentValue(histogram, 50));
    printf("Histogram: ");
    printArray(histogram, 50);
    printf("\n");
}

#endif // T07_NIZI_H
