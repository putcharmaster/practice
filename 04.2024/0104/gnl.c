static int	appendline(char **s, char **line)
{
	int		len;
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
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	output(char **s, char **line, int rt, int fd)
{
	if (rt < 0)
		return (-1);
	else if (rt == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int		rt;
	static char	*s[FD_SIZE];
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((rt = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rt] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (output(s, line, rt, fd));
}
