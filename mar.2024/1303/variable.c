#include <stdio.h>
#include <string.h>
#include <stdarg.h>
int	max(int num_args, ...)
{
	va_list	args;

	va_start(args, num_args);

	
	int max = 0;

	for (int i = 0; i < num_args; i++)
	{
		int x = va_arg(args, int);
		if (i == 0)
			max = x;
		else if( x>max)
			max = x;
		printf("x : %d\n", x);
	}
	va_end(args);


	return max;
}

void	print(char *placeholders, ...)
{
	int	num_args = strlen(placeholders);

	va_list	args;
	va_start(args, placeholders);

	for(int i = 0; i < num_args; i++)
	{
		if (placeholders[i] == 'd')
		{
			int x = va_arg(args, int);
			printf("%d\n", x);
		}
		else if (placeholders[i] == 'f')
		{
			double x = va_arg(args, double);
			printf("%f\n", x);
		}
	}
	

}


int	main(void)
{
	int	max_num = max(2, 1, 543, 23);

	print("ddfd", 4, 2, 10.6, 3);
//	printf("max_num: %d\n", max_num);
	return 0;
}
