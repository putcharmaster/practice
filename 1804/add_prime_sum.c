/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:40:48 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/18 21:28:42 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	r;
	
	i = 0;
	r = 0;
	while (str[i])
		r = r * 10 + str[i++] - '0';
	return (r);
}

void	putnbr(int n)
{
	char	r;

	if (n > 9)
		putnbr(n / 10);
	r = n % 10 + '0';
	write(1, &r, 1);
}

int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	nr;
		int	sum;

		nr = ft_atoi(av[1]);
		sum = 0;
		while (nr > 0)
		{
			if (is_prime(nr) != 0)
				sum += n;
			nr--;
		}
		putnbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}
