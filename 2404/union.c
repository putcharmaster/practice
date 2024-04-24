/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:38:36 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/24 23:56:58 by sanhwang         ###   ########.fr       */
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
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (ac == 3)
	{
		while (av[1][i])
			i++;
		while (av[2][j])
			av[1][i++] = av[2][j++];
		while (k < i)
		{
			if (!check(av[1], av[1][k], k))
				k++;
			else
				write(1, &av[1][k++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					if (check(av[1],  av[1][i], i))
						i++;
					else
						write(1, &av[1][i++], 1);
				}
				j;
			}
			j = 0;
			i++;
		}
	}
	write(1, "/n", 1);
	return (0);
}
*/
