/*

 * Exam 2 Program 1

 * Written by: Tyler Duong, Nikki Abedi, Jasmine Sourinthone

 * CS36 9/5/19
 * This program maintains information about a class of students and prints the letter grade
 *
 * INPUT:

        - Name

        - 3 Homework Grades     [0-25]          (40% of grade)

        - 2 Exam Scores         [0-100]         (60% of grade)

 */





        //VARIABLE NAME POLICY: first character of the datatype followed by an underscore, then an identifier for what the values name is

        //EXCLUSION: You don't have to do this in iterators in for loops, or anywhere where it wouldn't make sense to

        //example: A string for a name should be declared in the following manner:

        //              char[20] s_name;        (String name)

        //              int i_age;              (Interger age)

        //              float f_gpa;            (Float GPA)

        //      This is so that we don't start accidentally casting, or not cast datatypes when performing calculations

        //TODO: RENAME variables to actually follow this policy, since I obviously didn't even follow my own policy when writing the code



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



                //you will need i_students, students[i].g_test[0] and students[i].g_test[1]



                //i_students  - the number of students in the class

                //students[i].g_test[0] - the grade of the first test

                //students[i].g_test[1] - the grade of the second test

                //

                //start

                f_test1_total += students[i].g_test[0];

                f_test2_total += students[i].g_test[1];

                //end

                



        }

        float t1_avg = calcAvg(i_student, f_test1_total);

        float t2_avg = calcAvg(i_student, f_test2_total);



        printf("Test Average %.2f\n", t1_avg);

        printf("Test Average %0.2f\n", t2_avg);



        for (int i = (int)'A'; i < (int)'A'+5; i++)     //loop through each letter grade (1 int value apart except for F)

                if (i == 'A'+4)         printf("%c: %d\n", (char)(i+1), i_grades[i-'A']);       //if i is iterating on character E, (E is the 4th character away from A) we print F instead

                else                    printf("%c: %d\n", (char)(i), i_grades[i-'A']);         //otherwise print each character grade and the score in the array of scores







        free(students);         //free the students!!!

        return 0;

}



//TODO: Redo the output of the code when all changes have been taken care of

/*

======OUTPUT======

$ ./a.out 

Number of students are in the class: 5



Enter student 1's name: Duong, Tyler

Enter homework score 1: 24

Enter homework score 2: 23

Enter homework score 3: 20

Enter test score 1: 99

Enter test score 2: 90



Enter student 2's name: Stallman, Richard

Enter homework score 1: 25

Enter homework score 2: 25

Enter homework score 3: 25

Enter test score 1: 100

Enter test score 2: 100



Enter student 3's name: Torvalds, Linus

Enter homework score 1: 20

Enter homework score 2: 22

Enter homework score 3: 19

Enter test score 1: 75

Enter test score 2: 82



Enter student 4's name: Rossman, Louis

Enter homework score 1: 25

Enter homework score 2: 23

Enter homework score 3: 20

Enter test score 1: 96

Enter test score 2: 97



Enter student 5's name: Schmoe, Joe

Enter homework score 1: 0

Enter homework score 2: 2

Enter homework score 3: 10

Enter test score 1: 40

Enter test score 2: 32



        Name        |  H1  |  H2  |  H3  |  T1  |  T2  |  HTOTAL  |  TTOTAL  |  PERCENTAGE  

        Duong, Tyler|    24|    23|    20|    99|    90|        67|       189|         92.44% (A)

   Stallman, Richard|    25|    25|    25|   100|   100|        75|       200|        100.01% (A)

     Torvalds, Linus|    20|    22|    19|    75|    82|        61|       157|         79.64% (C)

      Rossman, Louis|    25|    23|    20|    96|    97|        68|       193|         94.17% (A)

         Schmoe, Joe|     0|     2|    10|    40|    32|        12|        72|         28.00% (F)

A: 3

B: 0

C: 1

D: 0

F: 1

*/


