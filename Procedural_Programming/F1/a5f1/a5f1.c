#include <stdio.h>
int main (){
    int wres;
    long antim;
    double pos, akath, pkrat, kath;

    printf("Dwse ton arithmo twn wrwn:");
    scanf("%d", &wres);
    printf("Dwse thn wriaia antimisthia:");
    scanf("%ld", &antim);
    printf("Dwse to pososto twn krathsewn:");
    scanf("%lf", &pos);

    kath = wres * antim;
    pkrat = kath * pos;
    akath = kath + pkrat;

    printf(" Oi akatharistes apodoxes einai %g \n", akath);
    printf("Oi krathseis einai %g \n", pkrat);
    printf("Oi kathares apodoxes einai %g", kath);
     return 0;

}
