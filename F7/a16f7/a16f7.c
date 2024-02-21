#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char str[100]={0}, out[100]={0};
    int i, u=0, sum=0, len;
    printf("Insert a string: ");
    gets(str);
    for (i=0; str[i]!='\0'; i++)
    {
        if(isdigit(str[i]))
        {
            out[u] = str[i];
            u++;
        }
    }
    out[u] = '\0';
    len = strlen(out);
    if(u>1)
    {
        for(i=0; i<=len-1; i++)
            {
                printf("%c + ", out[i]);
                sum+=out[i]-48;
            }
            printf("\b\b= %d", sum);
    }
    else if(u==1)
    {
        printf("%c = %c", out[0], out[0]);
    }
    else printf("No digits in input.");
    return 0;
}
