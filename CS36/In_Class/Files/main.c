#include <stdio.h>

/*
   3 file steps
   - open file for Input or Output

   binary file: Can retrieve entire array in one line
 */

void savetext(char s[][50], int size)
{
	int i;
	FILE *f = fopen("stud.txt", "w");
	for ( i=0; i<size; i++)
	{
		fprintf(f,"%s\n", s[i]);
	}
	fclose(f);

}

void loadtext(char *s, int size)
{

}

void savebin(void *s, int size)
{

}

void loadbin(void *s, int size)
{

}

int main()
{

	char names[5][50];
	int i;
	for (i=0; i<5; i++)
	{
		fgets(names[i], 50, stdin);
	}
	savetext(names, 5);

/*
	FILE *fp = fopen("data.bin", "r");
	int arr[] = {1,2,3,4};
	int arr2[4];

	fread((void*)arr2, sizeof(int), 4, fp);
	fclose(fp);

	fp = fopen("data.bin", "w");
	
	fwrite((void*)arr, sizeof(int), 4, fp);
	fclose(fp);

	FILE *fp = fopen("data.bin", "r");
	char buf[255];
	fgets(buf, 255, fp);
	printf("Data: %s\n", buf);
	fclose(fp);
	for (int i = 0; i < 240; i++)
		buf[i] = 'A';
	buf [240] = '\0';
	fp = fopen("data.bin", "w");
	fputs(buf, fp);
	fclose(fp);
	*/
	return 0;
}
