/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:03:42 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 19:24:53 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;

	if (ac == 4)
	{
		if (av[2][0] == '+')
			i = atoi(av[1]) + atoi(av[3]);
		if (av[2][0] == '-')
			i = atoi(av[1]) - atoi(av[3]);
		if (av[2][0] == '*')
			i = atoi(av[1]) * atoi(av[3]);
		if (av[2][0] == '/')
			i = atoi(av[1]) / atoi(av[3]);
		if (av[2][0] == '%')
			i = atoi(av[1]) % atoi(av[3]);
		printf("%d", i);
	}
	printf("\n");
	return (0);
}
