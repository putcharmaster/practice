/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:06:19 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 12:19:44 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	start = 0;
	int	end = 0;
	
	if (ac > 1)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		start = i;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			i++;
		end = i;
		while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		if (av[1][i]) //important+
		{
			while (av[1][i])
			{
				if (av[1][i] && av[1][i] == ' ' || av[1][i] == '\t')
				{
					while (av[1][i] == ' '|| av[1][i] == '\t')
						i++;
					if (av[1][i]) //important
						write(1, " ", 1);
				}
				else // this is important
					write(1, &av[1][i++], 1);
			}
			write(1, " ", 1);
		}
		while (start < end)
			write(1, &av[1][start++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
