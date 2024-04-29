/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:17:42 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 13:35:33 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid(char c, int base)
{
	char *lo;
	char*up;
	lo= "0123456789abcdef";
	up= "0123456789aBCDEF";
	while(base--)
		if (c == lo[base] || c== up[base])
			return (1);
	return (0);

}

int	value(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= '0' && c <= '9')
		return (c - '0');
}

int ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	m;
	int	r;

	i = 0;
	m = 1;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	while (valid(str[i], str_base))
	{
		r = r * str_base + value(str[i++]);
	}
	return (r * m);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_atoi_base("ffffff", 16));
}
*/
