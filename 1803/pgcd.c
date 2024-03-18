/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:42:21 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/18 18:52:25 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	nr1;
	int	nr2;

	if (ac == 3)
	{
		if((nr1 = atoi(av[1])) > 0 && (nr2 = atoi(av[2]) > 0))
		{
			while(nr1 != nr2)
			{
				if(nr1 > nr2)
					nr1 = nr1 - nr2;
				else
					nr2 = nr2 - nr1;
			}
			printf("%d", nr1);
		}
			
	}
	printf("\n");
	return (0);
}
