/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:16:52 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/26 19:20:55 by sanhwang         ###   ########.fr       */
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
		i = 2;
		n = atoi(av[1]);
		while (i <= n)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (i == n)
					break ;
				printf("*");
				n /= i;
				i = 1;
			}
			i++;
		}
	}
	printf("\n");
}
