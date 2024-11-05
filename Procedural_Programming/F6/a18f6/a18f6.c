#include <stdio.h>
#include <stdlib.h>
int populate(int rows, int columns, int array[rows][columns], int *seed);
void printTab_2d(int rows, int columns, int array[rows][columns]);
void FindStudents(int rows, int columns, int array[rows][columns], int *pexceln, double *ppercExcel, int *pfailn, double *ppercFail);
int main()
{
 int grades[30][3], seed, fail, excel;
 double perfail, perexcel;
 populate(30, 3, grades, &seed);
 printTab_2d(30, 3, grades);
 FindStudents(30, 3, grades, &excel, &perexcel, &fail, &perfail);
 printf("Succeed: %d, %.1lf%%\n", excel, perexcel);
 printf("Fail: %d, %.1lf%%", fail, perfail);

 return 0;
}
int populate(int rows, int columns, int array[rows][columns], int *seed)
{
    int i, j, seedk = 0;
    *seed = seedk;
    printf("Give seed: ");
    scanf("%d", &seedk);
    srand(seedk);
    for (i=0; i<rows; i++)
    {
        for (j=0; j<columns; j++)
        {
            array[i][j] = rand() % 21;
        }
    }
    return array[rows][columns];
}
void printTab_2d(int rows, int columns, int array[rows][columns])
{
    int i, j;
    for (i=0; i<rows; i++)
    {
        for (j=0; j<columns; j++)
        {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}
void FindStudents(int rows, int columns, int array[rows][columns], int *pexceln, double *ppercExcel, int *pfailn, double *ppercFail)
{
    int i, j, sum = 0, exceln =0, failn =0;
    double average, percExcel=0.0, percFail=0.0;

    for (i=0; i<rows; i++)
    {
        for (j=0; j<columns; j++)
        {
            sum += array[i][j];
        }
        average = sum / 3.0;
        if (average < 9.5)
        {
            failn++;
        }
        else if(average > 18.5)
        {
            exceln++;
        }
        sum = 0;

    }
    percExcel = (exceln / 30.0) * 100.0;
    percFail = (failn / 30.0) * 100.0;

    *ppercExcel = percExcel;
    *ppercFail = percFail;
    *pexceln = exceln;
    *pfailn = failn;

}
