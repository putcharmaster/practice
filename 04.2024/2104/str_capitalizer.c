/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:45:14 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 00:06:37 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
}

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
		while (j < ac)
		{
			if ((is_char(av[j][i]) == 1))
				av[j][i] -= 32;
			write(1, &av[j][i++], 1);
			while (av[j][i])
			{
				if ((is_char(av[j][i])) == 2)
					av[j][i] = av[j][i] + 32;
				if ((is_char(av[j][i])) == 1
					&& (av[j][i - 1] == ' '
					|| av[j][i - 1] == '\t'))
					av[j][i] = av[j][i] - 32;
				write(1, &av[j][i++], 1);

			}
			if (j == ac - 1)
				break ;
			write(1, "\n", 1);
			i = 0;
			j++;
		}
	}
}
