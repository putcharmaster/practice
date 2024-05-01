/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:02:48 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/17 23:28:18 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	length(int n)
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
	char	*res;
	int	len;

	len = length(nbr);
	if (nbr == -2147483648)
		return ("-2147483648\0");
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr == 0)
		res[0] = '0';
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

#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(33));
	printf("%s\n", ft_itoa(-33));
	printf("%s\n", ft_itoa(12345));
	printf("%s\n", ft_itoa(-12345));
	printf("%s\n", ft_itoa(92384095));
	printf("%s\n", ft_itoa(-98765));
	printf("%s\n", ft_itoa(45));
	printf("%s\n", ft_itoa(-45));
	printf("%s\n", ft_itoa(2147483649));
	printf("%s\n", ft_itoa(2147483649));
	printf("%s\n", ft_itoa(0));
	return (0);
}
