/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:45:28 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/03 15:21:23 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	simple_atoi(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
		r = r * 10 + str[i++] - '0';
	return (r);
}

void	ft_ctob(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		pid = simple_atoi(av[1]);
		while (av[2][i])
			ft_ctob(pid, av[2][i++]);
		ft_ctob(pid, '\0');
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
