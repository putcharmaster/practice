/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:36:24 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 12:45:32 by sanhwang         ###   ########.fr       */
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
	if (nbr == -2147483648)
		return ("-2147483648");
	char	*r;
	int	len;
	len = nlen(nbr);
	r = malloc(sizeof(char) * len + 1);
	if (!r)
		return (NULL);
	r[len] = 0;
	if (nbr == 0)
		r[0] = '0';
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
	printf("%s", ft_itoa(-2147483648));
}
*/
