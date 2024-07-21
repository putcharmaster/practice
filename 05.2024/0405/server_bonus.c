/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:20:31 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/07 14:38:07 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_handler(int sign, siginfo_t *info, void *context)
{
	static int	c;
	static int	bit;
	static int	pid;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	if (sign == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (!c)
		{
			kill (pid, SIGUSR1);
			pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	kill (info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	simple_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
