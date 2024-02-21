#include <stdio.h>
#include <math.h>
 
void towers(int num, char stylos_apo, char stylos_se, char stylos_temp);
 
int main(void)
{
    int n,ar;
    printf("Dose arithmo diskon : ");
    scanf("%d", &n);
    printf("H seira ton apaitoymenon kinisevn einai:\n\n");
    towers(n, 'A', 'C', 'B');
    ar=pow(2,n)-1;
    printf("\nXreiastikan %d metakiniseis\n",ar);
    return 0;
}

void towers(int num, char stylos_apo, char stylos_se, char stylos_temp)
{
    if (num == 1)
    {
        printf("Metakinise ton disko 1 apo to stilo %c sto stilo %c\n",stylos_apo, stylos_se);
        return;
    }
    towers(num-1, stylos_apo, stylos_temp, stylos_se);
    printf("Metakinise ton disko %d apo to stilo %c sto stilo %c\n",num, stylos_apo, stylos_se);
    towers(num-1, stylos_temp, stylos_se, stylos_apo);
}

