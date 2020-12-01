#ifndef T12_DATOTEKI_H
#define T12_DATOTEKI_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    int kod;
    char ime[20];
    int kolicina;
    double cena;
} Hardware;

void pecatiDatoteka()
{
    FILE* file;
    file = fopen("hardware.dat", "r");

    printf("%-10s %-20s %-10s %-10s\n", "Kod", "Ime na del", "Kolicina", "Cena");

    Hardware h;

    while (1)
    {
        fread(&h, sizeof(Hardware), 1, file);
        if (feof(file))
            break;

        if (h.kod != -1)
            printf("%-10d %-20s %-10d %-10.2f\n", h.kod, h.ime, h.kolicina, h.cena);
    }

    fclose(file);
}

void vnesiNovProizvod()
{
    FILE* file;
    file = fopen("hardware.dat", "ab");

    int kod;
    char ime[20];
    int kolicina;
    double cena;

    printf("Vnesete kod: ");
    scanf("%d", &kod);
    printf("Vnesete ime: ");
    scanf(" %[^\n]%*c", ime);
    printf("Vnesete kolicina: ");
    scanf("%d", &kolicina);
    printf("Vnesete cena: ");
    scanf("%lf", &cena);

    Hardware h;
    h.kod = kod;
    strcpy(h.ime, ime);
    h.kolicina = kolicina;
    h.cena = cena;

    fwrite(&h, sizeof(Hardware), 1, file);

    fclose(file);
}

void azurirajProizvod()
{
    FILE* file;
    file = fopen("hardware.dat", "rb+");

    int kod;
    printf("Vnesete kod na proizvodot: ");
    scanf("%d", &kod);

    Hardware h;
    for (int i=0;;++i)
    {
        fread(&h, sizeof(Hardware), 1, file);
        if (feof(file))
            break;

        if (h.kod == kod)
        {
            char ime[20];
            int kolicina;
            double cena;

            printf("Vnesete ime: ");
            scanf(" %[^\n]%*c", ime);
            printf("Vnesete kolicina: ");
            scanf("%d", &kolicina);
            printf("Vnesete cena: ");
            scanf("%lf", &cena);

            strcpy(h.ime, ime);
            h.kolicina = kolicina;
            h.cena = cena;

            fseek(file, i*sizeof(Hardware), SEEK_SET);
            fwrite(&h, sizeof(Hardware), 1, file);

            fclose(file);
            return;
        }
    }

    printf("Ne postoi proizvod so toj kod.\n");

    fclose(file);
}

void kupiProizvod()
{
    FILE* file;
    file = fopen("hardware.dat", "rb+");

    int kod;
    printf("Vnesete kod na proizvodot: ");
    scanf("%d", &kod);

    Hardware h;
    for (int i=0;;++i)
    {
        fread(&h, sizeof(Hardware), 1, file);
        if (feof(file))
            break;

        if (h.kod == kod)
        {
            int kolicina;
            printf("Vnesete kolicina koja sakate da ja kupite: ");
            scanf("%d", &kolicina);

            if (h.kolicina >= kolicina)
            {
                h.kolicina -= kolicina;
                fseek(file, i*sizeof(Hardware), SEEK_SET);
                if (h.kolicina > 0)
                    fwrite(&h, sizeof(Hardware), 1, file);
                else
                {
                    Hardware e;
                    e.kod = -1;
                    fwrite(&e, sizeof(Hardware), 1, file);
                }
            }
            else
            {
                printf("Najgolema kolicina shto moze da ja kupite e %d.\n", h.kolicina);
            }

            fclose(file);
            return;
        }
    }

    printf("Ne postoi proizvod so toj kod.\n");

    fclose(file);
}

void zadaca12_01()
{
    FILE* file;

    if ((file = fopen("hardware.dat", "r")) == NULL)
    {
        file = fopen("hardware.dat", "wb");
        if (file == NULL)
        {
            printf("Nemoze da se kreira hardware.dat\n");
            return;
        }

        Hardware h[4] = { { 3, "glusec Mico",     7, 10.34 },
                          {56, "monitor Kiki3",   5, 65.09 },
                          {75, "tastatura Biko8", 4, 12.09 },
                          {89, "matploc Ziko32",  6, 87.09 } };

        fwrite(&h, sizeof(Hardware), 4, file);

        fclose(file);
    }

    while(1)
    {
        int input;
        printf("_________________________________________________\n"
               "0 - Izlez\n"
               "1 - Kompleten listing\n"
               "2 - Nov proizvod\n"
               "3 - Kupi proizvod\n"
               "4 - Azuriraj proizvod\n"
               "Izbor: ");
        scanf("%d", &input);

        if (input == 0)
            break;

        switch (input)
        {
            case 1:
                pecatiDatoteka();
                break;
            case 2:
                vnesiNovProizvod();
                break;
            case 3:
                kupiProizvod();
                break;
            case 4:
                azurirajProizvod();
                break;
        }
    }

    pecatiDatoteka();

    printf("\n");
}



long numberFromString(char* string)
{
    char new[8];
    new[7] = '\n';

    for (int i=0;i<8;++i)
    {
        switch (string[i])
        {
            case 'A': case 'B': case 'C': new[i] = '2'; break;
            case 'D': case 'E': case 'F': new[i] = '3'; break;
            case 'G': case 'H': case 'I': new[i] = '4'; break;
            case 'J': case 'K': case 'L': new[i] = '5'; break;
            case 'M': case 'N': case 'O': new[i] = '6'; break;
            case 'P': case 'Q': case 'R': new[i] = '7'; break;
            case 'S': case 'T': case 'U': new[i] = '8'; break;
            case 'V': case 'W': case 'X': new[i] = '9'; break;
            case 'Y': case 'Z':           new[i] = '0'; break;
        }
    }

    return atol(new);
}

void printNumberToString(long number)
{
    char new[8];

    ltoa(number, new, 10);

    int counters[7] = {0};
    int canIncrement = 0;

    for (int i=0;;++i)
    {
        int c = i%7;

        int digit = new[c] - '0';
        digit -= 2;
        if (digit == -2)
            digit = 8;

        digit = digit*3 + counters[c];

        if (canIncrement)
        {
            int done = 0;
            for (int j=6;j>=0;--j)
            {
                if (++counters[j] >= (new[j] == '0'?2:3))
                {
                    counters[j] = 0;
                    if (j == 0)
                        done = 1;
                }
                else
                    break;
            }

            if (done)
                break;

            canIncrement = 0;
        }

        printf("%c", 'A'+digit);

        if (c == 6)
        {
            printf("\n");
            canIncrement = 1;
        }

    }
}

void zadaca()
{
    char str[8];
    printf("Vnesete 7 bukvi: ");
    scanf("%s", str);
    for (int i=0;i<7;++i)
        str[i] = toupper(str[i]);

    printf("Dobieniot broj e: %ld\n", numberFromString(str));

    long number;
    printf("Vnesete 7 cifren broj: ");
    scanf("%ld", &number);
    printNumberToString(number);

    printf("\n");
}

#endif // T12_DATOTEKI_H
