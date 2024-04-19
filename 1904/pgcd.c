/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:34:05 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/19 13:44:49 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
		r = r * 10 + str[i++] - '0';
	return (r);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 3)
	{
		i = ft_atoi(av[1]);
		j = ft_atoi(av[2]);
		if (i > 0 && j > 0)
		{
			while (i != j)
			{
				if (i > j)
					i -= j;
				else
					j -= i;
			}
			printf("%d", i);
		}
	}
	printf("\n");
	return (0);
}
