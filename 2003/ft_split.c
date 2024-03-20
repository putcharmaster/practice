/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:21:18 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/20 10:33:40 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while(i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int	i;
	int	j;
	int	k;
	int	wc;

	i = 0;
	j = 0;
	k = 0;
	wc = 0;
	while(str[i])
	{
		while (str[i] == ' ' 
	}
}
