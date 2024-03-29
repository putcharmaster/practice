/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:40:53 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/29 15:09:42 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_spec(const char s, va_list ap)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += ft_char(va_arg(ap, int));
	if (s == 's')
		len += ft_str(va_arg(ap, char *));
	if (s == 'd' || s == 'i')
		len += ft_int(va_arg(ap, int));
	if (s == 'u')
		len += ft_unsingned(va_arg(ap, unsigned int));
	if (s == 'p')
		len += ft_void(va_arg(ap, void *));
	if (s == 'x' || s == 'X')
		len += ft_hexa(va_arg(ap, unsigned long long));
	if (s == '%')
		len += ft_char('%');
	return (len);

}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	len;
	int	i;

	len = 0;
	i = 0;
	va_start(ap, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			len += check_spec(str[i + 1], ap);
			i++;
		}
		else
			len += ft_char(str[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
