/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:04:45 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/18 17:55:31 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	while(len--)
	{
		if(end >= start)
			r[len] = start++;
		else
			r[len] = start--;
	}
	return (r);
}

///////////////////////////////////

int	*ft_rrange(int start, int end)
{
	int	i;
	int	n;
	int	*r;
	int	size;

	i = 0;  
	size = 0;
  	if (end >= 0)
                size = end - start + 1;
	else
                size = start - end + 1;
	r = malloc(sizeof(int) * size);
 	if (!r)
		return (NULL);
	n = end;
	while (i < size)
	{
		r[i] = n;
		i++;
		if (end >= start)
			n--;
		else
			n++;
	}
	return (r);
}
/*
//////////////////////////////
int     *ft_range(int start, int end)
{
        int     i;
        int     *r;

        i = 0;
        if (start > end)
                r = malloc(sizeof(int) * (start - end) + 1);
        else
                r = malloc(sizeof(int) * (end - start) + 1);
	if (!r)
		return (NULL);
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
*/
