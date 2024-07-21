/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:45:17 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/24 15:06:58 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid(char c, int base)
{
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	while (base--)
	{
		if (c == lower[base] || c == upper[base])
			return (1);
	}
	return (0);
}

int	value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	m;
	int	r;

	i = 0;
	m = 1;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	while (valid(str[i], str_base))
		r = r * str_base + value(str[i++]);
	return (r * m);
}
