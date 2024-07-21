/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:55:28 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 17:21:05 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*r;
	int	len;

	if (nbr == -2147483648)
		return ("-2147483648");
	len = intlen(nbr);
	r = malloc(sizeof(char) * (len + 1));
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
	int	n = 0;
	printf("%s\n\n" , ft_itoa(n));
}
