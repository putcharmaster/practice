/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:45:36 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/25 21:05:09 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_string(char *args, int *len)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (args[i])
	{
		ft_putchar_len(args[i], len);
		i++;
	}
}

void	ft_nbr_len(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_len('-', len);
		ft_nbr_len(n * -1, len);
	}
	else
	{
		if (n > 9)
			ft_nbr_len(n / 10, len);
		ft_putchar_len(n % 10 + '0', len);
	}
}

void	ft_pointer(size_t pointer, int *len)
{
	char	str[25];
	char	*base_char;
	int		i;

	base_char = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (pointer == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (pointer)
	{
		str[i] = base_char[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

void	ft_hexa(unsigned int x, int *len, char x_X)
{
	char	str[25];
	char	*base_char;
	int		i;

	if (x_X == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (x)
	{
		str[i] = base_char[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

void	ft_unsigned_int(unsigned int ui, int *len)
{
	if (ui >= 10)
		ft_unsigned_int(ui / 10, len);
	ft_putchar_len(ui % 10 + '0', len);
}

static void	ft_printf_checker(char s, va_list *args, int *len, int *i)
{
	if (s == 's')
		ft_string(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_nbr_len(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexa(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
                ft_hexa(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_checker(str[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}

