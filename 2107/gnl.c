#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int	i;
	int	len;
	char	*dup;

	len = ft_strlen(str);
	i = 0;
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while(str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	int	i;
	int	r;
	char	c;
	char	buf[7000000];

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r = read(fd, &c, 1);
	while (r > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break ;
		r = read(fd, &c, 1);
	}
	if (r <= 0 && i == 0)
		return (NULL);
	buf[i] = '\0';
	return (ft_strdup(buf));
}
