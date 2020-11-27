#ifndef T02_STRUKTURA_NA_PROGRAMITE_H
#define T02_STRUKTURA_NA_PROGRAMITE_H

#include <stdio.h>

//nemase vezbi od ovoj del, samo go napisav prviot primer
void zadaca02_01()
{
    int num1, num2;

    printf("Vnesi dva celi broja\n");
    scanf("%d %d", &num1, &num2);

    printf("Relacii koi gi zadovoluvaat:\n");


    if (num1 == num2)
        printf("%d e ednakov so %d\n", num1, num2);

    if (num1 !=num2)
        printf("%d ne e ednakov so %d\n", num1, num2);

    if (num1 < num2)
        printf("%d e pomal od %d\n", num1, num2);

    if (num1 > num2)
        printf("%d e pogolem od %d\n", num1, num2);

    if (num1 <= num2)
        printf("%d e pomal ili ednakov so %d\n", num1, num2);

    if (num1 >= num2)
        printf("%d e pogolem ili ednakov so %d\n", num1, num2);

    if (num1 % num2 == 0)
        printf("%d e deliv so %d\n", num1, num2);

    printf("\n");
}

#endif // T02_STRUKTURA_NA_PROGRAMITE_H
