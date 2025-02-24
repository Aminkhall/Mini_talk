/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:08:24 by mkhallou          #+#    #+#             */
/*   Updated: 2025/02/24 17:20:12 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	ft_error(int state)
{
	if (state == 1)
		ft_putstr_fd("Usage = ./client <PID> \"Message\"\n", 2);
	if (state == 2)
		ft_putstr_fd("invalid PID\n", 1);
	exit(1);
}

void	check_sig(int sig)
{
	if (sig == SIGUSR1)
		return ;
	if (sig == SIGUSR2)
		ft_putstr_fd("Message received\n", 1);
}

void	send_char(char c, pid_t server)
{
	int	bit;
	int	tmp;
	int	err;

	err = 0;
	bit = 8;
	signal(SIGUSR1, check_sig);
	while (bit)
	{
		--bit;
		tmp = c >> bit;
		if (tmp % 2 == 0)
			err = kill(server, SIGUSR2);
		else
			err = kill(server, SIGUSR1);
		if (err == -1)
			ft_error(2);
		pause();
	}
}

int	main(int ac, char **av)
{
	pid_t	server;
	char	*message;

	signal(SIGUSR2, check_sig);
	if (ac != 3)
		ft_error(1);
	if (ft_atoi(av[1]) < 0 || ft_isdigit2(*(av + 1)) || !(*av[1]))
		ft_error(2);
	server = ft_atoi(av[1]);
	message = av[2];
	while (*message)
		send_char(*message++, server);
	send_char('\0', server);
	return (0);
}
