/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:20:31 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/06 11:44:17 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putnbr_simple(int n)
{
	char	*r;

	r = "0123456789";
	if (n > 9)
		putnbr_simple(n / 10);
	write(1, &r[n % 10], 1);
}

void	sig_handler(int sign, siginfo_t *info, void *context)
{
	static int	c;
	static int	bit;

	(void)context;
	if (sign == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (!c)
		{
			kill (info->si_pid, SIGUSR1);
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
	sa.sa_flags = SA_START | SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "Error\n" 6);
		return (1);
	}
	putnbr_simple(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
