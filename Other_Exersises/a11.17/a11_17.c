#include <stdio.h>
void function(int n, int *pmin, int *pmax, int *path, int *pgin, int *pplith);

int main()
{
    int num, min, max, ath, gin, plith;
    printf("Give an integer: ");
    scanf("%d", &num);
    function(num, &min, &max, &ath, &gin, &plith);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Sum: %d\n", ath);
    printf("Product: %d\n", gin);
    printf("Number of digits: %d", plith);
    return 0;
}

void function(int n, int *pmin, int *pmax, int *path, int *pgin, int *pplith)
{
   int m, ath = 0, gin = 1, max = 0, min, plith = 0;
    while (n != 0)
    {
        m = n % 10;
        ath += m;
        gin *= m;
        if (m > max)
        {
            max = m;
        }
        else if (m <= min)
        {
            min = m;
        }
        plith ++;
        n /= 10;
    }
    *pplith = plith;
    *path = ath;
    *pgin = gin;
    *pmax = max;
    *pmin = min;

}
