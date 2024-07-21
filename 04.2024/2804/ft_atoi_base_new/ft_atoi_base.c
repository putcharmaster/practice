/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:11:11 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 22:33:13 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid(char c, int base)
{
	char *lower;
	char *upper;
	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	while (base--)
	{
		if (c == lower[base] || c == upper[base])
			return (1);
	}
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
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	m = 1;
	int	r;
	i = 0;
	r = 0;
	if (str[i] == '-')
	{
		m = -m;
		i++;
	}
	while (valid(str[i], str_base))
		r = r * str_base + value(str[i++]);
	return (r * m);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_atoi_base("a", 16));
}
*/
