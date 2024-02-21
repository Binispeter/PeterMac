#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct values
{
    int arKyk;
    char color[20], kataskeyastis[20];
    int kybika;
    int horsePower;
};
int main()
{
    struct values car;
    printf("Arithmos Kykloforias: ");
    scanf("%d", &car.arKyk);
    printf("Xroma: ");
    scanf("%s", car.color);
    printf("Kataskeyastis: ");
    scanf("%s", car.kataskeyastis);
    printf("Kybika: ");
    scanf("%d", &car.kybika);
    printf("Ippodynami: ");
    scanf("%d", &car.horsePower);


    return 0;
}
