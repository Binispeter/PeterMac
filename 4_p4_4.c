#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
int main(void)
{
	int z1,z2;
	//srand(time(NULL));
	z1=rand()%6+1;
	z2=rand()%6+1;
	printf("Proti zaria   -> %d:%d\n",z1,z2);
	z1=rand()%6+1;
	z2=rand()%6+1;
	printf("Deyteri zaria -> %d:%d\n",z1,z2);
	z1=rand()%6+1;
	z2=rand()%6+1;
	printf("Triti zaria   -> %d:%d\n",z1,z2);
	return 0;
}

/* Αν θέλουμε πραγματικά τυχαία νούμερα θα πρέπει να προσθέστε στον κώδικα
τις γραμμές που έχουν γίνει σχόλια αφαιρώντας τις δύο καθέτους // από μπροστά τους!!! */
