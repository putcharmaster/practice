/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:54:38 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/16 21:09:14 by sanhwang         ###   ########.fr       */
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
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			m = -m;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * m);
}

#include <stdio.h>
int	main()
{
	printf("%d", ft_atoi("    -34"));
}
