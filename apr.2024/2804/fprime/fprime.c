/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:33:59 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 22:37:37 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	n;
	int	i;

	if (ac == 2)
	{
		n = atoi(av[1]);
		i = 2;
		while (n >= i)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (n == i)
					break ;
				printf("*");
				n /= i;
				i = 1;
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
