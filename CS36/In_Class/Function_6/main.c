#include <stdio.h>

void load(char *name, double *f_hrs, double *f_rate, double *tp)
{
	printf("Enter a name: ");
	fgets(name, 20, stdin);
	sscanf(name, "%[^\n]", name);
	name[19] = '\0';
	printf("Enter hours: ");
	scanf("%lf", f_hrs);
	printf("Enter pay rate: ");
	scanf("%lf", f_rate);
	printf("Enter tax rate: ");
	scanf("%lf", tp);
}

double calcGross(double hrs, double rate)
{
	return hrs*rate;
}

double calcTax(double gross, double tax)
{
	return gross*tax/100;
}

double calcNet(double gross, double tax)
{
	return gross - tax;
}

void calc(double f_hrs, double f_rate, double tp, double *gross, double *tax, double *net)
{
	*gross = calcGross(f_hrs, f_rate);
	*tax = calcTax(*gross, tp);
	*net = calcNet(*gross, *tax);
}

void print(char *name, double gross, double tax, double net)
{
	printf("The employee name is %s.\n", name);
	printf("The gross is: $%.2lf\n", gross);
	printf("The tax is: $%.2lf\n", tax);
	printf("The net is: $%.2lf\n", net);
}

int main()
{
	double hrs, rate, taxrate, gross, tax, net;
	char name[20];
	load(name, &hrs, &rate, &taxrate);
	calc(hrs, rate, taxrate, &gross, &tax, &net);
	print(name, gross, tax, net);
	return 0;
}
