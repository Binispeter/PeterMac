#include <stdio.h>
int reversenum (int num);
int main()
{   int num;

    do {
    printf("Give a number: ");
    scanf("%d", &num);

    if (num != -1)
    {
        printf("%d ", num);
    }

    else
    {
        break;
    }}
    while (reversenum(num) != 0);

    return 0;
}

int reversenum(int num)
{   int digit;
    while (num != 0) {

    digit = num % 10;
    printf("%d",digit);
    num /= 10;
    }
    printf("\n");
    return digit;
}
