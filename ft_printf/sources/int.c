/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:16:29 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/30 15:38:55 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	n_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	r_int(int n)
{
	char	*digit;

	digit = "0123456789";
	if (n > 9)
		r_int(n / 10);
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
	r_int(n);
	return (r);
}

size_t	ui_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
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
