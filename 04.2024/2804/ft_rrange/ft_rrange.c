/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:50:35 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 00:57:16 by sanhwang         ###   ########.fr       */
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
	int	len;
	int	i;
	int	*r;

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
	int	start = -6;
	int	end = 10;
	int	*r;

	r = ft_rrange(start, end);
	int	i;
	i = 0;
	int	len;
	len = ft_abs(start - end) + 1;
	while (i < len)
	{
		printf("%d\n", r[i++]);
	}

}
*/
