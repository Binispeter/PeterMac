#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dekades();
char *ekatontades(int ar, char lex[30],int pl);
char *monades(int ar, char lex[30],int pl);
char *tripsifio(int ar, char lex[30],int pl);

int main(void)
{
	char d[100]="";
	double ar;
	int a,f;
	int ek,xl,yp;
	printf("Dose enan arithmo:");
	scanf("%lf",&ar);
	if (ar<0) 
	{
		strcat(d,"Meion ");
		ar=-ar;
	}
	a=(int)ar;
	f=(ar-a)*100.0+0.5;
	ek=a/1000000;
	xl=(a%1000000)/1000;
	yp=a%1000;
	if (ek>0) 
	{
		tripsifio(ek,d,0);
		if (ek==1)
			strcat(d,"ekatomyrio ");
		else
			strcat(d,"ekatomyria ");    
	}    
	if (xl>0) 
	{
       
       if (xl==1)
			strcat(d,"Xilia ");
       else
       {
			tripsifio(xl,d,1);    
			strcat(d,"xiliades ");  
       }  
	} 
	if (yp>0) 
		tripsifio(yp,d,0);
	if (a==0) strcpy(d,"Miden ");
	if (ar>a) 
	{
		strcat(d,"koma ");
		tripsifio(f,d,0);
	}
	puts(d);
    return 0;    
}

char *tripsifio(int ar, char lex[],int pl)
{
	char tmp[30];
	int e,d,m,mm;
    e=ar/100;
    d=(ar%100)/10;
    m=ar%10;
    mm=ar%100;
    if (e!=0) strcat(lex,ekatontades(e,tmp,pl));
    if (mm>12)
    {
    	if (d!=0) strcat(lex,dekades(d,tmp,pl));
    	if (m!=0) strcat(lex,monades(m,tmp,pl));
    }
    else if (mm!=0)
		strcat(lex,monades(mm,tmp,pl));   
    return lex;
}     

char *monades(int ar, char lex[],int pl)
{
	 char mn[13][20];
     strcpy(mn[1],"Ena ");
     strcpy(mn[2],"Dyo ");
     strcpy(mn[3],"Tria ");
     strcpy(mn[4],"Tessera ");
     strcpy(mn[5],"Pente ");
     strcpy(mn[6],"Exi ");
     strcpy(mn[7],"Epta ");
     strcpy(mn[8],"Okto ");
     strcpy(mn[9],"Enia ");
     strcpy(mn[10],"Deka ");
     strcpy(mn[11],"Enteka ");
     strcpy(mn[12],"Dodeka ");
     if (pl==1)
     {
        switch(ar)
        {
           case 1:
              strcpy(mn[ar],"Mia ");
              break;
           case 3:
              strcpy(mn[ar],"Treis ");
              break;   
           case 4:
              strcpy(mn[ar],"Teseris ");
              break;               
        }                  
     }
     strcpy(lex,mn[ar]);
     return lex;
} 

char *dekades(int ar, char lex[])
{
     char dk[10][20];
     strcpy(dk[1],"Deka ");
     strcpy(dk[2],"Eikosi ");
     strcpy(dk[3],"Trianta ");
     strcpy(dk[4],"Saranta ");
     strcpy(dk[5],"Peninta ");
     strcpy(dk[6],"Exinta ");
     strcpy(dk[7],"Evdominta ");
     strcpy(dk[8],"Ogdonta ");
     strcpy(dk[9],"Eneninta ");
     strcpy(lex,dk[ar]);
     return lex;
}  
   
char *ekatontades(int ar, char lex[30],int pl)
{
     char ek[10][20];
     strcpy(ek[1],"Ekato ");
     strcpy(ek[2],"Diakosi");
     strcpy(ek[3],"Triakosi");
     strcpy(ek[4],"Tetrakosi");
     strcpy(ek[5],"Pentakosi");
     strcpy(ek[6],"Exakosi");
     strcpy(ek[7],"Eptakosi");
     strcpy(ek[8],"Oktakosi");
     strcpy(ek[9],"Eniakosi");
     if (ar>1)
     {
		if (pl==1) 
			strcat(ek[ar],"es ");
		else
			strcat(ek[ar],"a ");
     }   
     strcpy(lex,ek[ar]);
     return lex;
}   
