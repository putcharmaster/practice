#include <stdio.h>
#include <unistd.h>

int	main()
{
	printf("%d\n%d", getpid(), getppid());
}
