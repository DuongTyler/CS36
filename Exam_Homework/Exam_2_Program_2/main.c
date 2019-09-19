/* 
 * Exam 2 Program 2
 * Written by: Tyler Duong, Nikki Abedi
 * CS36 9/5/19
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll( int min, int max )		//return a random number between 1 and 6
{
	return (rand() / ((double)RAND_MAX+1)) * (max-min+1) + min;
}

int main()
{
	//for portability across as many systems as possible, I declare variables up here
	int 
		i_user_num, 	//Purpose: hold the user's input for number bet on
		i, 		//Purpose: act as an iterator for all for loops
		r;		//Purpose: hold each roll's result for printing
	float 
		f_bet, 		//Purpose: hold the user's input for amount bet
		f_res;		//Purpose: hold the result winnings of the user
	
	printf("How lucky are you feeling: $");
	scanf("%f", &f_bet);
	printf("What number are you betting on (1-6): ");	
	scanf("%d", &i_user_num);
	
	srand(time(NULL));		//generate a pseudo-random seed based on the time
	f_res = 0;			//init result as 0
	printf("Roll: ");
	for ( i = 0; i < 5; i++ )	//roll 5 times
	{
		r = roll(1,6);		//generate the roll
		printf("%d ", r);	//print each value so the user can verify that this rigged game is rigged
		if ( i_user_num == r )	f_res += f_bet;		//for each correct roll, add the amount
	}
	printf("\n");

	if (f_res)	printf("You won $%.02f\n", f_res);	//if > 0
	else		printf("Bad luck\n");			//else you lost

	return 0;
}
