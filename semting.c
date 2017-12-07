#include "semting.h"

void fsemget(int val) {
    int semid = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
    if (semid  == -1) {
        printf("Semaphore already exists! You're bad at keeping track of things!\n");
    } else {
        semctl(semid, 0, SETVAL, val);
        printf("Semaphore %d successfully created with value: %d\n", semid, val);
    }
}

void fsemval() {
    int semid = semget(KEY, 0, 0);
    if (semid == -1) {
        printf("Semaphore doesn't currently exist. You're terrible.\n");
    } else {
        printf("Semaphore %d value: %d\n", semid, semctl(semid, 0, GETVAL));
    }
}

void fsemrem() {
    int semid = semget(KEY, 0, 0);
    if (semid == -1) {
        printf("Semaphore removal encountered an error.\n");
    } else {
        int remsemid = semctl(semid, 0, IPC_RMID);
        printf("Removed semaphore %d. You're not a failure after all.\n", remsemid);
    }
}

int main(int argc, char **argv) {
    if (argc < 1) {
        printf("Not enough arguments provided to do anything. Enter moar!\n");
    } else {
        if (!strcmp(argv[1], "-c")) {
            if (argc > 2) {
                int val = (int)(argv[2][0] - '0');
                printf("Your inputted value: %d\n", val);
                fsemget(val);
            } else
                printf("Not enough arguments provided to create a semaphore.\n");
        } else if (!strcmp(argv[1], "-v")) {
            fsemval();
        } else if (!strcmp(argv[1], "-r")) {
            fsemrem();
        } else {
            printf("That command doesn't exist.\n");
        }
    }
    return 0;
}