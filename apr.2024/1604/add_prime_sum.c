/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:09:53 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 14:20:52 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	r;

	r = 0;
	while (*s)
		r = r * 10 + *s++ - '0';
	return (r);
}

int	is_prime(int n)
{
	int	i;

	i = 2;
	if(n <= 1)
		 return (0);
	while (i * i <= n)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	put_nbr(int n)
{
	char	digit;

	if (n >= 10)
		put_nbr(n / 10);
	digit = n % 10 + '0';
	write (1, &digit, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	nbr;
		int 	sum;

		nbr = ft_atoi(av[1]);
		sum = 0;
		while (nbr > 0)
		{
			if (is_prime(nbr))
				sum += nbr;
			nbr--;
		}
		put_nbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}
