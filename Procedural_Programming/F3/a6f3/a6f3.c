#include <stdio.h>
int main()
    {
        int N, i, sum, n;
        printf("N: ");
        scanf("%d",&N);
        sum = 0;
        printf("%d\n",sum);
        n=1;

        for (i=0;i<=N;i++) {
            sum+=n;
            n=sum-n;

            printf("%d\n",sum);}

       return 0;
    }
