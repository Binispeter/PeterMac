#include <stdio.h>
int main()
{
    FILE *makefile;

    makefile = fopen("i8f9.dat", "a");
    fprintf(makefile, "\0");

    fclose(makefile);
    return 0;
}
