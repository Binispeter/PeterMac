#include <stdio.h>
int read_array(int array[10]);
double average(int array[10]);
int main()
{
    int i,grades[10];
    double averag;
    read_array(grades);
    averag = average(grades);
    for (i=0; i<10; i++)
    {
        if (grades[i] > averag)
            printf("%d ", grades[i]);
    }
    return 0;
}

int read_array(int array[10])
{
    int i;
    for (i=0; i<10; i++)
    {
        printf("Enter a grade: ");
        scanf("%d", &array[i]);
    }
    return *array;
}

double average(int array[10])
{
    int i, sum = 0;
    double average;

    for (i=0; i<10; i++)
    {
        sum += array[i];
    }
    average = sum / 10.0;
    return average;
}
