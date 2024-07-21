/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:09:05 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/18 22:41:24 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int	*ft_range(int start, int end)
{
	int	i;
	int	*r;
	int	len;

	i = 0;
	len = start - end + 1;
	if (start > end)
		r = malloc(sizeof(int) * len);
	else
		r = malloc(sizeof(int) * len);
	while (i <= len)
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


int	*ft_range(int min, int max)
{
	int	n;
	int	*s;

	if (max >= min)
		n = max - min;
	else
		n = min - max;
	s = malloc(sizeof(int) * n);
	if (!s)
		return (NULL);
	while(max != min)
	{
		if(max > min)
			*s++ = min++;
		else
			*s++ = min--;
	}
	*s = min;
	return (s - n);
}

// not sure about this.
int	*ft_rrange(int start, int end)
{
	int	*range;
	int	i;
	int	n;

	i = 0;
	if (start > end)
		return (ft_rrange(end, start));
	n = end - start + 1;
	range = malloc(sizeof(int) * n);
	if (range)
	{
		while (i < n)
		{
			range[i] = start;
			start++;
			i++;
		}
	}
	return (range);
}


int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*res;

	i = 0;
	len = abs((end - start)) + 1;
	res = malloc(sizeof(int) * len);
	while (i < len)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return (res);
}
