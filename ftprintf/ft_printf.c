/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:15:43 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/22 17:37:22 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_hexa(unsigned long long n)
{
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
		ft_hexa(n / 16, 
}

int	ft_str(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (write(1, "(null)", 6));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	check_spec(const char s, va_list ap)
{
	int	len;

	len = 0;
	if (c == 's')
		len += ft_str(va_arg(ap, char *));
	if (c == 'd')
		len += ft_int(va_arg(ap, int));
	if (c == 'x')
		len += ft_hexa(va_arg(ap, unsigned long long));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
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
