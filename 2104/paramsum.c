/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:31:09 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 22:35:12 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	char r;

	if (n > 9)
		putnbr(n / 10);
	r = n % 10 + '0';
	write(1, &r, 1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		putnbr(ac - 1);
	}
}
