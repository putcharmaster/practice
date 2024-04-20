/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:35:02 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 19:49:29 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid(char c, int base)
{
	char	*l;
	char	*u;

	l = "0123456789abcdef";
	u = "0123456789ABCDEF";
	while (base--)
		if (l[base] == c || u[base] == c)
			return (1);
	return (0);
}

int	value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	r;
	int	m;

	i = 0;
	r = 0;
	m = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	while (valid(str[i], str_base))
		r = r * str_base + value(str[i++]);
	return (r * m);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
		int	i = 16;
		printf("%d", ft_atoi_base(av[1], i));
}
