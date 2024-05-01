/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 01:33:26 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 02:10:50 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nbrlen(int n)
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
	return(i);
}

char	*ft_itoa(int nbr)
{
	char	*r;
	int	len;

	if (nbr == -2147483648)
		return ("-2147483648");
	len = nbrlen(nbr);
	r = malloc(sizeof(char) * len + 1);
	if (!r)
		return (NULL);
	r[len] = 0;
	if (nbr < 0)
	{
		r[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		r[0] = '0';
	while (nbr)
	{
		r[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (r);
}


#include <stdio.h>
int	main()
{
	int	i = 0;
	printf("%s", ft_itoa(i));
}
