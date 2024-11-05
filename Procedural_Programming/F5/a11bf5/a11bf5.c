#include <stdio.h>
#include <math.h>

#define CTS 10
#define S 3

void getTemps(int rows, int cols, double temper[CTS][S]);
double natAvg(int rows, int cols, double temper[CTS][S]);
void ctAvg(int rows, int cols, double temper[CTS][S], double average[CTS]);
void SD(int rows, int cols, double natavg, double temper[CTS][S], double devnat[CTS][S]);
void maxSD(int rows, int cols, double sd[CTS][S], double mdev[CTS]);
void printRes(int rows, double natavg, double avg[CTS], double mdev[CTS]);

int main()
{
    double temper[CTS][S], average[CTS], devnat[CTS][S], mdev[CTS], natavg;

    getTemps(CTS, S, temper);
    natavg = natAvg(CTS, S, temper);
    ctAvg(CTS, S, temper, average);
    SD(CTS, S, natavg, temper, devnat);
    maxSD(CTS, S, devnat, mdev);

    return 0;
}

void getTemps(int rows, int cols, double temper[CTS][S])
{
    int i, j;
    for (i=0; i<rows; i++)
        for (j=0; j<cols; j++)
    {
       printf("Temp of City %d During $d 8-hour period: ", i, j);
       scanf("%lf", &temper[i][j]);
    }
}


double natAvg(int rows, int cols, double temper[CTS][S])
{
    int i, j;
    double natavg = 0;
     for (i=0; i<rows; i++)
    {
        for (j=0; j<cols; j++)
        {
        natavg += temper[i][j];
        }
    }
    natavg = natavg / (CTS*S);
    return natavg;

}


void ctAvg(int rows, int cols, double temper[CTS][S], double average[CTS])
{
    int i, j;
    for (i=0; i<rows; i++)
    {
        average[i]=0;
        for (j=0; j<cols; j++)
        {
            average[i] += temper[i][j];
        }
        average[i] = average[i]/cols;
    }
}

void SD(int rows, int cols, double natavg, double temper[CTS][S], double devnat[CTS][S])
{
    int i,j;
          for (i=0; i<rows; i++)
    {
        for (j=0; j<cols; j++)
        {
            devnat[i][j] = fabs(natavg - temper[i][j]);
        }
    }
}


void maxSD(int rows, int cols, double sd[CTS][S], double mdev[CTS])
{
    int i,j;
    for (i=0; i<rows; i++)
    {
        mdev[i] = sd[i][0];
        for (j=1; j<cols; j++)
        {
            if (mdev[i] < sd[i][j])
            {
                mdev[i] = sd[i][j];
            }
        }
    }
}


void printRes(int rows, double natavg, double avg[CTS], double mdev[CTS])
{
    int i;
    printf("%3.lf\n", natavg);
    for (i=0; i<rows; i++)
    {
        printf("City %d %.lf %.lf\n", i, avg[i], mdev[i]);
    }
}

