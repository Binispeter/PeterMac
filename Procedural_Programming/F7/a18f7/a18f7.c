#include <stdio.h>
#include <stdlib.h>

void FindInt(char array[15], int *coef, int *mark);

int main()
{
    char array[15], name[9];
    int coef, mark, i=0;
    float final_mark;

    printf("Please insert course info (name/coef/mark): ");
    scanf("%s", array);

    while(array[i] != '/')
    {
        name[i] = array[i];
        i++;
        if(i>9)
        {
            break;
        }
    }

    if(i>9)
        printf("Error! Name should not be more than 9 chars");

    else
    {
        FindInt(array, &coef, &mark);

        final_mark = mark*(coef/100.00);

        printf("Lesson: %s\n", name);
        printf("Coef: %d\n", coef);
        printf("Mark: %d\n", mark);
        printf("Final Mark: %.2f\n", final_mark);
    }




    return 0;
}

void FindInt(char array[15], int *coef, int *mark)
{
    int i=0;
    char mark_arr[2], coef_arr[2];

    for(i=0; i<15; i++)
    {
        if(array[i] == '/')
        {
            coef_arr[0] = array[i+1];
            coef_arr[1] = array[i+2];

            *coef = atoi(coef_arr);
            break;
        }
    }

    mark_arr[0] = array[i+4];
    mark_arr[1] = array[i+5];

    *mark = atoi(mark_arr);
}
