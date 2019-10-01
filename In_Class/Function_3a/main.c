#include <stdio.h>

void load(float *f_hrs, float *f_rate, float *tp)
{
	printf("Enter hours: ");
	scanf("%f", f_hrs);
	printf("Enter pay rate: ");
	scanf("%f", f_rate);
	printf("Enter tax rate: ");
	scanf("%f", tp);
}

void calc(float f_hrs, float f_rate, float tp, float *gross, float *tax, float *net)
{
	*gross = f_hrs * f_rate;
	*tax = *gross * tp/100;
	*net = *gross - *tax;
}

void print(float gross, float tax, float net)
{
	printf("The gross is: $%.2f\n", gross);
	printf("The tax is: $%.2f\n", tax);
	printf("The net is: $%.2f\n", net);
}

int main()
{
	float hrs, rate, taxrate, gross, tax, net;
	load(&hrs, &rate, &taxrate);
	calc(hrs, rate, taxrate, &gross, &tax, &net);
	print(gross, tax, net);
	return 0;
}
