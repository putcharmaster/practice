/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:08:26 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 17:48:04 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	dlimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_word(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i])
	{
		while (str[i] && dlimiter(str[i]))
			i++;
		if (str[i] && !dlimiter(str[i]))
		{
			r++;
			while (str[i] && !dlimiter(str[i]))
				i++;
		}
	}
	return(r);
}

char	*malloc_word(char *str)
{
	int	i;
	char	*r;

	i = 0;
	while (str[i] && !dlimiter(str[i]))
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
	char	**r;
	int	i;

	i = 0;
	r = malloc(sizeof(char *) * count_word(str) + 1);
	if (!r)
		return (NULL);
	while (*str)
	{
		while (*str && dlimiter(*str))
			str++;
		if (*str && !dlimiter(*str))
		{
			r[i] = malloc_word(str);
			i++;
			while (*str && !dlimiter(*str))
				str++;
		}
	}
	r[i] = NULL;
	return (r);
}	
#include <stdio.h>

int             main(int ac, char **av)
{
        char **arr;

        char *phrase = "   Hello,   Flavio\t Wuensche!  ";
        arr = ft_split(phrase);
        printf("%s\n", arr[0]);
        printf("%s\n", arr[1]);
        printf("%s\n", arr[2]);
        printf("%s\n", arr[3]);
}

