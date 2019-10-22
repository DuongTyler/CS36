/*
 * CS36 Exam 3 Program 1
 * Written by: Tyler Duong, Nikki Abedi, Jasmine Sourinthone
 * 
 * This program will input 4 intergers and sort them:
 * 	INPUT:
		- 4 ints
 	OUTPUT:
		- 4 sorted ints
		- The MAX value amongst the ints
		- The input numbers
 */
#include <stdio.h>

void load( int nums[], int len )
//allow the user to load 4 int values
{
    for (int i = 0; i < len; i++)
    {
			printf("Enter a number ");
      scanf("%d", &nums[i]);
		}
}

void print( int nums[], int len )
{
  printf("The numbers are  ");
  for (int i = 0; i < len; i++)	   printf("%d ", nums[i]);
  printf("\n");
}

int max( int nums[], int len )
{
        int i;
        int max=0;
        for ( i = 1; i < len; i++ )
                if (nums[i] > nums[max])        max = i;
        return nums[max];
}

/* void swap(int *a , int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
  
  //reference parameters CORRECT
}
*/


void sort( int nums[], int len )
//Sort from low to high
{
        int i, j, min;
				//loop through each element in reverse, except for the first element
        for ( i = 1; i < len; i++ )
        {
		min = nums[i];
		j = i-1;	//start j from the element behind i
		while ( j >= 0 && nums[j] > min)	//keep iterating backwards while j >= 0 and element j is greater then min
		{
			nums[j+1] = nums[j];
			j = j-1;
		}
		nums[j+1] = min;
        }
}

int main()
{
        int nums[4];
        load(nums, 4);
        print(nums, 4);
        printf("Max number: %d\n", max(nums, 4));
        sort(nums, 4);
        print(nums, 4);
        return 0;
}

