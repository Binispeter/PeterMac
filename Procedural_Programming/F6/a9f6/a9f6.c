#include <stdio.h>
#define SALESMEN 4
#define PRODUCTS 5

void calculateSales(int S, int P, int salesTable[S][P], int price[], int sp[]);
void printArray(int S, int table[S]);
void calculateProductSales(int S, int P, int sales[S][P], int productS[]);
void maxArray(int size, int tab[], int *max, int *pos);

int main()
{
    int sales[SALESMEN][PRODUCTS] =
    {{10, 4, 5, 6, 7},
    {7, 0, 12, 1, 3},
    {4, 19, 5, 0, 8},
    {3, 2, 1, 5, 6}};

    int price[] = {250, 150, 320, 210, 920}, salesPerson[SALESMEN], productSale[PRODUCTS];
    int max, pos;

    calculateSales(SALESMEN, PRODUCTS,sales, price, salesPerson);
    printf("SalesMan-Sales\n");
    printArray(SALESMEN, salesPerson);

    calculateProductSales(SALESMEN, PRODUCTS, sales, productSale);
    maxArray(SALESMEN, salesPerson, &max, &pos);
    printf("Best SalesMan was %d with %d sales\n",pos, max);
    printf("Product-Items\n");
    printArray(PRODUCTS, productSale);
    maxArray(PRODUCTS, productSale, &max, &pos);
    printf("Best Product was %d with %d items", pos, max);
    return 0;
}

void calculateSales(int S, int P, int salesTable[S][P], int price[], int sp[])
{
    int i, j;
    for (i=0; i<S; i++)
    {
        sp[i] = 0;
        for (j=0; j<P; j++)
            sp[i]+= salesTable[i][j] * price[j];
    }
}

void calculateProductSales(int S, int P, int sales[S][P], int productS[])
{
    int i, j;
    for (i=0; i<P; i++)
    {
        productS[i] = 0;
        for (j=0; j<S; j++)
            productS[i] += sales[j][i];
    }
}

void maxArray(int size, int tab[], int *max, int *pos)
{
    int i;
    *max = tab[0];
    *pos = 0;
    for (i=1; i<size; i++)
    {
        if (*max < tab[i])
        {
            *max = tab[i];
            *pos = i;
        }
    }
}

void printArray(int S, int table[S])
{
    int i;
    for (i=0; i<S; i++)
    {
        printf("  %d    %d\n", i, table[i]);
    }
}
