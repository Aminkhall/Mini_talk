#ifndef MINI_TALK_H
#define MINI_TALK_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// void Signal(int, void *, bool);
// void Kill(pid_t , int);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif 