#include <stdio.h>

void load(int arr[][5], int size)
//must include the size in the second subscript
{
	int i, j;
	for (i=0; i<size; i++)
		for (j=0; j<5; j++)
			scanf("%d", &arr[i][j]);
}

void print(int arr[][5], int size)
{
	int i, j;
	for (i=0; i<size; i++)
		for (j=0; j<5; j++)
			printf("%d ",arr[i][j]);
	printf("\n");
}

int main()
{
	int arr2[5][5];
	load(arr2, 5);
	print(arr2, 5);
	
	return 0;

}
