
/*
 *	This program finds the sum and average of 3 ints
 *	Written by Tyler Duong
 *	CS 36 - Aug. 22, 2019
 */
/*
#ifdef __unix__
	//most linux terminals do support ANSI escape characters
	#define TX_RST "\033[0m"
	#define TX_BNK "\033[5m"
	#define BG_RED "\033[41m"
	#define BG_GRN "\033[42m"
	#define BG_BLU "\033[44m"
#else
*/	//Visual Studio requires:
	#define _CRT_SECURE_NO_WARNINGS

	//Windows console cannot print \033 escape chars:
	#define TX_RST
	#define TX_BNK
	#define BG_RED
	#define BG_GRN
	#define BG_BLU
/*
#endif
*/

#define LENGTH 3
#define N_STUDENTS 2

#include <stdio.h>
#include <string.h>

void f_print_arr(int *arr ,int len)
{
	for (int i = 0; i < len; i++ )
	{
		printf("%d ",arr[i]);
	}
}

int main(/*int argc, char *argv[]*/)
{
	
	char name[2][20];
	int num[2][LENGTH];

	float avg[2]; //= {0,0};
	int sum[2]; //= {0,0};

	for (int s = 0; s < N_STUDENTS; s++)
	{
		avg[s] = 0;
		sum[s] = 0;
		for (int i = 0; i < LENGTH; i++)
		{
			printf(BG_RED"[Number %d]:"TX_RST" ", i+1);
			scanf("%d", &num[s][i]);
			sum[s] += num[s][i];
		}


		printf("Enter your name: ");
	//	fflush(stdin);		//not working for gcc 9.1.0
		while (getchar() != '\n');
	//	while (getchar() != "\n");
	//	scanf("%[^\n]", name);
		fgets(name[s], 20, stdin);
	//	name[s][19] = '\0';
		printf("Your name is: %s\n", name[s]);


		//DEBUGGING because I was interested where the memory addresses were being assigned
		printf("\n\n");
		printf("name:\t%p\n", name[s]);
		printf("avg:\t%p\n", &avg[s]);
		printf("sum:\t%p\n", &sum[s]);
		printf("\n\n");
		printf("SizeOf name:\t%ld\n", sizeof(name[s]));
		printf("SizeOf avg:\t%ld\n", sizeof(avg[s]));
		printf("SizeOf sum:\t%ld\n", sizeof(sum[s]));
		printf("SizeOf sum+avg:\t%ld\n", sizeof(sum[s]) + sizeof(avg[s]));
		printf("\n\n");
		
	/*
		for (int i = 0; i < LENGTH; i++)
		{
			printf(BG_RED"[Number %d]:"TX_RST" ", i+1);
			scanf("%d", &num[i]);
			sum += num[i];
		}
	*/
		avg[s] = (float)sum[s]/LENGTH;

		printf("The %d numbers are ", LENGTH);	
		f_print_arr(num[s], LENGTH);
		printf("\n\nThe sum of the %d ints is %d\n", LENGTH, sum[s]);
		printf("The average is "TX_BNK BG_GRN" %.2f \n"TX_RST, avg[s]);
	}
	return 0;
}
