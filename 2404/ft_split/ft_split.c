/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:14:03 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/24 23:33:29 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;

	while (str[i])
	{
		while (str[i] && (str[i] < 33))
			i++;
		if (str[i])
			wc++;
		while (str[i] && !(str[i] < 33))
			i++;
	}

	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;

	while (str[i])
	{
		while (str[i] && (str[i] < 33))
			i++;
		j = i;
		while (str[i] && !(str[i] < 33))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}

/*
#include <stdlib.h>

int	dlimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	wordcount(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && dlimiter(str[i]))
			i++;
		if (str[i] && !dlimiter(str[i]))
		{
			wc++;
			while (str[i] && !dlimiter(str[i]))
				i++;
		}
	}
	return (wc);
}

char	*woloc(char *str)
{
	char	*r;
	int	i;

	i = 0;
	while (str[i])
		i++;
	r = malloc(sizeof(char) * i + 1);
	i = 0;
	if (!r)
		return (NULL);
	while (str[i] && dlimiter(str[i]))
	{
		r[i] = str[i];
		i++;
	}
	r[i] = 0;
	return (r);
}

char	**ft_split(char *str)
{
	int	i;
	char	**r;

	i = 0;
	r = malloc(sizeof(char *) * wordcount(str) + 1);
	if (!r)
		return (NULL);
	while (*str)
	{
		while (*str && dlimiter(*str))
			str++;
		if (*str && !dlimiter(*str))
		{
			r[i] = woloc(str);
			i++;
			while (*str && !dlimiter(*str))
				str++;
		}
	}
	r[i] = NULL;
	return (r);
}
*/
