/*
	CS37 Exam 1 Program 1
	Written by: Kian Orr, Tyler Duong, Leo Park
*/

//TODO: FOR THE LOVE OF GOD WE NEED TO MAKE MORE MEANINGFUL VARIABLE NAMES! I'M LOOKING AT YOU LEO!!!
//TODO: Figure out doxygen

#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

#define NAME_LEN 50
#define NUM_EMPLOYEE 4

class Employee
{
	public:
		Employee(){}
		Employee(string nm, double wrkd, double hourrate, double ftax, double stax)
		{
			name = nm;
			worked = wrkd;
			hourlyrate = hourrate;
			fedtax = ftax;
			statetax = stax;
			calcGrossPay(worked, hourlyrate);
			calcSTaxOwed(gp, statetax);
			calcFTaxOwed(gp, fedtax);
			calcOverTime(worked, hourlyrate);
			calcNetPay(gp, fedtax, statetax);
		}

		//calc
		/** calcGrossPay() - calculate the gross pay for an employee */
		void calcGrossPay(double wrkd, double hourrate)
		{
		  gp = (double)wrkd * hourrate;
		}
		void calcSTaxOwed(double gp, double stax)
		{
		  staxowed = (double)gp * stax / 100;
		}
		void calcFTaxOwed(double gp, double fedtax)
		{
		  ftaxowed = (double)gp * fedtax / 100;
		}
		void calcOverTime(double wrkd, double hourlyrate)
		{
		  if (wrkd - 40 > 0)
		  {
				othours = wrkd - 40;
				otpay = hourlyrate * othours * 1.5;
				gp = otpay + gp;
				overtime = 1;
		  }
			else
			{
				otpay = 0;
				othours = 0;
			}
		}
		void calcNetPay(double gp, double ftaxowed, double staxowed)
		{
		  netpay = gp - ftaxowed - staxowed;
		}

		//get
		string getName()				{return name;}
		double getWorked()			{return worked;}
		double getHourlyRate()	{return hourlyrate;}
		double getFtaxR()				{return fedtax;}
		double getStaxR()				{return statetax;}
		double getGP()					{return gp;}
		double getFtaxO() 	    {return ftaxowed;}
		double getStaxO()     	{return staxowed;}
		double getnp()         	{return netpay;}
		double getOTP()        	{return otpay;}
		double getOTH()        	{return othours;}
		bool getDoneOvertime()	{return overtime;}
	private:
		string name;
		bool overtime = 0;
		double worked, //hours worked
			hourlyrate, //hourly rate
			fedtax, //federal tax rate
			statetax, //state tax rate
			gp, //gross pay
			ftaxowed, //federal tax owed
			staxowed, //state tax owed
			netpay, //net pay
			otpay, //overtime pay
			othours; /** over time hours */
};

void load(Employee e[], int len)
{
	int i;
	for (i=0; i<len; i++)
	{
		string name;
		double worked, hourlyrate, fedtax, statetax;
		cout << "Enter a name for employee " << i+1 << ": ";
		getline(cin, name);
		//cin.getline(name, 50 /*length of name*/)
		cout << "Enter hours worked: ";
		cin >> worked;
		cout << "Hourly rate: ";
		cin >> hourlyrate;
		cout << "Enter federal tax rate please: ";
		cin >> fedtax;
		cout<<"Enter state tax rate por favor: ";
		cin >> statetax;
		cin.ignore();
		e[i] = Employee(name, worked, hourlyrate, fedtax, statetax);
	}
}

/**! \fn void printAll(Employee e[], int len)
	\brief printAll() - Prints all data for each employee in the array */
void printAll(Employee e[], int len)
{
	int i, overtime;
	double overtimePaid;
	overtime = 0;
	overtimePaid = 0;
	for (i=0; i<len; i++)
	{
		cout << fixed << setprecision(2);
		cout << "Name: " << e[i].getName() << endl;
		cout << "Hours Worked: " << e[i].getWorked() << endl;
		cout << "Hourly Rate: $" << e[i].getHourlyRate() << endl;
		cout << "Federal Tax Rate: " << e[i].getFtaxR() << "%" << endl;
		cout << "State Tax Rate: " << e[i].getStaxR() << "%" << endl;
		cout << "Gross Pay: $" << e[i].getGP() << endl;
		cout << "Federal tax owed: $" << e[i].getFtaxO() << endl;
		cout << "State tax owed: $" << e[i].getStaxO() << endl;
		cout << "net pay: $" << e[i].getnp() << endl;
		cout << "Overtime pay: $" << e[i].getOTP() << endl;
		cout << "Overtime Hours: " << e[i].getOTH() << endl;
		cout << "==============================================" << endl;
		if (e[i].getDoneOvertime())	overtime++;
		overtimePaid += e[i].getOTP();
	}
	cout << overtime << " employees have done overtime work" << endl;
	cout << "Paid out $" << overtimePaid << " for overtime work\n";
}

int main()
{
	Employee e[NUM_EMPLOYEE];
	load(e, NUM_EMPLOYEE);
	printAll(e, NUM_EMPLOYEE);
	return 0;
}
/*
OUTPUT:
Enter a name for employee 1: Chamberlain, Kobe
Enter hours worked: 44.4
Hourly rate: 33.33
Enter federal tax rate please: 22.2
Enter state tax rate por favor: 8.5
Enter a name for employee 2: Bryant, Wilt
Enter hours worked: 33.33
Hourly rate: 44.44
Enter federal tax rate please: 23.3
Enter state tax rate por favor: 8.5
Enter a name for employee 3: Worthy, Jerry
Enter hours worked: 26.25
Hourly rate: 55.55
Enter federal tax rate please: 19.9
Enter state tax rate por favor: 7.77
Enter a name for employee 4: West, James
Enter hours worked: 55.5
Hourly rate: 45.67
Enter federal tax rate please: 24.4
Enter state tax rate por favor: 9.25
Name: Chamberlain, Kobe
Hours Worked: 44.40
Hourly Rate: $33.33
Federal Tax Rate: 22.20%
State Tax Rate: 8.50%
Gross Pay: $1699.83
Federal tax owed: $328.53
State tax owed: $125.79
net pay: $1669.13
Overtime pay: $219.98
Overtime Hours: 4.40
==============================================
Name: Bryant, Wilt
Hours Worked: 33.33
Hourly Rate: $44.44
Federal Tax Rate: 23.30%
State Tax Rate: 8.50%
Gross Pay: $1481.19
Federal tax owed: $345.12
State tax owed: $125.90
net pay: $1449.39
Overtime pay: $0.00
Overtime Hours: 0.00
==============================================
Name: Worthy, Jerry
Hours Worked: 26.25
Hourly Rate: $55.55
Federal Tax Rate: 19.90%
State Tax Rate: 7.77%
Gross Pay: $1458.19
Federal tax owed: $290.18
State tax owed: $113.30
net pay: $1430.52
Overtime pay: $0.00
Overtime Hours: 0.00
==============================================
Name: West, James
Hours Worked: 55.50
Hourly Rate: $45.67
Federal Tax Rate: 24.40%
State Tax Rate: 9.25%
Gross Pay: $3596.51
Federal tax owed: $618.46
State tax owed: $234.46
net pay: $3562.86
Overtime pay: $1061.83
Overtime Hours: 15.50
==============================================
2 employees have done overtime work
Paid out $1281.81 for overtime work
[Inferior 1 (process 654550) exited normally]
(gdb) 
*/






/*

//NOTES.CPP
#include <iostream>
//#include <string>
#if 0 
        #include <stdio.h>
#endif

//class example
class C
{
       public: //accessed anywhere
                C(int a)
                {
                        std::cout << "Hello world!" << std::endl;
                        t = a;
                }
                ~C()
                {
                        std::cout << "Goodbye World" << std::endl;
                }
                //overloading example (example of polymorphism)
                void foo(){}
                void foo(int a)                                                 {       std::cout << a << std::endl;    }
                int prnt(int a)                                                 {       return a;                                      }
                //templates
                template <typename T> T add(T a, T b)   {       return a+b;                                             }
        private:        //accessible only to the object itself (and also by friends)
                int t;
        protected:      //read only (also access from inherited)
};

class Cc : public C
{
        public:
                Cc(int a) : C(a)
                {
                        z = a;
                }
        private:
                int z;
        protected:
};

// Stream insertion operator (<<)
// Stream extraction operator (>>)

//block = contour



int main(int argc, char **argv)
{
        std::string s;
        //std::cin >> s;
        std::getline(std::cin, s);
        std::cout << s << std::endl;
        std::cout << std::fixed << std::setprecision(2);        //to 2 decimal places
        std::cin.ignore(0,'\n');        //ignores up to 100 chars or up to the next newline
        std::cin >> s;
        std::cout << s << std::endl;

        if (s == "test")                std::cout << "testing what?" << std::endl;

        Cc c(1);
        std::cout << c.add(1, 2) << std::endl;
        std::cout << c.prnt(1) << std::endl;
        try
        {
                if (1)  throw 2;
                int a = 2/0;

        }
        catch(int e)
        {
                std::cout << e << std::endl;
        }
        return 0;
}

//cin.get()             get one char
//cout.put()    put one char

//why read strings one char at a time?
// -- Tokenizer (break up strings into tokens)


//format manipulators
//      #include iomanip
 

//NOTES2.CPP

#include <iostream>
//inline function (or macro)
  //reduce memory stuff, also allows for the compiler to optimize the code for the pipeline more efficiently (time+mem)

// :: operator is the scope resolution operator
  //allow access outside the current scope
  //local variables get prio over globals
  //also used to access data members and methods outside current object

//signature is related to overloading, the order and types of parameters and return type

//C++ contains STL
	//header files with templates of reusable code
	//vector stuff


float bad = 2.345;

class Teacher
{
  public:
    Teacher(int x=0, int y=0, int z=0)
    {
      a = x;
      b = y;
      c = z;
    }
    void printData()
    {
      std::cout << a << b << c << std::endl;
    }
  private:
    int a, b, c;
};

class Student : public Teacher
{
  public:
    Student(int x, int y, int z) : Teacher()
    {
      a = x;
      b = y;
      c = z;
    }
    void printData()
    {
      std::cout << a << b << c << std::endl;
      Teacher::printData();
    }
		template <typename T> T add(T a, T b) {return a+b;}
    template <typename T, typename T2> T add2(T a, T2 b)  {return (T)(a+b);}
  private:
    int a, b, c;
};

inline double cube(double a)
{
  a = 4;
  return a;
}

#define cube2(a) \
  a = 2; \
  std::cout << a << std::endl; \

int main()
{
  Student s(1,2,3);
  s.printData();

  int a;
  //std::cin >> a >> b;
  std::cout << cube(2.22) << std::endl;
  cube2(a)
  std::cout << a << std::endl;

  char str[20];
  std::cin.getline(str, 20);

  float bad = 6.99;
  std::cout << ::bad << std::endl;
  std::cout << bad << std::endl;

  return 0;
}

*/
