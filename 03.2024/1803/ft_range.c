/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:51:28 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/18 17:03:41 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	*r;

	i = 0;
	if (start > end)
		r = malloc(sizeof(int) * (start - end) + 1);
	else
		r = malloc(sizeof(int) * (end - start) + 1);
	while (i < len)
	{
		if (start < end)
		{
			r[i] = start;
			start++;
			i++;
		}
		else
		{
			r[i] = start;
			start--;
			i++;
		}
	}
	return (r);
}
