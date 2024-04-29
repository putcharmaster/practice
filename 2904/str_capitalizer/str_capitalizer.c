/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:21:18 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 12:34:01 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	i = 0;
	if (ac > 1)
	{
		j = 1;
		if (av[j][i] >= 'a' && av[j][i] <= 'z')
		{
			av[j][i] = av[j][i] - 32;
			write(1, &av[j][i++], 1);
		}
		if (av[j][i] >= 'A' && av[j][i] <= 'Z')
			write(1, &av[j][i++], 1);
		while (j < ac)
		{
			while (av[j][i])
			{
				if (av[j][i] >= 'A' && av[j][i] <= 'Z')
					av[j][i] = av[j][i] + 32;
				if ((av[j][i] >= 'a' && av[j][i] <= 'z')
					&& (av[j][i - 1] == ' ' || av[j][i - 1] == '\t'))
					av[j][i] = av[j][i] - 32;
				write(1, &av[j][i++], 1);
			}
			i = 0;
			j++;
			write(1, "\n", 1);
		}
		return (0);
	}
	write(1, "\n", 1);
	return (0);
}
