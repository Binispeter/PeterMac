#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 100

typedef struct
{
    char name[30];
    int apousies;
} studentT;

void readInput(FILE *infile, studentT students[], int *pApousies, int *pStudents);
void writeOutput(FILE *outfile, int size, studentT students[], int total);

int main()
{
    FILE *infile;
    FILE *outfile;

    infile = fopen("i2f9.dat", "r");
    if (infile==NULL)
    {
        printf("Cannot open input file i2f9.dat");
        exit(1);
    }
    outfile = fopen("o2f9.dat", "w");
    studentT students[M];
    int numberOfStudents, numberOfApousies;

    readInput(infile, students, &numberOfApousies, &numberOfStudents);
    writeOutput(outfile, numberOfApousies, students, numberOfStudents);
    return 0;
}

void readInput(FILE *infile, studentT students[], int *pApousies, int *pStudents)
{
    int nscan, apousies, line;
    char name[30], comments[68], termch;
    line = 0;
    while(true)
    {
        nscan = fscanf(infile, "%30[^,], %d, %68[^\n]%c", name, &apousies, comments, &termch);

        if(nscan == EOF) break;
        line++;
        if(nscan !=4 || termch != '\n')
        {
            printf("Error in line %d. Program termination\n", line);
            exit(1);
        }
        if (apousies > 100)
        {
            strcpy(students[*pApousies].name, name);
            students[*pApousies].apousies = apousies;
            (*pApousies)++;
        }
        (*pStudents)++;
    }
}

void writeOutput(FILE *outfile, int size, studentT students[], int total)
{
    int i;

    fprintf(outfile, "%-30s%-9s\n", "ONOMATEPONYMO", "APOUSIES");
    for (i=1; i<=39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    for (i=0; i<size; i++)
        fprintf(outfile, "%-30s%9d\n", students[i].name, students[i].apousies);

    for (i=1; i<=39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);
    fprintf(outfile, "%-30s%9d\n", "SYNOLO MATHITWN:", total);
    fprintf(outfile, "%-30s%9d\n", "SYNOLO APONTWN:", size);

}
