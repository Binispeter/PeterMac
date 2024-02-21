#include <stdio.h>
#include <math.h>

#define cars 80000
#define rate 0.07
int main() {

long years, carsf;

    carsf = cars;
    years = 0;

    while(carsf <= 160000) {
        carsf = ceil(carsf*(1+rate));
        years++;
}
    printf("Years: %ld\n",years);
    printf("Cars: %ld\n",carsf);
    return 0;
}
