#include <stdio.h>
int main()
{
    int daysin, daysout, years, weeks;
    printf("Days: ");
    scanf("%d", &daysin);

    years = daysin / 365;
    weeks = (daysin % 365) / 7;
    daysout = (daysin % 365) % 7;

    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d\n\n", daysout);

    return 0;

}
