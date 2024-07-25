#include <unistd.h>
#include <stdarg.h>

void	putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	putnr(long long int n, int b, int *len)
{
	char	*h = "0123456789abcdef";

	if (n < 0)
	{
		n *= -1;
		*len += write(1, "-", 1);
	}
	if (n >= b)
		putnr(n/b, b, len);
	*len += write(1, &h[n%b], 1);
}

int	ft_printf(char *s, ...)
{
	int	len = 0;
	va_list	p;
	va_start(p, s);
	while (*s)
	{
		if (*s == '%' && *(s+1))
		{
			s++;
			if (*s == 's')
				putstr(va_arg(p, char *), &len);
			else if (*s == 'd')
				putnr((long long int)va_arg(p, int), 10, &len);
			else if (*s == 'x')
				putnr((long long int)va_arg(p, unsigned int), 16, &len);
		}
		else
			len += write(1, s, 1);
		s++;
	}
	return(va_end(p), len);
}
