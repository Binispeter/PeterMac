#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, max;
    int RandomNums[100]={1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,3,4,4,4,4,4,4,4,4,44,4,4,4,4,4,4,3,3,4,56,5,43,3,2,3,35,235,23,45,14,52,354,1,45,1345,13,45,134,5,23,13,45,234,513,45,234,52,345,23,45,134,523,45,23,45,234,62,346,23,45,234,623,46,134,5,1345,12};

    max = RandomNums[0];
    for (i=0; i<100; i++)
    {
        if (RandomNums[i] > max)
            max = RandomNums[i];

    }
    i=0;

    while (RandomNums[i] != max)
    {
        i++;
    }
        printf("Max: %d in position %d", max, i);
        return 0;
}
