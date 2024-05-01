/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:28:50 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 19:46:07 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i = i * 10 + str[i++] - '0';
	return (i);
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
	int	n;
	int	i;

	if (ac == 2)
	{
		i = 1;
		n = ft_atoi(av[1]);
		while (i < 10)
		{
			putnbr(i);
			write(1, " X ", 3);
			putnbr(n);
			write(1, " = ", 3);
			putnbr(i * n);
			i++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
