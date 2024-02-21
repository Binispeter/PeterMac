#include <stdio.h>
int main()

{
    #define Orio 100000
    int n,sum,i,max,min;
    i=0;
    do {if (sum<Orio) {

        printf("Dose poso: ");
        scanf("%d",&n);
        sum+=n;
        i++;

    }
    else {
        sum=n;

    }
        if (max<n){
            max=n;
        }
        if (min>n){
            min = n;
        }
    }
    while (sum<Orio);
    printf("Synoliko poso: %d\n",sum);
    printf("Plithos atomon: %d\n",i);
    printf("Megalytero Poso: %d\n",max);
    printf("Mikrotero Poso: %d\n",min);


        return 0;
}
