#include <stdio.h>


void swap( int *a, int *b )
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int a, b;
	a = 5; b = 2;
	printf("A: %p\nB: %p\n", a, b);
	printf("A: %d\nB: %d\n", a, b);

	swap(&a, &b);

	printf("A: %d\nB: %d\n", a, b);
	printf("A: %p\nB: %p\n", a, b);
	return 0;
}
