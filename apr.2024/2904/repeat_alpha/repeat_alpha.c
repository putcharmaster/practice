/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:17:29 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 19:25:12 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar_n(char c, int n)
{
	while (n--)
		write(1, &c, 1);
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
			{
				putchar_n(av[1][i], av[1][i] - 'a' + 1);
				i++;
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				putchar_n(av[1][i], av[1][i] -'A' + 1);
				i++;
			}
			else
				write(1, &av[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
