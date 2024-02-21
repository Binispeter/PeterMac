#include <stdio.h>

int main(void)
{
	int ar;
	int ok,eidos,timi;
	printf("Dose arimo apo ti syskevi:");
	scanf("%d",&ar);
	ok=(ar&128)>>7;
	eidos=(ar&96)>>5;
	timi=ar&31;
	if (ok==1)
		printf("Eidos=%d Timi=%d\n",eidos,timi);
	else
		printf("Yparxei problima sti syskevi\n");
	return 0;
}


