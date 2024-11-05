#include <stdio.h>

typedef struct
{
    int code;
    char name[16];
    long sales;
    int area;
}salesmen;

void read(int m, salesmen data[m]);
void calc(int m, salesmen data[m], long array[5]);
void printing(int m, salesmen data[m], long array[5]);

int main()
{
    int m;
    salesmen data[20];
    long array[5] = {0};

    printf("Enter the number of salesmen: ");
    scanf("%d", &m);

    read(m, data);
    calc(m, data, array);
    printing(m, data, array);

    return 0;
}

void read(int m, salesmen data[m])
{
    int i;
    for (i=0; i<m; i++)
    {
        printf("Code: ");
        scanf("%d", &data[i].code);

        printf("Name: ");
        scanf("%s", data[i].name);

        printf("Sales Amount: ");
        scanf("%ld", &data[i].sales);

        printf("Area: ");
        scanf("%d", &data[i].area);
        while (getchar()!='\n');

        printf("\n");
    }
}

void calc(int m, salesmen data[m], long array[5])
{
    int i;

    for (i=0; i<m; i++)
    {

        if(data[i].area==1)
            array[0]+=data[i].sales;

        else if(data[i].area==2)
            array[1]+=data[i].sales;

        else if(data[i].area==3)
            array[2]+=data[i].sales;

        else
            array[3]+=data[i].sales;
    }
        for (i=0; i<4; i++)
        {
            array[4] += array[i];
        }
}

void printing(int m, salesmen data[m], long array[5])
{
    printf("%11s %12s\n", "PERIOXH", "SYN.PWLHSEWN");
    for (int i=0; i<27; i++)
    {
        printf("-");
    }
    printf("\n%11s %12ld\n", "Thes/niki", array[0]);
    printf("%11s %12ld\n", "Athens", array[1]);
    printf("%11s %12ld\n", "Volos", array[2]);
    printf("%11s %12ld\n", "Hrakleio", array[3]);
    for (int i=0; i<27; i++)
    {
        printf("-");
    }
    printf("\n%11s %12ld\n", "SYNOLO", array[4]);
}
