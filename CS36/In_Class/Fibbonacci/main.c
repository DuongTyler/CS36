#include <stdio.h>

long long fib(int n)
{
	if (n == 1)	return 1;
	if (n == 0)	return 0;
	return fib(n-1) + fib(n-2);
}

long long fastfib(int n, long long *mem)
{
	long long res;
	if (n == 1 || n == 0) return n;
	if (mem[n] > 0) return mem[n];
	res = fastfib(n-1, mem) + fastfib(n-2, mem);
	mem[n] = res;
	return res;
}

int main()
{
	int x, i;
	printf("Fib to: ");
	scanf("%d", &x);
	long long mem[x+1];
	for (i=0; i<x+1; i++)	mem[i] = -1;
	printf("Fib of %d is %lld\n", x, fastfib(x, mem));
	return 0;
}
