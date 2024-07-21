/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:13:58 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/15 14:44:18 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fizbuz()
{
	int	i;
	char	j;
	char	k;

	i = 1;
	while(i < 100)
	{
		j = i % 10 + '0';
		k = i / 10 + '0';
		if(i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if(i % 3 == 0)
			write(1, "fizz", 4);
		else if(i % 5 == 0)				
			write(1, "buzz", 4);
		else
		{
			if(i < 10)
				write(1, &j, 1);
			else if(i > 9)
			{
				write(1, &j, 1);
				write(1, &k, 1);
			}
		}	
		i++;
		write(1, "\n", 1);
	}
}


int	main()
{
	fizbuz();
	return (0);
}
