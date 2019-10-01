#include <stdio.h>
#include "params.h"

void func()
{
	printf("Currently being useless\n");
}

int main()
{
	struct cube c = {2, 4, 10, &func};
	int x;
	printf("2+3=%d\n", sum(1,2));
	c.foo();

	doMore(&c);
	
	doStuff(&x);
	printf("X: %d\n", x);
	
	printf("l=%.2f\n", c.l);
	printf("w=%.2f\n", c.w);
	printf("h=%.2f\n", c.h);

	return 0;
}
