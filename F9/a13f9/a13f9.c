#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[40];
    int ypoloipo;
    float epitokio;
    int date;
} info;

int fillStruct(FILE *infile, info data[100]);
int notInBoth(info olda[100], info newa[100], int newclients, int oldclients, info result[100]);
void makefile(FILE *infile, FILE *newfile, info newdat[100], int newclients);
float showperc(int clients, info data[100]);
int findMax(info data[100], int clients);

int main()
{
    FILE *newfile, *oldfile, *madefile;
    info danew[100], daold[100], result[100];
    int old_num, new_num, i, both, n, o;
    float newexp, oldexp;

    newfile = fopen("bank_new.dat", "r");
    oldfile = fopen("bank_old.dat", "r");

    if (newfile==NULL || oldfile==NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    else
    {
        new_num = fillStruct(newfile, danew);
        old_num = fillStruct(oldfile, daold);

        printf("Clients in List New not Old\n");

        both = notInBoth(daold, danew, new_num, old_num, result);
        for (i=0; i<both; i++)
        {
            printf("- %s %d\n", result[i].name, result[i].ypoloipo);
        }

        makefile(newfile, madefile, danew, new_num);

        oldexp = showperc(old_num, daold);
        newexp = showperc(new_num, danew);

        printf("Expected Tax New: %.2f\n", newexp);
        printf("Expected Tax Old: %.2f\n", oldexp);

        n = findMax(danew, new_num);
        o = findMax(daold, old_num);
        printf("Max in New: %s %d\n", danew[n].name, danew[n].date);
        printf("Max in Old: %s %d\n", daold[o].name, daold[o].date);

        fclose(newfile);
        fclose(oldfile);

    }


    return 0;
}

int fillStruct(FILE *infile, info data[100])
{
    int i=0, nscan;

    char name[50], termch;
    int ypoloipo, date;
    float epitokio;

    while(true)
    {
        nscan = fscanf(infile, "%50[^,], %d, %f, %d%c", name, &ypoloipo, &epitokio, &date, &termch);

        if(nscan == EOF)
            break;
        if(nscan!=5 || termch!='\n')
        {
            printf("Error");
            exit(2);
        }
        else
        {
            strcpy(data[i].name, name);
            data[i].ypoloipo = ypoloipo;
            data[i].epitokio = epitokio;
            data[i].date = date;
            i++;
        }
    }

    return i;
}

int notInBoth(info olda[100], info newa[100], int newclients, int oldclients, info result[100])
{
    int i=0, j=0, pointer, n=0;

    for (i=0; i<newclients; i++)
    {
        pointer = 1;

        for (j=0; j<oldclients; j++)
        {
            if ((strcmp(olda[j].name, newa[i].name)) == 0)
            {
                pointer = 0;
                break;
            }
        }
        if(pointer == 1)
        {
            strcpy(result[n].name, newa[i].name);
            result[n].ypoloipo = newa[i].ypoloipo;
            n++;
        }
    }

    return n;
}

void makefile(FILE *infile, FILE *newfile, info newdat[100], int newclients)
{
    int i;

    newfile = fopen("mztfgm.dat", "w");
    if(newfile == NULL)
        printf("Cant open new file\n");

    else
    {

        for (i=0; i<newclients; i++)
        {
            if(newdat[i].date > 2000)
                fprintf(newfile, "%s, %d, %f, %d\n", newdat[i].name, newdat[i].ypoloipo, newdat[i].epitokio, newdat[i].date);
        }
    }

    fclose(newfile);
}

float showperc(int clients, info data[100])
{
    int i;
    int sum = 0;
    float result;

    for(i=0; i<clients; i++)
    {
        sum += data[i].ypoloipo;
    }
    result = sum * 0.40;

    return result;
}

int findMax(info data[100], int clients)
{
    int i, j=0;
    int max;

    max = data[0].ypoloipo;

     for (i=0; i<clients; i++)
    {
        if(data[i].ypoloipo > max)
        {
            max=data[i].ypoloipo;
            j=i;
        }
    }

    return j;
}
