/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:20:01 by sanhwang          #+#    #+#             */
/*   Updated: 2024/07/21 22:07:17 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_nr(long long int nr, int base, int *len)
{
	char *hexa = "0123456789abcdef";

	if (nr < 0)
	{
		nr *= -1;
		*len += write(1, "-", 1);
	}
	if (nr >= base)
		put_nr(nr/base, base, len);
	*len += write(1, &hexa[nr%base], 1);
}

int	ft_printf(const char *format, ...)
{
	int	len;
	va_list ptr;

	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if ((*format == '%') && *(format + 1))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_nr((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				put_nr((long long int)va_arg(ptr, unsigned int), 16, &len);
		} 
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}
/*
#include <stdio.h>
int main()
{
	char *str = "hello";
	int i = 42;
	long long int j = 10;
	ft_printf("%s\n%d\n%x\n", str,i,j);
}
*/
