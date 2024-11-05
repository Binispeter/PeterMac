#include <stdio.h>
void funcA ();
void funcB (int times);
void funcC (int choice, int times);
#define notvalid 8
#define C 5

int main()
{
    funcA();
    printf("Give number 5\n");
    funcC(1,C);
    funcC(2,C);
    funcC(notvalid,1);
    funcB(4);

    return 0;
}

void funcA()
{
    int i;
    for (i=1;i<=10;i++)
    {
        printf("learn C\n");

    }
}

void funcB(int times)
{
    int i;
   for (i=1;i<=times;i++)
    {
        printf("learn C\n");

    }
}

void funcC (int choice, int times)
{
    int i;
    for (i=1;i<=times;i++){
    if (choice == 1)
    {
        printf("*-");
    }
    else if (choice == 2)
    {
        printf("*-\n");
    }
    else
    {
        printf("wrong type\n");
        break;
    }
    }
}
