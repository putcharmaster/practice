/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:03:04 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/19 22:26:28 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdlib.h>

int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*r;
	int	len;

	len = ft_len(nbr);
	r = malloc(sizeof(char) * (len + 1));
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
*/
#include <stdio.h>

int	main()
{
	printf("%s", ft_itoa(42));
}
