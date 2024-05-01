/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:05:34 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/25 22:20:51 by sanhwang         ###   ########.fr       */
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

int	*ft_rrange(int start, int end)
{
	int	*r;
	int	len;
	int	i;

	i = 0;
	len = ft_abs(start - end);
	r = malloc(sizeof(int) * len + 1);
	if (!r)
		return (NULL);
	while (i <= len)
	{
		r[i] = end;
		if (start < end)
			end--;
		else
			end++;
		i++;
	}
	return (r);
}
/*
#include <stdio.h>
int	main()
{
	int	s;
	int	e;
	int	l;
	int	*r;

	
	s = 1;
	e = 2;
	l = ft_abs(s - e) + 1;
	int i = 0;
	r = ft_rrange(s, e);
	while (i < l)
	{
		printf("%d", r[i]);
		printf("\n");
		i++;
	}
}
*/
