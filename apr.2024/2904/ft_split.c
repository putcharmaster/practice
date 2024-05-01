/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:39:36 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 21:52:13 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (str[i] && !dlimiter(str[i]))
	{
		r[i] = str[i];
		i++;
	}
	r[i] = 0;
	return (r);
}	

char	**ft_split(char *str)
{
	char 	**r;
	int	i;
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
			r[i++] = woloc(str);
			while (*str && !dlimiter(*str))
				str++;
		}
	}
	r[i] = NULL;
	return (r);
}


#include <stdio.h>
int	main(int ac, char **av)
{
	char **r;
	char *str = "hello,  tomorrow exam";
	r = ft_split(str);
	printf("%s\n", r[0]);
	printf("%s\n", r[1]);
	printf("%s\n", r[2]);
}
