#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int number;
    char name[28];
    int points;
}player;

int readFromFile(FILE *infile, player stats[100]);
void writeToFile(FILE *outfile, player stats[100], int players);
int main()
{
    FILE *infile, *outfile;
    player stats[100];
    int players;

    infile = fopen("i11f9.dat", "r");
    outfile = fopen("o11f9.dat", "w");

    if(infile==NULL || outfile==NULL)
    {
        printf("Error opening files\n");
        exit(1);
    }
    else
    {
        players = readFromFile(infile, stats);
        writeToFile(outfile, stats, players);

        fclose(infile);
        fclose(outfile);
    }


    return 0;
}

int readFromFile(FILE *infile, player stats[100])
{
    int i=0, nscan, pnumber, points;
    char name[28], termch;

    while(true)

    {
        nscan = fscanf(infile, "%d, %28[^,], %d%c", &pnumber, name, &points, &termch);
        if(nscan == EOF)
            break;
        if(nscan!=4 || termch!='\n')
            exit(2);
        else
        {
            stats[i].number = pnumber;
            strcpy(stats[i].name, name);
            stats[i].points = points;
            i++;
        }
    }

    return i;
}

void writeToFile(FILE *outfile, player stats[100], int players)
{
    int i=0, sum=0, pabove10=0;


    fprintf(outfile, "%-28s %-10s\n", "ONOMATEPONYMO", "PONTOI");
    for(i=0; i<49; i++)
        fprintf(outfile, "-");
    fprintf(outfile, "\n");

    for(i=0; i<players; i++)
    {
        fprintf(outfile, "%-28s %10d\n", stats[i].name, stats[i].points);
        sum+=stats[i].points;

        if(stats[i].points > 10)
            pabove10++;
    }
    for(i=0; i<49; i++)
        fprintf(outfile, "-");
    fprintf(outfile, "\n");

    fprintf(outfile, "%-28s %10d\n", "SYNOLO PONTWN", sum);
    fprintf(outfile, "%-28s %10d\n", "SYNOLO PAIKTWN >= 10", pabove10);
}
