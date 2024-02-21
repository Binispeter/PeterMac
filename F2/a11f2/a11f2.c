#include <stdio.h>
int main() {

    float telh;
    int baros;

    printf("Dwse to baros: ");
    scanf("%d",&baros);

    if (baros>=1 && baros<=20) {
        telh = 25;
    }
    else if (baros>20 && baros<=200) {
        telh = 60;
    }

    else {
        telh = 0.4 * baros;
    }

    printf("Ta taxudromika telh einai %.2f", telh);
    return 0;

}




