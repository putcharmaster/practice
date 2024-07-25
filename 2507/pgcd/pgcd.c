#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	if (ac == 3)
	{
		i = atoi(av[1]);
		j = atoi(av[2]);
		while (i != j && i > 0 && j > 0)
		{
			if (i > j)
				i -= j;
			else
				j -= i;
		}
		printf("%d", i);
	}
	printf("\n");
	return (0);
}
