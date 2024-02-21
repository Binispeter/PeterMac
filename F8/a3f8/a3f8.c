#include <stdio.h>

typedef struct
{
    char date[11];
    int tim_num;
    long emp_value;
    int fpa;
}timrec;


int read_timologia(int num, int year, timrec timologia[]);
void write_data(int count, timrec timologiap[]);
resrec calculate_results(int m, timrec timologia[], resrec result[]);
void write_results(resrec results[], resrec sum);
