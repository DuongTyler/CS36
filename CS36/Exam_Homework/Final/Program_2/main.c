/*
 * Final Program 2
 * Written by: Tyler Duong, Nikki Abedi, Jasmine Sourinthone
 * CS36 10/3/19
 * This program maintains information about a class of students and prints the letter grade
 *
 * INPUT:
        - Name
        - 3 Homework Grades     [0-25]          (40% of grade)
        - 2 Exam Scores         [0-100]         (60% of grade)

		TODO:
			- Alphabet Sort Names in list
			- Save Text File
			- Save Bin File
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct student
{
        char name[20];
        int g_hmwk[3];
        int g_test[2];
        int i_htotal;
        int i_ttotal;
        float f_gtotal;
};

void actuallySwap(void *source, void *target, int size)
{
  struct student tmp;
  memcpy(&tmp, source, size);
  memcpy(source, target, size);
  memcpy(target, &tmp, size);
}

void sortNames(struct student arr[], int n)
{
  int i,j;
  for ( i=0; i<n; i++ )
  {
    for (j=i+1; j<n; j++)
    {
      if ((strcmp(arr[i].name, arr[j].name)) > 0)	actuallySwap(&arr[i], &arr[j], sizeof(struct student));
    }
  }
}

void savetext(struct student s[], int size)
{
        int i;
        FILE *f = fopen("studs.txt", "w");
        for ( i=0; i<size; i++)
        {
                fprintf(f, "%s\n%d %d %d %d %d %d %d %f\n", s[i].name, s[i].g_hmwk[0], s[i].g_hmwk[1], s[i].g_hmwk[2],
                                s[i].g_test[0], s[i].g_test[1], s[i].i_htotal, s[i].i_ttotal, s[i].f_gtotal);
        }
        fclose(f);
}

void loadtext(struct student s[], int size)
{
        int i;
        FILE *f = fopen("studs.txt", "r");
        for ( i=0; i<size; i++)
        {
          fscanf(f, "%[^\n]%d%d%d%d%d%d%d%f", s[i].name, &s[i].g_hmwk[0], &s[i].g_hmwk[1], &s[i].g_hmwk[2],
                      &s[i].g_test[0], &s[i].g_test[1], &s[i].i_htotal, &s[i].i_ttotal, &s[i].f_gtotal);
	  fgetc(f);
        }
        fclose(f);
}

void savebin(struct student s[], int n)
{
 	FILE *f = fopen("studs.bin", "wb");
  	fwrite(s, sizeof(struct student), n, f);
  	fclose(f);
}

void loadbin(struct student s[], int n)
{
        FILE *f = fopen("studs.bin", "rb");
        fread(s, sizeof(struct student), n, f);
        fclose(f);
}


float calcAvg(int numStudents, float sum)
{
  float avg;
  avg = sum / (float)numStudents;
  return avg;
}


char calcGrade(double grade, int gradeCount[])
{
        if ( grade >= 90 )        { gradeCount[0]++; return 'A';}
        else if ( grade >= 80 )   { gradeCount[1]++; return 'B';}
        else if ( grade >= 70 )   { gradeCount[2]++; return 'C';}
        else if ( grade >= 60 )   { gradeCount[3]++; return 'D';}
        else                      { gradeCount[4]++; return 'F';}
}

int getNumStudents()
{
        int ret;
        //get number of students
        printf("Number of students are in the class: ");
        scanf("%d", &ret);
        while (getchar() != '\n');      //flush the input stream, intederministic, exit controlled
        return ret;
}

void loadStudent( struct student *students, int i_student ) //i_student = 5
{        //loop through each student
        for (int i = 0; i < i_student; i++)//deterministic, entrance-controlled
        // 
        {
                //get name
                printf("\nEnter student %d's name: ", (i+1));
                fgets(students[i].name, 20, stdin);
                //get rid of extra newline in string using my favorite: Regex!!!
                sscanf(students[i].name, "%[^\n]", students[i].name);

                //get homework values
                students[i].i_htotal = 0;
                for (int a = 0; a < 3; a++)     //deterministic, entrance-controlled
                                                                // assume students struct has been initialized
                {
                        printf("Enter homework score %d: ", (a+1));
                        scanf("%d", &students[i].g_hmwk[a]);
                        students[i].i_htotal += students[i].g_hmwk[a];
                        while (getchar() != '\n');//intederministic, exit controlled
                }

                //get test values
                students[i].i_ttotal = 0;
                for (int a = 0; a < 2; a++)//deterministic, entrance-controlled
                {
                        printf("Enter test score %d: ", (a+1));
                        scanf("%d", &students[i].g_test[a]);
                        students[i].i_ttotal += students[i].g_test[a];
                        while (getchar() != '\n');//intederministic, exit controlled
                }

                students[i].f_gtotal =  (float)((students[i].i_htotal/1.875)
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
        for (int i = 0; i < i_student; i++)//deterministic, entrance-controlled
        {
                char c_grade_tmp = calcGrade(students[i].f_gtotal, i_grades);
                printf("%20s|%6d|%6d|%6d|%6d|%6d|%10d|%10d|%14.2f% (%c)\n", students[i].name,
                                students[i].g_hmwk[0],  //hw 1
                                students[i].g_hmwk[1],  //hw 2
                                students[i].g_hmwk[2],  //hw 3
                                students[i].g_test[0],  //test 1
                                students[i].g_test[1],  //test 2
                                students[i].i_htotal,   //HTOTAL
                                students[i].i_ttotal,   //TTOTAL
                                students[i].f_gtotal,   //PERCENTAGE
                                c_grade_tmp             //Letter Grade
                                );
                f_test1_total += students[i].g_test[0];
                f_test2_total += students[i].g_test[1];

        }

        float t1_avg = calcAvg(i_student, f_test1_total);
        float t2_avg = calcAvg(i_student, f_test2_total);

        printf("Test 1 Average: %.2f\n", t1_avg);
        printf("Test 2 Average: %0.2f\n", t2_avg);

        for (int i = (int)'A'; i < (int)'A'+5; i++)     //loop through each letter grade (1 int value apart except for F) //deterministic, entrance-controlled
                if (i == 'A'+4)         printf("%c: %d\n", (char)(i+1), i_grades[i-'A']);       //if i is iterating on character E, (E is the 4th character away from A) we print F instead
                else                    printf("%c: %d\n", (char)(i), i_grades[i-'A']);         //otherwise print each character grade and the score in the array of scores

}

int getMode()
{
  char hi;
  printf("Would you like the data to be saved or loaded? (hint: s = saved and l = load)\n");
  scanf("%c", &hi );
  getchar();
  switch (hi)
  {
    case 'S': case 's': return 0;
    case 'L': case 'l': return 1;
    default: return -1;
  }

  return -1;
}

int main()
{
        int i_student, x;

        struct student *students;
 
        //i_student = getNumStudents();
        i_student = 5;
        students = (struct student*) malloc(sizeof(struct student[i_student]));       

	x = getMode();
	if (x == 1)
	{
		loadtext(students, i_student);
		printf("from text file:\n");
 	        printData( students, i_student );
		loadbin(students, i_student);
		printf("from binary file:\n");
        	printData( students, i_student );
	}
        else if (x == -1)
        {
          printf("Your dumb\n\n");
          return -1;
        }
	else
	{
		loadStudent( students, i_student );
          	sortNames(students, i_student);
		savetext(students, i_student);
		savebin(students, i_student);
	}


        free(students);         //free the students!!!
        return 0;
}




/* OUTPUT:
Would you like the data to be saved or loaded? (hint: s = saved and l = load)
l
from text file:

        Name        |  H1  |  H2  |  H3  |  T1  |  T2  |  HTOTAL  |  TTOTAL  |  PERCENTAGE
        Ausmus, Mike|    15|    16|    20|    58|    75|        51|       133|         67.10% (D)
        Pujols, Mike|    25|    25|    20|    96|    99|        70|       195|         95.84% (A)
       Sciosia, Brad|    15|    14|    18|    77|    83|        47|       160|         73.07% (C)
        Student, Bad|     2|     2|     2|     4|     4|         6|         8|          5.60% (F)
       Trout, Albert|    18|    24|    20|    76|    88|        62|       164|         82.27% (B)
Test 1 Average: 62.20
Test 2 Average: 69.80
A: 1
B: 1
C: 1
D: 1
F: 1
from binary file:

        Name        |  H1  |  H2  |  H3  |  T1  |  T2  |  HTOTAL  |  TTOTAL  |  PERCENTAGE
        Ausmus, Mike|    15|    16|    20|    58|    75|        51|       133|         67.10% (D)
        Pujols, Mike|    25|    25|    20|    96|    99|        70|       195|         95.84% (A)
       Sciosia, Brad|    15|    14|    18|    77|    83|        47|       160|         73.07% (C)
        Student, Bad|     2|     2|     2|     4|     4|         6|         8|          5.60% (F)
       Trout, Albert|    18|    24|    20|    76|    88|        62|       164|         82.27% (B)
Test 1 Average: 62.20
Test 2 Average: 69.80
A: 1
B: 1
C: 1
D: 1
F: 1

Press ENTER or type command to continue

*/
