#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char movie[70];
    char main_role[50];
    long views;
} data;

int readInput(FILE *infile, data movie[]);
int findNewMovies(int lines18, int lines19, data movie18[lines18],
                  data movie19[lines19], data same[]);
FILE *writeOutput(int newLines, data same[newLines]);
int main()
{
    FILE *jan;
    FILE *dec;
    FILE *newfile;

    data jan_movies[20], dec_movies[20], same[20];
    int linesDec, linesJan, linesNew;

    jan = fopen("moviesJan2019.txt", "r");
    dec = fopen("moviesDec2018.txt", "r");

    if (jan == NULL || dec == NULL)
        printf("Error");

    else
    {
        linesDec = readInput(dec, dec_movies);
        linesJan = readInput(jan, jan_movies);
    }
    linesNew=findNewMovies(linesDec, linesJan, dec_movies, jan_movies, same);

    fclose(jan);
    fclose(dec);

    newfile = writeOutput(linesNew, same);


    fclose(newfile);

    return 0;
}

int readInput(FILE *infile, data stoixeia[])
{
    int line=0, nscan;
    char movie[70];
    char main_role[50];
    long views;
    char termch;

    while (true)
    {
        nscan = fscanf(infile, "%70[^,], %50[^,], %ld%c", movie, main_role, &views, &termch);
        if (nscan == EOF) break;
        if (nscan!=4 || termch!='\n')
        {
            printf("Error\n");
            exit(1);
        }
        else
        {
            strcpy(stoixeia[line].movie, movie);
            strcpy(stoixeia[line].main_role, main_role);
            stoixeia[line].views = views;
        }

        line++;
    }


    return line;
}

int findNewMovies(int lines18, int lines19, data movie18[lines18],
                  data movie19[lines19], data same[])

{
    int lines=0, i, j;
    for (i=0; i<lines19; i++)
    {
        int isNew=1;
        for (j=0; j<lines18; j++)
        {
            if(strcmp(movie19[i].movie, movie18[j].movie) == 0)
            {
                isNew = 0;
                break;
            }
        }
        if(isNew==1)
        {
            strcpy(same[lines].movie, movie19[i].movie);
            strcpy(same[lines].main_role, movie19[i].main_role);
            same[lines].views = movie19[i].views;
            lines++;
        }
    }
    return lines;
}

FILE *writeOutput(int newLines, data same[newLines])
{
    FILE *infile;
    infile = fopen("newMovies.txt", "w");

    for (int i=0; i<newLines; i++)
    {
        fprintf(infile, "%s, %s, %ld%c", same[i].movie, same[i].main_role, same[i].views, '\n');
    }
        return infile;
}
