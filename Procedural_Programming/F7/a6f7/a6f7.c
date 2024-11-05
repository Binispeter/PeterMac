#include <stdio.h>
#include <stdlib.h>

#define MinLetters 2
#define MaxLetters 8

void RandomWord(char word[]);

int main()
{
    char word[MaxLetters];
    for(int i=0; i<5; i++)
    {
        RandomWord(word);
        printf("%s\n", word);
    }

    return 0;
}

void RandomWord(char word[])
{
    int num, i=0;
    num = (rand()%(MaxLetters-MinLetters+1)) + MinLetters;

    int ch;

    while(i<num)
    {
        ch = 'a' + rand()%26;
            word[i] = ch;
            i++;
    }
    word[i] = '\0';
}
