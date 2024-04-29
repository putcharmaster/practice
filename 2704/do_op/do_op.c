/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:22:16 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 14:31:07 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 4)
	{
		i = atoi(av[1]);
		j = atoi(av[3]);
		if (av[2][0] == '+')
			return (printf("%d\n", i + j));
		if (av[2][0] == '-')
			return (printf("%d\n", i - j));
		if (av[2][0] == '*')
			return (printf("%d\n", i * j));
		if (av[2][0] == '/')
			return (printf("%d\n", i / j));
		if (av[2][0] == '%')
			return (printf("%d\n", i % j));
	}
	printf("\n");
	return (0);
}
