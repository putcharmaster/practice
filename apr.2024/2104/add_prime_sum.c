/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:47:04 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 20:30:19 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
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
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	putnbr(int n)
{
	char	r;

	if (n > 9)
		putnbr(n / 10);
	r= n % 10 + '0';
	write(1, &r, 1);
}

int	main(int ac, char **av)
{
	int	n;
	int	sum;

	if (ac == 2)
	{
		sum = 0;
		n = ft_atoi(av[1]);
		while (n > 0)
		{
			if (is_prime(n))
				sum += n;
			n--;
		}
		putnbr(sum);

	}
	write(1, "\n", 1);
	return (0);
}
