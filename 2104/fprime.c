/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 01:06:16 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 01:33:19 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	n;

	i = 2;
	n = atoi(av[1]);
	if (ac == 2)
	{
		if (n == 1)
			printf("1");
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
