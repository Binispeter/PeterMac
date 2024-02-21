#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    FILE *infile, *outfile;
    int nscan;
    char name[30], termch;
    long prom, actual, sum=0;
    double perc;

    infile = fopen("i3f9.dat", "r");
    outfile = fopen("o3f9.dat", "w");

    if (infile==NULL || outfile==NULL)
    {
        printf("Error opening files\n");
        exit(1);
    }

    else
    {
        fprintf(outfile, "%-30s %-10s\n", "ONOMATEPWNYMO", "PROMHTHIA");
        for (int i=0; i<40; i++)
        {
            fprintf(outfile, "-");

        }fprintf(outfile, "\n");
        while(true)
        {
            nscan = fscanf(infile, "%30[^,], %ld%c", name, &prom, &termch);
            if (nscan == EOF)
                break;
            if (nscan != 3 || termch!='\n')
            {
                printf("Improper file format\n");
                exit(2);
            }
            else
            {
                if(prom > 300000)
                {
                    perc = 0.05;
                }
                else
                {
                    perc = 0.03;
                }
                actual = perc*prom;
                sum+=actual;

                fprintf(outfile, "%-30s %10ld\n", name, actual);

            }
        }

        for (int i=0; i<40; i++)
        {
            fprintf(outfile, "-");
        }
        fprintf(outfile, "\n%-30s %ld", "SYNOLO PROMHTHEIWN:", sum);
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}
