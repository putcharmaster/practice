/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 00:06:26 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 00:10:22 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i--)
	{
		r = r * 2 + (octet % 2);
		octet = octet / 2;
	}
	return (res);
}
