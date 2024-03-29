/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:34:16 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/28 22:16:39 by sanhwang         ###   ########.fr       */
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
			i++;
		while(av[1][i] <= 32)
			i--;
		while(av[1][i] > 32)
			i--;
		i++;
		while(av[1][i] > 32)
			write(1, &av[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}

/*
////////////////////////////failed vers.//////////////////////////////
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		while (i >= 0 && av[1][i] == ' ' || av[1][i] == '\t')
			i--;
		while (i >= 0 && av[1][i])
		{
			i--;
			j++;
			if (av[1][i - 1] == ' ' || av[1][i - 1] == '\t')
				
		}		
	}
	write(1, "\n", 1);
	return (0);
}
*/
