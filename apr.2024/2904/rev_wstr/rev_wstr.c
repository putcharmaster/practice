/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:41:40 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 19:04:04 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	start = 0;
	int	end = 0;
	int	flg = 0;
	
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
			flg = start;
			while (start <= end)
				write(1, &av[1][start++], 1);
			if (flg)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
