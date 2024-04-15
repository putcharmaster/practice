/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:40:11 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/15 23:45:36 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	if (n == 1)
		return 1;
	else
		return 0;
}

int		is_power_of_2(unsigned int n)
{
    return (n > 0 && !(n & (n - 1)));
}


#include <stdio.h>
int	main()
{
	printf(
}
