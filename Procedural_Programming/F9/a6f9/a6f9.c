#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    FILE *infile, *outfile;
    char ch;


    infile = fopen("i6f9.dat", "r");
    outfile = fopen("o6f9.dat", "w");

    if (infile==NULL || outfile==NULL)
        exit(1);
    else
    {
        while (ch!=EOF)
        {
            ch = getc(infile);

            if((ch!='\n') && (ch!=' ') && (ch!='_'))
            {
                fprintf(outfile, "%c", ch);
            }
            else
            {
                while (true)
                {
                    ch = getc(infile);
                    if((ch!='\n') && (ch!=' ') && (ch!='_'))
                    {
                        fprintf(outfile, "\n%c", ch);
                        break;
                    }
                }
            }
        }
    }
    fclose(infile);
    fclose(outfile);
    return 0;
}
