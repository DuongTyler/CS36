/* 
 * Exam 4 Program 2
 * Written by: Tyler Duong, Nikki Abedi, Jasmine Sourinthone
 * CS36 11/7/19
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int roll( int min, int max )            //return a random number between 1 and 6
{
  return (rand() / ((double)RAND_MAX+1)) * (max-min+1) + min;
}

void load(float *f_bet, int *i_user_num)
{
  printf("How lucky are you feeling: $");
  scanf("%f", f_bet);
  if ( *f_bet < 0 )                // f_bet <= 0
  { 
    printf("You can't bet negative money\n");
    *f_bet=0;
    return;
  }

  printf("What number are you betting on (1-6): ");
  scanf("%d", i_user_num);
  if ( *i_user_num < 1 || *i_user_num > 6 )
  {
    printf("You're stupid that number is invalid\n");
    *f_bet=0;
    return;
  }
} 

void print(float f_res)
{
  printf("Total: %0.2f\n", f_res);
}

float play(float f_bet, int i_user_num)
{
  int i, match, num;
  srand(time(NULL));              //generate a pseudo-random seed based on the time
 
  match=0;
  num=0;
  printf("numbers: ");
  for ( i=0; i<5; i++)
  {
    if ( (num=roll(1,6)) == i_user_num )
      match++;
    printf("%d ", num);
  }
  printf("\n");
  printf("Matched %d times\n", match);
  if (match > 0) return f_bet*match;
  return -f_bet;
}


int main()
{
  int 
    i,
    i_user_num;     //Purpose: hold the user's input for number bet on
  float
    f_bet,	    //Purpose: hold the user's input bet amount
    f_res;          //Purpose: hold the balance of the user

  f_res=0;

  for ( i=0; i < 5 && f_res < 50 && f_res > -50; i++)
  {
    load(&f_bet, &i_user_num);
    f_res += play(f_bet, i_user_num);
    print(f_res);
  }
  if (f_res >= 0)      
    printf("You won $%.02f\n", f_res);      //if res is greater than zero
  else
    printf("You lost $%.02f\n", fabsf(f_res));
	
  return 0;
}

/*
How lucky are you feeling: $20
What number are you betting on (1-6): 1
numbers: 3 4 2 6 3
Matched 0 times
Total: -20.00
How lucky are you feeling: $20
What number are you betting on (1-6): 3
numbers: 1 2 5 6 2
Matched 0 times
Total: -40.00
How lucky are you feeling: $20
What number are you betting on (1-6): 4
numbers: 1 4 4 5 6
Matched 2 times
Total: 0.00
How lucky are you feeling: $20
What number are you betting on (1-6): 2
numbers: 2 6 6 5 6
Matched 1 times
Total: 20.00
How lucky are you feeling: $100
What number are you betting on (1-6): 2
numbers: 1 4 2 1 1
Matched 1 times
Total: 120.00
You won $120.00
   */
