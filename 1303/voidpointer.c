#include <stdio.h>

int	main(void)
{
	int a = 5;
	double b = 3;
	int *x = &a; //possible
	int *x = &b; // impossible

	void *p;

	p = &a;
	p = &b;

	// void *malloc(size_t size)
	//
	int *a = malloc(sizeof(int) * 10);

	

	return 0;
}
