/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:03:45 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 01:19:50 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	i;

	if (!a || !b)
		return (0);
	if (a < b)
		i = b;
	else
		i = a;
	while (1)
	{
		if (i % a == 0 && i % b == 0)
			return (i);
		i++;
	}
}
