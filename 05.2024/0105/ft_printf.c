#include <unistd.h>
#include <stdarg.h>

void	putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	putnr(long long int n, int base, int *len)
{
	char	*r;

	r = "0123456789abcdef";
	if (n < 0)
	{
		n *= -1;
		*len += write(1, "-", 1);
	}
	if (n >= base)
		putnr((n / base), base, len);
	*len += write(1, &r[n & base], 1);
}

int	ft_printf(const char *format, ...)
{
	int	len = 0;

	va_list ptr;
	va_start(ptr, format);

	while (*format)
	{
		if ((*format == '%') &&
		((*(format + 1) == 's') || (*(format + 1) == 'd')
		 || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				putstr(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				putnr((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				putnr((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}
