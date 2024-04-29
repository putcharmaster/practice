/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:22:11 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 17:29:13 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	int i;
	i = 0;
	while (str[i])
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
		while (av[1][i])
		{
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					i++;
					j++;
					if (!av[1][i])
					{
						putstr(av[1]);
						write(1, "\n", 1);
						return (0);
					}
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
