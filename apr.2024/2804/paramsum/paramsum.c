/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:48:26 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 18:53:12 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	char r;
	r = 0;
	if (n > 9)
		putnbr(n / 10);
	r = r * 10 + n%10 + '0';
	write(1, &r, 1);
}

int	main(int ac, char **av)
{
	int	i;
	if (ac > 1)
	{
		i = ac - 1;
		putnbr(i);
		write(1, "\n", 1);
		return (0);
	}
	write(1, "0\n", 2);
	return (0);
}
