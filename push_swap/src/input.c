/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:45:58 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/18 14:06:01 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	out_of_int(long input)
{
	return (input > 2147483647 || input < -2147483648);
}

static int	is_not_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	input_check(int ac, char **av)
{
	int		i;
	int		j;
	long	num;
	char	**input;

	i = 1;
	while (i < ac)
	{
		input = ft_split(av[i], ' ');
		j = 0;
		while (input[j])
		{
			num = ft_atol(input[j]);
			if (is_not_digit(input[j]) || out_of_int(num))
			{
				free_av(input);
				return (0);
			}
			j++;
		}
		free_av(input);
		i++;
	}
	return (1);
}
