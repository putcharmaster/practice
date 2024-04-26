/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:59:28 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/26 15:17:42 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	a;

	a = 1;
	i = 0;
	if (ac > 1)
	{
		while (a < ac)
		{
			while (av[a][i])
			{
				if(av[a][0] >= 'a' && av[a][0] <= 'z')
					av[a][0] -= 32;
				else if (av[a][i] >= 'A' && av[a][i] <= 'Z' && i!= 0 
						&& !(av[a][i - 1] == ' ' || av[a][i - 1] == '\t'))
					av[a][i] += 32;
				else if ((av[a][i] >= 'a' && av[a][i] <= 'z')
					&& av[a][i - 1] == ' ' || av[a][i - 1] == '\t')
					av[a][i] -= 32;
				write(1, &av[a][i++], 1);
			}
			write(1, "\n", 1);
			i = 0;
			a++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
