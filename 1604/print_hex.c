/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:57:31 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 21:10:53 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int p)
{
	char	*str;

	str = "0123456789abcdef";
	if (p == 0)
		write(1, "0", 1);
	while (p)
	{
		write(1, &str[p % 16], 1);
		p = p / 16;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	r;
	int	m;

	i = 0;
	m = 1;
	r = 0;
	if (!str[i])
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			m = -m;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
			r = r * 10 + str[i++] - '0';
	return (r * m);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}


////////////////////////////////////////////////////////////////////////////
int	ft_atoi(char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		n = n * 10;
		n = n + *str - '0';
		str++;
	}
	return (n);
}

void	print_hex(int n)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if(n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
