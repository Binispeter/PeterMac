#include <stdio.h>

#define sub 3
#define stud 10

int main()
{
    int grades[sub][stud];
    int student, subject, grade;
    int sum, fail = 0, suc = 0;
    double mo;

    for (student = 1; student<=stud; student++)
    {
        sum = 0;
        printf("\nMathitis %d\n", student);
        for (subject = 1; subject<=sub; subject++)
        {
            printf("Mathima %d: ", subject);
            scanf("%d", &grade);
            sum += grade;
            grades[subject][stud] = grade;
        }
        mo = sum / 3.0;
        if (mo < 9.5)
        {
            fail++;
        }
        else if (mo >= 18.5)
        {
            suc++;
        }
    }
    printf("APOTYXONTES: %d %.2lf%%\nARISTOUXOI: %d %.2lf%%", fail, ((double)fail * 10.0), suc, ((double)suc*10));
return 0;
}


