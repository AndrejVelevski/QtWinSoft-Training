#ifndef T01_STRUKTURA_NA_PROGRAMITE_H
#define T01_STRUKTURA_NA_PROGRAMITE_H

#include <stdio.h>

void zadaca01_01()
{
    printf("%s", "a) Namesto scanf(\"d\", vrednost);\n");
    printf("%s", "   Treba scanf(\"%d\", &vrednost);\n\n");

    printf("%s", "b) Namesto printf(\"Proizvodot na %d i %d e %d\"\\n, x, y);\n");
    printf("%s", "   Treba printf(\"Proizvodot na %d i %d e %d\\n\", x, y);\n\n");

    printf("%s", "c) Namesto prvBroj + vtorBroj = sumaBroevi\n");
    printf("%s", "   Treba sumaBroevi = prvBroj + vtorBroj;\n\n");

    printf("%s", "d) Namesto */Programata naogja maksimum od dva broja/*\n");
    printf("%s", "   Treba /*Programata naogja maksimum od dva broja*/\n\n");

    printf("%s", "e) Naredbata Scanf(\"%d\", &nekojBroj);\n");
    printf("%s", "   e dobro napisana.\n\n");
}

void zadaca01_02()
{
    int num1, num2, num3, num4;

    printf("Vnesete 4 celi broevi:\n");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    printf("Suma: %d\n\n", num1+num2+num3+num4);
}

void zadaca01_03()
{
    printf("a) 1234\n\n");
    printf("b) %d%d%d%d\n\n", 1, 2, 3, 4);
    printf("c) ");
    printf("%d", 1);
    printf("%d", 2);
    printf("%d", 3);
    printf("%d", 4);
    printf("\n\n");
}

void zadaca01_04()
{
    int num1, num2, num3;

    printf("Vnesete 3 celi broevi:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    int sum = num1 + num2 + num3;
    int avg = sum / 3;
    int prod = num1 * num2 * num3;

    printf("Celobrojna sredina: %d\n", avg);
    printf("Suma: %d\n", sum);
    printf("Proizvod: %d\n\n", prod);
}

void zadaca01_05()
{
    printf("|   *****   |      ***     |      *      |      *      |\n");
    printf("|   *   *   |     *   *    |     ***     |     * *     |\n");
    printf("|   *   *   |    *     *   |   *******   |    *   *    |\n");
    printf("|   *   *   |    *     *   |      *      |   *     *   |\n");
    printf("|   *   *   |    *     *   |      *      |    *   *    |\n");
    printf("|   *   *   |     *   *    |      *      |     * *     |\n");
    printf("|   *****   |      ***     |      *      |      *      |\n\n");
}

void zadaca01_06()
{
    int num, c1, c2, c3, c4, c5;

    printf("Vnesete petcifren broj:\n");
    scanf("%d", &num);

    c1 = num / 10000;
    c2 = (num / 1000) % 10;
    c3 = (num / 100) % 10;
    c4 = (num / 10) % 10;
    c5 = num % 10;

    printf("%d   %d   %d   %d   %d\n\n", c1, c2, c3, c4, c5);
}

#endif // T01_STRUKTURA_NA_PROGRAMITE_H
