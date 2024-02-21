#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a,b,c;
	// Ομάδα προτάσεων 1α
	a=10;
	b=20;
	a=a+1;
	b=b-1;
	c=a*b;
	printf("1A a=%d b=%d c=%d\n",a,b,c);
	// Ομάδα προτάσεων 1β ισοδύναμη με την 1α
	a=10;
	b=20;
	c=++a * --b;
	printf("1B a=%d b=%d c=%d\n",a,b,c);
	// Ομάδα προτάσεων 2α
	a=10;
	b=20;
	a=a+1;
	c=a*b;
	b=b-1;
	printf("2A a=%d b=%d c=%d\n",a,b,c);
	// Ομάδα προτάσεων 2β ισοδύναμη με την 2α
	a=10;
	b=20;
	c=++a * b--;
	printf("2B a=%d b=%d c=%d\n",a,b,c);
	// Ομάδα προτάσεων 3α
	a=10;
	b=20;
	c=a*b;
	a=a+1;
	b=b-1;
	printf("3A a=%d b=%d c=%d\n",a,b,c);
	// Ομάδα προτάσεων 3β ισοδύναμη με την 3α
	a=10;
	b=20;
	c=a++ * b--;
	printf("3B a=%d b=%d c=%d\n",a,b,c);
	return 0;
}
