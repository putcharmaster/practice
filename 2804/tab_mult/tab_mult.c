/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:15:39 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 17:27:03 by sanhwang         ###   ########.fr       */
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
		r = r*10+str[i++]-'0';
	return (r);
}

void	putnbr(int n)
{
	char	r;

	r = 0;
	if (n > 9)
		putnbr(n / 10);
	r = r * 10 + (n % 10) + '0';
	write(1, &r, 1);
}

int	main(int ac, char **av)
{
	int	n;
	int	i;

	if(ac == 2)
	{
		n = ft_atoi(av[1]);
		i = 1;
		while (i < 10)
		{
			putnbr(i);
			write(1, " x ", 3);
			putnbr(n);
			write(1, " = ", 3);
			putnbr(i*n);
			if(i < 9)
				write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
