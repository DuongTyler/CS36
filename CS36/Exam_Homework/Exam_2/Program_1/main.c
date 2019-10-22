/*
 * Exam 2 Program 1
 * Written by: Tyler Duong, Nikki Abedi, Jasmine Sourinthone
 * CS36 10/3/19
 * This program maintains information about a class of students and prints the letter grade
 *
 * INPUT:
        - Name
        - 3 Homework Grades     [0-25]          (40% of grade)
        - 2 Exam Scores         [0-100]         (60% of grade)
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

#include <stdio.h>
#include <stdlib.h>

int main()
{
        int i_student;
        struct student *students;
        int i_grades[5];
        for (int i = 0; i < 5; i++)
                i_grades[i] = 0;

        //get number of students
        printf("Number of students are in the class: ");
        scanf("%d", &i_student);

        //allocate the space for however many students we have in an array, each with 20 char names
        students = (struct student*) malloc(sizeof(struct student[i_student]));

        //flush the input stream
        while (getchar() != '\n');

        //loop through each student
        for (int i = 0; i < i_student; i++)
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

                students[i].d_gtotal =  ((students[i].i_htotal/1.875)
                                        +(students[i].i_ttotal/3.333));

        }

        //print the output of everything
        //%20s %6d %6d %6d %6d %10d %10d %14.2f
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

        free(students);         //free the students!!!
        return 0;
}


/*
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

        Name        |  H1  |  H2  |  H3  |  T1  |  T2  |  HTOTAL  |  TTOTAL  |  PERCENTAGE
       Trout, Albert|    18|    24|    20|    76|    88|        62|       164|         82.27% (B)
        Pujols, Mike|    25|    25|    20|    96|    99|        70|       195|         95.84% (A)
        Ausmus, Mike|    15|    16|    20|    58|    75|        51|       133|         67.10% (D)
       Sciosia, Brad|    15|    14|    18|    77|    83|        47|       160|         73.07% (C)
        Student, Bad|     2|     2|     2|     4|     4|         6|         8|          5.60% (F)
Test 1 Average: 62.20
Test 2 Average: 69.80
A: 1
B: 1
C: 1
D: 1
F: 1
*/


