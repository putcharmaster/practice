/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:32:45 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 23:56:32 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	print_bits(unsigned char octet)
{
	int	i;
	unsigned char r;

	i = 8;
	while (i--)
	{
		r = (octet >> i & 1) + '0';
	}
	return (r);
}

unsigned char	reverse_bits(unsigned char octet)
{
	return (((octet >> 0 & 1) << 7) |
		((octet >> 1 & 1) << 6) |
		((octet >> 2 & 1) << 5) |
		((octet >> 3 & 1) << 4) |
		((octet >> 4 & 1) << 3) |
		((octet >> 5 & 1) << 2) |
		((octet >> 6 & 1) << 1) |
		((octet >> 7 & 1) << 0));
}
/*
 *
unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char r;

	i = 8;
	while (i--)
	{
		r = r * 2 + (octet & 2);
		octet = octet / 2;
	}
	return (r);
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	r;
	int	i;

	i = 8;
	while (i--)
	{
		r = (r << 1) | (octet & 1);
		octet >>= 1;
	}
	return (r);
}
*/
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	unsigned char c = 0xab;

	printf("%d\n", print_bits(c));
	printf("%d\n", reverse_bits(c));
	printf("%d\n", swap_bits(c));
	return (0);
}
