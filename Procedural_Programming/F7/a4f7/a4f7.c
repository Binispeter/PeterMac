#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool IsConsonant(char ch);

int main()
{
    char ch;
    printf("Enter a letter: ");
    scanf("%c", &ch);

    if (IsConsonant(ch))
        printf("%c is a consonant\n", ch);

    else
    {
        printf("%c is not a consonant\n", ch);
    }

    return 0;
}

bool IsConsonant(char ch)
{
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    int n;

    for (n=0; n<5; n++)
    {
        if(ch==vowels[n] || ch==toupper(vowels[n]))
        {
            return 0;
            break;
        }
    }
    return 1;
}
