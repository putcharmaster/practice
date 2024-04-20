/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:27:00 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 19:34:03 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	r;

	i = 0;
	m = 1;
	r = 0;
	while (str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		r = r * 10 + str[i++] - '0';
	return (m * r);
}

#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{

	if (ac == 2)
	{
		printf("ft_atoi:%d\n\n", ft_atoi(av[1]));
		printf("atoi;%d", atoi(av[1]));
	}
}
