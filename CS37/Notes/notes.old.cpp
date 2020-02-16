#include <iostream>
//#include <string>
#if 0 
	#include <stdio.h>
#endif

//class example
class C
{
	public:	//accessed anywhere
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
		void foo(int a)							{	std::cout << a << std::endl;	}
		int prnt(int a)							{	return a;						}
		//templates
		template <typename T> T add(T a, T b)	{	return a+b;						}
	private:	//accessible only to the object itself (and also by friends)
		int t;
	protected:	//read only (also access from inherited)
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
	std::cout << std::fixed << std::setprecision(2);	//to 2 decimal places
	std::cin.ignore(0,'\n');	//ignores up to 100 chars or up to the next newline
	std::cin >> s;
	std::cout << s << std::endl;

	if (s == "test")		std::cout << "testing what?" << std::endl;

	Cc c(1);
	std::cout << c.add(1, 2) << std::endl;
	std::cout << c.prnt(1) << std::endl;
	try
	{
		if (1)	throw 2;
		int a = 2/0;

	}
	catch(int e)
	{
		std::cout << e << std::endl;
	}
	return 0;
}

//cin.get()		get one char
//cout.put()	put one char

//why read strings one char at a time?
// -- Tokenizer (break up strings into tokens)


//format manipulators
//	#include iomanip
