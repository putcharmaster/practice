/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:17:37 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 22:31:14 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	return (n > 0 && !(n & n - 1));
}


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac == 2)
    {
        printf("is power of 2 ?");
        is_power_of_2(atoi(av[1])) ? printf("Yes\n") : printf("No\n");
	printf("%d", is_power_of_2(atoi(av[1])));
    }
    return (0);
}
