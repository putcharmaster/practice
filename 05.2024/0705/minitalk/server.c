/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:03:12 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/06 12:28:35 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	simple_putnbr(int n)
{
	char	*r;

	r = "0123456789";
	if (n > 9)
		simple_putnbr(n / 10);
	write(1, &r[n % 10], 1);
}

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static int	i;
	static int	bit;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		i = i | (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		i = 0;
		bit = 0;
	}
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
