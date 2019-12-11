#include <iostream>
#include <cstring>
#include <iomanip>

class Student {

	public:
		Student()
		{}
		Student(char *nm, int hw[], int test[])
		{
			strcpy(name, nm);
			for ( int i = 0; i < 3 && hw[i]; i++ )		i_hw_sc[i] = hw[i];
			for ( int i = 0; i < 2 && test[i]; i++ )	i_ts_sc[i] = test[i];
			updateGrade();
		}
		void updateGrade()
		{
			hw_total = 0 , test_total = 0;
			for ( int i = 0; i < 3; i++ )	hw_total += i_hw_sc[i];
			for ( int i = 0; i < 2; i++ )	test_total += i_ts_sc[i];
			f_prcnt = (float)(hw_total/1.875)+(test_total/3.333);

			if ( f_prcnt < 0 )			letter_grade = '?';
			else if ( f_prcnt > 101 )		letter_grade = 'S';
			else if ( f_prcnt >= 90 )		letter_grade = 'A';
			else if ( f_prcnt >= 80 )		letter_grade = 'B';
			else if ( f_prcnt >= 70 )		letter_grade = 'C';
			else if ( f_prcnt >= 60 )		letter_grade = 'D';
			else 					letter_grade = 'F';
		}
		void load()
		{
			int v;
			std::cout << "Enter a Name: " << std::endl;
			std::cin >> name;
			for (v = 0; v < 3; v++)
			{
				std::cout << "Enter Homework " << v+1 << " score: ";
				std::cin >> i_hw_sc[v];
			}
			for (v = 0; v < 2; v++)
			{
				std::cout << "Enter Test " << v+1 << " score: ";
				std::cin >> i_ts_sc[v];
			}
			updateGrade();
		}
		void printGrade()
		{
			std::cout << std::endl;
			std::cout << "Name: " << name << std::endl;
			std::cout << "Grade: " << std::setprecision(4) << f_prcnt << "(" << letter_grade << ")" << std::endl;
			std::cout << "HW 1: " << i_hw_sc[0] << std::endl;
			std::cout << "HW 2: " << i_hw_sc[1] << std::endl;
			std::cout << "HW 3: " << i_hw_sc[2] << std::endl;
			std::cout << "Test 1: " << i_ts_sc[0] << std::endl;
			std::cout << "Test 2: " << i_ts_sc[1] << std::endl;
		}
		float getScores(int sc)
		{
			switch(sc)
			{
				case 0:	case 1:	case 2:		return i_hw_sc[sc];
				case 3:	case 4:			return i_ts_sc[sc-3];
				default:			return -1;
			}

		}
	private:
		char name[20];
		int i_hw_sc[3];
		int i_ts_sc[2];
		float f_prcnt = 0.0;
		int hw_total = 0, test_total = 0;
		char letter_grade;
};

void loadAll(Student *s, int c)
{
	for ( int i = 0; i < c; i++ )	s[i].load();
}
void printAll(Student *s, int **grades, int c)
{
	int i, j;
	for ( i = 0; i < c; i++)	s[i].printGrade();
	for ( i = 0; i < 2; i++)
		for ( j = (int)'A'; j < (int)'A'+5; j++ )
		{
			std::cout << (char)i << ": " << grades[i][j] << std::endl;
		}
}
void getGradeCount(Student *s, int *grds, int t, int c)
{
	int i;
	i = 0;
	for (i = 0; i < c; i++)
	{
		int score = s[i].getScores(t+3);
		if ( score >= 90 ) 	grds[0] ++;
		else if ( score >= 80 ) grds[1] ++;
		else if ( score >= 70 ) grds[2] ++;
		else if ( score >= 60 ) grds[3] ++;
		else 		 	grds[4] ++;
	}
}

int main()
{	
	int c = 0;
	int grds[2][5];
	std::cout << "Enter the number of students: ";
	std::cin >> c;
	if ( c < 0 )	return -1;

	Student students[c];
	loadAll (students, c);
	getGradeCount(students, grds[0], 0, c);
	getGradeCount(students, grds[1], 1, c);
	printAll(students, grds, c);
	return 0;
}
