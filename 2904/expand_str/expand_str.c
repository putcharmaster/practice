/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:29:19 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 18:40:20 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	if (ac == 2)
	{
		i = 0;
		j = 1;
		while (j < ac)
		{
			while (av[j][i] < 33)
				i++;
			while (av[j][i])
			{
				if (av[j][i] && av[j][i] < 33)
				{
					while (av[j][i] && av[j][i] < 33)
						i++;
					if (av[j][i])
						write(1, "   ", 3);
				}
				else
					write(1, &av[1][i++], 1);
			}
			if (j < ac - 1)
				write(1, "\n", 1);
			i = 0;
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
