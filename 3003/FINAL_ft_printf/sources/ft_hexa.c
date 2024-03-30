/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:02:57 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/30 16:18:43 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	recursive_hexa(unsigned long long ptr)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (ptr >= 16)
		recursive_hexa(ptr / 16);
	write(1, &hexa[ptr % 16], 1);
}

int	ft_void(void *ptr)
{
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	recursive_hexa((unsigned long long)ptr);
	return (h_len((unsigned long long)ptr) + 2);
}

int	ft_hexa(unsigned long long n, const char Xx)
{
	char	*upper;
	char	*lower;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	if (n >= 16)
		ft_hexa(n / 16, Xx);
	if (Xx == 'X')
		write (1, &upper[n % 16], 1);
	else if (Xx == 'x')
		write(1, &lower[n % 16], 1);
	return (h_len(n));
}
