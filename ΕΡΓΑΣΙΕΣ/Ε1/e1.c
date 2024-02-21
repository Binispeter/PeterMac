#include <stdio.h>

int main(void)
{
	int etos_en,etos_lx;
	int ap,i,a,b,g,d,z,f,e;

	printf("Dose etos enarxis: ");
	scanf("%d",&etos_en);
	printf("Dose etos lixis: ");
	scanf("%d",&etos_lx);
	for (e=etos_en;e<=etos_lx;e++)
	{
		a=e%19;
		b=e%4;
		g=e%7;
		d=(19*a+16)%30;
		z=(2*b+4*g+6*d)%7;
		if ((e%4==0 && e%100!=0) || e%400==0)
			f=1;
		else
			f=0;
		ap=d+z+f+13;
		if (f==1)
			if (ap<=29)
				printf("Oi apokries toy %d einai stis %d Febroyarioy\n",e,ap); 
			else
				printf("Oi apokries toy %d einai stis %d Martioy\n",e,ap-29); 
		else
			if (ap<=28)
				printf("Oi apokries toy %d einai stis %d Febroyarioy\n",e,ap); 
			else
				printf("Oi apokries toy %d einai stis %d Martioy\n",e,ap-28); 
	}
	return 0;    
}


