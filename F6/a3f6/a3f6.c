#include <stdio.h>
void swap(int *x, int *y);
int main()
{
    int a, b, g;
    printf("A: ");
    scanf("%d", &a);
    printf("B: ");
    scanf("%d", &b);
    printf("G: ");
    scanf("%d", &g);

    if (a>b)
        swap(&a, &b);
    if (a>g)
        swap(&a, &g);
    if (b>g)
        swap(&b, &g);

    printf("%d %d %d", a, b, g);
    return 0;

}

void swap(int *x, int *y)
{
    int v;
    v = *x;
    *x = *y;
    *y = v;
}
