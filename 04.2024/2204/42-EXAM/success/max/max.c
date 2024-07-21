/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:15:34 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 19:22:48 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	int	i;
	int	m;

	if (len == 0)
		return (0);
	i = 0;
	m = tab[i];
	while (i < len)
	{
		if (m < tab[i])
			m = tab[i];
		i++;
	}
	return (m);
}
