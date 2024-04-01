int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	format(const char *str, int i, va_list arg)
{
	int	len;

	len = 0;
	if (str[i] == 's')
		len = ft_print_str(va_arg(arg, char *));
	else if (str[i] == 'c')
		len = ft_print_char(va_arg(arg, int));
	else if (str[i] == 'p')
		len = put_ptr((void *)va_arg(arg, void *));
	else if (str[i] == 'd' || str[i] == 'i')
		len = ft_print_nbr(va_arg(arg, int));
	else if (str[i] == 'u')
		len = ft_print_unsigned_nbr(va_arg(arg, unsigned int));
	else if (str[i] == 'X')
		len = ft_print_hex(va_arg(arg, unsigned int), 'X');
	else if (str[i] == 'x')
		len = ft_print_hex(va_arg(arg, unsigned int), 'x');
	else if (str[i] == '%')
		len = ft_print_char('%');
	i++;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	len;
	int	i;
	va_list arg;

	len = 0;
	i = 0;
	va_start(arg, str);
	while(str[i])
	{
		if(str[i] == '%')
			len += format(str, ++i, arg);
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}
