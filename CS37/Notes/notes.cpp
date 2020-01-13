#include <iostream>

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
		int foo(){}
		int foo(int a)							{	std::cout << a << std::endl;	}
		//templates
		template <typename T> T add(T a, T b)	{	return a+b;						}
	private:	//accessible only to the object itself (and also by friends)
		int t;
	protected:	//read only (also access from inherited)
};

class Cc :: C 
{
	public:
		Cc(int a)
		{
			
		}
}


int main()
{
	std::cout << add(1, 2) << std::endl;
	C c(1);
	
	try
	{
		if (0)	throw 2;
		int a = 2/0;

	}
	catch(Exception e)
	{
		
	}

	return 0;
}
