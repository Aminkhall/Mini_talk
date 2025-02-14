#include "mini_talk.h"

void send_char(char c, pid_t server)
{
    int bit;
    int tmp;

    bit = 4 + 4;
    while (bit)
    {
        --bit;
        tmp = c >> bit;
        if (tmp % 2 == 0)
            kill(server, SIGUSR2);
        else
            kill(server, SIGUSR1);
        usleep(10000);
    }
}

int main(int ac, char **av)
{
    pid_t server;
    char *message;

    if (ac != 3)
    {
        ft_putstr_fd("Usage = ./client <PID> \"Message\"\n", 2);
        exit(1);
    }
    if (atoi(av[1]) < 0)
        exit(1);
    server = atoi(av[1]);
    message = av[2];
    while (*message)
        send_char(*message++, server);
    send_char('\0', server);
    return (EXIT_SUCCESS);
}
