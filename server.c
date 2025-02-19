#include "mini_talk.h" 

void handler(int sig, siginfo_t *siginfo, void *more_info)
{
    static int		i;
	static char		c;
	static pid_t	pid;

	(void)more_info;
	if (siginfo->si_pid != pid)
	{
		pid = siginfo->si_pid;
		i = 7;
		c = 0;
	}
	if (sig == SIGUSR1)
		c += 1 << i;
	i--;
	if (i == -1)
	{
		write(1, &c, 1);
		if (c == '\0')
			kill(siginfo->si_pid, SIGUSR2);
		i = 7;
		c = 0;
	}
	usleep(500);
	kill(siginfo->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction	s;

	ft_putstr_fd("SERVER PID == ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s.sa_sigaction = handler;
	s.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s, NULL) < 0 || sigaction(SIGUSR2, &s, NULL) < 0 )
    {
        ft_putstr_fd("Sigaction failed", 2);
        exit(1);
    }
    while (1)
        pause();
    return (0);
}
