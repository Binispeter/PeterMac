#include <stdio.h>
#include <ctype.h>
#include <string.h>
void ConvertToUpper(char name[20], char surname[20], char out[50], char outCap[50]);
int main()
{
    char name[20], surname[20], out[50], outCap[50];
    printf("Enter onoma: ");
    gets(name);
    printf("Enter eponymo: ");
    gets(surname);
    ConvertToUpper(name, surname, out, outCap);
    printf("Onoma = %s, %d\n", name,(int)strlen(name));
    printf("Eponymo = %s, %d\n", surname, (int)strlen(surname));
    printf("Onomateponymo = %s, %d\n", out, (int)strlen(out));
    printf("Upper Onomateponymo = %s, %d\n", outCap, (int)strlen(outCap));
    return 0;
}
void ConvertToUpper(char name[20], char surname[20], char out[50], char outCap[50])
{
    int i;

    strncpy(out, name, strlen(name));
    out[strlen(name)] = ' ';
    strncpy(&out[strlen(name)+1], surname, strlen(surname));
    strncpy(outCap, out, strlen(out));
    for (i=0; outCap[i]!=0; i++)
    {
        if (islower(outCap[i]))
            outCap[i] -=  32;
    }

}
