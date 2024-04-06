static int	appendline(char **s, char **line)
{
	int	len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			fr_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	output(char **s, char **line, int r, int fd)
{
	if (r < 0)
		return (-1);
	else if (r == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

int	*get_next_line(int fd, char **line)
{
	int	r;
	static char	*s[FD_SIZE];
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break;
	}
	return (output(s, line, r, fd));
}
