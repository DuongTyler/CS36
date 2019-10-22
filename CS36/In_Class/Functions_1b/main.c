#include <stdio.h>


//prototypes
int funcA();

//GLOBAL VARIABLES ARE BANNED
//Never use them to prevent side effects, local variables changing x might mess up global
int a, b, c;

int main()
{
	a=2, b=3, c=4;
	printf("%d\n", funcA());
	return 0;
}


int funcA()
{
	return a+b;
}

int sum()
{
	return a+b+c;
}
