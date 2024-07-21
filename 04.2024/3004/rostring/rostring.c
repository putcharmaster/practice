/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:25:19 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/30 08:34:07 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	start = 0;
	int	end = 0;

	if (ac > 1)
	{
		while (av[1][i] < 33)
			i++;
		start = i;
		while (av[1][i] && av[1][i] > 32)
			i++;
		end = i;
		while (av[1][i] && av[1][i] < 33)
			i++;
		if (av[1][i])
		{
			while (av[1][i])
			{
				if (av[1][i] < 33)
				{
					while (av[1][i] && av[1][i] < 33)
						i++;
					if (av[1][i])
						write(1, " ", 1);
				}
				else
					write(1, &av[1][i++], 1);
			}
			write(1, " ", 1);
		}
		while (start < end)
			write(1, &av[1][start++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
