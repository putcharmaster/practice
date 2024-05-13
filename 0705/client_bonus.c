/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:44:58 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/07 14:53:15 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	struct sigaction	sa;

	i = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	if (ac == 3 && (sigaction(SIGUSR1, &sa, NULL) != -1
			&& sigaction(SIGUSR2, &sa, NULL) != -1))
	{
		pid = simple_atoi(av[1]);
		while (av[2][i])
			ft_ctob(pid, av[2][i++]);
		ft_ctob(pid, '\0');
	}
	else
	{
		write(1, "Error\n" 6);
		return (1);
	}
	return (0);
}
