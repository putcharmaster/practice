/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:26:34 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/18 23:35:17 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_valid(char c, int base)
{
	char	*l_digits;
	char	*u_digits;

	l_digits = "0123456789abcdef";
	u_digits = "0123456798ABCDEF";
	while (base--)
		if (l_digits[base] == c || u_digits[base] == c)
			return (1);
	return (0);
}

int	ft_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	r;
	int	m;

	r = 0;
	m = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		str++;
	}
	while (ft_valid(str[i], base))
		r = r * base + ft_value(str[i++]);
	return (r * m);
}

#include <stdio.h>
int main()
{
  char str[] = "13";
  int base = 16;
  printf("%d", ft_atoi_base(str, base));

  }
