#include <stdio.h>

void swap( int *a, int *b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(int arr[], int n)
{
	int i, j;
	for (i=0; i < n-1; i++)
		for (j=0; j<n-1; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);

}

int main()
{
	int i;
	int arr[] = {8,6,3,4,2};
	
	for (i=0; i < 5; i++)	printf("%d ", arr[i]);
	printf("\n");

	sort(arr, 5);

	for (i=0; i < 5; i++)	printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
