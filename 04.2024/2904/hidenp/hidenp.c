/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:30:39 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 17:41:29 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[1][i] && av[2][j])
		{
			if (av[1][i] == av[2][j])
			{
				i++;
			}
			if (!av[1][i])
			{
				write(1, "1\n", 2);
				return (1);
			}
			j++;
		}
		if (!av[2][j])
		{
			write(1, "0\n", 2);
			return (0);
		}
	}
	write(1, "\n", 1);
	return (0);
}
