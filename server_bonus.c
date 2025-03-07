/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:08:28 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/07 15:06:32 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

void	free_tab(char **tab)
{
	free(*tab);
	*tab = NULL;
}

void	ft_reset(int *i, char *c)
{
	*i = 7;
	*c = 0;
}

void	ft_finish(char **tab, pid_t *pid)
{
	ft_putstr_fd(*tab, 1);
	free_tab(tab);
	kill(*pid, SIGUSR2);
}

void	handler(int sig, siginfo_t *siginfo, void *more_info)
{
	static int		i;
	static char		c;
	static pid_t	pid;
	static char		*tab;

	(void)more_info;
	if (siginfo->si_pid != pid)
	{
		pid = siginfo->si_pid;
		ft_reset(&i, &c);
		free_tab(&tab);
	}
	if (sig == SIGUSR1)
		c += 1 << i;
	i--;
	if (i == -1)
	{
		tab = ft_strjoin(tab, &c);
		if (c == '\0')
			ft_finish(&tab, &pid);
		ft_reset(&i, &c);
	}
	usleep(500);
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s;

	ft_putstr_fd("SERVER PID == ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s.sa_sigaction = handler;
	s.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s, NULL) < 0 || sigaction(SIGUSR2, &s, NULL) < 0)
	{
		ft_putstr_fd("Sigaction failed", 2);
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
