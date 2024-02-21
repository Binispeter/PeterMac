#include <stdio.h>

int main(void)
{
	int i;
	for (i=1;i<=5;i++)
	{
		static int a=100;
		printf("i=%d a=%d\n",i,a--);
	}
	return 0;
}



