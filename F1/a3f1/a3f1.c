#include <stdio.h>
int main(){
    freopen("a3f1.in", "r", stdin);
    freopen("a3f1.out", "w", stdout);
    int x, n1 , n5, n20, n50;
    printf("Dose plithos siskeuwn. \n");
    scanf("%d", &x);
    n50 = x/50;
    n20 = (x%50)/ 20;
    n5 = ((x%50)%20) / 5;
    n1 = (((x%50)%20)%5) / 1;
    printf("50 %d \n",n50);
    printf("20 %d \n",n20);
    printf("5 %d \n",n5);
    printf("1 %d \n",n1);
return 0;


}
