/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:13:49 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/18 12:37:43 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char const **av)
{
	int	i;
	int	spc;

	if (ac == 2)
	{
		i = 0;
		while(av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while(av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				spc = 1;
			if (!(av[1][i] == ' ' || av[1][i] == '\t'))
			{
				if(spc)
					write(1, "   ", 3);
				spc = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
