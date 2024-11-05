#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    FILE *infile, *outfile;
    int next, prev;

    infile = fopen("i10f9.dat", "r");
    outfile = fopen("o10f9.dat", "w");

    if (infile==NULL || outfile==NULL)
    {
        printf("Error\n");
        exit(1);
    }

    else
    {
        while ((prev = getc(infile))!=EOF)
        {
            fputc(prev, outfile);

            if ((prev==',') || (prev=='.'))
                {
                    next=getc(infile);
                    if(next==EOF)
                        break;
                    if (next != ' ')
                    {
                        fputc(' ', outfile);
                        fputc(next, outfile);
                    }
                    else fputc(next, outfile);
                }
        }
        fputc('\0', outfile);

    }
        fclose(infile);
        fclose(outfile);
        return 0;
}
