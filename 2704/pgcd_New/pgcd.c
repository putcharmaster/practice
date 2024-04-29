/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:56:19 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 13:03:05 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 3)
	{
		i = atoi(av[1]);
		j = atoi(av[2]);
		if (j > 0 && j > 0)
		{
			while(i != j)
			{
				if (i < j)
					j -= i;
				else
					i -= j;
			}
			printf ("%d", i);
		}
	}
	printf("\n");
	return (0);
}
