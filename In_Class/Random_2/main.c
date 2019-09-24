#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int random_f( int min, int max )
{
	return (rand() % (max - min + 1) + min);
}


int main()
{
	time_t t;
	int r1, r2, s;
	srand((unsigned)time(&t));
	printf(		"if sum is 7 or 11 you win\n"
			"if sum is 2, 3, or 12 you lose\n"
			"else tie\n");
	r1 = random_f(1,6);
	r2 = random_f(1,6);
	s = r1+r2;
	printf(		"Your numbers are: %d %d\n"
			"The sum is: %d\n"
			, r1, r2, s
	      );
	(s == 7 || s == 11)?
		printf("You win!\n") : 
			(s == 2 || s == 3 || s == 12)? 
				printf("You lose!\n"):
					printf("Tie\n");
	
	
	
	return 0;
}
