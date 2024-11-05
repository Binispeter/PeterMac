#include <stdio.h>
#include <string.h>
int main()
{
    int i, j=0;
    char names[5][20];
    for (i=0; i<5; i++)
        gets(names[i]);
    for (i=0; i<5; i++)
    {
        while(names[i][j]!='\0')
        {
            j++;
        }
        printf("%c%c", names[i][0], names[i][j-1]);
        printf("\n");
        j=0;
    }
    return 0;
}
