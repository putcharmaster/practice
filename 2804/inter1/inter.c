/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:12:55 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 23:17:59 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *str, char c, int n)
{
	int	i;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
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
					if (!check(av[1], av[1][i], i))
						write(1, &av[1][i], 1);
					break;
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
