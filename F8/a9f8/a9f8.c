#include <stdio.h>

typedef struct
{
    char name[10];
    char surname[10];
    float hour_wage;
    int hours;
    float mixed;
    float booked;
    float tax;
    float clean;
}employee;

void get_data(int n, employee data[n]);

int main()
{
    int n;
    employee data[30];

    printf("Enter the number of professors: ");
    scanf("%d", &n);

    get_data(n, data);

    return 0;
}

void get_data(int n, employee data[n])
{
    int i;

    for (i=0; i<n; i++)
    {
        printf("Enter the details of professor %d\n", i);

        printf("Name: ");
        scanf("%s", data[i].name);

        printf("Surname: ");
        scanf("%s", data[i].surname);

        printf("Hourly Wage: ");
        scanf("%f", &data[i].hour_wage);


        printf("Working Hours: ");
        scanf("%d", &data[i].hours);

        printf("\n");

    }
}
