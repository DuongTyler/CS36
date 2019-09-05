/*
 * Exam 1 Program 1
 * Written by: Tyler Duong
 * CS36 9/3/19
 * This program does the following
 * INPUT:
	- 2 ints
 * OUTPUT:
	- 2 ints
	- Sum
	- Difference
	- Product
	- Quotient
	- Cubes
	- Modulus
	- Average
 */


#include <stdio.h>
#include <math.h>

int main()
{
	int in1, in2;

	printf("Enter a number: ");
	scanf("%d", &in1);
	printf("Enter a second number: ");
	scanf("%d", &in2);
	
	printf("\n==========OUTPUT==========\n");
	printf("Number 1:\t\t%d\n", (in1));
	printf("Number 2:\t\t%d\n", (in2));
	printf("Sum:\t\t\t%d\n", (in1+in2));
	printf("Difference:\t\t%d\n", (in1-in2));
	printf("Product:\t\t%d\n", (in1*in2));
	printf("Quotient:\t\t%.2f\n", ((float)in1/in2));
	printf("Product:\t\t%d\n", (in1*in2));
	printf("Cube of first:\t\t%d\n", (int)pow(in1, 3));
	printf("Cube of second:\t\t%d\n", (int)pow(in2, 3));
	printf("Modulus:\t\t%d\n", (in1%in2));
	printf("Average:\t\t%.2f\n", ((float)(in1+in2)/2));
		
	return 0;
}

//	<1>.<2>
// [1] # of cols of too small
// [2] # of decimal places


/*+=+=+=+=+PROGRAM OUTPUT+=+=+=+=+*/
/*
	Enter a number: 1
	Enter a second number: 5
	==========OUTPUT==========
	Number 1:		1
	Number 2:		5
	Sum:			6
	Difference:		-4
	Product:		5
	Quotient:		0.20
	Product:		5
	Cube of first:		1
	Cube of second:		125
	Modulus:		1
	Average:		3.00
*/
