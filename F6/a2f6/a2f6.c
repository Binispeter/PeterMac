#include <stdio.h>

int readData(int array[100]);
void findMinMax(int num, int array[num], int *max, int *min);
int main()
{
    int array[100] = {0};
    int num;
    int rmin=0, rmax=0;


    printf("Enter the elements of the array, one per line.\nUse -1 to signal the end of the list.\n");
    num = readData(array);



    findMinMax(num, array, &rmax, &rmin);

    printf("The range of values is %d-%d\n", rmin, rmax);
    return 0;
}

int readData(int array[100])
{
    int i=0, num=0, element=0;
    for (i=0; i<100; i++)
    {
        printf("? ");
        scanf("%d", &element);
        if (element == -1)
        {
            break;

        }
         array[i] = element;
            num++;
    }
    return num;
}

void findMinMax(int num, int array[num], int *max, int *min)
{

    int rmax = array[0];
    int rmin = array[0];
    for (int i=0; i<num; i++)
    {
        if (array[i] < rmin)
        {
            rmin = array[i];
        }
        else if (array[i] > rmax)
        {
            rmax = array[i];
        }
    }
    *max = rmax;
    *min = rmin;
}
