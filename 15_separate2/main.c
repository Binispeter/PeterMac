#include <stdio.h>
#include <stdlib.h>

extern int fores;

void book();
void thanks(char *name);
void poly();

int main(void)
{
  int i;
  for (i=1;i<=fores;i++) book();
  thanks("Niko");
  poly();
  return 0;
}

