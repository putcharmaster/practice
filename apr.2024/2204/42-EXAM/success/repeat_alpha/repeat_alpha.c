/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:43:44 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 13:52:18 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchr(char c, int n)
{
	while (n >= 0)
	{
		write(1, &c, 1);
		n--;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				putchr(av[1][i], av[1][i] - 'a');
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				putchr(av[1][i], av[1][i] - 'A');
			else
				write(1, &av[1][i], 1);
			i++;
		}	
	}
	write(1, "\n", 1);
	return (0);
}
