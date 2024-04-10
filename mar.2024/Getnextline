#include <unistd.h>  //ssize_t
#include <stdlib.h>
#include <sys/types.h>  //ssize_t

void	*ft_setzero(char *s, int n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str++ = 0;
		n--;
	}
	return (s);
}

int	ft_strchr_num(char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !(*s))
		return (1);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_copystr(char *ans, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			ans[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		ans[i++] = s2[j++];
	ans[i] = 0;
	return (ans);
}

char	*ft_strjoin_r(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	char	*ans;

	s1len = 0;
	if (s1)
		s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	ans = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ans)
		return (NULL);
	ans = ft_copystr(ans, s1, s2);
	return (ans);
}

char	*read_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	b_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	b_read = 1;
	while (b_read > 0 && ft_strchr_num(line, '\n'))
	{
		ft_setzero(buffer, BUFFER_SIZE);
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
		{
			free (buffer);
			if (line)
				return (line);
			return (NULL);
		}
		buffer[b_read] = 0;
		line = ft_strjoin_r((char *)line, (char *)buffer);
	}
	free(buffer);
	return (line);
}

char	*save_newline(char *line)
{
	int		i;
	char	*r;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	r = malloc(sizeof(char) * (i + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		r[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		r[i++] = '\n';
	r[i] = 0;
	return (r);
}

char	*save_oldline(char *line)
{
	int		i;
	int		j;
	int		len;
	char	*oldline;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	if (!line[i])
	{
		free (line);
		return (NULL);
	}
	oldline = malloc(sizeof(char) * (len - i) + 1);
	if (!oldline)
		return (NULL);
	while (line[i])
		oldline[j++] = line[i++];
	oldline[i] = '\0';
	free (line);
	return (oldline);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	r = save_newline(line);
	line = save_oldline(line);
	return (r);
}
