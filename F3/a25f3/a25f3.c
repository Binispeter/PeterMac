#include <stdio.h>
int main ()
{
    int number, sum, i, sum1;
    printf("Give an integer between [0..1000] ");
    scanf("%d", &number);

    while (number<0 || number>1000){
    printf("Give an integer between [0..1000] ");
    scanf("%d", &number);
    }
    if (0<=number || 100>=number) {
        for (i=0;i<=number;i++){
            sum+=i;
        }
            sum1 = number*(number + 1)/2;
            }



    printf("The sum of 0+1+2+...+number is %d %d", sum, sum1);
    return 0;
}
