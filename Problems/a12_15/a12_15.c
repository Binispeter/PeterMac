#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char frasi[80];
    printf("Enter a phrase: ");
    gets(frasi);
    puts(frasi + strlen(frasi)/2);

	return 0;
}
