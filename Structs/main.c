/*
 * This program creates a struct, assigns values, and prints it's values
 * Written by Tyler Duong
 * CS36 8-27-19
 */


#include <stdio.h>
#include <stdlib.h>

struct test{
	int x;
	char y;
	int z;
};

int main()
{
	struct test a;
	a.x = 6;
	a.y = 'a';
	a.z = 8|4;
	printf("Struct x is: %d\n", a.x);
	printf("Struct y is: %c\n", a.y);
	printf("Struct z is: %d\n", a.z);
	return 0;
}
