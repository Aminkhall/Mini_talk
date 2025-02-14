#include "mini_talk.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long) n;
	if (num < 0)
	{
		num = -num;
		ft_putchar_fd('-', fd);
	}
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}

// void Kill(pid_t pid, int sig)
// {
//     if (kill(pid, sig))
//     {
//         perror("Kill failed");
//         exit(EXIT_FAILURE);
//     }
// }

// void Signal(int sig, void *handler, bool use_siginfo)
// {
//     struct sigaction sa = { 0 };    

//     if (use_siginfo)
//     {
//         sa.sa_flags = SA_SIGINFO;   
//         sa.sa_sigaction = handler;
//     }
//     else 
//         sa.sa_handler = handler;
//     sigemptyset(&sa.sa_mask);
//     sigaddset(&sa.sa_mask, SIGUSR1);
//     sigaddset(&sa.sa_mask, SIGUSR2);

//     if (sigaction(sig, &sa, NULL) < 0)
//     {
//         perror("Sigaction failed");
//         exit(EXIT_FAILURE);
//     }
// }
