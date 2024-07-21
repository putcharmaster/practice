#include <unistd.h>
#include <stdlib.h>

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int	i;

	i = 0;
	if (count && size)
		return (NULL);
	ptr = malloc(count*size);
	if (!ptr)
		return (NULL);
	while (ptr[i])
	{
		ptr[i] = 0;
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*get_next_line(int fd)
{
	int	b_read;
	char	*buffer;

	buffer = ft_calloc(3 + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	b_read = read(fd, buffer, 3);
	if (b_read <= 0)
		return (NULL);
	return (buffer);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*next_line;
	int	count;

	count = 0;
	fd = open("./text.txt", O_RDONLY);
	next_line = get_next_line(fd);
	count++;
	printf("%d;%s\n", count, next_line);
	next_line = NULL;

	close(fd);
	return (0);
}
