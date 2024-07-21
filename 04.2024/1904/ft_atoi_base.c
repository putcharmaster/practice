/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:12:09 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/19 12:51:22 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_valid(char c, int base)
{
	char	*upper;
	char	*lower;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	while (base--)
		if (upper[base] == c || lower[base] == c)
			return (1);
	return (0);
}

int	int_value(char c)
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
	while (ft_valid(str[i], str_base))
		r = r * str_base + int_value(str[i++]);
	return (r * m);
}

#include <stdio.h>
int main()
{
  char str[] = "a";
  int base = 16;
  printf("%d", ft_atoi_base(str, base));

  }

