#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[60];
    int start;
    int duration;
} work;

void ReadWorkpackages(work packages[100], int packs);
work FindFirstWp(work packages[100], int packs);

int main()
{
    int packs, i;
    work packages[100], first;

    printf("Total work packages: ");
    scanf("%d", &packs);

    ReadWorkpackages(packages, packs);

    first = FindFirstWp(packages, packs);
    printf("First WP: %s\nStart: %d\n Duration: %d", first.name, first.start, first.duration);


    return 0;
}
void ReadWorkpackages(work packages[100], int packs)
{
    int i;

    for (i=0; i<packs; i++)
    {
        printf("WP Name: ");
        scanf("%s", packages[i].name);


        printf("WP Start Month: ");
        scanf("%d", &packages[i].start);

        printf("WP Duration: ");
        scanf("%d", &packages[i].duration);
    }
}

work FindFirstWp(work packages[100], int packs)
{
    int i, min, pointer;
    work first;

    min = packages[0].start;

    for (i=0; i<packs; i++)
    {
        if(packages[i].start < min)
        {
            min = packages[i].start;
            pointer = i;
        }
    }

    first.duration = packages[pointer].duration;
    first.start = packages[pointer].start;
    strcpy(first.name, packages[pointer].name);

    return first;
}
