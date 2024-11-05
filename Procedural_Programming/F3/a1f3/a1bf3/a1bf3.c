#include <stdio.h>
#include <math.h>

int main() {

    long Arithmo_Aytok, Orio, years;
    double Rythmos;

   printf("Dwse ton arxiko arithmo autokinhtwn:");
   scanf("%ld",&Arithmo_Aytok);
   printf("Dwse ton etysio arithmo ayxhshs:");
   scanf("%lf",&Rythmos);
   printf("Dwse to orio:");
   scanf("%ld",&Orio);

   years=0;

    while (Arithmo_Aytok <= Orio) {
        Arithmo_Aytok = ceil(Arithmo_Aytok*(1+Rythmos));
        years++;
        }
    printf("Years: %ld\n",years);
    printf("Cars: %ld\n",Arithmo_Aytok);
    return 0;
}

