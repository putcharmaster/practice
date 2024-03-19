/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:35:23 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/19 09:56:46 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	nr;

	if (ac == 2)
	{
		i = 2;
		nr = atoi(av[1]);
		if (nr == 1)
			printf("1");
		while (nr > 1)
		{
			if (nr % i == 0)
			{
				printf("%d", i);
				if(nr == i)
					break;
				printf("*");
				nr = nr / i;
				
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}
