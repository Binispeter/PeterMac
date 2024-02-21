#include <stdio.h>

void go();

int main(void)
{
	go();
	go();	
	return 0;
}

void go()
{
	static int a=5;
	printf("a=%d\n",a++);
}


