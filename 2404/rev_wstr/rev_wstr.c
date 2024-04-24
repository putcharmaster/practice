/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:08:00 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/24 17:21:21 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;
	int	flag;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		while (i >= 0)
		{
			while (av[1][i] < 33)
				i--;
			end = i;
			while (av[1][i] > 32)
				i--;
			start = i + 1;
			while (start <= end)
				write(1, &av[1][start++], 1);
			if (i > 0)
			{
				write(1, " ", 1);
				i--;
			}
			else if (i == 0)
				break;

		}
	}
	write(1, "\n", 1);
	return (0);
}
