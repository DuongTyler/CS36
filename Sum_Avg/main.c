
/*
 *	This program finds the sum and average of 3 ints
 *	Written by Tyler Duong
 *	CS 36 - Aug. 22, 2019
 */

#ifdef __unix__
	//most linux terminals do support ANSI escape characters
	#define TX_RST "\033[0m"
	#define TX_BNK "\033[5m"
	#define BG_RED "\033[41m"
	#define BG_GRN "\033[42m"
	#define BG_BLU "\033[44m"
#else
	//Visual Studio requires:
	#define _CRT_SECURE_NO_WARNINGS

	//Windows console cannot print \033 escape chars:
	#define TX_RST
	#define TX_BNK
	#define BG_RED
	#define BG_GRN
	#define BG_BLU
#endif
#define LENGTH 3

#include <stdio.h>
#include <string.h>

void f_print_arr(int *arr ,int len)
{
	for (int i = 0; i < len; i++ )
	{
		printf("%d ",arr[i]);
	}
}

int main(int argc, char *argv[])
{

	if (argc > 1 && strcmp(argv[1], "--plain-text") == 0)
	{
	}
	
	int num[LENGTH];

	float avg = 0;
	int sum = 0;
	
//	scanf("%d,%d,%d", &num[0], &num[1], &num[2]);

	for (int i = 0; i < LENGTH; i++)
	{
		printf(BG_RED"[Number %d]:"TX_RST" ", i+1);
		scanf("%d", &num[i]);
		sum += num[i];
	}

	/*
	 * A typecast is only needed if the left and right sides of the operation are not the
	 * wanted datatype
	 */
	
	avg = (float)sum/LENGTH;

	printf("The %d numbers are ", LENGTH);	
	f_print_arr(num, LENGTH);
	printf("\n\nThe sum of the %d ints is %d\n", LENGTH, sum);
	printf("The average is "TX_BNK BG_GRN" %.2f \n"TX_RST, avg);

	return 0;
}
