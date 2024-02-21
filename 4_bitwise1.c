#include <stdio.h>

int main(void)
{
	int a,b,c,d;
	a=166;
	b=176;
	c=a && b;
	d=a & b;
	printf("c=%d d=%d\n",c,d);
	return 0;
}


