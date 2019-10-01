struct cube
{
	float l;
	float w;
	float h;
	void (*foo)(void);
};

int sum(int a, int b)
{
	return a+b;
}

void doMore(struct cube *c)
{
	c -> l = 1.0;
	c -> w = 1.0;
	c -> h = 1.0;
}

void doStuff(int *val)
{
	*val = 2;
}
