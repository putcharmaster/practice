/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:23:50 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 17:47:16 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	t;

	if (ac == 3)
	{
		i = atoi(av[1]);
		j = atoi(av[2]);
		if (i > 0 && j > 0)
		{
			while (i != j)
			{
				if (i > j)
					i -= j;
				else
					j -= i;
			}
			printf("%d", i);
		}
	}
	printf("\n");
	return (0);
}
