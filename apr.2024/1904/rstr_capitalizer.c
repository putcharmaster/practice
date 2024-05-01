/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:22:14 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/19 20:45:26 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& (str[i + 1] == ' ' || str[i + 1] == '\t'
				|| str[i + 1] == '\0'))
			str[i] -= 32;
		write(1, &str[i++], 1);
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < ac)
		{
			rstr_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
/*
///////////////////////////////// failed
int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac > 1)
	{
		while (av[i][j])
		{
			if ((av[i][j] >= 'A' && av[i][j] <= 'Z')
				&& av[i][j + 1] != ' ')
				av[i][j] = av[i][j] + 32;
			else if ((av[i][j] >= 'a' && av[i][j] <= 'z')
				&& av[i][j + 1] == ' ')
				av[i][j] = av[i][j] - 32;
			write(1, &av[i][j], 1);
			j++;
		}
	}
}
*/
