/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:08:07 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/30 16:22:16 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	recursive_int(int n)
{
	char	*digit;

	digit = "0123456789";
	if (n > 9)
		recursive_int(n / 10);
	write(1, &digit[n % 10], 1);
}

int	ft_int(int n)
{
	int	r;

	r = n_len(n);
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	recursive_int(n);
	return (r);
}

int	ft_ui(unsigned int n)
{
	char	*digit;

	digit = "0123456789";
	if (n > 9)
		ft_ui(n / 10);
	write(1, &digit[n % 10], 1);
	return (ui_len(n));
}
