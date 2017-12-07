#ifndef SEMTING_H
#define SEMTING_H

#define KEY 420

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void fsemget(int);
void fsemval();
void fsemrem();

#endif