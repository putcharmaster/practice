/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:28:08 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/17 23:02:23 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
void	fprime(unsigned int nb)
{
	unsigned int	i;

	if (nb == 1)
		printf("1");
	else
	{
		i = 1;
		while (nb > 1)
		{
			if (nb % ++i == 0)
			{
				printf("%d", i);
				nb /= i;
				if (nb > 1)
					printf("*");
				i--;
			}
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
*/
///////////////////////////////////////////////

int	main(int ac, char **av)
{
	int	i;
	int	number;

	if (ac == 2)
	{
		i = 1;
		number = atoi(av[1]);
		if (number == 1)
			printf("1");
		while (number > 1)
		{
			if (number % ++i == 0)
			{
				printf("%d", i);
				nb /= i;
				if (number > 1)
					printf("*");
				i--;
			}
		}
	}
	printf("\n");
	return (0);
}
