#include <stdio.h>
int read_temperatures(int array[30]);
void find_max_min_average(int temp[30], int *pmax, int *pmin, float *pav);
int main()
{
    int temps[30];
    read_temperatures(temps);
    int max, min;
    float av;
    find_max_min_average(temps, &max, &min, &av);
    printf("Max temperature: %d\n", max);
    printf("Min temperature: %d\n", min);
    printf("Average temperature: %.2f", av);

    return 0;
}
int read_temperatures(int array[30])
{
    int i;
    for (i=0; i<30; i++)
    {
        printf("Temperature %d: ", i);
        scanf("%d", &array[i]);
    }
    return *array;
}

void find_max_min_average(int temp[30], int *pmax, int *pmin, float *pav)
{
    int i, sum = 0;
    *pmax = *pmin = temp[0];
    for (i=0; i<30; i++)
    {
        if (temp[i] < *pmax)
            *pmax = temp[i];
        else if(temp[i] > *pmin)
            {*pmin = temp[i];}

        sum += temp[i];

    }
    *pav = sum / 30.00;
}
