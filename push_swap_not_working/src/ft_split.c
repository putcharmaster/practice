/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:25:22 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/09 22:06:42 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *rt;

        if (!s)
                return (NULL);
        if (ft_strlen(s) < start)
                len = 0;
        if (ft_strlen(s + start) < len)
                len = ft_strlen(s + start);
        rt = malloc(sizeof(char) * (len + 1));
        if (!rt)
                return (NULL);
        ft_strlcpy(rt, s + start, len + 1);
        return (rt);
}


static void	ft_allocate(char **tab, char const *s, char sep)
{
	char		**tab1;
	char const	*tmp;

	tmp = s;
	tab1 = tab;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*tab1 = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab1;
		}
	}
	*tab1 = NULL;
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			++s;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}
