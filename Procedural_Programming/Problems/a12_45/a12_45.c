#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool plaisio(int p[][10]);

int main(void)
{
	int grid[10][10]= {0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,
                       0,0,1,0,0,0,1,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,
                       0,0,1,0,0,0,1,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0};
    if (plaisio(grid))
	   printf("Nai yparxei plaisio\n");
    else
       printf("DEN yparxei plaisio\n");

    return 0;
}

bool plaisio(int p[][10])
{
    int cnt=0,i,j,g1,s1,g2,s2,g3,s3,g4,s4;
    for (i=0;i<10;i++)
        for (j=0;j<10;j++)
        {
           if (p[i][j]==1)
           {
              cnt++;
              switch (cnt)
              {
               case 1:
                     g1=i;
                     s1=j;
                     break;
               case 2:
                     g2=i;
                     s2=j;
                     break;
               case 3:
                     g3=i;
                     s3=j;
                     break;
               case 4:
                     g4=i;
                     s4=j;
                     break;
              }
           }
        }
    if (cnt!=4) return false;
    if (g1==g2 && g3==g4 && s1==s3 && s2==s4)
       return true;
    else
       return false;
}


