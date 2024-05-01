/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:34:40 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 13:42:32 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char 	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int is_power_of_2(unsigned int n)
{
	return (n > 0 && !(n & (n - 1)));
}
