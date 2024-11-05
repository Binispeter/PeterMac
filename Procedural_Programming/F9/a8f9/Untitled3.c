#include <stdio.h>

int main()
{
    FILE *makefile;

    makefile = fopen("i8f9.dat", "w");

    fprintf(makefile, "11_30\n");
    fprintf(makefile, "12_40\n");
    fprintf(makefile, "13_50\n");
    fprintf(makefile, "14_60\n");

    fclose(makefile);

    return 0;
}
