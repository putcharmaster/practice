#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	display(char *out)
{
	printf("%i\n", *out);
	printf("%s\n", out);
	char	*out1 = "new";	
	out = out1;
}

int	main(int ac, char **av)
{
	char *str = "This is a test";
	display(str);
	//display(str);
	printf("after= %s\n", str);
	return 0;
}
/*
void    display(char **out)
{
        printf("%s\n", *out);
	*out = "new";
}

int     main(int ac, char **av)
{
        char *str = "This is a test";
        display(&str);
        //display(str);
	printf("after= %s\n", str);
        return 0;
}
*/
//change the value of the pointer using double pointer
