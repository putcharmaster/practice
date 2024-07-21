/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:41:10 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 22:58:40 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_number_size(int number)
{
	unsigned int	len;

	len = 0;
	if (number <= 0)
		len++;
	while(number)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	unsigned int	len;

	len = ft_number_size(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	str[len] = 0;
	while(n)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

/////////////////////////////////////////////////////////////////////

char	*ft_itoa(int nbr)
{
	int	n;
	int	len;
	char	*res;

	if(nbr == -2147483648)
		return("-2147483648\0");
	n = nbr;
	len = 0;
	if (nbr <= 0)
		len++;
	while(n)
	{
		n /= 10;
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = 0;
	if (nbr == 0)
	{
		res[0] = 0;
		return (res);
	}
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		res[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (res);
}
