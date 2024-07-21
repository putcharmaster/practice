/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:48:34 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 20:56:59 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	n1;
	int	n2;

	n1 = atoi(av[1]);
	n2 = atoi(av[2]);
	if (ac == 3)
	{
		if(n1 > 0 && n2 > 0)
		{
			while (n1 != n2)
			{
				if (n1 > n2)
					n1 = n1 - n2;
				else
					n2 = n2 - n1;
			}
			printf("%d", n1);
		}
	}
	printf("\n");
	return (0);
}
