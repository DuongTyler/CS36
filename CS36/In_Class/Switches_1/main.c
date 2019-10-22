#include <stdio.h>

int main()
{
	int x;


	while (1)
	{
		printf("Select and option (1-10): ");
		scanf("%d", &x);
		switch (x)
		{
			case 1:
				printf("Primary\n");
				break;
			case 2:
				printf("Secondary\n");
				break;
			case 3:
				printf("Tertiary\n");
				break;
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				printf("I don't know\n");
				break;
			case 9:
			case 10:
				printf("Something hard to pronounce\n");
				break;
			default:
				printf("I said 1-10...\n");
				return -1;
		}
	}
	return 0;
}
