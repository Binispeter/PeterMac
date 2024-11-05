#include <stdio.h>
#include <stdlib.h>
float Func (int p1, int p2, int p3);
#define pb 5
#define pg 10

int main ()
{   int p1;
    float res;
for (p1 = 1;p1<=10;p1++){

res = Func(p1, pb, pg);
     if (p1 == 1)
        printf("Athr=%f\n",Func(p1, pb, pg));


    else if (p1 == 2)
        printf("Gin=%f\n",Func(p1, pb, pg));

    else if (p1 == 3)
        printf("Mo=%f\n",Func(p1, pb, pg));
    }


   return 0;
}

float Func (int p1, int p2,int p3)
{
    float res;
    if (p1 == 1)
        res = p2 + p3;


    else if (p1 == 2)
        res = p2 * p3;

    else if (p1 == 3)
        res = (p2 + p3) / 2.0;
    else {
        printf("Antikanoniki ektelesi synartisis");
        exit(1);
        }

        return res;
}
