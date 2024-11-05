#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char lex[20];
	int einai=1,i,j;
    printf("Dose mia lexi:");
    gets(lex);
    i=0;
    j=strlen(lex)-1;
    while (i<j)
    {
        if (lex[i++]!=lex[j--])
        {
          einai=0;
          break;
        }
    }
    if (einai)
       puts("Nai einai palindromiki");
    else
       puts("OXI den einai");

	return 0;
}
