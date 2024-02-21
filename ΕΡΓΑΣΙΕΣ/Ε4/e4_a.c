#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp1,*fp2;
    char set;
    char onoma_eikonas[30],onoma_keimenoy[30];
    int platos,ypsos,offset,g,size,bytes_per_raw,padding,padding_pos;
  	int s,count=0,i,cnt;
    short int bits;
    unsigned char ch;
    printf("Dose onoma eikonas stin opoia tha krypso to keimeno: ");
    gets(onoma_eikonas);
    fp1=fopen(onoma_eikonas,"rb+");
    if (fp1==NULL)
    {
    	printf("To arxeio eikonas %s den yparxei\n",onoma_eikonas);
    	exit(1);
	}
    fseek(fp1,2,SEEK_SET);
  	fread(&size,4,1,fp1);
  	printf("Bytes:%d\n",size);
	fseek(fp1,10,SEEK_SET);
  	fread(&offset,4,1,fp1);
  	printf("Offset:%d\n",offset);
    fseek(fp1,18,SEEK_SET);
	fread(&platos,4,1,fp1);
	fread(&ypsos,4,1,fp1);
	printf("Size:%dx%d\n",platos,ypsos);
	bytes_per_raw=3*platos;
	if (bytes_per_raw%4==0)
        padding=0;
    else
        padding=4-bytes_per_raw%4;
   	printf("Padding:%d\n",padding);
	if (padding==0)
    {
    	printf("Sygnomi alla to programma doyleyei mono me eikones poy exoyn padding bytes\n");
    	printf("dokimaste eikona bmp 999x999 pixels\n");
    	exit(1);
    }
    fseek(fp1,28,SEEK_SET);
    fread(&bits,2,1,fp1);
    printf("Bits per pixel:%d\n",bits);
    if (bits!=24)
    {
    	printf("Sygnomi alla to arxeio den einai RGB 24bits\n");
    	exit(1);
    }
    printf("\n--> Sto arxeio %s mporoyn na kryftoyn mexri %d xaraktires!\n\n", onoma_eikonas,ypsos*padding);
    printf("Dose onoma arxeioy keimenoy gia krypsimo: ");
    gets(onoma_keimenoy);
    fp2=fopen(onoma_keimenoy,"rb");
    if (fp2==NULL)
    {
    	printf("To arxeio keimenoy %s den yparxei\n",onoma_keimenoy);
    	exit(1);
	}
	printf("\n===== Patise <ENTER> gia synexeia =====\n");
	getchar();

	for (g=0;g<ypsos;g++)
    {
    	padding_pos=offset+platos*3*(g+1)+padding*g;
    	fseek(fp1,padding_pos,SEEK_SET);
    	for (i=1;i<=padding;i++)
    	{
			if (fread(&set,1,1,fp2))
			{
				fwrite(&set,1,1,fp1);
				putchar('#');
				count++;
			}
			else
			{
				set=0;
				fwrite(&set,1,1,fp1);
				continue;
			}
    	}
    	if (feof(fp2)) break;
   }
   fclose(fp1);
   fclose(fp2);
   printf("\nStin eikona %s kriftikan %d xaraktires\n",onoma_eikonas, count);
   return 0;
}


