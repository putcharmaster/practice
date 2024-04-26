/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:37 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/25 21:48:03 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	if (ac > 1)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		start = i;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			i++;
		end = i;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		if (av[1][i])
		{
			while (av[1][i])
			{
				if (av[1][i] == ' ' || av[1][i] == '\t')
				{
					while (av[1][i] == ' ' || av[1][i] == '\t')
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
/*
int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		while (av[1][i] < 33)
			i++;
		i = start;
		while (av[1][i] > 32)
			i++;
		i = end;
		while (av[1][i])
			i++;
		if (av[1][i])
		{
			while (av[1][i])
			av[1][i++] = ' ';
			while (start < end)
				av[1][i++] = av[i][start++];
		}
		i = start;
		while (av[1][i])
		{
			write(1, &av[1][i++], 1);
		}
		write(1, "\n", 1);
	}	
}
*/
