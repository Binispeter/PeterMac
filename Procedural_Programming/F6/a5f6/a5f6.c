#include <stdio.h>

int inputArray(int n, int array[100]);
void inputNumbers(int *pa, int *pb);
void performCalculations(int *pbelow_eq_a, int *pabove_eq_b, int *pbetween
                         , int n, int array[100], int *pa, int *pb);
void ShowResults(int n, int array[100], int a, int b, int above, int below, int between);
int main()
{
    int n, array[100], a, b, below_eq_a, above_eq_b, between;

    printf("Give n: ");
    scanf("%d", &n);
    inputArray(n, array);

    inputNumbers(&a, &b);
    performCalculations(&below_eq_a, &above_eq_b, &between, n, array, &a, &b);
    ShowResults(n, array, a, b, above_eq_b, below_eq_a, between);

    return 0;
}

int inputArray(int n, int array[100])
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("Give element [%d]: ", i);
        scanf("%d", &array[i]);

    }
    return array[n];
}

void inputNumbers(int *pa, int *pb)
{
    int a, b;

    printf("Give A: ");
    scanf("%d", &a);
    printf("Give B: ");
    scanf("%d", &b);

    *pa = a;
    *pb = b;
}

void performCalculations(int *pbelow_eq_a, int *pabove_eq_b, int *pbetween
                         , int n, int array[100], int *pa, int *pb)
{
    int below_eq_a=0, above_eq_b=0, between=0, a, b;
    a = *pa;
    b = *pb;


    for (int i=0; i<n; i++)
    {
        if (array[i] <= a)
            below_eq_a++;

        else if (array[i] >= b)
            above_eq_b++;

        else between++;
    }

    *pbelow_eq_a = below_eq_a;
    *pabove_eq_b = above_eq_b;
    *pbetween = between;
}

void ShowResults(int n, int array[100], int a, int b, int above, int below, int between)
{
    printf("\n----The numbers of the array-----\n");
    for (int i=0; i<n; i++)
    {
       printf("%d ", array[i]);
    }

    printf("\n\nA = %d\nB = %d\n", a, b);
    printf("\nNumbers smaller or equal to A: %d\n", below);
    printf("Numbers bigger or equal to B: %d\n", above);
    printf("Numbers bigger than A and smaller than B: %d\n", between);
}
