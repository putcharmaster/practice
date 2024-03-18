/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:44 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/18 18:35:50 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	r;

	if (n > 9)
		ft_putnbr(n / 10);
	r = (n % 10) + '0';
	write(1, &r, 1);
}

int	main(int ac, char **av)
{
	(void)av;

	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
