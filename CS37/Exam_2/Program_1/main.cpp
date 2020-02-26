#include <iostream>
#include <fstream>

//EXAM 2 PROGRAM
//MADE BY:
// DUONG, TYLER
// ORR, KIAN
// PARK, LEO
//function template to print an array
//works for multiple data types


template <typename T>
void saveTxt( const char* fname, const T *arr, const int len)
{
	int i;
	std::ofstream out (fname, std::ios::app);
	for (i=0; i<len; i++)
	{
		out << arr[i] << " ";
	}
	out << "\n";
	out.close();
}

template <typename T, typename T2, typename T3>
void loadTxt(const char* fname, T *arr, T2 *arr2, T3 *arr3, const int len, const int len2, const int len3)
{
	int i;
	std::ifstream infile(fname);
	for (i = 0; i < len; i++)
  {
    infile >> arr[i];
  }
	for (i = 0; i < len2; i++)
  {
    infile >> arr2[i];
	}
	for (i = 0; i < len3; i++)
  {
    infile >> arr3[i];
	}
	infile.close();
}


template <typename T>
void sort( T nums[], int len )
//Sort from high to low, insertion sort
{
   int i, j;
	 T max;
   //loop through each element, and compare the current element with the previous ones, then swap the value when i is gt j
   for ( i = 1; i < len; i++ )
   {
			max = nums[i]; //set current index to the min value, this is a placeholder temp value
			j = i-1;      //start j from the element behind i
			while ( j >= 0 && nums[j] < max)        //keep iterating j backwards while j >= 0 and element j is less then max
			{
						nums[j+1] = nums[j];      //keep shifting each value to the right until we find the correct value
						j = j-1;          //decriment j
			}
			//if element j is finally greater than max, we should insert the value of min in its place (j+1 since j is the larger)
			nums[j+1] = max;
   }
}

template <class T>
void printarray (const T *a, const int n)
{
        for (int i = 0; i < n; i++)
                std::cout << a[i] << "  ";
        std::cout << '\n';
} 

template <typename T> void loadArr(T *arr, const int len, const int type)
{
        int i;
        switch (type)
        {
                case 1: std::cout << "====Datatype Int====\n";  break;
                case 2: std::cout << "====Datatype Float====\n";        break;
                case 3: std::cout << "====Datatype Char====\n"; break;
                default: std::cout << "NO DATATYPE SPECIFIED!!!"; return;
        }
        std::cout << "Load Array of " << len << " elements\n";
        for (i=0; i<len; i++)
        {
                std::cout << "Enter element " << i << ": ";
                std::cin >> arr[i];
        }
}

//assumes len is >=1
template <typename T> void findTwoSmallest(T *arr, const int len)
{
        int i;
        T s1, s2;
        s1 = arr[0];
        s2 = arr[0];
        for (i=1; i<len; i++)
        {
                if ( arr[i] < s1 )
                {
                  s2 = s1;
                  s1 = arr[i];
                }
								else if ( arr[i] < s2)
								{
									s2 = arr[i];
								}
        }
        std::cout << "Smallest: " << s1 << "\nSecond Smallest: " << s2 << std::endl;
}

int main()
{
        const int n1 = 5, n2 = 7, n3 = 6;
        int a[n1];
        float b[n2];
        char c[n3];
        loadArr(a, n1, 1);
        loadArr(b, n2, 2);
        loadArr(c, n3, 3);
				
        std::cout <<"the integer array" << std::endl;
        printarray(a, n1);
        std::cout <<"the float array" << std::endl;
        printarray(b,n2);
        std::cout <<"the char is" << std::endl;
        printarray(c,n3);

        findTwoSmallest(a, n1);
        findTwoSmallest(b, n2);
        findTwoSmallest(c, n3);

				sort(a,n1);
				sort(b,n2);
				sort(c,n3);

        std::cout <<"the sorted integer array" << std::endl;
        printarray(a, n1);
        std::cout <<"the sorted float array" << std::endl;
        printarray(b,n2);
        std::cout <<"the sorted char is" << std::endl;
        printarray(c,n3);

				saveTxt("int.txt", a, n1);
        saveTxt("int.txt", b, n2);
        saveTxt("int.txt", c, n3);
				int a2[n1];
        float b2[n2];
        char c2[n3];
				loadTxt("int.txt", a2, b2, c2, n1, n2, n3);
        std::cout <<"the sorted int loaded from the file is" << std::endl;
        printarray(a, n1);
        std::cout <<"the sorted float loaded from the file is" << std::endl;
        printarray(b, n2);
        std::cout <<"the sorted char loaded from the file is" << std::endl;
        printarray(c, n3);
        return 0;
}

/*
 ./main
====Datatype Int====
Load Array of 5 elements
Enter element 0: 3
Enter element 1: 1
Enter element 2: 2
Enter element 3: 9
Enter element 4: 3
====Datatype Float====
Load Array of 7 elements
Enter element 0: 3.3
Enter element 1: 1.1
Enter element 2: 2.2
Enter element 3: 9.9
Enter element 4: 4.4
Enter element 5: 5.5
Enter element 6: 7.7
====Datatype Char====
Load Array of 6 elements
Enter element 0: a
Enter element 1: b
Enter element 2: c
Enter element 3: d
Enter element 4: e
Enter element 5: f
the integer array
3  1  2  9  3
the float array
3.3  1.1  2.2  9.9  4.4  5.5  7.7
the char is
a  b  c  d  e  f
Smallest: 1
Second Smallest: 2
Smallest: 1.1
Second Smallest: 2.2
Smallest: a
Second Smallest: a
the sorted integer array
9  3  3  2  1
the sorted float array
9.9  7.7  5.5  4.4  3.3  2.2  1.1
the sorted char is
f  e  d  c  b  a
the sorted int loaded from the file is
9  3  3  2  1
the sorted float loaded from the file is
9.9  7.7  5.5  5.4  3.3  2.2  1.1
the sorted char loaded from the file is
f  e  d  c  b  a
*/





/*
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
//      std::setbase(int)     //sets base to octal, hex, base2, base5, ect
//              std::oct      //prints in octal, use this or setbase
//      std::uppercase
//      std::nouppercase
//      std::showpoint  //shows decimal places even if int
//      std::cout.precision(int)        //set num of decimals to print
//      std::setprecision(int)  //set number of decimals to print
//              std::fixed    //set fixed width
        //      std::setw(int)  //set fixed width of chars
        //      std::left     //sets left justify
        //      std::right    //sets right justify

// Function Pointers
//      addr of func
//      menu handlers
//      only works if functions have same signatures


//cin.getline(void *var, int len)
//infile.getline(void *var, int len)
//cin.ignore(int max_char, '\n')

//Exam 2:
//      inline
//      scoperes
//      overload
//      maxtemp
//      arrtemp
//      defargs
//      funcptr1,2
//      file 1,2,3

//Exam 3:
//      class1 - class10
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
                template <typename T> T add(T a, T b)   {return a+b;}
                template <typename T, typename T2> T add2(T a, T2 b)    {return (T)(a+b);}
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

        std::ofstream of("data.txt", std::ios::out);    //std::ios::binary, std::ios::in, std::ios::app
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
        //      std::cout << name << endl;
        //infile.close();

        //while (!infile.eof()) //or use end of file
        //      infile.getline(name, 30)
        //      cout << name << endl;

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


                return 0;
}
*/
