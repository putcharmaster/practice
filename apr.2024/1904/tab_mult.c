/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:19:16 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/19 21:39:21 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	putnbr(int n)
{
	char	*r;

	r = "0123456789";
	if (n > 9)
		putnbr(n / 10);
	write(1, &r[n % 10], 1);
}

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

int	main(int ac, char **av)
{
	int	i;
	int	j;
	
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		j = ft_atoi(av[1]);
		while (i < 10)
		{
			putnbr(i);
			write(1, " x ", 3);
			putnbr(j);
			write(1, " = ", 3);
			putnbr(i++ * j);
			write(1, "\n", 1);
		}
	}
	return (0);
}
