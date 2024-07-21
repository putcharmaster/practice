/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:07:07 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 01:24:58 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//////////failed one


int	ft_strchr(char *str, char c, int n)
{
	int i;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

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
			j = 0;
			while (av[2][j])
			{
				if (av[2][j] == av[1][i])
				{
					if(ft_strchr(av[1], av[1][i], i))
						write(1, &av[1][j], 1);
					break ;
				}
				j++;
			}	
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
