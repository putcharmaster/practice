/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:20:23 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 22:43:34 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	flag = 0;
	i = 0;
	if (ac == 2)
	{
		while (av[1][i] < 33)
			i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
			{
				while (av[1][i] == ' ' || av[1][i] == '\t')
				{
					i++;
				}
				flag = 1;
				if (!av[1][i])
				{
					write(1, "\n", 1);
					return (0);
				}
			}
			if (flag)
			{
				write(1, " ", 1);
				flag = 0;
			}	
			write(1, &av[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
