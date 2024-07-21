#include <fcntl.h>
#include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

typedef struct	s_list
{
	char			*str_buf;
	struct s_list	*next;
}		t_list;

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	charcount(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (NULL);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	struct_strcpy(t_list *list, char *str)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->str_buf[i++]
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	scanline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	unmalloc(t_list **list, t_list *clean, char *buf)
{
	t_list	*temp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (clean->str_buf[0])
		*list = clean;
	else
	{
		free(buf);
		free(clean);
	}
}

char	*get_line(t_list *list)
{
	int		len;
	char	*nxtline;

	len = charcount(list);
	nxtline = malloc(len + 1);
	if (nxtline == NULL)
		return (NULL);
	struct_strcpy(list, nxtline);
	return (nxtline);
}

void	lstcat(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	last_node = ft_lstlast(*list);
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	clean_lst(t_list **list)
{
	t_list	*last_node;
	t_list	*clean;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean = malloc(sizeof(t_list));
	if (buf == NULL || clean == NULL)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	k = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		i++;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean->str_buf = buf;
	clean->next = NULL;
	unmalloc(list, clean, buf);
}

void	create_lst(t_list **list, int fd)
{
	char	*buf;
	int		b_read;

	while (scanline(*list) != 1)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[b_read] = '\0';
		lstcat(list, buf);
	}
}

char	*get_next_line(int fd) // fd : file descriptor
{
	static t_list	*list;
	char		*nxtline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_lst(&list, fd);
	if (list == NULL)
		return (NULL);
	nxtline = get_line(list);
	clean_lst(&list);
	return (nxtline);
}  //create_lst and clean_lst are like malloc and free
