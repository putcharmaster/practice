/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:28:37 by sanhwang          #+#    #+#             */
/*   Updated: 2024/07/21 16:36:04 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	whitespace_and_sign(const char *str, int *i, int *sign)
{
	while (str[*i] <= 32)
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

static int	char_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0.0;
	fraction = 1.0;
	whitespace_and_sign(str, &i, &sign);
	while (char_isdigit(str[i]))
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (char_isdigit(str[i]))
		{
			fraction /= 10.0;
			result += (str[i++] - '0') * fraction;
		}
	}
	return (result * sign);
}
