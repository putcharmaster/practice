/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:14:58 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/25 13:24:46 by sanhwang         ###   ########.fr       */
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
	len = ft_abs(start - end) + 1;
	r = malloc(sizeof(int) * len);
	if (!r)
		return (NULL);
	while (i < len)
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
	int	i;
	int	start = 5;
	int	end = 1;
	int	*r = ft_rrange(start, end);
	i = 0;
	while (i < ft_abs(start-end) + 1)
	{
		printf("%d", r[i++]);
	}
	
	return (0);

}
*/
