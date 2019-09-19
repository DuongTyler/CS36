#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* three steps to pick a randNum number in C
  -  include header file
  -  declare the time_t variable in main
  -  seed the randNum generator using srand
*/

int randNum(int min, int max)
{
	//return (rand() / ((double)RAND_MAX+1)) * (max-min+1) + min;
	return ((rand() % (max - min + 1)) + min);
}

int main()
{
	time_t t;
	srand((unsigned)time(&t));
	//srand((unsigned)time(NULL)); //you can do this too, but it's not compatible with some older systems
	printf("%d\n", randNum(1, 60));
	printf("%d\n", randNum(1, 60));
	printf("%d\n", randNum(1, 60));
	printf("%d\n", randNum(1, 60));
	return 0;
}
