/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_compact.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:01:03 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 14:22:45 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


doesnt work ////////////////////////////////////////////////////////////
/*
#include <stdlib.h>

char	**ft_split(char *str)
{
	int	i;
	int	j;
	int	k;
	char	**split;

	i = 0;
	k = 0;
	split = malloc(sizeof(char *) * 256);
	if (!split)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		j = 0;
		split[k] = malloc(sizeof(char) * 4096);
		if (!split[k])
			return (NULL);
		while (str[i] && (str[i] != ' ' 
				&& str[i] != '\t' && str[i] != '\n'))
			split[k][j++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		split[k] = 0;
		k++;
	}
	split[k] = NULL;
	return (split);
}
*/

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

