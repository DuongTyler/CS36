/*
   Final Program 3
   Written by: Tyler Duong, Nikki Abedi, Jasmine Sourthone

   The purpose of this program is to find the sum of the first n cubes a user enters
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ncubes(int n)
{
	if (n == 1) return 1;
	return (int)(pow(n,3) + ncubes(n-1));
}

int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	if (n > 0) printf("The sum of n cubed is: %d\n", ncubes(n));
	else	printf("The sum of n cubed is: %d\n", 0-ncubes(abs(n)));
	return 0;
}

/* OUTPUT:
[01:57 PM]「fishsauce」~/Documents/School/CS Programming/CS36/Exam_Homework/Final/Program_3
$ ./a.out
Enter n: -5
The sum of n cubed is: -225
[01:57 PM]「fishsauce」~/Documents/School/CS Programming/CS36/Exam_Homework/Final/Program_3
$ ./a.out
Enter n: -3
The sum of n cubed is: -36
[01:57 PM]「fishsauce」~/Documents/School/CS Programming/CS36/Exam_Homework/Final/Program_3
$ ./a.out
Enter n: -2
The sum of n cubed is: -9
[01:57 PM]「fishsauce」~/Documents/School/CS Programming/CS36/Exam_Homework/Final/Program_3
$ ./a.out
Enter n: 2
The sum of n cubed is: 9
[01:57 PM]「fishsauce」~/Documents/School/CS Programming/CS36/Exam_Homework/Final/Program_3
$ ./a.out
Enter n: 4
The sum of n cubed is: 100
   */
