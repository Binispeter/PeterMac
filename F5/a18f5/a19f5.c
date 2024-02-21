#include <stdio.h>
int main()
{
    int array[3][4];
    int i,j;
    for (i=0; i<3; i++)
    {
        for (j=0; j<4; j++)
        {
            array[i][j] = i + j;
        }
    }
     for (i=0; i<3; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    return 0;
}
