#include <stdio.h>
#include <string.h>



int main()
{
	//char str1[] = "Hello";
	//char str2[] = "World";
	/*strncpy(str1, str2, 2);
	printf("strncmp: %d\n", strncmp(str1, str2, 2));
	printf("strcmp: %d\n", strcmp(str1, str2));
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	//strncat();
	strcat(str1, str2);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	*/
	char str4[] = "reallyreallyreallyreallylongstring";
	char str3[] = "t";
	strcat(str3, str4);
	printf("str3: %s\n", str3);
	printf("str4: %s\n", str4);
	return 0;
}
