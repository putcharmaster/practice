/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:19:54 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/30 08:24:24 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int n)
{
	char *r;
	r = "0123456789";
	if (n > 9)
		putnbr(n / 10);
	write(1, &r[n%10], 1);
}


int	main(int ac, char **av)
{
	if (ac == 1)
		putnbr(0);
	else
		putnbr(ac-1);
	write(1, "\n", 1);
	return (0);
}
