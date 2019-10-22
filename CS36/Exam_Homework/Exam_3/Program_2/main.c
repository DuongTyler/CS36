/*
 * Exam 3 Program 2
 * Written by: Tyler Duong, Nikki Abedi, Jasmine Sourinthone
 * CS36 10/3/19
 * This program maintains information about a class of students and prints the letter grade
 *
 * INPUT:
        - Name
        - 3 Homework Grades     [0-25]          (40% of grade)
        - 2 Exam Scores         [0-100]         (60% of grade)
 */

#include <stdio.h>
#include <stdlib.h>

struct student
{
        char name[20];
        int g_hmwk[3];
        int g_test[2];
        int i_htotal;
        int i_ttotal;
        double d_gtotal;
};

float calcAvg(int numStudents, float sum)
{
  float avg;
  avg = sum / (float)numStudents;
  return avg;
}


char calcGrade(double grade)
{
        if ( grade >= 90 )              return 'A';
        else if ( grade >= 80 )         return 'B';
        else if ( grade >= 70 )         return 'C';
        else if ( grade >= 60 )         return 'D';
        else                            return 'F';
}

int getNumStudents()
{
				int ret;
        //get number of students
        printf("Number of students are in the class: ");
        scanf("%d", &ret);
				return ret;
}

void loadStudent( struct student *students, int i_student )
{        //loop through each student
        for (int i = 0; i < i_student; i++)
        {
                //get name
                printf("\nEnter student %d's name: ", (i+1));
                fgets(students[i].name, 20, stdin);
                //get rid of extra newline in string using my favorite: Regex!!!
                sscanf(students[i].name, "%[^\n]", students[i].name);

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

                students[i].d_gtotal =  ((students[i].i_htotal/1.875)
                                        +(students[i].i_ttotal/3.333));

        }
}

void printData(struct student *students, int i_student)
{
        //print the output of everything
        //%20s %6d %6d %6d %6d %10d %10d %14.2f
        int i_grades[5] = {0,0,0,0,0};
        printf("\n        Name        |  H1  |  H2  |  H3  |  T1  |  T2  |  HTOTAL  |  TTOTAL  |  PERCENTAGE  \n");
        float f_test1_total = 0;
        float f_test2_total = 0;
        for (int i = 0; i < i_student; i++)
        {
                char c_grade_tmp = calcGrade(students[i].d_gtotal);
                printf("%20s|%6d|%6d|%6d|%6d|%6d|%10d|%10d|%14.2f% (%c)\n", students[i].name,
                                students[i].g_hmwk[0],  //hw 1
                                students[i].g_hmwk[1],  //hw 2
                                students[i].g_hmwk[2],  //hw 3
                                students[i].g_test[0],  //test 1
                                students[i].g_test[1],  //test 2
                                students[i].i_htotal,   //HTOTAL
                                students[i].i_ttotal,   //TTOTAL
                                students[i].d_gtotal,   //PERCENTAGE
                                c_grade_tmp             //Letter Grade
                                );

                //add the total number of As, Bs, Cs, ect up
                if (c_grade_tmp == 'A')         i_grades[0]++;
                if (c_grade_tmp == 'B')         i_grades[1]++;
                if (c_grade_tmp == 'C')         i_grades[2]++;
                if (c_grade_tmp == 'D')         i_grades[3]++;
                if (c_grade_tmp == 'F')         i_grades[4]++;

                f_test1_total += students[i].g_test[0];
                f_test2_total += students[i].g_test[1];

        }

        float t1_avg = calcAvg(i_student, f_test1_total);
        float t2_avg = calcAvg(i_student, f_test2_total);

        printf("Test 1 Average: %.2f\n", t1_avg);
        printf("Test 2 Average: %0.2f\n", t2_avg);

        for (int i = (int)'A'; i < (int)'A'+5; i++)     //loop through each letter grade (1 int value apart except for F)
                if (i == 'A'+4)         printf("%c: %d\n", (char)(i+1), i_grades[i-'A']);       //if i is iterating on character E, (E is the 4th character away from A) we print F instead
                else                    printf("%c: %d\n", (char)(i), i_grades[i-'A']);         //otherwise print each character grade and the score in the array of scores

}

int main()
{
        int i_student;
        struct student *students;

	i_student = getNumStudents();
        while (getchar() != '\n');	//flush the input stream
        students = (struct student*) malloc(sizeof(struct student[i_student]));
	loadStudent( students, i_student );
	printData( students, i_student );

  	free(students);         //free the students!!!
        return 0;
}
