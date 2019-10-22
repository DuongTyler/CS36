#include <stdio.h>

//local variables can only be called in the function
//global variables can be references from almost all functions
//scope of a variable

void load(int *a, int *b, int *c)
{
	printf("enter 3 values\n");
	scanf("%d",a);
	scanf("%d",b);
	scanf("%d",c);
}

int sum(int a, int b, int c)
{
	return a+b+c;
}

float avg(int a, int b, int c)
{
	return (a+b+c)/(float)3;
}

void test()
{
	int (*func)(int, int, int);
	func = &sum;
	printf("TEST: %d (should be 6)\n",func(1,2,3));
}

int main()
{
	//main should only contain declarations, function calls, and loops
	int a, b, c;
	load(&a, &b, &c);
	printf("Sum: %d\n", sum(a, b, c));
	printf("Average: %.3f\n", avg(a, b, c));

	test();

	return 0;
}
