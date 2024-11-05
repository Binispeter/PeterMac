#include <stdio.h>
#include <stdlib.h>
int populate(int M, int N, int a[M][N]);
void print_2d(int M, int N, int a[M][N]);
void FindMaxMinRow(int size, int no, int *max, int *min, int a[no][size]);
int main()
{
    int a[5][4];
    int i, max, min;
    max = min = 0;

    populate(5, 4, a);
    print_2d(5, 4, a);

    while (i < 5 && i >= 0)
    {
        printf("Give line number ");
        scanf("%d", &i);
        max = min = a[i][0];
        FindMaxMinRow(4, i, &max, &min, a);
        if (i < 5 && i >= 0){
        printf("%d, %d\n", max, min);
        }
        else break;

    }

    return 0;
}

int populate(int M, int N, int a[M][N])
{
    int i, j;
    srand(30);
    for (i=0; i<M; i++)
    {
        for (j=0; j<N; j++)
        {
            a[i][j] = rand() % 21;
        }
    }
    return a;
}

void print_2d(int M, int N, int a[M][N])
{
    int i, j;
    for (i=0; i<M; i++)
    {
        for (j=0; j<N; j++)
        {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}

void FindMaxMinRow(int size, int no, int *max, int *min, int a[no][size])
{
    int i;
    *max = a[no][0];
    *min = a[no][0];
    for (i=0; i<size; i++)
    {
        if (*max < a[no][i])
            *max = a[no][i];
        else if (a[no][i] < *min)
            *min = a[no][i];
    }
}
