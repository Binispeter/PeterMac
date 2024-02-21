#include <stdio.h>
void GetTime (long SysSecs, int *hours, int *minutes, int *seconds);

int main()
{
    long *SysSecs;
    int *hours, *minutes, *seconds;
    printf("Enter Device Secs: ");
    scanf("%ld", &SysSecs);
    GetTime(SysSecs, &hours, &minutes, &seconds);
    printf("%d:%d:%d", hours,  minutes, seconds);

    return 0;
}
void GetTime (long SysSecs, int *hours, int *minutes, int *seconds)
{
    *hours = SysSecs / 3600;
    *minutes = (SysSecs % 3600) / 60;
    *seconds = (SysSecs % 3600) % 60;
}

