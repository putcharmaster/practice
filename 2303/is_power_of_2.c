/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:28:47 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/23 19:45:52 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	return(n > 0 && !(n & (n - 1))
}

/*
 For example, consider the binary representation of 4 (which is 2^2):

n = 4 in binary is 100.
n - 1 = 3 in binary is 011.
n & (n - 1) = 100 & 011 = 000 = 0.
This operation returns 0 because there is only one 1-bit in the binary representation of 4, indicating that 4 is a power of 2.
*/

int	is_power_of_2(unsigned int n)
{
	if (n <= 0)
		return (0);
	while (n % 2 == 0)
		n = n / 2;
	if (n == 1)
		return (1);
	else
		return (0);
}
