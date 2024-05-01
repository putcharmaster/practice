/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:34:24 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 00:51:56 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[2][j])
		{
			if(av[2][j++] == av[1][i])
				i++;
			if(!av[1][i])
			{
				ft_putchar(av[1]);
				write(1, "\n", 1);
				return (0);
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
