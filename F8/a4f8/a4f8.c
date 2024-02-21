#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct
{
    char name[26];
    char address[26];
    int tk;
    char city[16];
    char country[16];
    int type;
    int weight;
}data;

void readArray(int M, data parcel[N]);
void calculations(int M, data parcel[N], float *inside, float *outside, int *pIn, int *pOut);
void Printing(float inside, float outside, int pIn, int pOut);
int main()
{
    int m;
    data parcel[N];
    float inside, outside;
    int pIn, pOut;

    printf("Enter the number of parcels: ");
    scanf("%d", &m);
    readArray(m, parcel);
    calculations(m, parcel, &inside, &outside, &pIn, &pOut);
    Printing(inside, outside, pIn, pOut);
    return 0;
}

void readArray(int M, data parcel[N])
{
    int i;

    for (i=0; i<M; i++)
    {
        printf("Name: ");
        scanf("%s", parcel[i].name);


        printf("Address: ");
        gets(parcel[i].address);
        while (getchar()!= '\n');

        printf("Zip: ");
        scanf("%d", &parcel[i].tk);

        printf("City: ");
        scanf("%s", parcel[i].city);

        printf("Country: ");
        scanf("%s", parcel[i].country);

        printf("Type (1 or 2): ");
        scanf("%d", &parcel[i].type);

        printf("Weight: ");
        scanf("%d", &parcel[i].weight);
    }

}

void calculations(int M, data parcel[N], float *inside, float *outside, int *pIn, int *pOut)
{
    int i;
    float in_sum=0;
    float out_sum=0;
    float cost;
    int in=0, out=0;

    for (i=0; i<M; i++)
    {
        if(parcel[i].type == 1)
        {
            cost = parcel[i].weight * 0.40;
            in_sum += cost;
            in++;
        }

        else
        {
            cost = parcel[i].weight * 0.84;
            out_sum += cost;
            out++;
        }

    }

    *pIn = in;
    *pOut = out;
    *inside = in_sum;
    *outside = out_sum;
}

void Printing(float inside, float outside, int pIn, int pOut)
{


    printf("ESWTERIKOY: %d %.2f\n", pIn, inside);
    printf("EXWTERIKOY: %d %.2f", pOut, outside);
}
