/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:36:21 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 13:48:54 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;
	int	flag;

	start = 0;
	end = 0;
	flag = 0;
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
			flag = start;
			while (start <= end)
				write(1, &av[1][start++], 1);
			if (flag)
				write(1, " ", 1);
		}

	}
	write(1, "\n", 1);
	return (0);
}
