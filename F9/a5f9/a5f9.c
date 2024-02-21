#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    FILE *infile;
    char ch;
    int lines=0, words=0, chars=0;
    int inWord = 0;

    infile = fopen("i5f9.dat", "r");

    while (ch != EOF)
    {
        ch = getc(infile);


       if (ch == ' ' || ch == '\n') {
            if (inWord) {

                words++;
                inWord = 0;
            }
        } else {

            inWord = 1;
        }

        if (ch!=' ' && ch!='\n' && ch!='\0')
            chars++;

        if (ch=='\n')
            lines++;
    }


    fclose(infile);



    printf("%d\n", chars-1);
    printf("%d\n", lines);
    printf("%d", words);
    return 0;
}
