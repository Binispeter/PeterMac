#include <stdio.h>
void a(int n);
void b(char l);
int main()
{
    int num;
    char let;
    printf("Enter a number (1-26): ");
    scanf("%d", &num);
    a(num);
    printf("Enter a capital letter: ");
    scanf("%s", &let);
    b(let);
    return 0;
}
void a(int n)
{
    char kef, mik;
    kef = n + 64;
    mik = kef + 32;
    printf("%d %c %c\n", n, kef, mik);
}
void b(char l)
{
    int n;
    n = l - 64;
    printf("%d", n);
}
