#include <stdio.h>

int main(void)
{
	float b1,b2,b3,d;
	float mo;
	printf("Dose treis bathmous :");
	scanf("%f %f %f",&b1,&b2,&b3);
	if (b1<b2)
	   d=b2-b1;
	else
       d=b1-b2;   
	if (d<=2)
		mo=(b1+b2)/2;
	else
	{
		mo=(b1+b2+b3)/3;
	}	
	printf("Telikos bathmos =%f\n",mo);
	return 0;
}


