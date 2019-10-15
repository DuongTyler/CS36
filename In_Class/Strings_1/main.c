#include <stdio.h>
#include <stdlib.h>

//Strings are passed through by reference only


void load(char *a, char *b)
{
	printf("A: ");
	fgets(a, 20, stdin);
	sscanf(a, "%[^\n]", a);
	printf("B: ");
	fgets(b, 20, stdin);
	sscanf(b, "%[^\n]", b);
}

void stringSwap(void **pa, void **pb)
{
	void *pc;	//

	pc = *pa;	
	*pa = *pb;
	*pb = pc;
}

int main()
{
	char name1[20], name2[20];
	load (name1, name2);
	printf("%s, %s\n", name1, name2);
	stringSwap((void**) &name1, (void**) &name2);
	printf("%s, %s\n", name1, name2);

	return 0;
}
