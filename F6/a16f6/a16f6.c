#include <stdio.h>
#include <string.h>
void FindMax(int array[5][4], int n, double *boys, double *girls);
int main()
{
    int array[5][4] = {{1,40,120,12}, {0,45,110,13}, {0,50,140,14}, {1,40,120,14}, {1,45,135,15}}, i;
    char ca[][7] = {"weight", "height", "age"};
    double boys, girls;
    for (i=1; i<4; i++)
    {
        FindMax(array, i, &boys, &girls);
        printf("Max %s boy: %.1lf\n", ca[i-1], boys);
        printf("Max %s girl: %.1lf\n", ca[i-1], girls);
    }


    return 0;
}


void FindMax(int array[5][4], int n, double *boys, double *girls)
{
    int i;
    *boys = -1;
    *girls = -1;

    for (i=0; i<5; i++)
    {
        if ((array[i][0] == 0) && (*boys < array[i][n]))
        {
            *boys = array[i][n];
        }
        if ((array[i][0] == 1) && (*girls < array[i][n]))
        {
            *girls = array[i][n];
        }
    }

}
