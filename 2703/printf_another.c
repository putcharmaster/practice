#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

size_t	nbrlen(int n)
{
	size_t	len;

	len = 0;
	if(n <= 0)
		len++;
	while(n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	put_int(int n)
{
	char	*digits;

	digits = "0123456789";
	if (n > 9)
		put_int(n / 10);
	write(1, &digits[n % 10], 1);
}

int	ft_printnbr(int n)
{
	int	len;
	
	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	put_int(n);
	return(nbrlen(n));
}

size_t	n_len(unsigned int n)
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

int	ft_printunsigned(unsigned int n)
{
	char	*digits;

	digits = "0123456789";
	if (n > 9)
		ft_printunsigned(n / 10);
	write(1, &digits[n % 10], 1);
	return (n_len(n));
}

size_t	ptrlen(unsigned long long n)
{
	size_t	len;

	len = 0;
	if(n == 0)
		return (1);
	while(n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	putptr(unsigned long long ptr)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (ptr >= 16)
		putptr(ptr / 16);
	write(1, &hexa[ptr % 16], 1);
}

int	ft_printptr(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	putptr((unsigned long long)ptr);
	return (ptrlen((unsigned long long)ptr));
}

size_t	hexalen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while(n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_printhexa(unsigned int n, const char Xx)
{
	char	*upper;
	char	*lower;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";

	if (n >= 16)
		ft_printhexa(n / 16, Xx);
	if (Xx == 'X')
		write(1, &upper[n % 16], 1);
	else if (Xx == 'x')
		write(1, &lower[n % 16], 1);
	return (hexalen(n));
}


int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	checkstr(const char s, va_list args)
{
	int	count;

	count = 0;
	if (s == '%')
		count += ft_printchar('%');
	if (s == 'c')
		count += ft_printchar(va_arg(args, int));
	if (s == 's')
		count += ft_printstr(va_arg(args, char *));
	if (s == 'd' || s == 'i')
		count += ft_printnbr(va_arg(args, int));
	if (s == 'u')
		count += ft_printunsigned(va_arg(args, unsigned int));
	if (s == 'p')
		count += ft_printptr(va_arg(args, void *));
	if (s == 'x' || s == 'X')
		count += ft_printhexa(va_arg(args, unsigned int), s);
	return (count);

}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	count;
	int	i;

	count = 0;
	i = 0;
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += checkstr(str[i], args);
			i++;
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	main()
{
//	int c = 0;
	ft_printstr("haha working.");
}
