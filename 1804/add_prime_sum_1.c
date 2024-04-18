/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:29:45 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/18 21:45:04 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i])
	{
		r = r * 10 + str[i++] - '0';
	}
	return (r);
}

int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n <= 1)
		return (0);
	while (i * i <= n)
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

	r = 0;
	if (n > 9)
		putnbr(n / 10);
	r = n % 10 + '0';
	write(1, &r, 1);
}

int	main(int ac, char **av)
{
	int	nr;
	int	sum;

	if (ac == 2)
	{
		nr = ft_atoi(av[1]);
		sum = 0;
		while (nr > 0)
		{
			if (is_prime(nr))
				sum += n;
			nr--;
		}
		putnbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}
