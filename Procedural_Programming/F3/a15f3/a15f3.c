#include <stdio.h>
int main()
{
    int i;
    for (i=1;i<=100;i++){
        i=i;
        printf("%5d",i);
         if (i%10 == 0){
        printf("\n");
         }}


    return 0;

}
