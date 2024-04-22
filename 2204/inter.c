/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:26:04 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 13:38:48 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checker(char *str, char c, int n)
{
	int	i;

	i = 0;
	while (str[i] && (i < n || n == -1))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return(0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!checker(av[1], av[1][i], i)
				|| checker(av[2], av[1][i], -1))
					write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
