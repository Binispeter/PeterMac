#include <stdio.h>
int main()
{
    int array[10], i;
    for (i=0; i<10; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &array[i]);

    while(array[i] < array[i-1])
    {
        printf("Enter a higher number: ");
        scanf("%d", &array[i]);
    }}

    for (i=0; i<10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
