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
        int max=0;	//max is the key of the max value location
        for ( i = 1; i < len; i++ )	if (nums[i] > nums[max])        max = i; //if we find something larger, replace the index
        return nums[max];	//return the max index
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
//Sort from low to high, insertion sort
{
        int i, j, min;
	//loop through each element, and compare the current element with the previous ones, then swap the value when i is gt j
        for ( i = 1; i < len; i++ )
        {
		min = nums[i]; //set current index to the min value, this is a placeholder temp value
		j = i-1;	//start j from the element behind i
		while ( j >= 0 && nums[j] > min)	//keep iterating j backwards while j >= 0 and element j is greater then min
		{
			nums[j+1] = nums[j]; 	//keep shifting each value to the right until we find the correct value
			j = j-1;		//decriment j
		}
		//if element j is finally less than min, we should insert the value of min in its place (j+1 since j is the smaller)
		nums[j+1] = min;
        }
}

int main()
{
        int nums[4];
        load(nums, 4);
        print(nums, 4);
        printf("Max number: %d\n", max(nums, 4));
	printf("Sorting...\n");
        sort(nums, 4);
        print(nums, 4);
        return 0;
}



/*
OUTPUT

Enter a number 1
Enter a number 10
Enter a number 5
Enter a number 20
The numbers are  1 10 5 20 
Max number: 20
Sorting...
The numbers are  1 5 10 20 

Press ENTER or type command to continue
*/
