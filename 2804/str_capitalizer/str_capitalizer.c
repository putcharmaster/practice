/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:34:07 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 00:34:05 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	i = 0;
	j = 1;
	if (ac < 2)
		write(1, "\n", 1);
	else
	{
		while (j < ac)
		{
			if (av[j][i] >= 'a' && av[j][i] <= 'z')
			{
				av[j][i] = av[j][i] - 32;
				write(1, &av[j][i++], 1);
			}
			if (av[j][i] >= 'A' && av[j][i] <= 'Z')
				write(1, &av[j][i++], 1);
			while (av[j][i])
			{
				if(av[j][i] >= 'A' && av[j][i] <= 'Z')
					av[j][i] = av[j][i] + 32;
				if((av[j][i] >= 'a' && av[j][i] <= 'z')
					&& (av[j][i - 1] == ' ' || av[j][i-1] == '\t'))
					av[j][i] = av[j][i] - 32;
				write(1, &av[j][i++], 1);
			}
			write(1, "\n", 1);
			i = 0;
			j++;
		}
	}
	return (0);
}
