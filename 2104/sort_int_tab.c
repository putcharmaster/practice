/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:51:08 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 00:55:36 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = tab[i];
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tab[i];
			i = 0;
		}
		else
			i++;
	}
}
