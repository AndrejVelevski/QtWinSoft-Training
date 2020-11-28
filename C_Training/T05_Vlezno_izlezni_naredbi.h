#ifndef T05_VLEZNO_IZLEZNI_NAREDBI_H
#define T05_VLEZNO_IZLEZNI_NAREDBI_H

#include <stdio.h>

void zadaca05_01()
{
    double fahrenheit;
    printf("Vnesete temperatura vo farenhajotvi: ");
    scanf("%lf", &fahrenheit);

    double celsius = 5.0 / 9.0 * (fahrenheit - 32.0);
    printf("Temperaturata vo celziusovi iznesuva %.3f\n\n", celsius);
}

void zadaca05_02()
{
    int day;
    int month;
    int year;
    printf("Vnesi datum: ");
    scanf("%d%*c%d%*c%d", &year, &month, &day);

    switch (month)
    {
        case 1: printf("Vneseniot datum e %d %s %d godina.", day, "Januari", year); break;
        case 2: printf("Vneseniot datum e %d %s %d godina.", day, "Fevruari", year); break;
        case 3: printf("Vneseniot datum e %d %s %d godina.", day, "Mart", year); break;
        case 4: printf("Vneseniot datum e %d %s %d godina.", day, "April", year); break;
        case 5: printf("Vneseniot datum e %d %s %d godina.", day, "Maj", year); break;
        case 6: printf("Vneseniot datum e %d %s %d godina.", day, "Juni", year); break;
        case 7: printf("Vneseniot datum e %d %s %d godina.", day, "Juli", year); break;
        case 8: printf("Vneseniot datum e %d %s %d godina.", day, "Avgust", year); break;
        case 9: printf("Vneseniot datum e %d %s %d godina.", day, "Septemvri", year); break;
        case 10: printf("Vneseniot datum e %d %s %d godina.", day, "Oktomvri", year); break;
        case 11: printf("Vneseniot datum e %d %s %d godina.", day, "Noemvri", year); break;
        case 12: printf("Vneseniot datum e %d %s %d godina.", day, "Dekemvri", year); break;
    }

    printf("\n\n");
}

#endif // T05_VLEZNO_IZLEZNI_NAREDBI_H
