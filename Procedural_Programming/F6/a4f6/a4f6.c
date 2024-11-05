#include <stdio.h>
#define rows 2
#define collums 3

void read(int *arr[2][3]);
void greater(int *arr[2][3]);

int main()
{
    int *arr[rows][collums];
    read(arr);
    greater(&arr);

    return 0;
}

void read(int *arr[rows][collums])
{
    int i, j;
    for (i=0; i<rows; i++)
    {
        for (j=0; j<collums; j++)
        {
            scanf("%p", &arr[i][j]);
            printf("\n");
        }
    }
    printf(" ");
}

void greater(int *arr[rows][collums])
{
    int *max = 0;
    int i,j, line, col;
     for (i=0; i<rows; i++)
    {
        for (j=0; j<collums; j++)
        {
            if (*arr[i][j] > max){
            max = &arr[i][j];
            line = i;
            col = j;
            }
        }
    }
    printf("The greater element is %d in Row %d and Collum %d", max, line + 1, col + 1);
}
