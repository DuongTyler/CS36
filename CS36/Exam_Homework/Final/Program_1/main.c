/*
        Final Program 1
        Written by: Tyler Duong, Jasmine Sourthone, Nikki Abedi

        The purpose of this program is to allow a user to search an array of strings for a name
 */
#include <stdio.h>
#include <string.h>

#define NUM_NAMES 7
#define STR_LEN 50

void load(char arr[][STR_LEN])
{
        int i;
        printf("Load the student names:\n");
        for ( i=0; i<NUM_NAMES; i++ )
        {
                printf("%d) ",i+1);
                fgets(arr[i], STR_LEN, stdin);
                sscanf(arr[i], "%[^\n]", arr[i]);
        }
}

void print(char arr[][STR_LEN])
{
        int i;
        for ( i=0; i<NUM_NAMES; i++ )
                printf("%d) %s\n", i+1, arr[i]);
}

void swap(void **p1, void **p2)
{
        void *tmp;
        tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
}

void actuallySwap(char *source, char *target, int size)
{
	char tmp[size];
	strncpy(tmp, source, size);
	strncpy(source, target, size);
	strncpy(target, tmp, size);
}

void sortNames(char arr[][STR_LEN])
{
        int i,j;
        for ( i=0; i<NUM_NAMES; i++ )
        {
		for (j=i+1; j<NUM_NAMES; j++)
		{
			if ((strcmp(arr[i], arr[j])) > 0)
			actuallySwap(arr[i], arr[j], STR_LEN);
		}
        }
}

int binsearch(char arr[][STR_LEN], int l, int r, char *target)	//why use binary search? it is faster and easy to implement
{
	int mid;
	if (r >= 1)
	{
		mid = l+(r-l)/2;
		if (strcmp(arr[mid], target) == 0)	return mid;	//if we found the string, return the index //Why? if the strings are equal, we should return right away
		if (strcmp(arr[mid], target) > 0)	return binsearch(arr, l, mid-1, target); //if the target comes alphabetically before  mid, cut in half and keep the left side 
		return binsearch(arr, mid+1, r, target);	//otherwise cut in half and keep right side
	}
	return -1;	//string not found
}

/* Example of recursion
long long fastfib(int n, long long *mem)
{
        long long res;
        if (n == 1 || n == 0) return n;
        if (mem[n] > 0) return mem[n];
        res = fastfib(n-1, mem) + fastfib(n-2, mem);
        mem[n] = res;
        return res;
}

int main()
{
        int x, i;
        printf("Fib to: ");
        scanf("%d", &x);
        long long mem[x+1];
        for (i=0; i<x+1; i++)   mem[i] = -1;
        printf("Fib of %d is %lld\n", x, fastfib(x, mem));
        return 0;
}
*/

int main()
{
	int s;
        char names[NUM_NAMES][STR_LEN];
	char target[STR_LEN];
        load(names);
        printf("\nUNSORTED:\n");
        print(names);
	sortNames(names);
        printf("\nSORTED:\n");
        print(names);
	printf("Search for a name: ");
	fgets(target, STR_LEN, stdin);
	sscanf(target, "%[^\n]", target);	//get rid of newline
	s = binsearch(names, 0, (sizeof(names)/sizeof(names[0]))-1, target) + 1;
	if ( s >=0 )	printf("Found name at index %d\n", s);
	else		printf("Not found\n");

        return 0;

}


/* OUTPUT:
   Load the student names:
1) Tyler Duong
2) Jasmine Sourthone
3) Nikki Abedi
4) Joe Schmoe
5) Bad Student
6) int main
7) GNU's Not Unix

UNSORTED:
1) Tyler Duong
2) Jasmine Sourthone
3) Nikki Abedi
4) Joe Schmoe
5) Bad Student
6) int main
7) GNU's Not Unix

SORTED:
1) Bad Student
2) GNU's Not Unix
3) Jasmine Sourthone
4) Joe Schmoe
5) Nikki Abedi
6) Tyler Duong
7) int main             <-- NOTE: 'int main' was sorted out of order due to case sensitivity issues with my sorting algorithm. (since ascii lower case is represented by a larger number than captial characters
Search for a name: int main
Found name at index 7

Press ENTER or type command to continue
*/
