/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:50:47 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 18:18:34 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (ac == 2)
	{
		if (!av[1][0])
		{
			write(1, "\n", 1);
			return (0);
		}
		while (av[1][i] < 33)
			i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
			{
				flag = 1;
				while (av[1][i] && av[1][i] < 33)
					i++;
				if (!av[1][i])
				{	write(1, "\n", 1);
					return (0);
				}
			}
			if (flag)
			{
				write(1, "   ", 3);
				flag = 0;
			}
			if (av[1][i] != ' ' && av[1][i] != '\t')
				write(1, &av[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
