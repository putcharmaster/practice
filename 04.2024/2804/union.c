/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:38:06 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 22:51:30 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *str, char c, int n)
{
	int	i;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	start;

	start = 0;
	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[1][i])
			i++;
		while (av[2][j])
			av[1][i++] = av[2][j++];
		while (start < i)
		{
			if (!check(av[1], av[1][start], start))
				write(1, &av[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
