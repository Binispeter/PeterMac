#include <stdio.h>
#include <string.h>
void removeSpaces(char array[100],char out[100]);
int main()
{
    char array[100], out[100];
    removeSpaces(array, out);

}
void removeSpaces(char array[100], char out[100])
{
    ;
    int length,  back = strlen(array) - 1, front=0;
    gets(array);
    while (array[front] == ' ')
        front++;
    while (array[back] == ' ')
        back--;

    length = back - front + 1;

    strncpy(out, array + front,length);
    out[length] = '\0';
    printf("%s", out);

}
