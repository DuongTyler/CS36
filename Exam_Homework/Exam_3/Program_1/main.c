#include <stdio.h>

void load( int nums[], int len )
//allow the user to load 4 int values
{
	int i;
	for ( i = 0; i < len; i++ )
	{
		printf("Number %d: ", i);
		scanf("%d", &nums[i]);
	}
}

void print( int nums[], int len )
{
	int i;
	for ( i = 0; i < len; i++ )
		printf("%d ", nums[i]);
	printf("\n");
}

int max( int nums[], int len )
{
	int i;
	int max=0;
	for ( i = 1; i < len; i++ )
		if (nums[i] > nums[max])	max = i;
	return nums[max];
}

void sort( int nums[], int len )
//Sort from low to high
{
	int i, j, min;
	for ( i = 0; i < len-1; i++ )
	{
		
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
