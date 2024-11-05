#include <stdio.h>
int main() {

    long eswt, exwt;
    double keswt, kexwt, kostos;

    printf("Dwse ton arithmo epistolwn eswterikou:");
    scanf("%ld", &eswt);
    printf("Dwse ton arithmo epistolwn exwterikou:");
    scanf("%ld", &exwt);
    keswt = 0.30 * eswt;
    kexwt = 0.80 * exwt;
    kostos = keswt + kexwt;
    printf("To synoliko kostos apostolis einai %g", kostos);

    return 0;

}
