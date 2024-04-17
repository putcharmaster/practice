/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:47:50 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/17 15:07:57 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int	*tab, unsigned int len)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	if (!tab || !len)
		return (0);
	while(i < len)
	{
		max = tab[0];
		if(max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

#include <stdio.h>

int	main()
{
	int tab[] = {55, 4, 2, 3, 0};
	unsigned int len = sizeof(tab) / sizeof(tab[0]);

	printf("%d", max(tab, len));
}
