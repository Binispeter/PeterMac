#include <stdio.h>
#include <string.h>

typedef struct
{
    float heat_cost, common_charges;
} monthly_expenses;

typedef struct
{
    int apNumber;
    char name[25];
    int square_meters;
    int radiators;
} tenant;

typedef struct
{
    float heat_sum;
    float common_sum;
    float sum;
} calc;

typedef struct
{
    int tm_sum;
    int rad_sum;
} sums;

int ReadNumApparts();
monthly_expenses ReadMonthData();
tenant ReadEnoikoiData(int i, tenant data[20]);

calc Calculations(int m, float ap_heat[m], float ap_common[m],
                  float sum[m], sums *tmrads, calc charges, tenant data[m],
                  monthly_expenses monthly);
void Printing(int m, tenant data[m], float ap_heat[m], float ap_common[m],
     float sum[m], sums *tmrads, calc clc);

void Printing(int m, tenant data[m], float ap_heat[m], float ap_common[m],
     float sum[m], sums *tmrads, calc clc)
{

    printf("%3s %25s %5s %6s %12s %12s %12s\n", "A/A",
           "ONOMATEPONYMO", "T.M.", "FETES", "POSO THERM.",
           "POSO KOIN.", "SYNOLO");

    for (int i=0; i<82; i++)
    {
        printf("-");
    }
    printf("\n");

    for (int i=0; i<m; i++)
    {
        printf("%3d %25s %5d %6d %12.2f %12.2f %12.2f\n",
               i+1, data[i].name, data[i].square_meters, data[i].radiators,
               ap_heat[i], ap_common[i], sum[i]);
    }

      for (int i=0; i<82; i++)
    {
        printf("-");
    }
    printf("\n");

    printf("%-10s %19s %4d %6d %12.2f %12.2f %12.2f\n",
           "SYNOLA:", " ", tmrads->tm_sum, tmrads->rad_sum, clc.heat_sum, clc.common_sum,
           clc.sum);


}
int main()
{
    int m=0;
    monthly_expenses monthly;
    float ap_heat[20] = {0};
    float ap_common[20] = {0};
    float sum[20] = {0};
    sums *tmrads;
    calc charges;
    tenant data[20];


    m = ReadNumApparts();
    monthly = ReadMonthData();

    for (int i=0; i<m; i++)
    {
        ReadEnoikoiData(i, data);
    }

    charges = Calculations(m, ap_heat, ap_common,
                           sum, &tmrads, charges, data,
                           monthly);

    Printing(m, data, ap_heat, ap_common, sum, &tmrads, charges);

    return 0;
}

int ReadNumApparts()
{
    int m;
    printf("DWSE TO PLHTHOS TWN DIAMERISMATWN: ");
    scanf("%d", &m);
    return m;
}

monthly_expenses ReadMonthData()
{
    monthly_expenses data;
    printf("DWSE TO MHNIAIO POSO THERMANSHS: ");
    scanf("%f", &data.heat_cost);
    printf("DWSE TO MHNIAIO POSO KOINOXRHSTWN: ");
    {
        scanf("%f", &data.common_charges);
    }
    while (getchar() != '\n');

    return data;
}

tenant ReadEnoikoiData(int i, tenant data[20])
{
    printf("Dwse onomateponymo: ");
    gets(data[i].name);
    printf("Dwse t.m.: ");
    scanf("%d", &data[i].square_meters);
    while (getchar() != '\n');

    printf("Dwse fetes: ");
    scanf("%d", &data[i].radiators);
    while (getchar() != '\n');

    return data[i];
}

calc Calculations(int m, float ap_heat[m], float ap_common[m],
                  float sum[m], sums *tmrads, calc charges, tenant data[m],
                  monthly_expenses monthly)
{

    int i;
    tmrads->rad_sum = 0;
    tmrads->tm_sum = 0;

    for(i=0; i<m; i++)
    {
        tmrads->tm_sum += data[i].square_meters;
        tmrads->rad_sum += data[i].radiators;
    }

    for(i=0; i<m; i++)
    {
        ap_heat[i] = (data[i].radiators / (float)tmrads->rad_sum) * (float)monthly.heat_cost;

        ap_common[i] = (data[i].square_meters / (float)tmrads->tm_sum) * (float)monthly.common_charges;

        sum[i] = ap_heat[i] + ap_common[i];
    }

    for(i=0; i<m; i++)
    {
        charges.common_sum += ap_common[i];
        charges.heat_sum += ap_heat[i];
    }
    charges.sum = charges.common_sum + charges.heat_sum;


    return charges;
}
