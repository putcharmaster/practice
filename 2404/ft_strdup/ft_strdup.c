/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:36:09 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/24 14:43:58 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*ft_strdup(char *src)
{
	int	i;
	char	*r;

	i = 0;
	while (src[i])
		i++;
	r = malloc(sizeof(char) * i + 1);
	i = 0;
	if (!r)
		return (NULL);
	while (src[i])
	{
		r[i] = src[i];
		i++;
	}
	r[i] = 0;
	return (r);
}
