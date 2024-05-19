/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:05:57 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/17 19:19:45 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	dlimiter(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	*woloc(char *str)
{
	char	*r;
	int	i;

	i = 0;
	while (str[i])
		i++;
	r = malloc(sizeof(char) * i + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (str[i] && !dlimiter(str[i]))
	{
		r[i] = str[i];
		i++;
	}
	r[i] = 0;
	return (r);
}

int	wordcount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && dlimiter(str[i]))
			i++;
		if (str[i] && !dlimiter(str[i]))
		{
			count++;
			while (str[i] && !dlimiter(str[i]))
				i++;
		}
	}
	return (count);
}

char	**ft_split(char *str)
{
	char **r;
	int i;

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
