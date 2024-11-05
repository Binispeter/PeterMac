#include <stdio.h>
#include <stdbool.h>

int main() {
int hours;
long code;
double annual, perhour, perweek;

    printf("Dwse ton kwdiko:");
    scanf("%ld", &code);

if (code>=1000) {
    printf("Dwse ton ethsio mistho:");
    scanf("%lf", &annual);
    perweek=annual/52;
}

else {
    printf("Dwse tis wres ebdomadiaias ergasias:");
    scanf("%d", &hours);
    printf("Dwse thn amoibh ana wra:");
    scanf("%lf", &perhour);



    if (hours<=40) {
        perweek=hours*perhour;
    }
    else {
        perweek=40*perhour+1.5*(hours-40)*perhour;
    }
    }

printf("H ebdomadiaia amoibh einai %g.", perweek);
return 0;

}

