#include <unistd.h>
#include <stdlib.h>
int	ft_str_length(char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}

char	*ft_str_duplicate(char *string)
{
	int		index;
	int		length;
	char	*duplicate;

	length = ft_str_length(string);
	index = 0;
	duplicate = (char *)malloc(sizeof(char) * length + 1);
	if (!duplicate)
		return (NULL);
	while (string[index] != '\0')
	{
		duplicate[index] = string[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}

char	*get_next_line(int fd)
{
	int		n;
	int		index;
	char	character;
	char	buffer[7000000];

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n = read(fd, &character, 1);
	while (n > 0)
	{
		buffer[index++] = character;
		if (character == '\n')
			break ;
		n = read(fd, &character, 1);
	}
	if (n <= 0 && index == 0)
		return (NULL);
	buffer[index] = '\0';
	return (ft_str_duplicate(buffer));
}






/* all failed vers under
char	*get_next_line(int fd)
{
	int	i;
	int	b;
	char	*buf;
	char	c;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	i = 0;
	b = read(fd, &c, 1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (b > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break ;
		b = read(fd, &c, 1);
	}
	if ((b <= 0) && (i == 0))
		return (free(buf), NULL);
	buf[i] = '\0';
	return (buf);
}


failed
char	*get_next_line(int fd)
{
	int	i = 0;
	int 	rd;
	char	c;
	char	*buf = malloc(sizeof(char) * BUFFER_SIZE + 1);

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((rd = read(fd, &c, 1)) > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break ;
	}
	if ((rd <= 0) && (i == 0))
		return (free(buf), NULL);
	buf[i] = '\0';
	return (buf);
}

failed
char *get_next_line(int fd)
{
	int	i;
	int	rd;
	char	c;
	char *buf = malloc(10000);

	i = 0;
	rd = 0;
	while ((rd == read(fd, &c, 1)) > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break ;
	}
	if ((!buf[i - 1] && !rd) || rd == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[i] = '\0';
	return (buf);
}
*/
