/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:27:45 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/28 17:58:09 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

size_t	n_len(int n)
{
	size_t len;

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

void	recursive_int(int n)
{
	char	*digit;

	digit = "0123456789";
	if(n > 9)
		recursive_int(n / 10);
	write(1, &digit[n % 10], 1);
}

int	ft_int(int n)
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
	recursive_int(n);
	return (n_len(n));
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
	if(n > 9)
		ft_ui(n / 10);
	write(1, &digit[n % 10], 1);
	return (ui_len(n));
}

size_t	hexa_len(unsigned long long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	recursive_hexa(unsigned long long ptr)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if(ptr >= 16)
		recursive_hexa(ptr / 16);
	write(1, &hexa[ptr % 16], 1);
}

int	ft_void(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "ox", 2);
	recursive_hexa((unsigned long long)ptr);
	return (hexa_len((unsigned long long)ptr));
}

int	ft_hexa(unsigned long long n, const char Xx)
{
	char	*upper;
	char	*lower;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	if (n >= 16)
		ft_hexa(n / 16, Xx);
	if (Xx == 'X')
		write (1, &upper[n % 16], 1);
	else if (Xx == 'x')
		write(1, &lower[n % 16], 1);
	return (hexa_len(n));
}

int	ft_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
	{
		ft_str("(null)");
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

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
		len += ft_ui(va_arg(ap, unsigned int));
	if (s == 'x' || s == 'X')
		len += ft_hexa(va_arg(ap, unsigned long long), s);
	if (s == 'p')
		len += ft_void(va_arg(ap, void *));
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


#include <stdio.h>

int	main()
{
	int	integer = 50;
	char	letter = 'a';
	char	*str = "abcdef";
	int	*ptr = 65132;
	unsigned int	uint = 5500;
	ptr = (void *)ptr;
	ft_printf("\nTEST 1:\n");
	ft_printf("*****FT_PRINTF*****\n");
	ft_printf("test char %c\ntest str %s\ntest ptr %p\ntest unsigned %u\ntest int %i, %d\ntest hexa %x, %X, %%\n\n", letter, str, ptr, uint, integer, integer, uint, uint);
	ft_printf("*****ST_PRINTF*****\n");
	printf("test char %c\ntest str %s\ntest ptr %p\ntest unsigned %u\ntest int %i, %d\ntest hexa %x, %X, %%\n\n", letter, str, ptr, uint, integer, integer, uint, uint);
	ft_printf("----------------------------\n\n");

	integer = -50;
	letter = "test";
	str = "yeah";
	ptr = "dfghhf";
	uint = -5500;
	ft_printf("TEST 2:\n");
	ft_printf("*****FT_PRINTF*****\n");
	ft_printf("test char %c\ntest str %s\ntest ptr %p\ntest unsigned %u\ntest int %i, %d\ntest hexa %x, %X, %%\n\n", letter, str, ptr, uint, integer, integer, uint, uint);
	ft_printf("*****ST_PRINTF*****\n");
	printf("test char %c\ntest str %s\ntest ptr %p\ntest unsigned %u\ntest int %i, %d\ntest hexa %x, %X, %%\n", letter, str, ptr, uint, integer, integer, uint, uint);

	ft_printf("\nTEST 3:\n");
	ft_printf("*****FT_PRINTF*****\n");
	ft_printf("%c\n", '0');
	ft_printf(" %c\n", '0' - 256);
	ft_printf(" %d \n", -15);
        ft_printf(" %i \n", -15);
	ft_printf("*****ST_PRINTF*****\n");
	printf("%c\n", '0');
	printf(" %c\n", '0' - 256);
	printf(" %d \n", -15);
	printf(" %i \n", -15);
	ft_printf("----------------------------\n\n");

	ft_printf("\nTEST 4:\n");
	ft_printf("*****FT_PRINTF*****\n");
	ft_printf("%s\n", "");
	ft_printf(". .%s.\n", "");
	ft_printf("%c%c%c*\n", '\0', '1', 1);
	ft_printf("%c\n", 'a');
	ft_printf("%c\n", '0');
	ft_printf(" %p %p \n", 0, 0);
	ft_printf("*****ST_PRINTF*****\n");
	printf("%s\n", "");
	printf(". .%s.\n", "");
	printf("%c%c%c*\n", '\0', '1', 1);
	printf("%c\n", 'a');
	printf("%c\n", '0');
	printf(" %p %p \n", 0, 0);
	ft_printf("----------------------------\n\n");

	return 0;
}
