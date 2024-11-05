#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    FILE *infile, *outfile;

    int nscan, code;
    char termch, name[25];
    long value, prom;
    double perc;

    infile = fopen("i4f9.dat", "r");
    outfile = fopen("o4f9.dat", "w");

    if (infile==NULL || outfile==NULL)
        exit(1);
    else
    {
        while(true)
        {
            nscan = fscanf(infile, "%d, %25[^,], %ld%c", &code, name, &value, &termch);
            if(nscan == EOF)
                break;
            if(nscan!=4 || termch!='\n')
            {
                exit(2);
            }

            else
            {

                if(code==11)
                    perc = 0.03;
                else if(code==12)
                    perc = 0.05;
                else if(code==13)
                    perc = 0.08;
                else perc = 0.11;

                prom = perc*value;

                fprintf(outfile, "%-24s, %ld\n", name, prom);
            }
        }
        fclose(infile);
        fclose(outfile);
    }
    return 0;
}
