#ifndef T11_BITSKI_OPERATORI_H
#define T11_BITSKI_OPERATORI_H

#include <stdio.h>
#include <string.h>
#include <stddef.h>

int mnoziSoStepenOdDva(int number, int exponent)
{
    return number * (1 << exponent);
}

void zadaca11_01()
{
    int number, exponent;
    printf("Vnesete broj: ");
    scanf("%d", &number);
    printf("Vnesete eksonent: ");
    scanf("%d", &exponent);
    printf("Rezultatot iznesuva: %d\n\n", mnoziSoStepenOdDva(number, exponent));
}

unsigned prevrtiBitovi(unsigned number)
{
    unsigned reversed = 0;

    for (int i=0;i<32;++i)
    {
        unsigned temp = (number & (1 << i));
        if(temp)
            reversed |= (1 << (31 - i));
    }

    return reversed;
}

void printBits(unsigned number)
{
    int mask = 1 << 31;
    for (int i=1;i<=32;++i)
    {
        putchar((number&mask)?'1':'0');
        number <<= 1;
        if (i%8 == 0)
            putchar(' ');
    }
    putchar('\n');
}

void zadaca11_02()
{
    unsigned int number;
    printf("Vnesete broj: ");
    scanf("%d", &number);

    printf("Originalni %u: ", number);
    printBits(number);

    number = prevrtiBitovi(number);

    printf("Prevrteni %u: ", number);
    printBits(number);
    printf("\n");
}

int misterija(unsigned bitovi)
{
    unsigned i;
    unsigned maska = 1 << 31;
    unsigned total = 0;
    for (i = 1; i <= 32; i++, bitovi <<= 1)
    {
        if ( ( bitovi & maska ) == maska )
        {
            total++;
        }
    }
    return !(total % 2) ? 1 : 0;
}

void zadaca11_03()
{
    unsigned x;
    printf("Vnesi cel broj: " );
    scanf("%u", &x);
    printf("Rezultatot e %d\n", misterija(x));

    printBits(x);

    printf("Funkcijata vrakja true/false vo zavisnost dali zbirot\n"
           "na site bitovi e paren(true) ili neparen(false).\n\n");
}

typedef enum {
    FEMALE, MALE
} Gender;

typedef struct
{
    unsigned id;
    char name[15];
    char surname[15];
    unsigned age;
    Gender gender;
    unsigned credibility;
    char address[30];
    unsigned currentSalary;
    unsigned previousSalary;

} Employee;

void printHeader()
{
    printf("%-5s %-15s %-15s %-10s %-10s %-15s %-30s %-20s %-20s\n", "ID", "Name", "Surname", "Age", "Gender", "Credibility", "Address", "Current Salary", "Previous Salary");
}

void printEmployee(const Employee* employee)
{
    Employee e = *employee;
    printf("%-5u %-15s %-15s %-10u %-10s %-15u %-30s %-20u %-20u\n",
           e.id, e.name, e.surname, e.age, e.gender==MALE?"Male":"Female",
           e.credibility, e.address, e.currentSalary, e.previousSalary);
}

Employee createEmployee(unsigned id, const char* name, const char* surname, unsigned age,
                        Gender gender, unsigned credibility, const char* address,
                        unsigned currentSalary, unsigned previousSalary)
{
    Employee e;
    e.id = id;
    strcpy(e.name, name);
    strcpy(e.surname, surname);
    e.age = age;
    e.gender = gender;
    e.credibility = credibility;
    strcpy(e.address, address);
    e.currentSalary = currentSalary;
    e.previousSalary = previousSalary;
    return e;
}

Employee getEmployeeData(int id)
{
    char name[15];
    char surname[15];
    unsigned age;
    unsigned gender;
    unsigned credibility;
    char address[30];
    unsigned currentSalary;
    unsigned previousSalary;
    printf("Enter name: "); scanf(" %[^\n]%*c", name);
    printf("Enter surname: "); scanf(" %[^\n]%*c", surname);
    printf("Enter age: "); scanf("%u", &age);
    printf("Enter gender(0 - female, 1 - male): "); scanf("%d", &gender);
    printf("Enter credibility: "); scanf("%u", &credibility);
    printf("Enter address: "); scanf(" %[^\n]%*c", address);
    printf("Enter current salary: "); scanf("%u", &currentSalary);
    printf("Enter previous salary: "); scanf("%u", &previousSalary);

    return createEmployee(id, name, surname, age, gender, credibility,
                          address, currentSalary, previousSalary);
}

void editCredibility(Employee* employees, int size)
{
    for (int i=0;i<size;++i)
    {
        Employee* e = &employees[i];
        if (e->currentSalary > e->previousSalary)
        {
            e->credibility += 3;
            e->previousSalary = e->currentSalary;
        }
        else if (e->currentSalary < e->previousSalary)
        {
            e->credibility -= 3;
            e->currentSalary = e->previousSalary;
        }
    }
}

void sortEmployees(Employee* employees, int size, unsigned member)
{
    for (int i=0;i<size;++i)
    {
        int minIdx = i;

        for (int j=i+1;j<size;++j)
            if (*((unsigned*)(&employees[j])+member/4) < *((unsigned*)(&employees[minIdx])+member/4))
                minIdx = j;

        Employee temp = employees[i];
        employees[i] = employees[minIdx];
        employees[minIdx] = temp;
    }
}

void zadaca11_04()
{
    int id = 0;
    Employee employees[50];

    employees[id] = createEmployee(id, "Jovan", "Jovanovski", 20, MALE, 70, "st. SomeAddress 123/1", 17800, 15300); ++id;
    employees[id] = createEmployee(id, "Ana", "Anevska", 34, FEMALE, 43, "st. SomeAddress 41\\5\\7", 38400, 20500); ++id;
    employees[id] = createEmployee(id, "Angel", "Angelovski", 29, MALE, 60, "st. SomeAddress 41\\5\\7", 30000, 30000); ++id;
    employees[id] = createEmployee(id, "Maja", "Maevska", 25, FEMALE, 91, "st. SomeAddress 30", 23480, 28500); ++id;
    employees[id] = createEmployee(id, "Kosta", "Kostovski", 50, MALE, 58, "st. SomeAddress 12.58A", 25700, 23800); ++id;
    employees[id] = createEmployee(id, "Jana", "Janevska", 23, FEMALE, 23, "st. SomeAddress 222HB2", 31500, 36800); ++id;

    while(1)
    {
        int input;
        printf("___________________________________________\n"
               " 0 - Exit\n"
               " 1 - Print all employees\n"
               " 2 - Add new employee\n"
               " 3 - Sort by id\n"
               " 4 - Sort by age\n"
               " 5 - Sort by gender\n"
               " 6 - Sort by credibility\n"
               " 7 - Sort by current salary\n"
               " 8 - Sort by previous salary\n"
               " 9 - Edit employee\n"
               "10 - Edit credibility\n"
               "Input: ");
        scanf("%d", &input);

        if (input == 0)
            break;

        switch (input)
        {
            case 1:
                printHeader();
                for (int i=0;i<id;++i)
                    printEmployee(&employees[i]);
                break;
            case 2:
            {
                employees[id] = getEmployeeData(id);
                ++id;
                break;
            }
            case 3:
                sortEmployees(employees, id, offsetof(Employee, id));
                break;
            case 4:
                sortEmployees(employees, id, offsetof(Employee, age));
                break;
            case 5:
                sortEmployees(employees, id, offsetof(Employee, gender));
                break;
            case 6:
                sortEmployees(employees, id, offsetof(Employee, credibility));
                break;
            case 7:
                sortEmployees(employees, id, offsetof(Employee, currentSalary));
                break;
            case 8:
                sortEmployees(employees, id, offsetof(Employee, previousSalary));
                break;
            case 9:
            {
                int editId;
                printf("Please enter ID of employee 0-%d: ", id-1);
                scanf("%d", &editId);

                if (editId >= 0 && editId < id)
                    employees[editId] = getEmployeeData(editId);

                break;
            }
            case 10:
                editCredibility(employees, id);
                break;

        }

    }

    printf("\n");
}

#endif // T11_BITSKI_OPERATORI_H
