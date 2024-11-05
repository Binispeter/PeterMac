#include <stdio.h>
#include <stdbool.h>
bool disekto (int year);
int main()
{   int i, from, until;
    printf("Apo etos: ");
    scanf("%d", &from);
    printf("Eos etos: ");
    scanf("%d", &until);
    for (i=from; i<=until; i++)
    {
        if (disekto(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

bool disekto(int year)
{
    if ((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else return false;
}
