/*
 * Written by Tyler Duong
 * CS36 09-10-19
 */

#include <stdio.h>


void stringcopy( char *dest, char *in )
{
	while (*in)	(*dest++) = (*in++);
	*dest = '\0';
}

int main()
{
	int a, b;
	char one[20] = "test it";
	char two[20];
	stringcopy( two, one );
	stringcopy( one, "make sure to" );
	printf("one: %s\ntwo: %s\n", one, two);
	
	if (NULL);
	
	printf("enter two intergers\n");
	scanf("%d", &a);
	scanf("%d", &b);
	if (a > b)		printf("a > b\n");
	else if (a < b)		printf("a < b\n");
	else if (a == b)	printf("a == b\n");
	
	return 0;
}
