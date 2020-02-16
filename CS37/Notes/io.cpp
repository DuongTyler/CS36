#include <iostream>
#include <fstream>

int main()
{
	std::ofstream of("data.txt", std::ios::out);
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
	return 0;
}
