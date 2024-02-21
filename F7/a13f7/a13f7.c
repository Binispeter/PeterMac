#include <stdio.h>
#include <ctype.h>
void common(char first[20], char second[20]);
void common_once(char first[20], char second[20]);
int main()
{
    char first[20], second[20];
    printf("Insert two words to find the common characters\n");
    printf("Word 1: ");
    gets(first);
    printf("Word 2: ");
    gets(second);
    common(first, second);
    common_once(first, second);
    return 0;
}
void common(char first[20], char second[20])
{
    int i, j, u=0;
    char out[20]={0};
    for (i=0; first[i]!='\0'; i++)
    {
        for (j=0; second[j]!='\0'; j++)
        {
            if (first[i] == second[j])
            {
                out[u]=first[i];
                u++;
                break;
            }
        }
    }
    printf("Common Characters: %s\n", out);
}
void common_once(char first[20], char second[20])
{
    int i, j, u=0;
    char out[20]={0}, out_once[20]={0};
    for (i=0; first[i]!='\0'; i++)
    {
        for (j=0; second[j]!='\0'; j++)
        {
            if (first[i] == second[j])
            {
                out[u]=first[i];
                u++;
                break;
            }
        }
    }
    out[u]='\0';
    u=0;
    for(i=0; out[i]!='\0'; i++)
    {
        for (j=i+1; out[j]!='\0'; j++)
        {
            if(out[i]==out[j])
            {
                out[j]='0';
            }
        }
    }
    for(i=0; out[i]!='\0'; i++)
    {
        if(isalpha(out[i]))
        {
            out_once[u] = out[i];
            u++;
        }
    }
    printf("Unique Common Characters: %s\n", out_once);
}
