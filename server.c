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
		i = 7;
		c = 0;
	}
}

int main(void)
{
	struct sigaction	s;

    printf("SERVER PID == %d\n", getpid());
	s.sa_sigaction = handler;
	s.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
    // Signal(SIGUSR1, handler, true);
    // Signal(SIGUSR2, handler, true);
    while (1)
        pause();
    return (0);
}