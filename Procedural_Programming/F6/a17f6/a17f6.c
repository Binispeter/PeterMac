#include <stdio.h>
int ReadData(int rows, int columns, int array[rows][columns]);
void printTab_2d(int rows, int columns, int array[rows][columns]);
void FindMaxRowMinCol (int rows, int columns, int array[rows][columns], int line, int col, int *maxRow, int *minCol);
int main()
{
    int nums[3][4], row, column, maxR, minC;
    ReadData(3, 4, nums);
    printTab_2d(3, 4, nums);

    printf("Give row ");
    scanf("%d", &row);
    printf("Give column ");
    scanf("%d", &column);
    FindMaxRowMinCol(3, 4, nums, row, column, &maxR, &minC);
    printf("max=%d, min=%d", maxR, minC);
           return 0;
}
int ReadData(int rows, int columns, int array[rows][columns])
{
    int i, j, element;
    for (i=0; i<rows; i++)
    {
        for (j=0; j<columns; j++)
        {
            printf("Give element %d, %d ", i, j);
            scanf("%d", &element);
            array[i][j] = element;
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
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
}
void FindMaxRowMinCol(int rows, int columns, int array[rows][columns], int line, int col, int *maxRow, int *minCol)
{
    *maxRow = array[line][0];
    *minCol = array[0][col];
    int i, j;
    for (j=0; j<columns; j++)
    {
        if (array[line][j] > *maxRow)
        *maxRow = array[line][j];
    }
    for (i=0; i<rows; i++)
    {
        if (array[i][col] < *minCol)
            *minCol = array[i][col];
    }

}
