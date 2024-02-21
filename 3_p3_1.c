#include <stdio.h>

int main(void)
{
	int b1,b2,b3;
	float mo;
	printf("Dose treis bathmous:");
	scanf("%d %d %d",&b1,&b2,&b3);
	mo=(b1+b2+b3)/3.0;
	if(mo>=10)
		printf("Perases me bathmo %f\n",mo);
	else
		printf("Kopikes\n");
	return 0;
}


