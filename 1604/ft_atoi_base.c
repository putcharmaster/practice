/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:44:23 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 15:03:39 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	ft_isvalid(char c, int base)
{
	char	*digit_l;
	char	*digit_u;

	digit_l = "0123456789abcdef";
	digit_u = "0123456789ABCDEF";
	while(base--)
		if (digit_l[base] == c || digit_u[base] == c)
			return (1);
	return (0);
}

int	ft_valueof(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (ft_isblank(*str))
		str++;
	if(*str == '-')
		sign = -1;
	if(*str == '-' || *str '+')
		str++;
	while(ft_isvalid(*str, str_base))
		res = res * str_base + ft_valueof(*str++);
	return (res * sign);
}
