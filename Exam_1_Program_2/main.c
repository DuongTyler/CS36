/*
 * Exam 1 Program 2
 * Written by: Tyler Duong
 * CS36 9/3/19
 * This program maintains information about a class of students
 *
 * INPUT:
	- Name
	- 3 Homework Grades	[0-25]		(40% of grade)
	- 2 Exam Scores		[0-100]		(60% of grade)
 */

struct student
{
	char name[20];
	int g_hmwk[3];
	int g_test[2];
	int i_htotal;
	int i_ttotal;
	double d_gtotal;
	
};

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n_student;
	struct student *students;
	
	//get number of students
	printf("Number of students are in the class: ");
	scanf("%d", &n_student);
	
	//allocate the space for however many students we have in an array, each with 20 char names
	students = (struct student*) malloc(sizeof(struct student[n_student]));
	
	//flush the input stream
	while (getchar() != '\n');
	//loop through each student
	for (int i = 0; i < n_student; i++)
	{
		//get name
		printf("\nEnter student %d's name: ", (i+1));
		fgets(students[i].name, 20, stdin);
		//get rid of extra newline in string using my favorite: Regex!!!
		sscanf(students[i].name, "%[^\n]", &students[i].name);

		//get homework values
		students[i].i_htotal = 0;
		for (int a = 0; a < 3; a++)
		{
			printf("Enter homework score %d: ", (a+1));
			scanf("%d", &students[i].g_hmwk[a]);
			students[i].i_htotal += students[i].g_hmwk[a];
			while (getchar() != '\n');
		}

		//get test values
		students[i].i_ttotal = 0;
		for (int a = 0; a < 2; a++)
		{
			printf("Enter test score %d: ", (a+1));
			scanf("%d", &students[i].g_test[a]);
			students[i].i_ttotal += students[i].g_test[a];
			while (getchar() != '\n');
		}
		
		students[i].d_gtotal = 	((students[i].i_htotal/1.875)
					+(students[i].i_ttotal/3.333));
		
	}
	
	//print the output of everything
	//%20s %6d %6d %6d %6d %10d %10d %14.2f
	printf("\n        Name        |  H1  |  H2  |  H3  |  T1  |  T2  |  HTOTAL  |  TTOTAL  |  PERCENTAGE  \n");
	for (int i = 0; i < n_student; i++)
	{
		printf("%20s|%6d|%6d|%6d|%6d|%6d|%10d|%10d|%14.2f\n", students[i].name,
				students[i].g_hmwk[0],	//hw 1
				students[i].g_hmwk[1],	//hw 2
				students[i].g_hmwk[2],	//hw 3
				students[i].g_test[0],	//test 1
				students[i].g_test[1],	//test 2
				students[i].i_htotal,	//HTOTAL
				students[i].i_ttotal,	//TTOTAL
				students[i].d_gtotal	//PERCENTAGE
				);
	}
	free(students);		//free the students!!!
	return 0;
}


/*
======OUTPUT======

$ ./a.out 
Number of students are in the class: 5

Enter student 1's name: Duong, Tyler   
Enter homework score 1: 24
Enter homework score 2: 22
Enter homework score 3: 19
Enter test score 1: 98
Enter test score 2: 96

Enter student 2's name: Schmoe, Joe  
Enter homework score 1: 20
Enter homework score 2: 19
Enter homework score 3: 19
Enter test score 1: 0
Enter test score 2: 50

Enter student 3's name: Torvalds, Linus 
Enter homework score 1: 25
Enter homework score 2: 25
Enter homework score 3: 24
Enter test score 1: 100
Enter test score 2: 99

Enter student 4's name: Stallman, Richard
Enter homework score 1: 20
Enter homework score 2: 25
Enter homework score 3: 24
Enter test score 1: 100
Enter test score 2: 100

Enter student 5's name: Jobs, Steve
Enter homework score 1: 10
Enter homework score 2: 5
Enter homework score 3: 4
Enter test score 1: 45
Enter test score 2: 70

        Name        |  H1  |  H2  |  H3  |  T1  |  T2  |  HTOTAL  |  TTOTAL  |  PERCENTAGE  
        Duong, Tyler|    24|    22|    19|    98|    96|        65|       194|         92.87
         Schmoe, Joe|    20|    19|    19|     0|    50|        58|        50|         45.93
     Torvalds, Linus|    25|    25|    24|   100|    99|        74|       199|         99.17
   Stallman, Richard|    20|    25|    24|   100|   100|        69|       200|         96.81
         Jobs, Steve|    10|     5|     4|    45|    70|        19|       115|         44.64
*/
