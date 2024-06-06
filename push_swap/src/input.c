/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:20:11 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/06 12:30:05 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int     out_of_int(char **split)
{
    int	i;
	long n;

	i = 0;
	while (split[i])
	{
		n = ft_atol(split[i]);
		if (n > (int)2147483647 || n < (int)-2147483648)
		{
			free_av(split);
			return (1);
		}
		i++;
	}
	free_av(split);
	return (0);
}
int	int_range(char **av)
{
	int		i;
	char 	**split;

	i = 1;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		if (split == NULL || out_of_int(split))
			return (0);
		i++;
	}
	return (1);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-' || c == ' ');
}

int	valid_input(int ac, char **input)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!int_range(input))
		return (0);
	while (i < ac)
	{
		j = 0;
		while (input[i][j])
		{
            
			if (!is_digit(input[i][j]))
			{
				if (is_sign(input[i][j]) && (!is_digit(input[i][j + 1]) || input[i][j + 1] == '\0'))
					return (0);
				if (!is_sign(input[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
