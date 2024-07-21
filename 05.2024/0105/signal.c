https://medium.com/@oduwoledare/42-minitalk-explained-5b236adc2c24

the signal() doesn't block other signals from arriving WHILE the CURRENT handler is executing.
sigaction() CAN block other signals until the CURRENT handler returns.

signal() resets the signal action back to SIG_DFL(default) for almost all signals.
	this means signal() handler must reinstall itself as its first action.
	so it could be vulnerable for the time right before and when it gets reinstalled.
sigaction()
	sa_mask: indicated any signals that should be blocked while the signal handler is being executed.			signalaction masking.  like a masking tape.
	sa_flags: determines a number of different things.
			the most important ones are whether we get the extended information(SA_SIGINFO)
			and whether systhem calls that were interrupted by the signal are automatically
			restarted(SA_RESTART),
			the alternative is that the interrupted system calls will fail,
			so restarting them is obviously a better apporoach.

		//////	the sigaction function handler prototype/////
void	handle_prof_signal(int signal_number, siginfo_t *info, void *context);
	the signal number,	info about signal delivery,	info about the thread context

ex) H
|128| 64| 32| 16|  8|  4|  2|  1|
|  0|  1|  0|  0|  1|  0|  0|  0|
	
a process can send a signal with the kill or raise system call

int	kill(pidt pid, int signum);
int	raise(int signum);

asynchronous = there's no logic as to when the input comes. (unpredictable)












**************************************************************************************************
#include <sigio.h>
#include <unistd.h>
#include <signal.h>

//SIG_IGN: ignored
//sigaction
int	main()
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}

//signal
int	main()
{
	signal(SIGINT, SIG_IGN);
	while (1)
		sleep(1);
	return (0);
}


//caught
//sigaction
void	sig_handler(int signum, sigintfo_t* info, void* context)
{
	(void)context;
	(void)info;
	(void)signum;
	printf("\nSignal handler function called %d\n", signum);
}

int	main(void)
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGINT, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}

//signal
void	sig_handler(int signum)
{
	printf("\nSignal handler function called %d\n", signum);
}

int	main()
{
	signal(SIGINT, sig_handler);
	while (1)
		sleep(1);
	return (0);
}



//Default
//sigaction
int	main()
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_handler = SIG_DFL;
	sogaction(SIGINT, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}

//signal
int	main()
{
	signal(SIGINT, SIG_DFL);
	while (1)
		sleep(1);
	return (0);
}
