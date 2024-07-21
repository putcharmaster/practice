/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:30:52 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 21:13:14 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	retur (0);
}

int	valid(char c, int base)
{
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	while (base--)
		if (lower[base] == c || upper[base] == c)
			return (1);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	r;
	int	m;

	i = 0;
	r = 0;
	m = 1;
	while (str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	while (valid(str[i], str_base))
		r = r * str_base + ft_value(str[i++]);
	return (r * m);
}
