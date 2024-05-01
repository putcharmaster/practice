/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:58:57 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 23:09:47 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	int	i;
	i = 0;
	while(str[i])
	{
		write(1, &str[i++], 1);
	}
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
			if (av[2][j] == av[1][i])
			{
				j++;
				i++;
			}
			if (!av[1][i])
			{
				putstr(av[1]);
				write(1, "\n", 1);
				return (0);
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
