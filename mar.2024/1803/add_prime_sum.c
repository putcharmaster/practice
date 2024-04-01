/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:57:53 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/18 11:13:58 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int n)
{
	int	div;

	div = 2;
	while(div <= n / 2)
	{
		if(n & div == 0)
			return (0);
		div++;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	char	c;

	if(n = -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if(n < 0)
	{
		write(1, "-", 1);
		n = -nb;
	}
	if(n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	ft_atoi_simple(char *str)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	while(*str)
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	nr;
		int	sum;

		nr = ft_atoi(av[1]);
		sum = 0;
		while(nr > 0)
		{
			if (ft_is_prime(nr) != 0)
				sum += nr;
			nr--;
		}
		ft_putnbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}
