/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:53:19 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/26 13:32:42 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	sta;
	int	end;

	i = 0;
	if (ac > 1)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		sta = i;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			i++;
		end = i;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		if(av[1][i])
		{
			while (av[1][i])
			{
				if (av[1][i] == ' ' || av[1][i] == '\t')
				{
					while (av[1][i] == ' ' || av[1][i] == '\t')
						i++;
					if (av[1][i])
						write(1, " ", 1);
				}
				else
					write(1, &av[1][i++], 1);
			}
			write(1, " ", 1);
		}
		while (sta < end)
			write(1, &av[1][sta++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
