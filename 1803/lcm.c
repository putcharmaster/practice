/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:22:20 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/18 18:28:08 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	if(a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while(1)
	{
		if(n % a == 0 || n % b == 0)
			return (n);
		n++;
	}
}
