/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:10:38 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/25 12:55:55 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ctype.h>



int	wordcount(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && isspace(*str))
			str++;
		if (*str && !isspace(*str))
		{
			i++;
			while (*str && !isspace(*str))
				str++;
		}
	}
	return (i);
}

char	*split_word(char *str)
{
	char	*word;
	int	i;

	i = 0;
	while (str[i] && !isspace(str[i]))
			i++;
	word = malloc(sizeof(char) * i + 1);
	i = 0;
	if (!word)
		return (NULL);
	while (str[i] && !isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
	
}

char	**ft_split(char *str)
{
	char	**ret;
	int	i;

	i = 0;
	ret = malloc(sizeof(char *) * wordcount(str) + 1);
	if (!ret)
		return (NULL);
	while (*str)
	{
		while (*str && isspace(*str))
			str++;
		if (*str && !isspace(*str))
		{
			ret[i] = split_word(str);
			i++;
			while (*str && !isspace(*str))
				str++;
		}
	}
	ret[i] = 0;
	return (ret);
}


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
	free(arr);
}
