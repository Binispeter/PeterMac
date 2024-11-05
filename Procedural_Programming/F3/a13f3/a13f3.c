#include <stdio.h>
int main()
{
    int N,i;
    float sum;
    sum=0;
    printf("Orio: ");
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        sum+=1/(double)i;
    }
    printf("To athroisma einai %.2f", sum);
    return 0;
}
