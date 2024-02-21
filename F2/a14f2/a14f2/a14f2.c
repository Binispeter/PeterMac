#include <stdio.h>
int main()  {

    double B,Y, dms;
    printf("Dose ypsos: ");
    scanf("%lf",&Y);
    printf("Dose baros: ");
    scanf("%lf", &B);
    dms = B / (Y*Y);

    if (dms<18.5){
        printf("Lipobaris (Tsouglis)");
    }
    else if (dms>=18.5 && dms<25) {
        printf("Kanonikos (Pane mila ths)");
    }
    else if (dms>=26 && dms<30){
        printf("Yperbaros (Gourouni)");
    }
    else {
        printf("Paxisarkos (Den blepesai)");

    }
    return 0;
}
