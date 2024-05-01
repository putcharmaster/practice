/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 07:41:45 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/19 08:09:52 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
//	int	m;
	int	r;

	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
		r = r * 10 + str[i++] - '0';
	return (r);
}

int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n <= 1)
		return (0);
	if (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	putnbr(int n)
{
	char	*r;

	r = "0123456789";
	if (n > 9)
		putnbr(n / 10);
	write(1, &r[n % 10], 1);
}

int	main(int ac, char **av)
{
	int	nbr;
	int	sum;

//	nbr = ft_atoi(av[1]);
//	sum = 0;
	if (ac == 2)
	{
		nbr = ft_atoi(av[1]);
		sum = 0;
		while (nbr--)
		{
			if (is_prime(nbr))
				sum += nbr;
			
		}
		putnbr(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
