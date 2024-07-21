/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:52:14 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/18 16:42:15 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_isblank(char c)
{
	if (c < 33)
		return (1);
	return (0);
}

int	ft_isvalid(char c, int base)
{
	char digit_s[17] = "0123456789abcdef";
	char digit_b[17] = "0123456789ABCDEF";

	while(base--)
		if (digit_s[base] == c || digit_b[base] == c)
			return (1);
	return (0);
}

int	ft_value(char c)
{
	if(c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int base)
{
	int	r;
	int	m;

	r = 0;
	m = 1;
	while(ft_isblank(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if(*str == '-')
			m = -m;
		str++;
	}
	while(ft_isvalid(*str, base))
		r = r * base + ft_value(*str++);
	return (r * m);	
}
