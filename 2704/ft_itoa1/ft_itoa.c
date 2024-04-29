/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:38:58 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 20:59:00 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nlen(int n)
{
	int	i;
	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*r;
	int	i;
	if (nbr == -2147483648)
		return ("-2147483648");
	i = nlen(nbr);
	r = malloc(sizeof(char) * i + 1);
	if (!r)
		return (NULL);
	r[i] = 0;
	if (nbr == 0)
		r[0] = '0';
	if (nbr < 0)
	{
		r[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		r[--i] = nbr % 10 + '0';
		nbr /= 10;

	}
	return (r);
}
/*
#include <stdio.h>
int	main()
{
	int	i = -214748369;
	printf("%s", ft_itoa(i));
}
*/
