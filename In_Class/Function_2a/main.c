#include <stdio.h>

void load( int *a, int *b, int *c )
{
	printf("Enter for a: ");
	scanf("%d", a);
	printf("Enter for b: ");
	scanf("%d", b);
	printf("Enter for c: ");
	scanf("%d", c);
}

void sumavg1(int a, int b, int c, int *sum, float *avg)
{
	*sum = a+b+c;
	*avg = *sum/(float)3;
}

void print(int a, int b, int c, int sum, float avg)
{
	printf("The Numbers are: %d %d %d\n", a, b, c);
	printf("The Sum and average are: %d %.3f\n", sum, avg);
}

int main()
{
	int x,y,z,sum;
	float avg;
	load(&x, &y, &z);
	sumavg1(x,y,z,&sum,&avg);
	print(x,y,z,sum,avg);
	return 0;
}
