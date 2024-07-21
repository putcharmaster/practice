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
	char	*h = "0123456789abcdef";

	if (n < 0)
	{
		n *= -1;
		*len += write(1, "-", 1);
	}
	if (n >= base)
		putnr(n/base, base, len);
	*len += write(1, &h[n%base], 1);
}

int	ft_printf(char *f, ...)
{
	int	len;
	va_list	ptr;

	len = 0;
	va_start(ptr, f);
	while (*f)
	{
		if (*f == '%' && *(f+1))
		{
			f++;
			if(*f == 's')
				putstr(va_arg(ptr, char *), &len);
			else if (*f == 'd')
				putnr((long long int)va_arg(ptr, int), 10, &len);
			else if (*f == 'x')
				putnr((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, f, 1);
		f++;
	}
	return (va_end(ptr), len);
}
