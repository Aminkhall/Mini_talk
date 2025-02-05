#ifndef MINI_TALK_H
#define MINI_TALK_H

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void Signal(int, void *, bool);
void Kill(pid_t , int);

#endif 