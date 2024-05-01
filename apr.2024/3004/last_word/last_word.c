/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 07:42:27 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/30 07:45:20 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;
	i = 0;
	start = 0;
	end = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		while (av[1][i] < 33)
			i--;
		end = i;
		while (av[1][i] > 32)
			i--;
		start = i + 1;
		while (start <= end)
			write(1, &av[1][start++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
