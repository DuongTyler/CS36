#include <iostream>

class Student {

	public:
		Student(int hw[], int test[])
		{
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
		void printGrade()
		{
			std::cout << "Grade: " << f_prcnt << "(" << letter_grade << ")" << std::endl;
		}
	private:
		int i_hw_sc[3];
		int i_ts_sc[2];
		float f_prcnt = 0.0;
		int hw_total = 0, test_total = 0;
		char letter_grade;
};

void load(Student *s, int c)
{
	for ( int i = 0; i < c; i++ )
	{
		int v, tmp[3], tmp2[2];
		for (v = 0; v < 3; v++)
		{
			std::cout << "Enter Homework " << v+1 << " score: ";
			std::cin >> tmp[v];
		}
		for (v = 0; v < 5; v++)
		{
			std::cout << "Enter Test " << v+1 << " score: ";
			std::cin >> tmp2[v];
		}
	}
}

int main()
{	
	int c = 0;
	std::cout << "Enter the number of students: ";
	std::cin >> c;
	if ( c < 0 )	return -1;

	Student students[c];
	load (students, c);
	students[0].printGrade();
	return 0;
}
