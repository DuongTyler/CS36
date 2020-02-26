#include <iostream>
#include <fstream>
#include <stdio.h>

void writebin(int *arr, int len)
{
	FILE *f = fopen("data.bin", "wb");
	fwrite(&len, sizeof(int), 1, f);
	fwrite(arr, sizeof(arr[0]), len, f);
	fclose(f);
}

void readbin(int *arr, int len)
{
	FILE *f = fopen("data.bin", "rb");
	fread(&len, sizeof(int), 1, f);
	arr = new int[len];
	fread(arr, sizeof(int), len, f);
	fclose(f);
}

int main()
{
	int i;
	int len, *arr;
	int len2, *arr2;
	std::cout << "Enter length: ";
	std::cin >> len;
	arr = new int[len];
	for (i=0; i<len; i++)
		std::cin >> arr[i];
	writebin(arr, len);
	readbin(arr2, len2);
	for (i=0; i<len2; i++)
		std::cout << arr2[i] << std::endl;

	delete[] arr;
	delete[] arr2;
}

