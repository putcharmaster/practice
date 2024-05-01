/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:08:18 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 16:38:04 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				flag = 1;
			else
			{
				if (flag)
					write(1, " ", 1);
				flag = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
int	main(int ac, char **av)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
			{
				flag = 1;
			}
			else
			{
				if (flag == 1)
					write(1, " ", 1);
				flag = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 2)
	{
		i = 0;
		j = 1;
		while (av[j][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[j][i])
		{
			while (av[j][i] == ' ' || av[j][i] == '\t')
			{
				if (av[j][i + 1] != ' ' && av[j][i + 1] != '\t'
					&& av[j][i + 1] != '\0')
					write(1, " ", 1);
				i++;
			}
			write(1, &av[j][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/
