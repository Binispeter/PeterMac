#include <stdio.h>
int main()  {
    #define Pag 12
    #define EE 0.12
    #define Ektos 0.15
    int baros, country, extra;
    float telh, epib;

    printf("Dwse to baros: ");
    scanf("%d",&baros);
    printf("Dwse ton kwdiko ths xwras apostolhs (0,1): ");
    scanf("%d",&country);

    if (baros>=1 && baros<=20) {

        extra = baros * 5;

    }

    else if (baros>20 && baros<=100) {

         extra = 20*5 + 7*(baros - 20);

    }

    else {
         extra = 100*5 + 10*(baros - 100);

    }

    if (country == 0) {

        epib = (Pag + extra) * EE;
    }

    else {
        epib = (Pag + extra) * Ektos;
    }
    telh = epib + Pag + extra;

    printf("To baros einai %d \n", baros);
    printf("H epipleon xrewsh einai %d\n", extra);
    printf("H epibarunsh einai %.2f \n", epib);
    printf("Ta taxydromika telh einai %.2f\n", telh);

    return 0;
}
