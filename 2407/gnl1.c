#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(char *str)
{
	int	i = 0;
	char	*dup;

	while (str[i])
		i++;
	dup = malloc(sizeof(char) * i + 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

char 	*get_next_line(int fd)
{
	int	i = 0;
	int 	r;
	char 	c;
	char 	buf[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((r = read(fd, &c, 1)) > 0)
	{
		buf[i++] = c;
		if (c == '\0')
			break ;
	}
	buf[i] = '\0';
	if (r <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(buf));
}
