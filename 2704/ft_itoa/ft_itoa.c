/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:23:21 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 16:03:00 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nrlen(int n)
{
	int	i;
	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int	len;
	char	*r;

	len = nrlen(nbr);
	r = malloc(sizeof(char) * len + 1);
	if (!r)
		return (NULL);
	r[len] = 0;
	if (nbr == 0)
	{
		r[0] = '0';
		return (r);
	}
	if (nbr < 0)
	{
		r[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		r[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (r);
}
/*
#include <stdio.h>
int	main()
{
	int	n;
	n = 3;
	printf("%s", ft_itoa(n));

}
*/
