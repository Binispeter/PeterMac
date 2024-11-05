#include <stdio.h>
int main(){
    int rate;
    long purchaseAmount;
    double saleAmount, profit;
    printf("Dose kathari axia. \n");
    scanf("%ld", &purchaseAmount) ;
    printf("Dose pososto kerdous. \n");
    scanf("%d", &rate);
    profit = (purchaseAmount * rate) / 100;
    saleAmount = purchaseAmount + profit;
    printf("Kerdos %g \n", profit);
    printf("Synoliko Poso %g", saleAmount);
    return 0;

}
