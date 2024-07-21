/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:39:33 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/13 15:35:49 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_setzero(char *s, int n)
{
	char	*str;

	str = s;
	while (n--)
		*str++ = 0;
	return (s);
}

int	ft_strchr_n(char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !(*s))
		return (1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *ret, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	char	*ret;

	s1len = 0;
	if (s1)
		s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	ret = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ret)
		return (NULL);
	ret = ft_strcpy(ret, s1, s2);
	return (ret);
}
