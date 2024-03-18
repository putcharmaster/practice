/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:56:08 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/17 16:59:11 by sanhwang         ###   ########.fr       */
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
	while(i < len)
	{
		if (r < tab[i])
			r = tab[i];
		i++;
	}
	return (r);
}
