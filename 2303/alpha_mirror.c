/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:46:44 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/23 19:57:31 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while(av[1][i])
		{
			if(av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = 'z' - av[1][i] + 'a';
			else if(av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = 'Z' - av[1][i] + 'A';
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
