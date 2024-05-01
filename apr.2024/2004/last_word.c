/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:57:09 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 23:12:42 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	s;
	int	e;

	i = 0;
	s = 0;
	e = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		while (av[1][i] < 33)
			i--;
		while (av[1][i] > 32)
			i--;
		i++;	
		while (av[1][i] > 32)
			write(1, &av[1][i++], 1);
			
	}
	write(1, "\n", 1);
	return (0);
}
