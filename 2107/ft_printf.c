#include <unistd.h>
#include <stdarg.h>

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_nr(long long int n, int base, int *len)
{
	char *hexa = "0123456789abcdef";

	if (n < 0)
	{
		n *= -1;
		*len += write(1, "-", 1);
	}
	if (n >= base)
		put_nr(n/base, base, len);
	*len += write(1, &hexa[n%base], 1);
}

int	ft_printf(char *format, ...)
{
	int	len;
	va_list	ptr;

	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if(*format == '%' && *(format+1))
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
