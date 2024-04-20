/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:22:37 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 00:33:25 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
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
			if (av[2][j++] == av[1][i])
				i++;
			if (!av[1][i])
			{
				ft_putstr(av[1]);
				//i = 0;	
				break ;
			}
		}
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
