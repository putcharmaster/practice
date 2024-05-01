/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:15:23 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 15:19:27 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	char	r;
	if (n > 9)
		putnbr(n / 10);
	r = n % 10 + '0';
	write(1, &r, 1);
}

int	main(int ac, char **av)
{	
	int	i;

	i = 0;
	if (ac > 1)
	{
		i = ac - 1;
		putnbr(i);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
