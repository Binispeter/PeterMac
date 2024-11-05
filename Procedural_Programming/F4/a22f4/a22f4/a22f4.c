#include <stdio.h>
double fpa (double sum, int kat);

int main()
{
    int plithos, kat, proion;
    double tmonadas, sum, extra=0;
    float synolKostos = 0;
    for (proion = 1;proion <= 5;proion++){

    printf("Dwse to plithos temaxiwn apo to proion %d: ", proion);
    scanf("%d", &plithos);
    printf("Dwse timi gia to proion %d: ",proion);
    scanf("%lf", &tmonadas);
    printf("Dwse katigoria FPA gia to proion %d: ", proion);
    scanf("%d",&kat);
    sum = tmonadas * plithos;
    extra += sum *fpa(sum,kat);
    synolKostos += sum ;
    }
    synolKostos += extra;
    printf("Synoliko kostos: %.2f\n", synolKostos);
    printf("Synoliko FPA: %.2f", extra);

return 0;
}
double fpa(double sum, int kat)
{   double fpa = 0;


    if (kat == 1)
    {
       return fpa = 0.00;
    }

    else if (kat == 2)
    {
        return fpa = 0.06;
    }

    else if (kat == 3)
    {
       return fpa = 0.13;
    }

    else if (kat == 4)
    {
        return fpa = 0.19;
    }

    else{
        printf("Lathos katigoria FPA\n");
        return 0;}
}
