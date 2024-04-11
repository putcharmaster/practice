/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:43:16 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/11 17:24:15 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *line)
{
	char	*buf;
	ssize_t	b_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	b_read = 1;
	while (b_read > 0 && ft_strchr_n(line, '\n'))
	{
		ft_setzero(buf, BUFFER_SIZE);
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read <= 0)
		{
			free(buf);
			if (line)
				return (line);
			return (NULL);
		}
		buf[b_read] = 0;
		line = ft_strjoin((char *)line, (char *)buf);
	}
	free(buf);
	return (line);
}

char	*newline(char *line)
{
	int		i;
	char	*ret;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		ret[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		ret[i++] = '\n';
	ret[i] = 0;
	return (ret);
}
//if i free the line here, restline function cannot work.

char	*restline(char *line)
{
	int		i;
	int		j;
	int		len;
	char	*leftover;

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
	leftover = malloc(sizeof(char) * (len - i) + 1);
	if (!leftover)
		return (NULL);
	while (line[i])
		leftover[j++] = line[i++];
	leftover[j] = 0;
	free(line);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	ret = newline(line);
	line = restline(line);
	return (ret);
}
