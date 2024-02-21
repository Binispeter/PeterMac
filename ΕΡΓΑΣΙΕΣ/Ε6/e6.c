#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Η δομή τον κόμβων της στοίβας
// Κάθε κόμβος περιέχει το τμήμα δεδομένων του και έναν δείκτη προς τον επόμενο κόμβο
struct stack_node
{
	int axia;
	char eidos[10];
	char figoyra[10];
	struct stack_node *next;
};

// Η δομή stack αναπαριστά μια στοίβα
// Το μόνο που περιέχει είναι ένα πεδίο-δεικτη στον κόμβο κορυφής της στοίβας
// Ο δείκτης αυτός είναι ο χειριστής της στοίβας
struct stack
{
	struct  stack_node  *top;
};

void pop_from_stack(struct stack *s);
bool push_in_stack(struct stack *s, struct stack_node x);
bool is_stack_empty(struct stack *s);
struct stack *create_stack();
void display_stack(struct stack *s);
void fill(struct stack *tr, int ar);
void anakatema(struct stack *tr, int kartes);
void swap_data(struct stack_node *p1,struct stack_node *p2);
void pexe_31(struct stack *tr, int kartes);

int main(void)
{
	char ch;
	int timi,artr,kartes;
	struct stack *trapoyla=create_stack();
	printf("Poses trapoyles na exei i stoiva :");
	scanf("%d",&artr);
	kartes=artr*52;
	fill(trapoyla,artr);
	//display_stack(trapoyla);
	anakatema(trapoyla,kartes);
	puts("====================================");
	//display_stack(trapoyla);
	pexe_31(trapoyla, kartes);
	return 0;
}

// Η επόμενη συνάρτηση δημιουργεί μια κενή αρχικά στοίβα
// Επιστρέφει ως τιμή δείκτη σε αυτή τη στοίβα
struct stack *create_stack()
{
    struct stack *st=(struct stack*) malloc(sizeof(struct stack));;
    st->top=NULL;
    return st;
};

// Η επόμενη συνάρτηση προσθέτει έναν κόμβο στην κορυφή της στοίβας
// Στη συνάρτηση μεταβιβάζονται τόσο ένας δείκτης που προσδιορίζει τη στοίβα
// όσο και η τιμή-δεδομένο του κόμβου που θα προστεθεί
bool push_in_stack(struct stack *s,struct stack_node x)
{
	struct stack_node *neos;
	neos = (struct stack_node *)malloc(sizeof(struct stack_node));
	if (neos==NULL) return false;
	*neos=x;
	neos->next = s->top;
	s->top=neos;
	return true;
}

// Η επόμενη συνάρτηση απομακρύνει έναν κόμβο από την κορυφή της στοίβας
// Στη συνάρτηση μεταβιβάζεται ένας δείκτης που προσδιορίζει τη στοίβα
void pop_from_stack(struct stack *s)
{
	struct stack_node *temp;
	int d;
	if (is_stack_empty(s))
	{
		puts("Keni stoiva");
		return;
	}
	temp = s->top->next;
	free(s->top);
	s->top = temp;
}

// Η παρακάτω συνάρτηση ελέγχει αν η στοίβα είναι άδεια
// Στη συνάρτηση μεταβιβάζεται ένας δείκτης που προσδιορίζει τη στοίβα
bool is_stack_empty(struct stack *s)
{
	if (s->top==NULL)
		return true;
	else
		return false;
}


// Η επόμενη συνάρτηση εμφανίζει όλα τα στοιχεία της στοίβας ξεκινώντας από την κορυφή της
// Στη συνάρτηση μεταβιβάζεται ένας δείκτης που προσδιορίζει τη στοίβα
void display_stack(struct stack *s)
{
	struct stack_node *p;
	if (is_stack_empty(s))
		return;
	p=s->top;
	while (p)
	{
		printf("%s %s\n",p->figoyra,p->eidos);
		p=p->next;
	}
	printf("\n");
}


void fill(struct stack *tr, int ar)
{
	struct stack_node karta;
	int i,j,t;
	char eidei[4][10]={"Koypa","Karo","Spathi","Mpastoyni"};
	char figoyres[13][10]={"Assos","Dyo","Tria","Tessera","Pente","Exi","Epta","Okto","Enia","Deka","Vales","Ntama","Rigas"};
	int axies[13]={1,2,3,4,5,6,7,8,9,10,10,10,10};
	for (t=1;t<=ar;t++)
		for (i=0;i<4;i++)
			for (j=0;j<13;j++)
			{
				karta.axia=axies[j];
				strcpy(karta.eidos,eidei[i]);
				strcpy(karta.figoyra,figoyres[j]);
				push_in_stack(tr,karta);
			}
}

void anakatema(struct stack *tr, int kartes)
{
	struct stack_node *x1,*x2,*p,temp;
	int i,ta1,ta2,aa,tt;
	srand(time(NULL));
	for (i=1;i<=kartes*20;i++)
	{
		aa=0;
		ta1=rand()%kartes+1;
		ta2=rand()%kartes+1;
		if (ta1>ta2)
		{
			tt=ta1;
			ta1=ta2;
			ta2=tt;
		}
		p=tr->top;
		//printf("%d-%d\n",ta1,ta2);
		while (p)
		{
			aa++;
			if (aa==ta1)
				x1=p;
			else if (aa==ta2)
			{
				x2=p;
				break;
			}
			p=p->next;
		}
		//printf("%s %s - %s %s\n",x1->figoyra,x1->eidos,x2->figoyra,x2->eidos);
		swap_data(x1,x2);
	}
}

void swap_data(struct stack_node *p1,struct stack_node *p2)
{
	struct stack_node *p1_next, *p2_next, temp;
	p1_next=p1->next;
	p2_next=p2->next;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
	p1->next=p1_next;
	p2->next=p2_next;
}

void pexe_31(struct stack *tr, int kartes)
{
	struct stack_node kartes_paikti[10],kartes_manas[10];
	int xp,xm,bp,bm,poso,synolo;
	int gyroi=1,perasan=0;
	char ans;
	do
	{
		xp=xm=0;
		bp=bm=0;
		printf("\n########## GYROS No %d - Kartes sti stoiva %d ##########\n\n",gyroi,kartes-perasan);
		kartes_paikti[xp]=*(tr->top);
		pop_from_stack(tr);
        perasan++;
		bp=bp+kartes_paikti[xp].axia;
		printf("Karta paikti : %s %s Synolo pnontvn : %d\n",kartes_paikti[xp].figoyra,kartes_paikti[xp].eidos,bp);
		xp++;
		printf("Dose to pontarisma soy (1~10 euro) -> ");
		scanf("%d",&poso);
		printf("\nTora travaei i mana\n");
		while (bm<=23)
		{
			kartes_manas[xm]=*(tr->top);
			bm=bm+kartes_manas[xm].axia;
			xm++;
			pop_from_stack(tr);
			perasan++;
			if (bm==14) break;
		}
		if (bm==31)
        {
            printf("Triantamia ... se kerdisa\n");
            synolo=synolo-poso;
        }
		else if (bm>31)
        {
            printf("Ops ... kaika %d\n",bm);
            synolo=synolo+poso;
        }
		else
        {
            printf("Exo %d pontoys\n",bm);
            printf("\nTora travaei o paiktis \n");
            do
            {
                kartes_paikti[xp]=*(tr->top);
                pop_from_stack(tr);
                perasan++;
                bp=bp+kartes_paikti[xp].axia;
                printf("Karta paikti : %s %s Synolo ponton : %d\n",kartes_paikti[xp].figoyra,kartes_paikti[xp].eidos,bp);
                xp++;
                if (bp>=31) break;
                printf("\nPatise ENTER gia epomeni karta - otidipote allo gia stamatima  >");
                fflush(stdin);
                ans=getchar();
            } while (ans=='\n');
            if (bp==31)
            {
                printf("Mpravo TRIANTAMIA kerdises!!!\n",bp);
                synolo=synolo+poso;
            }
            else if (bp>31)
            {
                printf("Dystyxos kaikes %d\n",bp);
                synolo=synolo-poso;
            }
            else if (bm==14)
            {
                printf("Dystyxos se kerdisa giati exo 14\n",bp,bm);
                synolo=synolo-poso;
            }
            else if (bp==14)
            {
                printf("Mpravo me kerdises exeis 14\n",bp,bm);
                synolo=synolo+poso;
            }
            else if (bp>bm)
            {
                printf("Mpravo me kerdises exeis %d kai exo %d pontoys\n",bp,bm);
                synolo=synolo+poso;
            }
            else if (bp==bm)
            {
                printf("Exoyme kai oi dyo %d pontoys .. alla epeidi eimai mana se kerdizo :-)\n",bp);
                synolo=synolo-poso;
            }
            else
            {
                printf("Dystyxos se kerdisa exeis %d kai exo %d pontoys\n",bp,bm);
                synolo=synolo-poso;
            }
        }
		if (synolo>0)
            printf("\n ****** Mexri tora kerdizeis %d euro\n",synolo);
        else if (synolo<0)
            printf("\n ****** Mexri tora xaneis %d euro\n",-synolo);
        else
            printf("\n ****** Mexri tora den kerdizeis oyte xaneis\n");
		gyroi++;
		if (kartes-perasan<=10)
        {
            printf("Den  porei na ginei allos gyros - paremeinan mono %d kartes sti stoiva\n",kartes-perasan);
            printf("Thelete na prostethei sti stoiba allh mia trapoyla? N/O >");
            fflush(stdin);
            ans=getchar();
            if (ans=='N' || ans=='n')
            {
                fill(tr,1);
                kartes=kartes-perasan+52;
                perasan=0;
                anakatema(tr,kartes);
            }
            else break;
        }
		printf("\nPatise ENTER gia epomeno gyro - otidipote allo gia stamatima  >");
		fflush(stdin);
		ans=getchar();

	} while (ans=='\n');
	if (synolo>0)
        printf("\n BRAVO kerdizeis synolika %d euro\n",synolo);
    else if (synolo<0)
        printf("\n DYSTUXOS exases synolika %d euro\n",-synolo);
    else
        printf("\n OYTE GATA OYTE ZHMIA DEN KERDISES ALLA DEN EXASES KIOLAS\n");
}
