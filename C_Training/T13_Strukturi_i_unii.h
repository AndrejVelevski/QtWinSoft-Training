#ifndef T13_STRUKTURI_I_UNII_H
#define T13_STRUKTURI_I_UNII_H

#include <stdio.h>
#include <stddef.h>

typedef struct
{
    long a;
    char b[17];
    int c;
    double d;
} MyStruct;

void printMyStruct(MyStruct* s)
{
    printf("%ld %s %d %lf\n", s->a, s->b, s->c, s->d);
}

typedef union
{
    int a;
    int b;
    int c;
} MyUnion;

//nemase zadaci od ovoj del
void zadaca13_01()
{
    MyStruct s = {87, "Andrej", 23, 63.8 };

    printf("sizeof(MyStruct) = %lu bytes\n", (unsigned long)sizeof(MyStruct));
    printf("offsetof(MyStruct, a) = %lu bytes\n", (unsigned long)offsetof(MyStruct, a));
    printf("offsetof(MyStruct, b) = %lu bytes\n", (unsigned long)offsetof(MyStruct, b));
    printf("offsetof(MyStruct, c) = %lu bytes\n", (unsigned long)offsetof(MyStruct, c));
    printf("offsetof(MyStruct, d) = %lu bytes\n\n", (unsigned long)offsetof(MyStruct, d));

    printMyStruct(&s);

    printf("\nNormalno:\n");
    printf("s.a = %ld\n", s.a);
    printf("s.b = %s\n", s.b);
    printf("s.c = %d\n", s.c);
    printf("s.d = %f\n\n", s.d);


    long* a = (void*)&s+offsetof(MyStruct, a);
    char* b = (void*)&s+offsetof(MyStruct, b);
    int* c = (void*)&s+offsetof(MyStruct, c);
    double* d = (void*)&s+offsetof(MyStruct, d);
    printf("Preku pointer do memoriska lokacija:\n");
    printf("s.a = %ld\n", *a);
    printf("s.b = %s\n", b);
    printf("s.c = %d\n", *c);
    printf("s.d = %f\n\n", *d);

    MyUnion u;

    printf("sizeof(MyUnion) = %lu\n", (unsigned long)sizeof(MyUnion));
    printf("offsetof(MyUnion, a) = %lu bytes\n", (unsigned long)offsetof(MyUnion, a));
    printf("offsetof(MyUnion, b) = %lu bytes\n", (unsigned long)offsetof(MyUnion, b));
    printf("offsetof(MyUnion, c) = %lu bytes\n\n", (unsigned long)offsetof(MyUnion, c));

    u.a = 4;
    printf("Postavuvame u.a = 4\n");

    printf("u.a = %d\n", u.a);
    printf("u.b = %d\n", u.b);
    printf("u.c = %d\n\n", u.c);

    u.b = 2;
    printf("Postavuvame u.b = 2\n");

    printf("u.a = %d\n", u.a);
    printf("u.b = %d\n", u.b);
    printf("u.c = %d\n\n", u.c);
}

#endif // T13_STRUKTURI_I_UNII_H
