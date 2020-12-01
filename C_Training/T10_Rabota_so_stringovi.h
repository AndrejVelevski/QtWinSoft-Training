#ifndef T10_RABOTA_SO_STRINGOVI_H
#define T10_RABOTA_SO_STRINGOVI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void zadaca10_01()
{
    char telNumber[15];

    printf("Vnesete telefonski broj vo oblik (333) 333-3333: ");
    //scanf("%[^\n]%*c", telNumber);
    gets(telNumber);

    char* token;

    token = strtok(telNumber, "() -");
    char p0[4]; strcpy(p0, token);
    token = strtok(NULL, "() -");
    char p1[4]; strcpy(p1, token);
    token = strtok(NULL, "() -");
    char p2[5]; strcpy(p2, token);

    char fullNumber[11];
    char sevenDigitNumber[8];
    strcat(sevenDigitNumber, p1);
    strcat(sevenDigitNumber, p2);
    strcat(fullNumber, p0);
    strcat(fullNumber, sevenDigitNumber);

    int countryNumber = atoi(p0);
    long sevenDigits = atol(sevenDigitNumber);

    printf("Celosniot broj bez znaci i prazni mesta kako string: %s\n", fullNumber);
    printf("Brojot na drzavata kako int: %d\n", countryNumber);
    printf("Brojot na sedumte cifri kako long: %ld\n\n", sevenDigits);
}

void zadaca10_02()
{
    for (int i=0;i<5;++i)
    {
        int day, month, year;
        printf("Vnesete datum vo formatot dd/mm/yyyy: ");
        scanf("%d%*c%d%*c%d", &day, &month, &year);

        char monthStr[20];
        switch (month)
        {
            case 1: strcpy(monthStr, "Januari"); break;
            case 2: strcpy(monthStr, "Fevruari"); break;
            case 3: strcpy(monthStr, "Mart"); break;
            case 4: strcpy(monthStr, "April"); break;
            case 5: strcpy(monthStr, "Maj"); break;
            case 6: strcpy(monthStr, "Juni"); break;
            case 7: strcpy(monthStr, "Juli"); break;
            case 8: strcpy(monthStr, "Avgust"); break;
            case 9: strcpy(monthStr, "Septemvri"); break;
            case 10: strcpy(monthStr, "Oktomvri"); break;
            case 11: strcpy(monthStr, "Noemvri"); break;
            case 12: strcpy(monthStr, "Dekemvri"); break;
        }

        char formatted[30];
        sprintf(formatted, "%d %s %d", day, monthStr, year);

        printf("%s\n", formatted);
    }
}

void englishToMorse(char* string)
{
    printf("Morse code: ");
    while (1)
    {
        if (*string == '\0')
            break;

        char c = toupper(*string++);

        switch (c)
        {
            case 'A': printf(".- "); break;
            case 'B': printf("-... "); break;
            case 'C': printf("-.-. "); break;
            case 'D': printf("-.. "); break;
            case 'E': printf(". "); break;
            case 'F': printf("..-. "); break;
            case 'G': printf("--. "); break;
            case 'H': printf(".... "); break;
            case 'I': printf(".. "); break;
            case 'J': printf(".--- "); break;
            case 'K': printf("-.- "); break;
            case 'L': printf(".-.. "); break;
            case 'M': printf("-- "); break;
            case 'N': printf("-. "); break;
            case 'O': printf("--- "); break;
            case 'P': printf(".--. "); break;
            case 'Q': printf("--.- "); break;
            case 'R': printf(".-. "); break;
            case 'S': printf("... "); break;
            case 'T': printf("- "); break;
            case 'U': printf("..- "); break;
            case 'V': printf("...- "); break;
            case 'W': printf(".-- "); break;
            case 'X': printf("-..- "); break;
            case 'Y': printf("-.-- "); break;
            case 'Z': printf("--.. "); break;
            case '0': printf("----- "); break;
            case '1': printf(".---- "); break;
            case '2': printf("..--- "); break;
            case '3': printf("...-- "); break;
            case '4': printf("....- "); break;
            case '5': printf("..... "); break;
            case '6': printf("-.... "); break;
            case '7': printf("--... "); break;
            case '8': printf("---.. "); break;
            case '9': printf("----. "); break;
            case '.': printf(".-.-.- "); break;
            case ',': printf("--..-- "); break;
            case '!': printf("-.-.-- "); break;
            case '?': printf("..--.. "); break;
            case ' ': printf("---- "); break;
        }
    }
    printf("\n");
}

void morseToEnglish(char* string)
{
    char* token;

    token = strtok(string, " ");

    while(token != NULL)
    {
             if (strcmp(token, ".-")      == 0) printf("A");
        else if (strcmp(token, "-...")   == 0) printf("B");
        else if (strcmp(token, "-.-.")   == 0) printf("C");
        else if (strcmp(token, "-..")    == 0) printf("D");
        else if (strcmp(token, ".")      == 0) printf("E");
        else if (strcmp(token, "..-.")   == 0) printf("F");
        else if (strcmp(token, "--.")    == 0) printf("G");
        else if (strcmp(token, "....")   == 0) printf("H");
        else if (strcmp(token, "..")     == 0) printf("I");
        else if (strcmp(token, ".---")   == 0) printf("J");
        else if (strcmp(token, "-.-")    == 0) printf("K");
        else if (strcmp(token, ".-..")   == 0) printf("L");
        else if (strcmp(token, "--")     == 0) printf("M");
        else if (strcmp(token, "-.")     == 0) printf("N");
        else if (strcmp(token, "---")    == 0) printf("O");
        else if (strcmp(token, ".--.")   == 0) printf("P");
        else if (strcmp(token, "--.-")   == 0) printf("Q");
        else if (strcmp(token, ".-.")    == 0) printf("R");
        else if (strcmp(token, "...")    == 0) printf("S");
        else if (strcmp(token, "-")      == 0) printf("T");
        else if (strcmp(token, "..-")    == 0) printf("U");
        else if (strcmp(token, "...-")   == 0) printf("V");
        else if (strcmp(token, ".--")    == 0) printf("W");
        else if (strcmp(token, "-..-")   == 0) printf("X");
        else if (strcmp(token, "-.--")   == 0) printf("Y");
        else if (strcmp(token, "--..")   == 0) printf("Z");
        else if (strcmp(token, "-----")  == 0) printf("0");
        else if (strcmp(token, ".----")  == 0) printf("1");
        else if (strcmp(token, "..---")  == 0) printf("2");
        else if (strcmp(token, "...--")  == 0) printf("3");
        else if (strcmp(token, "....-")  == 0) printf("4");
        else if (strcmp(token, ".....")  == 0) printf("5");
        else if (strcmp(token, "-....")  == 0) printf("6");
        else if (strcmp(token, "--...")  == 0) printf("7");
        else if (strcmp(token, "---..")  == 0) printf("8");
        else if (strcmp(token, "----.")  == 0) printf("9");
        else if (strcmp(token, ".-.-.-") == 0) printf(".");
        else if (strcmp(token, "--..--") == 0) printf(",");
        else if (strcmp(token, "-.-.--") == 0) printf("!");
        else if (strcmp(token, "..--..") == 0) printf("?");
        else if (strcmp(token, "----")   == 0) printf(" ");

        token = strtok(NULL, " ");
    }
    printf("\n");
}

void zadaca10_03()
{
    //https://morsecode.world/international/translator.html
    while(1)
    {
        int input;
        printf("0 - Exit\n"
               "1 - English to Morse code\n"
               "2 - Morse code to English\n"
               "Input: ");
        scanf("%d", &input);

        if (input == 0)
            break;

        if (input == 1)
        {
            char string[1000];
            printf("Enter text in English: ");
            scanf(" %[^\n]%*c", string);
            englishToMorse(string);
        }
        else if (input == 2)
        {
            char string[10000];
            printf("Enter text in Morse code: ");
            scanf(" %[^\n]%*c", string);
            morseToEnglish(string);
        }
    }

    printf("\n");
}

#endif // T10_RABOTA_SO_STRINGOVI_H
