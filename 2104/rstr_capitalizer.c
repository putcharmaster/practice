/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:25:09 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 23:43:31 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
	//	i = 0;
	//	j = 1;
		while (j < ac)
		{
			while (av[j][i])
			{
				if (av[j][i] >= 'A' && av[j][i] <= 'Z')
					av[j][i] = av[j][i] + 32;
				if ((av[j][i] >= 'a' && av[j][i] <= 'z')
					&& (av[j][i + 1] == ' '
					|| av[j][i + 1] == '\t'
					|| av[j][i + 1] == '\0'))
					av[j][i] = av[j][i] - 32;
				write(1, &av[j][i++], 1);
			}
			if (j == ac - 1)
				break ;
			else
			{
			write(1, "\n", 1);
			i = 0;
			j++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
