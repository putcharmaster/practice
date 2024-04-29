/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:34:13 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 19:39:17 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	i;

	if (a > b)
		i = a;
	else
		i = b;
	if (!a || !b)
		return (0);
	while (1)
	{
		if (i % a == 0 && i % b == 0)
			return (i);
		i++;
	}
}

#include <stdio.h>
int	main(int ac, char **av)
{
	unsigned int a= 2;
	unsigned int b = 5;
	printf("%d", lcm(a, b));
}
