/* 
 * Exam 2 Program 2
 * Written by: Tyler Duong, Nikki Abedi, Jasmine Sourinthone
 * CS36 9/5/19
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll( int min, int max )            //return a random number between 1 and 6
{
        return (rand() / ((double)RAND_MAX+1)) * (max-min+1) + min;
}

int main()
{
        int 
                i_user_num,     //Purpose: hold the user's input for number bet on
                i,              //Purpose: act as an iterator for all for loops
                r,              //Purpose: hold each roll's result for printing
                i_win_ct;       //Purpose: hold the number of times the user matched their number
        float 
                f_bet,          //Purpose: hold the user's input for amount bet
                f_res;          //Purpose: hold the result winnings of the user

        printf("How lucky are you feeling: $");
        scanf("%f", &f_bet);
        if ( f_bet < 0 )		// f_bet <= 0
        { 
          printf("You can't bet negative money\n");
          return 3;
        }
				
        printf("What number are you betting on (1-6): ");
        scanf("%d", &i_user_num);
        if ( i_user_num < 1 || i_user_num > 6 )
				{
						printf(" You're stupid that number is invalid\n");
            return 8;
				}

        srand(time(NULL));              //generate a pseudo-random seed based on the time
        f_res = 0;                      //init result as 0
        i_win_ct = 0;
        printf("Roll: ");
        for ( i = 0; i < 5; i++ )       //roll 5 times
        {
                r = roll(1,6);          //generate the roll
                printf("%d ", r);       //print each value so the user can verify that this rigged game is rigged
                if ( i_user_num == r )
                {
                        f_res += f_bet;         //for each correct roll, add the amount
                        i_win_ct++;
                }
        }
        printf("\n");

        //if the count is not 0, you win
        (i_win_ct)? printf("You matched %d time(s)!\n", i_win_ct) : printf("You didn't match anything\n");
				
        if (f_res)      printf("You won $%.02f\n", f_res);      //if is a non-zero value
        else            printf("You sorta suck at this game...\n");                   //else you lost


				//operators
				// x++	- increment x by one after
				// ++x 	- increment x by one before
				// x--	-	decrease x by one after
				// --x	- decrease x by one before
				// x+=5	- increase x by 5
        return 0;
}


/*
OUTPUT:
$ ./main
How lucky are you feeling: $6000
What number are you betting on (1-6): 5
Roll: 5 2 1 6 3
You matched 1 time(s)!
You won $6000.00

$ ./main
How lucky are you feeling: $2
What number are you betting on (1-6): 2
Roll: 5 2 4 2 2
You matched 3 time(s)!
You won $6.00

$ ./main
How lucky are you feeling: $-100
You can't bet negative money

$ ./main
How lucky are you feeling: $1
What number are you betting on (1-6): -2
 You're stupid that number is invalid
*/


//Pick a random number and a range ( the computer)
				//Srand and rand only
				//2000 to 8000
				//srand((unsigned)time(&t));
				//Num = rand()%6001 + 2000;
				//Num = rand()%(max-min+1) + min;
				//printf("Enter the score  ");
	      // scanf("%d", &score);
  	   //  if (score < 0 || score > 100)

				// > greater than		if ( 2 > 1 ) ...
				// >= gt or eq to		if ( 2 >= 2 ) ... if ( x >= 100 ) ...
				// < less than
				// <= lt or eq to
				// == equal to
				// &&	and			if (true && true) ...				if ( x >= 100 && y >= 100 ) ...
				// || or			if (true || false) ...			if (1 > 0 || 1 > 4)
				// ( 2 > 1 ) == true

