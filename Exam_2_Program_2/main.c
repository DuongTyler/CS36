/* 
 * Exam 2 Program 2
 * Written by: Tyler Duong, Nikki Abedi
 * CS36 9/5/19
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll( int min, int max )	//return a random number between 1 and 6
{
	return (rand() / ((double)RAND_MAX+1)) * (max-min+1) + min;
}

int main()
{
	int i_user_num, i;
	float f_bet, f_res;
	
	printf("How lucky are you feeling: $");
	scanf("%f", &f_bet);
	printf("What number are you betting on (1-6): ");	
	scanf("%d", &i_user_num);
	
	srand(time(NULL));	//generate a pseudo-random seed based on the time
	f_res = 0;
	for ( i = 0; i < 5; i++ )
		if ( i_user_num == roll(1,6) )	f_res += f_bet;	
		//for each correct roll, add the amount
	
	if (f_res)	printf("You won $%.02f\n", f_res);
	else		printf("Bad luck\n");

	return 0;
}
