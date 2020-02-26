#include <iostream>
#include <fstream>
//inline function (or macro)
	//reduce memory stuff, also allows for the compiler to optimize the code for the pipeline more efficiently (time+mem)

// :: operator is the scope resolution operator
	//allow access outside the current scope
	//local variables get prio over globals
	//also used to access data members and methods outside current object
//signature is related to overloading, the order and types of parameters and return type

//cin.get()             get one char
//cout.put()    put one char

//why read strings one char at a time?
// -- Tokenizer (break up strings into tokens)

// << stream insertion operator
// >> stream extraction operator

//format manipulators
//  #include iomanip
//	std::setbase(int)	//sets base to octal, hex, base2, base5, ect
//		std::oct	//prints in octal, use this or setbase
//	std::uppercase
//	std::nouppercase
//	std::showpoint	//shows decimal places even if int
//	std::cout.precision(int)	//set num of decimals to print
//	std::setprecision(int)	//set number of decimals to print
//		std::fixed	//set fixed width
	//	std::setw(int)	//set fixed width of chars
	//	std::left	//sets left justify
	//	std::right	//sets right justify

// Function Pointers
//	addr of func
//	menu handlers
//	only works if functions have same signatures


//cin.getline(void *var, int len)
//infile.getline(void *var, int len)
//cin.ignore(int max_char, '\n')

//Exam 2:
//	inline
//	scoperes
//	overload
//	maxtemp
//	arrtemp
//	defargs
//	funcptr1,2
//	file 1,2,3

//Exam 3:
//	class1 - class10
//	
//


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
		template <typename T> T add(T a, T b)	{return a+b;}
		template <typename T, typename T2> T add2(T a, T2 b)	{return (T)(a+b);}
	private:
		int a, b, c;
};

inline double cube(double a)
{
	a=a*a*a;
	return a;
}

#define cube2(a) \
	a = 2; \
	std::cout << a << std::endl; \

int main()
{
	Student s(1,2,3);
	s.printData();
	std::cout << s.add2(2.222,2) << std::endl;

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

	std::string str2;
  //std::cin >> s;
  std::getline(std::cin, str2);
  std::cout << str2 << std::endl;
  std::cout << std::showpoint << std::fixed << std::cout.precision(2);        //to 2 decimal places
  std::cin.ignore(0,'\n');        //ignores up to 100 chars or up to the next newline
  std::cin >> str2;
  std::cout << str2 << std::endl;

  if (str2 == "test")  std::cout << "testing what?" << std::endl;
  //if (s == "test")  std::cout << "testing what?" << std::endl;
	try
  {
    if (1)  throw 2;
    int a = 2/0;

  }
  catch(int e)
  {
    std::cout << e << std::endl;
  }

	std::ofstream of("data.txt", std::ios::out);	//std::ios::binary, std::ios::in, std::ios::app
  int n;
  while (std::cin >> n && n != -1)
  {
    of << n << std::endl;
  }
  of.close();

	std::ifstream in("data.txt", std::ios::in);
  while (in >> n)
  {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  in.close();

	//std::ifstream infile("data.txt", std::ios::in);
	//while (infile.getline(name, 30))
	//	std::cout << name << endl;
	//infile.close();

	//while (!infile.eof())	//or use end of file
	//	infile.getline(name, 30)
	//	cout << name << endl;
	/*

		int main()
		{
			std::ifstream in("infile.txt");
			char name[20];
			while (in.getline(name, 20))
			{
				int a, b, c;
				in >> a >> b >> c;
				in.ignore();
				std::cout << name << "\n" << a << "\n"<< b << "\n"<< c << std::endl;
			}
			in.close();
		}


		 */
		return 0;
}
