/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:07:10 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/23 10:08:23 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	if (len == 0)
		return (0);

	unsigned int	r;
	unsigned int	i;

	i = 0;
	r = tab[i];
	while (i < len)
	{
		if (r < tab[i])
			r = tab[i];
		i++;
	}
	return (r)
}
