/* 
 * Exam 2 Program 2
 * Written by: Tyler Duong
 * CS36 9/5/19
 */

#include <stdio.h>
#include <stdlib.h>

int roll( int min, int max )
{
	return (rand() / ((double)RAND_MAX+1)) * (max-min+1) + min;
}

int main()
{
	printf("%d\n", roll(1,6));
	printf("%d\n", roll(1,6));
	printf("%d\n", roll(1,6));
	return 0;
}
