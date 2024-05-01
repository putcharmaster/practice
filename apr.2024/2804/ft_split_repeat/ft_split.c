/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:18:59 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 18:28:10 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	dlimiter(char c)
{
	return (c == ' '||c == '\t' || c == '\n');
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

	while (str[i])
		i++;
	r = malloc(sizeof(char) * i + 1);
	i = 0;
	if (!r)
		return (NULL);
	while (str[i] && !dlimiter(str[i]))
	{
		r[i] = str[i];
		i++;
	}
	r[i] = 0;
	return (r);

}

char 	**ft_split(char *str)
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
/*
#include <stdio.h>
int	main()
{
	char **ar;

	char *s = "hello bye this";
	ar = ft_split(s);
	printf("%s\n", ar[0]);
	printf("%s\n", ar[1]);
	printf("%s\n", ar[2]);

}
*/
