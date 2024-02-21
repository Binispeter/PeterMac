#include <stdio.h>
int copy(int a[10], int b[10], int ar);
int main()
{
    int ar[10] = {1,2,3,4,5,6,7,8,9,10};
    int br[10];
    int num = 0;
    num = copy(ar, br, 5);
    printf("Number of numbers above 5: %d", num);
    return 0;
}

int copy(int a[10], int b[10], int ar)
{
    int i, j = 0;
    for (i=0; i<10; i++)
    {
        if (a[i] > ar)
        {
            b[j] = a[i];
            j++;
        }
    }
    return j;
}
