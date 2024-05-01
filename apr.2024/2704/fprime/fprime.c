/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:44:41 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 22:48:45 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	n;
	int	i;

	if (ac == 2)
	{
		n = atoi(av[1]);
		i = 2;
		if (n == 1)
			printf("1");
		while (n >= i)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (n == i)
					break;
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
