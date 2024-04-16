/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:59:21 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 14:09:19 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
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
				i = 0;
			}
		}
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
