/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:55:55 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 18:14:39 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		if (a > 0 && b > 0)
		{
			while (a != b)
			{
				if (a > b)
					a = a - b;
				else
					b = b - a;
			}
			printf("%d", a);
		}
	}
	printf("\n");
	return (0);
}
