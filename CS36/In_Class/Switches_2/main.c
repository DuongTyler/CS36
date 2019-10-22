#include <stdio.h>
int main()
{
	while (1)
	{
		char code;
		printf("Enter a code: ");
		scanf("%c", &code);
		switch(code)
		{
			case 'J': case 'j':	printf("Jets\n");	break;
			case 'P': case 'p':	printf("Patriots\n");	break;
			case 'C': case 'c':	printf("Cowboys\n");	break;
			default:		printf("Unknown\n");
		}
		while (getchar() != '\n');
	}
	return 0;
}
