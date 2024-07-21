/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:26:28 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 21:42:14 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	m;
	int	r;

	m = 1;
	r = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		m = -m;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - '0';
		str++;
	}
	return (m * r);
}

void	ft_putnbr(int n)
{
	char	r;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	r = n % 10 + '0';
	write(1, &r, 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	nr;

	if(ac != 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		nr = ft_atoi(av[i]);
		while(i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nr);
			write(1, " = ", 3);
			ft_putnbr(i * nr);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
