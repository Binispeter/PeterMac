#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a,b,c;
	// ����� ��������� 1�
	a=10;
	b=20;
	a=a+1;
	b=b-1;
	c=a*b;
	printf("1A a=%d b=%d c=%d\n",a,b,c);
	// ����� ��������� 1� ��������� �� ��� 1�
	a=10;
	b=20;
	c=++a * --b;
	printf("1B a=%d b=%d c=%d\n",a,b,c);
	// ����� ��������� 2�
	a=10;
	b=20;
	a=a+1;
	c=a*b;
	b=b-1;
	printf("2A a=%d b=%d c=%d\n",a,b,c);
	// ����� ��������� 2� ��������� �� ��� 2�
	a=10;
	b=20;
	c=++a * b--;
	printf("2B a=%d b=%d c=%d\n",a,b,c);
	// ����� ��������� 3�
	a=10;
	b=20;
	c=a*b;
	a=a+1;
	b=b-1;
	printf("3A a=%d b=%d c=%d\n",a,b,c);
	// ����� ��������� 3� ��������� �� ��� 3�
	a=10;
	b=20;
	c=a++ * b--;
	printf("3B a=%d b=%d c=%d\n",a,b,c);
	return 0;
}
