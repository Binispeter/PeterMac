#include <stdio.h>
#include <stdbool.h>
float mo (float a, float b, float c);
int main(){
    float a,b,c;
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);
    if (mo(a,b,c) == -1)
        printf("No value in [1, 2]");
    else printf("Avg = %.2f", mo(a,b,c));
    return 0;
}

float mo(float a, float b, float c)
{   float mo;
    if (((a && b && c) < 1) || (a && b && c > 2))
    {
        return -1;
    }
    else if ((a < 1)|| (a > 2)){
            return mo = (b + c) / 2;
    }
    else if ((b < 1)|| (b > 2)){
            return mo = (a + c) / 2;
    }
    else if ((c < 1)|| (c > 2)){
            return mo = (b + a) / 2;
    }
    else return mo = (a + b + c) / 3;
}
