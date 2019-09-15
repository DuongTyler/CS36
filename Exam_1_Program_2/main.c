/*
 * Exam 1 Program 2
 * Written by: Tyler Duong, Nikki Abedi
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
	printf("\n        Name        |  H1  |  H2  |  H3  |  T1  |  T2  |  HTOTAL  |  TTOTAL  | HAVG | TAVG |  PERCENTAGE  \n");
	for (int i = 0; i < n_student; i++)
	{
		printf("%20s|%6d|%6d|%6d|%6d|%6d|%10d|%10d|%6.2f|%6.2f|%14.2f\n", students[i].name,
				students[i].g_hmwk[0],	//hw 1
				students[i].g_hmwk[1],	//hw 2
				students[i].g_hmwk[2],	//hw 3
				students[i].g_test[0],	//test 1
				students[i].g_test[1],	//test 2
				students[i].i_htotal,	//HTOTAL
				students[i].i_ttotal,	//TTOTAL
				(float)students[i].i_htotal/3,	//calculate the avg homework
				(float)students[i].i_ttotal/2,	//calculate the avg test
				students[i].d_gtotal	//PERCENTAGE
				);
	}
	free(students);		//free the students!!!
	return 0;
}


/*
$ ./a.out 
Number of students are in the class: 5

Enter student 1's name: Trout, Albert
Enter homework score 1: 18
Enter homework score 2: 24
Enter homework score 3: 20
Enter test score 1: 76
Enter test score 2: 88

Enter student 2's name: Pujols, Mike 
Enter homework score 1: 25
Enter homework score 2: 25
Enter homework score 3: 20
Enter test score 1: 96
Enter test score 2: 99

Enter student 3's name: Ausmus, Mike
Enter homework score 1: 15
Enter homework score 2: 16
Enter homework score 3: 20
Enter test score 1: 58
Enter test score 2: 75

Enter student 4's name: Sciosia, Brad
Enter homework score 1: 15
Enter homework score 2: 14
Enter homework score 3: 18
Enter test score 1: 77
Enter test score 2: 83

Enter student 5's name: Student, Bad
Enter homework score 1: 2
Enter homework score 2: 2
Enter homework score 3: 2
Enter test score 1: 4
Enter test score 2: 4

        Name        |  H1  |  H2  |  H3  |  T1  |  T2  |  HTOTAL  |  TTOTAL  | HAVG | TAVG |  PERCENTAGE  
       Trout, Albert|    18|    24|    20|    76|    88|        62|       164| 20.67| 82.00|         82.27
        Pujols, Mike|    25|    25|    20|    96|    99|        70|       195| 23.33| 97.50|         95.84
        Ausmus, Mike|    15|    16|    20|    58|    75|        51|       133| 17.00| 66.50|         67.10
       Sciosia, Brad|    15|    14|    18|    77|    83|        47|       160| 15.67| 80.00|         73.07
        Student, Bad|     2|     2|     2|     4|     4|         6|         8|  2.00|  4.00|          5.60
*/
