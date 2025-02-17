#include "mini_talk.h"

void ft_error(int state)
{
    if (state == 1)
        ft_putstr_fd("Usage = ./client <PID> \"Message\"\n", 2);
    if (state == 2)
        ft_putstr_fd("invalid PID\n", 1);
    exit(1);
}

void check_sig(int sig)
{
    if (sig == SIGUSR1)
        return ;
}

void send_char(char c, pid_t server)
{
    int bit;
    int tmp;
    int err;

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

// void ft_exit(int c)
// {
//     if (c == SIGINT)
//         exit(1);
// }

int is_valid(int c)
{
    return ((c >= '0' && c <= '9') || c == '+');
}

int ft_isdigit(char *s)
{
    int count;

    count = 0;
    while (*s)
    {
        if (*s == '+')
            count++;
        if (!is_valid(*s))
            return (1);
        s++;
    }
    if (count > 1)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    pid_t server;
    char *message;

    // signal(SIGINT, ft_exit);
    if (ac != 3)
        ft_error(1);
    if (atoi(av[1]) < 0 || ft_isdigit(*(av + 1)) || atoi(av[1]) > 4194304)
        ft_error(2);
    server = atoi(av[1]);
    message = av[2];
    while (*message)
        send_char(*message++, server);
    send_char('\0', server);
    return (EXIT_SUCCESS);
}
