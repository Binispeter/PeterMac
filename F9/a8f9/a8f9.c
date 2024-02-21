#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *infile, *outfile;

    infile = fopen("i8f9.dat", "r");
    //outfile = fopen("o8f9.dat", "w");

    if (infile == NULL)
    {
        printf("Error file format\n");
        exit(1);
    }

    else
    {

    }
    return 0;
}
