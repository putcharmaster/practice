/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:08:39 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/23 10:12:45 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	num;

	if (ac == 2)
	{
		i = 2;
		num = atoi(av[1]);
		if (num == 1)
			printf("1");
		while (num >= i)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				if (num == i)
					break;
				printf("*");
				num /= i;
				i = 1;
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
