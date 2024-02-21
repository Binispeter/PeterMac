#include <stdio.h>
#include <stdbool.h>
int Sum_Cube (int n);
bool IsArmstrong (int n);
int cube (int num);

int main()
{
    int i;
    for (i=1;i<=999;i++){
        if (IsArmstrong(i)){
            printf("%d\n",i);
        }
    }

    return 0;
}

int Sum_Cube (int n)
{
    int d1, d2, d3, sum;
    d1 = n % 10;
    d2 = (n % 100) / 10;
    d3 = n /  100;
    sum = cube(d1) + cube(d2) + cube(d3);
    return sum;
}

int cube (int num)
{
    int result = num;
    for (int i=1;i<=2;i++)
    {
        result*=num;
    }
    return result;
}

bool IsArmstrong (int n)
{
    return (n == Sum_Cube(n));

}
