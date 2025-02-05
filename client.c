#include "mini_talk.h"

void send_char(char c, pid_t server)
{
    int bit;
    int tmp;

    bit = 8;
    while (bit)
    {
        --bit;
        tmp = c >> bit;
        if (tmp % 2 == 0)
            kill(server, SIGUSR2);
        else
            kill(server, SIGUSR1);
        usleep(500);
    }
}

int main(int ac, char **av)
{
    pid_t server;
    char *message;

    if (ac != 3)
    {
        fputs("Usage = ./client <PID> \"Message\"\n", stderr);
        exit(EXIT_FAILURE);
    }
    server = atoi(av[1]);
    message = av[2];
    while (*message)
        send_char(*message++, server);
   send_char('\0', server);
    return (EXIT_SUCCESS);
}
