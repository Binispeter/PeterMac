#include <stdio.h>

int
main ()
{
  int i, j, prod;
  double commis[4];
  i = 0;
  j = 0;
  long collect;
  int products[5][5] = { {10, 4, 5, 6, 7},
  {7, 0, 12, 1, 3},
  {4, 9, 5, 0, 8},
  {3, 2, 1, 5, 6}
  };

  int price[5] = { 25000, 15000, 32000, 21000, 9200 };
  int add[5];
  printf ("EISPRAXEIS: ");
  for (i = 0; i < 4; i++)
    {

      collect = 0;
      prod = 0;
      for (j = 0; j < 5; j++)
	{
	  prod = (price[j]) * (products[i][j]);
	  collect += prod;



	}


      printf ("%ld ", collect);
    }

  printf ("\nPROMHTEIES: ");
  for (i = 0; i < 4; i++)
    {

      collect = 0;
      prod = 0;
      for (j = 0; j < 5; j++)
	{
	  prod = (price[j]) * (products[i][j]);
	  collect += prod;



	}
      commis[i] = (double) collect *0.10;
      printf ("%.2lf ", commis[i]);


    }
  printf ("\nPOSOTHTES: ");
  for (j = 0; j < 5; j++)
    {
      for (i = 0; i < 5; i++)
	{
	  add[j] += products[i][j];

	}

      printf ("%d ", add[j]);
    }
  return 0;
}
