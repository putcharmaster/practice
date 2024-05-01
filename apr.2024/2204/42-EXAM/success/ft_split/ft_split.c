/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:51:56 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 23:25:42 by sanhwang         ###   ########.fr       */
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


char	*word_malloc(char *str)
{
	int	i;
	char	*r;

	i = 0;
	while (str[i] && !dlimiter(str[i]))
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
			r[i] = word_malloc(str);
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

int		main(int ac, char **av)
{
 	char **arr;

 	char *phrase = "   Hello,   Flavio\t Wuensche!  ";
 	arr = ft_split(phrase);
 	printf("%s\n", arr[0]);
 	printf("%s\n", arr[1]);
 	printf("%s\n", arr[2]);
 	printf("%s\n", arr[3]);
}

#include <stdio.h>

int	main()
{
	char **r;
	char rr[] = " hl,  aswer. ddkjkfj ";
	r = ft_split(rr);
	printf("%s\n", r[0]);
	printf("%s\n", r[1]);
	printf("%s\n", r[2]);
}
*/
