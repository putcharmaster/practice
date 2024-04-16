/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:33:30 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 15:42:04 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	*r;
	int	len;

	i = 0;
	if (end >= start)
		len = end - start + 1;
	else 
		len = start - end + 1;
	r = malloc(sizeof(int) * len);
	if (!r)
		return (NULL);
	while (i < len)
	{
		r[i] = end;
		i++;
		if (end >= start)
			n--;
		else
			n++;
	}
	return (r);
}


int	*ft_rrange(int start, int end)
{
	int	*r;
	int	len;

	if (end >= start)
		len = end - start + 1;
	else
		len = start - end + 1;
	r = malloc(sizeof(int) * len);
	if (!r)
		return (NULL);
	while (len--)
	{
		if (end >= start)
			r[len] = start++;
		else
			r[len] = start--;
	}
	return (r);
}
