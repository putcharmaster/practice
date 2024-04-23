/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:59:48 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/23 10:01:35 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	i;

	if (!a || !b)
		return (0);
	if (a > b)
		i = a;
	else
		i = b;
	while (1)
	{
		if (i % a == 0 && i % b == 0)
			return (i);
		i++;
	}
}
