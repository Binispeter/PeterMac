#include <stdio.h>
#define N 5

void readData(int array[N][4]);
void FindMean(double *pmo_male, double *pmo_females, int array[N][4]);
int main()
{
    int i, j, weight_male, weight_female, height_male, height_female, age_male, age_female;
    int array[N][4] = {{0, 90, 180, 40},
                        {1, 65, 160, 42},
                        {1, 93, 160, 35},
                        {0, 65, 160, 25},
                        {1, 45, 170, 37}};

    FindMean(w)
    return 0;
}

void readData(int array[N][4])
{
    int i;
    for (i=0; i<N; i++)
    {
       printf("Enter gender: ");
       scanf("%d", &array[i][0]);

       printf("Enter weight: ");
       scanf("%d", &array[i][1]);

       printf("Enter height: ");
       scanf("%d", &array[i][2]);

       printf("Enter age: ");
       scanf("%d", &array[i][3]);

       printf("------\n");
    }
}

void FindMean(double *pmo_male, double *pmo_females, int array[N][4])
{
    int weight_males=0, weight_females=0, height_males=0, height_females=0, age_males=0, age_females=0, point;

    for (point=1; point<4; point++)
    {
        if (point == 1)
        {
            for (int i=1; i<N; i++)
            {
                if (array[i][0] == 0)
                    weight_males+=array[i][point];
                else weight_females+=array[i][point];
            }
        }
        else if (point == 2)
        {
            for (int i=1; i<N; i++)
            {
                if (array[i][0] == 0)
                    height_males+=array[i][point];
                else height_females+=array[i][point];
            }
        }
        else
        {
            for (int i=1; i<N; i++)
            {
                if (array[i][0] == 0)
                    age_males+=array[i][point];
                else age_females+=array[i][point];
            }
        }
    }

    printf("\nAverage males weight: %d\n", weight_males);
    printf("Average females weight: %d\n\n", weight_females);

    printf("Average males height: %d\n", height_males);
    printf("Average females height: %d\n\n", height_females);

    printf("Average males age: %d\n", age_males);
    printf("Average females age: %d\n", age_females);

}
