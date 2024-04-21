/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:58:26 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 19:16:15 by sanhwang         ###   ########.fr       */
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
char	*ft_strncpy(char *s1, char *s2, int n)
{
	int 	i;

	i = 0;
	while (s2[i] && i < n)
		s1[i] = s2[i];
	s1[i] = 0;
	return (s1);
}

char	**ft_split(char *str)
{
	int	i;
	int	start;
	int	k;
	int	wc;

	i = 0;
	start = 0;
	k = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
	}

	char	**out = malloc(sizeof(char *) * (wc + 1));
	i = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (i > start)
		{
			out[k] = malloc(sizeof(char) * ((i - start) + 1));
			ft_strncpy(out[k++], &str[start++], i - start);
		}
	}
	out[k] = 0;
	return (out);
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


